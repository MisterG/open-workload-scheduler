/**
 * Project: OWS: an Open Source Workload Scheduler
 * File name: master.cpp
 * Description: contains the main() function of the master node.
 *
 * @author Mathieu Grzybek on 2010-05-16
 * @copyright 2010 Mathieu Grzybek. All rights reserved.
 * @version $Id: code-gpl-license.txt,v 1.2 2004/05/04 13:19:30 garry Exp $
 *
 * @see The GNU Public License (GPL) version 3 or higher
 *
 *
 * OWS is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

// Generic stuff
#include <csignal>
#include <iostream>
#include <string>
#include <boost/thread/thread.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/program_options.hpp>

// Common stuff
#include "common.h"

// Config and routing stuff
//#include "cfg.h"
#include "router.h"
#include "rpc_server.h"

// Scheduler stuff
#include "day.h"
//#include "job.h"
#include "domain.h"
//#include "node.h"

///////////////////////////////////////////////////////////////////////////////

/**
 * @brief usage
 *
 * Prints the available options of the program to stdout.
 */
void	usage();

/**
 * @brief signal_handler
 *
 * Deals with the received signals when daemonized.
 *
 * @param	the signal received
 */
void	signal_handler(const int);

/**
 * @brief daemonnize
 *
 * Makes a clean fork :
 * - Forks cleanly
 * - Closes the file descriptors
 * - Writes the new PID to the given pid file
 * - Handles signals
 *
 * @param the PID file
 */
void	daemonnize(const char*);

class Config;

///////////////////////////////////////////////////////////////////////////////

int	main (int argc, char * const argv[]) {
	Config	conf_params;
	Router	router(&conf_params);
	boost::program_options::variables_map	opts_variables;

	/*
	 * Initialisation
	 *
	 * Read the config file (-f option):
	 * - bind_address
	 * - bind_port (default: 555)
	 * - data_path (default: /var/lib/ows)
	 * - etc_path (default: /etc/ows)
	 */
	boost::program_options::options_description usage("Allowed options");
	usage.add_options()
			("check,c", "check the configuration and exit")
			("config,f", boost::program_options::value<std::string>(), "the main configuration file")
			("daemon,d,", "daemon mode")
			("help,h", "produce help")
			("verbose,v", "set verbosity on")
	;

	boost::program_options::store(boost::program_options::parse_command_line(argc, argv, usage), opts_variables);
	boost::program_options::notify(opts_variables);

	if ( opts_variables.count("help") ) {
		std::cout << usage << std::endl;
		return EXIT_SUCCESS;
	}

	if ( ! opts_variables.count("config") ) {
		std::cerr << "config file not given" << std::endl;
		std::cout << usage << std::endl;
		exit(EXIT_FAILURE);
	} else {
		if ( conf_params.parse_file(opts_variables["config"].as<std::string>().c_str()) == false ) {
			std::cerr << "Cannot parse " << opts_variables["config"].as<std::string>() << std::endl;
			exit(EXIT_FAILURE);
		}
	}

	/*
	 * Logging stuff
	 *
	 * We use macros to send messages. See common.h (INFO, NOTICE...)
	 */
	log4cpp::PropertyConfigurator::configure(conf_params.get_param("log4cpp_properties")->c_str());
	log4cpp::Category& root_logger = log4cpp::Category::getRoot();

	//if ( opts_variables.count("daemon") )
		//daemonize();

	try {
		/*
		 * Peers Discovery
		 *
		 * - Get the (host, public key) list
		 * - Call Router.reach_master() : if true -> continue, else waiting loop (30 seconds and retry)
		 *
		 */
		//router.update_peers_list();

		/*
		 * Planning loading
		 *
		 * - Create the domain
		 * - Create the current planning from the template
		 * TODO: manage exceptions
		 */
		Domain	domain(&conf_params);

		/*
		 * Ports listening
		 *
		 * - create a Rpc_Server object
		 * - create a dedicated thread
		 */
		Rpc_Server		server(&domain, &conf_params, &router);
		boost::thread	server_thread(boost::bind(&Rpc_Server::run, &server));

		/*
		 * Domain preparation
		 *
		 * - Try to reach the node needed by the planning : build the routing table
		 */

		/*
		 * Domain routine
		 *
		 * - Check for ready jobs every minute:
		 *	- PASSIVE: for the whole nodes
		 *	- ACTIVE/P2P: for the local node only
		 * - Check if we need to initialize the next planning (buffer == 1 minute)
		 */
		boost::thread_group	running_jobs;

		while (1) {
			v_jobs	jobs;
			time_t	now = time(NULL);

			try {
				DEBUG << "planning start time: "
					  << domain.get_planning_start_time()
					  << " (" << build_human_readable_time(domain.get_planning_start_time()) << ")";
				DEBUG << "now: " << now << " (" << build_human_readable_time(now) << ")";

				if ( domain.get_planning_start_time() <= now ) {
					if ( conf_params.get_running_mode() == PASSIVE )
						domain.get_ready_jobs(jobs, NULL);
					else
						domain.get_ready_jobs(jobs, conf_params.get_param("node_name")->c_str());
				}

				if ( domain.get_next_planning_start_time() - now <= 60 ) {
					domain.switch_planning();
				}

			} catch ( const rpc::ex_job& e ) {
				ERROR << "Exception occured (ex_job): " << e.msg;
			}

			if ( domain.get_planning_start_time() <= now ) {
				INFO << "planning " << domain.get_current_planning_name() << " - ready jobs: " << jobs.size();
				if ( jobs.size() > 0 )
					for ( unsigned long iter = 0 ; iter < jobs.size() ; ++iter ) {
						if ( jobs[iter].get_state() == rpc::e_job_state::WAITING ) {
							if ( jobs[iter].get_node_name2().compare(conf_params.get_param("node_name")->c_str()) == 0 ) {
								running_jobs.create_thread(boost::bind(&Job::run, jobs[iter]));
							} else {
								NOTICE << jobs[iter].get_name() << " is not a local job";
								if ( conf_params.get_running_mode() == PASSIVE )
									NOTICE << "TODO: send the job to the target node";
							}
						}
					}

			} else {
				DEBUG << "planning start time > now. " << domain.get_planning_start_time() - now << " seconds left";
			}
			// This prevents the previous jobs to be run again
			jobs.clear();
			sleep(60);
		}

		running_jobs.join_all();
		server_thread.join();

	} catch ( const rpc::ex_processing& e ) {
		EMERG << "Fatal exception occured (ex_processing): " << e.msg;
		log4cpp::Category::shutdown();
		return EXIT_FAILURE;
	} catch ( const std::exception& e ) {
		EMERG << "Fatal exception occured (std::exception): " << e.what();
		log4cpp::Category::shutdown();
		return EXIT_FAILURE;
	}

	INFO << "Clean shutdown";
	log4cpp::Category::shutdown();
	return EXIT_SUCCESS;
}

