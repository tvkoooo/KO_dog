// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: c_shuttle_lobby.proto

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

 #import "CShuttleLobby.pbobjc.h"
 #import "BError.pbobjc.h"
 #import "BMath.pbobjc.h"
// @@protoc_insertion_point(imports)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

#pragma mark - C_shuttle_lobby_CShuttleLobbyRoot

@implementation C_shuttle_lobby_CShuttleLobbyRoot

// No extensions in the file and none of the imports (direct or indirect)
// defined extensions, so no need to generate +extensionRegistry.

@end

#pragma mark - C_shuttle_lobby_CShuttleLobbyRoot_FileDescriptor

static GPBFileDescriptor *C_shuttle_lobby_CShuttleLobbyRoot_FileDescriptor(void) {
  // This is called by +initialize so there is no need to worry
  // about thread safety of the singleton.
  static GPBFileDescriptor *descriptor = NULL;
  if (!descriptor) {
    GPB_DEBUG_CHECK_RUNTIME_VERSIONS();
    descriptor = [[GPBFileDescriptor alloc] initWithPackage:@"c_shuttle_lobby"
                                                 objcPrefix:@"C_shuttle_lobby_"
                                                     syntax:GPBFileSyntaxProto2];
  }
  return descriptor;
}

#pragma mark - Enum C_shuttle_lobby_msg

GPBEnumDescriptor *C_shuttle_lobby_msg_EnumDescriptor(void) {
  static GPBEnumDescriptor *descriptor = NULL;
  if (!descriptor) {
    static const char *valueNames =
        "MinId\000MaxId\000";
    static const int32_t values[] = {
        C_shuttle_lobby_msg_MinId,
        C_shuttle_lobby_msg_MaxId,
    };
    static const char *extraTextFormatInfo = "\002\000#\242\000\001#\242\000";
    GPBEnumDescriptor *worker =
        [GPBEnumDescriptor allocDescriptorForName:GPBNSStringifySymbol(C_shuttle_lobby_msg)
                                       valueNames:valueNames
                                           values:values
                                            count:(uint32_t)(sizeof(values) / sizeof(int32_t))
                                     enumVerifier:C_shuttle_lobby_msg_IsValidValue
                              extraTextFormatInfo:extraTextFormatInfo];
    if (!OSAtomicCompareAndSwapPtrBarrier(nil, worker, (void * volatile *)&descriptor)) {
      [worker release];
    }
  }
  return descriptor;
}

BOOL C_shuttle_lobby_msg_IsValidValue(int32_t value__) {
  switch (value__) {
    case C_shuttle_lobby_msg_MinId:
    case C_shuttle_lobby_msg_MaxId:
      return YES;
    default:
      return NO;
  }
}

#pragma mark - C_shuttle_lobby_exchange_key_rq

@implementation C_shuttle_lobby_exchange_key_rq

@dynamic hasPublicKey, publicKey;
@dynamic hasEncryptKeyL, encryptKeyL;
@dynamic hasVersion, version;

typedef struct C_shuttle_lobby_exchange_key_rq__storage_ {
  uint32_t _has_storage_[1];
  uint32_t version;
  NSData *publicKey;
  NSData *encryptKeyL;
} C_shuttle_lobby_exchange_key_rq__storage_;

