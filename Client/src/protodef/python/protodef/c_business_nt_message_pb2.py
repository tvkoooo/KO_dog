# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: c_business_nt_message.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf.internal import enum_type_wrapper
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


import b_error_pb2 as b__error__pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='c_business_nt_message.proto',
  package='c_business_nt_message',
  syntax='proto2',
  serialized_pb=_b('\n\x1b\x63_business_nt_message.proto\x12\x15\x63_business_nt_message\x1a\rb_error.proto\"Q\n\x1bnt_message_consume_by_id_rq\x12\x0f\n\x07user_id\x18\x01 \x02(\x04\x12\x0f\n\x07note_id\x18\x02 \x02(\x04\"\x10\n\x03msg\x12\t\n\x02id\x10\x81\x80\x80\x10\"o\n\x1bnt_message_consume_by_id_rs\x12\x1c\n\x05\x65rror\x18\x01 \x02(\x0b\x32\r.b_error.info\x12\x0f\n\x07user_id\x18\x02 \x02(\x04\x12\x0f\n\x07note_id\x18\x03 \x02(\x04\"\x10\n\x03msg\x12\t\n\x02id\x10\x82\x80\x80\x10\"W\n\x1ent_message_consume_by_maxid_rq\x12\x0f\n\x07user_id\x18\x01 \x02(\x04\x12\x12\n\nnote_maxid\x18\x02 \x02(\x04\"\x10\n\x03msg\x12\t\n\x02id\x10\x83\x80\x80\x10\"u\n\x1ent_message_consume_by_maxid_rs\x12\x1c\n\x05\x65rror\x18\x01 \x02(\x0b\x32\r.b_error.info\x12\x0f\n\x07user_id\x18\x02 \x02(\x04\x12\x12\n\nnote_maxid\x18\x03 \x02(\x04\"\x10\n\x03msg\x12\t\n\x02id\x10\x84\x80\x80\x10\"P\n\x1ant_message_read_note_id_rq\x12\x0f\n\x07user_id\x18\x01 \x02(\x04\x12\x0f\n\x07note_id\x18\x02 \x02(\x04\"\x10\n\x03msg\x12\t\n\x02id\x10\x81\x80\x80\x10\"n\n\x1ant_message_read_note_id_rs\x12\x1c\n\x05\x65rror\x18\x01 \x02(\x0b\x32\r.b_error.info\x12\x0f\n\x07user_id\x18\x02 \x02(\x04\x12\x0f\n\x07note_id\x18\x03 \x02(\x04\"\x10\n\x03msg\x12\t\n\x02id\x10\x82\x80\x80\x10\"=\n\x18nt_message_all_unread_rq\x12\x0f\n\x07user_id\x18\x01 \x02(\x04\"\x10\n\x03msg\x12\t\n\x02id\x10\x83\x80\x80\x10\"[\n\x18nt_message_all_unread_rs\x12\x1c\n\x05\x65rror\x18\x01 \x02(\x0b\x32\r.b_error.info\x12\x0f\n\x07user_id\x18\x02 \x02(\x04\"\x10\n\x03msg\x12\t\n\x02id\x10\x84\x80\x80\x10\"=\n\x18nt_message_all_unread_nt\x12\x0f\n\x07user_id\x18\x02 \x02(\x04\"\x10\n\x03msg\x12\t\n\x02id\x10\x85\x80\x80\x10*#\n\x03msg\x12\r\n\x06min_id\x10\x80\x80\x80\x10\x12\r\n\x06max_id\x10\xff\x81\x80\x10\x42r\n\x08protodefB\x15\x63_business_nt_messageZ\x1eprotodef/c_business_nt_message\xa2\x02\x16\x43_business_nt_message_\xaa\x02\x15\x63_business_nt_message')
  ,
  dependencies=[b__error__pb2.DESCRIPTOR,])

_MSG = _descriptor.EnumDescriptor(
  name='msg',
  full_name='c_business_nt_message.msg',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='min_id', index=0, number=33554432,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='max_id', index=1, number=33554687,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=886,
  serialized_end=921,
)
_sym_db.RegisterEnumDescriptor(_MSG)

msg = enum_type_wrapper.EnumTypeWrapper(_MSG)
min_id = 33554432
max_id = 33554687


_NT_MESSAGE_CONSUME_BY_ID_RQ_MSG = _descriptor.EnumDescriptor(
  name='msg',
  full_name='c_business_nt_message.nt_message_consume_by_id_rq.msg',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='id', index=0, number=33554433,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=134,
  serialized_end=150,
)
_sym_db.RegisterEnumDescriptor(_NT_MESSAGE_CONSUME_BY_ID_RQ_MSG)

