// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: c_business_nt_message.proto

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

 #import "CBusinessNtMessage.pbobjc.h"
 #import "BError.pbobjc.h"
// @@protoc_insertion_point(imports)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

#pragma mark - C_business_nt_message_CBusinessNtMessageRoot

@implementation C_business_nt_message_CBusinessNtMessageRoot

// No extensions in the file and none of the imports (direct or indirect)
// defined extensions, so no need to generate +extensionRegistry.

@end

#pragma mark - C_business_nt_message_CBusinessNtMessageRoot_FileDescriptor

static GPBFileDescriptor *C_business_nt_message_CBusinessNtMessageRoot_FileDescriptor(void) {
  // This is called by +initialize so there is no need to worry
  // about thread safety of the singleton.
  static GPBFileDescriptor *descriptor = NULL;
  if (!descriptor) {
    GPB_DEBUG_CHECK_RUNTIME_VERSIONS();
    descriptor = [[GPBFileDescriptor alloc] initWithPackage:@"c_business_nt_message"
                                                 objcPrefix:@"C_business_nt_message_"
                                                     syntax:GPBFileSyntaxProto2];
  }
  return descriptor;
}

#pragma mark - Enum C_business_nt_message_msg

GPBEnumDescriptor *C_business_nt_message_msg_EnumDescriptor(void) {
  static GPBEnumDescriptor *descriptor = NULL;
  if (!descriptor) {
    static const char *valueNames =
        "MinId\000MaxId\000";
    static const int32_t values[] = {
        C_business_nt_message_msg_MinId,
        C_business_nt_message_msg_MaxId,
    };
    static const char *extraTextFormatInfo = "\002\000#\242\000\001#\242\000";
    GPBEnumDescriptor *worker =
        [GPBEnumDescriptor allocDescriptorForName:GPBNSStringifySymbol(C_business_nt_message_msg)
                                       valueNames:valueNames
                                           values:values
                                            count:(uint32_t)(sizeof(values) / sizeof(int32_t))
                                     enumVerifier:C_business_nt_message_msg_IsValidValue
                              extraTextFormatInfo:extraTextFormatInfo];
    if (!OSAtomicCompareAndSwapPtrBarrier(nil, worker, (void * volatile *)&descriptor)) {
      [worker release];
    }
  }
  return descriptor;
}

BOOL C_business_nt_message_msg_IsValidValue(int32_t value__) {
  switch (value__) {
    case C_business_nt_message_msg_MinId:
    case C_business_nt_message_msg_MaxId:
      return YES;
    default:
      return NO;
  }
}

#pragma mark - C_business_nt_message_nt_message_consume_by_id_rq

@implementation C_business_nt_message_nt_message_consume_by_id_rq

@dynamic hasUserId, userId;
@dynamic hasNoteId, noteId;

typedef struct C_business_nt_message_nt_message_consume_by_id_rq__storage_ {
  uint32_t _has_storage_[1];
  uint64_t userId;
  uint64_t noteId;
} C_business_nt_message_nt_message_consume_by_id_rq__storage_;

// This method is threadsafe because it is initially called
// in +initialize for each subclass.
+ (GPBDescriptor *)descriptor {
  static GPBDescriptor *descriptor = nil;
  if (!descriptor) {
    static GPBMessageFieldDescription fields[] = {
      {
        .name = "userId",
        .dataTypeSpecific.className = NULL,
        .number = C_business_nt_message_nt_message_consume_by_id_rq_FieldNumber_UserId,
        .hasIndex = 0,
        .offset = (uint32_t)offsetof(C_business_nt_message_nt_message_consume_by_id_rq__storage_, userId),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeUInt64,
      },
      {
        .name = "noteId",
        .dataTypeSpecific.className = NULL,
        .number = C_business_nt_message_nt_message_consume_by_id_rq_FieldNumber_NoteId,
        .hasIndex = 1,
        .offset = (uint32_t)offsetof(C_business_nt_message_nt_message_consume_by_id_rq__storage_, noteId),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeUInt64,
      },
    };
    GPBDescriptor *localDescriptor =
        [GPBDescriptor allocDescriptorForClass:[C_business_nt_message_nt_message_consume_by_id_rq class]
                                     rootClass:[C_business_nt_message_CBusinessNtMessageRoot class]
                                          file:C_business_nt_message_CBusinessNtMessageRoot_FileDescriptor()
                                        fields:fields
                                    fieldCount:(uint32_t)(sizeof(fields) / sizeof(GPBMessageFieldDescription))
                                   storageSize:sizeof(C_business_nt_message_nt_message_consume_by_id_rq__storage_)
                                         flags:GPBDescriptorInitializationFlag_None];
    NSAssert(descriptor == nil, @"Startup recursed!");
    descriptor = localDescriptor;
  }
  return descriptor;
}

