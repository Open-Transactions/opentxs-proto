// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: StorageBip47AddressIndex.proto

#ifndef PROTOBUF_StorageBip47AddressIndex_2eproto__INCLUDED
#define PROTOBUF_StorageBip47AddressIndex_2eproto__INCLUDED

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
// @@protoc_insertion_point(includes)

namespace protobuf_StorageBip47AddressIndex_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void InitDefaultsStorageBip47AddressIndexImpl();
void InitDefaultsStorageBip47AddressIndex();
inline void InitDefaults() {
  InitDefaultsStorageBip47AddressIndex();
}
}  // namespace protobuf_StorageBip47AddressIndex_2eproto
namespace opentxs {
namespace proto {
class StorageBip47AddressIndex;
class StorageBip47AddressIndexDefaultTypeInternal;
extern StorageBip47AddressIndexDefaultTypeInternal _StorageBip47AddressIndex_default_instance_;
}  // namespace proto
}  // namespace opentxs
namespace opentxs {
namespace proto {

// ===================================================================

class StorageBip47AddressIndex : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:opentxs.proto.StorageBip47AddressIndex) */ {
 public:
  StorageBip47AddressIndex();
  virtual ~StorageBip47AddressIndex();

  StorageBip47AddressIndex(const StorageBip47AddressIndex& from);

