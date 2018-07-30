// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: PaymentEvent.proto

#ifndef PROTOBUF_PaymentEvent_2eproto__INCLUDED
#define PROTOBUF_PaymentEvent_2eproto__INCLUDED

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
#include "PaymentWorkflowEnums.pb.h"  // IWYU pragma: export
// @@protoc_insertion_point(includes)

namespace protobuf_PaymentEvent_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void InitDefaultsPaymentEventImpl();
void InitDefaultsPaymentEvent();
inline void InitDefaults() {
  InitDefaultsPaymentEvent();
}
}  // namespace protobuf_PaymentEvent_2eproto
namespace opentxs {
namespace proto {
class PaymentEvent;
class PaymentEventDefaultTypeInternal;
extern PaymentEventDefaultTypeInternal _PaymentEvent_default_instance_;
}  // namespace proto
}  // namespace opentxs
namespace opentxs {
namespace proto {

// ===================================================================

class PaymentEvent : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:opentxs.proto.PaymentEvent) */ {
 public:
  PaymentEvent();
  virtual ~PaymentEvent();

  PaymentEvent(const PaymentEvent& from);

  inline PaymentEvent& operator=(const PaymentEvent& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  PaymentEvent(PaymentEvent&& from) noexcept
    : PaymentEvent() {
    *this = ::std::move(from);
  }

  inline PaymentEvent& operator=(PaymentEvent&& from) noexcept {
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

  static const PaymentEvent& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const PaymentEvent* internal_default_instance() {
    return reinterpret_cast<const PaymentEvent*>(
               &_PaymentEvent_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(PaymentEvent* other);
  friend void swap(PaymentEvent& a, PaymentEvent& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline PaymentEvent* New() const PROTOBUF_FINAL { return New(NULL); }

  PaymentEvent* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from)
    PROTOBUF_FINAL;
  void CopyFrom(const PaymentEvent& from);
  void MergeFrom(const PaymentEvent& from);
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
  void InternalSwap(PaymentEvent* other);
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

  // repeated string item = 3;
  int item_size() const;
  void clear_item();
  static const int kItemFieldNumber = 3;
  const ::std::string& item(int index) const;
  ::std::string* mutable_item(int index);
  void set_item(int index, const ::std::string& value);
  #if LANG_CXX11
  void set_item(int index, ::std::string&& value);
  #endif
  void set_item(int index, const char* value);
  void set_item(int index, const char* value, size_t size);
  ::std::string* add_item();
  void add_item(const ::std::string& value);
  #if LANG_CXX11
  void add_item(::std::string&& value);
  #endif
  void add_item(const char* value);
  void add_item(const char* value, size_t size);
  const ::google::protobuf::RepeatedPtrField< ::std::string>& item() const;
  ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_item();

  // optional string transport = 6;
  bool has_transport() const;
  void clear_transport();
  static const int kTransportFieldNumber = 6;
  const ::std::string& transport() const;
  void set_transport(const ::std::string& value);
  #if LANG_CXX11
  void set_transport(::std::string&& value);
  #endif
  void set_transport(const char* value);
  void set_transport(const char* value, size_t size);
  ::std::string* mutable_transport();
  ::std::string* release_transport();
  void set_allocated_transport(::std::string* transport);

  // optional string nym = 7;
  bool has_nym() const;
  void clear_nym();
  static const int kNymFieldNumber = 7;
  const ::std::string& nym() const;
  void set_nym(const ::std::string& value);
  #if LANG_CXX11
  void set_nym(::std::string&& value);
  #endif
  void set_nym(const char* value);
  void set_nym(const char* value, size_t size);
  ::std::string* mutable_nym();
  ::std::string* release_nym();
  void set_allocated_nym(::std::string* nym);

  // optional string memo = 9;
  bool has_memo() const;
  void clear_memo();
  static const int kMemoFieldNumber = 9;
  const ::std::string& memo() const;
  void set_memo(const ::std::string& value);
  #if LANG_CXX11
  void set_memo(::std::string&& value);
  #endif
  void set_memo(const char* value);
  void set_memo(const char* value, size_t size);
  ::std::string* mutable_memo();
  ::std::string* release_memo();
  void set_allocated_memo(::std::string* memo);

  // optional uint32 version = 1;
  bool has_version() const;
  void clear_version();
  static const int kVersionFieldNumber = 1;
  ::google::protobuf::uint32 version() const;
  void set_version(::google::protobuf::uint32 value);

  // optional .opentxs.proto.PaymentEventType type = 2;
  bool has_type() const;
  void clear_type();
  static const int kTypeFieldNumber = 2;
  ::opentxs::proto::PaymentEventType type() const;
  void set_type(::opentxs::proto::PaymentEventType value);

  // optional int64 time = 4;
  bool has_time() const;
  void clear_time();
  static const int kTimeFieldNumber = 4;
  ::google::protobuf::int64 time() const;
  void set_time(::google::protobuf::int64 value);

  // optional .opentxs.proto.EventTransportMethod method = 5;
  bool has_method() const;
  void clear_method();
  static const int kMethodFieldNumber = 5;
  ::opentxs::proto::EventTransportMethod method() const;
  void set_method(::opentxs::proto::EventTransportMethod value);

  // optional bool success = 8;
  bool has_success() const;
  void clear_success();
  static const int kSuccessFieldNumber = 8;
  bool success() const;
  void set_success(bool value);

  // @@protoc_insertion_point(class_scope:opentxs.proto.PaymentEvent)
 private:
  void set_has_version();
  void clear_has_version();
  void set_has_type();
  void clear_has_type();
  void set_has_time();
  void clear_has_time();
  void set_has_method();
  void clear_has_method();
  void set_has_transport();
  void clear_has_transport();
  void set_has_nym();
  void clear_has_nym();
  void set_has_success();
  void clear_has_success();
  void set_has_memo();
  void clear_has_memo();

  ::google::protobuf::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::std::string> item_;
  ::google::protobuf::internal::ArenaStringPtr transport_;
  ::google::protobuf::internal::ArenaStringPtr nym_;
  ::google::protobuf::internal::ArenaStringPtr memo_;
  ::google::protobuf::uint32 version_;
  int type_;
  ::google::protobuf::int64 time_;
  int method_;
  bool success_;
  friend struct ::protobuf_PaymentEvent_2eproto::TableStruct;
  friend void ::protobuf_PaymentEvent_2eproto::InitDefaultsPaymentEventImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// PaymentEvent

// optional uint32 version = 1;
inline bool PaymentEvent::has_version() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void PaymentEvent::set_has_version() {
  _has_bits_[0] |= 0x00000008u;
}
inline void PaymentEvent::clear_has_version() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void PaymentEvent::clear_version() {
  version_ = 0u;
  clear_has_version();
}
inline ::google::protobuf::uint32 PaymentEvent::version() const {
  // @@protoc_insertion_point(field_get:opentxs.proto.PaymentEvent.version)
  return version_;
}
inline void PaymentEvent::set_version(::google::protobuf::uint32 value) {
  set_has_version();
  version_ = value;
  // @@protoc_insertion_point(field_set:opentxs.proto.PaymentEvent.version)
}

// optional .opentxs.proto.PaymentEventType type = 2;
inline bool PaymentEvent::has_type() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void PaymentEvent::set_has_type() {
  _has_bits_[0] |= 0x00000010u;
}
inline void PaymentEvent::clear_has_type() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void PaymentEvent::clear_type() {
  type_ = 0;
  clear_has_type();
}
inline ::opentxs::proto::PaymentEventType PaymentEvent::type() const {
  // @@protoc_insertion_point(field_get:opentxs.proto.PaymentEvent.type)
  return static_cast< ::opentxs::proto::PaymentEventType >(type_);
}
inline void PaymentEvent::set_type(::opentxs::proto::PaymentEventType value) {
  assert(::opentxs::proto::PaymentEventType_IsValid(value));
  set_has_type();
  type_ = value;
  // @@protoc_insertion_point(field_set:opentxs.proto.PaymentEvent.type)
}

// repeated string item = 3;
inline int PaymentEvent::item_size() const {
  return item_.size();
}
inline void PaymentEvent::clear_item() {
  item_.Clear();
}
inline const ::std::string& PaymentEvent::item(int index) const {
  // @@protoc_insertion_point(field_get:opentxs.proto.PaymentEvent.item)
  return item_.Get(index);
}
inline ::std::string* PaymentEvent::mutable_item(int index) {
  // @@protoc_insertion_point(field_mutable:opentxs.proto.PaymentEvent.item)
  return item_.Mutable(index);
}
inline void PaymentEvent::set_item(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:opentxs.proto.PaymentEvent.item)
  item_.Mutable(index)->assign(value);
}
#if LANG_CXX11
inline void PaymentEvent::set_item(int index, ::std::string&& value) {
  // @@protoc_insertion_point(field_set:opentxs.proto.PaymentEvent.item)
  item_.Mutable(index)->assign(std::move(value));
}
#endif
inline void PaymentEvent::set_item(int index, const char* value) {
  GOOGLE_DCHECK(value != NULL);
  item_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:opentxs.proto.PaymentEvent.item)
}
inline void PaymentEvent::set_item(int index, const char* value, size_t size) {
  item_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:opentxs.proto.PaymentEvent.item)
}
inline ::std::string* PaymentEvent::add_item() {
  // @@protoc_insertion_point(field_add_mutable:opentxs.proto.PaymentEvent.item)
  return item_.Add();
}
inline void PaymentEvent::add_item(const ::std::string& value) {
  item_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:opentxs.proto.PaymentEvent.item)
}
#if LANG_CXX11
inline void PaymentEvent::add_item(::std::string&& value) {
  item_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:opentxs.proto.PaymentEvent.item)
}
#endif
inline void PaymentEvent::add_item(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  item_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:opentxs.proto.PaymentEvent.item)
}
inline void PaymentEvent::add_item(const char* value, size_t size) {
  item_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:opentxs.proto.PaymentEvent.item)
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
PaymentEvent::item() const {
  // @@protoc_insertion_point(field_list:opentxs.proto.PaymentEvent.item)
  return item_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
PaymentEvent::mutable_item() {
  // @@protoc_insertion_point(field_mutable_list:opentxs.proto.PaymentEvent.item)
  return &item_;
}

// optional int64 time = 4;
inline bool PaymentEvent::has_time() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void PaymentEvent::set_has_time() {
  _has_bits_[0] |= 0x00000020u;
}
inline void PaymentEvent::clear_has_time() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void PaymentEvent::clear_time() {
  time_ = GOOGLE_LONGLONG(0);
  clear_has_time();
}
inline ::google::protobuf::int64 PaymentEvent::time() const {
  // @@protoc_insertion_point(field_get:opentxs.proto.PaymentEvent.time)
  return time_;
}
inline void PaymentEvent::set_time(::google::protobuf::int64 value) {
  set_has_time();
  time_ = value;
  // @@protoc_insertion_point(field_set:opentxs.proto.PaymentEvent.time)
}

// optional .opentxs.proto.EventTransportMethod method = 5;
inline bool PaymentEvent::has_method() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void PaymentEvent::set_has_method() {
  _has_bits_[0] |= 0x00000040u;
}
inline void PaymentEvent::clear_has_method() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void PaymentEvent::clear_method() {
  method_ = 0;
  clear_has_method();
}
inline ::opentxs::proto::EventTransportMethod PaymentEvent::method() const {
  // @@protoc_insertion_point(field_get:opentxs.proto.PaymentEvent.method)
  return static_cast< ::opentxs::proto::EventTransportMethod >(method_);
}
inline void PaymentEvent::set_method(::opentxs::proto::EventTransportMethod value) {
  assert(::opentxs::proto::EventTransportMethod_IsValid(value));
  set_has_method();
  method_ = value;
  // @@protoc_insertion_point(field_set:opentxs.proto.PaymentEvent.method)
}

// optional string transport = 6;
inline bool PaymentEvent::has_transport() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void PaymentEvent::set_has_transport() {
  _has_bits_[0] |= 0x00000001u;
}
inline void PaymentEvent::clear_has_transport() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void PaymentEvent::clear_transport() {
  transport_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_transport();
}
inline const ::std::string& PaymentEvent::transport() const {
  // @@protoc_insertion_point(field_get:opentxs.proto.PaymentEvent.transport)
  return transport_.GetNoArena();
}
inline void PaymentEvent::set_transport(const ::std::string& value) {
  set_has_transport();
  transport_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:opentxs.proto.PaymentEvent.transport)
}
#if LANG_CXX11
inline void PaymentEvent::set_transport(::std::string&& value) {
  set_has_transport();
  transport_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:opentxs.proto.PaymentEvent.transport)
}
#endif
inline void PaymentEvent::set_transport(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_transport();
  transport_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:opentxs.proto.PaymentEvent.transport)
}
inline void PaymentEvent::set_transport(const char* value, size_t size) {
  set_has_transport();
  transport_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:opentxs.proto.PaymentEvent.transport)
}
inline ::std::string* PaymentEvent::mutable_transport() {
  set_has_transport();
  // @@protoc_insertion_point(field_mutable:opentxs.proto.PaymentEvent.transport)
  return transport_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PaymentEvent::release_transport() {
  // @@protoc_insertion_point(field_release:opentxs.proto.PaymentEvent.transport)
  clear_has_transport();
  return transport_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PaymentEvent::set_allocated_transport(::std::string* transport) {
  if (transport != NULL) {
    set_has_transport();
  } else {
    clear_has_transport();
  }
  transport_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), transport);
  // @@protoc_insertion_point(field_set_allocated:opentxs.proto.PaymentEvent.transport)
}