@end

#pragma mark - Enum C_business_nt_message_nt_message_consume_by_id_rq_msg

GPBEnumDescriptor *C_business_nt_message_nt_message_consume_by_id_rq_msg_EnumDescriptor(void) {
  static GPBEnumDescriptor *descriptor = NULL;
  if (!descriptor) {
    static const char *valueNames =
        "Id\000";
    static const int32_t values[] = {
        C_business_nt_message_nt_message_consume_by_id_rq_msg_Id,
    };
    static const char *extraTextFormatInfo = "\001\000\"\000";
    GPBEnumDescriptor *worker =
        [GPBEnumDescriptor allocDescriptorForName:GPBNSStringifySymbol(C_business_nt_message_nt_message_consume_by_id_rq_msg)
                                       valueNames:valueNames
                                           values:values
                                            count:(uint32_t)(sizeof(values) / sizeof(int32_t))
                                     enumVerifier:C_business_nt_message_nt_message_consume_by_id_rq_msg_IsValidValue
                              extraTextFormatInfo:extraTextFormatInfo];
    if (!OSAtomicCompareAndSwapPtrBarrier(nil, worker, (void * volatile *)&descriptor)) {
      [worker release];
    }
  }
  return descriptor;
}

BOOL C_business_nt_message_nt_message_consume_by_id_rq_msg_IsValidValue(int32_t value__) {
  switch (value__) {
    case C_business_nt_message_nt_message_consume_by_id_rq_msg_Id:
      return YES;
    default:
      return NO;
  }
}

#pragma mark - C_business_nt_message_nt_message_consume_by_id_rs

@implementation C_business_nt_message_nt_message_consume_by_id_rs

@dynamic hasError, error;
@dynamic hasUserId, userId;
@dynamic hasNoteId, noteId;

typedef struct C_business_nt_message_nt_message_consume_by_id_rs__storage_ {
  uint32_t _has_storage_[1];
  B_error_info *error;
  uint64_t userId;
  uint64_t noteId;
} C_business_nt_message_nt_message_consume_by_id_rs__storage_;

// This method is threadsafe because it is initially called
// in +initialize for each subclass.
+ (GPBDescriptor *)descriptor {
  static GPBDescriptor *descriptor = nil;
  if (!descriptor) {
    static GPBMessageFieldDescription fields[] = {
      {
        .name = "error",
        .dataTypeSpecific.className = GPBStringifySymbol(B_error_info),
        .number = C_business_nt_message_nt_message_consume_by_id_rs_FieldNumber_Error,
        .hasIndex = 0,
        .offset = (uint32_t)offsetof(C_business_nt_message_nt_message_consume_by_id_rs__storage_, error),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeMessage,
      },
      {
        .name = "userId",
        .dataTypeSpecific.className = NULL,
        .number = C_business_nt_message_nt_message_consume_by_id_rs_FieldNumber_UserId,
        .hasIndex = 1,
        .offset = (uint32_t)offsetof(C_business_nt_message_nt_message_consume_by_id_rs__storage_, userId),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeUInt64,
      },
      {
        .name = "noteId",
        .dataTypeSpecific.className = NULL,
        .number = C_business_nt_message_nt_message_consume_by_id_rs_FieldNumber_NoteId,
        .hasIndex = 2,
        .offset = (uint32_t)offsetof(C_business_nt_message_nt_message_consume_by_id_rs__storage_, noteId),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeUInt64,
      },
    };
    GPBDescriptor *localDescriptor =
        [GPBDescriptor allocDescriptorForClass:[C_business_nt_message_nt_message_consume_by_id_rs class]
                                     rootClass:[C_business_nt_message_CBusinessNtMessageRoot class]
                                          file:C_business_nt_message_CBusinessNtMessageRoot_FileDescriptor()
                                        fields:fields
                                    fieldCount:(uint32_t)(sizeof(fields) / sizeof(GPBMessageFieldDescription))
                                   storageSize:sizeof(C_business_nt_message_nt_message_consume_by_id_rs__storage_)
                                         flags:GPBDescriptorInitializationFlag_None];
    NSAssert(descriptor == nil, @"Startup recursed!");
    descriptor = localDescriptor;
  }
  return descriptor;
}

@end

#pragma mark - Enum C_business_nt_message_nt_message_consume_by_id_rs_msg

