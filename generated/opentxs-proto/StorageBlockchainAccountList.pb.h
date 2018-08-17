// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: StorageBlockchainAccountList.proto

#ifndef PROTOBUF_StorageBlockchainAccountList_2eproto__INCLUDED
#define PROTOBUF_StorageBlockchainAccountList_2eproto__INCLUDED

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
#include "ContactEnums.pb.h"  // IWYU pragma: export
// @@protoc_insertion_point(includes)

namespace protobuf_StorageBlockchainAccountList_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void InitDefaultsStorageBlockchainAccountListImpl();
void InitDefaultsStorageBlockchainAccountList();
inline void InitDefaults() {
  InitDefaultsStorageBlockchainAccountList();
}
}  // namespace protobuf_StorageBlockchainAccountList_2eproto
namespace opentxs {
namespace proto {
class StorageBlockchainAccountList;
class StorageBlockchainAccountListDefaultTypeInternal;
extern StorageBlockchainAccountListDefaultTypeInternal _StorageBlockchainAccountList_default_instance_;
}  // namespace proto
}  // namespace opentxs
namespace opentxs {
namespace proto {

// ===================================================================

class StorageBlockchainAccountList : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:opentxs.proto.StorageBlockchainAccountList) */ {
 public:
  StorageBlockchainAccountList();
  virtual ~StorageBlockchainAccountList();

  StorageBlockchainAccountList(const StorageBlockchainAccountList& from);

