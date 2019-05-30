// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ListenAddress.proto

#ifndef PROTOBUF_ListenAddress_2eproto__INCLUDED
#define PROTOBUF_ListenAddress_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3005001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
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
#include "ContractEnums.pb.h"  // IWYU pragma: export
// @@protoc_insertion_point(includes)

namespace protobuf_ListenAddress_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void InitDefaultsListenAddressImpl();
void InitDefaultsListenAddress();
inline void InitDefaults() {
  InitDefaultsListenAddress();
}
}  // namespace protobuf_ListenAddress_2eproto
namespace opentxs {
namespace proto {
class ListenAddress;
class ListenAddressDefaultTypeInternal;
extern ListenAddressDefaultTypeInternal _ListenAddress_default_instance_;
}  // namespace proto
}  // namespace opentxs
namespace opentxs {
namespace proto {

// ===================================================================

class ListenAddress : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:opentxs.proto.ListenAddress) */ {
 public:
  ListenAddress();
  virtual ~ListenAddress();

  ListenAddress(const ListenAddress& from);

  inline ListenAddress& operator=(const ListenAddress& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ListenAddress(ListenAddress&& from) noexcept
    : ListenAddress() {
    *this = ::std::move(from);
  }

  inline ListenAddress& operator=(ListenAddress&& from) noexcept {
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

  static const ListenAddress& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ListenAddress* internal_default_instance() {
    return reinterpret_cast<const ListenAddress*>(
               &_ListenAddress_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(ListenAddress* other);
  friend void swap(ListenAddress& a, ListenAddress& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ListenAddress* New() const PROTOBUF_FINAL { return New(NULL); }

  ListenAddress* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from)
    PROTOBUF_FINAL;
  void CopyFrom(const ListenAddress& from);
  void MergeFrom(const ListenAddress& from);
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
  void InternalSwap(ListenAddress* other);
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

  // optional string host = 4;
  bool has_host() const;
  void clear_host();
  static const int kHostFieldNumber = 4;
  const ::std::string& host() const;
  void set_host(const ::std::string& value);
  #if LANG_CXX11
  void set_host(::std::string&& value);
  #endif
  void set_host(const char* value);
  void set_host(const char* value, size_t size);
  ::std::string* mutable_host();
  ::std::string* release_host();
  void set_allocated_host(::std::string* host);

  // optional uint32 version = 1;
  bool has_version() const;
  void clear_version();
  static const int kVersionFieldNumber = 1;
  ::google::protobuf::uint32 version() const;
  void set_version(::google::protobuf::uint32 value);

  // optional .opentxs.proto.AddressType type = 2;
  bool has_type() const;
  void clear_type();
  static const int kTypeFieldNumber = 2;
  ::opentxs::proto::AddressType type() const;
  void set_type(::opentxs::proto::AddressType value);

  // optional .opentxs.proto.ProtocolVersion protocol = 3;
  bool has_protocol() const;
  void clear_protocol();
  static const int kProtocolFieldNumber = 3;
  ::opentxs::proto::ProtocolVersion protocol() const;
  void set_protocol(::opentxs::proto::ProtocolVersion value);

  // optional uint32 port = 5;
  bool has_port() const;
  void clear_port();
  static const int kPortFieldNumber = 5;
  ::google::protobuf::uint32 port() const;
  void set_port(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:opentxs.proto.ListenAddress)
 private:
  void set_has_version();
  void clear_has_version();
  void set_has_type();
  void clear_has_type();
  void set_has_protocol();
  void clear_has_protocol();
  void set_has_host();
  void clear_has_host();
  void set_has_port();
  void clear_has_port();

  ::google::protobuf::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr host_;
  ::google::protobuf::uint32 version_;
  int type_;
  int protocol_;
  ::google::protobuf::uint32 port_;
  friend struct ::protobuf_ListenAddress_2eproto::TableStruct;
  friend void ::protobuf_ListenAddress_2eproto::InitDefaultsListenAddressImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ListenAddress

// optional uint32 version = 1;
inline bool ListenAddress::has_version() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ListenAddress::set_has_version() {
  _has_bits_[0] |= 0x00000002u;
}
inline void ListenAddress::clear_has_version() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void ListenAddress::clear_version() {
  version_ = 0u;
  clear_has_version();
}
inline ::google::protobuf::uint32 ListenAddress::version() const {
  // @@protoc_insertion_point(field_get:opentxs.proto.ListenAddress.version)
  return version_;
}
inline void ListenAddress::set_version(::google::protobuf::uint32 value) {
  set_has_version();
  version_ = value;
  // @@protoc_insertion_point(field_set:opentxs.proto.ListenAddress.version)
}

// optional .opentxs.proto.AddressType type = 2;
inline bool ListenAddress::has_type() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void ListenAddress::set_has_type() {
  _has_bits_[0] |= 0x00000004u;
}
inline void ListenAddress::clear_has_type() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void ListenAddress::clear_type() {
  type_ = 0;
  clear_has_type();
}
inline ::opentxs::proto::AddressType ListenAddress::type() const {
  // @@protoc_insertion_point(field_get:opentxs.proto.ListenAddress.type)
  return static_cast< ::opentxs::proto::AddressType >(type_);
}
inline void ListenAddress::set_type(::opentxs::proto::AddressType value) {
  assert(::opentxs::proto::AddressType_IsValid(value));
  set_has_type();
  type_ = value;
  // @@protoc_insertion_point(field_set:opentxs.proto.ListenAddress.type)
}

// optional .opentxs.proto.ProtocolVersion protocol = 3;
inline bool ListenAddress::has_protocol() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void ListenAddress::set_has_protocol() {
  _has_bits_[0] |= 0x00000008u;
}
inline void ListenAddress::clear_has_protocol() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void ListenAddress::clear_protocol() {
  protocol_ = 0;
  clear_has_protocol();
}
inline ::opentxs::proto::ProtocolVersion ListenAddress::protocol() const {
  // @@protoc_insertion_point(field_get:opentxs.proto.ListenAddress.protocol)
  return static_cast< ::opentxs::proto::ProtocolVersion >(protocol_);
}
inline void ListenAddress::set_protocol(::opentxs::proto::ProtocolVersion value) {
  assert(::opentxs::proto::ProtocolVersion_IsValid(value));
  set_has_protocol();
  protocol_ = value;
  // @@protoc_insertion_point(field_set:opentxs.proto.ListenAddress.protocol)
}

// optional string host = 4;
inline bool ListenAddress::has_host() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ListenAddress::set_has_host() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ListenAddress::clear_has_host() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ListenAddress::clear_host() {
  host_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_host();
}
inline const ::std::string& ListenAddress::host() const {
  // @@protoc_insertion_point(field_get:opentxs.proto.ListenAddress.host)
  return host_.GetNoArena();
}
inline void ListenAddress::set_host(const ::std::string& value) {
  set_has_host();
  host_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:opentxs.proto.ListenAddress.host)
}
#if LANG_CXX11
inline void ListenAddress::set_host(::std::string&& value) {
  set_has_host();
  host_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:opentxs.proto.ListenAddress.host)
}
#endif
inline void ListenAddress::set_host(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_host();
  host_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:opentxs.proto.ListenAddress.host)
}
inline void ListenAddress::set_host(const char* value, size_t size) {
  set_has_host();
  host_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:opentxs.proto.ListenAddress.host)
}
inline ::std::string* ListenAddress::mutable_host() {
  set_has_host();
  // @@protoc_insertion_point(field_mutable:opentxs.proto.ListenAddress.host)
  return host_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ListenAddress::release_host() {
  // @@protoc_insertion_point(field_release:opentxs.proto.ListenAddress.host)
  clear_has_host();
  return host_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ListenAddress::set_allocated_host(::std::string* host) {
  if (host != NULL) {
    set_has_host();
  } else {
    clear_has_host();
  }
  host_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), host);
  // @@protoc_insertion_point(field_set_allocated:opentxs.proto.ListenAddress.host)
}

// optional uint32 port = 5;
inline bool ListenAddress::has_port() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void ListenAddress::set_has_port() {
  _has_bits_[0] |= 0x00000010u;
}
inline void ListenAddress::clear_has_port() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void ListenAddress::clear_port() {
  port_ = 0u;
  clear_has_port();
}
inline ::google::protobuf::uint32 ListenAddress::port() const {
  // @@protoc_insertion_point(field_get:opentxs.proto.ListenAddress.port)
  return port_;
}
inline void ListenAddress::set_port(::google::protobuf::uint32 value) {
  set_has_port();
  port_ = value;
  // @@protoc_insertion_point(field_set:opentxs.proto.ListenAddress.port)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace opentxs

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_ListenAddress_2eproto__INCLUDED
