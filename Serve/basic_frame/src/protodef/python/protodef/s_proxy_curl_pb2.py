# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: s_proxy_curl.proto

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
  name='s_proxy_curl.proto',
  package='s_proxy_curl',
  syntax='proto2',
  serialized_pb=_b('\n\x12s_proxy_curl.proto\x12\x0cs_proxy_curl\x1a\rb_error.proto\"0\n\x0cjson_data_rq\x12\x0e\n\x06\x62uffer\x18\x01 \x02(\x0c\"\x10\n\x03msg\x12\t\n\x02id\x10\x80\x82\x80\x08\"d\n\x0cjson_data_rs\x12\x1c\n\x05\x65rror\x18\x01 \x02(\x0b\x32\r.b_error.info\x12\x14\n\tcurl_code\x18\x02 \x02(\r:\x01\x30\x12\x0e\n\x06\x62uffer\x18\x03 \x02(\x0c\"\x10\n\x03msg\x12\t\n\x02id\x10\x81\x82\x80\x08*#\n\x03msg\x12\r\n\x06min_id\x10\x80\x82\x80\x08\x12\r\n\x06max_id\x10\xff\x83\x80\x08\x42N\n\x08protodefB\x0cs_proxy_curlZ\x15protodef/s_proxy_curl\xa2\x02\rS_proxy_curl_\xaa\x02\x0cs_proxy_curl')
  ,
  dependencies=[b__error__pb2.DESCRIPTOR,])

_MSG = _descriptor.EnumDescriptor(
  name='msg',
  full_name='s_proxy_curl.msg',
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
  serialized_start=203,
  serialized_end=238,
)
_sym_db.RegisterEnumDescriptor(_MSG)

msg = enum_type_wrapper.EnumTypeWrapper(_MSG)
min_id = 16777472
max_id = 16777727


_JSON_DATA_RQ_MSG = _descriptor.EnumDescriptor(
  name='msg',
  full_name='s_proxy_curl.json_data_rq.msg',
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
  serialized_start=83,
  serialized_end=99,
)
_sym_db.RegisterEnumDescriptor(_JSON_DATA_RQ_MSG)

_JSON_DATA_RS_MSG = _descriptor.EnumDescriptor(
  name='msg',
  full_name='s_proxy_curl.json_data_rs.msg',
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
  serialized_start=185,
  serialized_end=201,
)
_sym_db.RegisterEnumDescriptor(_JSON_DATA_RS_MSG)


_JSON_DATA_RQ = _descriptor.Descriptor(
  name='json_data_rq',
  full_name='s_proxy_curl.json_data_rq',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='buffer', full_name='s_proxy_curl.json_data_rq.buffer', index=0,
      number=1, type=12, cpp_type=9, label=2,
      has_default_value=False, default_value=_b(""),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
    _JSON_DATA_RQ_MSG,
  ],
  options=None,
  is_extendable=False,
  syntax='proto2',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=51,
  serialized_end=99,
)


_JSON_DATA_RS = _descriptor.Descriptor(
  name='json_data_rs',
  full_name='s_proxy_curl.json_data_rs',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='error', full_name='s_proxy_curl.json_data_rs.error', index=0,
      number=1, type=11, cpp_type=10, label=2,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='curl_code', full_name='s_proxy_curl.json_data_rs.curl_code', index=1,
      number=2, type=13, cpp_type=3, label=2,
      has_default_value=True, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='buffer', full_name='s_proxy_curl.json_data_rs.buffer', index=2,
      number=3, type=12, cpp_type=9, label=2,
      has_default_value=False, default_value=_b(""),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
    _JSON_DATA_RS_MSG,
  ],
  options=None,
  is_extendable=False,
  syntax='proto2',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=101,
  serialized_end=201,
)

_JSON_DATA_RQ_MSG.containing_type = _JSON_DATA_RQ
_JSON_DATA_RS.fields_by_name['error'].message_type = b__error__pb2._INFO
_JSON_DATA_RS_MSG.containing_type = _JSON_DATA_RS
DESCRIPTOR.message_types_by_name['json_data_rq'] = _JSON_DATA_RQ
DESCRIPTOR.message_types_by_name['json_data_rs'] = _JSON_DATA_RS
DESCRIPTOR.enum_types_by_name['msg'] = _MSG
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

json_data_rq = _reflection.GeneratedProtocolMessageType('json_data_rq', (_message.Message,), dict(
  DESCRIPTOR = _JSON_DATA_RQ,
  __module__ = 's_proxy_curl_pb2'
  # @@protoc_insertion_point(class_scope:s_proxy_curl.json_data_rq)
  ))
_sym_db.RegisterMessage(json_data_rq)

json_data_rs = _reflection.GeneratedProtocolMessageType('json_data_rs', (_message.Message,), dict(
  DESCRIPTOR = _JSON_DATA_RS,
  __module__ = 's_proxy_curl_pb2'
  # @@protoc_insertion_point(class_scope:s_proxy_curl.json_data_rs)
  ))
_sym_db.RegisterMessage(json_data_rs)


DESCRIPTOR.has_options = True
DESCRIPTOR._options = _descriptor._ParseOptions(descriptor_pb2.FileOptions(), _b('\n\010protodefB\014s_proxy_curlZ\025protodef/s_proxy_curl\242\002\rS_proxy_curl_\252\002\014s_proxy_curl'))
# @@protoc_insertion_point(module_scope)
