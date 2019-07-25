// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: BlockchainTransactionOutput.proto

#include "BlockchainTransactionOutput.pb.h"

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
class BlockchainTransactionOutputDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<BlockchainTransactionOutput>
      _instance;
  const ::opentxs::proto::BlockchainWalletKey* key_;
  const ::opentxs::proto::BlockchainExternalAddress* external_;
} _BlockchainTransactionOutput_default_instance_;
}  // namespace proto
}  // namespace opentxs
namespace protobuf_BlockchainTransactionOutput_2eproto {
void InitDefaultsBlockchainTransactionOutputImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  protobuf_BlockchainWalletKey_2eproto::InitDefaultsBlockchainWalletKey();
  protobuf_BlockchainExternalAddress_2eproto::InitDefaultsBlockchainExternalAddress();
  {
    void* ptr = &::opentxs::proto::_BlockchainTransactionOutput_default_instance_;
    new (ptr) ::opentxs::proto::BlockchainTransactionOutput();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::opentxs::proto::BlockchainTransactionOutput::InitAsDefaultInstance();
}

void InitDefaultsBlockchainTransactionOutput() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsBlockchainTransactionOutputImpl);
}

}  // namespace protobuf_BlockchainTransactionOutput_2eproto
namespace opentxs {
namespace proto {

// ===================================================================

void BlockchainTransactionOutput::InitAsDefaultInstance() {
}
void BlockchainTransactionOutput::set_allocated_key(::opentxs::proto::BlockchainWalletKey* key) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  clear_destination();
  if (key) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      key = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, key, submessage_arena);
    }
    set_has_key();
    destination_.key_ = key;
  }
  // @@protoc_insertion_point(field_set_allocated:opentxs.proto.BlockchainTransactionOutput.key)
}
void BlockchainTransactionOutput::clear_key() {
  if (has_key()) {
    delete destination_.key_;
    clear_has_destination();
  }
}
void BlockchainTransactionOutput::set_allocated_external(::opentxs::proto::BlockchainExternalAddress* external) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  clear_destination();
  if (external) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      external = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, external, submessage_arena);
    }
    set_has_external();
    destination_.external_ = external;
  }
  // @@protoc_insertion_point(field_set_allocated:opentxs.proto.BlockchainTransactionOutput.external)
}
void BlockchainTransactionOutput::clear_external() {
  if (has_external()) {
    delete destination_.external_;
    clear_has_destination();
  }
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int BlockchainTransactionOutput::kVersionFieldNumber;
const int BlockchainTransactionOutput::kIndexFieldNumber;
const int BlockchainTransactionOutput::kValueFieldNumber;
const int BlockchainTransactionOutput::kScriptFieldNumber;
const int BlockchainTransactionOutput::kKeyFieldNumber;
const int BlockchainTransactionOutput::kExternalFieldNumber;
const int BlockchainTransactionOutput::kConfirmedspendFieldNumber;
const int BlockchainTransactionOutput::kOrphanedspendFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

BlockchainTransactionOutput::BlockchainTransactionOutput()
  : ::google::protobuf::MessageLite(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_BlockchainTransactionOutput_2eproto::InitDefaultsBlockchainTransactionOutput();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:opentxs.proto.BlockchainTransactionOutput)
}
BlockchainTransactionOutput::BlockchainTransactionOutput(const BlockchainTransactionOutput& from)
  : ::google::protobuf::MessageLite(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0),
      orphanedspend_(from.orphanedspend_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  script_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_script()) {
    script_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.script_);
  }
  confirmedspend_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_confirmedspend()) {
    confirmedspend_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.confirmedspend_);
  }
  ::memcpy(&version_, &from.version_,
    static_cast<size_t>(reinterpret_cast<char*>(&value_) -
    reinterpret_cast<char*>(&version_)) + sizeof(value_));
  clear_has_destination();
  switch (from.destination_case()) {
    case kKey: {
      mutable_key()->::opentxs::proto::BlockchainWalletKey::MergeFrom(from.key());
      break;
    }
    case kExternal: {
      mutable_external()->::opentxs::proto::BlockchainExternalAddress::MergeFrom(from.external());
      break;
    }
    case DESTINATION_NOT_SET: {
      break;
    }
  }
  // @@protoc_insertion_point(copy_constructor:opentxs.proto.BlockchainTransactionOutput)
}

