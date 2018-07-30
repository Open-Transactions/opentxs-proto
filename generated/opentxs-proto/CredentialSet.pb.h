// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: CredentialSet.proto

#ifndef PROTOBUF_CredentialSet_2eproto__INCLUDED
#define PROTOBUF_CredentialSet_2eproto__INCLUDED

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
#include "Enums.pb.h"  // IWYU pragma: export
#include "Credential.pb.h"  // IWYU pragma: export
// @@protoc_insertion_point(includes)

namespace protobuf_CredentialSet_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void InitDefaultsCredentialSetImpl();
void InitDefaultsCredentialSet();
inline void InitDefaults() {
  InitDefaultsCredentialSet();
}
}  // namespace protobuf_CredentialSet_2eproto
namespace opentxs {
namespace proto {
class CredentialSet;
class CredentialSetDefaultTypeInternal;
extern CredentialSetDefaultTypeInternal _CredentialSet_default_instance_;
}  // namespace proto
}  // namespace opentxs
namespace opentxs {
namespace proto {

// ===================================================================

class CredentialSet : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:opentxs.proto.CredentialSet) */ {
 public:
  CredentialSet();
  virtual ~CredentialSet();

  CredentialSet(const CredentialSet& from);

  inline CredentialSet& operator=(const CredentialSet& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  CredentialSet(CredentialSet&& from) noexcept
    : CredentialSet() {
    *this = ::std::move(from);
  }

  inline CredentialSet& operator=(CredentialSet&& from) noexcept {
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

  static const CredentialSet& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const CredentialSet* internal_default_instance() {
    return reinterpret_cast<const CredentialSet*>(
               &_CredentialSet_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(CredentialSet* other);
  friend void swap(CredentialSet& a, CredentialSet& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline CredentialSet* New() const PROTOBUF_FINAL { return New(NULL); }

  CredentialSet* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from)
    PROTOBUF_FINAL;
  void CopyFrom(const CredentialSet& from);
  void MergeFrom(const CredentialSet& from);
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
  void InternalSwap(CredentialSet* other);
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

  // repeated string activeChildIDs = 7;
  int activechildids_size() const;
  void clear_activechildids();
  static const int kActiveChildIDsFieldNumber = 7;
  const ::std::string& activechildids(int index) const;
  ::std::string* mutable_activechildids(int index);
  void set_activechildids(int index, const ::std::string& value);
  #if LANG_CXX11
  void set_activechildids(int index, ::std::string&& value);
  #endif
  void set_activechildids(int index, const char* value);
  void set_activechildids(int index, const char* value, size_t size);
  ::std::string* add_activechildids();
  void add_activechildids(const ::std::string& value);
  #if LANG_CXX11
  void add_activechildids(::std::string&& value);
  #endif
  void add_activechildids(const char* value);
  void add_activechildids(const char* value, size_t size);
  const ::google::protobuf::RepeatedPtrField< ::std::string>& activechildids() const;
  ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_activechildids();

  // repeated .opentxs.proto.Credential activeChildren = 8;
  int activechildren_size() const;
  void clear_activechildren();
  static const int kActiveChildrenFieldNumber = 8;
  const ::opentxs::proto::Credential& activechildren(int index) const;
  ::opentxs::proto::Credential* mutable_activechildren(int index);
  ::opentxs::proto::Credential* add_activechildren();
  ::google::protobuf::RepeatedPtrField< ::opentxs::proto::Credential >*
      mutable_activechildren();
  const ::google::protobuf::RepeatedPtrField< ::opentxs::proto::Credential >&
      activechildren() const;

  // repeated string revokedChildIDs = 9;
  int revokedchildids_size() const;
  void clear_revokedchildids();
  static const int kRevokedChildIDsFieldNumber = 9;
  const ::std::string& revokedchildids(int index) const;
  ::std::string* mutable_revokedchildids(int index);
  void set_revokedchildids(int index, const ::std::string& value);
  #if LANG_CXX11
  void set_revokedchildids(int index, ::std::string&& value);
  #endif
  void set_revokedchildids(int index, const char* value);
  void set_revokedchildids(int index, const char* value, size_t size);
  ::std::string* add_revokedchildids();
  void add_revokedchildids(const ::std::string& value);
  #if LANG_CXX11
  void add_revokedchildids(::std::string&& value);
  #endif
  void add_revokedchildids(const char* value);
  void add_revokedchildids(const char* value, size_t size);
  const ::google::protobuf::RepeatedPtrField< ::std::string>& revokedchildids() const;
  ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_revokedchildids();

  // repeated .opentxs.proto.Credential revokedChildren = 10;
  int revokedchildren_size() const;
  void clear_revokedchildren();
  static const int kRevokedChildrenFieldNumber = 10;
  const ::opentxs::proto::Credential& revokedchildren(int index) const;
  ::opentxs::proto::Credential* mutable_revokedchildren(int index);
  ::opentxs::proto::Credential* add_revokedchildren();
  ::google::protobuf::RepeatedPtrField< ::opentxs::proto::Credential >*
      mutable_revokedchildren();
  const ::google::protobuf::RepeatedPtrField< ::opentxs::proto::Credential >&
      revokedchildren() const;

  // optional string nymID = 2;
  bool has_nymid() const;
  void clear_nymid();
  static const int kNymIDFieldNumber = 2;
  const ::std::string& nymid() const;
  void set_nymid(const ::std::string& value);
  #if LANG_CXX11
  void set_nymid(::std::string&& value);
  #endif
  void set_nymid(const char* value);
  void set_nymid(const char* value, size_t size);
  ::std::string* mutable_nymid();
  ::std::string* release_nymid();
  void set_allocated_nymid(::std::string* nymid);

  // optional string masterID = 3;
  bool has_masterid() const;
  void clear_masterid();
  static const int kMasterIDFieldNumber = 3;
  const ::std::string& masterid() const;
  void set_masterid(const ::std::string& value);
  #if LANG_CXX11
  void set_masterid(::std::string&& value);
  #endif
  void set_masterid(const char* value);
  void set_masterid(const char* value, size_t size);
  ::std::string* mutable_masterid();
  ::std::string* release_masterid();
  void set_allocated_masterid(::std::string* masterid);

  // optional .opentxs.proto.Credential masterCredential = 6;
  bool has_mastercredential() const;
  void clear_mastercredential();
  static const int kMasterCredentialFieldNumber = 6;
  const ::opentxs::proto::Credential& mastercredential() const;
  ::opentxs::proto::Credential* release_mastercredential();
  ::opentxs::proto::Credential* mutable_mastercredential();
  void set_allocated_mastercredential(::opentxs::proto::Credential* mastercredential);

  // optional uint32 version = 1;
  bool has_version() const;
  void clear_version();
  static const int kVersionFieldNumber = 1;
  ::google::protobuf::uint32 version() const;
  void set_version(::google::protobuf::uint32 value);

  // optional .opentxs.proto.CredentialSetMode mode = 4;
  bool has_mode() const;
  void clear_mode();
  static const int kModeFieldNumber = 4;
  ::opentxs::proto::CredentialSetMode mode() const;
  void set_mode(::opentxs::proto::CredentialSetMode value);

  // optional uint32 index = 5;
  bool has_index() const;
  void clear_index();
  static const int kIndexFieldNumber = 5;
  ::google::protobuf::uint32 index() const;
  void set_index(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:opentxs.proto.CredentialSet)
 private:
  void set_has_version();
  void clear_has_version();
  void set_has_nymid();
  void clear_has_nymid();
  void set_has_masterid();
  void clear_has_masterid();
  void set_has_mode();
  void clear_has_mode();
  void set_has_index();
  void clear_has_index();
  void set_has_mastercredential();
  void clear_has_mastercredential();

  ::google::protobuf::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::std::string> activechildids_;
  ::google::protobuf::RepeatedPtrField< ::opentxs::proto::Credential > activechildren_;
  ::google::protobuf::RepeatedPtrField< ::std::string> revokedchildids_;
  ::google::protobuf::RepeatedPtrField< ::opentxs::proto::Credential > revokedchildren_;
  ::google::protobuf::internal::ArenaStringPtr nymid_;
  ::google::protobuf::internal::ArenaStringPtr masterid_;
  ::opentxs::proto::Credential* mastercredential_;
  ::google::protobuf::uint32 version_;
  int mode_;
  ::google::protobuf::uint32 index_;
  friend struct ::protobuf_CredentialSet_2eproto::TableStruct;
  friend void ::protobuf_CredentialSet_2eproto::InitDefaultsCredentialSetImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// CredentialSet

// optional uint32 version = 1;
inline bool CredentialSet::has_version() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void CredentialSet::set_has_version() {
  _has_bits_[0] |= 0x00000008u;
}
inline void CredentialSet::clear_has_version() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void CredentialSet::clear_version() {
  version_ = 0u;
  clear_has_version();
}
inline ::google::protobuf::uint32 CredentialSet::version() const {
  // @@protoc_insertion_point(field_get:opentxs.proto.CredentialSet.version)
  return version_;
}
inline void CredentialSet::set_version(::google::protobuf::uint32 value) {
  set_has_version();
  version_ = value;
  // @@protoc_insertion_point(field_set:opentxs.proto.CredentialSet.version)
}

// optional string nymID = 2;
inline bool CredentialSet::has_nymid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CredentialSet::set_has_nymid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CredentialSet::clear_has_nymid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CredentialSet::clear_nymid() {
  nymid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_nymid();
}
inline const ::std::string& CredentialSet::nymid() const {
  // @@protoc_insertion_point(field_get:opentxs.proto.CredentialSet.nymID)
  return nymid_.GetNoArena();
}
inline void CredentialSet::set_nymid(const ::std::string& value) {
  set_has_nymid();
  nymid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:opentxs.proto.CredentialSet.nymID)
}
#if LANG_CXX11
inline void CredentialSet::set_nymid(::std::string&& value) {
  set_has_nymid();
  nymid_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:opentxs.proto.CredentialSet.nymID)
}
#endif
inline void CredentialSet::set_nymid(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_nymid();
  nymid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:opentxs.proto.CredentialSet.nymID)
}
inline void CredentialSet::set_nymid(const char* value, size_t size) {
  set_has_nymid();
  nymid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:opentxs.proto.CredentialSet.nymID)
}
inline ::std::string* CredentialSet::mutable_nymid() {
  set_has_nymid();
  // @@protoc_insertion_point(field_mutable:opentxs.proto.CredentialSet.nymID)
  return nymid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* CredentialSet::release_nymid() {
  // @@protoc_insertion_point(field_release:opentxs.proto.CredentialSet.nymID)
  clear_has_nymid();
  return nymid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void CredentialSet::set_allocated_nymid(::std::string* nymid) {
  if (nymid != NULL) {
    set_has_nymid();
  } else {
    clear_has_nymid();
  }
  nymid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), nymid);
  // @@protoc_insertion_point(field_set_allocated:opentxs.proto.CredentialSet.nymID)
}

// optional string masterID = 3;
inline bool CredentialSet::has_masterid() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void CredentialSet::set_has_masterid() {
  _has_bits_[0] |= 0x00000002u;
}
inline void CredentialSet::clear_has_masterid() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void CredentialSet::clear_masterid() {
  masterid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_masterid();
}
inline const ::std::string& CredentialSet::masterid() const {
  // @@protoc_insertion_point(field_get:opentxs.proto.CredentialSet.masterID)
  return masterid_.GetNoArena();
}
inline void CredentialSet::set_masterid(const ::std::string& value) {
  set_has_masterid();
  masterid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:opentxs.proto.CredentialSet.masterID)
}
#if LANG_CXX11
inline void CredentialSet::set_masterid(::std::string&& value) {
  set_has_masterid();
  masterid_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:opentxs.proto.CredentialSet.masterID)
}
#endif
inline void CredentialSet::set_masterid(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_masterid();
  masterid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:opentxs.proto.CredentialSet.masterID)
}
inline void CredentialSet::set_masterid(const char* value, size_t size) {
  set_has_masterid();
  masterid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:opentxs.proto.CredentialSet.masterID)
}
inline ::std::string* CredentialSet::mutable_masterid() {
  set_has_masterid();
  // @@protoc_insertion_point(field_mutable:opentxs.proto.CredentialSet.masterID)
  return masterid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* CredentialSet::release_masterid() {
  // @@protoc_insertion_point(field_release:opentxs.proto.CredentialSet.masterID)
  clear_has_masterid();
  return masterid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void CredentialSet::set_allocated_masterid(::std::string* masterid) {
  if (masterid != NULL) {
    set_has_masterid();
  } else {
    clear_has_masterid();
  }
  masterid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), masterid);
  // @@protoc_insertion_point(field_set_allocated:opentxs.proto.CredentialSet.masterID)
}

