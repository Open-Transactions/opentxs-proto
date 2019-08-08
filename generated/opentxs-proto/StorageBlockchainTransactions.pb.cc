// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: StorageBlockchainTransactions.proto

#include "StorageBlockchainTransactions.pb.h"

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
class StorageBlockchainTransactionsDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<StorageBlockchainTransactions>
      _instance;
} _StorageBlockchainTransactions_default_instance_;
}  // namespace proto
}  // namespace opentxs
namespace protobuf_StorageBlockchainTransactions_2eproto {
void InitDefaultsStorageBlockchainTransactionsImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  protobuf_StorageItemHash_2eproto::InitDefaultsStorageItemHash();
  protobuf_StorageContactNymIndex_2eproto::InitDefaultsStorageContactNymIndex();
  {
    void* ptr = &::opentxs::proto::_StorageBlockchainTransactions_default_instance_;
    new (ptr) ::opentxs::proto::StorageBlockchainTransactions();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::opentxs::proto::StorageBlockchainTransactions::InitAsDefaultInstance();
}

void InitDefaultsStorageBlockchainTransactions() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsStorageBlockchainTransactionsImpl);
}

}  // namespace protobuf_StorageBlockchainTransactions_2eproto
namespace opentxs {
namespace proto {

// ===================================================================

void StorageBlockchainTransactions::InitAsDefaultInstance() {
}
void StorageBlockchainTransactions::clear_transaction() {
  transaction_.Clear();
}
void StorageBlockchainTransactions::clear_nymindex() {
  nymindex_.Clear();
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int StorageBlockchainTransactions::kVersionFieldNumber;
const int StorageBlockchainTransactions::kTransactionFieldNumber;
const int StorageBlockchainTransactions::kNymindexFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

StorageBlockchainTransactions::StorageBlockchainTransactions()
  : ::google::protobuf::MessageLite(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_StorageBlockchainTransactions_2eproto::InitDefaultsStorageBlockchainTransactions();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:opentxs.proto.StorageBlockchainTransactions)
}
StorageBlockchainTransactions::StorageBlockchainTransactions(const StorageBlockchainTransactions& from)
  : ::google::protobuf::MessageLite(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0),
      transaction_(from.transaction_),
      nymindex_(from.nymindex_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  version_ = from.version_;
  // @@protoc_insertion_point(copy_constructor:opentxs.proto.StorageBlockchainTransactions)
}

void StorageBlockchainTransactions::SharedCtor() {
  _cached_size_ = 0;
  version_ = 0u;
}

StorageBlockchainTransactions::~StorageBlockchainTransactions() {
  // @@protoc_insertion_point(destructor:opentxs.proto.StorageBlockchainTransactions)
  SharedDtor();
}

void StorageBlockchainTransactions::SharedDtor() {
}

void StorageBlockchainTransactions::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const StorageBlockchainTransactions& StorageBlockchainTransactions::default_instance() {
  ::protobuf_StorageBlockchainTransactions_2eproto::InitDefaultsStorageBlockchainTransactions();
  return *internal_default_instance();
}

StorageBlockchainTransactions* StorageBlockchainTransactions::New(::google::protobuf::Arena* arena) const {
  StorageBlockchainTransactions* n = new StorageBlockchainTransactions;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void StorageBlockchainTransactions::Clear() {
// @@protoc_insertion_point(message_clear_start:opentxs.proto.StorageBlockchainTransactions)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  transaction_.Clear();
  nymindex_.Clear();
  version_ = 0u;
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool StorageBlockchainTransactions::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  ::google::protobuf::internal::LiteUnknownFieldSetter unknown_fields_setter(
      &_internal_metadata_);
  ::google::protobuf::io::StringOutputStream unknown_fields_output(
      unknown_fields_setter.buffer());
  ::google::protobuf::io::CodedOutputStream unknown_fields_stream(
      &unknown_fields_output, false);
  // @@protoc_insertion_point(parse_start:opentxs.proto.StorageBlockchainTransactions)
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

      // repeated .opentxs.proto.StorageItemHash transaction = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(input, add_transaction()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated .opentxs.proto.StorageContactNymIndex nymindex = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(input, add_nymindex()));
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
  // @@protoc_insertion_point(parse_success:opentxs.proto.StorageBlockchainTransactions)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:opentxs.proto.StorageBlockchainTransactions)
  return false;
#undef DO_
}

void StorageBlockchainTransactions::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:opentxs.proto.StorageBlockchainTransactions)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional uint32 version = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->version(), output);
  }

  // repeated .opentxs.proto.StorageItemHash transaction = 2;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->transaction_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      2, this->transaction(static_cast<int>(i)), output);
  }

  // repeated .opentxs.proto.StorageContactNymIndex nymindex = 3;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->nymindex_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessage(
      3, this->nymindex(static_cast<int>(i)), output);
  }

  output->WriteRaw(_internal_metadata_.unknown_fields().data(),
                   static_cast<int>(_internal_metadata_.unknown_fields().size()));
  // @@protoc_insertion_point(serialize_end:opentxs.proto.StorageBlockchainTransactions)
}

size_t StorageBlockchainTransactions::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:opentxs.proto.StorageBlockchainTransactions)
  size_t total_size = 0;

  total_size += _internal_metadata_.unknown_fields().size();

  // repeated .opentxs.proto.StorageItemHash transaction = 2;
  {
    unsigned int count = static_cast<unsigned int>(this->transaction_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          this->transaction(static_cast<int>(i)));
    }
  }

  // repeated .opentxs.proto.StorageContactNymIndex nymindex = 3;
  {
    unsigned int count = static_cast<unsigned int>(this->nymindex_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          this->nymindex(static_cast<int>(i)));
    }
  }

  // optional uint32 version = 1;
  if (has_version()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->version());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void StorageBlockchainTransactions::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const StorageBlockchainTransactions*>(&from));
}

void StorageBlockchainTransactions::MergeFrom(const StorageBlockchainTransactions& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:opentxs.proto.StorageBlockchainTransactions)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  transaction_.MergeFrom(from.transaction_);
  nymindex_.MergeFrom(from.nymindex_);
  if (from.has_version()) {
    set_version(from.version());
  }
}

void StorageBlockchainTransactions::CopyFrom(const StorageBlockchainTransactions& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:opentxs.proto.StorageBlockchainTransactions)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool StorageBlockchainTransactions::IsInitialized() const {
  return true;
}

void StorageBlockchainTransactions::Swap(StorageBlockchainTransactions* other) {
  if (other == this) return;
  InternalSwap(other);
}
void StorageBlockchainTransactions::InternalSwap(StorageBlockchainTransactions* other) {
  using std::swap;
  transaction_.InternalSwap(&other->transaction_);
  nymindex_.InternalSwap(&other->nymindex_);
  swap(version_, other->version_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::std::string StorageBlockchainTransactions::GetTypeName() const {
  return "opentxs.proto.StorageBlockchainTransactions";
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace proto
}  // namespace opentxs

// @@protoc_insertion_point(global_scope)
