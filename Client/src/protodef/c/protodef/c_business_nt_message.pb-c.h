/* Generated by the protocol buffer compiler.  DO NOT EDIT! */

#ifndef PROTOBUF_C_c_5fbusiness_5fnt_5fmessage_2eproto_INCLUDED
#define PROTOBUF_C_c_5fbusiness_5fnt_5fmessage_2eproto_INCLUDED

#include <google/protobuf-c/protobuf-c.h>

PROTOBUF_C_BEGIN_DECLS

#include "b_error.pb-c.h"

typedef struct _c_business_nt_message_nt_message_consume_by_id_rq c_business_nt_message_nt_message_consume_by_id_rq;
typedef struct _c_business_nt_message_nt_message_consume_by_id_rs c_business_nt_message_nt_message_consume_by_id_rs;
typedef struct _c_business_nt_message_nt_message_consume_by_maxid_rq c_business_nt_message_nt_message_consume_by_maxid_rq;
typedef struct _c_business_nt_message_nt_message_consume_by_maxid_rs c_business_nt_message_nt_message_consume_by_maxid_rs;
typedef struct _c_business_nt_message_nt_message_read_note_id_rq c_business_nt_message_nt_message_read_note_id_rq;
typedef struct _c_business_nt_message_nt_message_read_note_id_rs c_business_nt_message_nt_message_read_note_id_rs;
typedef struct _c_business_nt_message_nt_message_all_unread_rq c_business_nt_message_nt_message_all_unread_rq;
typedef struct _c_business_nt_message_nt_message_all_unread_rs c_business_nt_message_nt_message_all_unread_rs;
typedef struct _c_business_nt_message_nt_message_all_unread_nt c_business_nt_message_nt_message_all_unread_nt;


/* --- enums --- */

typedef enum _c_business_nt_message_nt_message_consume_by_id_rq_msg {
  c_business_nt_message_nt_message_consume_by_id_rq_msg_id = 33554433
} c_business_nt_message_nt_message_consume_by_id_rq_msg;
typedef enum _c_business_nt_message_nt_message_consume_by_id_rs_msg {
  c_business_nt_message_nt_message_consume_by_id_rs_msg_id = 33554434
} c_business_nt_message_nt_message_consume_by_id_rs_msg;
typedef enum _c_business_nt_message_nt_message_consume_by_maxid_rq_msg {
  c_business_nt_message_nt_message_consume_by_maxid_rq_msg_id = 33554435
} c_business_nt_message_nt_message_consume_by_maxid_rq_msg;
typedef enum _c_business_nt_message_nt_message_consume_by_maxid_rs_msg {
  c_business_nt_message_nt_message_consume_by_maxid_rs_msg_id = 33554436
} c_business_nt_message_nt_message_consume_by_maxid_rs_msg;
typedef enum _c_business_nt_message_nt_message_read_note_id_rq_msg {
  c_business_nt_message_nt_message_read_note_id_rq_msg_id = 33554433
} c_business_nt_message_nt_message_read_note_id_rq_msg;
typedef enum _c_business_nt_message_nt_message_read_note_id_rs_msg {
  c_business_nt_message_nt_message_read_note_id_rs_msg_id = 33554434
} c_business_nt_message_nt_message_read_note_id_rs_msg;
typedef enum _c_business_nt_message_nt_message_all_unread_rq_msg {
  c_business_nt_message_nt_message_all_unread_rq_msg_id = 33554435
} c_business_nt_message_nt_message_all_unread_rq_msg;
typedef enum _c_business_nt_message_nt_message_all_unread_rs_msg {
  c_business_nt_message_nt_message_all_unread_rs_msg_id = 33554436
} c_business_nt_message_nt_message_all_unread_rs_msg;
typedef enum _c_business_nt_message_nt_message_all_unread_nt_msg {
  c_business_nt_message_nt_message_all_unread_nt_msg_id = 33554437
} c_business_nt_message_nt_message_all_unread_nt_msg;
typedef enum _c_business_nt_message_msg {
  c_business_nt_message_msg_min_id = 33554432,
  c_business_nt_message_msg_max_id = 33554687
} c_business_nt_message_msg;

/* --- messages --- */

struct  _c_business_nt_message_nt_message_consume_by_id_rq
{
  ProtobufCMessage base;
  unsigned long long int user_id;
  unsigned long long int note_id;
};
#define c_business_nt_message_nt_message_consume_by_id_rq_Init \
 { PROTOBUF_C_MESSAGE_INIT (&c_business_nt_message_nt_message_consume_by_id_rq_descriptor) \
    , 0, 0 }