GPBEnumDescriptor *C_business_nt_message_nt_message_consume_by_id_rs_msg_EnumDescriptor(void) {
  static GPBEnumDescriptor *descriptor = NULL;
  if (!descriptor) {
    static const char *valueNames =
        "Id\000";
    static const int32_t values[] = {
        C_business_nt_message_nt_message_consume_by_id_rs_msg_Id,
    };
    static const char *extraTextFormatInfo = "\001\000\"\000";
    GPBEnumDescriptor *worker =
        [GPBEnumDescriptor allocDescriptorForName:GPBNSStringifySymbol(C_business_nt_message_nt_message_consume_by_id_rs_msg)
                                       valueNames:valueNames
                                           values:values
                                            count:(uint32_t)(sizeof(values) / sizeof(int32_t))
                                     enumVerifier:C_business_nt_message_nt_message_consume_by_id_rs_msg_IsValidValue
                              extraTextFormatInfo:extraTextFormatInfo];
    if (!OSAtomicCompareAndSwapPtrBarrier(nil, worker, (void * volatile *)&descriptor)) {
      [worker release];
    }
  }
  return descriptor;
}

BOOL C_business_nt_message_nt_message_consume_by_id_rs_msg_IsValidValue(int32_t value__) {
  switch (value__) {
    case C_business_nt_message_nt_message_consume_by_id_rs_msg_Id:
      return YES;
    default:
      return NO;
  }
}

#pragma mark - C_business_nt_message_nt_message_consume_by_maxid_rq

@implementation C_business_nt_message_nt_message_consume_by_maxid_rq

@dynamic hasUserId, userId;
@dynamic hasNoteMaxid, noteMaxid;

typedef struct C_business_nt_message_nt_message_consume_by_maxid_rq__storage_ {
  uint32_t _has_storage_[1];
  uint64_t userId;
  uint64_t noteMaxid;
} C_business_nt_message_nt_message_consume_by_maxid_rq__storage_;

// This method is threadsafe because it is initially called
// in +initialize for each subclass.
+ (GPBDescriptor *)descriptor {
  static GPBDescriptor *descriptor = nil;
  if (!descriptor) {
    static GPBMessageFieldDescription fields[] = {
      {
        .name = "userId",
        .dataTypeSpecific.className = NULL,
        .number = C_business_nt_message_nt_message_consume_by_maxid_rq_FieldNumber_UserId,
        .hasIndex = 0,
        .offset = (uint32_t)offsetof(C_business_nt_message_nt_message_consume_by_maxid_rq__storage_, userId),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeUInt64,
      },
      {
        .name = "noteMaxid",
        .dataTypeSpecific.className = NULL,
        .number = C_business_nt_message_nt_message_consume_by_maxid_rq_FieldNumber_NoteMaxid,
        .hasIndex = 1,
        .offset = (uint32_t)offsetof(C_business_nt_message_nt_message_consume_by_maxid_rq__storage_, noteMaxid),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeUInt64,
      },
    };
    GPBDescriptor *localDescriptor =
        [GPBDescriptor allocDescriptorForClass:[C_business_nt_message_nt_message_consume_by_maxid_rq class]
                                     rootClass:[C_business_nt_message_CBusinessNtMessageRoot class]
                                          file:C_business_nt_message_CBusinessNtMessageRoot_FileDescriptor()
                                        fields:fields
                                    fieldCount:(uint32_t)(sizeof(fields) / sizeof(GPBMessageFieldDescription))
                                   storageSize:sizeof(C_business_nt_message_nt_message_consume_by_maxid_rq__storage_)
                                         flags:GPBDescriptorInitializationFlag_None];
    NSAssert(descriptor == nil, @"Startup recursed!");
    descriptor = localDescriptor;
  }
  return descriptor;
}

@end

#pragma mark - Enum C_business_nt_message_nt_message_consume_by_maxid_rq_msg

GPBEnumDescriptor *C_business_nt_message_nt_message_consume_by_maxid_rq_msg_EnumDescriptor(void) {
  static GPBEnumDescriptor *descriptor = NULL;
  if (!descriptor) {
    static const char *valueNames =
        "Id\000";
    static const int32_t values[] = {
        C_business_nt_message_nt_message_consume_by_maxid_rq_msg_Id,
    };
    static const char *extraTextFormatInfo = "\001\000\"\000";
    GPBEnumDescriptor *worker =
        [GPBEnumDescriptor allocDescriptorForName:GPBNSStringifySymbol(C_business_nt_message_nt_message_consume_by_maxid_rq_msg)
                                       valueNames:valueNames
                                           values:values
                                            count:(uint32_t)(sizeof(values) / sizeof(int32_t))
                                     enumVerifier:C_business_nt_message_nt_message_consume_by_maxid_rq_msg_IsValidValue
                              extraTextFormatInfo:extraTextFormatInfo];
    if (!OSAtomicCompareAndSwapPtrBarrier(nil, worker, (void * volatile *)&descriptor)) {
      [worker release];
    }
  }
  return descriptor;
}

