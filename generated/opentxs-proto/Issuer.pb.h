// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Issuer.proto

#ifndef PROTOBUF_Issuer_2eproto__INCLUDED
#define PROTOBUF_Issuer_2eproto__INCLUDED

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
#include "PeerRequestHistory.pb.h"  // IWYU pragma: export
#include "UnitAccountMap.pb.h"  // IWYU pragma: export
// @@protoc_insertion_point(includes)

namespace protobuf_Issuer_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void InitDefaultsIssuerImpl();
void InitDefaultsIssuer();
inline void InitDefaults() {
  InitDefaultsIssuer();
}
}  // namespace protobuf_Issuer_2eproto
namespace opentxs {
namespace proto {
class Issuer;
class IssuerDefaultTypeInternal;
extern IssuerDefaultTypeInternal _Issuer_default_instance_;
}  // namespace proto
}  // namespace opentxs
namespace opentxs {
namespace proto {

// ===================================================================

class Issuer : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:opentxs.proto.Issuer) */ {
 public:
  Issuer();
  virtual ~Issuer();

  Issuer(const Issuer& from);

  inline Issuer& operator=(const Issuer& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Issuer(Issuer&& from) noexcept
    : Issuer() {
    *this = ::std::move(from);
  }

  inline Issuer& operator=(Issuer&& from) noexcept {
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

  static const Issuer& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Issuer* internal_default_instance() {
    return reinterpret_cast<const Issuer*>(
               &_Issuer_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(Issuer* other);
  friend void swap(Issuer& a, Issuer& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Issuer* New() const PROTOBUF_FINAL { return New(NULL); }

  Issuer* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from)
    PROTOBUF_FINAL;
  void CopyFrom(const Issuer& from);
  void MergeFrom(const Issuer& from);
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
  void InternalSwap(Issuer* other);
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

  // repeated .opentxs.proto.UnitAccountMap accounts = 5;
  int accounts_size() const;
  void clear_accounts();
  static const int kAccountsFieldNumber = 5;
  const ::opentxs::proto::UnitAccountMap& accounts(int index) const;
  ::opentxs::proto::UnitAccountMap* mutable_accounts(int index);
  ::opentxs::proto::UnitAccountMap* add_accounts();
  ::google::protobuf::RepeatedPtrField< ::opentxs::proto::UnitAccountMap >*
      mutable_accounts();
  const ::google::protobuf::RepeatedPtrField< ::opentxs::proto::UnitAccountMap >&
      accounts() const;

  // repeated .opentxs.proto.PeerRequestHistory peerrequests = 6;
  int peerrequests_size() const;
  void clear_peerrequests();
  static const int kPeerrequestsFieldNumber = 6;
  const ::opentxs::proto::PeerRequestHistory& peerrequests(int index) const;
  ::opentxs::proto::PeerRequestHistory* mutable_peerrequests(int index);
  ::opentxs::proto::PeerRequestHistory* add_peerrequests();
  ::google::protobuf::RepeatedPtrField< ::opentxs::proto::PeerRequestHistory >*
      mutable_peerrequests();
  const ::google::protobuf::RepeatedPtrField< ::opentxs::proto::PeerRequestHistory >&
      peerrequests() const;

  // optional string id = 2;
  bool has_id() const;
  void clear_id();
  static const int kIdFieldNumber = 2;
  const ::std::string& id() const;
  void set_id(const ::std::string& value);
  #if LANG_CXX11
  void set_id(::std::string&& value);
  #endif
  void set_id(const char* value);
  void set_id(const char* value, size_t size);
  ::std::string* mutable_id();
  ::std::string* release_id();
  void set_allocated_id(::std::string* id);

  // optional string pairingcode = 4;
  bool has_pairingcode() const;
  void clear_pairingcode();
  static const int kPairingcodeFieldNumber = 4;
  const ::std::string& pairingcode() const;
  void set_pairingcode(const ::std::string& value);
  #if LANG_CXX11
  void set_pairingcode(::std::string&& value);
  #endif
  void set_pairingcode(const char* value);
  void set_pairingcode(const char* value, size_t size);
  ::std::string* mutable_pairingcode();
  ::std::string* release_pairingcode();
  void set_allocated_pairingcode(::std::string* pairingcode);

  // optional uint32 version = 1;
  bool has_version() const;
  void clear_version();
  static const int kVersionFieldNumber = 1;
  ::google::protobuf::uint32 version() const;
  void set_version(::google::protobuf::uint32 value);

  // optional bool paired = 3;
  bool has_paired() const;
  void clear_paired();
  static const int kPairedFieldNumber = 3;
  bool paired() const;
  void set_paired(bool value);

  // @@protoc_insertion_point(class_scope:opentxs.proto.Issuer)
 private:
  void set_has_version();
  void clear_has_version();
  void set_has_id();
  void clear_has_id();
  void set_has_paired();
  void clear_has_paired();
  void set_has_pairingcode();
  void clear_has_pairingcode();

  ::google::protobuf::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::opentxs::proto::UnitAccountMap > accounts_;
  ::google::protobuf::RepeatedPtrField< ::opentxs::proto::PeerRequestHistory > peerrequests_;
  ::google::protobuf::internal::ArenaStringPtr id_;
  ::google::protobuf::internal::ArenaStringPtr pairingcode_;
  ::google::protobuf::uint32 version_;
  bool paired_;
  friend struct ::protobuf_Issuer_2eproto::TableStruct;
  friend void ::protobuf_Issuer_2eproto::InitDefaultsIssuerImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Issuer

// optional uint32 version = 1;
inline bool Issuer::has_version() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Issuer::set_has_version() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Issuer::clear_has_version() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Issuer::clear_version() {
  version_ = 0u;
  clear_has_version();
}
inline ::google::protobuf::uint32 Issuer::version() const {
  // @@protoc_insertion_point(field_get:opentxs.proto.Issuer.version)
  return version_;
}
inline void Issuer::set_version(::google::protobuf::uint32 value) {
  set_has_version();
  version_ = value;
  // @@protoc_insertion_point(field_set:opentxs.proto.Issuer.version)
}

// optional string id = 2;
inline bool Issuer::has_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Issuer::set_has_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Issuer::clear_has_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Issuer::clear_id() {
  id_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_id();
}
inline const ::std::string& Issuer::id() const {
  // @@protoc_insertion_point(field_get:opentxs.proto.Issuer.id)
  return id_.GetNoArena();
}
inline void Issuer::set_id(const ::std::string& value) {
  set_has_id();
  id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:opentxs.proto.Issuer.id)
}
#if LANG_CXX11
inline void Issuer::set_id(::std::string&& value) {
  set_has_id();
  id_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:opentxs.proto.Issuer.id)
}
#endif
inline void Issuer::set_id(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_id();
  id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:opentxs.proto.Issuer.id)
}
inline void Issuer::set_id(const char* value, size_t size) {
  set_has_id();
  id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:opentxs.proto.Issuer.id)
}
inline ::std::string* Issuer::mutable_id() {
  set_has_id();
  // @@protoc_insertion_point(field_mutable:opentxs.proto.Issuer.id)
  return id_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Issuer::release_id() {
  // @@protoc_insertion_point(field_release:opentxs.proto.Issuer.id)
  clear_has_id();
  return id_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Issuer::set_allocated_id(::std::string* id) {
  if (id != NULL) {
    set_has_id();
  } else {
    clear_has_id();
  }
  id_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), id);
  // @@protoc_insertion_point(field_set_allocated:opentxs.proto.Issuer.id)
}

// optional bool paired = 3;
inline bool Issuer::has_paired() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Issuer::set_has_paired() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Issuer::clear_has_paired() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Issuer::clear_paired() {
  paired_ = false;
  clear_has_paired();
}
inline bool Issuer::paired() const {
  // @@protoc_insertion_point(field_get:opentxs.proto.Issuer.paired)
  return paired_;
}
inline void Issuer::set_paired(bool value) {
  set_has_paired();
  paired_ = value;
  // @@protoc_insertion_point(field_set:opentxs.proto.Issuer.paired)
}

// optional string pairingcode = 4;
inline bool Issuer::has_pairingcode() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Issuer::set_has_pairingcode() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Issuer::clear_has_pairingcode() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Issuer::clear_pairingcode() {
  pairingcode_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_pairingcode();
}
inline const ::std::string& Issuer::pairingcode() const {
  // @@protoc_insertion_point(field_get:opentxs.proto.Issuer.pairingcode)
  return pairingcode_.GetNoArena();
}
inline void Issuer::set_pairingcode(const ::std::string& value) {
  set_has_pairingcode();
  pairingcode_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:opentxs.proto.Issuer.pairingcode)
}
#if LANG_CXX11
inline void Issuer::set_pairingcode(::std::string&& value) {
  set_has_pairingcode();
  pairingcode_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:opentxs.proto.Issuer.pairingcode)
}
#endif
inline void Issuer::set_pairingcode(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_pairingcode();
  pairingcode_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:opentxs.proto.Issuer.pairingcode)
}
inline void Issuer::set_pairingcode(const char* value, size_t size) {
  set_has_pairingcode();
  pairingcode_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:opentxs.proto.Issuer.pairingcode)
}
inline ::std::string* Issuer::mutable_pairingcode() {
  set_has_pairingcode();
  // @@protoc_insertion_point(field_mutable:opentxs.proto.Issuer.pairingcode)
  return pairingcode_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Issuer::release_pairingcode() {
  // @@protoc_insertion_point(field_release:opentxs.proto.Issuer.pairingcode)
  clear_has_pairingcode();
  return pairingcode_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Issuer::set_allocated_pairingcode(::std::string* pairingcode) {
  if (pairingcode != NULL) {
    set_has_pairingcode();
  } else {
    clear_has_pairingcode();
  }
  pairingcode_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), pairingcode);
  // @@protoc_insertion_point(field_set_allocated:opentxs.proto.Issuer.pairingcode)
}