struct  _c_business_nt_message_nt_message_consume_by_id_rs
{
  ProtobufCMessage base;
  b_error_info *error;
  unsigned long long int user_id;
  unsigned long long int note_id;
};
#define c_business_nt_message_nt_message_consume_by_id_rs_Init \
 { PROTOBUF_C_MESSAGE_INIT (&c_business_nt_message_nt_message_consume_by_id_rs_descriptor) \
    , NULL, 0, 0 }


struct  _c_business_nt_message_nt_message_consume_by_maxid_rq
{
  ProtobufCMessage base;
  unsigned long long int user_id;
  unsigned long long int note_maxid;
};
#define c_business_nt_message_nt_message_consume_by_maxid_rq_Init \
 { PROTOBUF_C_MESSAGE_INIT (&c_business_nt_message_nt_message_consume_by_maxid_rq_descriptor) \
    , 0, 0 }


struct  _c_business_nt_message_nt_message_consume_by_maxid_rs
{
  ProtobufCMessage base;
  b_error_info *error;
  unsigned long long int user_id;
  unsigned long long int note_maxid;
};
#define c_business_nt_message_nt_message_consume_by_maxid_rs_Init \
 { PROTOBUF_C_MESSAGE_INIT (&c_business_nt_message_nt_message_consume_by_maxid_rs_descriptor) \
    , NULL, 0, 0 }


struct  _c_business_nt_message_nt_message_read_note_id_rq
{
  ProtobufCMessage base;
  unsigned long long int user_id;
  unsigned long long int note_id;
};
#define c_business_nt_message_nt_message_read_note_id_rq_Init \
 { PROTOBUF_C_MESSAGE_INIT (&c_business_nt_message_nt_message_read_note_id_rq_descriptor) \
    , 0, 0 }


struct  _c_business_nt_message_nt_message_read_note_id_rs
{
  ProtobufCMessage base;
  b_error_info *error;
  unsigned long long int user_id;
  unsigned long long int note_id;
};
#define c_business_nt_message_nt_message_read_note_id_rs_Init \
 { PROTOBUF_C_MESSAGE_INIT (&c_business_nt_message_nt_message_read_note_id_rs_descriptor) \
    , NULL, 0, 0 }


struct  _c_business_nt_message_nt_message_all_unread_rq
{
  ProtobufCMessage base;
  unsigned long long int user_id;
};
#define c_business_nt_message_nt_message_all_unread_rq_Init \
 { PROTOBUF_C_MESSAGE_INIT (&c_business_nt_message_nt_message_all_unread_rq_descriptor) \
    , 0 }


struct  _c_business_nt_message_nt_message_all_unread_rs
{
  ProtobufCMessage base;
  b_error_info *error;
  unsigned long long int user_id;
};
#define c_business_nt_message_nt_message_all_unread_rs_Init \
 { PROTOBUF_C_MESSAGE_INIT (&c_business_nt_message_nt_message_all_unread_rs_descriptor) \
    , NULL, 0 }


struct  _c_business_nt_message_nt_message_all_unread_nt
{
  ProtobufCMessage base;
  unsigned long long int user_id;
};
#define c_business_nt_message_nt_message_all_unread_nt_Init \
 { PROTOBUF_C_MESSAGE_INIT (&c_business_nt_message_nt_message_all_unread_nt_descriptor) \
    , 0 }


/* c_business_nt_message_nt_message_consume_by_id_rq methods */
void   c_business_nt_message_nt_message_consume_by_id_rq_init
                     (c_business_nt_message_nt_message_consume_by_id_rq         *message);
size_t c_business_nt_message_nt_message_consume_by_id_rq_get_packed_size
                     (const c_business_nt_message_nt_message_consume_by_id_rq   *message);
size_t c_business_nt_message_nt_message_consume_by_id_rq_pack
                     (const c_business_nt_message_nt_message_consume_by_id_rq   *message,
                      unsigned char             *out);
size_t c_business_nt_message_nt_message_consume_by_id_rq_pack_to_buffer
                     (const c_business_nt_message_nt_message_consume_by_id_rq   *message,
                      ProtobufCBuffer     *buffer);
