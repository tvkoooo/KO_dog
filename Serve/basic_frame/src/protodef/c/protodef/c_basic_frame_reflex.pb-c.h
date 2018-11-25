/* Generated by the protocol buffer compiler.  DO NOT EDIT! */

#ifndef PROTOBUF_C_c_5fbasic_5fframe_5freflex_2eproto_INCLUDED
#define PROTOBUF_C_c_5fbasic_5fframe_5freflex_2eproto_INCLUDED

#include <google/protobuf-c/protobuf-c.h>

PROTOBUF_C_BEGIN_DECLS

#include "b_error.pb-c.h"

typedef struct _c_basic_frame_reflex_simulation_variable c_basic_frame_reflex_simulation_variable;
typedef struct _c_basic_frame_reflex_simulation_frame c_basic_frame_reflex_simulation_frame;
typedef struct _c_basic_frame_reflex_alloc_channel_rq c_basic_frame_reflex_alloc_channel_rq;
typedef struct _c_basic_frame_reflex_alloc_channel_rs c_basic_frame_reflex_alloc_channel_rs;
typedef struct _c_basic_frame_reflex_relax_channel_rq c_basic_frame_reflex_relax_channel_rq;
typedef struct _c_basic_frame_reflex_relax_channel_rs c_basic_frame_reflex_relax_channel_rs;
typedef struct _c_basic_frame_reflex_enter_channel_rq c_basic_frame_reflex_enter_channel_rq;
typedef struct _c_basic_frame_reflex_enter_channel_rs c_basic_frame_reflex_enter_channel_rs;
typedef struct _c_basic_frame_reflex_leave_channel_rq c_basic_frame_reflex_leave_channel_rq;
typedef struct _c_basic_frame_reflex_leave_channel_rs c_basic_frame_reflex_leave_channel_rs;
typedef struct _c_basic_frame_reflex_simulation_frame_nt c_basic_frame_reflex_simulation_frame_nt;


/* --- enums --- */

typedef enum _c_basic_frame_reflex_alloc_channel_rq_msg {
  c_basic_frame_reflex_alloc_channel_rq_msg_id = 16777472
} c_basic_frame_reflex_alloc_channel_rq_msg;
typedef enum _c_basic_frame_reflex_alloc_channel_rs_msg {
  c_basic_frame_reflex_alloc_channel_rs_msg_id = 16777473
} c_basic_frame_reflex_alloc_channel_rs_msg;
typedef enum _c_basic_frame_reflex_relax_channel_rq_msg {
  c_basic_frame_reflex_relax_channel_rq_msg_id = 16777472
} c_basic_frame_reflex_relax_channel_rq_msg;
typedef enum _c_basic_frame_reflex_relax_channel_rs_msg {
  c_basic_frame_reflex_relax_channel_rs_msg_id = 16777473
} c_basic_frame_reflex_relax_channel_rs_msg;
typedef enum _c_basic_frame_reflex_enter_channel_rq_msg {
  c_basic_frame_reflex_enter_channel_rq_msg_id = 16777472
} c_basic_frame_reflex_enter_channel_rq_msg;
typedef enum _c_basic_frame_reflex_enter_channel_rs_msg {
  c_basic_frame_reflex_enter_channel_rs_msg_id = 16777473
} c_basic_frame_reflex_enter_channel_rs_msg;
typedef enum _c_basic_frame_reflex_leave_channel_rq_msg {
  c_basic_frame_reflex_leave_channel_rq_msg_id = 16777472
} c_basic_frame_reflex_leave_channel_rq_msg;
typedef enum _c_basic_frame_reflex_leave_channel_rs_msg {
  c_basic_frame_reflex_leave_channel_rs_msg_id = 16777473
} c_basic_frame_reflex_leave_channel_rs_msg;
typedef enum _c_basic_frame_reflex_simulation_frame_nt_msg {
  c_basic_frame_reflex_simulation_frame_nt_msg_id = 16777475
} c_basic_frame_reflex_simulation_frame_nt_msg;
typedef enum _c_basic_frame_reflex_msg {
  c_basic_frame_reflex_msg_min_id = 33558784,
  c_basic_frame_reflex_msg_max_id = 33559039
} c_basic_frame_reflex_msg;

