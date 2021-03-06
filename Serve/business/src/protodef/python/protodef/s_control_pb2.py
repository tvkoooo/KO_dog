# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: s_control.proto

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
  name='s_control.proto',
  package='s_control',
  syntax='proto2',
  serialized_pb=_b('\n\x0fs_control.proto\x12\ts_control\x1a\rb_error.proto\"3\n\rset_logger_rq\x12\x10\n\x05level\x18\x01 \x02(\r:\x01\x30\"\x10\n\x03msg\x12\t\n\x02id\x10\x80\x82\x80\x08\"Q\n\rset_logger_rs\x12\x1c\n\x05\x65rror\x18\x01 \x02(\x0b\x32\r.b_error.info\x12\x10\n\x05level\x18\x02 \x02(\r:\x01\x30\"\x10\n\x03msg\x12\t\n\x02id\x10\x81\x82\x80\x08\"!\n\rget_logger_rq\"\x10\n\x03msg\x12\t\n\x02id\x10\x82\x82\x80\x08\"Q\n\rget_logger_rs\x12\x1c\n\x05\x65rror\x18\x01 \x02(\x0b\x32\r.b_error.info\x12\x10\n\x05level\x18\x02 \x02(\r:\x01\x30\"\x10\n\x03msg\x12\t\n\x02id\x10\x83\x82\x80\x08*#\n\x03msg\x12\r\n\x06min_id\x10\x80\x82\x80\x08\x12\r\n\x06max_id\x10\xff\x83\x80\x08\x42\x42\n\x08protodefB\ts_controlZ\x12protodef/s_control\xa2\x02\nS_control_\xaa\x02\ts_control')
  ,
  dependencies=[b__error__pb2.DESCRIPTOR,])

_MSG = _descriptor.EnumDescriptor(
  name='msg',
  full_name='s_control.msg',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='min_id', index=0, number=16777472,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='max_id', index=1, number=16777727,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=299,
  serialized_end=334,
)
_sym_db.RegisterEnumDescriptor(_MSG)

msg = enum_type_wrapper.EnumTypeWrapper(_MSG)
min_id = 16777472
max_id = 16777727


_SET_LOGGER_RQ_MSG = _descriptor.EnumDescriptor(
  name='msg',
  full_name='s_control.set_logger_rq.msg',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='id', index=0, number=16777472,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=80,
  serialized_end=96,
)
_sym_db.RegisterEnumDescriptor(_SET_LOGGER_RQ_MSG)

_SET_LOGGER_RS_MSG = _descriptor.EnumDescriptor(
  name='msg',
  full_name='s_control.set_logger_rs.msg',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='id', index=0, number=16777473,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=163,
  serialized_end=179,
)
_sym_db.RegisterEnumDescriptor(_SET_LOGGER_RS_MSG)

_GET_LOGGER_RQ_MSG = _descriptor.EnumDescriptor(
  name='msg',
  full_name='s_control.get_logger_rq.msg',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='id', index=0, number=16777474,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=198,
  serialized_end=214,
)
_sym_db.RegisterEnumDescriptor(_GET_LOGGER_RQ_MSG)

_GET_LOGGER_RS_MSG = _descriptor.EnumDescriptor(
  name='msg',
  full_name='s_control.get_logger_rs.msg',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='id', index=0, number=16777475,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=281,
  serialized_end=297,
)
_sym_db.RegisterEnumDescriptor(_GET_LOGGER_RS_MSG)


_SET_LOGGER_RQ = _descriptor.Descriptor(
  name='set_logger_rq',
  full_name='s_control.set_logger_rq',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='level', full_name='s_control.set_logger_rq.level', index=0,
      number=1, type=13, cpp_type=3, label=2,
      has_default_value=True, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
    _SET_LOGGER_RQ_MSG,
  ],
  options=None,
  is_extendable=False,
  syntax='proto2',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=45,
  serialized_end=96,
)