BOOL C_business_nt_message_nt_message_consume_by_maxid_rq_msg_IsValidValue(int32_t value__) {
  switch (value__) {
    case C_business_nt_message_nt_message_consume_by_maxid_rq_msg_Id:
      return YES;
    default:
      return NO;
  }
}

#pragma mark - C_business_nt_message_nt_message_consume_by_maxid_rs

@implementation C_business_nt_message_nt_message_consume_by_maxid_rs

@dynamic hasError, error;
@dynamic hasUserId, userId;
@dynamic hasNoteMaxid, noteMaxid;

typedef struct C_business_nt_message_nt_message_consume_by_maxid_rs__storage_ {
  uint32_t _has_storage_[1];
  B_error_info *error;
  uint64_t userId;
  uint64_t noteMaxid;
} C_business_nt_message_nt_message_consume_by_maxid_rs__storage_;

// This method is threadsafe because it is initially called
// in +initialize for each subclass.
+ (GPBDescriptor *)descriptor {
  static GPBDescriptor *descriptor = nil;
  if (!descriptor) {
    static GPBMessageFieldDescription fields[] = {
      {
        .name = "error",
        .dataTypeSpecific.className = GPBStringifySymbol(B_error_info),
        .number = C_business_nt_message_nt_message_consume_by_maxid_rs_FieldNumber_Error,
        .hasIndex = 0,
        .offset = (uint32_t)offsetof(C_business_nt_message_nt_message_consume_by_maxid_rs__storage_, error),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeMessage,
      },
      {
        .name = "userId",
        .dataTypeSpecific.className = NULL,
        .number = C_business_nt_message_nt_message_consume_by_maxid_rs_FieldNumber_UserId,
        .hasIndex = 1,
        .offset = (uint32_t)offsetof(C_business_nt_message_nt_message_consume_by_maxid_rs__storage_, userId),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeUInt64,
      },
      {
        .name = "noteMaxid",
        .dataTypeSpecific.className = NULL,
        .number = C_business_nt_message_nt_message_consume_by_maxid_rs_FieldNumber_NoteMaxid,
        .hasIndex = 2,
        .offset = (uint32_t)offsetof(C_business_nt_message_nt_message_consume_by_maxid_rs__storage_, noteMaxid),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeUInt64,
      },
    };
    GPBDescriptor *localDescriptor =
        [GPBDescriptor allocDescriptorForClass:[C_business_nt_message_nt_message_consume_by_maxid_rs class]
                                     rootClass:[C_business_nt_message_CBusinessNtMessageRoot class]
                                          file:C_business_nt_message_CBusinessNtMessageRoot_FileDescriptor()
                                        fields:fields
                                    fieldCount:(uint32_t)(sizeof(fields) / sizeof(GPBMessageFieldDescription))
                                   storageSize:sizeof(C_business_nt_message_nt_message_consume_by_maxid_rs__storage_)
                                         flags:GPBDescriptorInitializationFlag_None];
    NSAssert(descriptor == nil, @"Startup recursed!");
    descriptor = localDescriptor;
  }
  return descriptor;
}

@end

#pragma mark - Enum C_business_nt_message_nt_message_consume_by_maxid_rs_msg

GPBEnumDescriptor *C_business_nt_message_nt_message_consume_by_maxid_rs_msg_EnumDescriptor(void) {
  static GPBEnumDescriptor *descriptor = NULL;
  if (!descriptor) {
    static const char *valueNames =
        "Id\000";
    static const int32_t values[] = {
        C_business_nt_message_nt_message_consume_by_maxid_rs_msg_Id,
    };
    static const char *extraTextFormatInfo = "\001\000\"\000";
    GPBEnumDescriptor *worker =
        [GPBEnumDescriptor allocDescriptorForName:GPBNSStringifySymbol(C_business_nt_message_nt_message_consume_by_maxid_rs_msg)
                                       valueNames:valueNames
                                           values:values
                                            count:(uint32_t)(sizeof(values) / sizeof(int32_t))
                                     enumVerifier:C_business_nt_message_nt_message_consume_by_maxid_rs_msg_IsValidValue
                              extraTextFormatInfo:extraTextFormatInfo];
    if (!OSAtomicCompareAndSwapPtrBarrier(nil, worker, (void * volatile *)&descriptor)) {
      [worker release];
    }
  }
  return descriptor;
}