  inline StorageBip47AddressIndex& operator=(const StorageBip47AddressIndex& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  StorageBip47AddressIndex(StorageBip47AddressIndex&& from) noexcept
    : StorageBip47AddressIndex() {
    *this = ::std::move(from);
  }

  inline StorageBip47AddressIndex& operator=(StorageBip47AddressIndex&& from) noexcept {
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

  static const StorageBip47AddressIndex& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const StorageBip47AddressIndex* internal_default_instance() {
    return reinterpret_cast<const StorageBip47AddressIndex*>(
               &_StorageBip47AddressIndex_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(StorageBip47AddressIndex* other);
  friend void swap(StorageBip47AddressIndex& a, StorageBip47AddressIndex& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline StorageBip47AddressIndex* New() const PROTOBUF_FINAL { return New(NULL); }

  StorageBip47AddressIndex* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from)
    PROTOBUF_FINAL;
  void CopyFrom(const StorageBip47AddressIndex& from);
  void MergeFrom(const StorageBip47AddressIndex& from);
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
  void InternalSwap(StorageBip47AddressIndex* other);
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

  // optional string address = 2;
  bool has_address() const;
  void clear_address();
  static const int kAddressFieldNumber = 2;
  const ::std::string& address() const;
  void set_address(const ::std::string& value);
  #if LANG_CXX11
  void set_address(::std::string&& value);
  #endif
  void set_address(const char* value);
  void set_address(const char* value, size_t size);
  ::std::string* mutable_address();
  ::std::string* release_address();
  void set_allocated_address(::std::string* address);

  // optional string channelid = 3;
  bool has_channelid() const;
  void clear_channelid();
  static const int kChannelidFieldNumber = 3;
  const ::std::string& channelid() const;
  void set_channelid(const ::std::string& value);
  #if LANG_CXX11
  void set_channelid(::std::string&& value);
  #endif
  void set_channelid(const char* value);
  void set_channelid(const char* value, size_t size);
  ::std::string* mutable_channelid();
  ::std::string* release_channelid();
  void set_allocated_channelid(::std::string* channelid);

  // optional uint32 version = 1;
  bool has_version() const;
  void clear_version();
  static const int kVersionFieldNumber = 1;
  ::google::protobuf::uint32 version() const;
  void set_version(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:opentxs.proto.StorageBip47AddressIndex)
 private:
  void set_has_version();
  void clear_has_version();
  void set_has_address();
  void clear_has_address();
  void set_has_channelid();
  void clear_has_channelid();

  ::google::protobuf::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr address_;
  ::google::protobuf::internal::ArenaStringPtr channelid_;
  ::google::protobuf::uint32 version_;
  friend struct ::protobuf_StorageBip47AddressIndex_2eproto::TableStruct;
  friend void ::protobuf_StorageBip47AddressIndex_2eproto::InitDefaultsStorageBip47AddressIndexImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// StorageBip47AddressIndex

// optional uint32 version = 1;
inline bool StorageBip47AddressIndex::has_version() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void StorageBip47AddressIndex::set_has_version() {
  _has_bits_[0] |= 0x00000004u;
}
inline void StorageBip47AddressIndex::clear_has_version() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void StorageBip47AddressIndex::clear_version() {
  version_ = 0u;
  clear_has_version();
}
inline ::google::protobuf::uint32 StorageBip47AddressIndex::version() const {
  // @@protoc_insertion_point(field_get:opentxs.proto.StorageBip47AddressIndex.version)
  return version_;
}
inline void StorageBip47AddressIndex::set_version(::google::protobuf::uint32 value) {
  set_has_version();
  version_ = value;
  // @@protoc_insertion_point(field_set:opentxs.proto.StorageBip47AddressIndex.version)
}

// optional string address = 2;
inline bool StorageBip47AddressIndex::has_address() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void StorageBip47AddressIndex::set_has_address() {
  _has_bits_[0] |= 0x00000001u;
}
inline void StorageBip47AddressIndex::clear_has_address() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void StorageBip47AddressIndex::clear_address() {
  address_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_address();
}
inline const ::std::string& StorageBip47AddressIndex::address() const {
  // @@protoc_insertion_point(field_get:opentxs.proto.StorageBip47AddressIndex.address)
  return address_.GetNoArena();
}
inline void StorageBip47AddressIndex::set_address(const ::std::string& value) {
  set_has_address();
  address_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:opentxs.proto.StorageBip47AddressIndex.address)
}
#if LANG_CXX11
inline void StorageBip47AddressIndex::set_address(::std::string&& value) {
  set_has_address();
  address_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:opentxs.proto.StorageBip47AddressIndex.address)
}
#endif
inline void StorageBip47AddressIndex::set_address(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_address();
  address_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:opentxs.proto.StorageBip47AddressIndex.address)
}
inline void StorageBip47AddressIndex::set_address(const char* value, size_t size) {
  set_has_address();
  address_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:opentxs.proto.StorageBip47AddressIndex.address)
}
inline ::std::string* StorageBip47AddressIndex::mutable_address() {
  set_has_address();
  // @@protoc_insertion_point(field_mutable:opentxs.proto.StorageBip47AddressIndex.address)
  return address_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* StorageBip47AddressIndex::release_address() {
  // @@protoc_insertion_point(field_release:opentxs.proto.StorageBip47AddressIndex.address)
  clear_has_address();
  return address_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void StorageBip47AddressIndex::set_allocated_address(::std::string* address) {
  if (address != NULL) {
    set_has_address();
  } else {
    clear_has_address();
  }
  address_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), address);
  // @@protoc_insertion_point(field_set_allocated:opentxs.proto.StorageBip47AddressIndex.address)
}

// optional string channelid = 3;
inline bool StorageBip47AddressIndex::has_channelid() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void StorageBip47AddressIndex::set_has_channelid() {
  _has_bits_[0] |= 0x00000002u;
}
inline void StorageBip47AddressIndex::clear_has_channelid() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void StorageBip47AddressIndex::clear_channelid() {
  channelid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_channelid();
}
inline const ::std::string& StorageBip47AddressIndex::channelid() const {
  // @@protoc_insertion_point(field_get:opentxs.proto.StorageBip47AddressIndex.channelid)
  return channelid_.GetNoArena();
}
inline void StorageBip47AddressIndex::set_channelid(const ::std::string& value) {
  set_has_channelid();
  channelid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:opentxs.proto.StorageBip47AddressIndex.channelid)
}
#if LANG_CXX11
inline void StorageBip47AddressIndex::set_channelid(::std::string&& value) {
  set_has_channelid();
  channelid_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:opentxs.proto.StorageBip47AddressIndex.channelid)
}
#endif
inline void StorageBip47AddressIndex::set_channelid(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_channelid();
  channelid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:opentxs.proto.StorageBip47AddressIndex.channelid)
}
inline void StorageBip47AddressIndex::set_channelid(const char* value, size_t size) {
  set_has_channelid();
  channelid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:opentxs.proto.StorageBip47AddressIndex.channelid)
}
inline ::std::string* StorageBip47AddressIndex::mutable_channelid() {
  set_has_channelid();
  // @@protoc_insertion_point(field_mutable:opentxs.proto.StorageBip47AddressIndex.channelid)
  return channelid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* StorageBip47AddressIndex::release_channelid() {
  // @@protoc_insertion_point(field_release:opentxs.proto.StorageBip47AddressIndex.channelid)
  clear_has_channelid();
  return channelid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void StorageBip47AddressIndex::set_allocated_channelid(::std::string* channelid) {
  if (channelid != NULL) {
    set_has_channelid();
  } else {
    clear_has_channelid();
  }
  channelid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), channelid);
  // @@protoc_insertion_point(field_set_allocated:opentxs.proto.StorageBip47AddressIndex.channelid)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace opentxs

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_StorageBip47AddressIndex_2eproto__INCLUDED