_NT_MESSAGE_CONSUME_BY_ID_RS_MSG = _descriptor.EnumDescriptor(
  name='msg',
  full_name='c_business_nt_message.nt_message_consume_by_id_rs.msg',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='id', index=0, number=33554434,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=247,
  serialized_end=263,
)
_sym_db.RegisterEnumDescriptor(_NT_MESSAGE_CONSUME_BY_ID_RS_MSG)

_NT_MESSAGE_CONSUME_BY_MAXID_RQ_MSG = _descriptor.EnumDescriptor(
  name='msg',
  full_name='c_business_nt_message.nt_message_consume_by_maxid_rq.msg',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='id', index=0, number=33554435,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=336,
  serialized_end=352,
)
_sym_db.RegisterEnumDescriptor(_NT_MESSAGE_CONSUME_BY_MAXID_RQ_MSG)

_NT_MESSAGE_CONSUME_BY_MAXID_RS_MSG = _descriptor.EnumDescriptor(
  name='msg',
  full_name='c_business_nt_message.nt_message_consume_by_maxid_rs.msg',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='id', index=0, number=33554436,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=455,
  serialized_end=471,
)
_sym_db.RegisterEnumDescriptor(_NT_MESSAGE_CONSUME_BY_MAXID_RS_MSG)

_NT_MESSAGE_READ_NOTE_ID_RQ_MSG = _descriptor.EnumDescriptor(
  name='msg',
  full_name='c_business_nt_message.nt_message_read_note_id_rq.msg',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='id', index=0, number=33554433,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=134,
  serialized_end=150,
)
_sym_db.RegisterEnumDescriptor(_NT_MESSAGE_READ_NOTE_ID_RQ_MSG)

_NT_MESSAGE_READ_NOTE_ID_RS_MSG = _descriptor.EnumDescriptor(
  name='msg',
  full_name='c_business_nt_message.nt_message_read_note_id_rs.msg',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='id', index=0, number=33554434,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=247,
  serialized_end=263,
)
_sym_db.RegisterEnumDescriptor(_NT_MESSAGE_READ_NOTE_ID_RS_MSG)

_NT_MESSAGE_ALL_UNREAD_RQ_MSG = _descriptor.EnumDescriptor(
  name='msg',
  full_name='c_business_nt_message.nt_message_all_unread_rq.msg',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='id', index=0, number=33554435,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=336,
  serialized_end=352,
)
_sym_db.RegisterEnumDescriptor(_NT_MESSAGE_ALL_UNREAD_RQ_MSG)

_NT_MESSAGE_ALL_UNREAD_RS_MSG = _descriptor.EnumDescriptor(
  name='msg',
  full_name='c_business_nt_message.nt_message_all_unread_rs.msg',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='id', index=0, number=33554436,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=455,
  serialized_end=471,
)
_sym_db.RegisterEnumDescriptor(_NT_MESSAGE_ALL_UNREAD_RS_MSG)

_NT_MESSAGE_ALL_UNREAD_NT_MSG = _descriptor.EnumDescriptor(
  name='msg',
  full_name='c_business_nt_message.nt_message_all_unread_nt.msg',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='id', index=0, number=33554437,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=868,
  serialized_end=884,
)
_sym_db.RegisterEnumDescriptor(_NT_MESSAGE_ALL_UNREAD_NT_MSG)


_NT_MESSAGE_CONSUME_BY_ID_RQ = _descriptor.Descriptor(
  name='nt_message_consume_by_id_rq',
  full_name='c_business_nt_message.nt_message_consume_by_id_rq',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='user_id', full_name='c_business_nt_message.nt_message_consume_by_id_rq.user_id', index=0,
      number=1, type=4, cpp_type=4, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='note_id', full_name='c_business_nt_message.nt_message_consume_by_id_rq.note_id', index=1,
      number=2, type=4, cpp_type=4, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
    _NT_MESSAGE_CONSUME_BY_ID_RQ_MSG,
  ],
  options=None,
  is_extendable=False,
  syntax='proto2',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=69,
  serialized_end=150,
)