BOOL C_business_nt_message_nt_message_consume_by_maxid_rs_msg_IsValidValue(int32_t value__) {
  switch (value__) {
    case C_business_nt_message_nt_message_consume_by_maxid_rs_msg_Id:
      return YES;
    default:
      return NO;
  }
}

#pragma mark - C_business_nt_message_nt_message_read_note_id_rq

@implementation C_business_nt_message_nt_message_read_note_id_rq

@dynamic hasUserId, userId;
@dynamic hasNoteId, noteId;

typedef struct C_business_nt_message_nt_message_read_note_id_rq__storage_ {
  uint32_t _has_storage_[1];
  uint64_t userId;
  uint64_t noteId;
} C_business_nt_message_nt_message_read_note_id_rq__storage_;

// This method is threadsafe because it is initially called
// in +initialize for each subclass.
+ (GPBDescriptor *)descriptor {
  static GPBDescriptor *descriptor = nil;
  if (!descriptor) {
    static GPBMessageFieldDescription fields[] = {
      {
        .name = "userId",
        .dataTypeSpecific.className = NULL,
        .number = C_business_nt_message_nt_message_read_note_id_rq_FieldNumber_UserId,
        .hasIndex = 0,
        .offset = (uint32_t)offsetof(C_business_nt_message_nt_message_read_note_id_rq__storage_, userId),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeUInt64,
      },
      {
        .name = "noteId",
        .dataTypeSpecific.className = NULL,
        .number = C_business_nt_message_nt_message_read_note_id_rq_FieldNumber_NoteId,
        .hasIndex = 1,
        .offset = (uint32_t)offsetof(C_business_nt_message_nt_message_read_note_id_rq__storage_, noteId),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeUInt64,
      },
    };
    GPBDescriptor *localDescriptor =
        [GPBDescriptor allocDescriptorForClass:[C_business_nt_message_nt_message_read_note_id_rq class]
                                     rootClass:[C_business_nt_message_CBusinessNtMessageRoot class]
                                          file:C_business_nt_message_CBusinessNtMessageRoot_FileDescriptor()
                                        fields:fields
                                    fieldCount:(uint32_t)(sizeof(fields) / sizeof(GPBMessageFieldDescription))
                                   storageSize:sizeof(C_business_nt_message_nt_message_read_note_id_rq__storage_)
                                         flags:GPBDescriptorInitializationFlag_None];
    NSAssert(descriptor == nil, @"Startup recursed!");
    descriptor = localDescriptor;
  }
  return descriptor;
}

@end

#pragma mark - Enum C_business_nt_message_nt_message_read_note_id_rq_msg

GPBEnumDescriptor *C_business_nt_message_nt_message_read_note_id_rq_msg_EnumDescriptor(void) {
  static GPBEnumDescriptor *descriptor = NULL;
  if (!descriptor) {
    static const char *valueNames =
        "Id\000";
    static const int32_t values[] = {
        C_business_nt_message_nt_message_read_note_id_rq_msg_Id,
    };
    static const char *extraTextFormatInfo = "\001\000\"\000";
    GPBEnumDescriptor *worker =
        [GPBEnumDescriptor allocDescriptorForName:GPBNSStringifySymbol(C_business_nt_message_nt_message_read_note_id_rq_msg)
                                       valueNames:valueNames
                                           values:values
                                            count:(uint32_t)(sizeof(values) / sizeof(int32_t))
                                     enumVerifier:C_business_nt_message_nt_message_read_note_id_rq_msg_IsValidValue
                              extraTextFormatInfo:extraTextFormatInfo];
    if (!OSAtomicCompareAndSwapPtrBarrier(nil, worker, (void * volatile *)&descriptor)) {
      [worker release];
    }
  }
  return descriptor;
}

BOOL C_business_nt_message_nt_message_read_note_id_rq_msg_IsValidValue(int32_t value__) {
  switch (value__) {
    case C_business_nt_message_nt_message_read_note_id_rq_msg_Id:
      return YES;
    default:
      return NO;
  }
}

#pragma mark - C_business_nt_message_nt_message_read_note_id_rs

@implementation C_business_nt_message_nt_message_read_note_id_rs

@dynamic hasError, error;
@dynamic hasUserId, userId;
@dynamic hasNoteId, noteId;

typedef struct C_business_nt_message_nt_message_read_note_id_rs__storage_ {
  uint32_t _has_storage_[1];
  B_error_info *error;
  uint64_t userId;
  uint64_t noteId;
} C_business_nt_message_nt_message_read_note_id_rs__storage_;

