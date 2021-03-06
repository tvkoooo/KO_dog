// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: b_enum.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "b_enum.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace b_enum {

namespace protobuf_b_5fenum_2eproto {


namespace {

const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors[3];

}  // namespace

PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::ParseTableField
    const TableStruct::entries[] = {
  {0, 0, 0, ::google::protobuf::internal::kInvalidMask, 0, 0},
};

PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::AuxillaryParseTableField
    const TableStruct::aux[] = {
  ::google::protobuf::internal::AuxillaryParseTableField(),
};
PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::ParseTable const
    TableStruct::schema[] = {
  { NULL, NULL, 0, -1, -1, false },
};

const ::google::protobuf::uint32 TableStruct::offsets[] = { ~0u };
static const ::google::protobuf::internal::MigrationSchema* schemas = NULL;
static const ::google::protobuf::Message* const* file_default_instances = NULL;
namespace {

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "b_enum.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      NULL, file_level_enum_descriptors, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
}

}  // namespace

void TableStruct::Shutdown() {
}

void TableStruct::InitDefaultsImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::internal::InitProtobufDefaults();
}

void InitDefaults() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &TableStruct::InitDefaultsImpl);
}
void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] = {
      "\n\014b_enum.proto\022\006b_enum*!\n\007reply_t\022\n\n\006acc"
      "ept\020\000\022\n\n\006refuse\020\001*#\n\toperate_t\022\n\n\006ensure"
      "\020\000\022\n\n\006cancel\020\001*F\n\010opcode_t\022\n\n\006assign\020\000\022\n"
      "\n\006update\020\001\022\n\n\006insert\020\002\022\n\n\006remove\020\003\022\n\n\006de"
      "lete\020\004B6\n\010protodefB\006b_enumZ\017protodef/b_e"
      "num\242\002\007B_enum_\252\002\006b_enum"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 222);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "b_enum.proto", &protobuf_RegisterTypes);
  ::google::protobuf::internal::OnShutdown(&TableStruct::Shutdown);
}

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;

}  // namespace protobuf_b_5fenum_2eproto

const ::google::protobuf::EnumDescriptor* reply_t_descriptor() {
  protobuf_b_5fenum_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_b_5fenum_2eproto::file_level_enum_descriptors[0];
}
bool reply_t_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}

const ::google::protobuf::EnumDescriptor* operate_t_descriptor() {
  protobuf_b_5fenum_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_b_5fenum_2eproto::file_level_enum_descriptors[1];
}
bool operate_t_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}

const ::google::protobuf::EnumDescriptor* opcode_t_descriptor() {
  protobuf_b_5fenum_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_b_5fenum_2eproto::file_level_enum_descriptors[2];
}
bool opcode_t_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace b_enum

// @@protoc_insertion_point(global_scope)