/* --- messages --- */

struct  _c_basic_frame_reflex_simulation_variable
{
  ProtobufCMessage base;
  unsigned long long int uid;
  size_t n_commands;
  ProtobufCBinaryData *commands;
};
#define c_basic_frame_reflex_simulation_variable_Init \
 { PROTOBUF_C_MESSAGE_INIT (&c_basic_frame_reflex_simulation_variable_descriptor) \
    , 0, 0,NULL }


struct  _c_basic_frame_reflex_simulation_frame
{
  ProtobufCMessage base;
  unsigned long long int frame_number;
  size_t n_variables;
  c_basic_frame_reflex_simulation_variable **variables;
};
#define c_basic_frame_reflex_simulation_frame_Init \
 { PROTOBUF_C_MESSAGE_INIT (&c_basic_frame_reflex_simulation_frame_descriptor) \
    , 0, 0,NULL }


struct  _c_basic_frame_reflex_alloc_channel_rq
{
  ProtobufCMessage base;
};
#define c_basic_frame_reflex_alloc_channel_rq_Init \
 { PROTOBUF_C_MESSAGE_INIT (&c_basic_frame_reflex_alloc_channel_rq_descriptor) \
     }


struct  _c_basic_frame_reflex_alloc_channel_rs
{
  ProtobufCMessage base;
  b_error_info *error;
};
#define c_basic_frame_reflex_alloc_channel_rs_Init \
 { PROTOBUF_C_MESSAGE_INIT (&c_basic_frame_reflex_alloc_channel_rs_descriptor) \
    , NULL }


struct  _c_basic_frame_reflex_relax_channel_rq
{
  ProtobufCMessage base;
};
#define c_basic_frame_reflex_relax_channel_rq_Init \
 { PROTOBUF_C_MESSAGE_INIT (&c_basic_frame_reflex_relax_channel_rq_descriptor) \
     }


struct  _c_basic_frame_reflex_relax_channel_rs
{
  ProtobufCMessage base;
  b_error_info *error;
};
#define c_basic_frame_reflex_relax_channel_rs_Init \
 { PROTOBUF_C_MESSAGE_INIT (&c_basic_frame_reflex_relax_channel_rs_descriptor) \
    , NULL }


struct  _c_basic_frame_reflex_enter_channel_rq
{
  ProtobufCMessage base;
};
#define c_basic_frame_reflex_enter_channel_rq_Init \
 { PROTOBUF_C_MESSAGE_INIT (&c_basic_frame_reflex_enter_channel_rq_descriptor) \
     }


struct  _c_basic_frame_reflex_enter_channel_rs
{
  ProtobufCMessage base;
  b_error_info *error;
};
#define c_basic_frame_reflex_enter_channel_rs_Init \
 { PROTOBUF_C_MESSAGE_INIT (&c_basic_frame_reflex_enter_channel_rs_descriptor) \
    , NULL }


struct  _c_basic_frame_reflex_leave_channel_rq
{
  ProtobufCMessage base;
};
#define c_basic_frame_reflex_leave_channel_rq_Init \
 { PROTOBUF_C_MESSAGE_INIT (&c_basic_frame_reflex_leave_channel_rq_descriptor) \
     }


struct  _c_basic_frame_reflex_leave_channel_rs
{
  ProtobufCMessage base;
  b_error_info *error;
};
#define c_basic_frame_reflex_leave_channel_rs_Init \
 { PROTOBUF_C_MESSAGE_INIT (&c_basic_frame_reflex_leave_channel_rs_descriptor) \
    , NULL }