///////////////////////////////////////////////////////////////////////////////

/*
 * usage
 *
 * Prints the usage page on stdout
 *
 */
void	usage() {
	std::cout << "Usage: master -f <config_file> [ -d || -v || -c ]" << std::endl
		<< "	<config_file>	: the main configuration file" << std::endl
		<< "	-d		: daemon mode" << std::endl
		<< "	-c		: check the configuration and exit" << std::endl
		<< "	-v		: verbose mode" << std::endl;
}

void	signal_handler(const int sig) {
	log4cpp::Category& root_logger = log4cpp::Category::getRoot();

	switch(sig) {
		case SIGHUP:
			INFO << "received SIGHUP, nothing done.";
			break;
		case SIGTERM:
			INFO << "received SIGTERM, shutting down.";
			log4cpp::Category::shutdown();
			exit(EXIT_SUCCESS);
			break;
	}
}

void	daemonize(const char* lock_file) {
	int			result;
	std::ofstream	f;

	result = fork();
	if (result < 0)
		exit(1); /* fork error */
	if (result > 0)
		exit(0); /* parent exits */

	/* child (daemon) continues */
	setsid(); /* obtain a new process group */

	for (result = getdtablesize() ; result >= 0 ; --result)
		close(result); /* close all descriptors */

	chdir("/tmp"); /* change running directory */

	/* first instance continues */
	f.open(lock_file);
	f << getpid();
	f.close();

	signal(SIGCHLD,SIG_IGN); /* ignore child */
	signal(SIGTSTP,SIG_IGN); /* ignore tty signals */
	signal(SIGTTOU,SIG_IGN);
	signal(SIGTTIN,SIG_IGN);
	signal(SIGHUP,signal_handler); /* catch hangup signal */
	signal(SIGTERM,signal_handler); /* catch kill signal */
}