// optional string nym = 7;
inline bool PaymentEvent::has_nym() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void PaymentEvent::set_has_nym() {
  _has_bits_[0] |= 0x00000002u;
}
inline void PaymentEvent::clear_has_nym() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void PaymentEvent::clear_nym() {
  nym_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_nym();
}
inline const ::std::string& PaymentEvent::nym() const {
  // @@protoc_insertion_point(field_get:opentxs.proto.PaymentEvent.nym)
  return nym_.GetNoArena();
}
inline void PaymentEvent::set_nym(const ::std::string& value) {
  set_has_nym();
  nym_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:opentxs.proto.PaymentEvent.nym)
}
#if LANG_CXX11
inline void PaymentEvent::set_nym(::std::string&& value) {
  set_has_nym();
  nym_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:opentxs.proto.PaymentEvent.nym)
}
#endif
inline void PaymentEvent::set_nym(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_nym();
  nym_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:opentxs.proto.PaymentEvent.nym)
}
inline void PaymentEvent::set_nym(const char* value, size_t size) {
  set_has_nym();
  nym_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:opentxs.proto.PaymentEvent.nym)
}
inline ::std::string* PaymentEvent::mutable_nym() {
  set_has_nym();
  // @@protoc_insertion_point(field_mutable:opentxs.proto.PaymentEvent.nym)
  return nym_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PaymentEvent::release_nym() {
  // @@protoc_insertion_point(field_release:opentxs.proto.PaymentEvent.nym)
  clear_has_nym();
  return nym_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PaymentEvent::set_allocated_nym(::std::string* nym) {
  if (nym != NULL) {
    set_has_nym();
  } else {
    clear_has_nym();
  }
  nym_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), nym);
  // @@protoc_insertion_point(field_set_allocated:opentxs.proto.PaymentEvent.nym)
}