struct  _c_basic_frame_reflex_simulation_frame_nt
{
  ProtobufCMessage base;
  unsigned long long int frame_number;
  size_t n_variables;
  c_basic_frame_reflex_simulation_variable **variables;
};
#define c_basic_frame_reflex_simulation_frame_nt_Init \
 { PROTOBUF_C_MESSAGE_INIT (&c_basic_frame_reflex_simulation_frame_nt_descriptor) \
    , 0, 0,NULL }


/* c_basic_frame_reflex_simulation_variable methods */
void   c_basic_frame_reflex_simulation_variable_init
                     (c_basic_frame_reflex_simulation_variable         *message);
size_t c_basic_frame_reflex_simulation_variable_get_packed_size
                     (const c_basic_frame_reflex_simulation_variable   *message);
size_t c_basic_frame_reflex_simulation_variable_pack
                     (const c_basic_frame_reflex_simulation_variable   *message,
                      unsigned char             *out);
size_t c_basic_frame_reflex_simulation_variable_pack_to_buffer
                     (const c_basic_frame_reflex_simulation_variable   *message,
                      ProtobufCBuffer     *buffer);
c_basic_frame_reflex_simulation_variable *
       c_basic_frame_reflex_simulation_variable_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   c_basic_frame_reflex_simulation_variable_free_unpacked
                     (c_basic_frame_reflex_simulation_variable *message,
                      ProtobufCAllocator *allocator);
/* c_basic_frame_reflex_simulation_frame methods */
void   c_basic_frame_reflex_simulation_frame_init
                     (c_basic_frame_reflex_simulation_frame         *message);
size_t c_basic_frame_reflex_simulation_frame_get_packed_size
                     (const c_basic_frame_reflex_simulation_frame   *message);
size_t c_basic_frame_reflex_simulation_frame_pack
                     (const c_basic_frame_reflex_simulation_frame   *message,
                      unsigned char             *out);
size_t c_basic_frame_reflex_simulation_frame_pack_to_buffer
                     (const c_basic_frame_reflex_simulation_frame   *message,
                      ProtobufCBuffer     *buffer);
c_basic_frame_reflex_simulation_frame *
       c_basic_frame_reflex_simulation_frame_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   c_basic_frame_reflex_simulation_frame_free_unpacked
                     (c_basic_frame_reflex_simulation_frame *message,
                      ProtobufCAllocator *allocator);
/* c_basic_frame_reflex_alloc_channel_rq methods */
void   c_basic_frame_reflex_alloc_channel_rq_init
                     (c_basic_frame_reflex_alloc_channel_rq         *message);
size_t c_basic_frame_reflex_alloc_channel_rq_get_packed_size
                     (const c_basic_frame_reflex_alloc_channel_rq   *message);
size_t c_basic_frame_reflex_alloc_channel_rq_pack
                     (const c_basic_frame_reflex_alloc_channel_rq   *message,
                      unsigned char             *out);
size_t c_basic_frame_reflex_alloc_channel_rq_pack_to_buffer
                     (const c_basic_frame_reflex_alloc_channel_rq   *message,
                      ProtobufCBuffer     *buffer);
c_basic_frame_reflex_alloc_channel_rq *
       c_basic_frame_reflex_alloc_channel_rq_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   c_basic_frame_reflex_alloc_channel_rq_free_unpacked
                     (c_basic_frame_reflex_alloc_channel_rq *message,
                      ProtobufCAllocator *allocator);
/* c_basic_frame_reflex_alloc_channel_rs methods */
void   c_basic_frame_reflex_alloc_channel_rs_init
                     (c_basic_frame_reflex_alloc_channel_rs         *message);
size_t c_basic_frame_reflex_alloc_channel_rs_get_packed_size
                     (const c_basic_frame_reflex_alloc_channel_rs   *message);
size_t c_basic_frame_reflex_alloc_channel_rs_pack
                     (const c_basic_frame_reflex_alloc_channel_rs   *message,
                      unsigned char             *out);
size_t c_basic_frame_reflex_alloc_channel_rs_pack_to_buffer
                     (const c_basic_frame_reflex_alloc_channel_rs   *message,
                      ProtobufCBuffer     *buffer);
