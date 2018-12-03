/* Generated by the protocol buffer compiler.  DO NOT EDIT! */

#ifndef PROTOBUF_C_c_5fshuttle_5fentry_2eproto_INCLUDED
#define PROTOBUF_C_c_5fshuttle_5fentry_2eproto_INCLUDED

#include <google/protobuf-c/protobuf-c.h>

PROTOBUF_C_BEGIN_DECLS

#include "b_error.pb-c.h"
#include "b_math.pb-c.h"
#include "b_network.pb-c.h"

typedef struct _c_shuttle_entry_knock_rq c_shuttle_entry_knock_rq;
typedef struct _c_shuttle_entry_knock_rs c_shuttle_entry_knock_rs;
typedef struct _c_shuttle_entry_exchange_key_rq c_shuttle_entry_exchange_key_rq;
typedef struct _c_shuttle_entry_exchange_key_rs c_shuttle_entry_exchange_key_rs;


/* --- enums --- */

typedef enum _c_shuttle_entry_knock_rq_msg {
  c_shuttle_entry_knock_rq_msg_id = 33558528
} c_shuttle_entry_knock_rq_msg;
typedef enum _c_shuttle_entry_knock_rs_msg {
  c_shuttle_entry_knock_rs_msg_id = 33558529
} c_shuttle_entry_knock_rs_msg;
typedef enum _c_shuttle_entry_exchange_key_rq_msg {
  c_shuttle_entry_exchange_key_rq_msg_id = 33558544
} c_shuttle_entry_exchange_key_rq_msg;
typedef enum _c_shuttle_entry_exchange_key_rs_msg {
  c_shuttle_entry_exchange_key_rs_msg_id = 33558545
} c_shuttle_entry_exchange_key_rs_msg;
typedef enum _c_shuttle_entry_msg {
  c_shuttle_entry_msg_min_id = 33558528,
  c_shuttle_entry_msg_max_id = 33558783
} c_shuttle_entry_msg;

/* --- messages --- */

struct  _c_shuttle_entry_knock_rq
{
  ProtobufCMessage base;
  char *native_client_version;
  char *native_source_version;
  b_math_coord *coord_info;
};
extern char c_shuttle_entry_knock_rq_native_client_version_default_value[];
extern char c_shuttle_entry_knock_rq_native_source_version_default_value[];
#define c_shuttle_entry_knock_rq_Init \
 { PROTOBUF_C_MESSAGE_INIT (&c_shuttle_entry_knock_rq_descriptor) \
    , c_shuttle_entry_knock_rq_native_client_version_default_value, c_shuttle_entry_knock_rq_native_source_version_default_value, NULL }


struct  _c_shuttle_entry_knock_rs
{
  ProtobufCMessage base;
  b_error_info *error;
  b_network_address *addr;
  char *remote_client_version;
  char *remote_source_version;
  char *remote_server_version;
};
extern char c_shuttle_entry_knock_rs_remote_client_version_default_value[];
extern char c_shuttle_entry_knock_rs_remote_source_version_default_value[];
extern char c_shuttle_entry_knock_rs_remote_server_version_default_value[];
#define c_shuttle_entry_knock_rs_Init \
 { PROTOBUF_C_MESSAGE_INIT (&c_shuttle_entry_knock_rs_descriptor) \
    , NULL, NULL, c_shuttle_entry_knock_rs_remote_client_version_default_value, c_shuttle_entry_knock_rs_remote_source_version_default_value, c_shuttle_entry_knock_rs_remote_server_version_default_value }


struct  _c_shuttle_entry_exchange_key_rq
{
  ProtobufCMessage base;
  ProtobufCBinaryData n;
  ProtobufCBinaryData e;
  unsigned int version;
};
#define c_shuttle_entry_exchange_key_rq_Init \
 { PROTOBUF_C_MESSAGE_INIT (&c_shuttle_entry_exchange_key_rq_descriptor) \
    , {0,NULL}, {0,NULL}, 0 }


struct  _c_shuttle_entry_exchange_key_rs
{
  ProtobufCMessage base;
  b_error_info *error;
  ProtobufCBinaryData key;
};
#define c_shuttle_entry_exchange_key_rs_Init \
 { PROTOBUF_C_MESSAGE_INIT (&c_shuttle_entry_exchange_key_rs_descriptor) \
    , NULL, {0,NULL} }


/* c_shuttle_entry_knock_rq methods */
void   c_shuttle_entry_knock_rq_init
                     (c_shuttle_entry_knock_rq         *message);
size_t c_shuttle_entry_knock_rq_get_packed_size
                     (const c_shuttle_entry_knock_rq   *message);
size_t c_shuttle_entry_knock_rq_pack
                     (const c_shuttle_entry_knock_rq   *message,
                      unsigned char             *out);