// This method is threadsafe because it is initially called
// in +initialize for each subclass.
+ (GPBDescriptor *)descriptor {
  static GPBDescriptor *descriptor = nil;
  if (!descriptor) {
    static GPBMessageFieldDescription fields[] = {
      {
        .name = "publicKey",
        .dataTypeSpecific.className = NULL,
        .number = C_shuttle_lobby_exchange_key_rq_FieldNumber_PublicKey,
        .hasIndex = 0,
        .offset = (uint32_t)offsetof(C_shuttle_lobby_exchange_key_rq__storage_, publicKey),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeBytes,
      },
      {
        .name = "encryptKeyL",
        .dataTypeSpecific.className = NULL,
        .number = C_shuttle_lobby_exchange_key_rq_FieldNumber_EncryptKeyL,
        .hasIndex = 1,
        .offset = (uint32_t)offsetof(C_shuttle_lobby_exchange_key_rq__storage_, encryptKeyL),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeBytes,
      },
      {
        .name = "version",
        .dataTypeSpecific.className = NULL,
        .number = C_shuttle_lobby_exchange_key_rq_FieldNumber_Version,
        .hasIndex = 2,
        .offset = (uint32_t)offsetof(C_shuttle_lobby_exchange_key_rq__storage_, version),
        .flags = (GPBFieldFlags)(GPBFieldRequired | GPBFieldHasDefaultValue),
        .dataType = GPBDataTypeUInt32,
      },
    };
    GPBDescriptor *localDescriptor =
        [GPBDescriptor allocDescriptorForClass:[C_shuttle_lobby_exchange_key_rq class]
                                     rootClass:[C_shuttle_lobby_CShuttleLobbyRoot class]
                                          file:C_shuttle_lobby_CShuttleLobbyRoot_FileDescriptor()
                                        fields:fields
                                    fieldCount:(uint32_t)(sizeof(fields) / sizeof(GPBMessageFieldDescription))
                                   storageSize:sizeof(C_shuttle_lobby_exchange_key_rq__storage_)
                                         flags:GPBDescriptorInitializationFlag_None];
    NSAssert(descriptor == nil, @"Startup recursed!");
    descriptor = localDescriptor;
  }
  return descriptor;
}

@end

#pragma mark - Enum C_shuttle_lobby_exchange_key_rq_msg

GPBEnumDescriptor *C_shuttle_lobby_exchange_key_rq_msg_EnumDescriptor(void) {
  static GPBEnumDescriptor *descriptor = NULL;
  if (!descriptor) {
    static const char *valueNames =
        "Id\000";
    static const int32_t values[] = {
        C_shuttle_lobby_exchange_key_rq_msg_Id,
    };
    static const char *extraTextFormatInfo = "\001\000\"\000";
    GPBEnumDescriptor *worker =
        [GPBEnumDescriptor allocDescriptorForName:GPBNSStringifySymbol(C_shuttle_lobby_exchange_key_rq_msg)
                                       valueNames:valueNames
                                           values:values
                                            count:(uint32_t)(sizeof(values) / sizeof(int32_t))
                                     enumVerifier:C_shuttle_lobby_exchange_key_rq_msg_IsValidValue
                              extraTextFormatInfo:extraTextFormatInfo];
    if (!OSAtomicCompareAndSwapPtrBarrier(nil, worker, (void * volatile *)&descriptor)) {
      [worker release];
    }
  }
  return descriptor;
}

BOOL C_shuttle_lobby_exchange_key_rq_msg_IsValidValue(int32_t value__) {
  switch (value__) {
    case C_shuttle_lobby_exchange_key_rq_msg_Id:
      return YES;
    default:
      return NO;
  }
}

#pragma mark - C_shuttle_lobby_exchange_key_rs

@implementation C_shuttle_lobby_exchange_key_rs

@dynamic hasError, error;
@dynamic hasEncryptKeyR, encryptKeyR;

typedef struct C_shuttle_lobby_exchange_key_rs__storage_ {
  uint32_t _has_storage_[1];
  B_error_info *error;
  NSData *encryptKeyR;
} C_shuttle_lobby_exchange_key_rs__storage_;