c_business_nt_message_nt_message_consume_by_id_rq *
       c_business_nt_message_nt_message_consume_by_id_rq_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   c_business_nt_message_nt_message_consume_by_id_rq_free_unpacked
                     (c_business_nt_message_nt_message_consume_by_id_rq *message,
                      ProtobufCAllocator *allocator);
/* c_business_nt_message_nt_message_consume_by_id_rs methods */
void   c_business_nt_message_nt_message_consume_by_id_rs_init
                     (c_business_nt_message_nt_message_consume_by_id_rs         *message);
size_t c_business_nt_message_nt_message_consume_by_id_rs_get_packed_size
                     (const c_business_nt_message_nt_message_consume_by_id_rs   *message);
size_t c_business_nt_message_nt_message_consume_by_id_rs_pack
                     (const c_business_nt_message_nt_message_consume_by_id_rs   *message,
                      unsigned char             *out);
size_t c_business_nt_message_nt_message_consume_by_id_rs_pack_to_buffer
                     (const c_business_nt_message_nt_message_consume_by_id_rs   *message,
                      ProtobufCBuffer     *buffer);
c_business_nt_message_nt_message_consume_by_id_rs *
       c_business_nt_message_nt_message_consume_by_id_rs_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   c_business_nt_message_nt_message_consume_by_id_rs_free_unpacked
                     (c_business_nt_message_nt_message_consume_by_id_rs *message,
                      ProtobufCAllocator *allocator);
/* c_business_nt_message_nt_message_consume_by_maxid_rq methods */
void   c_business_nt_message_nt_message_consume_by_maxid_rq_init
                     (c_business_nt_message_nt_message_consume_by_maxid_rq         *message);
size_t c_business_nt_message_nt_message_consume_by_maxid_rq_get_packed_size
                     (const c_business_nt_message_nt_message_consume_by_maxid_rq   *message);
size_t c_business_nt_message_nt_message_consume_by_maxid_rq_pack
                     (const c_business_nt_message_nt_message_consume_by_maxid_rq   *message,
                      unsigned char             *out);
size_t c_business_nt_message_nt_message_consume_by_maxid_rq_pack_to_buffer
                     (const c_business_nt_message_nt_message_consume_by_maxid_rq   *message,
                      ProtobufCBuffer     *buffer);
c_business_nt_message_nt_message_consume_by_maxid_rq *
       c_business_nt_message_nt_message_consume_by_maxid_rq_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   c_business_nt_message_nt_message_consume_by_maxid_rq_free_unpacked
                     (c_business_nt_message_nt_message_consume_by_maxid_rq *message,
                      ProtobufCAllocator *allocator);
/* c_business_nt_message_nt_message_consume_by_maxid_rs methods */
void   c_business_nt_message_nt_message_consume_by_maxid_rs_init
                     (c_business_nt_message_nt_message_consume_by_maxid_rs         *message);
size_t c_business_nt_message_nt_message_consume_by_maxid_rs_get_packed_size
                     (const c_business_nt_message_nt_message_consume_by_maxid_rs   *message);
size_t c_business_nt_message_nt_message_consume_by_maxid_rs_pack
                     (const c_business_nt_message_nt_message_consume_by_maxid_rs   *message,
                      unsigned char             *out);
size_t c_business_nt_message_nt_message_consume_by_maxid_rs_pack_to_buffer
                     (const c_business_nt_message_nt_message_consume_by_maxid_rs   *message,
                      ProtobufCBuffer     *buffer);
c_business_nt_message_nt_message_consume_by_maxid_rs *
       c_business_nt_message_nt_message_consume_by_maxid_rs_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   c_business_nt_message_nt_message_consume_by_maxid_rs_free_unpacked
                     (c_business_nt_message_nt_message_consume_by_maxid_rs *message,
                      ProtobufCAllocator *allocator);
/* c_business_nt_message_nt_message_read_note_id_rq methods */
void   c_business_nt_message_nt_message_read_note_id_rq_init
                     (c_business_nt_message_nt_message_read_note_id_rq         *message);
size_t c_business_nt_message_nt_message_read_note_id_rq_get_packed_size
                     (const c_business_nt_message_nt_message_read_note_id_rq   *message);
size_t c_business_nt_message_nt_message_read_note_id_rq_pack
                     (const c_business_nt_message_nt_message_read_note_id_rq   *message,
                      unsigned char             *out);
