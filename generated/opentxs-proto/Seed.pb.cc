// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Seed.proto

#include "Seed.pb.h"

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
class SeedDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Seed>
      _instance;
} _Seed_default_instance_;
}  // namespace proto
}  // namespace opentxs
namespace protobuf_Seed_2eproto {
void InitDefaultsSeedImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  protobuf_Ciphertext_2eproto::InitDefaultsCiphertext();
  {
    void* ptr = &::opentxs::proto::_Seed_default_instance_;
    new (ptr) ::opentxs::proto::Seed();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::opentxs::proto::Seed::InitAsDefaultInstance();
}

void InitDefaultsSeed() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsSeedImpl);
}

}  // namespace protobuf_Seed_2eproto
namespace opentxs {
namespace proto {

// ===================================================================

void Seed::InitAsDefaultInstance() {
  ::opentxs::proto::_Seed_default_instance_._instance.get_mutable()->words_ = const_cast< ::opentxs::proto::Ciphertext*>(
      ::opentxs::proto::Ciphertext::internal_default_instance());
  ::opentxs::proto::_Seed_default_instance_._instance.get_mutable()->passphrase_ = const_cast< ::opentxs::proto::Ciphertext*>(
      ::opentxs::proto::Ciphertext::internal_default_instance());
  ::opentxs::proto::_Seed_default_instance_._instance.get_mutable()->raw_ = const_cast< ::opentxs::proto::Ciphertext*>(
      ::opentxs::proto::Ciphertext::internal_default_instance());
}
void Seed::clear_words() {
  if (words_ != NULL) words_->Clear();
  clear_has_words();
}
void Seed::clear_passphrase() {
  if (passphrase_ != NULL) passphrase_->Clear();
  clear_has_passphrase();
}
void Seed::clear_raw() {
  if (raw_ != NULL) raw_->Clear();
  clear_has_raw();
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Seed::kVersionFieldNumber;
const int Seed::kWordsFieldNumber;
const int Seed::kPassphraseFieldNumber;
const int Seed::kFingerprintFieldNumber;
const int Seed::kIndexFieldNumber;
const int Seed::kRawFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Seed::Seed()
  : ::google::protobuf::MessageLite(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_Seed_2eproto::InitDefaultsSeed();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:opentxs.proto.Seed)
}
Seed::Seed(const Seed& from)
  : ::google::protobuf::MessageLite(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  fingerprint_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_fingerprint()) {
    fingerprint_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.fingerprint_);
  }
  if (from.has_words()) {
    words_ = new ::opentxs::proto::Ciphertext(*from.words_);
  } else {
    words_ = NULL;
  }
  if (from.has_passphrase()) {
    passphrase_ = new ::opentxs::proto::Ciphertext(*from.passphrase_);
  } else {
    passphrase_ = NULL;
  }
  if (from.has_raw()) {
    raw_ = new ::opentxs::proto::Ciphertext(*from.raw_);
  } else {
    raw_ = NULL;
  }
  ::memcpy(&version_, &from.version_,
    static_cast<size_t>(reinterpret_cast<char*>(&index_) -
    reinterpret_cast<char*>(&version_)) + sizeof(index_));
  // @@protoc_insertion_point(copy_constructor:opentxs.proto.Seed)
}

void Seed::SharedCtor() {
  _cached_size_ = 0;
  fingerprint_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&words_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&index_) -
      reinterpret_cast<char*>(&words_)) + sizeof(index_));
}

Seed::~Seed() {
  // @@protoc_insertion_point(destructor:opentxs.proto.Seed)
  SharedDtor();
}

void Seed::SharedDtor() {
  fingerprint_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != internal_default_instance()) delete words_;
  if (this != internal_default_instance()) delete passphrase_;
  if (this != internal_default_instance()) delete raw_;
}

void Seed::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const Seed& Seed::default_instance() {
  ::protobuf_Seed_2eproto::InitDefaultsSeed();
  return *internal_default_instance();
}

