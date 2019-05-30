// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ChildCredentialParameters.proto

#ifndef PROTOBUF_ChildCredentialParameters_2eproto__INCLUDED
#define PROTOBUF_ChildCredentialParameters_2eproto__INCLUDED

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
// @@protoc_insertion_point(includes)

namespace protobuf_ChildCredentialParameters_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void InitDefaultsChildCredentialParametersImpl();
void InitDefaultsChildCredentialParameters();
inline void InitDefaults() {
  InitDefaultsChildCredentialParameters();
}
}  // namespace protobuf_ChildCredentialParameters_2eproto
namespace opentxs {
namespace proto {
class ChildCredentialParameters;
class ChildCredentialParametersDefaultTypeInternal;
extern ChildCredentialParametersDefaultTypeInternal _ChildCredentialParameters_default_instance_;
}  // namespace proto
}  // namespace opentxs
namespace opentxs {
namespace proto {

// ===================================================================

class ChildCredentialParameters : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:opentxs.proto.ChildCredentialParameters) */ {
 public:
  ChildCredentialParameters();
  virtual ~ChildCredentialParameters();

  ChildCredentialParameters(const ChildCredentialParameters& from);

  inline ChildCredentialParameters& operator=(const ChildCredentialParameters& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ChildCredentialParameters(ChildCredentialParameters&& from) noexcept
    : ChildCredentialParameters() {
    *this = ::std::move(from);
  }

  inline ChildCredentialParameters& operator=(ChildCredentialParameters&& from) noexcept {
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

  static const ChildCredentialParameters& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ChildCredentialParameters* internal_default_instance() {
    return reinterpret_cast<const ChildCredentialParameters*>(
               &_ChildCredentialParameters_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(ChildCredentialParameters* other);
  friend void swap(ChildCredentialParameters& a, ChildCredentialParameters& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ChildCredentialParameters* New() const PROTOBUF_FINAL { return New(NULL); }

  ChildCredentialParameters* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from)
    PROTOBUF_FINAL;
  void CopyFrom(const ChildCredentialParameters& from);
  void MergeFrom(const ChildCredentialParameters& from);
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
  void InternalSwap(ChildCredentialParameters* other);
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

  // optional string masterID = 2;
  bool has_masterid() const;
  void clear_masterid();
  static const int kMasterIDFieldNumber = 2;
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

  // optional uint32 version = 1;
  bool has_version() const;
  void clear_version();
  static const int kVersionFieldNumber = 1;
  ::google::protobuf::uint32 version() const;
  void set_version(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:opentxs.proto.ChildCredentialParameters)
 private:
  void set_has_version();
  void clear_has_version();
  void set_has_masterid();
  void clear_has_masterid();

  ::google::protobuf::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr masterid_;
  ::google::protobuf::uint32 version_;
  friend struct ::protobuf_ChildCredentialParameters_2eproto::TableStruct;
  friend void ::protobuf_ChildCredentialParameters_2eproto::InitDefaultsChildCredentialParametersImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ChildCredentialParameters

// optional uint32 version = 1;
inline bool ChildCredentialParameters::has_version() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ChildCredentialParameters::set_has_version() {
  _has_bits_[0] |= 0x00000002u;
}
inline void ChildCredentialParameters::clear_has_version() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void ChildCredentialParameters::clear_version() {
  version_ = 0u;
  clear_has_version();
}
inline ::google::protobuf::uint32 ChildCredentialParameters::version() const {
  // @@protoc_insertion_point(field_get:opentxs.proto.ChildCredentialParameters.version)
  return version_;
}
inline void ChildCredentialParameters::set_version(::google::protobuf::uint32 value) {
  set_has_version();
  version_ = value;
  // @@protoc_insertion_point(field_set:opentxs.proto.ChildCredentialParameters.version)
}

// optional string masterID = 2;
inline bool ChildCredentialParameters::has_masterid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ChildCredentialParameters::set_has_masterid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ChildCredentialParameters::clear_has_masterid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ChildCredentialParameters::clear_masterid() {
  masterid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_masterid();
}
inline const ::std::string& ChildCredentialParameters::masterid() const {
  // @@protoc_insertion_point(field_get:opentxs.proto.ChildCredentialParameters.masterID)
  return masterid_.GetNoArena();
}
inline void ChildCredentialParameters::set_masterid(const ::std::string& value) {
  set_has_masterid();
  masterid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:opentxs.proto.ChildCredentialParameters.masterID)
}
#if LANG_CXX11
inline void ChildCredentialParameters::set_masterid(::std::string&& value) {
  set_has_masterid();
  masterid_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:opentxs.proto.ChildCredentialParameters.masterID)
}
#endif
inline void ChildCredentialParameters::set_masterid(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_masterid();
  masterid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:opentxs.proto.ChildCredentialParameters.masterID)
}
inline void ChildCredentialParameters::set_masterid(const char* value, size_t size) {
  set_has_masterid();
  masterid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:opentxs.proto.ChildCredentialParameters.masterID)
}
inline ::std::string* ChildCredentialParameters::mutable_masterid() {
  set_has_masterid();
  // @@protoc_insertion_point(field_mutable:opentxs.proto.ChildCredentialParameters.masterID)
  return masterid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ChildCredentialParameters::release_masterid() {
  // @@protoc_insertion_point(field_release:opentxs.proto.ChildCredentialParameters.masterID)
  clear_has_masterid();
  return masterid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ChildCredentialParameters::set_allocated_masterid(::std::string* masterid) {
  if (masterid != NULL) {
    set_has_masterid();
  } else {
    clear_has_masterid();
  }
  masterid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), masterid);
  // @@protoc_insertion_point(field_set_allocated:opentxs.proto.ChildCredentialParameters.masterID)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace opentxs

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_ChildCredentialParameters_2eproto__INCLUDED
