/* Generated by the protocol buffer compiler.  DO NOT EDIT! */

#ifndef PROTOBUF_C_s_5fbasis_2eproto_INCLUDED
#define PROTOBUF_C_s_5fbasis_2eproto_INCLUDED

#include <google/protobuf-c/protobuf-c.h>

PROTOBUF_C_BEGIN_DECLS

#include "b_math.pb-c.h"

typedef struct _s_basis_heartbeat_ev s_basis_heartbeat_ev;


/* --- enums --- */

typedef enum _s_basis_heartbeat_ev_msg {
  s_basis_heartbeat_ev_msg_id = 16781312
} s_basis_heartbeat_ev_msg;
typedef enum _s_basis_msg {
  s_basis_msg_min_id = 16781312,
  s_basis_msg_max_id = 16781567
} s_basis_msg;

/* --- messages --- */

struct  _s_basis_heartbeat_ev
{
  ProtobufCMessage base;
  unsigned long long int event_time;
  unsigned long long int uid;
  unsigned long long int timecode_native;
  b_math_coord *coord_info;
};
#define s_basis_heartbeat_ev_Init \
 { PROTOBUF_C_MESSAGE_INIT (&s_basis_heartbeat_ev_descriptor) \
    , 0, 0, 0, NULL }


/* s_basis_heartbeat_ev methods */
void   s_basis_heartbeat_ev_init
                     (s_basis_heartbeat_ev         *message);
size_t s_basis_heartbeat_ev_get_packed_size
                     (const s_basis_heartbeat_ev   *message);
size_t s_basis_heartbeat_ev_pack
                     (const s_basis_heartbeat_ev   *message,
                      unsigned char             *out);
size_t s_basis_heartbeat_ev_pack_to_buffer
                     (const s_basis_heartbeat_ev   *message,
                      ProtobufCBuffer     *buffer);
s_basis_heartbeat_ev *
       s_basis_heartbeat_ev_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   s_basis_heartbeat_ev_free_unpacked
                     (s_basis_heartbeat_ev *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*s_basis_heartbeat_ev_Closure)
                 (const s_basis_heartbeat_ev *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCEnumDescriptor    s_basis_msg_descriptor;
extern const ProtobufCMessageDescriptor s_basis_heartbeat_ev_descriptor;
extern const ProtobufCEnumDescriptor    s_basis_heartbeat_ev_msg_descriptor;

PROTOBUF_C_END_DECLS


#endif  /* PROTOBUF_s_5fbasis_2eproto_INCLUDED */