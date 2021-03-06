/* Generated by the protocol buffer compiler.  DO NOT EDIT! */

#ifndef PROTOBUF_C_c_5fbusiness_5faccount_2eproto_INCLUDED
#define PROTOBUF_C_c_5fbusiness_5faccount_2eproto_INCLUDED

#include <google/protobuf-c/protobuf-c.h>

PROTOBUF_C_BEGIN_DECLS

#include "b_error.pb-c.h"

typedef struct _c_business_account_signed_in_rq c_business_account_signed_in_rq;
typedef struct _c_business_account_signed_in_rs c_business_account_signed_in_rs;
typedef struct _c_business_account_register_rq c_business_account_register_rq;
typedef struct _c_business_account_register_rs c_business_account_register_rs;


/* --- enums --- */

typedef enum _c_business_account_signed_in_rq_msg {
  c_business_account_signed_in_rq_msg_id = 33562640
} c_business_account_signed_in_rq_msg;
typedef enum _c_business_account_signed_in_rs_msg {
  c_business_account_signed_in_rs_msg_id = 33558545
} c_business_account_signed_in_rs_msg;
typedef enum _c_business_account_register_rq_msg {
  c_business_account_register_rq_msg_id = 33562656
} c_business_account_register_rq_msg;
typedef enum _c_business_account_register_rs_msg {
  c_business_account_register_rs_msg_id = 33558561
} c_business_account_register_rs_msg;
typedef enum _c_business_account_msg {
  c_business_account_msg_min_id = 33562624,
  c_business_account_msg_max_id = 33562879
} c_business_account_msg;

/* --- messages --- */

struct  _c_business_account_signed_in_rq
{
  ProtobufCMessage base;
  char *user_name;
  char *password;
};
#define c_business_account_signed_in_rq_Init \
 { PROTOBUF_C_MESSAGE_INIT (&c_business_account_signed_in_rq_descriptor) \
    , NULL, NULL }


struct  _c_business_account_signed_in_rs
{
  ProtobufCMessage base;
  b_error_info *error;
  char *user_name;
  unsigned long long int user_id;
  char *token;
};
#define c_business_account_signed_in_rs_Init \
 { PROTOBUF_C_MESSAGE_INIT (&c_business_account_signed_in_rs_descriptor) \
    , NULL, NULL, 0, NULL }


struct  _c_business_account_register_rq
{
  ProtobufCMessage base;
  char *user_name;
  char *password;
};
#define c_business_account_register_rq_Init \
 { PROTOBUF_C_MESSAGE_INIT (&c_business_account_register_rq_descriptor) \
    , NULL, NULL }


struct  _c_business_account_register_rs
{
  ProtobufCMessage base;
  b_error_info *error;
  char *user_name;
  unsigned long long int user_id;
  char *token;
};
#define c_business_account_register_rs_Init \
 { PROTOBUF_C_MESSAGE_INIT (&c_business_account_register_rs_descriptor) \
    , NULL, NULL, 0, NULL }


/* c_business_account_signed_in_rq methods */
void   c_business_account_signed_in_rq_init
                     (c_business_account_signed_in_rq         *message);
size_t c_business_account_signed_in_rq_get_packed_size
                     (const c_business_account_signed_in_rq   *message);
size_t c_business_account_signed_in_rq_pack
                     (const c_business_account_signed_in_rq   *message,
                      unsigned char             *out);
size_t c_business_account_signed_in_rq_pack_to_buffer
                     (const c_business_account_signed_in_rq   *message,
                      ProtobufCBuffer     *buffer);
c_business_account_signed_in_rq *
       c_business_account_signed_in_rq_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   c_business_account_signed_in_rq_free_unpacked
                     (c_business_account_signed_in_rq *message,
                      ProtobufCAllocator *allocator);
/* c_business_account_signed_in_rs methods */
void   c_business_account_signed_in_rs_init
                     (c_business_account_signed_in_rs         *message);
size_t c_business_account_signed_in_rs_get_packed_size
                     (const c_business_account_signed_in_rs   *message);
size_t c_business_account_signed_in_rs_pack
                     (const c_business_account_signed_in_rs   *message,
                      unsigned char             *out);
size_t c_business_account_signed_in_rs_pack_to_buffer
                     (const c_business_account_signed_in_rs   *message,
                      ProtobufCBuffer     *buffer);
c_business_account_signed_in_rs *
       c_business_account_signed_in_rs_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   c_business_account_signed_in_rs_free_unpacked
                     (c_business_account_signed_in_rs *message,
                      ProtobufCAllocator *allocator);
/* c_business_account_register_rq methods */
void   c_business_account_register_rq_init
                     (c_business_account_register_rq         *message);
size_t c_business_account_register_rq_get_packed_size
                     (const c_business_account_register_rq   *message);
size_t c_business_account_register_rq_pack
                     (const c_business_account_register_rq   *message,
                      unsigned char             *out);
size_t c_business_account_register_rq_pack_to_buffer
                     (const c_business_account_register_rq   *message,
                      ProtobufCBuffer     *buffer);
c_business_account_register_rq *
       c_business_account_register_rq_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   c_business_account_register_rq_free_unpacked
                     (c_business_account_register_rq *message,
                      ProtobufCAllocator *allocator);
/* c_business_account_register_rs methods */
void   c_business_account_register_rs_init
                     (c_business_account_register_rs         *message);
size_t c_business_account_register_rs_get_packed_size
                     (const c_business_account_register_rs   *message);
size_t c_business_account_register_rs_pack
                     (const c_business_account_register_rs   *message,
                      unsigned char             *out);
size_t c_business_account_register_rs_pack_to_buffer
                     (const c_business_account_register_rs   *message,
                      ProtobufCBuffer     *buffer);
c_business_account_register_rs *
       c_business_account_register_rs_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   c_business_account_register_rs_free_unpacked
                     (c_business_account_register_rs *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*c_business_account_signed_in_rq_Closure)
                 (const c_business_account_signed_in_rq *message,
                  void *closure_data);
typedef void (*c_business_account_signed_in_rs_Closure)
                 (const c_business_account_signed_in_rs *message,
                  void *closure_data);
typedef void (*c_business_account_register_rq_Closure)
                 (const c_business_account_register_rq *message,
                  void *closure_data);
typedef void (*c_business_account_register_rs_Closure)
                 (const c_business_account_register_rs *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCEnumDescriptor    c_business_account_msg_descriptor;
extern const ProtobufCMessageDescriptor c_business_account_signed_in_rq_descriptor;
extern const ProtobufCEnumDescriptor    c_business_account_signed_in_rq_msg_descriptor;
extern const ProtobufCMessageDescriptor c_business_account_signed_in_rs_descriptor;
extern const ProtobufCEnumDescriptor    c_business_account_signed_in_rs_msg_descriptor;
extern const ProtobufCMessageDescriptor c_business_account_register_rq_descriptor;
extern const ProtobufCEnumDescriptor    c_business_account_register_rq_msg_descriptor;
extern const ProtobufCMessageDescriptor c_business_account_register_rs_descriptor;
extern const ProtobufCEnumDescriptor    c_business_account_register_rs_msg_descriptor;

PROTOBUF_C_END_DECLS


#endif  /* PROTOBUF_c_5fbusiness_5faccount_2eproto_INCLUDED */
