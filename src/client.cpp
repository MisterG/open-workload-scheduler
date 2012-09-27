/**
 * Project: OWS: an Open Source Workload Scheduler
 * File name: client.cpp
 * Description: contains the main() function of the client node.
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
#include <string>
#include <csignal>
#include <iostream>
#include <boost/thread.hpp>
#include <boost/lexical_cast.hpp>

// Common stuff
#include "common.h"

// Config and routing stuff
#include "config.h"
#include "router.h"
#include "rpc_server.h"

// Scheduler stuff
#include "day.h"
//#include "job.h"
#include "domain.h"
//#include "node.h"

///////////////////////////////////////////////////////////////////////////////

void	usage();
void	signal_handler(const int);
void	daemonnize(const char*);

///////////////////////////////////////////////////////////////////////////////

int		main (int argc, char * const argv[]) {
	char*		config_file		= NULL;
//	bool		debug_mode		= false;
//	bool		daemon_mode		= false;
//	bool		check_mode		= false;
	Config		conf_params;
	Router		router(&conf_params);

	/*
	 * Initialisation
	 *
	 * Read the config file (-f option):
	 * - bind_address
	 * - bind_port (default: 555)
	 * - data_path (default: /var/lib/ows)
	 * - etc_path (default: /etc/ows)
	 */
	if ( argc < 3 ) {
		usage();
		return EXIT_FAILURE;
	}

	for ( int i = 1 ; i < argc ; i++ ) {
		if ( strcmp(argv[i], "-f" ) == 0 && i < argc ) {
			config_file = argv[i+1];
			continue;
		}
/*		if ( strcmp(argv[i], "-v" ) == 0 ) {
			debug_mode = true;
			continue;
		}
		if ( strcmp(argv[i], "-d" ) == 0 ) {
			daemon_mode = true;
			continue;
		}
*/	}

	if ( config_file == NULL ) {
		std::cerr << "No config file given" << std::endl;
		usage();
		return EXIT_FAILURE;
	}

	if ( conf_params.parse_file(config_file) == false ) {
		std::cout << "Cannot parse " << config_file << std::endl;
		return EXIT_FAILURE;
	}

//	if (daemon_mode == true)
//		daemonize();

	/*
	 * Peers Discovery
	 *
	 * - Get the (host, public key) list
	 * - Call Router.reach_master() : if true -> continue, else waiting loop (30 seconds and retry)
	 *
	 */
	router.update_peers_list();
	while ( router.get_reachable_peers_number() < 1 ) {
		std::cout << "Cannot reach any peer" << std::endl;
		router.update_peers_list();
		sleep(30);
	}

	while ( router.reach_master() == false ) {
		std::cout << "Cannot reach the master" << std::endl;
		sleep(30);
	}

	/*
	 * Planning loading
	 *
	 * - Call Rpc_Client.get_planning() until it succeeds
	 * - Create the domain
	 * - Call Domain.load_planning();
	 */
	rpc::t_node	node;
	Domain		domain(&conf_params);

	while ( router.get_node(conf_params.get_param("domain_name")->c_str(), node) == false ) {
		std::cout << "Cannot get the planning" << std::endl;
		sleep(30);
	}
	if ( domain.add_node(conf_params.get_param("domain_name")->c_str(), node) == false ) {
		std::cerr << "Cannot load the planning" << std::endl;
		return EXIT_FAILURE;
	}

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
	 * - Check for ready jobs every minute
	 */
	v_jobs	jobs;
	boost::thread_group	running_jobs;
	while (1) {
		domain.get_ready_jobs(conf_params.get_param("domain_name")->c_str(), jobs, conf_params.get_param("node_name")->c_str());
		std::cout << "jobs size: " << jobs.size() << std::endl; // TODO: remove it
		BOOST_FOREACH(Job j, jobs) {
			running_jobs.create_thread(boost::bind(&Job::run, &j));
		}
		sleep(60);
	}

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
	std::cout << "Usage: client -f <config_file> [ -d || -v ]" << std::endl;
	std::cout << "	<config_file>	: the main configuration file" << std::endl;
	std::cout << "	-d		: daemon mode" << std::endl;
	std::cout << "	-c		: check the configuration and exit" << std::endl;
	std::cout << "	-v		: verbose mode" << std::endl;
}

/*
 * signal_handler
 *
 * Handles kill signals
 *
 * @arg sig : the recieved signal
 */
void	signal_handler(const int sig) {
	switch(sig) {
		case SIGHUP:
			break;
		case SIGTERM:
			exit(0);
			break;
	}
}

/*
 * daemonize
 *
 * Makes a clean fork :
 * - Forks cleanly
 * - Closes the file descriptors
 * - Writes the new PID to the given pid file
 * - Handles signals
 *
 * @arg	lock_file : typically /var/run/process.pid
 *
 */
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
