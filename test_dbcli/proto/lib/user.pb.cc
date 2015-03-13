// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: user.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "user.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace db_proto {

namespace {

const ::google::protobuf::Descriptor* MUser_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MUser_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_user_2eproto() {
  protobuf_AddDesc_user_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "user.proto");
  GOOGLE_CHECK(file != NULL);
  MUser_descriptor_ = file->message_type(0);
  static const int MUser_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MUser, userid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MUser, name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MUser, score_),
  };
  MUser_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      MUser_descriptor_,
      MUser::default_instance_,
      MUser_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MUser, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MUser, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(MUser));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_user_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    MUser_descriptor_, &MUser::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_user_2eproto() {
  delete MUser::default_instance_;
  delete MUser_reflection_;
}

void protobuf_AddDesc_user_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\nuser.proto\022\010db_proto\"4\n\005MUser\022\016\n\006useri"
    "d\030\001 \002(\r\022\014\n\004name\030\002 \002(\t\022\r\n\005score\030\003 \001(\r", 76);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "user.proto", &protobuf_RegisterTypes);
  MUser::default_instance_ = new MUser();
  MUser::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_user_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_user_2eproto {
  StaticDescriptorInitializer_user_2eproto() {
    protobuf_AddDesc_user_2eproto();
  }
} static_descriptor_initializer_user_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int MUser::kUseridFieldNumber;
const int MUser::kNameFieldNumber;
const int MUser::kScoreFieldNumber;
#endif  // !_MSC_VER

MUser::MUser()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:db_proto.MUser)
}

void MUser::InitAsDefaultInstance() {
}

MUser::MUser(const MUser& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:db_proto.MUser)
}

void MUser::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  userid_ = 0u;
  name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  score_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

MUser::~MUser() {
  // @@protoc_insertion_point(destructor:db_proto.MUser)
  SharedDtor();
}

void MUser::SharedDtor() {
  if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete name_;
  }
  if (this != default_instance_) {
  }
}

void MUser::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MUser::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MUser_descriptor_;
}

const MUser& MUser::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_user_2eproto();
  return *default_instance_;
}

MUser* MUser::default_instance_ = NULL;

MUser* MUser::New() const {
  return new MUser;
}

void MUser::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<MUser*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 7) {
    ZR_(userid_, score_);
    if (has_name()) {
      if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        name_->clear();
      }
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool MUser::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:db_proto.MUser)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 userid = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &userid_)));
          set_has_userid();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_name;
        break;
      }

      // required string name = 2;
      case 2: {
        if (tag == 18) {
         parse_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->name().data(), this->name().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "name");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_score;
        break;
      }

      // optional uint32 score = 3;
      case 3: {
        if (tag == 24) {
         parse_score:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &score_)));
          set_has_score();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:db_proto.MUser)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:db_proto.MUser)
  return false;
#undef DO_
}

void MUser::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:db_proto.MUser)
  // required uint32 userid = 1;
  if (has_userid()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->userid(), output);
  }

  // required string name = 2;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->name(), output);
  }

  // optional uint32 score = 3;
  if (has_score()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->score(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:db_proto.MUser)
}

::google::protobuf::uint8* MUser::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:db_proto.MUser)
  // required uint32 userid = 1;
  if (has_userid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->userid(), target);
  }

  // required string name = 2;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->name(), target);
  }

  // optional uint32 score = 3;
  if (has_score()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->score(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:db_proto.MUser)
  return target;
}

int MUser::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 userid = 1;
    if (has_userid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->userid());
    }

    // required string name = 2;
    if (has_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->name());
    }

    // optional uint32 score = 3;
    if (has_score()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->score());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void MUser::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const MUser* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const MUser*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MUser::MergeFrom(const MUser& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_userid()) {
      set_userid(from.userid());
    }
    if (from.has_name()) {
      set_name(from.name());
    }
    if (from.has_score()) {
      set_score(from.score());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void MUser::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MUser::CopyFrom(const MUser& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MUser::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void MUser::Swap(MUser* other) {
  if (other != this) {
    std::swap(userid_, other->userid_);
    std::swap(name_, other->name_);
    std::swap(score_, other->score_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata MUser::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MUser_descriptor_;
  metadata.reflection = MUser_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace db_proto

// @@protoc_insertion_point(global_scope)