_NT_MESSAGE_CONSUME_BY_ID_RS = _descriptor.Descriptor(
  name='nt_message_consume_by_id_rs',
  full_name='c_business_nt_message.nt_message_consume_by_id_rs',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='error', full_name='c_business_nt_message.nt_message_consume_by_id_rs.error', index=0,
      number=1, type=11, cpp_type=10, label=2,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='user_id', full_name='c_business_nt_message.nt_message_consume_by_id_rs.user_id', index=1,
      number=2, type=4, cpp_type=4, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='note_id', full_name='c_business_nt_message.nt_message_consume_by_id_rs.note_id', index=2,
      number=3, type=4, cpp_type=4, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
    _NT_MESSAGE_CONSUME_BY_ID_RS_MSG,
  ],
  options=None,
  is_extendable=False,
  syntax='proto2',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=152,
  serialized_end=263,
)


_NT_MESSAGE_CONSUME_BY_MAXID_RQ = _descriptor.Descriptor(
  name='nt_message_consume_by_maxid_rq',
  full_name='c_business_nt_message.nt_message_consume_by_maxid_rq',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='user_id', full_name='c_business_nt_message.nt_message_consume_by_maxid_rq.user_id', index=0,
      number=1, type=4, cpp_type=4, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='note_maxid', full_name='c_business_nt_message.nt_message_consume_by_maxid_rq.note_maxid', index=1,
      number=2, type=4, cpp_type=4, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
    _NT_MESSAGE_CONSUME_BY_MAXID_RQ_MSG,
  ],
  options=None,
  is_extendable=False,
  syntax='proto2',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=265,
  serialized_end=352,
)


_NT_MESSAGE_CONSUME_BY_MAXID_RS = _descriptor.Descriptor(
  name='nt_message_consume_by_maxid_rs',
  full_name='c_business_nt_message.nt_message_consume_by_maxid_rs',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='error', full_name='c_business_nt_message.nt_message_consume_by_maxid_rs.error', index=0,
      number=1, type=11, cpp_type=10, label=2,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='user_id', full_name='c_business_nt_message.nt_message_consume_by_maxid_rs.user_id', index=1,
      number=2, type=4, cpp_type=4, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='note_maxid', full_name='c_business_nt_message.nt_message_consume_by_maxid_rs.note_maxid', index=2,
      number=3, type=4, cpp_type=4, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
    _NT_MESSAGE_CONSUME_BY_MAXID_RS_MSG,
  ],
  options=None,
  is_extendable=False,
  syntax='proto2',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=354,
  serialized_end=471,
)


_NT_MESSAGE_READ_NOTE_ID_RQ = _descriptor.Descriptor(
  name='nt_message_read_note_id_rq',
  full_name='c_business_nt_message.nt_message_read_note_id_rq',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='user_id', full_name='c_business_nt_message.nt_message_read_note_id_rq.user_id', index=0,
      number=1, type=4, cpp_type=4, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='note_id', full_name='c_business_nt_message.nt_message_read_note_id_rq.note_id', index=1,
      number=2, type=4, cpp_type=4, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
    _NT_MESSAGE_READ_NOTE_ID_RQ_MSG,
  ],
  options=None,
  is_extendable=False,
  syntax='proto2',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=473,
  serialized_end=553,
)


_NT_MESSAGE_READ_NOTE_ID_RS = _descriptor.Descriptor(
  name='nt_message_read_note_id_rs',
  full_name='c_business_nt_message.nt_message_read_note_id_rs',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='error', full_name='c_business_nt_message.nt_message_read_note_id_rs.error', index=0,
      number=1, type=11, cpp_type=10, label=2,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='user_id', full_name='c_business_nt_message.nt_message_read_note_id_rs.user_id', index=1,
      number=2, type=4, cpp_type=4, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='note_id', full_name='c_business_nt_message.nt_message_read_note_id_rs.note_id', index=2,
      number=3, type=4, cpp_type=4, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
    _NT_MESSAGE_READ_NOTE_ID_RS_MSG,
  ],
  options=None,
  is_extendable=False,
  syntax='proto2',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=555,
  serialized_end=665,
)


_NT_MESSAGE_ALL_UNREAD_RQ = _descriptor.Descriptor(
  name='nt_message_all_unread_rq',
  full_name='c_business_nt_message.nt_message_all_unread_rq',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='user_id', full_name='c_business_nt_message.nt_message_all_unread_rq.user_id', index=0,
      number=1, type=4, cpp_type=4, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
    _NT_MESSAGE_ALL_UNREAD_RQ_MSG,
  ],
  options=None,
  is_extendable=False,
  syntax='proto2',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=667,
  serialized_end=728,
)


