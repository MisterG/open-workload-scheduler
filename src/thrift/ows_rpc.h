/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 */
#ifndef ows_rpc_H
#define ows_rpc_H

#include <TProcessor.h>
#include "model_types.h"

namespace rpc {

class ows_rpcIf {
 public:
  virtual ~ows_rpcIf() {}
  virtual void hello(t_hello& _return, const t_node& target_node) = 0;
  virtual void reach_master(t_route& _return) = 0;
  virtual void get_planning(std::string& _return, const t_node& calling_node) = 0;
  virtual bool add_node(const t_node& calling_node, const t_node& hosting_node, const t_node& node_to_add) = 0;
  virtual void get_jobs(v_jobs& _return, const t_node& calling_node, const t_node& target_node) = 0;
  virtual void get_ready_jobs(v_jobs& _return, const t_node& calling_node, const t_node& target_node) = 0;
  virtual bool add_job(const t_node& calling_node, const t_job& j) = 0;
  virtual bool remove_job(const t_node& calling_node, const t_job& j) = 0;
  virtual bool update_job_state(const t_node& calling_node, const t_job& j) = 0;
  virtual void sql_exec(const std::string& query) = 0;
};

class ows_rpcNull : virtual public ows_rpcIf {
 public:
  virtual ~ows_rpcNull() {}
  void hello(t_hello& /* _return */, const t_node& /* target_node */) {
    return;
  }
  void reach_master(t_route& /* _return */) {
    return;
  }
  void get_planning(std::string& /* _return */, const t_node& /* calling_node */) {
    return;
  }
  bool add_node(const t_node& /* calling_node */, const t_node& /* hosting_node */, const t_node& /* node_to_add */) {
    bool _return = false;
    return _return;
  }
  void get_jobs(v_jobs& /* _return */, const t_node& /* calling_node */, const t_node& /* target_node */) {
    return;
  }
  void get_ready_jobs(v_jobs& /* _return */, const t_node& /* calling_node */, const t_node& /* target_node */) {
    return;
  }
  bool add_job(const t_node& /* calling_node */, const t_job& /* j */) {
    bool _return = false;
    return _return;
  }
  bool remove_job(const t_node& /* calling_node */, const t_job& /* j */) {
    bool _return = false;
    return _return;
  }
  bool update_job_state(const t_node& /* calling_node */, const t_job& /* j */) {
    bool _return = false;
    return _return;
  }
  void sql_exec(const std::string& /* query */) {
    return;
  }
};


class ows_rpc_hello_args {
 public:

  ows_rpc_hello_args() {
  }

  virtual ~ows_rpc_hello_args() throw() {}

  t_node target_node;