size_t c_business_nt_message_nt_message_read_note_id_rq_pack_to_buffer
                     (const c_business_nt_message_nt_message_read_note_id_rq   *message,
                      ProtobufCBuffer     *buffer);
c_business_nt_message_nt_message_read_note_id_rq *
       c_business_nt_message_nt_message_read_note_id_rq_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   c_business_nt_message_nt_message_read_note_id_rq_free_unpacked
                     (c_business_nt_message_nt_message_read_note_id_rq *message,
                      ProtobufCAllocator *allocator);
/* c_business_nt_message_nt_message_read_note_id_rs methods */
void   c_business_nt_message_nt_message_read_note_id_rs_init
                     (c_business_nt_message_nt_message_read_note_id_rs         *message);
size_t c_business_nt_message_nt_message_read_note_id_rs_get_packed_size
                     (const c_business_nt_message_nt_message_read_note_id_rs   *message);
size_t c_business_nt_message_nt_message_read_note_id_rs_pack
                     (const c_business_nt_message_nt_message_read_note_id_rs   *message,
                      unsigned char             *out);
size_t c_business_nt_message_nt_message_read_note_id_rs_pack_to_buffer
                     (const c_business_nt_message_nt_message_read_note_id_rs   *message,
                      ProtobufCBuffer     *buffer);
c_business_nt_message_nt_message_read_note_id_rs *
       c_business_nt_message_nt_message_read_note_id_rs_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   c_business_nt_message_nt_message_read_note_id_rs_free_unpacked
                     (c_business_nt_message_nt_message_read_note_id_rs *message,
                      ProtobufCAllocator *allocator);
/* c_business_nt_message_nt_message_all_unread_rq methods */
void   c_business_nt_message_nt_message_all_unread_rq_init
                     (c_business_nt_message_nt_message_all_unread_rq         *message);
size_t c_business_nt_message_nt_message_all_unread_rq_get_packed_size
                     (const c_business_nt_message_nt_message_all_unread_rq   *message);
size_t c_business_nt_message_nt_message_all_unread_rq_pack
                     (const c_business_nt_message_nt_message_all_unread_rq   *message,
                      unsigned char             *out);
size_t c_business_nt_message_nt_message_all_unread_rq_pack_to_buffer
                     (const c_business_nt_message_nt_message_all_unread_rq   *message,
                      ProtobufCBuffer     *buffer);
c_business_nt_message_nt_message_all_unread_rq *
       c_business_nt_message_nt_message_all_unread_rq_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   c_business_nt_message_nt_message_all_unread_rq_free_unpacked
                     (c_business_nt_message_nt_message_all_unread_rq *message,
                      ProtobufCAllocator *allocator);
/* c_business_nt_message_nt_message_all_unread_rs methods */
void   c_business_nt_message_nt_message_all_unread_rs_init
                     (c_business_nt_message_nt_message_all_unread_rs         *message);
size_t c_business_nt_message_nt_message_all_unread_rs_get_packed_size
                     (const c_business_nt_message_nt_message_all_unread_rs   *message);
size_t c_business_nt_message_nt_message_all_unread_rs_pack
                     (const c_business_nt_message_nt_message_all_unread_rs   *message,
                      unsigned char             *out);
size_t c_business_nt_message_nt_message_all_unread_rs_pack_to_buffer
                     (const c_business_nt_message_nt_message_all_unread_rs   *message,
                      ProtobufCBuffer     *buffer);
c_business_nt_message_nt_message_all_unread_rs *
       c_business_nt_message_nt_message_all_unread_rs_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   c_business_nt_message_nt_message_all_unread_rs_free_unpacked
                     (c_business_nt_message_nt_message_all_unread_rs *message,
                      ProtobufCAllocator *allocator);
/* c_business_nt_message_nt_message_all_unread_nt methods */
void   c_business_nt_message_nt_message_all_unread_nt_init
                     (c_business_nt_message_nt_message_all_unread_nt         *message);
size_t c_business_nt_message_nt_message_all_unread_nt_get_packed_size
                     (const c_business_nt_message_nt_message_all_unread_nt   *message);
size_t c_business_nt_message_nt_message_all_unread_nt_pack
                     (const c_business_nt_message_nt_message_all_unread_nt   *message,
                      unsigned char             *out);
size_t c_business_nt_message_nt_message_all_unread_nt_pack_to_buffer
                     (const c_business_nt_message_nt_message_all_unread_nt   *message,
                      ProtobufCBuffer     *buffer);