c_basic_frame_reflex_alloc_channel_rs *
       c_basic_frame_reflex_alloc_channel_rs_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   c_basic_frame_reflex_alloc_channel_rs_free_unpacked
                     (c_basic_frame_reflex_alloc_channel_rs *message,
                      ProtobufCAllocator *allocator);
/* c_basic_frame_reflex_relax_channel_rq methods */
void   c_basic_frame_reflex_relax_channel_rq_init
                     (c_basic_frame_reflex_relax_channel_rq         *message);
size_t c_basic_frame_reflex_relax_channel_rq_get_packed_size
                     (const c_basic_frame_reflex_relax_channel_rq   *message);
size_t c_basic_frame_reflex_relax_channel_rq_pack
                     (const c_basic_frame_reflex_relax_channel_rq   *message,
                      unsigned char             *out);
size_t c_basic_frame_reflex_relax_channel_rq_pack_to_buffer
                     (const c_basic_frame_reflex_relax_channel_rq   *message,
                      ProtobufCBuffer     *buffer);
c_basic_frame_reflex_relax_channel_rq *
       c_basic_frame_reflex_relax_channel_rq_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   c_basic_frame_reflex_relax_channel_rq_free_unpacked
                     (c_basic_frame_reflex_relax_channel_rq *message,
                      ProtobufCAllocator *allocator);
/* c_basic_frame_reflex_relax_channel_rs methods */
void   c_basic_frame_reflex_relax_channel_rs_init
                     (c_basic_frame_reflex_relax_channel_rs         *message);
size_t c_basic_frame_reflex_relax_channel_rs_get_packed_size
                     (const c_basic_frame_reflex_relax_channel_rs   *message);
size_t c_basic_frame_reflex_relax_channel_rs_pack
                     (const c_basic_frame_reflex_relax_channel_rs   *message,
                      unsigned char             *out);
size_t c_basic_frame_reflex_relax_channel_rs_pack_to_buffer
                     (const c_basic_frame_reflex_relax_channel_rs   *message,
                      ProtobufCBuffer     *buffer);
c_basic_frame_reflex_relax_channel_rs *
       c_basic_frame_reflex_relax_channel_rs_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   c_basic_frame_reflex_relax_channel_rs_free_unpacked
                     (c_basic_frame_reflex_relax_channel_rs *message,
                      ProtobufCAllocator *allocator);
/* c_basic_frame_reflex_enter_channel_rq methods */
void   c_basic_frame_reflex_enter_channel_rq_init
                     (c_basic_frame_reflex_enter_channel_rq         *message);
size_t c_basic_frame_reflex_enter_channel_rq_get_packed_size
                     (const c_basic_frame_reflex_enter_channel_rq   *message);
size_t c_basic_frame_reflex_enter_channel_rq_pack
                     (const c_basic_frame_reflex_enter_channel_rq   *message,
                      unsigned char             *out);
size_t c_basic_frame_reflex_enter_channel_rq_pack_to_buffer
                     (const c_basic_frame_reflex_enter_channel_rq   *message,
                      ProtobufCBuffer     *buffer);
c_basic_frame_reflex_enter_channel_rq *
       c_basic_frame_reflex_enter_channel_rq_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   c_basic_frame_reflex_enter_channel_rq_free_unpacked
                     (c_basic_frame_reflex_enter_channel_rq *message,
                      ProtobufCAllocator *allocator);
/* c_basic_frame_reflex_enter_channel_rs methods */
void   c_basic_frame_reflex_enter_channel_rs_init
                     (c_basic_frame_reflex_enter_channel_rs         *message);
size_t c_basic_frame_reflex_enter_channel_rs_get_packed_size
                     (const c_basic_frame_reflex_enter_channel_rs   *message);
size_t c_basic_frame_reflex_enter_channel_rs_pack
                     (const c_basic_frame_reflex_enter_channel_rs   *message,
                      unsigned char             *out);