// optional .opentxs.proto.CredentialSetMode mode = 4;
inline bool CredentialSet::has_mode() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void CredentialSet::set_has_mode() {
  _has_bits_[0] |= 0x00000010u;
}
inline void CredentialSet::clear_has_mode() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void CredentialSet::clear_mode() {
  mode_ = 0;
  clear_has_mode();
}
inline ::opentxs::proto::CredentialSetMode CredentialSet::mode() const {
  // @@protoc_insertion_point(field_get:opentxs.proto.CredentialSet.mode)
  return static_cast< ::opentxs::proto::CredentialSetMode >(mode_);
}
inline void CredentialSet::set_mode(::opentxs::proto::CredentialSetMode value) {
  assert(::opentxs::proto::CredentialSetMode_IsValid(value));
  set_has_mode();
  mode_ = value;
  // @@protoc_insertion_point(field_set:opentxs.proto.CredentialSet.mode)
}

// optional uint32 index = 5;
inline bool CredentialSet::has_index() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void CredentialSet::set_has_index() {
  _has_bits_[0] |= 0x00000020u;
}
inline void CredentialSet::clear_has_index() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void CredentialSet::clear_index() {
  index_ = 0u;
  clear_has_index();
}
inline ::google::protobuf::uint32 CredentialSet::index() const {
  // @@protoc_insertion_point(field_get:opentxs.proto.CredentialSet.index)
  return index_;
}
inline void CredentialSet::set_index(::google::protobuf::uint32 value) {
  set_has_index();
  index_ = value;
  // @@protoc_insertion_point(field_set:opentxs.proto.CredentialSet.index)
}

