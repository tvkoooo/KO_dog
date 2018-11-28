// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: s_basis.proto

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

 #import "SBasis.pbobjc.h"
 #import "BMath.pbobjc.h"
// @@protoc_insertion_point(imports)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

#pragma mark - S_basisSBasisRoot

@implementation S_basisSBasisRoot

// No extensions in the file and none of the imports (direct or indirect)
// defined extensions, so no need to generate +extensionRegistry.

@end

#pragma mark - S_basisSBasisRoot_FileDescriptor

static GPBFileDescriptor *S_basisSBasisRoot_FileDescriptor(void) {
  // This is called by +initialize so there is no need to worry
  // about thread safety of the singleton.
  static GPBFileDescriptor *descriptor = NULL;
  if (!descriptor) {
    GPB_DEBUG_CHECK_RUNTIME_VERSIONS();
    descriptor = [[GPBFileDescriptor alloc] initWithPackage:@"s_basis"
                                                 objcPrefix:@"S_basis"
                                                     syntax:GPBFileSyntaxProto2];
  }
  return descriptor;
}

#pragma mark - Enum S_basismsg

GPBEnumDescriptor *S_basismsg_EnumDescriptor(void) {
  static GPBEnumDescriptor *descriptor = NULL;
  if (!descriptor) {
    static const char *valueNames =
        "MinId\000MaxId\000";
    static const int32_t values[] = {
        S_basismsg_MinId,
        S_basismsg_MaxId,
    };
    static const char *extraTextFormatInfo = "\002\000#\242\000\001#\242\000";
    GPBEnumDescriptor *worker =
        [GPBEnumDescriptor allocDescriptorForName:GPBNSStringifySymbol(S_basismsg)
                                       valueNames:valueNames
                                           values:values
                                            count:(uint32_t)(sizeof(values) / sizeof(int32_t))
                                     enumVerifier:S_basismsg_IsValidValue
                              extraTextFormatInfo:extraTextFormatInfo];
    if (!OSAtomicCompareAndSwapPtrBarrier(nil, worker, (void * volatile *)&descriptor)) {
      [worker release];
    }
  }
  return descriptor;
}

BOOL S_basismsg_IsValidValue(int32_t value__) {
  switch (value__) {
    case S_basismsg_MinId:
    case S_basismsg_MaxId:
      return YES;
    default:
      return NO;
  }
}

#pragma mark - S_basisheartbeat_ev

@implementation S_basisheartbeat_ev

@dynamic hasEventTime, eventTime;
@dynamic hasUid, uid;
@dynamic hasTimecodeNative, timecodeNative;
@dynamic hasCoordInfo, coordInfo;

typedef struct S_basisheartbeat_ev__storage_ {
  uint32_t _has_storage_[1];
  B_math_coord *coordInfo;
  uint64_t eventTime;
  uint64_t uid;
  uint64_t timecodeNative;
} S_basisheartbeat_ev__storage_;

// This method is threadsafe because it is initially called
// in +initialize for each subclass.
+ (GPBDescriptor *)descriptor {
  static GPBDescriptor *descriptor = nil;
  if (!descriptor) {
    static GPBMessageFieldDescription fields[] = {
      {
        .name = "eventTime",
        .dataTypeSpecific.className = NULL,
        .number = S_basisheartbeat_ev_FieldNumber_EventTime,
        .hasIndex = 0,
        .offset = (uint32_t)offsetof(S_basisheartbeat_ev__storage_, eventTime),
        .flags = (GPBFieldFlags)(GPBFieldRequired | GPBFieldHasDefaultValue),
        .dataType = GPBDataTypeUInt64,
      },
      {
        .name = "uid",
        .dataTypeSpecific.className = NULL,
        .number = S_basisheartbeat_ev_FieldNumber_Uid,
        .hasIndex = 1,
        .offset = (uint32_t)offsetof(S_basisheartbeat_ev__storage_, uid),
        .flags = (GPBFieldFlags)(GPBFieldRequired | GPBFieldHasDefaultValue),
        .dataType = GPBDataTypeUInt64,
      },
      {
        .name = "timecodeNative",
        .dataTypeSpecific.className = NULL,
        .number = S_basisheartbeat_ev_FieldNumber_TimecodeNative,
        .hasIndex = 2,
        .offset = (uint32_t)offsetof(S_basisheartbeat_ev__storage_, timecodeNative),
        .flags = (GPBFieldFlags)(GPBFieldRequired | GPBFieldHasDefaultValue),
        .dataType = GPBDataTypeUInt64,
      },
      {
        .name = "coordInfo",
        .dataTypeSpecific.className = GPBStringifySymbol(B_math_coord),
        .number = S_basisheartbeat_ev_FieldNumber_CoordInfo,
        .hasIndex = 3,
        .offset = (uint32_t)offsetof(S_basisheartbeat_ev__storage_, coordInfo),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeMessage,
      },
    };
    GPBDescriptor *localDescriptor =
        [GPBDescriptor allocDescriptorForClass:[S_basisheartbeat_ev class]
                                     rootClass:[S_basisSBasisRoot class]
                                          file:S_basisSBasisRoot_FileDescriptor()
                                        fields:fields
                                    fieldCount:(uint32_t)(sizeof(fields) / sizeof(GPBMessageFieldDescription))
                                   storageSize:sizeof(S_basisheartbeat_ev__storage_)
                                         flags:GPBDescriptorInitializationFlag_None];
    NSAssert(descriptor == nil, @"Startup recursed!");
    descriptor = localDescriptor;
  }
  return descriptor;
}

@end

#pragma mark - Enum S_basisheartbeat_ev_msg

GPBEnumDescriptor *S_basisheartbeat_ev_msg_EnumDescriptor(void) {
  static GPBEnumDescriptor *descriptor = NULL;
  if (!descriptor) {
    static const char *valueNames =
        "Id\000";
    static const int32_t values[] = {
        S_basisheartbeat_ev_msg_Id,
    };
    static const char *extraTextFormatInfo = "\001\000\"\000";
    GPBEnumDescriptor *worker =
        [GPBEnumDescriptor allocDescriptorForName:GPBNSStringifySymbol(S_basisheartbeat_ev_msg)
                                       valueNames:valueNames
                                           values:values
                                            count:(uint32_t)(sizeof(values) / sizeof(int32_t))
                                     enumVerifier:S_basisheartbeat_ev_msg_IsValidValue
                              extraTextFormatInfo:extraTextFormatInfo];
    if (!OSAtomicCompareAndSwapPtrBarrier(nil, worker, (void * volatile *)&descriptor)) {
      [worker release];
    }
  }
  return descriptor;
}

BOOL S_basisheartbeat_ev_msg_IsValidValue(int32_t value__) {
  switch (value__) {
    case S_basisheartbeat_ev_msg_Id:
      return YES;
    default:
      return NO;
  }
}


#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)