// This method is threadsafe because it is initially called
// in +initialize for each subclass.
+ (GPBDescriptor *)descriptor {
  static GPBDescriptor *descriptor = nil;
  if (!descriptor) {
    static GPBMessageFieldDescription fields[] = {
      {
        .name = "error",
        .dataTypeSpecific.className = GPBStringifySymbol(B_error_info),
        .number = C_shuttle_lobby_exchange_key_rs_FieldNumber_Error,
        .hasIndex = 0,
        .offset = (uint32_t)offsetof(C_shuttle_lobby_exchange_key_rs__storage_, error),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeMessage,
      },
      {
        .name = "encryptKeyR",
        .dataTypeSpecific.className = NULL,
        .number = C_shuttle_lobby_exchange_key_rs_FieldNumber_EncryptKeyR,
        .hasIndex = 1,
        .offset = (uint32_t)offsetof(C_shuttle_lobby_exchange_key_rs__storage_, encryptKeyR),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeBytes,
      },
    };
    GPBDescriptor *localDescriptor =
        [GPBDescriptor allocDescriptorForClass:[C_shuttle_lobby_exchange_key_rs class]
                                     rootClass:[C_shuttle_lobby_CShuttleLobbyRoot class]
                                          file:C_shuttle_lobby_CShuttleLobbyRoot_FileDescriptor()
                                        fields:fields
                                    fieldCount:(uint32_t)(sizeof(fields) / sizeof(GPBMessageFieldDescription))
                                   storageSize:sizeof(C_shuttle_lobby_exchange_key_rs__storage_)
                                         flags:GPBDescriptorInitializationFlag_None];
    NSAssert(descriptor == nil, @"Startup recursed!");
    descriptor = localDescriptor;
  }
  return descriptor;
}

@end

#pragma mark - Enum C_shuttle_lobby_exchange_key_rs_msg

GPBEnumDescriptor *C_shuttle_lobby_exchange_key_rs_msg_EnumDescriptor(void) {
  static GPBEnumDescriptor *descriptor = NULL;
  if (!descriptor) {
    static const char *valueNames =
        "Id\000";
    static const int32_t values[] = {
        C_shuttle_lobby_exchange_key_rs_msg_Id,
    };
    static const char *extraTextFormatInfo = "\001\000\"\000";
    GPBEnumDescriptor *worker =
        [GPBEnumDescriptor allocDescriptorForName:GPBNSStringifySymbol(C_shuttle_lobby_exchange_key_rs_msg)
                                       valueNames:valueNames
                                           values:values
                                            count:(uint32_t)(sizeof(values) / sizeof(int32_t))
                                     enumVerifier:C_shuttle_lobby_exchange_key_rs_msg_IsValidValue
                              extraTextFormatInfo:extraTextFormatInfo];
    if (!OSAtomicCompareAndSwapPtrBarrier(nil, worker, (void * volatile *)&descriptor)) {
      [worker release];
    }
  }
  return descriptor;
}

BOOL C_shuttle_lobby_exchange_key_rs_msg_IsValidValue(int32_t value__) {
  switch (value__) {
    case C_shuttle_lobby_exchange_key_rs_msg_Id:
      return YES;
    default:
      return NO;
  }
}

#pragma mark - C_shuttle_lobby_token_verify_rq

@implementation C_shuttle_lobby_token_verify_rq

@dynamic hasUid, uid;
@dynamic hasToken, token;

typedef struct C_shuttle_lobby_token_verify_rq__storage_ {
  uint32_t _has_storage_[1];
  NSString *token;
  uint64_t uid;
} C_shuttle_lobby_token_verify_rq__storage_;