// This method is threadsafe because it is initially called
// in +initialize for each subclass.
+ (GPBDescriptor *)descriptor {
  static GPBDescriptor *descriptor = nil;
  if (!descriptor) {
    static GPBMessageFieldDescription fields[] = {
      {
        .name = "error",
        .dataTypeSpecific.className = GPBStringifySymbol(B_error_info),
        .number = C_business_nt_message_nt_message_read_note_id_rs_FieldNumber_Error,
        .hasIndex = 0,
        .offset = (uint32_t)offsetof(C_business_nt_message_nt_message_read_note_id_rs__storage_, error),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeMessage,
      },
      {
        .name = "userId",
        .dataTypeSpecific.className = NULL,
        .number = C_business_nt_message_nt_message_read_note_id_rs_FieldNumber_UserId,
        .hasIndex = 1,
        .offset = (uint32_t)offsetof(C_business_nt_message_nt_message_read_note_id_rs__storage_, userId),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeUInt64,
      },
      {
        .name = "noteId",
        .dataTypeSpecific.className = NULL,
        .number = C_business_nt_message_nt_message_read_note_id_rs_FieldNumber_NoteId,
        .hasIndex = 2,
        .offset = (uint32_t)offsetof(C_business_nt_message_nt_message_read_note_id_rs__storage_, noteId),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeUInt64,
      },
    };
    GPBDescriptor *localDescriptor =
        [GPBDescriptor allocDescriptorForClass:[C_business_nt_message_nt_message_read_note_id_rs class]
                                     rootClass:[C_business_nt_message_CBusinessNtMessageRoot class]
                                          file:C_business_nt_message_CBusinessNtMessageRoot_FileDescriptor()
                                        fields:fields
                                    fieldCount:(uint32_t)(sizeof(fields) / sizeof(GPBMessageFieldDescription))
                                   storageSize:sizeof(C_business_nt_message_nt_message_read_note_id_rs__storage_)
                                         flags:GPBDescriptorInitializationFlag_None];
    NSAssert(descriptor == nil, @"Startup recursed!");
    descriptor = localDescriptor;
  }
  return descriptor;
}

@end

#pragma mark - Enum C_business_nt_message_nt_message_read_note_id_rs_msg

GPBEnumDescriptor *C_business_nt_message_nt_message_read_note_id_rs_msg_EnumDescriptor(void) {
  static GPBEnumDescriptor *descriptor = NULL;
  if (!descriptor) {
    static const char *valueNames =
        "Id\000";
    static const int32_t values[] = {
        C_business_nt_message_nt_message_read_note_id_rs_msg_Id,
    };
    static const char *extraTextFormatInfo = "\001\000\"\000";
    GPBEnumDescriptor *worker =
        [GPBEnumDescriptor allocDescriptorForName:GPBNSStringifySymbol(C_business_nt_message_nt_message_read_note_id_rs_msg)
                                       valueNames:valueNames
                                           values:values
                                            count:(uint32_t)(sizeof(values) / sizeof(int32_t))
                                     enumVerifier:C_business_nt_message_nt_message_read_note_id_rs_msg_IsValidValue
                              extraTextFormatInfo:extraTextFormatInfo];
    if (!OSAtomicCompareAndSwapPtrBarrier(nil, worker, (void * volatile *)&descriptor)) {
      [worker release];
    }
  }
  return descriptor;
}

BOOL C_business_nt_message_nt_message_read_note_id_rs_msg_IsValidValue(int32_t value__) {
  switch (value__) {
    case C_business_nt_message_nt_message_read_note_id_rs_msg_Id:
      return YES;
    default:
      return NO;
  }
}

#pragma mark - C_business_nt_message_nt_message_all_unread_rq

@implementation C_business_nt_message_nt_message_all_unread_rq

@dynamic hasUserId, userId;

typedef struct C_business_nt_message_nt_message_all_unread_rq__storage_ {
  uint32_t _has_storage_[1];
  uint64_t userId;
} C_business_nt_message_nt_message_all_unread_rq__storage_;