// optional bool success = 8;
inline bool PaymentEvent::has_success() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void PaymentEvent::set_has_success() {
  _has_bits_[0] |= 0x00000080u;
}
inline void PaymentEvent::clear_has_success() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void PaymentEvent::clear_success() {
  success_ = false;
  clear_has_success();
}
inline bool PaymentEvent::success() const {
  // @@protoc_insertion_point(field_get:opentxs.proto.PaymentEvent.success)
  return success_;
}
inline void PaymentEvent::set_success(bool value) {
  set_has_success();
  success_ = value;
  // @@protoc_insertion_point(field_set:opentxs.proto.PaymentEvent.success)
}

// optional string memo = 9;
inline bool PaymentEvent::has_memo() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void PaymentEvent::set_has_memo() {
  _has_bits_[0] |= 0x00000004u;
}
inline void PaymentEvent::clear_has_memo() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void PaymentEvent::clear_memo() {
  memo_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_memo();
}
inline const ::std::string& PaymentEvent::memo() const {
  // @@protoc_insertion_point(field_get:opentxs.proto.PaymentEvent.memo)
  return memo_.GetNoArena();
}
inline void PaymentEvent::set_memo(const ::std::string& value) {
  set_has_memo();
  memo_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:opentxs.proto.PaymentEvent.memo)
}
#if LANG_CXX11
inline void PaymentEvent::set_memo(::std::string&& value) {
  set_has_memo();
  memo_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:opentxs.proto.PaymentEvent.memo)
}
#endif
inline void PaymentEvent::set_memo(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_memo();
  memo_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:opentxs.proto.PaymentEvent.memo)
}
inline void PaymentEvent::set_memo(const char* value, size_t size) {
  set_has_memo();
  memo_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:opentxs.proto.PaymentEvent.memo)
}
inline ::std::string* PaymentEvent::mutable_memo() {
  set_has_memo();
  // @@protoc_insertion_point(field_mutable:opentxs.proto.PaymentEvent.memo)
  return memo_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PaymentEvent::release_memo() {
  // @@protoc_insertion_point(field_release:opentxs.proto.PaymentEvent.memo)
  clear_has_memo();
  return memo_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PaymentEvent::set_allocated_memo(::std::string* memo) {
  if (memo != NULL) {
    set_has_memo();
  } else {
    clear_has_memo();
  }
  memo_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), memo);
  // @@protoc_insertion_point(field_set_allocated:opentxs.proto.PaymentEvent.memo)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace opentxs

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_PaymentEvent_2eproto__INCLUDED
