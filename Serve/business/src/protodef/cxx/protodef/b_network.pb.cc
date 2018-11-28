// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: b_network.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "b_network.pb.h"

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

namespace b_network {
class addressDefaultTypeInternal : public ::google::protobuf::internal::ExplicitlyConstructed<address> {
} _address_default_instance_;

namespace protobuf_b_5fnetwork_2eproto {


namespace {

::google::protobuf::Metadata file_level_metadata[1];

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

const ::google::protobuf::uint32 TableStruct::offsets[] = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(address, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(address, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(address, host_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(address, port_),
  0,
  1,
};

static const ::google::protobuf::internal::MigrationSchema schemas[] = {
  { 0, 7, sizeof(address)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&_address_default_instance_),
};

namespace {

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "b_network.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

}  // namespace

void TableStruct::Shutdown() {
  _address_default_instance_.Shutdown();
  delete file_level_metadata[0].reflection;
}

void TableStruct::InitDefaultsImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::internal::InitProtobufDefaults();
  _address_default_instance_.DefaultConstruct();
}

void InitDefaults() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &TableStruct::InitDefaultsImpl);
}
void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] = {
      "\n\017b_network.proto\022\tb_network\"*\n\007address\022"
      "\016\n\004host\030\001 \002(\t:\000\022\017\n\004port\030\002 \002(\r:\0010BB\n\010prot"
      "odefB\tb_networkZ\022protodef/b_network\242\002\nB_"
      "network_\252\002\tb_network"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 140);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "b_network.proto", &protobuf_RegisterTypes);
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

}  // namespace protobuf_b_5fnetwork_2eproto


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int address::kHostFieldNumber;
const int address::kPortFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

address::address()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_b_5fnetwork_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:b_network.address)
}
address::address(const address& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  host_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_host()) {
    host_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.host_);
  }
  port_ = from.port_;
  // @@protoc_insertion_point(copy_constructor:b_network.address)
}

void address::SharedCtor() {
  _cached_size_ = 0;
  host_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  port_ = 0u;
}

address::~address() {
  // @@protoc_insertion_point(destructor:b_network.address)
  SharedDtor();
}

void address::SharedDtor() {
  host_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void address::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* address::descriptor() {
  protobuf_b_5fnetwork_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_b_5fnetwork_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const address& address::default_instance() {
  protobuf_b_5fnetwork_2eproto::InitDefaults();
  return *internal_default_instance();
}

address* address::New(::google::protobuf::Arena* arena) const {
  address* n = new address;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void address::Clear() {
// @@protoc_insertion_point(message_clear_start:b_network.address)
  if (has_host()) {
    GOOGLE_DCHECK(!host_.IsDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited()));
    (*host_.UnsafeRawStringPointer())->clear();
  }
  port_ = 0u;
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool address::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:b_network.address)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string host = 1 [default = ""];
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_host()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->host().data(), this->host().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "b_network.address.host");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required uint32 port = 2 [default = 0];
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u)) {
          set_has_port();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &port_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:b_network.address)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:b_network.address)
  return false;
#undef DO_
}

void address::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:b_network.address)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required string host = 1 [default = ""];
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->host().data(), this->host().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "b_network.address.host");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->host(), output);
  }

  // required uint32 port = 2 [default = 0];
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->port(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:b_network.address)
}

::google::protobuf::uint8* address::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:b_network.address)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required string host = 1 [default = ""];
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->host().data(), this->host().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "b_network.address.host");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->host(), target);
  }

  // required uint32 port = 2 [default = 0];
  if (cached_has_bits & 0x00000002u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->port(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:b_network.address)
  return target;
}

size_t address::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:b_network.address)
  size_t total_size = 0;

  if (has_host()) {
    // required string host = 1 [default = ""];
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->host());
  }

  if (has_port()) {
    // required uint32 port = 2 [default = 0];
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->port());
  }

  return total_size;
}
size_t address::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:b_network.address)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  if (((_has_bits_[0] & 0x00000003) ^ 0x00000003) == 0) {  // All required fields are present.
    // required string host = 1 [default = ""];
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->host());

    // required uint32 port = 2 [default = 0];
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->port());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void address::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:b_network.address)
  GOOGLE_DCHECK_NE(&from, this);
  const address* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const address>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:b_network.address)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:b_network.address)
    MergeFrom(*source);
  }
}

void address::MergeFrom(const address& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:b_network.address)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 3u) {
    if (cached_has_bits & 0x00000001u) {
      set_has_host();
      host_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.host_);
    }
    if (cached_has_bits & 0x00000002u) {
      port_ = from.port_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void address::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:b_network.address)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void address::CopyFrom(const address& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:b_network.address)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool address::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;
  return true;
}

void address::Swap(address* other) {
  if (other == this) return;
  InternalSwap(other);
}
void address::InternalSwap(address* other) {
  host_.Swap(&other->host_);
  std::swap(port_, other->port_);
  std::swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata address::GetMetadata() const {
  protobuf_b_5fnetwork_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_b_5fnetwork_2eproto::file_level_metadata[kIndexInFileMessages];
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// address

// required string host = 1 [default = ""];
bool address::has_host() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
void address::set_has_host() {
  _has_bits_[0] |= 0x00000001u;
}
void address::clear_has_host() {
  _has_bits_[0] &= ~0x00000001u;
}
void address::clear_host() {
  host_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_host();
}
const ::std::string& address::host() const {
  // @@protoc_insertion_point(field_get:b_network.address.host)
  return host_.GetNoArena();
}
void address::set_host(const ::std::string& value) {
  set_has_host();
  host_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:b_network.address.host)
}
#if LANG_CXX11
void address::set_host(::std::string&& value) {
  set_has_host();
  host_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:b_network.address.host)
}
#endif
void address::set_host(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_host();
  host_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:b_network.address.host)
}
void address::set_host(const char* value, size_t size) {
  set_has_host();
  host_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:b_network.address.host)
}
::std::string* address::mutable_host() {
  set_has_host();
  // @@protoc_insertion_point(field_mutable:b_network.address.host)
  return host_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* address::release_host() {
  // @@protoc_insertion_point(field_release:b_network.address.host)
  clear_has_host();
  return host_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void address::set_allocated_host(::std::string* host) {
  if (host != NULL) {
    set_has_host();
  } else {
    clear_has_host();
  }
  host_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), host);
  // @@protoc_insertion_point(field_set_allocated:b_network.address.host)
}

// required uint32 port = 2 [default = 0];
bool address::has_port() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
void address::set_has_port() {
  _has_bits_[0] |= 0x00000002u;
}
void address::clear_has_port() {
  _has_bits_[0] &= ~0x00000002u;
}
void address::clear_port() {
  port_ = 0u;
  clear_has_port();
}
::google::protobuf::uint32 address::port() const {
  // @@protoc_insertion_point(field_get:b_network.address.port)
  return port_;
}
void address::set_port(::google::protobuf::uint32 value) {
  set_has_port();
  port_ = value;
  // @@protoc_insertion_point(field_set:b_network.address.port)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace b_network

// @@protoc_insertion_point(global_scope)