_NT_MESSAGE_ALL_UNREAD_RS = _descriptor.Descriptor(
  name='nt_message_all_unread_rs',
  full_name='c_business_nt_message.nt_message_all_unread_rs',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='error', full_name='c_business_nt_message.nt_message_all_unread_rs.error', index=0,
      number=1, type=11, cpp_type=10, label=2,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='user_id', full_name='c_business_nt_message.nt_message_all_unread_rs.user_id', index=1,
      number=2, type=4, cpp_type=4, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
    _NT_MESSAGE_ALL_UNREAD_RS_MSG,
  ],
  options=None,
  is_extendable=False,
  syntax='proto2',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=730,
  serialized_end=821,
)


_NT_MESSAGE_ALL_UNREAD_NT = _descriptor.Descriptor(
  name='nt_message_all_unread_nt',
  full_name='c_business_nt_message.nt_message_all_unread_nt',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='user_id', full_name='c_business_nt_message.nt_message_all_unread_nt.user_id', index=0,
      number=2, type=4, cpp_type=4, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
    _NT_MESSAGE_ALL_UNREAD_NT_MSG,
  ],
  options=None,
  is_extendable=False,
  syntax='proto2',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=823,
  serialized_end=884,
)

_NT_MESSAGE_CONSUME_BY_ID_RQ_MSG.containing_type = _NT_MESSAGE_CONSUME_BY_ID_RQ
_NT_MESSAGE_CONSUME_BY_ID_RS.fields_by_name['error'].message_type = b__error__pb2._INFO
_NT_MESSAGE_CONSUME_BY_ID_RS_MSG.containing_type = _NT_MESSAGE_CONSUME_BY_ID_RS
_NT_MESSAGE_CONSUME_BY_MAXID_RQ_MSG.containing_type = _NT_MESSAGE_CONSUME_BY_MAXID_RQ
_NT_MESSAGE_CONSUME_BY_MAXID_RS.fields_by_name['error'].message_type = b__error__pb2._INFO
_NT_MESSAGE_CONSUME_BY_MAXID_RS_MSG.containing_type = _NT_MESSAGE_CONSUME_BY_MAXID_RS
_NT_MESSAGE_READ_NOTE_ID_RQ_MSG.containing_type = _NT_MESSAGE_READ_NOTE_ID_RQ
_NT_MESSAGE_READ_NOTE_ID_RS.fields_by_name['error'].message_type = b__error__pb2._INFO
_NT_MESSAGE_READ_NOTE_ID_RS_MSG.containing_type = _NT_MESSAGE_READ_NOTE_ID_RS
_NT_MESSAGE_ALL_UNREAD_RQ_MSG.containing_type = _NT_MESSAGE_ALL_UNREAD_RQ
_NT_MESSAGE_ALL_UNREAD_RS.fields_by_name['error'].message_type = b__error__pb2._INFO
_NT_MESSAGE_ALL_UNREAD_RS_MSG.containing_type = _NT_MESSAGE_ALL_UNREAD_RS
_NT_MESSAGE_ALL_UNREAD_NT_MSG.containing_type = _NT_MESSAGE_ALL_UNREAD_NT
DESCRIPTOR.message_types_by_name['nt_message_consume_by_id_rq'] = _NT_MESSAGE_CONSUME_BY_ID_RQ
DESCRIPTOR.message_types_by_name['nt_message_consume_by_id_rs'] = _NT_MESSAGE_CONSUME_BY_ID_RS
DESCRIPTOR.message_types_by_name['nt_message_consume_by_maxid_rq'] = _NT_MESSAGE_CONSUME_BY_MAXID_RQ
DESCRIPTOR.message_types_by_name['nt_message_consume_by_maxid_rs'] = _NT_MESSAGE_CONSUME_BY_MAXID_RS
DESCRIPTOR.message_types_by_name['nt_message_read_note_id_rq'] = _NT_MESSAGE_READ_NOTE_ID_RQ
DESCRIPTOR.message_types_by_name['nt_message_read_note_id_rs'] = _NT_MESSAGE_READ_NOTE_ID_RS
DESCRIPTOR.message_types_by_name['nt_message_all_unread_rq'] = _NT_MESSAGE_ALL_UNREAD_RQ
DESCRIPTOR.message_types_by_name['nt_message_all_unread_rs'] = _NT_MESSAGE_ALL_UNREAD_RS
DESCRIPTOR.message_types_by_name['nt_message_all_unread_nt'] = _NT_MESSAGE_ALL_UNREAD_NT
DESCRIPTOR.enum_types_by_name['msg'] = _MSG
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

nt_message_consume_by_id_rq = _reflection.GeneratedProtocolMessageType('nt_message_consume_by_id_rq', (_message.Message,), dict(
  DESCRIPTOR = _NT_MESSAGE_CONSUME_BY_ID_RQ,
  __module__ = 'c_business_nt_message_pb2'
  # @@protoc_insertion_point(class_scope:c_business_nt_message.nt_message_consume_by_id_rq)
  ))