  bool operator == (const ows_rpc_hello_args & rhs) const
  {
    if (!(target_node == rhs.target_node))
      return false;
    return true;
  }
  bool operator != (const ows_rpc_hello_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ows_rpc_hello_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ows_rpc_hello_pargs {
 public:


  virtual ~ows_rpc_hello_pargs() throw() {}

  const t_node* target_node;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ows_rpc_hello_result__isset {
  _ows_rpc_hello_result__isset() : success(false), e(false) {}
  bool success;
  bool e;
} _ows_rpc_hello_result__isset;

class ows_rpc_hello_result {
 public:

  ows_rpc_hello_result() {
  }

  virtual ~ows_rpc_hello_result() throw() {}

  t_hello success;
  e_routing e;

  _ows_rpc_hello_result__isset __isset;

  bool operator == (const ows_rpc_hello_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const ows_rpc_hello_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ows_rpc_hello_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ows_rpc_hello_presult__isset {
  _ows_rpc_hello_presult__isset() : success(false), e(false) {}
  bool success;
  bool e;
} _ows_rpc_hello_presult__isset;

class ows_rpc_hello_presult {
 public:


  virtual ~ows_rpc_hello_presult() throw() {}

  t_hello* success;
  e_routing e;

  _ows_rpc_hello_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class ows_rpc_reach_master_args {
 public:

  ows_rpc_reach_master_args() {
  }

  virtual ~ows_rpc_reach_master_args() throw() {}


  bool operator == (const ows_rpc_reach_master_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ows_rpc_reach_master_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ows_rpc_reach_master_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ows_rpc_reach_master_pargs {
 public:


  virtual ~ows_rpc_reach_master_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ows_rpc_reach_master_result__isset {
  _ows_rpc_reach_master_result__isset() : success(false), e(false) {}
  bool success;
  bool e;
} _ows_rpc_reach_master_result__isset;

class ows_rpc_reach_master_result {
 public:

  ows_rpc_reach_master_result() {
  }

  virtual ~ows_rpc_reach_master_result() throw() {}

  t_route success;
  e_routing e;

  _ows_rpc_reach_master_result__isset __isset;

  bool operator == (const ows_rpc_reach_master_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const ows_rpc_reach_master_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ows_rpc_reach_master_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ows_rpc_reach_master_presult__isset {
  _ows_rpc_reach_master_presult__isset() : success(false), e(false) {}
  bool success;
  bool e;
} _ows_rpc_reach_master_presult__isset;

class ows_rpc_reach_master_presult {
 public:


  virtual ~ows_rpc_reach_master_presult() throw() {}

  t_route* success;
  e_routing e;

  _ows_rpc_reach_master_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class ows_rpc_get_planning_args {
 public:

  ows_rpc_get_planning_args() {
  }

  virtual ~ows_rpc_get_planning_args() throw() {}

  t_node calling_node;

  bool operator == (const ows_rpc_get_planning_args & rhs) const
  {
    if (!(calling_node == rhs.calling_node))
      return false;
    return true;
  }
  bool operator != (const ows_rpc_get_planning_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ows_rpc_get_planning_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ows_rpc_get_planning_pargs {
 public:


  virtual ~ows_rpc_get_planning_pargs() throw() {}

  const t_node* calling_node;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ows_rpc_get_planning_result__isset {
  _ows_rpc_get_planning_result__isset() : success(false), e(false) {}
  bool success;
  bool e;
} _ows_rpc_get_planning_result__isset;

class ows_rpc_get_planning_result {
 public:

  ows_rpc_get_planning_result() : success("") {
  }

  virtual ~ows_rpc_get_planning_result() throw() {}

  std::string success;
  e_planning e;

  _ows_rpc_get_planning_result__isset __isset;

  bool operator == (const ows_rpc_get_planning_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const ows_rpc_get_planning_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ows_rpc_get_planning_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ows_rpc_get_planning_presult__isset {
  _ows_rpc_get_planning_presult__isset() : success(false), e(false) {}
  bool success;
  bool e;
} _ows_rpc_get_planning_presult__isset;

class ows_rpc_get_planning_presult {
 public:


  virtual ~ows_rpc_get_planning_presult() throw() {}

  std::string* success;
  e_planning e;

  _ows_rpc_get_planning_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class ows_rpc_add_node_args {
 public:

  ows_rpc_add_node_args() {
  }

  virtual ~ows_rpc_add_node_args() throw() {}

  t_node calling_node;
  t_node hosting_node;
  t_node node_to_add;

  bool operator == (const ows_rpc_add_node_args & rhs) const
  {
    if (!(calling_node == rhs.calling_node))
      return false;
    if (!(hosting_node == rhs.hosting_node))
      return false;
    if (!(node_to_add == rhs.node_to_add))
      return false;
    return true;
  }
  bool operator != (const ows_rpc_add_node_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ows_rpc_add_node_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ows_rpc_add_node_pargs {
 public:


  virtual ~ows_rpc_add_node_pargs() throw() {}

  const t_node* calling_node;
  const t_node* hosting_node;
  const t_node* node_to_add;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ows_rpc_add_node_result__isset {
  _ows_rpc_add_node_result__isset() : success(false), e(false) {}
  bool success;
  bool e;
} _ows_rpc_add_node_result__isset;

class ows_rpc_add_node_result {
 public:

  ows_rpc_add_node_result() : success(0) {
  }

  virtual ~ows_rpc_add_node_result() throw() {}

  bool success;
  e_node e;

  _ows_rpc_add_node_result__isset __isset;

  bool operator == (const ows_rpc_add_node_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const ows_rpc_add_node_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ows_rpc_add_node_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ows_rpc_add_node_presult__isset {
  _ows_rpc_add_node_presult__isset() : success(false), e(false) {}
  bool success;
  bool e;
} _ows_rpc_add_node_presult__isset;

class ows_rpc_add_node_presult {
 public:


  virtual ~ows_rpc_add_node_presult() throw() {}

  bool* success;
  e_node e;

  _ows_rpc_add_node_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class ows_rpc_get_jobs_args {
 public:

  ows_rpc_get_jobs_args() {
  }

  virtual ~ows_rpc_get_jobs_args() throw() {}

  t_node calling_node;
  t_node target_node;

  bool operator == (const ows_rpc_get_jobs_args & rhs) const
  {
    if (!(calling_node == rhs.calling_node))
      return false;
    if (!(target_node == rhs.target_node))
      return false;
    return true;
  }
  bool operator != (const ows_rpc_get_jobs_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ows_rpc_get_jobs_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ows_rpc_get_jobs_pargs {
 public:


  virtual ~ows_rpc_get_jobs_pargs() throw() {}

  const t_node* calling_node;
  const t_node* target_node;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ows_rpc_get_jobs_result__isset {
  _ows_rpc_get_jobs_result__isset() : success(false), e(false) {}
  bool success;
  bool e;
} _ows_rpc_get_jobs_result__isset;

class ows_rpc_get_jobs_result {
 public:

  ows_rpc_get_jobs_result() {
  }

  virtual ~ows_rpc_get_jobs_result() throw() {}

  v_jobs success;
  e_job e;

  _ows_rpc_get_jobs_result__isset __isset;

  bool operator == (const ows_rpc_get_jobs_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const ows_rpc_get_jobs_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ows_rpc_get_jobs_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ows_rpc_get_jobs_presult__isset {
  _ows_rpc_get_jobs_presult__isset() : success(false), e(false) {}
  bool success;
  bool e;
} _ows_rpc_get_jobs_presult__isset;

class ows_rpc_get_jobs_presult {
 public:


  virtual ~ows_rpc_get_jobs_presult() throw() {}

  v_jobs* success;
  e_job e;

  _ows_rpc_get_jobs_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class ows_rpc_get_ready_jobs_args {
 public:

  ows_rpc_get_ready_jobs_args() {
  }

  virtual ~ows_rpc_get_ready_jobs_args() throw() {}

  t_node calling_node;
  t_node target_node;

  bool operator == (const ows_rpc_get_ready_jobs_args & rhs) const
  {
    if (!(calling_node == rhs.calling_node))
      return false;
    if (!(target_node == rhs.target_node))
      return false;
    return true;
  }
  bool operator != (const ows_rpc_get_ready_jobs_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ows_rpc_get_ready_jobs_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ows_rpc_get_ready_jobs_pargs {
 public:


  virtual ~ows_rpc_get_ready_jobs_pargs() throw() {}

  const t_node* calling_node;
  const t_node* target_node;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ows_rpc_get_ready_jobs_result__isset {
  _ows_rpc_get_ready_jobs_result__isset() : success(false), e(false) {}
  bool success;
  bool e;
} _ows_rpc_get_ready_jobs_result__isset;

class ows_rpc_get_ready_jobs_result {
 public:

  ows_rpc_get_ready_jobs_result() {
  }

  virtual ~ows_rpc_get_ready_jobs_result() throw() {}

  v_jobs success;
  e_job e;

  _ows_rpc_get_ready_jobs_result__isset __isset;

  bool operator == (const ows_rpc_get_ready_jobs_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const ows_rpc_get_ready_jobs_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ows_rpc_get_ready_jobs_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ows_rpc_get_ready_jobs_presult__isset {
  _ows_rpc_get_ready_jobs_presult__isset() : success(false), e(false) {}
  bool success;
  bool e;
} _ows_rpc_get_ready_jobs_presult__isset;

class ows_rpc_get_ready_jobs_presult {
 public:


  virtual ~ows_rpc_get_ready_jobs_presult() throw() {}

  v_jobs* success;
  e_job e;

  _ows_rpc_get_ready_jobs_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class ows_rpc_add_job_args {
 public:

  ows_rpc_add_job_args() {
  }

  virtual ~ows_rpc_add_job_args() throw() {}

  t_node calling_node;
  t_job j;

  bool operator == (const ows_rpc_add_job_args & rhs) const
  {
    if (!(calling_node == rhs.calling_node))
      return false;
    if (!(j == rhs.j))
      return false;
    return true;
  }
  bool operator != (const ows_rpc_add_job_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ows_rpc_add_job_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ows_rpc_add_job_pargs {
 public:


  virtual ~ows_rpc_add_job_pargs() throw() {}

  const t_node* calling_node;
  const t_job* j;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ows_rpc_add_job_result__isset {
  _ows_rpc_add_job_result__isset() : success(false), e(false) {}
  bool success;
  bool e;
} _ows_rpc_add_job_result__isset;

class ows_rpc_add_job_result {
 public:

  ows_rpc_add_job_result() : success(0) {
  }

  virtual ~ows_rpc_add_job_result() throw() {}

  bool success;
  e_job e;

  _ows_rpc_add_job_result__isset __isset;

  bool operator == (const ows_rpc_add_job_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const ows_rpc_add_job_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ows_rpc_add_job_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ows_rpc_add_job_presult__isset {
  _ows_rpc_add_job_presult__isset() : success(false), e(false) {}
  bool success;
  bool e;
} _ows_rpc_add_job_presult__isset;

class ows_rpc_add_job_presult {
 public:


  virtual ~ows_rpc_add_job_presult() throw() {}

  bool* success;
  e_job e;

  _ows_rpc_add_job_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class ows_rpc_remove_job_args {
 public:

  ows_rpc_remove_job_args() {
  }

  virtual ~ows_rpc_remove_job_args() throw() {}

  t_node calling_node;
  t_job j;

  bool operator == (const ows_rpc_remove_job_args & rhs) const
  {
    if (!(calling_node == rhs.calling_node))
      return false;
    if (!(j == rhs.j))
      return false;
    return true;
  }
  bool operator != (const ows_rpc_remove_job_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ows_rpc_remove_job_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ows_rpc_remove_job_pargs {
 public:


  virtual ~ows_rpc_remove_job_pargs() throw() {}

  const t_node* calling_node;
  const t_job* j;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ows_rpc_remove_job_result__isset {
  _ows_rpc_remove_job_result__isset() : success(false), e(false) {}
  bool success;
  bool e;
} _ows_rpc_remove_job_result__isset;

class ows_rpc_remove_job_result {
 public:

  ows_rpc_remove_job_result() : success(0) {
  }

  virtual ~ows_rpc_remove_job_result() throw() {}

  bool success;
  e_job e;

  _ows_rpc_remove_job_result__isset __isset;

  bool operator == (const ows_rpc_remove_job_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const ows_rpc_remove_job_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ows_rpc_remove_job_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ows_rpc_remove_job_presult__isset {
  _ows_rpc_remove_job_presult__isset() : success(false), e(false) {}
  bool success;
  bool e;
} _ows_rpc_remove_job_presult__isset;

class ows_rpc_remove_job_presult {
 public:


  virtual ~ows_rpc_remove_job_presult() throw() {}

  bool* success;
  e_job e;

  _ows_rpc_remove_job_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class ows_rpc_update_job_state_args {
 public:

  ows_rpc_update_job_state_args() {
  }

  virtual ~ows_rpc_update_job_state_args() throw() {}

  t_node calling_node;
  t_job j;

  bool operator == (const ows_rpc_update_job_state_args & rhs) const
  {
    if (!(calling_node == rhs.calling_node))
      return false;
    if (!(j == rhs.j))
      return false;
    return true;
  }
  bool operator != (const ows_rpc_update_job_state_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ows_rpc_update_job_state_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ows_rpc_update_job_state_pargs {
 public:


  virtual ~ows_rpc_update_job_state_pargs() throw() {}

  const t_node* calling_node;
  const t_job* j;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ows_rpc_update_job_state_result__isset {
  _ows_rpc_update_job_state_result__isset() : success(false), e(false) {}
  bool success;
  bool e;
} _ows_rpc_update_job_state_result__isset;

class ows_rpc_update_job_state_result {
 public:

  ows_rpc_update_job_state_result() : success(0) {
  }

  virtual ~ows_rpc_update_job_state_result() throw() {}

  bool success;
  e_job e;

  _ows_rpc_update_job_state_result__isset __isset;

  bool operator == (const ows_rpc_update_job_state_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const ows_rpc_update_job_state_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ows_rpc_update_job_state_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ows_rpc_update_job_state_presult__isset {
  _ows_rpc_update_job_state_presult__isset() : success(false), e(false) {}
  bool success;
  bool e;
} _ows_rpc_update_job_state_presult__isset;

class ows_rpc_update_job_state_presult {
 public:


  virtual ~ows_rpc_update_job_state_presult() throw() {}

  bool* success;
  e_job e;

  _ows_rpc_update_job_state_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class ows_rpc_sql_exec_args {
 public:

  ows_rpc_sql_exec_args() : query("") {
  }

  virtual ~ows_rpc_sql_exec_args() throw() {}

  std::string query;

  bool operator == (const ows_rpc_sql_exec_args & rhs) const
  {
    if (!(query == rhs.query))
      return false;
    return true;
  }
  bool operator != (const ows_rpc_sql_exec_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ows_rpc_sql_exec_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ows_rpc_sql_exec_pargs {
 public:


  virtual ~ows_rpc_sql_exec_pargs() throw() {}

  const std::string* query;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

class ows_rpcClient : virtual public ows_rpcIf {
 public:
  ows_rpcClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  ows_rpcClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void hello(t_hello& _return, const t_node& target_node);
  void send_hello(const t_node& target_node);
  void recv_hello(t_hello& _return);
  void reach_master(t_route& _return);
  void send_reach_master();
  void recv_reach_master(t_route& _return);
  void get_planning(std::string& _return, const t_node& calling_node);
  void send_get_planning(const t_node& calling_node);
  void recv_get_planning(std::string& _return);
  bool add_node(const t_node& calling_node, const t_node& hosting_node, const t_node& node_to_add);
  void send_add_node(const t_node& calling_node, const t_node& hosting_node, const t_node& node_to_add);
  bool recv_add_node();
  void get_jobs(v_jobs& _return, const t_node& calling_node, const t_node& target_node);
  void send_get_jobs(const t_node& calling_node, const t_node& target_node);
  void recv_get_jobs(v_jobs& _return);
  void get_ready_jobs(v_jobs& _return, const t_node& calling_node, const t_node& target_node);
  void send_get_ready_jobs(const t_node& calling_node, const t_node& target_node);
  void recv_get_ready_jobs(v_jobs& _return);
  bool add_job(const t_node& calling_node, const t_job& j);
  void send_add_job(const t_node& calling_node, const t_job& j);
  bool recv_add_job();
  bool remove_job(const t_node& calling_node, const t_job& j);
  void send_remove_job(const t_node& calling_node, const t_job& j);
  bool recv_remove_job();
  bool update_job_state(const t_node& calling_node, const t_job& j);
  void send_update_job_state(const t_node& calling_node, const t_job& j);
  bool recv_update_job_state();
  void sql_exec(const std::string& query);
  void send_sql_exec(const std::string& query);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class ows_rpcProcessor : virtual public ::apache::thrift::TProcessor {
 protected:
  boost::shared_ptr<ows_rpcIf> iface_;
  virtual bool process_fn(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, std::string& fname, int32_t seqid, void* callContext);
 private:
  std::map<std::string, void (ows_rpcProcessor::*)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*)> processMap_;
  void process_hello(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_reach_master(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_get_planning(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_add_node(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_get_jobs(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_get_ready_jobs(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_add_job(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_remove_job(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_update_job_state(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_sql_exec(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  ows_rpcProcessor(boost::shared_ptr<ows_rpcIf> iface) :
    iface_(iface) {
    processMap_["hello"] = &ows_rpcProcessor::process_hello;
    processMap_["reach_master"] = &ows_rpcProcessor::process_reach_master;
    processMap_["get_planning"] = &ows_rpcProcessor::process_get_planning;
    processMap_["add_node"] = &ows_rpcProcessor::process_add_node;
    processMap_["get_jobs"] = &ows_rpcProcessor::process_get_jobs;
    processMap_["get_ready_jobs"] = &ows_rpcProcessor::process_get_ready_jobs;
    processMap_["add_job"] = &ows_rpcProcessor::process_add_job;
    processMap_["remove_job"] = &ows_rpcProcessor::process_remove_job;
    processMap_["update_job_state"] = &ows_rpcProcessor::process_update_job_state;
    processMap_["sql_exec"] = &ows_rpcProcessor::process_sql_exec;
  }

  virtual bool process(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot, void* callContext);
  virtual ~ows_rpcProcessor() {}
};

class ows_rpcMultiface : virtual public ows_rpcIf {
 public:
  ows_rpcMultiface(std::vector<boost::shared_ptr<ows_rpcIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~ows_rpcMultiface() {}
 protected:
  std::vector<boost::shared_ptr<ows_rpcIf> > ifaces_;
  ows_rpcMultiface() {}
  void add(boost::shared_ptr<ows_rpcIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void hello(t_hello& _return, const t_node& target_node) {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      if (i == sz - 1) {
        ifaces_[i]->hello(_return, target_node);
        return;
      } else {
        ifaces_[i]->hello(_return, target_node);
      }
    }
  }

  void reach_master(t_route& _return) {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      if (i == sz - 1) {
        ifaces_[i]->reach_master(_return);
        return;
      } else {
        ifaces_[i]->reach_master(_return);
      }
    }
  }

  void get_planning(std::string& _return, const t_node& calling_node) {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      if (i == sz - 1) {
        ifaces_[i]->get_planning(_return, calling_node);
        return;
      } else {
        ifaces_[i]->get_planning(_return, calling_node);
      }
    }
  }

  bool add_node(const t_node& calling_node, const t_node& hosting_node, const t_node& node_to_add) {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      if (i == sz - 1) {
        return ifaces_[i]->add_node(calling_node, hosting_node, node_to_add);
      } else {
        ifaces_[i]->add_node(calling_node, hosting_node, node_to_add);
      }
    }
  }

  void get_jobs(v_jobs& _return, const t_node& calling_node, const t_node& target_node) {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      if (i == sz - 1) {
        ifaces_[i]->get_jobs(_return, calling_node, target_node);
        return;
      } else {
        ifaces_[i]->get_jobs(_return, calling_node, target_node);
      }
    }
  }

  void get_ready_jobs(v_jobs& _return, const t_node& calling_node, const t_node& target_node) {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      if (i == sz - 1) {
        ifaces_[i]->get_ready_jobs(_return, calling_node, target_node);
        return;
      } else {
        ifaces_[i]->get_ready_jobs(_return, calling_node, target_node);
      }
    }
  }

  bool add_job(const t_node& calling_node, const t_job& j) {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      if (i == sz - 1) {
        return ifaces_[i]->add_job(calling_node, j);
      } else {
        ifaces_[i]->add_job(calling_node, j);
      }
    }
  }

  bool remove_job(const t_node& calling_node, const t_job& j) {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      if (i == sz - 1) {
        return ifaces_[i]->remove_job(calling_node, j);
      } else {
        ifaces_[i]->remove_job(calling_node, j);
      }
    }
  }

  bool update_job_state(const t_node& calling_node, const t_job& j) {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      if (i == sz - 1) {
        return ifaces_[i]->update_job_state(calling_node, j);
      } else {
        ifaces_[i]->update_job_state(calling_node, j);
      }
    }
  }

  void sql_exec(const std::string& query) {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      ifaces_[i]->sql_exec(query);
    }
  }

};

} // namespace

#endif