// This method is threadsafe because it is initially called
// in +initialize for each subclass.
+ (GPBDescriptor *)descriptor {
  static GPBDescriptor *descriptor = nil;
  if (!descriptor) {
    static GPBMessageFieldDescription fields[] = {
      {
        .name = "userId",
        .dataTypeSpecific.className = NULL,
        .number = C_business_nt_message_nt_message_all_unread_rq_FieldNumber_UserId,
        .hasIndex = 0,
        .offset = (uint32_t)offsetof(C_business_nt_message_nt_message_all_unread_rq__storage_, userId),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeUInt64,
      },
    };
    GPBDescriptor *localDescriptor =
        [GPBDescriptor allocDescriptorForClass:[C_business_nt_message_nt_message_all_unread_rq class]
                                     rootClass:[C_business_nt_message_CBusinessNtMessageRoot class]
                                          file:C_business_nt_message_CBusinessNtMessageRoot_FileDescriptor()
                                        fields:fields
                                    fieldCount:(uint32_t)(sizeof(fields) / sizeof(GPBMessageFieldDescription))
                                   storageSize:sizeof(C_business_nt_message_nt_message_all_unread_rq__storage_)
                                         flags:GPBDescriptorInitializationFlag_None];
    NSAssert(descriptor == nil, @"Startup recursed!");
    descriptor = localDescriptor;
  }
  return descriptor;
}

@end

#pragma mark - Enum C_business_nt_message_nt_message_all_unread_rq_msg

GPBEnumDescriptor *C_business_nt_message_nt_message_all_unread_rq_msg_EnumDescriptor(void) {
  static GPBEnumDescriptor *descriptor = NULL;
  if (!descriptor) {
    static const char *valueNames =
        "Id\000";
    static const int32_t values[] = {
        C_business_nt_message_nt_message_all_unread_rq_msg_Id,
    };
    static const char *extraTextFormatInfo = "\001\000\"\000";
    GPBEnumDescriptor *worker =
        [GPBEnumDescriptor allocDescriptorForName:GPBNSStringifySymbol(C_business_nt_message_nt_message_all_unread_rq_msg)
                                       valueNames:valueNames
                                           values:values
                                            count:(uint32_t)(sizeof(values) / sizeof(int32_t))
                                     enumVerifier:C_business_nt_message_nt_message_all_unread_rq_msg_IsValidValue
                              extraTextFormatInfo:extraTextFormatInfo];
    if (!OSAtomicCompareAndSwapPtrBarrier(nil, worker, (void * volatile *)&descriptor)) {
      [worker release];
    }
  }
  return descriptor;
}

BOOL C_business_nt_message_nt_message_all_unread_rq_msg_IsValidValue(int32_t value__) {
  switch (value__) {
    case C_business_nt_message_nt_message_all_unread_rq_msg_Id:
      return YES;
    default:
      return NO;
  }
}

#pragma mark - C_business_nt_message_nt_message_all_unread_rs

@implementation C_business_nt_message_nt_message_all_unread_rs

@dynamic hasError, error;
@dynamic hasUserId, userId;

typedef struct C_business_nt_message_nt_message_all_unread_rs__storage_ {
  uint32_t _has_storage_[1];
  B_error_info *error;
  uint64_t userId;
} C_business_nt_message_nt_message_all_unread_rs__storage_;

// This method is threadsafe because it is initially called
// in +initialize for each subclass.
+ (GPBDescriptor *)descriptor {
  static GPBDescriptor *descriptor = nil;
  if (!descriptor) {
    static GPBMessageFieldDescription fields[] = {
      {
        .name = "error",
        .dataTypeSpecific.className = GPBStringifySymbol(B_error_info),
        .number = C_business_nt_message_nt_message_all_unread_rs_FieldNumber_Error,
        .hasIndex = 0,
        .offset = (uint32_t)offsetof(C_business_nt_message_nt_message_all_unread_rs__storage_, error),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeMessage,
      },
      {
        .name = "userId",
        .dataTypeSpecific.className = NULL,
        .number = C_business_nt_message_nt_message_all_unread_rs_FieldNumber_UserId,
        .hasIndex = 1,
        .offset = (uint32_t)offsetof(C_business_nt_message_nt_message_all_unread_rs__storage_, userId),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeUInt64,
      },
    };
    GPBDescriptor *localDescriptor =
        [GPBDescriptor allocDescriptorForClass:[C_business_nt_message_nt_message_all_unread_rs class]
                                     rootClass:[C_business_nt_message_CBusinessNtMessageRoot class]
                                          file:C_business_nt_message_CBusinessNtMessageRoot_FileDescriptor()
                                        fields:fields
                                    fieldCount:(uint32_t)(sizeof(fields) / sizeof(GPBMessageFieldDescription))
                                   storageSize:sizeof(C_business_nt_message_nt_message_all_unread_rs__storage_)
                                         flags:GPBDescriptorInitializationFlag_None];
    NSAssert(descriptor == nil, @"Startup recursed!");
    descriptor = localDescriptor;
  }
  return descriptor;
}

@end

#pragma mark - Enum C_business_nt_message_nt_message_all_unread_rs_msg

