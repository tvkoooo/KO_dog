/* Generated by the protocol buffer compiler.  DO NOT EDIT! */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C_NO_DEPRECATED
#define PROTOBUF_C_NO_DEPRECATED
#endif

#include "s_basis.pb-c.h"
void   s_basis_heartbeat_ev_init
                     (s_basis_heartbeat_ev         *message)
{
  static s_basis_heartbeat_ev init_value = s_basis_heartbeat_ev_Init;
  *message = init_value;
}
size_t s_basis_heartbeat_ev_get_packed_size
                     (const s_basis_heartbeat_ev *message)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &s_basis_heartbeat_ev_descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t s_basis_heartbeat_ev_pack
                     (const s_basis_heartbeat_ev *message,
                      unsigned char       *out)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &s_basis_heartbeat_ev_descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t s_basis_heartbeat_ev_pack_to_buffer
                     (const s_basis_heartbeat_ev *message,
                      ProtobufCBuffer *buffer)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &s_basis_heartbeat_ev_descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
s_basis_heartbeat_ev *
       s_basis_heartbeat_ev_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data)
{
  return (s_basis_heartbeat_ev *)
     protobuf_c_message_unpack (&s_basis_heartbeat_ev_descriptor,
                                allocator, len, data);
}
void   s_basis_heartbeat_ev_free_unpacked
                     (s_basis_heartbeat_ev *message,
                      ProtobufCAllocator *allocator)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &s_basis_heartbeat_ev_descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
const ProtobufCEnumValue s_basis_heartbeat_ev_msg_enum_values_by_number[1] =
{
  { "id", "s_basis_heartbeat_ev_msg_ID", 16781312 },
};
static const ProtobufCIntRange s_basis_heartbeat_ev_msg_value_ranges[] = {
{16781312, 0},{0, 1}
};
const ProtobufCEnumValueIndex s_basis_heartbeat_ev_msg_enum_values_by_name[1] =
{
  { "id", 0 },
};
const ProtobufCEnumDescriptor s_basis_heartbeat_ev_msg_descriptor =
{
  PROTOBUF_C_ENUM_DESCRIPTOR_MAGIC,
  "s_basis.heartbeat_ev.msg",
  "msg",
  "s_basis_heartbeat_ev_msg",
  "s_basis",
  1,
  s_basis_heartbeat_ev_msg_enum_values_by_number,
  1,
  s_basis_heartbeat_ev_msg_enum_values_by_name,
  1,
  s_basis_heartbeat_ev_msg_value_ranges,
  NULL,NULL,NULL,NULL   /* reserved[1234] */
};
static const unsigned long long int s_basis_heartbeat_ev_event_time_default_value = 0;
static const unsigned long long int s_basis_heartbeat_ev_uid_default_value = 0;
static const unsigned long long int s_basis_heartbeat_ev_timecode_native_default_value = 0;
static const ProtobufCFieldDescriptor s_basis_heartbeat_ev_field_descriptors[4] =
{
  {
    "event_time",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT64,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(s_basis_heartbeat_ev, event_time),
    NULL,
    &s_basis_heartbeat_ev_event_time_default_value,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "uid",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT64,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(s_basis_heartbeat_ev, uid),
    NULL,
    &s_basis_heartbeat_ev_uid_default_value,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "timecode_native",
    3,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_UINT64,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(s_basis_heartbeat_ev, timecode_native),
    NULL,
    &s_basis_heartbeat_ev_timecode_native_default_value,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "coord_info",
    4,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    PROTOBUF_C_OFFSETOF(s_basis_heartbeat_ev, coord_info),
    &b_math_coord_descriptor,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned s_basis_heartbeat_ev_field_indices_by_name[] = {
  3,   /* field[3] = coord_info */
  0,   /* field[0] = event_time */
  2,   /* field[2] = timecode_native */
  1,   /* field[1] = uid */
};
static const ProtobufCIntRange s_basis_heartbeat_ev_number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 4 }
};
const ProtobufCMessageDescriptor s_basis_heartbeat_ev_descriptor =
{
  PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC,
  "s_basis.heartbeat_ev",
  "HeartbeatEv",
  "s_basis_heartbeat_ev",
  "s_basis",
  sizeof(s_basis_heartbeat_ev),
  4,
  s_basis_heartbeat_ev_field_descriptors,
  s_basis_heartbeat_ev_field_indices_by_name,
  1,  s_basis_heartbeat_ev_number_ranges,
  (ProtobufCMessageInit) s_basis_heartbeat_ev_init,
  NULL,NULL,NULL    /* reserved[123] */
};
const ProtobufCEnumValue s_basis_msg_enum_values_by_number[2] =
{
  { "min_id", "s_basis_msg_MIN_ID", 16781312 },
  { "max_id", "s_basis_msg_MAX_ID", 16781567 },
};
static const ProtobufCIntRange s_basis_msg_value_ranges[] = {
{16781312, 0},{16781567, 1},{0, 2}
};
const ProtobufCEnumValueIndex s_basis_msg_enum_values_by_name[2] =
{
  { "max_id", 1 },
  { "min_id", 0 },
};
const ProtobufCEnumDescriptor s_basis_msg_descriptor =
{
  PROTOBUF_C_ENUM_DESCRIPTOR_MAGIC,
  "s_basis.msg",
  "msg",
  "s_basis_msg",
  "s_basis",
  2,
  s_basis_msg_enum_values_by_number,
  2,
  s_basis_msg_enum_values_by_name,
  2,
  s_basis_msg_value_ranges,
  NULL,NULL,NULL,NULL   /* reserved[1234] */
};