  inline StorageBlockchainAccountList& operator=(const StorageBlockchainAccountList& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  StorageBlockchainAccountList(StorageBlockchainAccountList&& from) noexcept
    : StorageBlockchainAccountList() {
    *this = ::std::move(from);
  }

  inline StorageBlockchainAccountList& operator=(StorageBlockchainAccountList&& from) noexcept {
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

  static const StorageBlockchainAccountList& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const StorageBlockchainAccountList* internal_default_instance() {
    return reinterpret_cast<const StorageBlockchainAccountList*>(
               &_StorageBlockchainAccountList_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(StorageBlockchainAccountList* other);
  friend void swap(StorageBlockchainAccountList& a, StorageBlockchainAccountList& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline StorageBlockchainAccountList* New() const PROTOBUF_FINAL { return New(NULL); }

  StorageBlockchainAccountList* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from)
    PROTOBUF_FINAL;
  void CopyFrom(const StorageBlockchainAccountList& from);
  void MergeFrom(const StorageBlockchainAccountList& from);
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
  void InternalSwap(StorageBlockchainAccountList* other);
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

  // repeated string list = 3;
  int list_size() const;
  void clear_list();
  static const int kListFieldNumber = 3;
  const ::std::string& list(int index) const;
  ::std::string* mutable_list(int index);
  void set_list(int index, const ::std::string& value);
  #if LANG_CXX11
  void set_list(int index, ::std::string&& value);
  #endif
  void set_list(int index, const char* value);
  void set_list(int index, const char* value, size_t size);
  ::std::string* add_list();
  void add_list(const ::std::string& value);
  #if LANG_CXX11
  void add_list(::std::string&& value);
  #endif
  void add_list(const char* value);
  void add_list(const char* value, size_t size);
  const ::google::protobuf::RepeatedPtrField< ::std::string>& list() const;
  ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_list();

  // optional uint32 version = 1;
  bool has_version() const;
  void clear_version();
  static const int kVersionFieldNumber = 1;
  ::google::protobuf::uint32 version() const;
  void set_version(::google::protobuf::uint32 value);

  // optional .opentxs.proto.ContactItemType id = 2;
  bool has_id() const;
  void clear_id();
  static const int kIdFieldNumber = 2;
  ::opentxs::proto::ContactItemType id() const;
  void set_id(::opentxs::proto::ContactItemType value);

  // @@protoc_insertion_point(class_scope:opentxs.proto.StorageBlockchainAccountList)
 private:
  void set_has_version();
  void clear_has_version();
  void set_has_id();
  void clear_has_id();

  ::google::protobuf::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::std::string> list_;
  ::google::protobuf::uint32 version_;
  int id_;
  friend struct ::protobuf_StorageBlockchainAccountList_2eproto::TableStruct;
  friend void ::protobuf_StorageBlockchainAccountList_2eproto::InitDefaultsStorageBlockchainAccountListImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// StorageBlockchainAccountList

// optional uint32 version = 1;
inline bool StorageBlockchainAccountList::has_version() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void StorageBlockchainAccountList::set_has_version() {
  _has_bits_[0] |= 0x00000001u;
}
inline void StorageBlockchainAccountList::clear_has_version() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void StorageBlockchainAccountList::clear_version() {
  version_ = 0u;
  clear_has_version();
}
inline ::google::protobuf::uint32 StorageBlockchainAccountList::version() const {
  // @@protoc_insertion_point(field_get:opentxs.proto.StorageBlockchainAccountList.version)
  return version_;
}
inline void StorageBlockchainAccountList::set_version(::google::protobuf::uint32 value) {
  set_has_version();
  version_ = value;
  // @@protoc_insertion_point(field_set:opentxs.proto.StorageBlockchainAccountList.version)
}

// optional .opentxs.proto.ContactItemType id = 2;
inline bool StorageBlockchainAccountList::has_id() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void StorageBlockchainAccountList::set_has_id() {
  _has_bits_[0] |= 0x00000002u;
}
inline void StorageBlockchainAccountList::clear_has_id() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void StorageBlockchainAccountList::clear_id() {
  id_ = 0;
  clear_has_id();
}
inline ::opentxs::proto::ContactItemType StorageBlockchainAccountList::id() const {
  // @@protoc_insertion_point(field_get:opentxs.proto.StorageBlockchainAccountList.id)
  return static_cast< ::opentxs::proto::ContactItemType >(id_);
}
inline void StorageBlockchainAccountList::set_id(::opentxs::proto::ContactItemType value) {
  assert(::opentxs::proto::ContactItemType_IsValid(value));
  set_has_id();
  id_ = value;
  // @@protoc_insertion_point(field_set:opentxs.proto.StorageBlockchainAccountList.id)
}

// repeated string list = 3;
inline int StorageBlockchainAccountList::list_size() const {
  return list_.size();
}
inline void StorageBlockchainAccountList::clear_list() {
  list_.Clear();
}
inline const ::std::string& StorageBlockchainAccountList::list(int index) const {
  // @@protoc_insertion_point(field_get:opentxs.proto.StorageBlockchainAccountList.list)
  return list_.Get(index);
}
inline ::std::string* StorageBlockchainAccountList::mutable_list(int index) {
  // @@protoc_insertion_point(field_mutable:opentxs.proto.StorageBlockchainAccountList.list)
  return list_.Mutable(index);
}
inline void StorageBlockchainAccountList::set_list(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:opentxs.proto.StorageBlockchainAccountList.list)
  list_.Mutable(index)->assign(value);
}
#if LANG_CXX11
inline void StorageBlockchainAccountList::set_list(int index, ::std::string&& value) {
  // @@protoc_insertion_point(field_set:opentxs.proto.StorageBlockchainAccountList.list)
  list_.Mutable(index)->assign(std::move(value));
}
#endif
inline void StorageBlockchainAccountList::set_list(int index, const char* value) {
  GOOGLE_DCHECK(value != NULL);
  list_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:opentxs.proto.StorageBlockchainAccountList.list)
}
inline void StorageBlockchainAccountList::set_list(int index, const char* value, size_t size) {
  list_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:opentxs.proto.StorageBlockchainAccountList.list)
}
inline ::std::string* StorageBlockchainAccountList::add_list() {
  // @@protoc_insertion_point(field_add_mutable:opentxs.proto.StorageBlockchainAccountList.list)
  return list_.Add();
}
inline void StorageBlockchainAccountList::add_list(const ::std::string& value) {
  list_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:opentxs.proto.StorageBlockchainAccountList.list)
}
#if LANG_CXX11
inline void StorageBlockchainAccountList::add_list(::std::string&& value) {
  list_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:opentxs.proto.StorageBlockchainAccountList.list)
}
#endif
inline void StorageBlockchainAccountList::add_list(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  list_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:opentxs.proto.StorageBlockchainAccountList.list)
}
inline void StorageBlockchainAccountList::add_list(const char* value, size_t size) {
  list_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:opentxs.proto.StorageBlockchainAccountList.list)
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
StorageBlockchainAccountList::list() const {
  // @@protoc_insertion_point(field_list:opentxs.proto.StorageBlockchainAccountList.list)
  return list_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
StorageBlockchainAccountList::mutable_list() {
  // @@protoc_insertion_point(field_mutable_list:opentxs.proto.StorageBlockchainAccountList.list)
  return &list_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace opentxs

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_StorageBlockchainAccountList_2eproto__INCLUDED