GPBEnumDescriptor *C_business_nt_message_nt_message_all_unread_rs_msg_EnumDescriptor(void) {
  static GPBEnumDescriptor *descriptor = NULL;
  if (!descriptor) {
    static const char *valueNames =
        "Id\000";
    static const int32_t values[] = {
        C_business_nt_message_nt_message_all_unread_rs_msg_Id,
    };
    static const char *extraTextFormatInfo = "\001\000\"\000";
    GPBEnumDescriptor *worker =
        [GPBEnumDescriptor allocDescriptorForName:GPBNSStringifySymbol(C_business_nt_message_nt_message_all_unread_rs_msg)
                                       valueNames:valueNames
                                           values:values
                                            count:(uint32_t)(sizeof(values) / sizeof(int32_t))
                                     enumVerifier:C_business_nt_message_nt_message_all_unread_rs_msg_IsValidValue
                              extraTextFormatInfo:extraTextFormatInfo];
    if (!OSAtomicCompareAndSwapPtrBarrier(nil, worker, (void * volatile *)&descriptor)) {
      [worker release];
    }
  }
  return descriptor;
}

BOOL C_business_nt_message_nt_message_all_unread_rs_msg_IsValidValue(int32_t value__) {
  switch (value__) {
    case C_business_nt_message_nt_message_all_unread_rs_msg_Id:
      return YES;
    default:
      return NO;
  }
}

#pragma mark - C_business_nt_message_nt_message_all_unread_nt

@implementation C_business_nt_message_nt_message_all_unread_nt

@dynamic hasUserId, userId;

typedef struct C_business_nt_message_nt_message_all_unread_nt__storage_ {
  uint32_t _has_storage_[1];
  uint64_t userId;
} C_business_nt_message_nt_message_all_unread_nt__storage_;

// This method is threadsafe because it is initially called
// in +initialize for each subclass.
+ (GPBDescriptor *)descriptor {
  static GPBDescriptor *descriptor = nil;
  if (!descriptor) {
    static GPBMessageFieldDescription fields[] = {
      {
        .name = "userId",
        .dataTypeSpecific.className = NULL,
        .number = C_business_nt_message_nt_message_all_unread_nt_FieldNumber_UserId,
        .hasIndex = 0,
        .offset = (uint32_t)offsetof(C_business_nt_message_nt_message_all_unread_nt__storage_, userId),
        .flags = GPBFieldRequired,
        .dataType = GPBDataTypeUInt64,
      },
    };
    GPBDescriptor *localDescriptor =
        [GPBDescriptor allocDescriptorForClass:[C_business_nt_message_nt_message_all_unread_nt class]
                                     rootClass:[C_business_nt_message_CBusinessNtMessageRoot class]
                                          file:C_business_nt_message_CBusinessNtMessageRoot_FileDescriptor()
                                        fields:fields
                                    fieldCount:(uint32_t)(sizeof(fields) / sizeof(GPBMessageFieldDescription))
                                   storageSize:sizeof(C_business_nt_message_nt_message_all_unread_nt__storage_)
                                         flags:GPBDescriptorInitializationFlag_None];
    NSAssert(descriptor == nil, @"Startup recursed!");
    descriptor = localDescriptor;
  }
  return descriptor;
}

@end

#pragma mark - Enum C_business_nt_message_nt_message_all_unread_nt_msg

GPBEnumDescriptor *C_business_nt_message_nt_message_all_unread_nt_msg_EnumDescriptor(void) {
  static GPBEnumDescriptor *descriptor = NULL;
  if (!descriptor) {
    static const char *valueNames =
        "Id\000";
    static const int32_t values[] = {
        C_business_nt_message_nt_message_all_unread_nt_msg_Id,
    };
    static const char *extraTextFormatInfo = "\001\000\"\000";
    GPBEnumDescriptor *worker =
        [GPBEnumDescriptor allocDescriptorForName:GPBNSStringifySymbol(C_business_nt_message_nt_message_all_unread_nt_msg)
                                       valueNames:valueNames
                                           values:values
                                            count:(uint32_t)(sizeof(values) / sizeof(int32_t))
                                     enumVerifier:C_business_nt_message_nt_message_all_unread_nt_msg_IsValidValue
                              extraTextFormatInfo:extraTextFormatInfo];
    if (!OSAtomicCompareAndSwapPtrBarrier(nil, worker, (void * volatile *)&descriptor)) {
      [worker release];
    }
  }
  return descriptor;
}

BOOL C_business_nt_message_nt_message_all_unread_nt_msg_IsValidValue(int32_t value__) {
  switch (value__) {
    case C_business_nt_message_nt_message_all_unread_nt_msg_Id:
      return YES;
    default:
      return NO;
  }
}


#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)