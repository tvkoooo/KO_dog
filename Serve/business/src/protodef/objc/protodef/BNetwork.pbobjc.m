// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: b_network.proto

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

 #import "BNetwork.pbobjc.h"
// @@protoc_insertion_point(imports)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

#pragma mark - B_network_BNetworkRoot

@implementation B_network_BNetworkRoot

// No extensions in the file and no imports, so no need to generate
// +extensionRegistry.

@end

#pragma mark - B_network_BNetworkRoot_FileDescriptor

static GPBFileDescriptor *B_network_BNetworkRoot_FileDescriptor(void) {
  // This is called by +initialize so there is no need to worry
  // about thread safety of the singleton.
  static GPBFileDescriptor *descriptor = NULL;
  if (!descriptor) {
    GPB_DEBUG_CHECK_RUNTIME_VERSIONS();
    descriptor = [[GPBFileDescriptor alloc] initWithPackage:@"b_network"
                                                 objcPrefix:@"B_network_"
                                                     syntax:GPBFileSyntaxProto2];
  }
  return descriptor;
}

#pragma mark - B_network_address

@implementation B_network_address

@dynamic hasHost, host;
@dynamic hasPort, port;

typedef struct B_network_address__storage_ {
  uint32_t _has_storage_[1];
  uint32_t port;
  NSString *host;
} B_network_address__storage_;

// This method is threadsafe because it is initially called
// in +initialize for each subclass.
+ (GPBDescriptor *)descriptor {
  static GPBDescriptor *descriptor = nil;
  if (!descriptor) {
    static GPBMessageFieldDescription fields[] = {
      {
        .name = "host",
        .dataTypeSpecific.className = NULL,
        .number = B_network_address_FieldNumber_Host,
        .hasIndex = 0,
        .offset = (uint32_t)offsetof(B_network_address__storage_, host),
        .flags = (GPBFieldFlags)(GPBFieldRequired | GPBFieldHasDefaultValue),
        .dataType = GPBDataTypeString,
      },
      {
        .name = "port",
        .dataTypeSpecific.className = NULL,
        .number = B_network_address_FieldNumber_Port,
        .hasIndex = 1,
        .offset = (uint32_t)offsetof(B_network_address__storage_, port),
        .flags = (GPBFieldFlags)(GPBFieldRequired | GPBFieldHasDefaultValue),
        .dataType = GPBDataTypeUInt32,
      },
    };
    GPBDescriptor *localDescriptor =
        [GPBDescriptor allocDescriptorForClass:[B_network_address class]
                                     rootClass:[B_network_BNetworkRoot class]
                                          file:B_network_BNetworkRoot_FileDescriptor()
                                        fields:fields
                                    fieldCount:(uint32_t)(sizeof(fields) / sizeof(GPBMessageFieldDescription))
                                   storageSize:sizeof(B_network_address__storage_)
                                         flags:GPBDescriptorInitializationFlag_None];
    NSAssert(descriptor == nil, @"Startup recursed!");
    descriptor = localDescriptor;
  }
  return descriptor;
}

@end


#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)
