/* Generated by the protocol buffer compiler.  DO NOT EDIT! */

#ifndef PROTOBUF_C_s_5fcontrol_2eproto_INCLUDED
#define PROTOBUF_C_s_5fcontrol_2eproto_INCLUDED

#include <google/protobuf-c/protobuf-c.h>

PROTOBUF_C_BEGIN_DECLS

#include "b_error.pb-c.h"

typedef struct _s_control_set_logger_rq s_control_set_logger_rq;
typedef struct _s_control_set_logger_rs s_control_set_logger_rs;
typedef struct _s_control_get_logger_rq s_control_get_logger_rq;
typedef struct _s_control_get_logger_rs s_control_get_logger_rs;


/* --- enums --- */

typedef enum _s_control_set_logger_rq_msg {
  s_control_set_logger_rq_msg_id = 16777472
} s_control_set_logger_rq_msg;
typedef enum _s_control_set_logger_rs_msg {
  s_control_set_logger_rs_msg_id = 16777473
} s_control_set_logger_rs_msg;
typedef enum _s_control_get_logger_rq_msg {
  s_control_get_logger_rq_msg_id = 16777474
} s_control_get_logger_rq_msg;
typedef enum _s_control_get_logger_rs_msg {
  s_control_get_logger_rs_msg_id = 16777475
} s_control_get_logger_rs_msg;
typedef enum _s_control_msg {
  s_control_msg_min_id = 16777472,
  s_control_msg_max_id = 16777727
} s_control_msg;

/* --- messages --- */

struct  _s_control_set_logger_rq
{
  ProtobufCMessage base;
  unsigned int level;
};
#define s_control_set_logger_rq_Init \
 { PROTOBUF_C_MESSAGE_INIT (&s_control_set_logger_rq_descriptor) \
    , 0 }


struct  _s_control_set_logger_rs
{
  ProtobufCMessage base;
  b_error_info *error;
  unsigned int level;
};
#define s_control_set_logger_rs_Init \
 { PROTOBUF_C_MESSAGE_INIT (&s_control_set_logger_rs_descriptor) \
    , NULL, 0 }


struct  _s_control_get_logger_rq
{
  ProtobufCMessage base;
};
#define s_control_get_logger_rq_Init \
 { PROTOBUF_C_MESSAGE_INIT (&s_control_get_logger_rq_descriptor) \
     }


struct  _s_control_get_logger_rs
{
  ProtobufCMessage base;
  b_error_info *error;
  unsigned int level;
};
#define s_control_get_logger_rs_Init \
 { PROTOBUF_C_MESSAGE_INIT (&s_control_get_logger_rs_descriptor) \
    , NULL, 0 }


/* s_control_set_logger_rq methods */
void   s_control_set_logger_rq_init
                     (s_control_set_logger_rq         *message);
size_t s_control_set_logger_rq_get_packed_size
                     (const s_control_set_logger_rq   *message);
size_t s_control_set_logger_rq_pack
                     (const s_control_set_logger_rq   *message,
                      unsigned char             *out);
size_t s_control_set_logger_rq_pack_to_buffer
                     (const s_control_set_logger_rq   *message,
                      ProtobufCBuffer     *buffer);
s_control_set_logger_rq *
       s_control_set_logger_rq_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   s_control_set_logger_rq_free_unpacked
                     (s_control_set_logger_rq *message,
                      ProtobufCAllocator *allocator);
/* s_control_set_logger_rs methods */
void   s_control_set_logger_rs_init
                     (s_control_set_logger_rs         *message);
size_t s_control_set_logger_rs_get_packed_size
                     (const s_control_set_logger_rs   *message);
size_t s_control_set_logger_rs_pack
                     (const s_control_set_logger_rs   *message,
                      unsigned char             *out);
size_t s_control_set_logger_rs_pack_to_buffer
                     (const s_control_set_logger_rs   *message,
                      ProtobufCBuffer     *buffer);
s_control_set_logger_rs *
       s_control_set_logger_rs_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   s_control_set_logger_rs_free_unpacked
                     (s_control_set_logger_rs *message,
                      ProtobufCAllocator *allocator);
/* s_control_get_logger_rq methods */
void   s_control_get_logger_rq_init
                     (s_control_get_logger_rq         *message);
size_t s_control_get_logger_rq_get_packed_size
                     (const s_control_get_logger_rq   *message);
size_t s_control_get_logger_rq_pack
                     (const s_control_get_logger_rq   *message,
                      unsigned char             *out);
size_t s_control_get_logger_rq_pack_to_buffer
                     (const s_control_get_logger_rq   *message,
                      ProtobufCBuffer     *buffer);
s_control_get_logger_rq *
       s_control_get_logger_rq_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   s_control_get_logger_rq_free_unpacked
                     (s_control_get_logger_rq *message,
                      ProtobufCAllocator *allocator);
/* s_control_get_logger_rs methods */
void   s_control_get_logger_rs_init
                     (s_control_get_logger_rs         *message);
size_t s_control_get_logger_rs_get_packed_size
                     (const s_control_get_logger_rs   *message);
size_t s_control_get_logger_rs_pack
                     (const s_control_get_logger_rs   *message,
                      unsigned char             *out);
size_t s_control_get_logger_rs_pack_to_buffer
                     (const s_control_get_logger_rs   *message,
                      ProtobufCBuffer     *buffer);
s_control_get_logger_rs *
       s_control_get_logger_rs_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   s_control_get_logger_rs_free_unpacked
                     (s_control_get_logger_rs *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*s_control_set_logger_rq_Closure)
                 (const s_control_set_logger_rq *message,
                  void *closure_data);
typedef void (*s_control_set_logger_rs_Closure)
                 (const s_control_set_logger_rs *message,
                  void *closure_data);
typedef void (*s_control_get_logger_rq_Closure)
                 (const s_control_get_logger_rq *message,
                  void *closure_data);
typedef void (*s_control_get_logger_rs_Closure)
                 (const s_control_get_logger_rs *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCEnumDescriptor    s_control_msg_descriptor;
extern const ProtobufCMessageDescriptor s_control_set_logger_rq_descriptor;
extern const ProtobufCEnumDescriptor    s_control_set_logger_rq_msg_descriptor;
extern const ProtobufCMessageDescriptor s_control_set_logger_rs_descriptor;
extern const ProtobufCEnumDescriptor    s_control_set_logger_rs_msg_descriptor;
extern const ProtobufCMessageDescriptor s_control_get_logger_rq_descriptor;
extern const ProtobufCEnumDescriptor    s_control_get_logger_rq_msg_descriptor;
extern const ProtobufCMessageDescriptor s_control_get_logger_rs_descriptor;
extern const ProtobufCEnumDescriptor    s_control_get_logger_rs_msg_descriptor;

PROTOBUF_C_END_DECLS


#endif  /* PROTOBUF_s_5fcontrol_2eproto_INCLUDED */
