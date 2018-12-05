// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: c_shuttle_entry.proto

// This CPP symbol can be defined to use imports that match up to the framework
// imports needed when using CocoaPods.
#if !defined(GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS)
 #define GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS 0
#endif

#if GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS
 #import <Protobuf/GPBProtocolBuffers.h>
#else
 #import "GPBProtocolBuffers.h"
#endif

#if GOOGLE_PROTOBUF_OBJC_VERSION < 30002
#error This file was generated by a newer version of protoc which is incompatible with your Protocol Buffer library sources.
#endif
#if 30002 < GOOGLE_PROTOBUF_OBJC_MIN_SUPPORTED_VERSION
#error This file was generated by an older version of protoc which is incompatible with your Protocol Buffer library sources.
#endif

// @@protoc_insertion_point(imports)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

CF_EXTERN_C_BEGIN

@class B_error_info;
@class B_math_coord;
@class B_network_address;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Enum C_shuttle_entry_msg

typedef GPB_ENUM(C_shuttle_entry_msg) {
  C_shuttle_entry_msg_MinId = 33558528,
  C_shuttle_entry_msg_MaxId = 33558783,
};

GPBEnumDescriptor *C_shuttle_entry_msg_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL C_shuttle_entry_msg_IsValidValue(int32_t value);

#pragma mark - Enum C_shuttle_entry_knock_rq_msg

typedef GPB_ENUM(C_shuttle_entry_knock_rq_msg) {
  C_shuttle_entry_knock_rq_msg_Id = 33558528,
};

GPBEnumDescriptor *C_shuttle_entry_knock_rq_msg_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL C_shuttle_entry_knock_rq_msg_IsValidValue(int32_t value);

#pragma mark - Enum C_shuttle_entry_knock_rs_msg

typedef GPB_ENUM(C_shuttle_entry_knock_rs_msg) {
  C_shuttle_entry_knock_rs_msg_Id = 33558529,
};

GPBEnumDescriptor *C_shuttle_entry_knock_rs_msg_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL C_shuttle_entry_knock_rs_msg_IsValidValue(int32_t value);

#pragma mark - C_shuttle_entry_CShuttleEntryRoot

/**
 * Exposes the extension registry for this file.
 *
 * The base class provides:
 * @code
 *   + (GPBExtensionRegistry *)extensionRegistry;
 * @endcode
 * which is a @c GPBExtensionRegistry that includes all the extensions defined by
 * this file and all files that it depends on.
 **/
@interface C_shuttle_entry_CShuttleEntryRoot : GPBRootObject
@end

#pragma mark - C_shuttle_entry_knock_rq

typedef GPB_ENUM(C_shuttle_entry_knock_rq_FieldNumber) {
  C_shuttle_entry_knock_rq_FieldNumber_NativeClientVersion = 1,
  C_shuttle_entry_knock_rq_FieldNumber_NativeSourceVersion = 2,
  C_shuttle_entry_knock_rq_FieldNumber_CoordInfo = 3,
};

/**
 * (udp)获取总线地址请求
 **/
@interface C_shuttle_entry_knock_rq : GPBMessage

/** 本地client version. */
@property(nonatomic, readwrite, copy, null_resettable) NSString *nativeClientVersion;
/** Test to see if @c nativeClientVersion has been set. */
@property(nonatomic, readwrite) BOOL hasNativeClientVersion;

/** 本地source version. */
@property(nonatomic, readwrite, copy, null_resettable) NSString *nativeSourceVersion;
/** Test to see if @c nativeSourceVersion has been set. */
@property(nonatomic, readwrite) BOOL hasNativeSourceVersion;

/** Earth(j,w). */
@property(nonatomic, readwrite, strong, null_resettable) B_math_coord *coordInfo;
/** Test to see if @c coordInfo has been set. */
@property(nonatomic, readwrite) BOOL hasCoordInfo;

@end

#pragma mark - C_shuttle_entry_knock_rs

typedef GPB_ENUM(C_shuttle_entry_knock_rs_FieldNumber) {
  C_shuttle_entry_knock_rs_FieldNumber_Error = 1,
  C_shuttle_entry_knock_rs_FieldNumber_Addr = 2,
  C_shuttle_entry_knock_rs_FieldNumber_PublicKey = 3,
  C_shuttle_entry_knock_rs_FieldNumber_RemoteClientVersion = 4,
  C_shuttle_entry_knock_rs_FieldNumber_RemoteSourceVersion = 5,
  C_shuttle_entry_knock_rs_FieldNumber_RemoteServerVersion = 6,
};

/**
 * (udp)获取总线地址返回
 **/
@interface C_shuttle_entry_knock_rs : GPBMessage

/** error info */
@property(nonatomic, readwrite, strong, null_resettable) B_error_info *error;
/** Test to see if @c error has been set. */
@property(nonatomic, readwrite) BOOL hasError;

/** 大厅网络地址 */
@property(nonatomic, readwrite, strong, null_resettable) B_network_address *addr;
/** Test to see if @c addr has been set. */
@property(nonatomic, readwrite) BOOL hasAddr;

/** 大厅服务端密钥对的公钥. */
@property(nonatomic, readwrite, copy, null_resettable) NSData *publicKey;
/** Test to see if @c publicKey has been set. */
@property(nonatomic, readwrite) BOOL hasPublicKey;

/** 远端client version. */
@property(nonatomic, readwrite, copy, null_resettable) NSString *remoteClientVersion;
/** Test to see if @c remoteClientVersion has been set. */
@property(nonatomic, readwrite) BOOL hasRemoteClientVersion;

/** 远端source version. */
@property(nonatomic, readwrite, copy, null_resettable) NSString *remoteSourceVersion;
/** Test to see if @c remoteSourceVersion has been set. */
@property(nonatomic, readwrite) BOOL hasRemoteSourceVersion;

/** 远端server version. */
@property(nonatomic, readwrite, copy, null_resettable) NSString *remoteServerVersion;
/** Test to see if @c remoteServerVersion has been set. */
@property(nonatomic, readwrite) BOOL hasRemoteServerVersion;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)
