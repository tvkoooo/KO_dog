/* Generated by the protocol buffer compiler.  DO NOT EDIT! */

#ifndef PROTOBUF_C_s_5fproxy_5fcurl_2eproto_INCLUDED
#define PROTOBUF_C_s_5fproxy_5fcurl_2eproto_INCLUDED

#include <google/protobuf-c/protobuf-c.h>

PROTOBUF_C_BEGIN_DECLS

#include "b_error.pb-c.h"

typedef struct _s_proxy_curl_json_data_rq s_proxy_curl_json_data_rq;
typedef struct _s_proxy_curl_json_data_rs s_proxy_curl_json_data_rs;


/* --- enums --- */

typedef enum _s_proxy_curl_json_data_rq_msg {
  s_proxy_curl_json_data_rq_msg_id = 16777472
} s_proxy_curl_json_data_rq_msg;
typedef enum _s_proxy_curl_json_data_rs_msg {
  s_proxy_curl_json_data_rs_msg_id = 16777473
} s_proxy_curl_json_data_rs_msg;
typedef enum _s_proxy_curl_msg {
  s_proxy_curl_msg_min_id = 16777472,
  s_proxy_curl_msg_max_id = 16777727
} s_proxy_curl_msg;

/* --- messages --- */

struct  _s_proxy_curl_json_data_rq
{
  ProtobufCMessage base;
  ProtobufCBinaryData buffer;
};
#define s_proxy_curl_json_data_rq_Init \
 { PROTOBUF_C_MESSAGE_INIT (&s_proxy_curl_json_data_rq_descriptor) \
    , {0,NULL} }


struct  _s_proxy_curl_json_data_rs
{
  ProtobufCMessage base;
  b_error_info *error;
  unsigned int curl_code;
  ProtobufCBinaryData buffer;
};
#define s_proxy_curl_json_data_rs_Init \
 { PROTOBUF_C_MESSAGE_INIT (&s_proxy_curl_json_data_rs_descriptor) \
    , NULL, 0, {0,NULL} }


/* s_proxy_curl_json_data_rq methods */
void   s_proxy_curl_json_data_rq_init
                     (s_proxy_curl_json_data_rq         *message);
size_t s_proxy_curl_json_data_rq_get_packed_size
                     (const s_proxy_curl_json_data_rq   *message);
size_t s_proxy_curl_json_data_rq_pack
                     (const s_proxy_curl_json_data_rq   *message,
                      unsigned char             *out);
size_t s_proxy_curl_json_data_rq_pack_to_buffer
                     (const s_proxy_curl_json_data_rq   *message,
                      ProtobufCBuffer     *buffer);
s_proxy_curl_json_data_rq *
       s_proxy_curl_json_data_rq_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   s_proxy_curl_json_data_rq_free_unpacked
                     (s_proxy_curl_json_data_rq *message,
                      ProtobufCAllocator *allocator);
/* s_proxy_curl_json_data_rs methods */
void   s_proxy_curl_json_data_rs_init
                     (s_proxy_curl_json_data_rs         *message);
size_t s_proxy_curl_json_data_rs_get_packed_size
                     (const s_proxy_curl_json_data_rs   *message);
size_t s_proxy_curl_json_data_rs_pack
                     (const s_proxy_curl_json_data_rs   *message,
                      unsigned char             *out);
size_t s_proxy_curl_json_data_rs_pack_to_buffer
                     (const s_proxy_curl_json_data_rs   *message,
                      ProtobufCBuffer     *buffer);
s_proxy_curl_json_data_rs *
       s_proxy_curl_json_data_rs_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   s_proxy_curl_json_data_rs_free_unpacked
                     (s_proxy_curl_json_data_rs *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*s_proxy_curl_json_data_rq_Closure)
                 (const s_proxy_curl_json_data_rq *message,
                  void *closure_data);
typedef void (*s_proxy_curl_json_data_rs_Closure)
                 (const s_proxy_curl_json_data_rs *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCEnumDescriptor    s_proxy_curl_msg_descriptor;
extern const ProtobufCMessageDescriptor s_proxy_curl_json_data_rq_descriptor;
extern const ProtobufCEnumDescriptor    s_proxy_curl_json_data_rq_msg_descriptor;
extern const ProtobufCMessageDescriptor s_proxy_curl_json_data_rs_descriptor;
extern const ProtobufCEnumDescriptor    s_proxy_curl_json_data_rs_msg_descriptor;

PROTOBUF_C_END_DECLS


#endif  /* PROTOBUF_s_5fproxy_5fcurl_2eproto_INCLUDED */
