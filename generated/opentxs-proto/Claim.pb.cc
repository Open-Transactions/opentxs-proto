// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Claim.proto

#include "Claim.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)
namespace opentxs {
namespace proto {
class ClaimDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Claim>
      _instance;
} _Claim_default_instance_;
}  // namespace proto
}  // namespace opentxs
namespace protobuf_Claim_2eproto {
void InitDefaultsClaimImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  {
    void* ptr = &::opentxs::proto::_Claim_default_instance_;
    new (ptr) ::opentxs::proto::Claim();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::opentxs::proto::Claim::InitAsDefaultInstance();
}

void InitDefaultsClaim() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsClaimImpl);
}

}  // namespace protobuf_Claim_2eproto
namespace opentxs {
namespace proto {

// ===================================================================

void Claim::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Claim::kVersionFieldNumber;
const int Claim::kNymIDFieldNumber;
const int Claim::kSectionFieldNumber;
const int Claim::kTypeFieldNumber;
const int Claim::kStartFieldNumber;
const int Claim::kEndFieldNumber;
const int Claim::kValueFieldNumber;
const int Claim::kSubtypeFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Claim::Claim()
  : ::google::protobuf::MessageLite(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_Claim_2eproto::InitDefaultsClaim();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:opentxs.proto.Claim)
}
Claim::Claim(const Claim& from)
  : ::google::protobuf::MessageLite(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  nymid_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_nymid()) {
    nymid_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.nymid_);
  }
  value_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_value()) {
    value_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.value_);
  }
  subtype_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_subtype()) {
    subtype_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.subtype_);
  }
  ::memcpy(&version_, &from.version_,
    static_cast<size_t>(reinterpret_cast<char*>(&type_) -
    reinterpret_cast<char*>(&version_)) + sizeof(type_));
  // @@protoc_insertion_point(copy_constructor:opentxs.proto.Claim)
}

void Claim::SharedCtor() {
  _cached_size_ = 0;
  nymid_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  value_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  subtype_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&version_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&type_) -
      reinterpret_cast<char*>(&version_)) + sizeof(type_));
}

Claim::~Claim() {
  // @@protoc_insertion_point(destructor:opentxs.proto.Claim)
  SharedDtor();
}

