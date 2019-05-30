// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Envelope.proto

#ifndef PROTOBUF_Envelope_2eproto__INCLUDED
#define PROTOBUF_Envelope_2eproto__INCLUDED

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
#include "AsymmetricKey.pb.h"
#include "Ciphertext.pb.h"
#include "SymmetricKey.pb.h"
// @@protoc_insertion_point(includes)

namespace protobuf_Envelope_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void InitDefaultsEnvelopeImpl();
void InitDefaultsEnvelope();
inline void InitDefaults() {
  InitDefaultsEnvelope();
}
}  // namespace protobuf_Envelope_2eproto
namespace opentxs {
namespace proto {
class Envelope;
class EnvelopeDefaultTypeInternal;
extern EnvelopeDefaultTypeInternal _Envelope_default_instance_;
}  // namespace proto
}  // namespace opentxs
namespace opentxs {
namespace proto {

// ===================================================================

class Envelope : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:opentxs.proto.Envelope) */ {
 public:
  Envelope();
  virtual ~Envelope();

  Envelope(const Envelope& from);

  inline Envelope& operator=(const Envelope& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Envelope(Envelope&& from) noexcept
    : Envelope() {
    *this = ::std::move(from);
  }

  inline Envelope& operator=(Envelope&& from) noexcept {
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

  static const Envelope& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Envelope* internal_default_instance() {
    return reinterpret_cast<const Envelope*>(
               &_Envelope_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(Envelope* other);
  friend void swap(Envelope& a, Envelope& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Envelope* New() const PROTOBUF_FINAL { return New(NULL); }

  Envelope* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from)
    PROTOBUF_FINAL;
  void CopyFrom(const Envelope& from);
  void MergeFrom(const Envelope& from);
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
  void InternalSwap(Envelope* other);
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

  // repeated .opentxs.proto.AsymmetricKey dhkey = 2;
  int dhkey_size() const;
  void clear_dhkey();
  static const int kDhkeyFieldNumber = 2;
  const ::opentxs::proto::AsymmetricKey& dhkey(int index) const;
  ::opentxs::proto::AsymmetricKey* mutable_dhkey(int index);
  ::opentxs::proto::AsymmetricKey* add_dhkey();
  ::google::protobuf::RepeatedPtrField< ::opentxs::proto::AsymmetricKey >*
      mutable_dhkey();
  const ::google::protobuf::RepeatedPtrField< ::opentxs::proto::AsymmetricKey >&
      dhkey() const;

  // repeated .opentxs.proto.SymmetricKey sessionkey = 4;
  int sessionkey_size() const;
  void clear_sessionkey();
  static const int kSessionkeyFieldNumber = 4;
  const ::opentxs::proto::SymmetricKey& sessionkey(int index) const;
  ::opentxs::proto::SymmetricKey* mutable_sessionkey(int index);
  ::opentxs::proto::SymmetricKey* add_sessionkey();
  ::google::protobuf::RepeatedPtrField< ::opentxs::proto::SymmetricKey >*
      mutable_sessionkey();
  const ::google::protobuf::RepeatedPtrField< ::opentxs::proto::SymmetricKey >&
      sessionkey() const;

  // optional bytes rsakey = 3;
  bool has_rsakey() const;
  void clear_rsakey();
  static const int kRsakeyFieldNumber = 3;
  const ::std::string& rsakey() const;
  void set_rsakey(const ::std::string& value);
  #if LANG_CXX11
  void set_rsakey(::std::string&& value);
  #endif
  void set_rsakey(const char* value);
  void set_rsakey(const void* value, size_t size);
  ::std::string* mutable_rsakey();
  ::std::string* release_rsakey();
  void set_allocated_rsakey(::std::string* rsakey);

  // optional .opentxs.proto.Ciphertext ciphertext = 5;
  bool has_ciphertext() const;
  void clear_ciphertext();
  static const int kCiphertextFieldNumber = 5;
  const ::opentxs::proto::Ciphertext& ciphertext() const;
  ::opentxs::proto::Ciphertext* release_ciphertext();
  ::opentxs::proto::Ciphertext* mutable_ciphertext();
  void set_allocated_ciphertext(::opentxs::proto::Ciphertext* ciphertext);

  // optional uint32 version = 1;
  bool has_version() const;
  void clear_version();
  static const int kVersionFieldNumber = 1;
  ::google::protobuf::uint32 version() const;
  void set_version(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:opentxs.proto.Envelope)
 private:
  void set_has_version();
  void clear_has_version();
  void set_has_rsakey();
  void clear_has_rsakey();
  void set_has_ciphertext();
  void clear_has_ciphertext();

  ::google::protobuf::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::opentxs::proto::AsymmetricKey > dhkey_;
  ::google::protobuf::RepeatedPtrField< ::opentxs::proto::SymmetricKey > sessionkey_;
  ::google::protobuf::internal::ArenaStringPtr rsakey_;
  ::opentxs::proto::Ciphertext* ciphertext_;
  ::google::protobuf::uint32 version_;
  friend struct ::protobuf_Envelope_2eproto::TableStruct;
  friend void ::protobuf_Envelope_2eproto::InitDefaultsEnvelopeImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Envelope

// optional uint32 version = 1;
inline bool Envelope::has_version() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Envelope::set_has_version() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Envelope::clear_has_version() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Envelope::clear_version() {
  version_ = 0u;
  clear_has_version();
}
inline ::google::protobuf::uint32 Envelope::version() const {
  // @@protoc_insertion_point(field_get:opentxs.proto.Envelope.version)
  return version_;
}
inline void Envelope::set_version(::google::protobuf::uint32 value) {
  set_has_version();
  version_ = value;
  // @@protoc_insertion_point(field_set:opentxs.proto.Envelope.version)
}

// repeated .opentxs.proto.AsymmetricKey dhkey = 2;
inline int Envelope::dhkey_size() const {
  return dhkey_.size();
}
inline const ::opentxs::proto::AsymmetricKey& Envelope::dhkey(int index) const {
  // @@protoc_insertion_point(field_get:opentxs.proto.Envelope.dhkey)
  return dhkey_.Get(index);
}
inline ::opentxs::proto::AsymmetricKey* Envelope::mutable_dhkey(int index) {
  // @@protoc_insertion_point(field_mutable:opentxs.proto.Envelope.dhkey)
  return dhkey_.Mutable(index);
}
inline ::opentxs::proto::AsymmetricKey* Envelope::add_dhkey() {
  // @@protoc_insertion_point(field_add:opentxs.proto.Envelope.dhkey)
  return dhkey_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::opentxs::proto::AsymmetricKey >*
Envelope::mutable_dhkey() {
  // @@protoc_insertion_point(field_mutable_list:opentxs.proto.Envelope.dhkey)
  return &dhkey_;
}
inline const ::google::protobuf::RepeatedPtrField< ::opentxs::proto::AsymmetricKey >&
Envelope::dhkey() const {
  // @@protoc_insertion_point(field_list:opentxs.proto.Envelope.dhkey)
  return dhkey_;
}

// optional bytes rsakey = 3;
inline bool Envelope::has_rsakey() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Envelope::set_has_rsakey() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Envelope::clear_has_rsakey() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Envelope::clear_rsakey() {
  rsakey_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_rsakey();
}
inline const ::std::string& Envelope::rsakey() const {
  // @@protoc_insertion_point(field_get:opentxs.proto.Envelope.rsakey)
  return rsakey_.GetNoArena();
}
inline void Envelope::set_rsakey(const ::std::string& value) {
  set_has_rsakey();
  rsakey_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:opentxs.proto.Envelope.rsakey)
}
#if LANG_CXX11
inline void Envelope::set_rsakey(::std::string&& value) {
  set_has_rsakey();
  rsakey_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:opentxs.proto.Envelope.rsakey)
}
#endif
inline void Envelope::set_rsakey(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_rsakey();
  rsakey_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:opentxs.proto.Envelope.rsakey)
}
inline void Envelope::set_rsakey(const void* value, size_t size) {
  set_has_rsakey();
  rsakey_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:opentxs.proto.Envelope.rsakey)
}
inline ::std::string* Envelope::mutable_rsakey() {
  set_has_rsakey();
  // @@protoc_insertion_point(field_mutable:opentxs.proto.Envelope.rsakey)
  return rsakey_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Envelope::release_rsakey() {
  // @@protoc_insertion_point(field_release:opentxs.proto.Envelope.rsakey)
  clear_has_rsakey();
  return rsakey_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Envelope::set_allocated_rsakey(::std::string* rsakey) {
  if (rsakey != NULL) {
    set_has_rsakey();
  } else {
    clear_has_rsakey();
  }
  rsakey_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), rsakey);
  // @@protoc_insertion_point(field_set_allocated:opentxs.proto.Envelope.rsakey)
}

// repeated .opentxs.proto.SymmetricKey sessionkey = 4;
inline int Envelope::sessionkey_size() const {
  return sessionkey_.size();
}
inline const ::opentxs::proto::SymmetricKey& Envelope::sessionkey(int index) const {
  // @@protoc_insertion_point(field_get:opentxs.proto.Envelope.sessionkey)
  return sessionkey_.Get(index);
}
inline ::opentxs::proto::SymmetricKey* Envelope::mutable_sessionkey(int index) {
  // @@protoc_insertion_point(field_mutable:opentxs.proto.Envelope.sessionkey)
  return sessionkey_.Mutable(index);
}
inline ::opentxs::proto::SymmetricKey* Envelope::add_sessionkey() {
  // @@protoc_insertion_point(field_add:opentxs.proto.Envelope.sessionkey)
  return sessionkey_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::opentxs::proto::SymmetricKey >*
Envelope::mutable_sessionkey() {
  // @@protoc_insertion_point(field_mutable_list:opentxs.proto.Envelope.sessionkey)
  return &sessionkey_;
}
inline const ::google::protobuf::RepeatedPtrField< ::opentxs::proto::SymmetricKey >&
Envelope::sessionkey() const {
  // @@protoc_insertion_point(field_list:opentxs.proto.Envelope.sessionkey)
  return sessionkey_;
}

// optional .opentxs.proto.Ciphertext ciphertext = 5;
inline bool Envelope::has_ciphertext() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Envelope::set_has_ciphertext() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Envelope::clear_has_ciphertext() {
  _has_bits_[0] &= ~0x00000002u;
}
inline const ::opentxs::proto::Ciphertext& Envelope::ciphertext() const {
  const ::opentxs::proto::Ciphertext* p = ciphertext_;
  // @@protoc_insertion_point(field_get:opentxs.proto.Envelope.ciphertext)
  return p != NULL ? *p : *reinterpret_cast<const ::opentxs::proto::Ciphertext*>(
      &::opentxs::proto::_Ciphertext_default_instance_);
}
inline ::opentxs::proto::Ciphertext* Envelope::release_ciphertext() {
  // @@protoc_insertion_point(field_release:opentxs.proto.Envelope.ciphertext)
  clear_has_ciphertext();
  ::opentxs::proto::Ciphertext* temp = ciphertext_;
  ciphertext_ = NULL;
  return temp;
}
inline ::opentxs::proto::Ciphertext* Envelope::mutable_ciphertext() {
  set_has_ciphertext();
  if (ciphertext_ == NULL) {
    ciphertext_ = new ::opentxs::proto::Ciphertext;
  }
  // @@protoc_insertion_point(field_mutable:opentxs.proto.Envelope.ciphertext)
  return ciphertext_;
}
inline void Envelope::set_allocated_ciphertext(::opentxs::proto::Ciphertext* ciphertext) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete reinterpret_cast< ::google::protobuf::MessageLite*>(ciphertext_);
  }
  if (ciphertext) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      ciphertext = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, ciphertext, submessage_arena);
    }
    set_has_ciphertext();
  } else {
    clear_has_ciphertext();
  }
  ciphertext_ = ciphertext;
  // @@protoc_insertion_point(field_set_allocated:opentxs.proto.Envelope.ciphertext)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace opentxs

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_Envelope_2eproto__INCLUDED
