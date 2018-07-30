// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: StorageItemHash.proto

#include "StorageItemHash.pb.h"

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
class StorageItemHashDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<StorageItemHash>
      _instance;
} _StorageItemHash_default_instance_;
}  // namespace proto
}  // namespace opentxs
namespace protobuf_StorageItemHash_2eproto {
void InitDefaultsStorageItemHashImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  {
    void* ptr = &::opentxs::proto::_StorageItemHash_default_instance_;
    new (ptr) ::opentxs::proto::StorageItemHash();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::opentxs::proto::StorageItemHash::InitAsDefaultInstance();
}

void InitDefaultsStorageItemHash() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsStorageItemHashImpl);
}

}  // namespace protobuf_StorageItemHash_2eproto
namespace opentxs {
namespace proto {

// ===================================================================

void StorageItemHash::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int StorageItemHash::kVersionFieldNumber;
const int StorageItemHash::kItemIDFieldNumber;
const int StorageItemHash::kHashFieldNumber;
const int StorageItemHash::kAliasFieldNumber;
const int StorageItemHash::kTypeFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

StorageItemHash::StorageItemHash()
  : ::google::protobuf::MessageLite(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_StorageItemHash_2eproto::InitDefaultsStorageItemHash();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:opentxs.proto.StorageItemHash)
}
StorageItemHash::StorageItemHash(const StorageItemHash& from)
  : ::google::protobuf::MessageLite(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  itemid_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_itemid()) {
    itemid_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.itemid_);
  }
  hash_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_hash()) {
    hash_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.hash_);
  }
  alias_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_alias()) {
    alias_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.alias_);
  }
  ::memcpy(&version_, &from.version_,
    static_cast<size_t>(reinterpret_cast<char*>(&type_) -
    reinterpret_cast<char*>(&version_)) + sizeof(type_));
  // @@protoc_insertion_point(copy_constructor:opentxs.proto.StorageItemHash)
}

void StorageItemHash::SharedCtor() {
  _cached_size_ = 0;
  itemid_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  hash_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  alias_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&version_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&type_) -
      reinterpret_cast<char*>(&version_)) + sizeof(type_));
}

StorageItemHash::~StorageItemHash() {
  // @@protoc_insertion_point(destructor:opentxs.proto.StorageItemHash)
  SharedDtor();
}

void StorageItemHash::SharedDtor() {
  itemid_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  hash_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  alias_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void StorageItemHash::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const StorageItemHash& StorageItemHash::default_instance() {
  ::protobuf_StorageItemHash_2eproto::InitDefaultsStorageItemHash();
  return *internal_default_instance();
}

StorageItemHash* StorageItemHash::New(::google::protobuf::Arena* arena) const {
  StorageItemHash* n = new StorageItemHash;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void StorageItemHash::Clear() {
// @@protoc_insertion_point(message_clear_start:opentxs.proto.StorageItemHash)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 7u) {
    if (cached_has_bits & 0x00000001u) {
      GOOGLE_DCHECK(!itemid_.IsDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited()));
      (*itemid_.UnsafeRawStringPointer())->clear();
    }
    if (cached_has_bits & 0x00000002u) {
      GOOGLE_DCHECK(!hash_.IsDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited()));
      (*hash_.UnsafeRawStringPointer())->clear();
    }
    if (cached_has_bits & 0x00000004u) {
      GOOGLE_DCHECK(!alias_.IsDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited()));
      (*alias_.UnsafeRawStringPointer())->clear();
    }
  }
  if (cached_has_bits & 24u) {
    ::memset(&version_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&type_) -
        reinterpret_cast<char*>(&version_)) + sizeof(type_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool StorageItemHash::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  ::google::protobuf::internal::LiteUnknownFieldSetter unknown_fields_setter(
      &_internal_metadata_);
  ::google::protobuf::io::StringOutputStream unknown_fields_output(
      unknown_fields_setter.buffer());
  ::google::protobuf::io::CodedOutputStream unknown_fields_stream(
      &unknown_fields_output, false);
  // @@protoc_insertion_point(parse_start:opentxs.proto.StorageItemHash)
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

      // optional string itemID = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_itemid()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string hash = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_hash()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string alias = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(34u /* 34 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_alias()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional .opentxs.proto.StorageHashType type = 5;
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(40u /* 40 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::opentxs::proto::StorageHashType_IsValid(value)) {
            set_type(static_cast< ::opentxs::proto::StorageHashType >(value));
          } else {
            unknown_fields_stream.WriteVarint32(40u);
            unknown_fields_stream.WriteVarint32(
                static_cast< ::google::protobuf::uint32>(value));
          }
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
  // @@protoc_insertion_point(parse_success:opentxs.proto.StorageItemHash)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:opentxs.proto.StorageItemHash)
  return false;
#undef DO_
}

void StorageItemHash::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:opentxs.proto.StorageItemHash)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional uint32 version = 1;
  if (cached_has_bits & 0x00000008u) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->version(), output);
  }

  // optional string itemID = 2;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->itemid(), output);
  }

  // optional string hash = 3;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->hash(), output);
  }

  // optional string alias = 4;
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      4, this->alias(), output);
  }

  // optional .opentxs.proto.StorageHashType type = 5;
  if (cached_has_bits & 0x00000010u) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      5, this->type(), output);
  }

  output->WriteRaw(_internal_metadata_.unknown_fields().data(),
                   static_cast<int>(_internal_metadata_.unknown_fields().size()));
  // @@protoc_insertion_point(serialize_end:opentxs.proto.StorageItemHash)
}

size_t StorageItemHash::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:opentxs.proto.StorageItemHash)
  size_t total_size = 0;

  total_size += _internal_metadata_.unknown_fields().size();

  if (_has_bits_[0 / 32] & 31u) {
    // optional string itemID = 2;
    if (has_itemid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->itemid());
    }

    // optional string hash = 3;
    if (has_hash()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->hash());
    }

    // optional string alias = 4;
    if (has_alias()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->alias());
    }

    // optional uint32 version = 1;
    if (has_version()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->version());
    }

    // optional .opentxs.proto.StorageHashType type = 5;
    if (has_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->type());
    }

  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void StorageItemHash::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const StorageItemHash*>(&from));
}

void StorageItemHash::MergeFrom(const StorageItemHash& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:opentxs.proto.StorageItemHash)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 31u) {
    if (cached_has_bits & 0x00000001u) {
      set_has_itemid();
      itemid_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.itemid_);
    }
    if (cached_has_bits & 0x00000002u) {
      set_has_hash();
      hash_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.hash_);
    }
    if (cached_has_bits & 0x00000004u) {
      set_has_alias();
      alias_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.alias_);
    }
    if (cached_has_bits & 0x00000008u) {
      version_ = from.version_;
    }
    if (cached_has_bits & 0x00000010u) {
      type_ = from.type_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void StorageItemHash::CopyFrom(const StorageItemHash& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:opentxs.proto.StorageItemHash)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool StorageItemHash::IsInitialized() const {
  return true;
}

void StorageItemHash::Swap(StorageItemHash* other) {
  if (other == this) return;
  InternalSwap(other);
}
void StorageItemHash::InternalSwap(StorageItemHash* other) {
  using std::swap;
  itemid_.Swap(&other->itemid_);
  hash_.Swap(&other->hash_);
  alias_.Swap(&other->alias_);
  swap(version_, other->version_);
  swap(type_, other->type_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::std::string StorageItemHash::GetTypeName() const {
  return "opentxs.proto.StorageItemHash";
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace proto
}  // namespace opentxs

// @@protoc_insertion_point(global_scope)