size_t c_basic_frame_reflex_enter_channel_rs_pack_to_buffer
                     (const c_basic_frame_reflex_enter_channel_rs   *message,
                      ProtobufCBuffer     *buffer);
c_basic_frame_reflex_enter_channel_rs *
       c_basic_frame_reflex_enter_channel_rs_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   c_basic_frame_reflex_enter_channel_rs_free_unpacked
                     (c_basic_frame_reflex_enter_channel_rs *message,
                      ProtobufCAllocator *allocator);
/* c_basic_frame_reflex_leave_channel_rq methods */
void   c_basic_frame_reflex_leave_channel_rq_init
                     (c_basic_frame_reflex_leave_channel_rq         *message);
size_t c_basic_frame_reflex_leave_channel_rq_get_packed_size
                     (const c_basic_frame_reflex_leave_channel_rq   *message);
size_t c_basic_frame_reflex_leave_channel_rq_pack
                     (const c_basic_frame_reflex_leave_channel_rq   *message,
                      unsigned char             *out);
size_t c_basic_frame_reflex_leave_channel_rq_pack_to_buffer
                     (const c_basic_frame_reflex_leave_channel_rq   *message,
                      ProtobufCBuffer     *buffer);
c_basic_frame_reflex_leave_channel_rq *
       c_basic_frame_reflex_leave_channel_rq_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   c_basic_frame_reflex_leave_channel_rq_free_unpacked
                     (c_basic_frame_reflex_leave_channel_rq *message,
                      ProtobufCAllocator *allocator);
/* c_basic_frame_reflex_leave_channel_rs methods */
void   c_basic_frame_reflex_leave_channel_rs_init
                     (c_basic_frame_reflex_leave_channel_rs         *message);
size_t c_basic_frame_reflex_leave_channel_rs_get_packed_size
                     (const c_basic_frame_reflex_leave_channel_rs   *message);
size_t c_basic_frame_reflex_leave_channel_rs_pack
                     (const c_basic_frame_reflex_leave_channel_rs   *message,
                      unsigned char             *out);
size_t c_basic_frame_reflex_leave_channel_rs_pack_to_buffer
                     (const c_basic_frame_reflex_leave_channel_rs   *message,
                      ProtobufCBuffer     *buffer);
c_basic_frame_reflex_leave_channel_rs *
       c_basic_frame_reflex_leave_channel_rs_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   c_basic_frame_reflex_leave_channel_rs_free_unpacked
                     (c_basic_frame_reflex_leave_channel_rs *message,
                      ProtobufCAllocator *allocator);
/* c_basic_frame_reflex_simulation_frame_nt methods */
void   c_basic_frame_reflex_simulation_frame_nt_init
                     (c_basic_frame_reflex_simulation_frame_nt         *message);
size_t c_basic_frame_reflex_simulation_frame_nt_get_packed_size
                     (const c_basic_frame_reflex_simulation_frame_nt   *message);
size_t c_basic_frame_reflex_simulation_frame_nt_pack
                     (const c_basic_frame_reflex_simulation_frame_nt   *message,
                      unsigned char             *out);
size_t c_basic_frame_reflex_simulation_frame_nt_pack_to_buffer
                     (const c_basic_frame_reflex_simulation_frame_nt   *message,
                      ProtobufCBuffer     *buffer);
c_basic_frame_reflex_simulation_frame_nt *
       c_basic_frame_reflex_simulation_frame_nt_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   c_basic_frame_reflex_simulation_frame_nt_free_unpacked
                     (c_basic_frame_reflex_simulation_frame_nt *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*c_basic_frame_reflex_simulation_variable_Closure)
                 (const c_basic_frame_reflex_simulation_variable *message,
                  void *closure_data);
typedef void (*c_basic_frame_reflex_simulation_frame_Closure)
                 (const c_basic_frame_reflex_simulation_frame *message,
                  void *closure_data);
typedef void (*c_basic_frame_reflex_alloc_channel_rq_Closure)
                 (const c_basic_frame_reflex_alloc_channel_rq *message,
                  void *closure_data);