// This method is threadsafe because it is initially called
// in +initialize for each subclass.
+ (GPBDescriptor *)descriptor {
  static GPBDescriptor *descriptor = nil;
  if (!descriptor) {
    static GPBMessageFieldDescription fields[] = {
      {
        .name = "uid",
        .dataTypeSpecific.className = NULL,
        .number = C_shuttle_lobby_token_verify_rq_FieldNumber_Uid,
        .hasIndex = 0,
        .offset = (uint32_t)offsetof(C_shuttle_lobby_token_verify_rq__storage_, uid),
        .flags = (GPBFieldFlags)(GPBFieldRequired | GPBFieldHasDefaultValue),
        .dataType = GPBDataTypeUInt64,
      },
      {
        .name = "token",
        .dataTypeSpecific.className = NULL,
        .number = C_shuttle_lobby_token_verify_rq_FieldNumber_Token,
        .hasIndex = 1,
        .offset = (uint32_t)offsetof(C_shuttle_lobby_token_verify_rq__storage_, token),
        .flags = (GPBFieldFlags)(GPBFieldRequired | GPBFieldHasDefaultValue),
        .dataType = GPBDataTypeString,
      },
    };
    GPBDescriptor *localDescriptor =
        [GPBDescriptor allocDescriptorForClass:[C_shuttle_lobby_token_verify_rq class]
                                     rootClass:[C_shuttle_lobby_CShuttleLobbyRoot class]
                                          file:C_shuttle_lobby_CShuttleLobbyRoot_FileDescriptor()
                                        fields:fields
                                    fieldCount:(uint32_t)(sizeof(fields) / sizeof(GPBMessageFieldDescription))
                                   storageSize:sizeof(C_shuttle_lobby_token_verify_rq__storage_)
                                         flags:GPBDescriptorInitializationFlag_None];
    NSAssert(descriptor == nil, @"Startup recursed!");
    descriptor = localDescriptor;
  }
  return descriptor;
}

@end

#pragma mark - Enum C_shuttle_lobby_token_verify_rq_msg

GPBEnumDescriptor *C_shuttle_lobby_token_verify_rq_msg_EnumDescriptor(void) {
  static GPBEnumDescriptor *descriptor = NULL;
  if (!descriptor) {
    static const char *valueNames =
        "Id\000";
    static const int32_t values[] = {
        C_shuttle_lobby_token_verify_rq_msg_Id,
    };
    static const char *extraTextFormatInfo = "\001\000\"\000";
    GPBEnumDescriptor *worker =
        [GPBEnumDescriptor allocDescriptorForName:GPBNSStringifySymbol(C_shuttle_lobby_token_verify_rq_msg)
                                       valueNames:valueNames
                                           values:values
                                            count:(uint32_t)(sizeof(values) / sizeof(int32_t))
                                     enumVerifier:C_shuttle_lobby_token_verify_rq_msg_IsValidValue
                              extraTextFormatInfo:extraTextFormatInfo];
    if (!OSAtomicCompareAndSwapPtrBarrier(nil, worker, (void * volatile *)&descriptor)) {
      [worker release];
    }
  }
  return descriptor;
}

BOOL C_shuttle_lobby_token_verify_rq_msg_IsValidValue(int32_t value__) {
  switch (value__) {
    case C_shuttle_lobby_token_verify_rq_msg_Id:
      return YES;
    default:
      return NO;
  }
}

#pragma mark - C_shuttle_lobby_token_verify_rs

@implementation C_shuttle_lobby_token_verify_rs

@dynamic hasError, error;
@dynamic hasUid, uid;
@dynamic hasToken, token;

typedef struct C_shuttle_lobby_token_verify_rs__storage_ {
  uint32_t _has_storage_[1];
  B_error_info *error;
  NSString *token;
  uint64_t uid;
} C_shuttle_lobby_token_verify_rs__storage_;

