// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: s_control.proto

#ifndef PROTOBUF_s_5fcontrol_2eproto__INCLUDED
#define PROTOBUF_s_5fcontrol_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3003000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3003000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "b_error.pb.h"
// @@protoc_insertion_point(includes)
namespace b_error {
class info;
class infoDefaultTypeInternal;
extern infoDefaultTypeInternal _info_default_instance_;
}  // namespace b_error
namespace s_control {
class get_logger_rq;
class get_logger_rqDefaultTypeInternal;
extern get_logger_rqDefaultTypeInternal _get_logger_rq_default_instance_;
class get_logger_rs;
class get_logger_rsDefaultTypeInternal;
extern get_logger_rsDefaultTypeInternal _get_logger_rs_default_instance_;
class set_logger_rq;
class set_logger_rqDefaultTypeInternal;
extern set_logger_rqDefaultTypeInternal _set_logger_rq_default_instance_;
class set_logger_rs;
class set_logger_rsDefaultTypeInternal;
extern set_logger_rsDefaultTypeInternal _set_logger_rs_default_instance_;
}  // namespace s_control

namespace s_control {

namespace protobuf_s_5fcontrol_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static void InitDefaultsImpl();
  static void Shutdown();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_s_5fcontrol_2eproto

enum set_logger_rq_msg {
  set_logger_rq_msg_id = 16777472
};
bool set_logger_rq_msg_IsValid(int value);
const set_logger_rq_msg set_logger_rq_msg_msg_MIN = set_logger_rq_msg_id;
const set_logger_rq_msg set_logger_rq_msg_msg_MAX = set_logger_rq_msg_id;
const int set_logger_rq_msg_msg_ARRAYSIZE = set_logger_rq_msg_msg_MAX + 1;

const ::google::protobuf::EnumDescriptor* set_logger_rq_msg_descriptor();
inline const ::std::string& set_logger_rq_msg_Name(set_logger_rq_msg value) {
  return ::google::protobuf::internal::NameOfEnum(
    set_logger_rq_msg_descriptor(), value);
}
inline bool set_logger_rq_msg_Parse(
    const ::std::string& name, set_logger_rq_msg* value) {
  return ::google::protobuf::internal::ParseNamedEnum<set_logger_rq_msg>(
    set_logger_rq_msg_descriptor(), name, value);
}
enum set_logger_rs_msg {
  set_logger_rs_msg_id = 16777473
};
bool set_logger_rs_msg_IsValid(int value);
const set_logger_rs_msg set_logger_rs_msg_msg_MIN = set_logger_rs_msg_id;
const set_logger_rs_msg set_logger_rs_msg_msg_MAX = set_logger_rs_msg_id;
const int set_logger_rs_msg_msg_ARRAYSIZE = set_logger_rs_msg_msg_MAX + 1;

const ::google::protobuf::EnumDescriptor* set_logger_rs_msg_descriptor();
inline const ::std::string& set_logger_rs_msg_Name(set_logger_rs_msg value) {
  return ::google::protobuf::internal::NameOfEnum(
    set_logger_rs_msg_descriptor(), value);
}
inline bool set_logger_rs_msg_Parse(
    const ::std::string& name, set_logger_rs_msg* value) {
  return ::google::protobuf::internal::ParseNamedEnum<set_logger_rs_msg>(
    set_logger_rs_msg_descriptor(), name, value);
}
enum get_logger_rq_msg {
  get_logger_rq_msg_id = 16777474
};
bool get_logger_rq_msg_IsValid(int value);
const get_logger_rq_msg get_logger_rq_msg_msg_MIN = get_logger_rq_msg_id;
const get_logger_rq_msg get_logger_rq_msg_msg_MAX = get_logger_rq_msg_id;
const int get_logger_rq_msg_msg_ARRAYSIZE = get_logger_rq_msg_msg_MAX + 1;

const ::google::protobuf::EnumDescriptor* get_logger_rq_msg_descriptor();
inline const ::std::string& get_logger_rq_msg_Name(get_logger_rq_msg value) {
  return ::google::protobuf::internal::NameOfEnum(
    get_logger_rq_msg_descriptor(), value);
}
inline bool get_logger_rq_msg_Parse(
    const ::std::string& name, get_logger_rq_msg* value) {
  return ::google::protobuf::internal::ParseNamedEnum<get_logger_rq_msg>(
    get_logger_rq_msg_descriptor(), name, value);
}
enum get_logger_rs_msg {
  get_logger_rs_msg_id = 16777475
};
bool get_logger_rs_msg_IsValid(int value);
const get_logger_rs_msg get_logger_rs_msg_msg_MIN = get_logger_rs_msg_id;
const get_logger_rs_msg get_logger_rs_msg_msg_MAX = get_logger_rs_msg_id;
const int get_logger_rs_msg_msg_ARRAYSIZE = get_logger_rs_msg_msg_MAX + 1;

const ::google::protobuf::EnumDescriptor* get_logger_rs_msg_descriptor();
inline const ::std::string& get_logger_rs_msg_Name(get_logger_rs_msg value) {
  return ::google::protobuf::internal::NameOfEnum(
    get_logger_rs_msg_descriptor(), value);
}
inline bool get_logger_rs_msg_Parse(
    const ::std::string& name, get_logger_rs_msg* value) {
  return ::google::protobuf::internal::ParseNamedEnum<get_logger_rs_msg>(
    get_logger_rs_msg_descriptor(), name, value);
}
enum msg {
  min_id = 16777472,
  max_id = 16777727
};
bool msg_IsValid(int value);
const msg msg_MIN = min_id;
const msg msg_MAX = max_id;
const int msg_ARRAYSIZE = msg_MAX + 1;

const ::google::protobuf::EnumDescriptor* msg_descriptor();
inline const ::std::string& msg_Name(msg value) {
  return ::google::protobuf::internal::NameOfEnum(
    msg_descriptor(), value);
}
inline bool msg_Parse(
    const ::std::string& name, msg* value) {
  return ::google::protobuf::internal::ParseNamedEnum<msg>(
    msg_descriptor(), name, value);
}
// ===================================================================

class set_logger_rq : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:s_control.set_logger_rq) */ {
 public:
  set_logger_rq();
  virtual ~set_logger_rq();

