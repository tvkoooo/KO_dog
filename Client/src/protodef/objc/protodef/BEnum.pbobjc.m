// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: b_enum.proto

// This CPP symbol can be defined to use imports that match up to the framework
// imports needed when using CocoaPods.
#if !defined(GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS)
 #define GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS 0
#endif

#if GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS
 #import <Protobuf/GPBProtocolBuffers_RuntimeSupport.h>
#else
 #import "GPBProtocolBuffers_RuntimeSupport.h"
#endif

 #import "BEnum.pbobjc.h"
// @@protoc_insertion_point(imports)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

#pragma mark - B_enum_BEnumRoot

@implementation B_enum_BEnumRoot

// No extensions in the file and no imports, so no need to generate
// +extensionRegistry.

@end

#pragma mark - Enum B_enum_reply_t

GPBEnumDescriptor *B_enum_reply_t_EnumDescriptor(void) {
  static GPBEnumDescriptor *descriptor = NULL;
  if (!descriptor) {
    static const char *valueNames =
        "Accept\000Refuse\000";
    static const int32_t values[] = {
        B_enum_reply_t_Accept,
        B_enum_reply_t_Refuse,
    };
    static const char *extraTextFormatInfo = "\002\000&\000\001&\000";
    GPBEnumDescriptor *worker =
        [GPBEnumDescriptor allocDescriptorForName:GPBNSStringifySymbol(B_enum_reply_t)
                                       valueNames:valueNames
                                           values:values
                                            count:(uint32_t)(sizeof(values) / sizeof(int32_t))
                                     enumVerifier:B_enum_reply_t_IsValidValue
                              extraTextFormatInfo:extraTextFormatInfo];
    if (!OSAtomicCompareAndSwapPtrBarrier(nil, worker, (void * volatile *)&descriptor)) {
      [worker release];
    }
  }
  return descriptor;
}

BOOL B_enum_reply_t_IsValidValue(int32_t value__) {
  switch (value__) {
    case B_enum_reply_t_Accept:
    case B_enum_reply_t_Refuse:
      return YES;
    default:
      return NO;
  }
}

#pragma mark - Enum B_enum_operate_t

GPBEnumDescriptor *B_enum_operate_t_EnumDescriptor(void) {
  static GPBEnumDescriptor *descriptor = NULL;
  if (!descriptor) {
    static const char *valueNames =
        "Ensure\000Cancel\000";
    static const int32_t values[] = {
        B_enum_operate_t_Ensure,
        B_enum_operate_t_Cancel,
    };
    static const char *extraTextFormatInfo = "\002\000&\000\001&\000";
    GPBEnumDescriptor *worker =
        [GPBEnumDescriptor allocDescriptorForName:GPBNSStringifySymbol(B_enum_operate_t)
                                       valueNames:valueNames
                                           values:values
                                            count:(uint32_t)(sizeof(values) / sizeof(int32_t))
                                     enumVerifier:B_enum_operate_t_IsValidValue
                              extraTextFormatInfo:extraTextFormatInfo];
    if (!OSAtomicCompareAndSwapPtrBarrier(nil, worker, (void * volatile *)&descriptor)) {
      [worker release];
    }
  }
  return descriptor;
}

BOOL B_enum_operate_t_IsValidValue(int32_t value__) {
  switch (value__) {
    case B_enum_operate_t_Ensure:
    case B_enum_operate_t_Cancel:
      return YES;
    default:
      return NO;
  }
}

#pragma mark - Enum B_enum_opcode_t

GPBEnumDescriptor *B_enum_opcode_t_EnumDescriptor(void) {
  static GPBEnumDescriptor *descriptor = NULL;
  if (!descriptor) {
    static const char *valueNames =
        "Assign\000Update\000Insert\000Remove\000Delete\000";
    static const int32_t values[] = {
        B_enum_opcode_t_Assign,
        B_enum_opcode_t_Update,
        B_enum_opcode_t_Insert,
        B_enum_opcode_t_Remove,
        B_enum_opcode_t_Delete,
    };
    static const char *extraTextFormatInfo = "\005\000&\000\001&\000\002&\000\003&\000\004&\000";
    GPBEnumDescriptor *worker =
        [GPBEnumDescriptor allocDescriptorForName:GPBNSStringifySymbol(B_enum_opcode_t)
                                       valueNames:valueNames
                                           values:values
                                            count:(uint32_t)(sizeof(values) / sizeof(int32_t))
                                     enumVerifier:B_enum_opcode_t_IsValidValue
                              extraTextFormatInfo:extraTextFormatInfo];
    if (!OSAtomicCompareAndSwapPtrBarrier(nil, worker, (void * volatile *)&descriptor)) {
      [worker release];
    }
  }
  return descriptor;
}

BOOL B_enum_opcode_t_IsValidValue(int32_t value__) {
  switch (value__) {
    case B_enum_opcode_t_Assign:
    case B_enum_opcode_t_Update:
    case B_enum_opcode_t_Insert:
    case B_enum_opcode_t_Remove:
    case B_enum_opcode_t_Delete:
      return YES;
    default:
      return NO;
  }
}


#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)