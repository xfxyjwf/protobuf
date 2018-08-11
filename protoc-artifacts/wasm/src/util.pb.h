// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: util.proto

#ifndef PROTOBUF_INCLUDED_util_2eproto
#define PROTOBUF_INCLUDED_util_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/map.h>  // IWYU pragma: export
#include <google/protobuf/map_entry.h>
#include <google/protobuf/map_field_inl.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_util_2eproto 

namespace protobuf_util_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[4];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_util_2eproto
namespace google {
namespace protobuf {
namespace compiler {
namespace wasm {
namespace util {
class GeneratorInput;
class GeneratorInputDefaultTypeInternal;
extern GeneratorInputDefaultTypeInternal _GeneratorInput_default_instance_;
class GeneratorOutput;
class GeneratorOutputDefaultTypeInternal;
extern GeneratorOutputDefaultTypeInternal _GeneratorOutput_default_instance_;
class GeneratorOutput_FilesEntry_DoNotUse;
class GeneratorOutput_FilesEntry_DoNotUseDefaultTypeInternal;
extern GeneratorOutput_FilesEntry_DoNotUseDefaultTypeInternal _GeneratorOutput_FilesEntry_DoNotUse_default_instance_;
class LanguageList;
class LanguageListDefaultTypeInternal;
extern LanguageListDefaultTypeInternal _LanguageList_default_instance_;
}  // namespace util
}  // namespace wasm
}  // namespace compiler
}  // namespace protobuf
}  // namespace google
namespace google {
namespace protobuf {
template<> ::google::protobuf::compiler::wasm::util::GeneratorInput* Arena::CreateMaybeMessage<::google::protobuf::compiler::wasm::util::GeneratorInput>(Arena*);
template<> ::google::protobuf::compiler::wasm::util::GeneratorOutput* Arena::CreateMaybeMessage<::google::protobuf::compiler::wasm::util::GeneratorOutput>(Arena*);
template<> ::google::protobuf::compiler::wasm::util::GeneratorOutput_FilesEntry_DoNotUse* Arena::CreateMaybeMessage<::google::protobuf::compiler::wasm::util::GeneratorOutput_FilesEntry_DoNotUse>(Arena*);
template<> ::google::protobuf::compiler::wasm::util::LanguageList* Arena::CreateMaybeMessage<::google::protobuf::compiler::wasm::util::LanguageList>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace google {
namespace protobuf {
namespace compiler {
namespace wasm {
namespace util {

// ===================================================================

class GeneratorInput : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:google.protobuf.compiler.wasm.util.GeneratorInput) */ {
 public:
  GeneratorInput();
  virtual ~GeneratorInput();

  GeneratorInput(const GeneratorInput& from);

  inline GeneratorInput& operator=(const GeneratorInput& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  GeneratorInput(GeneratorInput&& from) noexcept
    : GeneratorInput() {
    *this = ::std::move(from);
  }

  inline GeneratorInput& operator=(GeneratorInput&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const GeneratorInput& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const GeneratorInput* internal_default_instance() {
    return reinterpret_cast<const GeneratorInput*>(
               &_GeneratorInput_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(GeneratorInput* other);
  friend void swap(GeneratorInput& a, GeneratorInput& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline GeneratorInput* New() const final {
    return CreateMaybeMessage<GeneratorInput>(NULL);
  }

  GeneratorInput* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<GeneratorInput>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const GeneratorInput& from);
  void MergeFrom(const GeneratorInput& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(GeneratorInput* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string name = 1;
  void clear_name();
  static const int kNameFieldNumber = 1;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // string content = 2;
  void clear_content();
  static const int kContentFieldNumber = 2;
  const ::std::string& content() const;
  void set_content(const ::std::string& value);
  #if LANG_CXX11
  void set_content(::std::string&& value);
  #endif
  void set_content(const char* value);
  void set_content(const char* value, size_t size);
  ::std::string* mutable_content();
  ::std::string* release_content();
  void set_allocated_content(::std::string* content);

  // string language = 3;
  void clear_language();
  static const int kLanguageFieldNumber = 3;
  const ::std::string& language() const;
  void set_language(const ::std::string& value);
  #if LANG_CXX11
  void set_language(::std::string&& value);
  #endif
  void set_language(const char* value);
  void set_language(const char* value, size_t size);
  ::std::string* mutable_language();
  ::std::string* release_language();
  void set_allocated_language(::std::string* language);

  // string parameters = 4;
  void clear_parameters();
  static const int kParametersFieldNumber = 4;
  const ::std::string& parameters() const;
  void set_parameters(const ::std::string& value);
  #if LANG_CXX11
  void set_parameters(::std::string&& value);
  #endif
  void set_parameters(const char* value);
  void set_parameters(const char* value, size_t size);
  ::std::string* mutable_parameters();
  ::std::string* release_parameters();
  void set_allocated_parameters(::std::string* parameters);

  // @@protoc_insertion_point(class_scope:google.protobuf.compiler.wasm.util.GeneratorInput)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::internal::ArenaStringPtr content_;
  ::google::protobuf::internal::ArenaStringPtr language_;
  ::google::protobuf::internal::ArenaStringPtr parameters_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_util_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class GeneratorOutput_FilesEntry_DoNotUse : public ::google::protobuf::internal::MapEntry<GeneratorOutput_FilesEntry_DoNotUse, 
    ::std::string, ::std::string,
    ::google::protobuf::internal::WireFormatLite::TYPE_STRING,
    ::google::protobuf::internal::WireFormatLite::TYPE_STRING,
    0 > {
public:
  typedef ::google::protobuf::internal::MapEntry<GeneratorOutput_FilesEntry_DoNotUse, 
    ::std::string, ::std::string,
    ::google::protobuf::internal::WireFormatLite::TYPE_STRING,
    ::google::protobuf::internal::WireFormatLite::TYPE_STRING,
    0 > SuperType;
  GeneratorOutput_FilesEntry_DoNotUse();
  GeneratorOutput_FilesEntry_DoNotUse(::google::protobuf::Arena* arena);
  void MergeFrom(const GeneratorOutput_FilesEntry_DoNotUse& other);
  static const GeneratorOutput_FilesEntry_DoNotUse* internal_default_instance() { return reinterpret_cast<const GeneratorOutput_FilesEntry_DoNotUse*>(&_GeneratorOutput_FilesEntry_DoNotUse_default_instance_); }
  void MergeFrom(const ::google::protobuf::Message& other) final;
  ::google::protobuf::Metadata GetMetadata() const;
};

// -------------------------------------------------------------------

class GeneratorOutput : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:google.protobuf.compiler.wasm.util.GeneratorOutput) */ {
 public:
  GeneratorOutput();
  virtual ~GeneratorOutput();

  GeneratorOutput(const GeneratorOutput& from);

  inline GeneratorOutput& operator=(const GeneratorOutput& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  GeneratorOutput(GeneratorOutput&& from) noexcept
    : GeneratorOutput() {
    *this = ::std::move(from);
  }

  inline GeneratorOutput& operator=(GeneratorOutput&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const GeneratorOutput& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const GeneratorOutput* internal_default_instance() {
    return reinterpret_cast<const GeneratorOutput*>(
               &_GeneratorOutput_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(GeneratorOutput* other);
  friend void swap(GeneratorOutput& a, GeneratorOutput& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline GeneratorOutput* New() const final {
    return CreateMaybeMessage<GeneratorOutput>(NULL);
  }

  GeneratorOutput* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<GeneratorOutput>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const GeneratorOutput& from);
  void MergeFrom(const GeneratorOutput& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(GeneratorOutput* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------


  // accessors -------------------------------------------------------

  // map<string, string> files = 2;
  int files_size() const;
  void clear_files();
  static const int kFilesFieldNumber = 2;
  const ::google::protobuf::Map< ::std::string, ::std::string >&
      files() const;
  ::google::protobuf::Map< ::std::string, ::std::string >*
      mutable_files();

  // string error = 1;
  void clear_error();
  static const int kErrorFieldNumber = 1;
  const ::std::string& error() const;
  void set_error(const ::std::string& value);
  #if LANG_CXX11
  void set_error(::std::string&& value);
  #endif
  void set_error(const char* value);
  void set_error(const char* value, size_t size);
  ::std::string* mutable_error();
  ::std::string* release_error();
  void set_allocated_error(::std::string* error);

  // @@protoc_insertion_point(class_scope:google.protobuf.compiler.wasm.util.GeneratorOutput)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::MapField<
      GeneratorOutput_FilesEntry_DoNotUse,
      ::std::string, ::std::string,
      ::google::protobuf::internal::WireFormatLite::TYPE_STRING,
      ::google::protobuf::internal::WireFormatLite::TYPE_STRING,
      0 > files_;
  ::google::protobuf::internal::ArenaStringPtr error_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_util_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class LanguageList : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:google.protobuf.compiler.wasm.util.LanguageList) */ {
 public:
  LanguageList();
  virtual ~LanguageList();

  LanguageList(const LanguageList& from);

  inline LanguageList& operator=(const LanguageList& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  LanguageList(LanguageList&& from) noexcept
    : LanguageList() {
    *this = ::std::move(from);
  }

  inline LanguageList& operator=(LanguageList&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const LanguageList& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const LanguageList* internal_default_instance() {
    return reinterpret_cast<const LanguageList*>(
               &_LanguageList_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    3;

  void Swap(LanguageList* other);
  friend void swap(LanguageList& a, LanguageList& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline LanguageList* New() const final {
    return CreateMaybeMessage<LanguageList>(NULL);
  }

  LanguageList* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<LanguageList>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const LanguageList& from);
  void MergeFrom(const LanguageList& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(LanguageList* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated string languages = 1;
  int languages_size() const;
  void clear_languages();
  static const int kLanguagesFieldNumber = 1;
  const ::std::string& languages(int index) const;
  ::std::string* mutable_languages(int index);
  void set_languages(int index, const ::std::string& value);
  #if LANG_CXX11
  void set_languages(int index, ::std::string&& value);
  #endif
  void set_languages(int index, const char* value);
  void set_languages(int index, const char* value, size_t size);
  ::std::string* add_languages();
  void add_languages(const ::std::string& value);
  #if LANG_CXX11
  void add_languages(::std::string&& value);
  #endif
  void add_languages(const char* value);
  void add_languages(const char* value, size_t size);
  const ::google::protobuf::RepeatedPtrField< ::std::string>& languages() const;
  ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_languages();

  // @@protoc_insertion_point(class_scope:google.protobuf.compiler.wasm.util.LanguageList)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::std::string> languages_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_util_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// GeneratorInput

// string name = 1;
inline void GeneratorInput::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& GeneratorInput::name() const {
  // @@protoc_insertion_point(field_get:google.protobuf.compiler.wasm.util.GeneratorInput.name)
  return name_.GetNoArena();
}
inline void GeneratorInput::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:google.protobuf.compiler.wasm.util.GeneratorInput.name)
}
#if LANG_CXX11
inline void GeneratorInput::set_name(::std::string&& value) {
  
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:google.protobuf.compiler.wasm.util.GeneratorInput.name)
}
#endif
inline void GeneratorInput::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:google.protobuf.compiler.wasm.util.GeneratorInput.name)
}
inline void GeneratorInput::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:google.protobuf.compiler.wasm.util.GeneratorInput.name)
}
inline ::std::string* GeneratorInput::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:google.protobuf.compiler.wasm.util.GeneratorInput.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* GeneratorInput::release_name() {
  // @@protoc_insertion_point(field_release:google.protobuf.compiler.wasm.util.GeneratorInput.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void GeneratorInput::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:google.protobuf.compiler.wasm.util.GeneratorInput.name)
}

// string content = 2;
inline void GeneratorInput::clear_content() {
  content_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& GeneratorInput::content() const {
  // @@protoc_insertion_point(field_get:google.protobuf.compiler.wasm.util.GeneratorInput.content)
  return content_.GetNoArena();
}
inline void GeneratorInput::set_content(const ::std::string& value) {
  
  content_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:google.protobuf.compiler.wasm.util.GeneratorInput.content)
}
#if LANG_CXX11
inline void GeneratorInput::set_content(::std::string&& value) {
  
  content_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:google.protobuf.compiler.wasm.util.GeneratorInput.content)
}
#endif
inline void GeneratorInput::set_content(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  content_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:google.protobuf.compiler.wasm.util.GeneratorInput.content)
}
inline void GeneratorInput::set_content(const char* value, size_t size) {
  
  content_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:google.protobuf.compiler.wasm.util.GeneratorInput.content)
}
inline ::std::string* GeneratorInput::mutable_content() {
  
  // @@protoc_insertion_point(field_mutable:google.protobuf.compiler.wasm.util.GeneratorInput.content)
  return content_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* GeneratorInput::release_content() {
  // @@protoc_insertion_point(field_release:google.protobuf.compiler.wasm.util.GeneratorInput.content)
  
  return content_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void GeneratorInput::set_allocated_content(::std::string* content) {
  if (content != NULL) {
    
  } else {
    
  }
  content_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), content);
  // @@protoc_insertion_point(field_set_allocated:google.protobuf.compiler.wasm.util.GeneratorInput.content)
}

// string language = 3;
inline void GeneratorInput::clear_language() {
  language_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& GeneratorInput::language() const {
  // @@protoc_insertion_point(field_get:google.protobuf.compiler.wasm.util.GeneratorInput.language)
  return language_.GetNoArena();
}
inline void GeneratorInput::set_language(const ::std::string& value) {
  
  language_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:google.protobuf.compiler.wasm.util.GeneratorInput.language)
}
#if LANG_CXX11
inline void GeneratorInput::set_language(::std::string&& value) {
  
  language_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:google.protobuf.compiler.wasm.util.GeneratorInput.language)
}
#endif
inline void GeneratorInput::set_language(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  language_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:google.protobuf.compiler.wasm.util.GeneratorInput.language)
}
inline void GeneratorInput::set_language(const char* value, size_t size) {
  
  language_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:google.protobuf.compiler.wasm.util.GeneratorInput.language)
}
inline ::std::string* GeneratorInput::mutable_language() {
  
  // @@protoc_insertion_point(field_mutable:google.protobuf.compiler.wasm.util.GeneratorInput.language)
  return language_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* GeneratorInput::release_language() {
  // @@protoc_insertion_point(field_release:google.protobuf.compiler.wasm.util.GeneratorInput.language)
  
  return language_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void GeneratorInput::set_allocated_language(::std::string* language) {
  if (language != NULL) {
    
  } else {
    
  }
  language_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), language);
  // @@protoc_insertion_point(field_set_allocated:google.protobuf.compiler.wasm.util.GeneratorInput.language)
}

// string parameters = 4;
inline void GeneratorInput::clear_parameters() {
  parameters_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& GeneratorInput::parameters() const {
  // @@protoc_insertion_point(field_get:google.protobuf.compiler.wasm.util.GeneratorInput.parameters)
  return parameters_.GetNoArena();
}
inline void GeneratorInput::set_parameters(const ::std::string& value) {
  
  parameters_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:google.protobuf.compiler.wasm.util.GeneratorInput.parameters)
}
#if LANG_CXX11
inline void GeneratorInput::set_parameters(::std::string&& value) {
  
  parameters_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:google.protobuf.compiler.wasm.util.GeneratorInput.parameters)
}
#endif
inline void GeneratorInput::set_parameters(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  parameters_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:google.protobuf.compiler.wasm.util.GeneratorInput.parameters)
}
inline void GeneratorInput::set_parameters(const char* value, size_t size) {
  
  parameters_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:google.protobuf.compiler.wasm.util.GeneratorInput.parameters)
}
inline ::std::string* GeneratorInput::mutable_parameters() {
  
  // @@protoc_insertion_point(field_mutable:google.protobuf.compiler.wasm.util.GeneratorInput.parameters)
  return parameters_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* GeneratorInput::release_parameters() {
  // @@protoc_insertion_point(field_release:google.protobuf.compiler.wasm.util.GeneratorInput.parameters)
  
  return parameters_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void GeneratorInput::set_allocated_parameters(::std::string* parameters) {
  if (parameters != NULL) {
    
  } else {
    
  }
  parameters_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), parameters);
  // @@protoc_insertion_point(field_set_allocated:google.protobuf.compiler.wasm.util.GeneratorInput.parameters)
}

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// GeneratorOutput

// string error = 1;
inline void GeneratorOutput::clear_error() {
  error_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& GeneratorOutput::error() const {
  // @@protoc_insertion_point(field_get:google.protobuf.compiler.wasm.util.GeneratorOutput.error)
  return error_.GetNoArena();
}
inline void GeneratorOutput::set_error(const ::std::string& value) {
  
  error_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:google.protobuf.compiler.wasm.util.GeneratorOutput.error)
}
#if LANG_CXX11
inline void GeneratorOutput::set_error(::std::string&& value) {
  
  error_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:google.protobuf.compiler.wasm.util.GeneratorOutput.error)
}
#endif
inline void GeneratorOutput::set_error(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  error_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:google.protobuf.compiler.wasm.util.GeneratorOutput.error)
}
inline void GeneratorOutput::set_error(const char* value, size_t size) {
  
  error_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:google.protobuf.compiler.wasm.util.GeneratorOutput.error)
}
inline ::std::string* GeneratorOutput::mutable_error() {
  
  // @@protoc_insertion_point(field_mutable:google.protobuf.compiler.wasm.util.GeneratorOutput.error)
  return error_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* GeneratorOutput::release_error() {
  // @@protoc_insertion_point(field_release:google.protobuf.compiler.wasm.util.GeneratorOutput.error)
  
  return error_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void GeneratorOutput::set_allocated_error(::std::string* error) {
  if (error != NULL) {
    
  } else {
    
  }
  error_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), error);
  // @@protoc_insertion_point(field_set_allocated:google.protobuf.compiler.wasm.util.GeneratorOutput.error)
}

// map<string, string> files = 2;
inline int GeneratorOutput::files_size() const {
  return files_.size();
}
inline void GeneratorOutput::clear_files() {
  files_.Clear();
}
inline const ::google::protobuf::Map< ::std::string, ::std::string >&
GeneratorOutput::files() const {
  // @@protoc_insertion_point(field_map:google.protobuf.compiler.wasm.util.GeneratorOutput.files)
  return files_.GetMap();
}
inline ::google::protobuf::Map< ::std::string, ::std::string >*
GeneratorOutput::mutable_files() {
  // @@protoc_insertion_point(field_mutable_map:google.protobuf.compiler.wasm.util.GeneratorOutput.files)
  return files_.MutableMap();
}

// -------------------------------------------------------------------

// LanguageList

// repeated string languages = 1;
inline int LanguageList::languages_size() const {
  return languages_.size();
}
inline void LanguageList::clear_languages() {
  languages_.Clear();
}
inline const ::std::string& LanguageList::languages(int index) const {
  // @@protoc_insertion_point(field_get:google.protobuf.compiler.wasm.util.LanguageList.languages)
  return languages_.Get(index);
}
inline ::std::string* LanguageList::mutable_languages(int index) {
  // @@protoc_insertion_point(field_mutable:google.protobuf.compiler.wasm.util.LanguageList.languages)
  return languages_.Mutable(index);
}
inline void LanguageList::set_languages(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:google.protobuf.compiler.wasm.util.LanguageList.languages)
  languages_.Mutable(index)->assign(value);
}
#if LANG_CXX11
inline void LanguageList::set_languages(int index, ::std::string&& value) {
  // @@protoc_insertion_point(field_set:google.protobuf.compiler.wasm.util.LanguageList.languages)
  languages_.Mutable(index)->assign(std::move(value));
}
#endif
inline void LanguageList::set_languages(int index, const char* value) {
  GOOGLE_DCHECK(value != NULL);
  languages_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:google.protobuf.compiler.wasm.util.LanguageList.languages)
}
inline void LanguageList::set_languages(int index, const char* value, size_t size) {
  languages_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:google.protobuf.compiler.wasm.util.LanguageList.languages)
}
inline ::std::string* LanguageList::add_languages() {
  // @@protoc_insertion_point(field_add_mutable:google.protobuf.compiler.wasm.util.LanguageList.languages)
  return languages_.Add();
}
inline void LanguageList::add_languages(const ::std::string& value) {
  languages_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:google.protobuf.compiler.wasm.util.LanguageList.languages)
}
#if LANG_CXX11
inline void LanguageList::add_languages(::std::string&& value) {
  languages_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:google.protobuf.compiler.wasm.util.LanguageList.languages)
}
#endif
inline void LanguageList::add_languages(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  languages_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:google.protobuf.compiler.wasm.util.LanguageList.languages)
}
inline void LanguageList::add_languages(const char* value, size_t size) {
  languages_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:google.protobuf.compiler.wasm.util.LanguageList.languages)
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
LanguageList::languages() const {
  // @@protoc_insertion_point(field_list:google.protobuf.compiler.wasm.util.LanguageList.languages)
  return languages_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
LanguageList::mutable_languages() {
  // @@protoc_insertion_point(field_mutable_list:google.protobuf.compiler.wasm.util.LanguageList.languages)
  return &languages_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace util
}  // namespace wasm
}  // namespace compiler
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_util_2eproto