  set_logger_rq(const set_logger_rq& from);

  inline set_logger_rq& operator=(const set_logger_rq& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const set_logger_rq& default_instance();

  static inline const set_logger_rq* internal_default_instance() {
    return reinterpret_cast<const set_logger_rq*>(
               &_set_logger_rq_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(set_logger_rq* other);

  // implements Message ----------------------------------------------

  inline set_logger_rq* New() const PROTOBUF_FINAL { return New(NULL); }

  set_logger_rq* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const set_logger_rq& from);
  void MergeFrom(const set_logger_rq& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(set_logger_rq* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  typedef set_logger_rq_msg msg;
  static const msg id =
    set_logger_rq_msg_id;
  static inline bool msg_IsValid(int value) {
    return set_logger_rq_msg_IsValid(value);
  }
  static const msg msg_MIN =
    set_logger_rq_msg_msg_MIN;
  static const msg msg_MAX =
    set_logger_rq_msg_msg_MAX;
  static const int msg_ARRAYSIZE =
    set_logger_rq_msg_msg_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  msg_descriptor() {
    return set_logger_rq_msg_descriptor();
  }
  static inline const ::std::string& msg_Name(msg value) {
    return set_logger_rq_msg_Name(value);
  }
  static inline bool msg_Parse(const ::std::string& name,
      msg* value) {
    return set_logger_rq_msg_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // required uint32 level = 1 [default = 0];
  bool has_level() const;
  void clear_level();
  static const int kLevelFieldNumber = 1;
  ::google::protobuf::uint32 level() const;
  void set_level(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:s_control.set_logger_rq)
 private:
  void set_has_level();
  void clear_has_level();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::uint32 level_;
  friend struct protobuf_s_5fcontrol_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class set_logger_rs : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:s_control.set_logger_rs) */ {
 public:
  set_logger_rs();
  virtual ~set_logger_rs();

  set_logger_rs(const set_logger_rs& from);

  inline set_logger_rs& operator=(const set_logger_rs& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const set_logger_rs& default_instance();

  static inline const set_logger_rs* internal_default_instance() {
    return reinterpret_cast<const set_logger_rs*>(
               &_set_logger_rs_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(set_logger_rs* other);

  // implements Message ----------------------------------------------

  inline set_logger_rs* New() const PROTOBUF_FINAL { return New(NULL); }

  set_logger_rs* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const set_logger_rs& from);
  void MergeFrom(const set_logger_rs& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(set_logger_rs* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  typedef set_logger_rs_msg msg;
  static const msg id =
    set_logger_rs_msg_id;
  static inline bool msg_IsValid(int value) {
    return set_logger_rs_msg_IsValid(value);
  }
  static const msg msg_MIN =
    set_logger_rs_msg_msg_MIN;
  static const msg msg_MAX =
    set_logger_rs_msg_msg_MAX;
  static const int msg_ARRAYSIZE =
    set_logger_rs_msg_msg_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  msg_descriptor() {
    return set_logger_rs_msg_descriptor();
  }
  static inline const ::std::string& msg_Name(msg value) {
    return set_logger_rs_msg_Name(value);
  }
  static inline bool msg_Parse(const ::std::string& name,
      msg* value) {
    return set_logger_rs_msg_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // required .b_error.info error = 1;
  bool has_error() const;
  void clear_error();
  static const int kErrorFieldNumber = 1;
  const ::b_error::info& error() const;
  ::b_error::info* mutable_error();
  ::b_error::info* release_error();
  void set_allocated_error(::b_error::info* error);

  // required uint32 level = 2 [default = 0];
  bool has_level() const;
  void clear_level();
  static const int kLevelFieldNumber = 2;
  ::google::protobuf::uint32 level() const;
  void set_level(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:s_control.set_logger_rs)
 private:
  void set_has_error();
  void clear_has_error();
  void set_has_level();
  void clear_has_level();

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::b_error::info* error_;
  ::google::protobuf::uint32 level_;
  friend struct protobuf_s_5fcontrol_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class get_logger_rq : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:s_control.get_logger_rq) */ {
 public:
  get_logger_rq();
  virtual ~get_logger_rq();

  get_logger_rq(const get_logger_rq& from);

  inline get_logger_rq& operator=(const get_logger_rq& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const get_logger_rq& default_instance();

  static inline const get_logger_rq* internal_default_instance() {
    return reinterpret_cast<const get_logger_rq*>(
               &_get_logger_rq_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    2;

  void Swap(get_logger_rq* other);

  // implements Message ----------------------------------------------

  inline get_logger_rq* New() const PROTOBUF_FINAL { return New(NULL); }

  get_logger_rq* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const get_logger_rq& from);
  void MergeFrom(const get_logger_rq& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(get_logger_rq* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  typedef get_logger_rq_msg msg;
  static const msg id =
    get_logger_rq_msg_id;
  static inline bool msg_IsValid(int value) {
    return get_logger_rq_msg_IsValid(value);
  }
  static const msg msg_MIN =
    get_logger_rq_msg_msg_MIN;
  static const msg msg_MAX =
    get_logger_rq_msg_msg_MAX;
  static const int msg_ARRAYSIZE =
    get_logger_rq_msg_msg_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  msg_descriptor() {
    return get_logger_rq_msg_descriptor();
  }
  static inline const ::std::string& msg_Name(msg value) {
    return get_logger_rq_msg_Name(value);
  }
  static inline bool msg_Parse(const ::std::string& name,
      msg* value) {
    return get_logger_rq_msg_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:s_control.get_logger_rq)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  friend struct protobuf_s_5fcontrol_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class get_logger_rs : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:s_control.get_logger_rs) */ {
 public:
  get_logger_rs();
  virtual ~get_logger_rs();

  get_logger_rs(const get_logger_rs& from);

  inline get_logger_rs& operator=(const get_logger_rs& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const get_logger_rs& default_instance();

  static inline const get_logger_rs* internal_default_instance() {
    return reinterpret_cast<const get_logger_rs*>(
               &_get_logger_rs_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    3;

  void Swap(get_logger_rs* other);

  // implements Message ----------------------------------------------

  inline get_logger_rs* New() const PROTOBUF_FINAL { return New(NULL); }

  get_logger_rs* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const get_logger_rs& from);
  void MergeFrom(const get_logger_rs& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(get_logger_rs* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  typedef get_logger_rs_msg msg;
  static const msg id =
    get_logger_rs_msg_id;
  static inline bool msg_IsValid(int value) {
    return get_logger_rs_msg_IsValid(value);
  }
  static const msg msg_MIN =
    get_logger_rs_msg_msg_MIN;
  static const msg msg_MAX =
    get_logger_rs_msg_msg_MAX;
  static const int msg_ARRAYSIZE =
    get_logger_rs_msg_msg_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  msg_descriptor() {
    return get_logger_rs_msg_descriptor();
  }
  static inline const ::std::string& msg_Name(msg value) {
    return get_logger_rs_msg_Name(value);
  }
  static inline bool msg_Parse(const ::std::string& name,
      msg* value) {
    return get_logger_rs_msg_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // required .b_error.info error = 1;
  bool has_error() const;
  void clear_error();
  static const int kErrorFieldNumber = 1;
  const ::b_error::info& error() const;
  ::b_error::info* mutable_error();
  ::b_error::info* release_error();
  void set_allocated_error(::b_error::info* error);

  // required uint32 level = 2 [default = 0];
  bool has_level() const;
  void clear_level();
  static const int kLevelFieldNumber = 2;
  ::google::protobuf::uint32 level() const;
  void set_level(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:s_control.get_logger_rs)
 private:
  void set_has_error();
  void clear_has_error();
  void set_has_level();
  void clear_has_level();

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::b_error::info* error_;
  ::google::protobuf::uint32 level_;
  friend struct protobuf_s_5fcontrol_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// set_logger_rq

// required uint32 level = 1 [default = 0];
inline bool set_logger_rq::has_level() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void set_logger_rq::set_has_level() {
  _has_bits_[0] |= 0x00000001u;
}
inline void set_logger_rq::clear_has_level() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void set_logger_rq::clear_level() {
  level_ = 0u;
  clear_has_level();
}
inline ::google::protobuf::uint32 set_logger_rq::level() const {
  // @@protoc_insertion_point(field_get:s_control.set_logger_rq.level)
  return level_;
}
inline void set_logger_rq::set_level(::google::protobuf::uint32 value) {
  set_has_level();
  level_ = value;
  // @@protoc_insertion_point(field_set:s_control.set_logger_rq.level)
}

// -------------------------------------------------------------------

// set_logger_rs

// required .b_error.info error = 1;
inline bool set_logger_rs::has_error() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void set_logger_rs::set_has_error() {
  _has_bits_[0] |= 0x00000001u;
}
inline void set_logger_rs::clear_has_error() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void set_logger_rs::clear_error() {
  if (error_ != NULL) error_->::b_error::info::Clear();
  clear_has_error();
}
inline const ::b_error::info& set_logger_rs::error() const {
  // @@protoc_insertion_point(field_get:s_control.set_logger_rs.error)
  return error_ != NULL ? *error_
                         : *::b_error::info::internal_default_instance();
}
inline ::b_error::info* set_logger_rs::mutable_error() {
  set_has_error();
  if (error_ == NULL) {
    error_ = new ::b_error::info;
  }
  // @@protoc_insertion_point(field_mutable:s_control.set_logger_rs.error)
  return error_;
}
inline ::b_error::info* set_logger_rs::release_error() {
  // @@protoc_insertion_point(field_release:s_control.set_logger_rs.error)
  clear_has_error();
  ::b_error::info* temp = error_;
  error_ = NULL;
  return temp;
}
inline void set_logger_rs::set_allocated_error(::b_error::info* error) {
  delete error_;
  error_ = error;
  if (error) {
    set_has_error();
  } else {
    clear_has_error();
  }
  // @@protoc_insertion_point(field_set_allocated:s_control.set_logger_rs.error)
}

// required uint32 level = 2 [default = 0];
inline bool set_logger_rs::has_level() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void set_logger_rs::set_has_level() {
  _has_bits_[0] |= 0x00000002u;
}
inline void set_logger_rs::clear_has_level() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void set_logger_rs::clear_level() {
  level_ = 0u;
  clear_has_level();
}
inline ::google::protobuf::uint32 set_logger_rs::level() const {
  // @@protoc_insertion_point(field_get:s_control.set_logger_rs.level)
  return level_;
}
inline void set_logger_rs::set_level(::google::protobuf::uint32 value) {
  set_has_level();
  level_ = value;
  // @@protoc_insertion_point(field_set:s_control.set_logger_rs.level)
}

// -------------------------------------------------------------------

// get_logger_rq

// -------------------------------------------------------------------

// get_logger_rs

// required .b_error.info error = 1;
inline bool get_logger_rs::has_error() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void get_logger_rs::set_has_error() {
  _has_bits_[0] |= 0x00000001u;
}
inline void get_logger_rs::clear_has_error() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void get_logger_rs::clear_error() {
  if (error_ != NULL) error_->::b_error::info::Clear();
  clear_has_error();
}
inline const ::b_error::info& get_logger_rs::error() const {
  // @@protoc_insertion_point(field_get:s_control.get_logger_rs.error)
  return error_ != NULL ? *error_
                         : *::b_error::info::internal_default_instance();
}
inline ::b_error::info* get_logger_rs::mutable_error() {
  set_has_error();
  if (error_ == NULL) {
    error_ = new ::b_error::info;
  }
  // @@protoc_insertion_point(field_mutable:s_control.get_logger_rs.error)
  return error_;
}
inline ::b_error::info* get_logger_rs::release_error() {
  // @@protoc_insertion_point(field_release:s_control.get_logger_rs.error)
  clear_has_error();
  ::b_error::info* temp = error_;
  error_ = NULL;
  return temp;
}
inline void get_logger_rs::set_allocated_error(::b_error::info* error) {
  delete error_;
  error_ = error;
  if (error) {
    set_has_error();
  } else {
    clear_has_error();
  }
  // @@protoc_insertion_point(field_set_allocated:s_control.get_logger_rs.error)
}

// required uint32 level = 2 [default = 0];
inline bool get_logger_rs::has_level() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void get_logger_rs::set_has_level() {
  _has_bits_[0] |= 0x00000002u;
}
inline void get_logger_rs::clear_has_level() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void get_logger_rs::clear_level() {
  level_ = 0u;
  clear_has_level();
}
inline ::google::protobuf::uint32 get_logger_rs::level() const {
  // @@protoc_insertion_point(field_get:s_control.get_logger_rs.level)
  return level_;
}
inline void get_logger_rs::set_level(::google::protobuf::uint32 value) {
  set_has_level();
  level_ = value;
  // @@protoc_insertion_point(field_set:s_control.get_logger_rs.level)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


}  // namespace s_control

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::s_control::set_logger_rq_msg> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::s_control::set_logger_rq_msg>() {
  return ::s_control::set_logger_rq_msg_descriptor();
}
template <> struct is_proto_enum< ::s_control::set_logger_rs_msg> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::s_control::set_logger_rs_msg>() {
  return ::s_control::set_logger_rs_msg_descriptor();
}
template <> struct is_proto_enum< ::s_control::get_logger_rq_msg> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::s_control::get_logger_rq_msg>() {
  return ::s_control::get_logger_rq_msg_descriptor();
}
template <> struct is_proto_enum< ::s_control::get_logger_rs_msg> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::s_control::get_logger_rs_msg>() {
  return ::s_control::get_logger_rs_msg_descriptor();
}
template <> struct is_proto_enum< ::s_control::msg> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::s_control::msg>() {
  return ::s_control::msg_descriptor();
}

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_s_5fcontrol_2eproto__INCLUDED
