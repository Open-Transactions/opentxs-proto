// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Bip47Direction.proto

#ifndef PROTOBUF_Bip47Direction_2eproto__INCLUDED
#define PROTOBUF_Bip47Direction_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include "Bip47Address.pb.h"  // IWYU pragma: export
// @@protoc_insertion_point(includes)

namespace protobuf_Bip47Direction_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void InitDefaultsBip47DirectionImpl();
void InitDefaultsBip47Direction();
inline void InitDefaults() {
  InitDefaultsBip47Direction();
}
}  // namespace protobuf_Bip47Direction_2eproto
namespace opentxs {
namespace proto {
class Bip47Direction;
class Bip47DirectionDefaultTypeInternal;
extern Bip47DirectionDefaultTypeInternal _Bip47Direction_default_instance_;
}  // namespace proto
}  // namespace opentxs
namespace opentxs {
namespace proto {

// ===================================================================

class Bip47Direction : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:opentxs.proto.Bip47Direction) */ {
 public:
  Bip47Direction();
  virtual ~Bip47Direction();

  Bip47Direction(const Bip47Direction& from);

  inline Bip47Direction& operator=(const Bip47Direction& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Bip47Direction(Bip47Direction&& from) noexcept
    : Bip47Direction() {
    *this = ::std::move(from);
  }

  inline Bip47Direction& operator=(Bip47Direction&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::std::string& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::std::string* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const Bip47Direction& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Bip47Direction* internal_default_instance() {
    return reinterpret_cast<const Bip47Direction*>(
               &_Bip47Direction_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(Bip47Direction* other);
  friend void swap(Bip47Direction& a, Bip47Direction& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Bip47Direction* New() const PROTOBUF_FINAL { return New(NULL); }

  Bip47Direction* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from)
    PROTOBUF_FINAL;
  void CopyFrom(const Bip47Direction& from);
  void MergeFrom(const Bip47Direction& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  void DiscardUnknownFields();
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(Bip47Direction* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::std::string GetTypeName() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated string notification = 2;
  int notification_size() const;
  void clear_notification();
  static const int kNotificationFieldNumber = 2;
  const ::std::string& notification(int index) const;
  ::std::string* mutable_notification(int index);
  void set_notification(int index, const ::std::string& value);
  #if LANG_CXX11
  void set_notification(int index, ::std::string&& value);
  #endif
  void set_notification(int index, const char* value);
  void set_notification(int index, const char* value, size_t size);
  ::std::string* add_notification();
  void add_notification(const ::std::string& value);
  #if LANG_CXX11
  void add_notification(::std::string&& value);
  #endif
  void add_notification(const char* value);
  void add_notification(const char* value, size_t size);
  const ::google::protobuf::RepeatedPtrField< ::std::string>& notification() const;
  ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_notification();

  // repeated .opentxs.proto.Bip47Address address = 3;
  int address_size() const;
  void clear_address();
  static const int kAddressFieldNumber = 3;
  const ::opentxs::proto::Bip47Address& address(int index) const;
  ::opentxs::proto::Bip47Address* mutable_address(int index);
  ::opentxs::proto::Bip47Address* add_address();
  ::google::protobuf::RepeatedPtrField< ::opentxs::proto::Bip47Address >*
      mutable_address();
  const ::google::protobuf::RepeatedPtrField< ::opentxs::proto::Bip47Address >&
      address() const;

  // optional uint32 version = 1;
  bool has_version() const;
  void clear_version();
  static const int kVersionFieldNumber = 1;
  ::google::protobuf::uint32 version() const;
  void set_version(::google::protobuf::uint32 value);

  // optional uint32 index = 4;
  bool has_index() const;
  void clear_index();
  static const int kIndexFieldNumber = 4;
  ::google::protobuf::uint32 index() const;
  void set_index(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:opentxs.proto.Bip47Direction)
 private:
  void set_has_version();
  void clear_has_version();
  void set_has_index();
  void clear_has_index();

  ::google::protobuf::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::std::string> notification_;
  ::google::protobuf::RepeatedPtrField< ::opentxs::proto::Bip47Address > address_;
  ::google::protobuf::uint32 version_;
  ::google::protobuf::uint32 index_;
  friend struct ::protobuf_Bip47Direction_2eproto::TableStruct;
  friend void ::protobuf_Bip47Direction_2eproto::InitDefaultsBip47DirectionImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Bip47Direction

// optional uint32 version = 1;
inline bool Bip47Direction::has_version() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Bip47Direction::set_has_version() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Bip47Direction::clear_has_version() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Bip47Direction::clear_version() {
  version_ = 0u;
  clear_has_version();
}
inline ::google::protobuf::uint32 Bip47Direction::version() const {
  // @@protoc_insertion_point(field_get:opentxs.proto.Bip47Direction.version)
  return version_;
}
inline void Bip47Direction::set_version(::google::protobuf::uint32 value) {
  set_has_version();
  version_ = value;
  // @@protoc_insertion_point(field_set:opentxs.proto.Bip47Direction.version)
}

// repeated string notification = 2;
inline int Bip47Direction::notification_size() const {
  return notification_.size();
}
inline void Bip47Direction::clear_notification() {
  notification_.Clear();
}
inline const ::std::string& Bip47Direction::notification(int index) const {
  // @@protoc_insertion_point(field_get:opentxs.proto.Bip47Direction.notification)
  return notification_.Get(index);
}
inline ::std::string* Bip47Direction::mutable_notification(int index) {
  // @@protoc_insertion_point(field_mutable:opentxs.proto.Bip47Direction.notification)
  return notification_.Mutable(index);
}
inline void Bip47Direction::set_notification(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:opentxs.proto.Bip47Direction.notification)
  notification_.Mutable(index)->assign(value);
}
#if LANG_CXX11
inline void Bip47Direction::set_notification(int index, ::std::string&& value) {
  // @@protoc_insertion_point(field_set:opentxs.proto.Bip47Direction.notification)
  notification_.Mutable(index)->assign(std::move(value));
}
#endif
inline void Bip47Direction::set_notification(int index, const char* value) {
  GOOGLE_DCHECK(value != NULL);
  notification_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:opentxs.proto.Bip47Direction.notification)
}
inline void Bip47Direction::set_notification(int index, const char* value, size_t size) {
  notification_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:opentxs.proto.Bip47Direction.notification)
}
inline ::std::string* Bip47Direction::add_notification() {
  // @@protoc_insertion_point(field_add_mutable:opentxs.proto.Bip47Direction.notification)
  return notification_.Add();
}
inline void Bip47Direction::add_notification(const ::std::string& value) {
  notification_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:opentxs.proto.Bip47Direction.notification)
}
#if LANG_CXX11
inline void Bip47Direction::add_notification(::std::string&& value) {
  notification_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:opentxs.proto.Bip47Direction.notification)
}
#endif
inline void Bip47Direction::add_notification(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  notification_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:opentxs.proto.Bip47Direction.notification)
}
inline void Bip47Direction::add_notification(const char* value, size_t size) {
  notification_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:opentxs.proto.Bip47Direction.notification)
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
Bip47Direction::notification() const {
  // @@protoc_insertion_point(field_list:opentxs.proto.Bip47Direction.notification)
  return notification_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
Bip47Direction::mutable_notification() {
  // @@protoc_insertion_point(field_mutable_list:opentxs.proto.Bip47Direction.notification)
  return &notification_;
}

// repeated .opentxs.proto.Bip47Address address = 3;
inline int Bip47Direction::address_size() const {
  return address_.size();
}
inline const ::opentxs::proto::Bip47Address& Bip47Direction::address(int index) const {
  // @@protoc_insertion_point(field_get:opentxs.proto.Bip47Direction.address)
  return address_.Get(index);
}
inline ::opentxs::proto::Bip47Address* Bip47Direction::mutable_address(int index) {
  // @@protoc_insertion_point(field_mutable:opentxs.proto.Bip47Direction.address)
  return address_.Mutable(index);
}
inline ::opentxs::proto::Bip47Address* Bip47Direction::add_address() {
  // @@protoc_insertion_point(field_add:opentxs.proto.Bip47Direction.address)
  return address_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::opentxs::proto::Bip47Address >*
Bip47Direction::mutable_address() {
  // @@protoc_insertion_point(field_mutable_list:opentxs.proto.Bip47Direction.address)
  return &address_;
}
inline const ::google::protobuf::RepeatedPtrField< ::opentxs::proto::Bip47Address >&
Bip47Direction::address() const {
  // @@protoc_insertion_point(field_list:opentxs.proto.Bip47Direction.address)
  return address_;
}

// optional uint32 index = 4;
inline bool Bip47Direction::has_index() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Bip47Direction::set_has_index() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Bip47Direction::clear_has_index() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Bip47Direction::clear_index() {
  index_ = 0u;
  clear_has_index();
}
inline ::google::protobuf::uint32 Bip47Direction::index() const {
  // @@protoc_insertion_point(field_get:opentxs.proto.Bip47Direction.index)
  return index_;
}
inline void Bip47Direction::set_index(::google::protobuf::uint32 value) {
  set_has_index();
  index_ = value;
  // @@protoc_insertion_point(field_set:opentxs.proto.Bip47Direction.index)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace opentxs

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_Bip47Direction_2eproto__INCLUDED