typedef void (*c_basic_frame_reflex_alloc_channel_rs_Closure)
                 (const c_basic_frame_reflex_alloc_channel_rs *message,
                  void *closure_data);
typedef void (*c_basic_frame_reflex_relax_channel_rq_Closure)
                 (const c_basic_frame_reflex_relax_channel_rq *message,
                  void *closure_data);
typedef void (*c_basic_frame_reflex_relax_channel_rs_Closure)
                 (const c_basic_frame_reflex_relax_channel_rs *message,
                  void *closure_data);
typedef void (*c_basic_frame_reflex_enter_channel_rq_Closure)
                 (const c_basic_frame_reflex_enter_channel_rq *message,
                  void *closure_data);
typedef void (*c_basic_frame_reflex_enter_channel_rs_Closure)
                 (const c_basic_frame_reflex_enter_channel_rs *message,
                  void *closure_data);
typedef void (*c_basic_frame_reflex_leave_channel_rq_Closure)
                 (const c_basic_frame_reflex_leave_channel_rq *message,
                  void *closure_data);
typedef void (*c_basic_frame_reflex_leave_channel_rs_Closure)
                 (const c_basic_frame_reflex_leave_channel_rs *message,
                  void *closure_data);
typedef void (*c_basic_frame_reflex_simulation_frame_nt_Closure)
                 (const c_basic_frame_reflex_simulation_frame_nt *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCEnumDescriptor    c_basic_frame_reflex_msg_descriptor;
extern const ProtobufCMessageDescriptor c_basic_frame_reflex_simulation_variable_descriptor;
extern const ProtobufCMessageDescriptor c_basic_frame_reflex_simulation_frame_descriptor;
extern const ProtobufCMessageDescriptor c_basic_frame_reflex_alloc_channel_rq_descriptor;
extern const ProtobufCEnumDescriptor    c_basic_frame_reflex_alloc_channel_rq_msg_descriptor;
extern const ProtobufCMessageDescriptor c_basic_frame_reflex_alloc_channel_rs_descriptor;
extern const ProtobufCEnumDescriptor    c_basic_frame_reflex_alloc_channel_rs_msg_descriptor;
extern const ProtobufCMessageDescriptor c_basic_frame_reflex_relax_channel_rq_descriptor;
extern const ProtobufCEnumDescriptor    c_basic_frame_reflex_relax_channel_rq_msg_descriptor;
extern const ProtobufCMessageDescriptor c_basic_frame_reflex_relax_channel_rs_descriptor;
extern const ProtobufCEnumDescriptor    c_basic_frame_reflex_relax_channel_rs_msg_descriptor;
extern const ProtobufCMessageDescriptor c_basic_frame_reflex_enter_channel_rq_descriptor;
extern const ProtobufCEnumDescriptor    c_basic_frame_reflex_enter_channel_rq_msg_descriptor;
extern const ProtobufCMessageDescriptor c_basic_frame_reflex_enter_channel_rs_descriptor;
extern const ProtobufCEnumDescriptor    c_basic_frame_reflex_enter_channel_rs_msg_descriptor;
extern const ProtobufCMessageDescriptor c_basic_frame_reflex_leave_channel_rq_descriptor;
extern const ProtobufCEnumDescriptor    c_basic_frame_reflex_leave_channel_rq_msg_descriptor;
extern const ProtobufCMessageDescriptor c_basic_frame_reflex_leave_channel_rs_descriptor;
extern const ProtobufCEnumDescriptor    c_basic_frame_reflex_leave_channel_rs_msg_descriptor;
extern const ProtobufCMessageDescriptor c_basic_frame_reflex_simulation_frame_nt_descriptor;
extern const ProtobufCEnumDescriptor    c_basic_frame_reflex_simulation_frame_nt_msg_descriptor;

PROTOBUF_C_END_DECLS


#endif  /* PROTOBUF_c_5fbasic_5fframe_5freflex_2eproto_INCLUDED */
