# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: b_business_account.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='b_business_account.proto',
  package='b_business_account',
  syntax='proto2',
  serialized_pb=_b('\n\x18\x62_business_account.proto\x12\x12\x62_business_account\"W\n\tuser_info\x12\x0f\n\x07user_id\x18\x01 \x02(\x04\x12\x11\n\tuser_name\x18\x02 \x02(\t\x12\x11\n\tuser_nick\x18\x03 \x02(\t\x12\x13\n\x0b\x63reate_time\x18\x04 \x02(\rBf\n\x08protodefB\x12\x62_business_accountZ\x1bprotodef/b_business_account\xa2\x02\x13\x42_business_account_\xaa\x02\x12\x62_business_account')
)




_USER_INFO = _descriptor.Descriptor(
  name='user_info',
  full_name='b_business_account.user_info',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='user_id', full_name='b_business_account.user_info.user_id', index=0,
      number=1, type=4, cpp_type=4, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='user_name', full_name='b_business_account.user_info.user_name', index=1,
      number=2, type=9, cpp_type=9, label=2,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='user_nick', full_name='b_business_account.user_info.user_nick', index=2,
      number=3, type=9, cpp_type=9, label=2,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='create_time', full_name='b_business_account.user_info.create_time', index=3,
      number=4, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto2',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=48,
  serialized_end=135,
)

DESCRIPTOR.message_types_by_name['user_info'] = _USER_INFO
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

user_info = _reflection.GeneratedProtocolMessageType('user_info', (_message.Message,), dict(
  DESCRIPTOR = _USER_INFO,
  __module__ = 'b_business_account_pb2'
  # @@protoc_insertion_point(class_scope:b_business_account.user_info)
  ))
_sym_db.RegisterMessage(user_info)


DESCRIPTOR.has_options = True
DESCRIPTOR._options = _descriptor._ParseOptions(descriptor_pb2.FileOptions(), _b('\n\010protodefB\022b_business_accountZ\033protodef/b_business_account\242\002\023B_business_account_\252\002\022b_business_account'))
# @@protoc_insertion_point(module_scope)