c_business_nt_message_nt_message_all_unread_nt *
       c_business_nt_message_nt_message_all_unread_nt_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   c_business_nt_message_nt_message_all_unread_nt_free_unpacked
                     (c_business_nt_message_nt_message_all_unread_nt *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*c_business_nt_message_nt_message_consume_by_id_rq_Closure)
                 (const c_business_nt_message_nt_message_consume_by_id_rq *message,
                  void *closure_data);
typedef void (*c_business_nt_message_nt_message_consume_by_id_rs_Closure)
                 (const c_business_nt_message_nt_message_consume_by_id_rs *message,
                  void *closure_data);
typedef void (*c_business_nt_message_nt_message_consume_by_maxid_rq_Closure)
                 (const c_business_nt_message_nt_message_consume_by_maxid_rq *message,
                  void *closure_data);
typedef void (*c_business_nt_message_nt_message_consume_by_maxid_rs_Closure)
                 (const c_business_nt_message_nt_message_consume_by_maxid_rs *message,
                  void *closure_data);
typedef void (*c_business_nt_message_nt_message_read_note_id_rq_Closure)
                 (const c_business_nt_message_nt_message_read_note_id_rq *message,
                  void *closure_data);
typedef void (*c_business_nt_message_nt_message_read_note_id_rs_Closure)
                 (const c_business_nt_message_nt_message_read_note_id_rs *message,
                  void *closure_data);
typedef void (*c_business_nt_message_nt_message_all_unread_rq_Closure)
                 (const c_business_nt_message_nt_message_all_unread_rq *message,
                  void *closure_data);
typedef void (*c_business_nt_message_nt_message_all_unread_rs_Closure)
                 (const c_business_nt_message_nt_message_all_unread_rs *message,
                  void *closure_data);
typedef void (*c_business_nt_message_nt_message_all_unread_nt_Closure)
                 (const c_business_nt_message_nt_message_all_unread_nt *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCEnumDescriptor    c_business_nt_message_msg_descriptor;
extern const ProtobufCMessageDescriptor c_business_nt_message_nt_message_consume_by_id_rq_descriptor;
extern const ProtobufCEnumDescriptor    c_business_nt_message_nt_message_consume_by_id_rq_msg_descriptor;
extern const ProtobufCMessageDescriptor c_business_nt_message_nt_message_consume_by_id_rs_descriptor;
extern const ProtobufCEnumDescriptor    c_business_nt_message_nt_message_consume_by_id_rs_msg_descriptor;
extern const ProtobufCMessageDescriptor c_business_nt_message_nt_message_consume_by_maxid_rq_descriptor;
extern const ProtobufCEnumDescriptor    c_business_nt_message_nt_message_consume_by_maxid_rq_msg_descriptor;
extern const ProtobufCMessageDescriptor c_business_nt_message_nt_message_consume_by_maxid_rs_descriptor;
extern const ProtobufCEnumDescriptor    c_business_nt_message_nt_message_consume_by_maxid_rs_msg_descriptor;
extern const ProtobufCMessageDescriptor c_business_nt_message_nt_message_read_note_id_rq_descriptor;
extern const ProtobufCEnumDescriptor    c_business_nt_message_nt_message_read_note_id_rq_msg_descriptor;
extern const ProtobufCMessageDescriptor c_business_nt_message_nt_message_read_note_id_rs_descriptor;
extern const ProtobufCEnumDescriptor    c_business_nt_message_nt_message_read_note_id_rs_msg_descriptor;
extern const ProtobufCMessageDescriptor c_business_nt_message_nt_message_all_unread_rq_descriptor;
extern const ProtobufCEnumDescriptor    c_business_nt_message_nt_message_all_unread_rq_msg_descriptor;
extern const ProtobufCMessageDescriptor c_business_nt_message_nt_message_all_unread_rs_descriptor;
extern const ProtobufCEnumDescriptor    c_business_nt_message_nt_message_all_unread_rs_msg_descriptor;
extern const ProtobufCMessageDescriptor c_business_nt_message_nt_message_all_unread_nt_descriptor;
extern const ProtobufCEnumDescriptor    c_business_nt_message_nt_message_all_unread_nt_msg_descriptor;

PROTOBUF_C_END_DECLS


#endif  /* PROTOBUF_c_5fbusiness_5fnt_5fmessage_2eproto_INCLUDED */