// optional .opentxs.proto.Credential masterCredential = 6;
inline bool CredentialSet::has_mastercredential() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void CredentialSet::set_has_mastercredential() {
  _has_bits_[0] |= 0x00000004u;
}
inline void CredentialSet::clear_has_mastercredential() {
  _has_bits_[0] &= ~0x00000004u;
}
inline const ::opentxs::proto::Credential& CredentialSet::mastercredential() const {
  const ::opentxs::proto::Credential* p = mastercredential_;
  // @@protoc_insertion_point(field_get:opentxs.proto.CredentialSet.masterCredential)
  return p != NULL ? *p : *reinterpret_cast<const ::opentxs::proto::Credential*>(
      &::opentxs::proto::_Credential_default_instance_);
}
inline ::opentxs::proto::Credential* CredentialSet::release_mastercredential() {
  // @@protoc_insertion_point(field_release:opentxs.proto.CredentialSet.masterCredential)
  clear_has_mastercredential();
  ::opentxs::proto::Credential* temp = mastercredential_;
  mastercredential_ = NULL;
  return temp;
}
inline ::opentxs::proto::Credential* CredentialSet::mutable_mastercredential() {
  set_has_mastercredential();
  if (mastercredential_ == NULL) {
    mastercredential_ = new ::opentxs::proto::Credential;
  }
  // @@protoc_insertion_point(field_mutable:opentxs.proto.CredentialSet.masterCredential)
  return mastercredential_;
}
inline void CredentialSet::set_allocated_mastercredential(::opentxs::proto::Credential* mastercredential) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete reinterpret_cast< ::google::protobuf::MessageLite*>(mastercredential_);
  }
  if (mastercredential) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      mastercredential = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, mastercredential, submessage_arena);
    }
    set_has_mastercredential();
  } else {
    clear_has_mastercredential();
  }
  mastercredential_ = mastercredential;
  // @@protoc_insertion_point(field_set_allocated:opentxs.proto.CredentialSet.masterCredential)
}