// This method is threadsafe because it is initially called
// in +initialize for each subclass.
+ (GPBDescriptor *)descriptor {
  static GPBDescriptor *descriptor = nil;
  if (!descriptor) {
    static GPBMessageFieldDescription fields[] = {
      {
        .name = "error",
        .dataTypeSpecific.className = GPBStringifySymbol(B_error_info),
        .number = C_shuttle_lobby_token_verify_rs_FieldNumber_Error,
        .hasIndex = 0,
        .offset = (uint32_t)offsetof(C_shuttle_lobby_token_verify_rs__storage_, error),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeMessage,
      },
      {
        .name = "uid",
        .dataTypeSpecific.className = NULL,
        .number = C_shuttle_lobby_token_verify_rs_FieldNumber_Uid,
        .hasIndex = 1,
        .offset = (uint32_t)offsetof(C_shuttle_lobby_token_verify_rs__storage_, uid),
        .flags = (GPBFieldFlags)(GPBFieldRequired | GPBFieldHasDefaultValue),
        .dataType = GPBDataTypeUInt64,
      },
      {
        .name = "token",
        .dataTypeSpecific.className = NULL,
        .number = C_shuttle_lobby_token_verify_rs_FieldNumber_Token,
        .hasIndex = 2,
        .offset = (uint32_t)offsetof(C_shuttle_lobby_token_verify_rs__storage_, token),
        .flags = (GPBFieldFlags)(GPBFieldRequired | GPBFieldHasDefaultValue),
        .dataType = GPBDataTypeString,
      },
    };
    GPBDescriptor *localDescriptor =
        [GPBDescriptor allocDescriptorForClass:[C_shuttle_lobby_token_verify_rs class]
                                     rootClass:[C_shuttle_lobby_CShuttleLobbyRoot class]
                                          file:C_shuttle_lobby_CShuttleLobbyRoot_FileDescriptor()
                                        fields:fields
                                    fieldCount:(uint32_t)(sizeof(fields) / sizeof(GPBMessageFieldDescription))
                                   storageSize:sizeof(C_shuttle_lobby_token_verify_rs__storage_)
                                         flags:GPBDescriptorInitializationFlag_None];
    NSAssert(descriptor == nil, @"Startup recursed!");
    descriptor = localDescriptor;
  }
  return descriptor;
}

@end

#pragma mark - Enum C_shuttle_lobby_token_verify_rs_msg

GPBEnumDescriptor *C_shuttle_lobby_token_verify_rs_msg_EnumDescriptor(void) {
  static GPBEnumDescriptor *descriptor = NULL;
  if (!descriptor) {
    static const char *valueNames =
        "Id\000";
    static const int32_t values[] = {
        C_shuttle_lobby_token_verify_rs_msg_Id,
    };
    static const char *extraTextFormatInfo = "\001\000\"\000";
    GPBEnumDescriptor *worker =
        [GPBEnumDescriptor allocDescriptorForName:GPBNSStringifySymbol(C_shuttle_lobby_token_verify_rs_msg)
                                       valueNames:valueNames
                                           values:values
                                            count:(uint32_t)(sizeof(values) / sizeof(int32_t))
                                     enumVerifier:C_shuttle_lobby_token_verify_rs_msg_IsValidValue
                              extraTextFormatInfo:extraTextFormatInfo];
    if (!OSAtomicCompareAndSwapPtrBarrier(nil, worker, (void * volatile *)&descriptor)) {
      [worker release];
    }
  }
  return descriptor;
}

BOOL C_shuttle_lobby_token_verify_rs_msg_IsValidValue(int32_t value__) {
  switch (value__) {
    case C_shuttle_lobby_token_verify_rs_msg_Id:
      return YES;
    default:
      return NO;
  }
}

#pragma mark - C_shuttle_lobby_heartbeat_rq

@implementation C_shuttle_lobby_heartbeat_rq

@dynamic hasUid, uid;
@dynamic hasTimecodeNative, timecodeNative;
@dynamic hasCoordInfo, coordInfo;

typedef struct C_shuttle_lobby_heartbeat_rq__storage_ {
  uint32_t _has_storage_[1];
  B_math_coord *coordInfo;
  uint64_t uid;
  uint64_t timecodeNative;
} C_shuttle_lobby_heartbeat_rq__storage_;