_sym_db.RegisterMessage(nt_message_consume_by_id_rq)

nt_message_consume_by_id_rs = _reflection.GeneratedProtocolMessageType('nt_message_consume_by_id_rs', (_message.Message,), dict(
  DESCRIPTOR = _NT_MESSAGE_CONSUME_BY_ID_RS,
  __module__ = 'c_business_nt_message_pb2'
  # @@protoc_insertion_point(class_scope:c_business_nt_message.nt_message_consume_by_id_rs)
  ))
_sym_db.RegisterMessage(nt_message_consume_by_id_rs)

nt_message_consume_by_maxid_rq = _reflection.GeneratedProtocolMessageType('nt_message_consume_by_maxid_rq', (_message.Message,), dict(
  DESCRIPTOR = _NT_MESSAGE_CONSUME_BY_MAXID_RQ,
  __module__ = 'c_business_nt_message_pb2'
  # @@protoc_insertion_point(class_scope:c_business_nt_message.nt_message_consume_by_maxid_rq)
  ))
_sym_db.RegisterMessage(nt_message_consume_by_maxid_rq)

nt_message_consume_by_maxid_rs = _reflection.GeneratedProtocolMessageType('nt_message_consume_by_maxid_rs', (_message.Message,), dict(
  DESCRIPTOR = _NT_MESSAGE_CONSUME_BY_MAXID_RS,
  __module__ = 'c_business_nt_message_pb2'
  # @@protoc_insertion_point(class_scope:c_business_nt_message.nt_message_consume_by_maxid_rs)
  ))
_sym_db.RegisterMessage(nt_message_consume_by_maxid_rs)

nt_message_read_note_id_rq = _reflection.GeneratedProtocolMessageType('nt_message_read_note_id_rq', (_message.Message,), dict(
  DESCRIPTOR = _NT_MESSAGE_READ_NOTE_ID_RQ,
  __module__ = 'c_business_nt_message_pb2'
  # @@protoc_insertion_point(class_scope:c_business_nt_message.nt_message_read_note_id_rq)
  ))
_sym_db.RegisterMessage(nt_message_read_note_id_rq)

nt_message_read_note_id_rs = _reflection.GeneratedProtocolMessageType('nt_message_read_note_id_rs', (_message.Message,), dict(
  DESCRIPTOR = _NT_MESSAGE_READ_NOTE_ID_RS,
  __module__ = 'c_business_nt_message_pb2'
  # @@protoc_insertion_point(class_scope:c_business_nt_message.nt_message_read_note_id_rs)
  ))
_sym_db.RegisterMessage(nt_message_read_note_id_rs)

nt_message_all_unread_rq = _reflection.GeneratedProtocolMessageType('nt_message_all_unread_rq', (_message.Message,), dict(
  DESCRIPTOR = _NT_MESSAGE_ALL_UNREAD_RQ,
  __module__ = 'c_business_nt_message_pb2'
  # @@protoc_insertion_point(class_scope:c_business_nt_message.nt_message_all_unread_rq)
  ))
_sym_db.RegisterMessage(nt_message_all_unread_rq)

nt_message_all_unread_rs = _reflection.GeneratedProtocolMessageType('nt_message_all_unread_rs', (_message.Message,), dict(
  DESCRIPTOR = _NT_MESSAGE_ALL_UNREAD_RS,
  __module__ = 'c_business_nt_message_pb2'
  # @@protoc_insertion_point(class_scope:c_business_nt_message.nt_message_all_unread_rs)
  ))
_sym_db.RegisterMessage(nt_message_all_unread_rs)

nt_message_all_unread_nt = _reflection.GeneratedProtocolMessageType('nt_message_all_unread_nt', (_message.Message,), dict(
  DESCRIPTOR = _NT_MESSAGE_ALL_UNREAD_NT,
  __module__ = 'c_business_nt_message_pb2'
  # @@protoc_insertion_point(class_scope:c_business_nt_message.nt_message_all_unread_nt)
  ))
_sym_db.RegisterMessage(nt_message_all_unread_nt)


DESCRIPTOR.has_options = True
DESCRIPTOR._options = _descriptor._ParseOptions(descriptor_pb2.FileOptions(), _b('\n\010protodefB\025c_business_nt_messageZ\036protodef/c_business_nt_message\242\002\026C_business_nt_message_\252\002\025c_business_nt_message'))
# @@protoc_insertion_point(module_scope)