// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: b_math.proto

#ifndef PROTOBUF_b_5fmath_2eproto__INCLUDED
#define PROTOBUF_b_5fmath_2eproto__INCLUDED

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
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
namespace b_math {
class coord;
class coordDefaultTypeInternal;
extern coordDefaultTypeInternal _coord_default_instance_;
class mat3;
class mat3DefaultTypeInternal;
extern mat3DefaultTypeInternal _mat3_default_instance_;
class mat4;
class mat4DefaultTypeInternal;
extern mat4DefaultTypeInternal _mat4_default_instance_;
class vec2;
class vec2DefaultTypeInternal;
extern vec2DefaultTypeInternal _vec2_default_instance_;
class vec3;
class vec3DefaultTypeInternal;
extern vec3DefaultTypeInternal _vec3_default_instance_;
class vec4;
class vec4DefaultTypeInternal;
extern vec4DefaultTypeInternal _vec4_default_instance_;
}  // namespace b_math

namespace b_math {

namespace protobuf_b_5fmath_2eproto {
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
}  // namespace protobuf_b_5fmath_2eproto

// ===================================================================

class coord : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:b_math.coord) */ {
 public:
  coord();
  virtual ~coord();

  coord(const coord& from);

  inline coord& operator=(const coord& from) {
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
  static const coord& default_instance();

  static inline const coord* internal_default_instance() {
    return reinterpret_cast<const coord*>(
               &_coord_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(coord* other);

  // implements Message ----------------------------------------------

  inline coord* New() const PROTOBUF_FINAL { return New(NULL); }

  coord* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const coord& from);
  void MergeFrom(const coord& from);
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
  void InternalSwap(coord* other);
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

  // accessors -------------------------------------------------------

  // required double j = 1 [default = 0];
  bool has_j() const;
  void clear_j();
  static const int kJFieldNumber = 1;
  double j() const;
  void set_j(double value);

  // required double w = 2 [default = 0];
  bool has_w() const;
  void clear_w();
  static const int kWFieldNumber = 2;
  double w() const;
  void set_w(double value);

  // @@protoc_insertion_point(class_scope:b_math.coord)
 private:
  void set_has_j();
  void clear_has_j();
  void set_has_w();
  void clear_has_w();

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  double j_;
  double w_;
  friend struct protobuf_b_5fmath_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class vec2 : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:b_math.vec2) */ {
 public:
  vec2();
  virtual ~vec2();

  vec2(const vec2& from);

  inline vec2& operator=(const vec2& from) {
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
  static const vec2& default_instance();

  static inline const vec2* internal_default_instance() {
    return reinterpret_cast<const vec2*>(
               &_vec2_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(vec2* other);

  // implements Message ----------------------------------------------

  inline vec2* New() const PROTOBUF_FINAL { return New(NULL); }

  vec2* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const vec2& from);
  void MergeFrom(const vec2& from);
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
  void InternalSwap(vec2* other);
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

  // accessors -------------------------------------------------------

  // required double x = 1 [default = 0];
  bool has_x() const;
  void clear_x();
  static const int kXFieldNumber = 1;
  double x() const;
  void set_x(double value);

  // required double y = 2 [default = 0];
  bool has_y() const;
  void clear_y();
  static const int kYFieldNumber = 2;
  double y() const;
  void set_y(double value);

  // @@protoc_insertion_point(class_scope:b_math.vec2)
 private:
  void set_has_x();
  void clear_has_x();
  void set_has_y();
  void clear_has_y();

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  double x_;
  double y_;
  friend struct protobuf_b_5fmath_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class vec3 : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:b_math.vec3) */ {
 public:
  vec3();
  virtual ~vec3();

  vec3(const vec3& from);

  inline vec3& operator=(const vec3& from) {
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
  static const vec3& default_instance();

  static inline const vec3* internal_default_instance() {
    return reinterpret_cast<const vec3*>(
               &_vec3_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    2;

  void Swap(vec3* other);

  // implements Message ----------------------------------------------

  inline vec3* New() const PROTOBUF_FINAL { return New(NULL); }

  vec3* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const vec3& from);
  void MergeFrom(const vec3& from);
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
  void InternalSwap(vec3* other);
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

  // accessors -------------------------------------------------------

  // required double x = 1 [default = 0];
  bool has_x() const;
  void clear_x();
  static const int kXFieldNumber = 1;
  double x() const;
  void set_x(double value);

  // required double y = 2 [default = 0];
  bool has_y() const;
  void clear_y();
  static const int kYFieldNumber = 2;
  double y() const;
  void set_y(double value);

  // required double z = 3 [default = 0];
  bool has_z() const;
  void clear_z();
  static const int kZFieldNumber = 3;
  double z() const;
  void set_z(double value);

  // @@protoc_insertion_point(class_scope:b_math.vec3)
 private:
  void set_has_x();
  void clear_has_x();
  void set_has_y();
  void clear_has_y();
  void set_has_z();
  void clear_has_z();

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  double x_;
  double y_;
  double z_;
  friend struct protobuf_b_5fmath_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class vec4 : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:b_math.vec4) */ {
 public:
  vec4();
  virtual ~vec4();

  vec4(const vec4& from);

  inline vec4& operator=(const vec4& from) {
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
  static const vec4& default_instance();

  static inline const vec4* internal_default_instance() {
    return reinterpret_cast<const vec4*>(
               &_vec4_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    3;

  void Swap(vec4* other);

  // implements Message ----------------------------------------------

  inline vec4* New() const PROTOBUF_FINAL { return New(NULL); }

  vec4* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const vec4& from);
  void MergeFrom(const vec4& from);
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
  void InternalSwap(vec4* other);
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

  // accessors -------------------------------------------------------

  // required double x = 1 [default = 0];
  bool has_x() const;
  void clear_x();
  static const int kXFieldNumber = 1;
  double x() const;
  void set_x(double value);

  // required double y = 2 [default = 0];
  bool has_y() const;
  void clear_y();
  static const int kYFieldNumber = 2;
  double y() const;
  void set_y(double value);

  // required double z = 3 [default = 0];
  bool has_z() const;
  void clear_z();
  static const int kZFieldNumber = 3;
  double z() const;
  void set_z(double value);

  // required double w = 4 [default = 0];
  bool has_w() const;
  void clear_w();
  static const int kWFieldNumber = 4;
  double w() const;
  void set_w(double value);

  // @@protoc_insertion_point(class_scope:b_math.vec4)
 private:
  void set_has_x();
  void clear_has_x();
  void set_has_y();
  void clear_has_y();
  void set_has_z();
  void clear_has_z();
  void set_has_w();
  void clear_has_w();

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  double x_;
  double y_;
  double z_;
  double w_;
  friend struct protobuf_b_5fmath_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class mat3 : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:b_math.mat3) */ {
 public:
  mat3();
  virtual ~mat3();

  mat3(const mat3& from);

  inline mat3& operator=(const mat3& from) {
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
  static const mat3& default_instance();

  static inline const mat3* internal_default_instance() {
    return reinterpret_cast<const mat3*>(
               &_mat3_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    4;

  void Swap(mat3* other);

  // implements Message ----------------------------------------------

  inline mat3* New() const PROTOBUF_FINAL { return New(NULL); }

  mat3* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const mat3& from);
  void MergeFrom(const mat3& from);
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
  void InternalSwap(mat3* other);
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

  // accessors -------------------------------------------------------

  // repeated double m = 1;
  int m_size() const;
  void clear_m();
  static const int kMFieldNumber = 1;
  double m(int index) const;
  void set_m(int index, double value);
  void add_m(double value);
  const ::google::protobuf::RepeatedField< double >&
      m() const;
  ::google::protobuf::RepeatedField< double >*
      mutable_m();

  // @@protoc_insertion_point(class_scope:b_math.mat3)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedField< double > m_;
  friend struct protobuf_b_5fmath_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class mat4 : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:b_math.mat4) */ {
 public:
  mat4();
  virtual ~mat4();

  mat4(const mat4& from);

  inline mat4& operator=(const mat4& from) {
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
  static const mat4& default_instance();

  static inline const mat4* internal_default_instance() {
    return reinterpret_cast<const mat4*>(
               &_mat4_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    5;

  void Swap(mat4* other);

  // implements Message ----------------------------------------------

  inline mat4* New() const PROTOBUF_FINAL { return New(NULL); }

  mat4* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const mat4& from);
  void MergeFrom(const mat4& from);
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
  void InternalSwap(mat4* other);
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

  // accessors -------------------------------------------------------

  // repeated double m = 1;
  int m_size() const;
  void clear_m();
  static const int kMFieldNumber = 1;
  double m(int index) const;
  void set_m(int index, double value);
  void add_m(double value);
  const ::google::protobuf::RepeatedField< double >&
      m() const;
  ::google::protobuf::RepeatedField< double >*
      mutable_m();

  // @@protoc_insertion_point(class_scope:b_math.mat4)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedField< double > m_;
  friend struct protobuf_b_5fmath_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// coord

// required double j = 1 [default = 0];
inline bool coord::has_j() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void coord::set_has_j() {
  _has_bits_[0] |= 0x00000001u;
}
inline void coord::clear_has_j() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void coord::clear_j() {
  j_ = 0;
  clear_has_j();
}
inline double coord::j() const {
  // @@protoc_insertion_point(field_get:b_math.coord.j)
  return j_;
}
inline void coord::set_j(double value) {
  set_has_j();
  j_ = value;
  // @@protoc_insertion_point(field_set:b_math.coord.j)
}

// required double w = 2 [default = 0];
inline bool coord::has_w() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void coord::set_has_w() {
  _has_bits_[0] |= 0x00000002u;
}
inline void coord::clear_has_w() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void coord::clear_w() {
  w_ = 0;
  clear_has_w();
}
inline double coord::w() const {
  // @@protoc_insertion_point(field_get:b_math.coord.w)
  return w_;
}
inline void coord::set_w(double value) {
  set_has_w();
  w_ = value;
  // @@protoc_insertion_point(field_set:b_math.coord.w)
}

// -------------------------------------------------------------------

// vec2

// required double x = 1 [default = 0];
inline bool vec2::has_x() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void vec2::set_has_x() {
  _has_bits_[0] |= 0x00000001u;
}
inline void vec2::clear_has_x() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void vec2::clear_x() {
  x_ = 0;
  clear_has_x();
}
inline double vec2::x() const {
  // @@protoc_insertion_point(field_get:b_math.vec2.x)
  return x_;
}
inline void vec2::set_x(double value) {
  set_has_x();
  x_ = value;
  // @@protoc_insertion_point(field_set:b_math.vec2.x)
}

// required double y = 2 [default = 0];
inline bool vec2::has_y() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void vec2::set_has_y() {
  _has_bits_[0] |= 0x00000002u;
}
inline void vec2::clear_has_y() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void vec2::clear_y() {
  y_ = 0;
  clear_has_y();
}
inline double vec2::y() const {
  // @@protoc_insertion_point(field_get:b_math.vec2.y)
  return y_;
}
inline void vec2::set_y(double value) {
  set_has_y();
  y_ = value;
  // @@protoc_insertion_point(field_set:b_math.vec2.y)
}

// -------------------------------------------------------------------

// vec3

// required double x = 1 [default = 0];
inline bool vec3::has_x() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void vec3::set_has_x() {
  _has_bits_[0] |= 0x00000001u;
}
inline void vec3::clear_has_x() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void vec3::clear_x() {
  x_ = 0;
  clear_has_x();
}
inline double vec3::x() const {
  // @@protoc_insertion_point(field_get:b_math.vec3.x)
  return x_;
}
inline void vec3::set_x(double value) {
  set_has_x();
  x_ = value;
  // @@protoc_insertion_point(field_set:b_math.vec3.x)
}

// required double y = 2 [default = 0];
inline bool vec3::has_y() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void vec3::set_has_y() {
  _has_bits_[0] |= 0x00000002u;
}
inline void vec3::clear_has_y() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void vec3::clear_y() {
  y_ = 0;
  clear_has_y();
}
inline double vec3::y() const {
  // @@protoc_insertion_point(field_get:b_math.vec3.y)
  return y_;
}
inline void vec3::set_y(double value) {
  set_has_y();
  y_ = value;
  // @@protoc_insertion_point(field_set:b_math.vec3.y)
}

// required double z = 3 [default = 0];
inline bool vec3::has_z() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void vec3::set_has_z() {
  _has_bits_[0] |= 0x00000004u;
}
inline void vec3::clear_has_z() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void vec3::clear_z() {
  z_ = 0;
  clear_has_z();
}
inline double vec3::z() const {
  // @@protoc_insertion_point(field_get:b_math.vec3.z)
  return z_;
}
inline void vec3::set_z(double value) {
  set_has_z();
  z_ = value;
  // @@protoc_insertion_point(field_set:b_math.vec3.z)
}

// -------------------------------------------------------------------

// vec4

// required double x = 1 [default = 0];
inline bool vec4::has_x() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void vec4::set_has_x() {
  _has_bits_[0] |= 0x00000001u;
}
inline void vec4::clear_has_x() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void vec4::clear_x() {
  x_ = 0;
  clear_has_x();
}
inline double vec4::x() const {
  // @@protoc_insertion_point(field_get:b_math.vec4.x)
  return x_;
}
inline void vec4::set_x(double value) {
  set_has_x();
  x_ = value;
  // @@protoc_insertion_point(field_set:b_math.vec4.x)
}

// required double y = 2 [default = 0];
inline bool vec4::has_y() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void vec4::set_has_y() {
  _has_bits_[0] |= 0x00000002u;
}
inline void vec4::clear_has_y() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void vec4::clear_y() {
  y_ = 0;
  clear_has_y();
}
inline double vec4::y() const {
  // @@protoc_insertion_point(field_get:b_math.vec4.y)
  return y_;
}
inline void vec4::set_y(double value) {
  set_has_y();
  y_ = value;
  // @@protoc_insertion_point(field_set:b_math.vec4.y)
}

// required double z = 3 [default = 0];
inline bool vec4::has_z() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void vec4::set_has_z() {
  _has_bits_[0] |= 0x00000004u;
}
inline void vec4::clear_has_z() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void vec4::clear_z() {
  z_ = 0;
  clear_has_z();
}
inline double vec4::z() const {
  // @@protoc_insertion_point(field_get:b_math.vec4.z)
  return z_;
}
inline void vec4::set_z(double value) {
  set_has_z();
  z_ = value;
  // @@protoc_insertion_point(field_set:b_math.vec4.z)
}

// required double w = 4 [default = 0];
inline bool vec4::has_w() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void vec4::set_has_w() {
  _has_bits_[0] |= 0x00000008u;
}
inline void vec4::clear_has_w() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void vec4::clear_w() {
  w_ = 0;
  clear_has_w();
}
inline double vec4::w() const {
  // @@protoc_insertion_point(field_get:b_math.vec4.w)
  return w_;
}
inline void vec4::set_w(double value) {
  set_has_w();
  w_ = value;
  // @@protoc_insertion_point(field_set:b_math.vec4.w)
}

// -------------------------------------------------------------------

// mat3

// repeated double m = 1;
inline int mat3::m_size() const {
  return m_.size();
}
inline void mat3::clear_m() {
  m_.Clear();
}
inline double mat3::m(int index) const {
  // @@protoc_insertion_point(field_get:b_math.mat3.m)
  return m_.Get(index);
}
inline void mat3::set_m(int index, double value) {
  m_.Set(index, value);
  // @@protoc_insertion_point(field_set:b_math.mat3.m)
}
inline void mat3::add_m(double value) {
  m_.Add(value);
  // @@protoc_insertion_point(field_add:b_math.mat3.m)
}
inline const ::google::protobuf::RepeatedField< double >&
mat3::m() const {
  // @@protoc_insertion_point(field_list:b_math.mat3.m)
  return m_;
}
inline ::google::protobuf::RepeatedField< double >*
mat3::mutable_m() {
  // @@protoc_insertion_point(field_mutable_list:b_math.mat3.m)
  return &m_;
}

// -------------------------------------------------------------------

// mat4

// repeated double m = 1;
inline int mat4::m_size() const {
  return m_.size();
}
inline void mat4::clear_m() {
  m_.Clear();
}
inline double mat4::m(int index) const {
  // @@protoc_insertion_point(field_get:b_math.mat4.m)
  return m_.Get(index);
}
inline void mat4::set_m(int index, double value) {
  m_.Set(index, value);
  // @@protoc_insertion_point(field_set:b_math.mat4.m)
}
inline void mat4::add_m(double value) {
  m_.Add(value);
  // @@protoc_insertion_point(field_add:b_math.mat4.m)
}
inline const ::google::protobuf::RepeatedField< double >&
mat4::m() const {
  // @@protoc_insertion_point(field_list:b_math.mat4.m)
  return m_;
}
inline ::google::protobuf::RepeatedField< double >*
mat4::mutable_m() {
  // @@protoc_insertion_point(field_mutable_list:b_math.mat4.m)
  return &m_;
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


}  // namespace b_math

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_b_5fmath_2eproto__INCLUDED
