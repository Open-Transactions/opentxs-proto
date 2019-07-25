// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: BlockchainPreviousOutput.proto

#include "BlockchainPreviousOutput.pb.h"

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
class BlockchainPreviousOutputDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<BlockchainPreviousOutput>
      _instance;
} _BlockchainPreviousOutput_default_instance_;
}  // namespace proto
}  // namespace opentxs
namespace protobuf_BlockchainPreviousOutput_2eproto {
void InitDefaultsBlockchainPreviousOutputImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  {
    void* ptr = &::opentxs::proto::_BlockchainPreviousOutput_default_instance_;
    new (ptr) ::opentxs::proto::BlockchainPreviousOutput();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::opentxs::proto::BlockchainPreviousOutput::InitAsDefaultInstance();
}

void InitDefaultsBlockchainPreviousOutput() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsBlockchainPreviousOutputImpl);
}

}  // namespace protobuf_BlockchainPreviousOutput_2eproto
namespace opentxs {
namespace proto {

// ===================================================================

void BlockchainPreviousOutput::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int BlockchainPreviousOutput::kVersionFieldNumber;
const int BlockchainPreviousOutput::kTxidFieldNumber;
const int BlockchainPreviousOutput::kIndexFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

BlockchainPreviousOutput::BlockchainPreviousOutput()
  : ::google::protobuf::MessageLite(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_BlockchainPreviousOutput_2eproto::InitDefaultsBlockchainPreviousOutput();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:opentxs.proto.BlockchainPreviousOutput)
}
BlockchainPreviousOutput::BlockchainPreviousOutput(const BlockchainPreviousOutput& from)
  : ::google::protobuf::MessageLite(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  txid_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_txid()) {
    txid_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.txid_);
  }
  ::memcpy(&index_, &from.index_,
    static_cast<size_t>(reinterpret_cast<char*>(&version_) -
    reinterpret_cast<char*>(&index_)) + sizeof(version_));
  // @@protoc_insertion_point(copy_constructor:opentxs.proto.BlockchainPreviousOutput)
}

void BlockchainPreviousOutput::SharedCtor() {
  _cached_size_ = 0;
  txid_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&index_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&version_) -
      reinterpret_cast<char*>(&index_)) + sizeof(version_));
}

BlockchainPreviousOutput::~BlockchainPreviousOutput() {
  // @@protoc_insertion_point(destructor:opentxs.proto.BlockchainPreviousOutput)
  SharedDtor();
}

void BlockchainPreviousOutput::SharedDtor() {
  txid_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void BlockchainPreviousOutput::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const BlockchainPreviousOutput& BlockchainPreviousOutput::default_instance() {
  ::protobuf_BlockchainPreviousOutput_2eproto::InitDefaultsBlockchainPreviousOutput();
  return *internal_default_instance();
}

BlockchainPreviousOutput* BlockchainPreviousOutput::New(::google::protobuf::Arena* arena) const {
  BlockchainPreviousOutput* n = new BlockchainPreviousOutput;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void BlockchainPreviousOutput::Clear() {
// @@protoc_insertion_point(message_clear_start:opentxs.proto.BlockchainPreviousOutput)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    GOOGLE_DCHECK(!txid_.IsDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited()));
    (*txid_.UnsafeRawStringPointer())->clear();
  }
  if (cached_has_bits & 6u) {
    ::memset(&index_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&version_) -
        reinterpret_cast<char*>(&index_)) + sizeof(version_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool BlockchainPreviousOutput::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  ::google::protobuf::internal::LiteUnknownFieldSetter unknown_fields_setter(
      &_internal_metadata_);
  ::google::protobuf::io::StringOutputStream unknown_fields_output(
      unknown_fields_setter.buffer());
  ::google::protobuf::io::CodedOutputStream unknown_fields_stream(
      &unknown_fields_output, false);
  // @@protoc_insertion_point(parse_start:opentxs.proto.BlockchainPreviousOutput)
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

      // optional string txid = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_txid()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional uint64 index = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(24u /* 24 & 0xFF */)) {
          set_has_index();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &index_)));
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
  // @@protoc_insertion_point(parse_success:opentxs.proto.BlockchainPreviousOutput)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:opentxs.proto.BlockchainPreviousOutput)
  return false;
#undef DO_
}

void BlockchainPreviousOutput::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:opentxs.proto.BlockchainPreviousOutput)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional uint32 version = 1;
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->version(), output);
  }

  // optional string txid = 2;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->txid(), output);
  }

  // optional uint64 index = 3;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(3, this->index(), output);
  }

  output->WriteRaw(_internal_metadata_.unknown_fields().data(),
                   static_cast<int>(_internal_metadata_.unknown_fields().size()));
  // @@protoc_insertion_point(serialize_end:opentxs.proto.BlockchainPreviousOutput)
}

size_t BlockchainPreviousOutput::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:opentxs.proto.BlockchainPreviousOutput)
  size_t total_size = 0;

  total_size += _internal_metadata_.unknown_fields().size();

  if (_has_bits_[0 / 32] & 7u) {
    // optional string txid = 2;
    if (has_txid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->txid());
    }

    // optional uint64 index = 3;
    if (has_index()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->index());
    }

    // optional uint32 version = 1;
    if (has_version()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->version());
    }

  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void BlockchainPreviousOutput::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const BlockchainPreviousOutput*>(&from));
}

void BlockchainPreviousOutput::MergeFrom(const BlockchainPreviousOutput& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:opentxs.proto.BlockchainPreviousOutput)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 7u) {
    if (cached_has_bits & 0x00000001u) {
      set_has_txid();
      txid_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.txid_);
    }
    if (cached_has_bits & 0x00000002u) {
      index_ = from.index_;
    }
    if (cached_has_bits & 0x00000004u) {
      version_ = from.version_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void BlockchainPreviousOutput::CopyFrom(const BlockchainPreviousOutput& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:opentxs.proto.BlockchainPreviousOutput)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool BlockchainPreviousOutput::IsInitialized() const {
  return true;
}

void BlockchainPreviousOutput::Swap(BlockchainPreviousOutput* other) {
  if (other == this) return;
  InternalSwap(other);
}
void BlockchainPreviousOutput::InternalSwap(BlockchainPreviousOutput* other) {
  using std::swap;
  txid_.Swap(&other->txid_);
  swap(index_, other->index_);
  swap(version_, other->version_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::std::string BlockchainPreviousOutput::GetTypeName() const {
  return "opentxs.proto.BlockchainPreviousOutput";
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace proto
}  // namespace opentxs

// @@protoc_insertion_point(global_scope)