// repeated .opentxs.proto.UnitAccountMap accounts = 5;
inline int Issuer::accounts_size() const {
  return accounts_.size();
}
inline const ::opentxs::proto::UnitAccountMap& Issuer::accounts(int index) const {
  // @@protoc_insertion_point(field_get:opentxs.proto.Issuer.accounts)
  return accounts_.Get(index);
}
inline ::opentxs::proto::UnitAccountMap* Issuer::mutable_accounts(int index) {
  // @@protoc_insertion_point(field_mutable:opentxs.proto.Issuer.accounts)
  return accounts_.Mutable(index);
}
inline ::opentxs::proto::UnitAccountMap* Issuer::add_accounts() {
  // @@protoc_insertion_point(field_add:opentxs.proto.Issuer.accounts)
  return accounts_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::opentxs::proto::UnitAccountMap >*
Issuer::mutable_accounts() {
  // @@protoc_insertion_point(field_mutable_list:opentxs.proto.Issuer.accounts)
  return &accounts_;
}
inline const ::google::protobuf::RepeatedPtrField< ::opentxs::proto::UnitAccountMap >&
Issuer::accounts() const {
  // @@protoc_insertion_point(field_list:opentxs.proto.Issuer.accounts)
  return accounts_;
}

// repeated .opentxs.proto.PeerRequestHistory peerrequests = 6;
inline int Issuer::peerrequests_size() const {
  return peerrequests_.size();
}
inline const ::opentxs::proto::PeerRequestHistory& Issuer::peerrequests(int index) const {
  // @@protoc_insertion_point(field_get:opentxs.proto.Issuer.peerrequests)
  return peerrequests_.Get(index);
}
inline ::opentxs::proto::PeerRequestHistory* Issuer::mutable_peerrequests(int index) {
  // @@protoc_insertion_point(field_mutable:opentxs.proto.Issuer.peerrequests)
  return peerrequests_.Mutable(index);
}
inline ::opentxs::proto::PeerRequestHistory* Issuer::add_peerrequests() {
  // @@protoc_insertion_point(field_add:opentxs.proto.Issuer.peerrequests)
  return peerrequests_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::opentxs::proto::PeerRequestHistory >*
Issuer::mutable_peerrequests() {
  // @@protoc_insertion_point(field_mutable_list:opentxs.proto.Issuer.peerrequests)
  return &peerrequests_;
}
inline const ::google::protobuf::RepeatedPtrField< ::opentxs::proto::PeerRequestHistory >&
Issuer::peerrequests() const {
  // @@protoc_insertion_point(field_list:opentxs.proto.Issuer.peerrequests)
  return peerrequests_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace opentxs

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_Issuer_2eproto__INCLUDED