void Claim::SharedDtor() {
  nymid_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  value_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  subtype_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void Claim::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const Claim& Claim::default_instance() {
  ::protobuf_Claim_2eproto::InitDefaultsClaim();
  return *internal_default_instance();
}

Claim* Claim::New(::google::protobuf::Arena* arena) const {
  Claim* n = new Claim;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void Claim::Clear() {
// @@protoc_insertion_point(message_clear_start:opentxs.proto.Claim)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 7u) {
    if (cached_has_bits & 0x00000001u) {
      GOOGLE_DCHECK(!nymid_.IsDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited()));
      (*nymid_.UnsafeRawStringPointer())->clear();
    }
    if (cached_has_bits & 0x00000002u) {
      GOOGLE_DCHECK(!value_.IsDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited()));
      (*value_.UnsafeRawStringPointer())->clear();
    }
    if (cached_has_bits & 0x00000004u) {
      GOOGLE_DCHECK(!subtype_.IsDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited()));
      (*subtype_.UnsafeRawStringPointer())->clear();
    }
  }
  if (cached_has_bits & 248u) {
    ::memset(&version_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&type_) -
        reinterpret_cast<char*>(&version_)) + sizeof(type_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool Claim::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  ::google::protobuf::internal::LiteUnknownFieldSetter unknown_fields_setter(
      &_internal_metadata_);
  ::google::protobuf::io::StringOutputStream unknown_fields_output(
      unknown_fields_setter.buffer());
  ::google::protobuf::io::CodedOutputStream unknown_fields_stream(
      &unknown_fields_output, false);
  // @@protoc_insertion_point(parse_start:opentxs.proto.Claim)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional uint32 version = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {
          set_has_version();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &version_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string nymID = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_nymid()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional uint32 section = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(24u /* 24 & 0xFF */)) {
          set_has_section();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &section_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional uint32 type = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(32u /* 32 & 0xFF */)) {
          set_has_type();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &type_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional sint64 start = 5;
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(40u /* 40 & 0xFF */)) {
          set_has_start();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_SINT64>(
                 input, &start_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional sint64 end = 6;
      case 6: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(48u /* 48 & 0xFF */)) {
          set_has_end();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_SINT64>(
                 input, &end_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string value = 7;
      case 7: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(58u /* 58 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_value()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string subtype = 8;
      case 8: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(66u /* 66 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_subtype()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(
            input, tag, &unknown_fields_stream));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:opentxs.proto.Claim)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:opentxs.proto.Claim)
  return false;
#undef DO_
}

void Claim::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:opentxs.proto.Claim)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional uint32 version = 1;
  if (cached_has_bits & 0x00000008u) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->version(), output);
  }

  // optional string nymID = 2;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->nymid(), output);
  }

  // optional uint32 section = 3;
  if (cached_has_bits & 0x00000010u) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->section(), output);
  }

  // optional uint32 type = 4;
  if (cached_has_bits & 0x00000080u) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(4, this->type(), output);
  }

  // optional sint64 start = 5;
  if (cached_has_bits & 0x00000020u) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt64(5, this->start(), output);
  }

  // optional sint64 end = 6;
  if (cached_has_bits & 0x00000040u) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt64(6, this->end(), output);
  }

  // optional string value = 7;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      7, this->value(), output);
  }

  // optional string subtype = 8;
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      8, this->subtype(), output);
  }

  output->WriteRaw(_internal_metadata_.unknown_fields().data(),
                   static_cast<int>(_internal_metadata_.unknown_fields().size()));
  // @@protoc_insertion_point(serialize_end:opentxs.proto.Claim)
}

size_t Claim::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:opentxs.proto.Claim)
  size_t total_size = 0;

  total_size += _internal_metadata_.unknown_fields().size();

  if (_has_bits_[0 / 32] & 255u) {
    // optional string nymID = 2;
    if (has_nymid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->nymid());
    }

    // optional string value = 7;
    if (has_value()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->value());
    }

    // optional string subtype = 8;
    if (has_subtype()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->subtype());
    }

    // optional uint32 version = 1;
    if (has_version()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->version());
    }

    // optional uint32 section = 3;
    if (has_section()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->section());
    }

    // optional sint64 start = 5;
    if (has_start()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::SInt64Size(
          this->start());
    }

    // optional sint64 end = 6;
    if (has_end()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::SInt64Size(
          this->end());
    }

    // optional uint32 type = 4;
    if (has_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->type());
    }

  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Claim::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const Claim*>(&from));
}

void Claim::MergeFrom(const Claim& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:opentxs.proto.Claim)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 255u) {
    if (cached_has_bits & 0x00000001u) {
      set_has_nymid();
      nymid_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.nymid_);
    }
    if (cached_has_bits & 0x00000002u) {
      set_has_value();
      value_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.value_);
    }
    if (cached_has_bits & 0x00000004u) {
      set_has_subtype();
      subtype_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.subtype_);
    }
    if (cached_has_bits & 0x00000008u) {
      version_ = from.version_;
    }
    if (cached_has_bits & 0x00000010u) {
      section_ = from.section_;
    }
    if (cached_has_bits & 0x00000020u) {
      start_ = from.start_;
    }
    if (cached_has_bits & 0x00000040u) {
      end_ = from.end_;
    }
    if (cached_has_bits & 0x00000080u) {
      type_ = from.type_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void Claim::CopyFrom(const Claim& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:opentxs.proto.Claim)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Claim::IsInitialized() const {
  return true;
}

void Claim::Swap(Claim* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Claim::InternalSwap(Claim* other) {
  using std::swap;
  nymid_.Swap(&other->nymid_);
  value_.Swap(&other->value_);
  subtype_.Swap(&other->subtype_);
  swap(version_, other->version_);
  swap(section_, other->section_);
  swap(start_, other->start_);
  swap(end_, other->end_);
  swap(type_, other->type_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::std::string Claim::GetTypeName() const {
  return "opentxs.proto.Claim";
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace proto
}  // namespace opentxs

// @@protoc_insertion_point(global_scope)