// repeated string activeChildIDs = 7;
inline int CredentialSet::activechildids_size() const {
  return activechildids_.size();
}
inline void CredentialSet::clear_activechildids() {
  activechildids_.Clear();
}
inline const ::std::string& CredentialSet::activechildids(int index) const {
  // @@protoc_insertion_point(field_get:opentxs.proto.CredentialSet.activeChildIDs)
  return activechildids_.Get(index);
}
inline ::std::string* CredentialSet::mutable_activechildids(int index) {
  // @@protoc_insertion_point(field_mutable:opentxs.proto.CredentialSet.activeChildIDs)
  return activechildids_.Mutable(index);
}
inline void CredentialSet::set_activechildids(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:opentxs.proto.CredentialSet.activeChildIDs)
  activechildids_.Mutable(index)->assign(value);
}
#if LANG_CXX11
inline void CredentialSet::set_activechildids(int index, ::std::string&& value) {
  // @@protoc_insertion_point(field_set:opentxs.proto.CredentialSet.activeChildIDs)
  activechildids_.Mutable(index)->assign(std::move(value));
}
#endif
inline void CredentialSet::set_activechildids(int index, const char* value) {
  GOOGLE_DCHECK(value != NULL);
  activechildids_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:opentxs.proto.CredentialSet.activeChildIDs)
}
inline void CredentialSet::set_activechildids(int index, const char* value, size_t size) {
  activechildids_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:opentxs.proto.CredentialSet.activeChildIDs)
}
inline ::std::string* CredentialSet::add_activechildids() {
  // @@protoc_insertion_point(field_add_mutable:opentxs.proto.CredentialSet.activeChildIDs)
  return activechildids_.Add();
}
inline void CredentialSet::add_activechildids(const ::std::string& value) {
  activechildids_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:opentxs.proto.CredentialSet.activeChildIDs)
}
#if LANG_CXX11
inline void CredentialSet::add_activechildids(::std::string&& value) {
  activechildids_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:opentxs.proto.CredentialSet.activeChildIDs)
}
#endif
inline void CredentialSet::add_activechildids(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  activechildids_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:opentxs.proto.CredentialSet.activeChildIDs)
}
inline void CredentialSet::add_activechildids(const char* value, size_t size) {
  activechildids_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:opentxs.proto.CredentialSet.activeChildIDs)
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
CredentialSet::activechildids() const {
  // @@protoc_insertion_point(field_list:opentxs.proto.CredentialSet.activeChildIDs)
  return activechildids_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
CredentialSet::mutable_activechildids() {
  // @@protoc_insertion_point(field_mutable_list:opentxs.proto.CredentialSet.activeChildIDs)
  return &activechildids_;
}

// repeated .opentxs.proto.Credential activeChildren = 8;
inline int CredentialSet::activechildren_size() const {
  return activechildren_.size();
}
inline const ::opentxs::proto::Credential& CredentialSet::activechildren(int index) const {
  // @@protoc_insertion_point(field_get:opentxs.proto.CredentialSet.activeChildren)
  return activechildren_.Get(index);
}
inline ::opentxs::proto::Credential* CredentialSet::mutable_activechildren(int index) {
  // @@protoc_insertion_point(field_mutable:opentxs.proto.CredentialSet.activeChildren)
  return activechildren_.Mutable(index);
}
inline ::opentxs::proto::Credential* CredentialSet::add_activechildren() {
  // @@protoc_insertion_point(field_add:opentxs.proto.CredentialSet.activeChildren)
  return activechildren_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::opentxs::proto::Credential >*
CredentialSet::mutable_activechildren() {
  // @@protoc_insertion_point(field_mutable_list:opentxs.proto.CredentialSet.activeChildren)
  return &activechildren_;
}
inline const ::google::protobuf::RepeatedPtrField< ::opentxs::proto::Credential >&
CredentialSet::activechildren() const {
  // @@protoc_insertion_point(field_list:opentxs.proto.CredentialSet.activeChildren)
  return activechildren_;
}

// repeated string revokedChildIDs = 9;
inline int CredentialSet::revokedchildids_size() const {
  return revokedchildids_.size();
}
inline void CredentialSet::clear_revokedchildids() {
  revokedchildids_.Clear();
}
inline const ::std::string& CredentialSet::revokedchildids(int index) const {
  // @@protoc_insertion_point(field_get:opentxs.proto.CredentialSet.revokedChildIDs)
  return revokedchildids_.Get(index);
}
inline ::std::string* CredentialSet::mutable_revokedchildids(int index) {
  // @@protoc_insertion_point(field_mutable:opentxs.proto.CredentialSet.revokedChildIDs)
  return revokedchildids_.Mutable(index);
}
inline void CredentialSet::set_revokedchildids(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:opentxs.proto.CredentialSet.revokedChildIDs)
  revokedchildids_.Mutable(index)->assign(value);
}
#if LANG_CXX11
inline void CredentialSet::set_revokedchildids(int index, ::std::string&& value) {
  // @@protoc_insertion_point(field_set:opentxs.proto.CredentialSet.revokedChildIDs)
  revokedchildids_.Mutable(index)->assign(std::move(value));
}
#endif
inline void CredentialSet::set_revokedchildids(int index, const char* value) {
  GOOGLE_DCHECK(value != NULL);
  revokedchildids_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:opentxs.proto.CredentialSet.revokedChildIDs)
}
inline void CredentialSet::set_revokedchildids(int index, const char* value, size_t size) {
  revokedchildids_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:opentxs.proto.CredentialSet.revokedChildIDs)
}
inline ::std::string* CredentialSet::add_revokedchildids() {
  // @@protoc_insertion_point(field_add_mutable:opentxs.proto.CredentialSet.revokedChildIDs)
  return revokedchildids_.Add();
}
inline void CredentialSet::add_revokedchildids(const ::std::string& value) {
  revokedchildids_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:opentxs.proto.CredentialSet.revokedChildIDs)
}
#if LANG_CXX11
inline void CredentialSet::add_revokedchildids(::std::string&& value) {
  revokedchildids_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:opentxs.proto.CredentialSet.revokedChildIDs)
}
#endif
inline void CredentialSet::add_revokedchildids(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  revokedchildids_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:opentxs.proto.CredentialSet.revokedChildIDs)
}
inline void CredentialSet::add_revokedchildids(const char* value, size_t size) {
  revokedchildids_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:opentxs.proto.CredentialSet.revokedChildIDs)
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
CredentialSet::revokedchildids() const {
  // @@protoc_insertion_point(field_list:opentxs.proto.CredentialSet.revokedChildIDs)
  return revokedchildids_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
CredentialSet::mutable_revokedchildids() {
  // @@protoc_insertion_point(field_mutable_list:opentxs.proto.CredentialSet.revokedChildIDs)
  return &revokedchildids_;
}

// repeated .opentxs.proto.Credential revokedChildren = 10;
inline int CredentialSet::revokedchildren_size() const {
  return revokedchildren_.size();
}
inline const ::opentxs::proto::Credential& CredentialSet::revokedchildren(int index) const {
  // @@protoc_insertion_point(field_get:opentxs.proto.CredentialSet.revokedChildren)
  return revokedchildren_.Get(index);
}
inline ::opentxs::proto::Credential* CredentialSet::mutable_revokedchildren(int index) {
  // @@protoc_insertion_point(field_mutable:opentxs.proto.CredentialSet.revokedChildren)
  return revokedchildren_.Mutable(index);
}
inline ::opentxs::proto::Credential* CredentialSet::add_revokedchildren() {
  // @@protoc_insertion_point(field_add:opentxs.proto.CredentialSet.revokedChildren)
  return revokedchildren_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::opentxs::proto::Credential >*
CredentialSet::mutable_revokedchildren() {
  // @@protoc_insertion_point(field_mutable_list:opentxs.proto.CredentialSet.revokedChildren)
  return &revokedchildren_;
}
inline const ::google::protobuf::RepeatedPtrField< ::opentxs::proto::Credential >&
CredentialSet::revokedchildren() const {
  // @@protoc_insertion_point(field_list:opentxs.proto.CredentialSet.revokedChildren)
  return revokedchildren_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace opentxs

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_CredentialSet_2eproto__INCLUDED