_SET_LOGGER_RS = _descriptor.Descriptor(
  name='set_logger_rs',
  full_name='s_control.set_logger_rs',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='error', full_name='s_control.set_logger_rs.error', index=0,
      number=1, type=11, cpp_type=10, label=2,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='level', full_name='s_control.set_logger_rs.level', index=1,
      number=2, type=13, cpp_type=3, label=2,
      has_default_value=True, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
    _SET_LOGGER_RS_MSG,
  ],
  options=None,
  is_extendable=False,
  syntax='proto2',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=98,
  serialized_end=179,
)


_GET_LOGGER_RQ = _descriptor.Descriptor(
  name='get_logger_rq',
  full_name='s_control.get_logger_rq',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
    _GET_LOGGER_RQ_MSG,
  ],
  options=None,
  is_extendable=False,
  syntax='proto2',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=181,
  serialized_end=214,
)


_GET_LOGGER_RS = _descriptor.Descriptor(
  name='get_logger_rs',
  full_name='s_control.get_logger_rs',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='error', full_name='s_control.get_logger_rs.error', index=0,
      number=1, type=11, cpp_type=10, label=2,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='level', full_name='s_control.get_logger_rs.level', index=1,
      number=2, type=13, cpp_type=3, label=2,
      has_default_value=True, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
    _GET_LOGGER_RS_MSG,
  ],
  options=None,
  is_extendable=False,
  syntax='proto2',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=216,
  serialized_end=297,
)

_SET_LOGGER_RQ_MSG.containing_type = _SET_LOGGER_RQ
_SET_LOGGER_RS.fields_by_name['error'].message_type = b__error__pb2._INFO
_SET_LOGGER_RS_MSG.containing_type = _SET_LOGGER_RS
_GET_LOGGER_RQ_MSG.containing_type = _GET_LOGGER_RQ
_GET_LOGGER_RS.fields_by_name['error'].message_type = b__error__pb2._INFO
_GET_LOGGER_RS_MSG.containing_type = _GET_LOGGER_RS
DESCRIPTOR.message_types_by_name['set_logger_rq'] = _SET_LOGGER_RQ
DESCRIPTOR.message_types_by_name['set_logger_rs'] = _SET_LOGGER_RS
DESCRIPTOR.message_types_by_name['get_logger_rq'] = _GET_LOGGER_RQ
DESCRIPTOR.message_types_by_name['get_logger_rs'] = _GET_LOGGER_RS
DESCRIPTOR.enum_types_by_name['msg'] = _MSG
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

set_logger_rq = _reflection.GeneratedProtocolMessageType('set_logger_rq', (_message.Message,), dict(
  DESCRIPTOR = _SET_LOGGER_RQ,
  __module__ = 's_control_pb2'
  # @@protoc_insertion_point(class_scope:s_control.set_logger_rq)
  ))
_sym_db.RegisterMessage(set_logger_rq)

set_logger_rs = _reflection.GeneratedProtocolMessageType('set_logger_rs', (_message.Message,), dict(
  DESCRIPTOR = _SET_LOGGER_RS,
  __module__ = 's_control_pb2'
  # @@protoc_insertion_point(class_scope:s_control.set_logger_rs)
  ))
_sym_db.RegisterMessage(set_logger_rs)

get_logger_rq = _reflection.GeneratedProtocolMessageType('get_logger_rq', (_message.Message,), dict(
  DESCRIPTOR = _GET_LOGGER_RQ,
  __module__ = 's_control_pb2'
  # @@protoc_insertion_point(class_scope:s_control.get_logger_rq)
  ))
_sym_db.RegisterMessage(get_logger_rq)

get_logger_rs = _reflection.GeneratedProtocolMessageType('get_logger_rs', (_message.Message,), dict(
  DESCRIPTOR = _GET_LOGGER_RS,
  __module__ = 's_control_pb2'
  # @@protoc_insertion_point(class_scope:s_control.get_logger_rs)
  ))
_sym_db.RegisterMessage(get_logger_rs)


DESCRIPTOR.has_options = True
DESCRIPTOR._options = _descriptor._ParseOptions(descriptor_pb2.FileOptions(), _b('\n\010protodefB\ts_controlZ\022protodef/s_control\242\002\nS_control_\252\002\ts_control'))
# @@protoc_insertion_point(module_scope)