void BlockchainTransactionOutput::SharedCtor() {
  _cached_size_ = 0;
  script_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  confirmedspend_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&version_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&value_) -
      reinterpret_cast<char*>(&version_)) + sizeof(value_));
  clear_has_destination();
}

BlockchainTransactionOutput::~BlockchainTransactionOutput() {
  // @@protoc_insertion_point(destructor:opentxs.proto.BlockchainTransactionOutput)
  SharedDtor();
}

void BlockchainTransactionOutput::SharedDtor() {
  script_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  confirmedspend_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (has_destination()) {
    clear_destination();
  }
}

void BlockchainTransactionOutput::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const BlockchainTransactionOutput& BlockchainTransactionOutput::default_instance() {
  ::protobuf_BlockchainTransactionOutput_2eproto::InitDefaultsBlockchainTransactionOutput();
  return *internal_default_instance();
}

BlockchainTransactionOutput* BlockchainTransactionOutput::New(::google::protobuf::Arena* arena) const {
  BlockchainTransactionOutput* n = new BlockchainTransactionOutput;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void BlockchainTransactionOutput::clear_destination() {
// @@protoc_insertion_point(one_of_clear_start:opentxs.proto.BlockchainTransactionOutput)
  switch (destination_case()) {
    case kKey: {
      delete destination_.key_;
      break;
    }
    case kExternal: {
      delete destination_.external_;
      break;
    }
    case DESTINATION_NOT_SET: {
      break;
    }
  }
  _oneof_case_[0] = DESTINATION_NOT_SET;
}


void BlockchainTransactionOutput::Clear() {
// @@protoc_insertion_point(message_clear_start:opentxs.proto.BlockchainTransactionOutput)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  orphanedspend_.Clear();
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 3u) {
    if (cached_has_bits & 0x00000001u) {
      GOOGLE_DCHECK(!script_.IsDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited()));
      (*script_.UnsafeRawStringPointer())->clear();
    }
    if (cached_has_bits & 0x00000002u) {
      GOOGLE_DCHECK(!confirmedspend_.IsDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited()));
      (*confirmedspend_.UnsafeRawStringPointer())->clear();
    }
  }
  if (cached_has_bits & 28u) {
    ::memset(&version_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&value_) -
        reinterpret_cast<char*>(&version_)) + sizeof(value_));
  }
  clear_destination();
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool BlockchainTransactionOutput::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  ::google::protobuf::internal::LiteUnknownFieldSetter unknown_fields_setter(
      &_internal_metadata_);
  ::google::protobuf::io::StringOutputStream unknown_fields_output(
      unknown_fields_setter.buffer());
  ::google::protobuf::io::CodedOutputStream unknown_fields_stream(
      &unknown_fields_output, false);
  // @@protoc_insertion_point(parse_start:opentxs.proto.BlockchainTransactionOutput)
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

      // optional uint32 index = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {
          set_has_index();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &index_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional uint64 value = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(24u /* 24 & 0xFF */)) {
          set_has_value();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &value_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional bytes script = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(34u /* 34 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_script()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional .opentxs.proto.BlockchainWalletKey key = 5;
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(42u /* 42 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
               input, mutable_key()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional .opentxs.proto.BlockchainExternalAddress external = 6;
      case 6: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(50u /* 50 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
               input, mutable_external()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string confirmedspend = 7;
      case 7: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(58u /* 58 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_confirmedspend()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated string orphanedspend = 8;
      case 8: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(66u /* 66 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->add_orphanedspend()));
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
  // @@protoc_insertion_point(parse_success:opentxs.proto.BlockchainTransactionOutput)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:opentxs.proto.BlockchainTransactionOutput)
  return false;
#undef DO_
}

void BlockchainTransactionOutput::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:opentxs.proto.BlockchainTransactionOutput)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional uint32 version = 1;
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->version(), output);
  }

  // optional uint32 index = 2;
  if (cached_has_bits & 0x00000008u) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->index(), output);
  }

  // optional uint64 value = 3;
  if (cached_has_bits & 0x00000010u) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(3, this->value(), output);
  }

  // optional bytes script = 4;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      4, this->script(), output);
  }

  switch (destination_case()) {
    case kKey:
      ::google::protobuf::internal::WireFormatLite::WriteMessage(
        5, *destination_.key_, output);
      break;
    case kExternal:
      ::google::protobuf::internal::WireFormatLite::WriteMessage(
        6, *destination_.external_, output);
      break;
    default: ;
  }
  // optional string confirmedspend = 7;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      7, this->confirmedspend(), output);
  }

  // repeated string orphanedspend = 8;
  for (int i = 0, n = this->orphanedspend_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteString(
      8, this->orphanedspend(i), output);
  }

  output->WriteRaw(_internal_metadata_.unknown_fields().data(),
                   static_cast<int>(_internal_metadata_.unknown_fields().size()));
  // @@protoc_insertion_point(serialize_end:opentxs.proto.BlockchainTransactionOutput)
}

size_t BlockchainTransactionOutput::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:opentxs.proto.BlockchainTransactionOutput)
  size_t total_size = 0;

  total_size += _internal_metadata_.unknown_fields().size();

  // repeated string orphanedspend = 8;
  total_size += 1 *
      ::google::protobuf::internal::FromIntSize(this->orphanedspend_size());
  for (int i = 0, n = this->orphanedspend_size(); i < n; i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
      this->orphanedspend(i));
  }

  if (_has_bits_[0 / 32] & 31u) {
    // optional bytes script = 4;
    if (has_script()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->script());
    }

    // optional string confirmedspend = 7;
    if (has_confirmedspend()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->confirmedspend());
    }

    // optional uint32 version = 1;
    if (has_version()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->version());
    }

    // optional uint32 index = 2;
    if (has_index()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->index());
    }

    // optional uint64 value = 3;
    if (has_value()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->value());
    }

  }
  switch (destination_case()) {
    // optional .opentxs.proto.BlockchainWalletKey key = 5;
    case kKey: {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          *destination_.key_);
      break;
    }
    // optional .opentxs.proto.BlockchainExternalAddress external = 6;
    case kExternal: {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          *destination_.external_);
      break;
    }
    case DESTINATION_NOT_SET: {
      break;
    }
  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void BlockchainTransactionOutput::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const BlockchainTransactionOutput*>(&from));
}

void BlockchainTransactionOutput::MergeFrom(const BlockchainTransactionOutput& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:opentxs.proto.BlockchainTransactionOutput)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  orphanedspend_.MergeFrom(from.orphanedspend_);
  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 31u) {
    if (cached_has_bits & 0x00000001u) {
      set_has_script();
      script_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.script_);
    }
    if (cached_has_bits & 0x00000002u) {
      set_has_confirmedspend();
      confirmedspend_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.confirmedspend_);
    }
    if (cached_has_bits & 0x00000004u) {
      version_ = from.version_;
    }
    if (cached_has_bits & 0x00000008u) {
      index_ = from.index_;
    }
    if (cached_has_bits & 0x00000010u) {
      value_ = from.value_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
  switch (from.destination_case()) {
    case kKey: {
      mutable_key()->::opentxs::proto::BlockchainWalletKey::MergeFrom(from.key());
      break;
    }
    case kExternal: {
      mutable_external()->::opentxs::proto::BlockchainExternalAddress::MergeFrom(from.external());
      break;
    }
    case DESTINATION_NOT_SET: {
      break;
    }
  }
}

void BlockchainTransactionOutput::CopyFrom(const BlockchainTransactionOutput& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:opentxs.proto.BlockchainTransactionOutput)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool BlockchainTransactionOutput::IsInitialized() const {
  return true;
}

void BlockchainTransactionOutput::Swap(BlockchainTransactionOutput* other) {
  if (other == this) return;
  InternalSwap(other);
}
void BlockchainTransactionOutput::InternalSwap(BlockchainTransactionOutput* other) {
  using std::swap;
  orphanedspend_.InternalSwap(&other->orphanedspend_);
  script_.Swap(&other->script_);
  confirmedspend_.Swap(&other->confirmedspend_);
  swap(version_, other->version_);
  swap(index_, other->index_);
  swap(value_, other->value_);
  swap(destination_, other->destination_);
  swap(_oneof_case_[0], other->_oneof_case_[0]);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::std::string BlockchainTransactionOutput::GetTypeName() const {
  return "opentxs.proto.BlockchainTransactionOutput";
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace proto
}  // namespace opentxs

// @@protoc_insertion_point(global_scope)