Seed* Seed::New(::google::protobuf::Arena* arena) const {
  Seed* n = new Seed;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void Seed::Clear() {
// @@protoc_insertion_point(message_clear_start:opentxs.proto.Seed)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 15u) {
    if (cached_has_bits & 0x00000001u) {
      GOOGLE_DCHECK(!fingerprint_.IsDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited()));
      (*fingerprint_.UnsafeRawStringPointer())->clear();
    }
    if (cached_has_bits & 0x00000002u) {
      GOOGLE_DCHECK(words_ != NULL);
      words_->Clear();
    }
    if (cached_has_bits & 0x00000004u) {
      GOOGLE_DCHECK(passphrase_ != NULL);
      passphrase_->Clear();
    }
    if (cached_has_bits & 0x00000008u) {
      GOOGLE_DCHECK(raw_ != NULL);
      raw_->Clear();
    }
  }
  if (cached_has_bits & 48u) {
    ::memset(&version_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&index_) -
        reinterpret_cast<char*>(&version_)) + sizeof(index_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool Seed::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  ::google::protobuf::internal::LiteUnknownFieldSetter unknown_fields_setter(
      &_internal_metadata_);
  ::google::protobuf::io::StringOutputStream unknown_fields_output(
      unknown_fields_setter.buffer());
  ::google::protobuf::io::CodedOutputStream unknown_fields_stream(
      &unknown_fields_output, false);
  // @@protoc_insertion_point(parse_start:opentxs.proto.Seed)
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

      // optional .opentxs.proto.Ciphertext words = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
               input, mutable_words()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional .opentxs.proto.Ciphertext passphrase = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
               input, mutable_passphrase()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string fingerprint = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(34u /* 34 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_fingerprint()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional uint32 index = 5;
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(40u /* 40 & 0xFF */)) {
          set_has_index();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &index_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional .opentxs.proto.Ciphertext raw = 6;
      case 6: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(50u /* 50 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
               input, mutable_raw()));
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
  // @@protoc_insertion_point(parse_success:opentxs.proto.Seed)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:opentxs.proto.Seed)
  return false;
#undef DO_
}

void Seed::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:opentxs.proto.Seed)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional uint32 version = 1;
  if (cached_has_bits & 0x00000010u) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->version(), output);
  }

  // optional .opentxs.proto.Ciphertext words = 2;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      2, *this->words_, output);
  }

  // optional .opentxs.proto.Ciphertext passphrase = 3;
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      3, *this->passphrase_, output);
  }

  // optional string fingerprint = 4;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      4, this->fingerprint(), output);
  }

  // optional uint32 index = 5;
  if (cached_has_bits & 0x00000020u) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(5, this->index(), output);
  }

  // optional .opentxs.proto.Ciphertext raw = 6;
  if (cached_has_bits & 0x00000008u) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      6, *this->raw_, output);
  }

  output->WriteRaw(_internal_metadata_.unknown_fields().data(),
                   static_cast<int>(_internal_metadata_.unknown_fields().size()));
  // @@protoc_insertion_point(serialize_end:opentxs.proto.Seed)
}

size_t Seed::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:opentxs.proto.Seed)
  size_t total_size = 0;

  total_size += _internal_metadata_.unknown_fields().size();

  if (_has_bits_[0 / 32] & 63u) {
    // optional string fingerprint = 4;
    if (has_fingerprint()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->fingerprint());
    }

    // optional .opentxs.proto.Ciphertext words = 2;
    if (has_words()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          *this->words_);
    }

    // optional .opentxs.proto.Ciphertext passphrase = 3;
    if (has_passphrase()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          *this->passphrase_);
    }

    // optional .opentxs.proto.Ciphertext raw = 6;
    if (has_raw()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          *this->raw_);
    }

    // optional uint32 version = 1;
    if (has_version()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->version());
    }

    // optional uint32 index = 5;
    if (has_index()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->index());
    }

  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Seed::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const Seed*>(&from));
}

void Seed::MergeFrom(const Seed& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:opentxs.proto.Seed)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 63u) {
    if (cached_has_bits & 0x00000001u) {
      set_has_fingerprint();
      fingerprint_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.fingerprint_);
    }
    if (cached_has_bits & 0x00000002u) {
      mutable_words()->::opentxs::proto::Ciphertext::MergeFrom(from.words());
    }
    if (cached_has_bits & 0x00000004u) {
      mutable_passphrase()->::opentxs::proto::Ciphertext::MergeFrom(from.passphrase());
    }
    if (cached_has_bits & 0x00000008u) {
      mutable_raw()->::opentxs::proto::Ciphertext::MergeFrom(from.raw());
    }
    if (cached_has_bits & 0x00000010u) {
      version_ = from.version_;
    }
    if (cached_has_bits & 0x00000020u) {
      index_ = from.index_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void Seed::CopyFrom(const Seed& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:opentxs.proto.Seed)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Seed::IsInitialized() const {
  return true;
}

void Seed::Swap(Seed* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Seed::InternalSwap(Seed* other) {
  using std::swap;
  fingerprint_.Swap(&other->fingerprint_);
  swap(words_, other->words_);
  swap(passphrase_, other->passphrase_);
  swap(raw_, other->raw_);
  swap(version_, other->version_);
  swap(index_, other->index_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::std::string Seed::GetTypeName() const {
  return "opentxs.proto.Seed";
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace proto
}  // namespace opentxs

// @@protoc_insertion_point(global_scope)