// This method is threadsafe because it is initially called
// in +initialize for each subclass.
+ (GPBDescriptor *)descriptor {
  static GPBDescriptor *descriptor = nil;
  if (!descriptor) {
    static GPBMessageFieldDescription fields[] = {
      {
        .name = "uid",
        .dataTypeSpecific.className = NULL,
        .number = C_shuttle_lobby_heartbeat_rq_FieldNumber_Uid,
        .hasIndex = 0,
        .offset = (uint32_t)offsetof(C_shuttle_lobby_heartbeat_rq__storage_, uid),
        .flags = (GPBFieldFlags)(GPBFieldRequired | GPBFieldHasDefaultValue),
        .dataType = GPBDataTypeUInt64,
      },
      {
        .name = "timecodeNative",
        .dataTypeSpecific.className = NULL,
        .number = C_shuttle_lobby_heartbeat_rq_FieldNumber_TimecodeNative,
        .hasIndex = 1,
        .offset = (uint32_t)offsetof(C_shuttle_lobby_heartbeat_rq__storage_, timecodeNative),
        .flags = (GPBFieldFlags)(GPBFieldRequired | GPBFieldHasDefaultValue),
        .dataType = GPBDataTypeUInt64,
      },
      {
        .name = "coordInfo",
        .dataTypeSpecific.className = GPBStringifySymbol(B_math_coord),
        .number = C_shuttle_lobby_heartbeat_rq_FieldNumber_CoordInfo,
        .hasIndex = 2,
        .offset = (uint32_t)offsetof(C_shuttle_lobby_heartbeat_rq__storage_, coordInfo),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeMessage,
      },
    };
    GPBDescriptor *localDescriptor =
        [GPBDescriptor allocDescriptorForClass:[C_shuttle_lobby_heartbeat_rq class]
                                     rootClass:[C_shuttle_lobby_CShuttleLobbyRoot class]
                                          file:C_shuttle_lobby_CShuttleLobbyRoot_FileDescriptor()
                                        fields:fields
                                    fieldCount:(uint32_t)(sizeof(fields) / sizeof(GPBMessageFieldDescription))
                                   storageSize:sizeof(C_shuttle_lobby_heartbeat_rq__storage_)
                                         flags:GPBDescriptorInitializationFlag_None];
    NSAssert(descriptor == nil, @"Startup recursed!");
    descriptor = localDescriptor;
  }
  return descriptor;
}

@end

#pragma mark - Enum C_shuttle_lobby_heartbeat_rq_msg

GPBEnumDescriptor *C_shuttle_lobby_heartbeat_rq_msg_EnumDescriptor(void) {
  static GPBEnumDescriptor *descriptor = NULL;
  if (!descriptor) {
    static const char *valueNames =
        "Id\000";
    static const int32_t values[] = {
        C_shuttle_lobby_heartbeat_rq_msg_Id,
    };
    static const char *extraTextFormatInfo = "\001\000\"\000";
    GPBEnumDescriptor *worker =
        [GPBEnumDescriptor allocDescriptorForName:GPBNSStringifySymbol(C_shuttle_lobby_heartbeat_rq_msg)
                                       valueNames:valueNames
                                           values:values
                                            count:(uint32_t)(sizeof(values) / sizeof(int32_t))
                                     enumVerifier:C_shuttle_lobby_heartbeat_rq_msg_IsValidValue
                              extraTextFormatInfo:extraTextFormatInfo];
    if (!OSAtomicCompareAndSwapPtrBarrier(nil, worker, (void * volatile *)&descriptor)) {
      [worker release];
    }
  }
  return descriptor;
}

BOOL C_shuttle_lobby_heartbeat_rq_msg_IsValidValue(int32_t value__) {
  switch (value__) {
    case C_shuttle_lobby_heartbeat_rq_msg_Id:
      return YES;
    default:
      return NO;
  }
}

#pragma mark - C_shuttle_lobby_heartbeat_rs

@implementation C_shuttle_lobby_heartbeat_rs

@dynamic hasError, error;
@dynamic hasUid, uid;
@dynamic hasTimecodeNative, timecodeNative;
@dynamic hasCoordInfo, coordInfo;

typedef struct C_shuttle_lobby_heartbeat_rs__storage_ {
  uint32_t _has_storage_[1];
  B_error_info *error;
  B_math_coord *coordInfo;
  uint64_t uid;
  uint64_t timecodeNative;
} C_shuttle_lobby_heartbeat_rs__storage_;