size_t c_shuttle_entry_knock_rq_pack_to_buffer
                     (const c_shuttle_entry_knock_rq   *message,
                      ProtobufCBuffer     *buffer);
c_shuttle_entry_knock_rq *
       c_shuttle_entry_knock_rq_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   c_shuttle_entry_knock_rq_free_unpacked
                     (c_shuttle_entry_knock_rq *message,
                      ProtobufCAllocator *allocator);
/* c_shuttle_entry_knock_rs methods */
void   c_shuttle_entry_knock_rs_init
                     (c_shuttle_entry_knock_rs         *message);
size_t c_shuttle_entry_knock_rs_get_packed_size
                     (const c_shuttle_entry_knock_rs   *message);
size_t c_shuttle_entry_knock_rs_pack
                     (const c_shuttle_entry_knock_rs   *message,
                      unsigned char             *out);
size_t c_shuttle_entry_knock_rs_pack_to_buffer
                     (const c_shuttle_entry_knock_rs   *message,
                      ProtobufCBuffer     *buffer);
c_shuttle_entry_knock_rs *
       c_shuttle_entry_knock_rs_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   c_shuttle_entry_knock_rs_free_unpacked
                     (c_shuttle_entry_knock_rs *message,
                      ProtobufCAllocator *allocator);
/* c_shuttle_entry_exchange_key_rq methods */
void   c_shuttle_entry_exchange_key_rq_init
                     (c_shuttle_entry_exchange_key_rq         *message);
size_t c_shuttle_entry_exchange_key_rq_get_packed_size
                     (const c_shuttle_entry_exchange_key_rq   *message);
size_t c_shuttle_entry_exchange_key_rq_pack
                     (const c_shuttle_entry_exchange_key_rq   *message,
                      unsigned char             *out);
size_t c_shuttle_entry_exchange_key_rq_pack_to_buffer
                     (const c_shuttle_entry_exchange_key_rq   *message,
                      ProtobufCBuffer     *buffer);
c_shuttle_entry_exchange_key_rq *
       c_shuttle_entry_exchange_key_rq_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   c_shuttle_entry_exchange_key_rq_free_unpacked
                     (c_shuttle_entry_exchange_key_rq *message,
                      ProtobufCAllocator *allocator);
/* c_shuttle_entry_exchange_key_rs methods */
void   c_shuttle_entry_exchange_key_rs_init
                     (c_shuttle_entry_exchange_key_rs         *message);
size_t c_shuttle_entry_exchange_key_rs_get_packed_size
                     (const c_shuttle_entry_exchange_key_rs   *message);
size_t c_shuttle_entry_exchange_key_rs_pack
                     (const c_shuttle_entry_exchange_key_rs   *message,
                      unsigned char             *out);
size_t c_shuttle_entry_exchange_key_rs_pack_to_buffer
                     (const c_shuttle_entry_exchange_key_rs   *message,
                      ProtobufCBuffer     *buffer);
c_shuttle_entry_exchange_key_rs *
       c_shuttle_entry_exchange_key_rs_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   c_shuttle_entry_exchange_key_rs_free_unpacked
                     (c_shuttle_entry_exchange_key_rs *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*c_shuttle_entry_knock_rq_Closure)
                 (const c_shuttle_entry_knock_rq *message,
                  void *closure_data);
typedef void (*c_shuttle_entry_knock_rs_Closure)
                 (const c_shuttle_entry_knock_rs *message,
                  void *closure_data);
typedef void (*c_shuttle_entry_exchange_key_rq_Closure)
                 (const c_shuttle_entry_exchange_key_rq *message,
                  void *closure_data);
typedef void (*c_shuttle_entry_exchange_key_rs_Closure)
                 (const c_shuttle_entry_exchange_key_rs *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCEnumDescriptor    c_shuttle_entry_msg_descriptor;
extern const ProtobufCMessageDescriptor c_shuttle_entry_knock_rq_descriptor;
extern const ProtobufCEnumDescriptor    c_shuttle_entry_knock_rq_msg_descriptor;
extern const ProtobufCMessageDescriptor c_shuttle_entry_knock_rs_descriptor;
extern const ProtobufCEnumDescriptor    c_shuttle_entry_knock_rs_msg_descriptor;
extern const ProtobufCMessageDescriptor c_shuttle_entry_exchange_key_rq_descriptor;
extern const ProtobufCEnumDescriptor    c_shuttle_entry_exchange_key_rq_msg_descriptor;
extern const ProtobufCMessageDescriptor c_shuttle_entry_exchange_key_rs_descriptor;
extern const ProtobufCEnumDescriptor    c_shuttle_entry_exchange_key_rs_msg_descriptor;

PROTOBUF_C_END_DECLS


#endif  /* PROTOBUF_c_5fshuttle_5fentry_2eproto_INCLUDED */