// This method is threadsafe because it is initially called
// in +initialize for each subclass.
+ (GPBDescriptor *)descriptor {
  static GPBDescriptor *descriptor = nil;
  if (!descriptor) {
    static GPBMessageFieldDescription fields[] = {
      {
        .name = "error",
        .dataTypeSpecific.className = GPBStringifySymbol(B_error_info),
        .number = C_shuttle_lobby_heartbeat_rs_FieldNumber_Error,
        .hasIndex = 0,
        .offset = (uint32_t)offsetof(C_shuttle_lobby_heartbeat_rs__storage_, error),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeMessage,
      },
      {
        .name = "uid",
        .dataTypeSpecific.className = NULL,
        .number = C_shuttle_lobby_heartbeat_rs_FieldNumber_Uid,
        .hasIndex = 1,
        .offset = (uint32_t)offsetof(C_shuttle_lobby_heartbeat_rs__storage_, uid),
        .flags = (GPBFieldFlags)(GPBFieldRequired | GPBFieldHasDefaultValue),
        .dataType = GPBDataTypeUInt64,
      },
      {
        .name = "timecodeNative",
        .dataTypeSpecific.className = NULL,
        .number = C_shuttle_lobby_heartbeat_rs_FieldNumber_TimecodeNative,
        .hasIndex = 2,
        .offset = (uint32_t)offsetof(C_shuttle_lobby_heartbeat_rs__storage_, timecodeNative),
        .flags = (GPBFieldFlags)(GPBFieldRequired | GPBFieldHasDefaultValue),
        .dataType = GPBDataTypeUInt64,
      },
      {
        .name = "coordInfo",
        .dataTypeSpecific.className = GPBStringifySymbol(B_math_coord),
        .number = C_shuttle_lobby_heartbeat_rs_FieldNumber_CoordInfo,
        .hasIndex = 3,
        .offset = (uint32_t)offsetof(C_shuttle_lobby_heartbeat_rs__storage_, coordInfo),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeMessage,
      },
    };
    GPBDescriptor *localDescriptor =
        [GPBDescriptor allocDescriptorForClass:[C_shuttle_lobby_heartbeat_rs class]
                                     rootClass:[C_shuttle_lobby_CShuttleLobbyRoot class]
                                          file:C_shuttle_lobby_CShuttleLobbyRoot_FileDescriptor()
                                        fields:fields
                                    fieldCount:(uint32_t)(sizeof(fields) / sizeof(GPBMessageFieldDescription))
                                   storageSize:sizeof(C_shuttle_lobby_heartbeat_rs__storage_)
                                         flags:GPBDescriptorInitializationFlag_None];
    NSAssert(descriptor == nil, @"Startup recursed!");
    descriptor = localDescriptor;
  }
  return descriptor;
}

@end

#pragma mark - Enum C_shuttle_lobby_heartbeat_rs_msg

GPBEnumDescriptor *C_shuttle_lobby_heartbeat_rs_msg_EnumDescriptor(void) {
  static GPBEnumDescriptor *descriptor = NULL;
  if (!descriptor) {
    static const char *valueNames =
        "Id\000";
    static const int32_t values[] = {
        C_shuttle_lobby_heartbeat_rs_msg_Id,
    };
    static const char *extraTextFormatInfo = "\001\000\"\000";
    GPBEnumDescriptor *worker =
        [GPBEnumDescriptor allocDescriptorForName:GPBNSStringifySymbol(C_shuttle_lobby_heartbeat_rs_msg)
                                       valueNames:valueNames
                                           values:values
                                            count:(uint32_t)(sizeof(values) / sizeof(int32_t))
                                     enumVerifier:C_shuttle_lobby_heartbeat_rs_msg_IsValidValue
                              extraTextFormatInfo:extraTextFormatInfo];
    if (!OSAtomicCompareAndSwapPtrBarrier(nil, worker, (void * volatile *)&descriptor)) {
      [worker release];
    }
  }
  return descriptor;
}

BOOL C_shuttle_lobby_heartbeat_rs_msg_IsValidValue(int32_t value__) {
  switch (value__) {
    case C_shuttle_lobby_heartbeat_rs_msg_Id:
      return YES;
    default:
      return NO;
  }
}


#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)
