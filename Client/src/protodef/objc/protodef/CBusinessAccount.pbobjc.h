// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: c_business_account.proto

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

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Enum C_business_account_msg

typedef GPB_ENUM(C_business_account_msg) {
  C_business_account_msg_MinId = 33562624,
  C_business_account_msg_MaxId = 33562879,
};

GPBEnumDescriptor *C_business_account_msg_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL C_business_account_msg_IsValidValue(int32_t value);

#pragma mark - Enum C_business_account_signed_in_rq_msg

typedef GPB_ENUM(C_business_account_signed_in_rq_msg) {
  C_business_account_signed_in_rq_msg_Id = 33562640,
};

GPBEnumDescriptor *C_business_account_signed_in_rq_msg_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL C_business_account_signed_in_rq_msg_IsValidValue(int32_t value);

#pragma mark - Enum C_business_account_signed_in_rs_msg

typedef GPB_ENUM(C_business_account_signed_in_rs_msg) {
  C_business_account_signed_in_rs_msg_Id = 33558545,
};

GPBEnumDescriptor *C_business_account_signed_in_rs_msg_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL C_business_account_signed_in_rs_msg_IsValidValue(int32_t value);

#pragma mark - Enum C_business_account_register_rq_msg

typedef GPB_ENUM(C_business_account_register_rq_msg) {
  C_business_account_register_rq_msg_Id = 33562656,
};

GPBEnumDescriptor *C_business_account_register_rq_msg_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL C_business_account_register_rq_msg_IsValidValue(int32_t value);

#pragma mark - Enum C_business_account_register_rs_msg

typedef GPB_ENUM(C_business_account_register_rs_msg) {
  C_business_account_register_rs_msg_Id = 33558561,
};

GPBEnumDescriptor *C_business_account_register_rs_msg_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL C_business_account_register_rs_msg_IsValidValue(int32_t value);

#pragma mark - C_business_account_CBusinessAccountRoot

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
@interface C_business_account_CBusinessAccountRoot : GPBRootObject
@end

#pragma mark - C_business_account_signed_in_rq

typedef GPB_ENUM(C_business_account_signed_in_rq_FieldNumber) {
  C_business_account_signed_in_rq_FieldNumber_UserName = 1,
  C_business_account_signed_in_rq_FieldNumber_Password = 2,
};

/**
 * (tcp)登陆
 **/
@interface C_business_account_signed_in_rq : GPBMessage

/** 用户名 */
@property(nonatomic, readwrite, copy, null_resettable) NSString *userName;
/** Test to see if @c userName has been set. */
@property(nonatomic, readwrite) BOOL hasUserName;

/** 密码（md5） */
@property(nonatomic, readwrite, copy, null_resettable) NSString *password;
/** Test to see if @c password has been set. */
@property(nonatomic, readwrite) BOOL hasPassword;

@end

#pragma mark - C_business_account_signed_in_rs

typedef GPB_ENUM(C_business_account_signed_in_rs_FieldNumber) {
  C_business_account_signed_in_rs_FieldNumber_Error = 1,
  C_business_account_signed_in_rs_FieldNumber_UserName = 2,
  C_business_account_signed_in_rs_FieldNumber_UserId = 3,
  C_business_account_signed_in_rs_FieldNumber_Token = 4,
};

/**
 * (tcp)登陆
 **/
@interface C_business_account_signed_in_rs : GPBMessage

/** error info */
@property(nonatomic, readwrite, strong, null_resettable) B_error_info *error;
/** Test to see if @c error has been set. */
@property(nonatomic, readwrite) BOOL hasError;

/** 用户名 */
@property(nonatomic, readwrite, copy, null_resettable) NSString *userName;
/** Test to see if @c userName has been set. */
@property(nonatomic, readwrite) BOOL hasUserName;

/** 用户id */
@property(nonatomic, readwrite) uint64_t userId;

@property(nonatomic, readwrite) BOOL hasUserId;
/** 用户令牌 */
@property(nonatomic, readwrite, copy, null_resettable) NSString *token;
/** Test to see if @c token has been set. */
@property(nonatomic, readwrite) BOOL hasToken;

@end

#pragma mark - C_business_account_register_rq

typedef GPB_ENUM(C_business_account_register_rq_FieldNumber) {
  C_business_account_register_rq_FieldNumber_UserName = 1,
  C_business_account_register_rq_FieldNumber_Password = 2,
};

/**
 * (tcp)注册
 **/
@interface C_business_account_register_rq : GPBMessage

/** 用户名 */
@property(nonatomic, readwrite, copy, null_resettable) NSString *userName;
/** Test to see if @c userName has been set. */
@property(nonatomic, readwrite) BOOL hasUserName;

/** 密码（md5） */
@property(nonatomic, readwrite, copy, null_resettable) NSString *password;
/** Test to see if @c password has been set. */
@property(nonatomic, readwrite) BOOL hasPassword;

@end

#pragma mark - C_business_account_register_rs

typedef GPB_ENUM(C_business_account_register_rs_FieldNumber) {
  C_business_account_register_rs_FieldNumber_Error = 1,
  C_business_account_register_rs_FieldNumber_UserName = 2,
  C_business_account_register_rs_FieldNumber_UserId = 3,
  C_business_account_register_rs_FieldNumber_Token = 4,
};

/**
 * (tcp)注册
 **/
@interface C_business_account_register_rs : GPBMessage

/** error info */
@property(nonatomic, readwrite, strong, null_resettable) B_error_info *error;
/** Test to see if @c error has been set. */
@property(nonatomic, readwrite) BOOL hasError;

/** 用户名 */
@property(nonatomic, readwrite, copy, null_resettable) NSString *userName;
/** Test to see if @c userName has been set. */
@property(nonatomic, readwrite) BOOL hasUserName;

/** 用户id */
@property(nonatomic, readwrite) uint64_t userId;

@property(nonatomic, readwrite) BOOL hasUserId;
/** 用户令牌 */
@property(nonatomic, readwrite, copy, null_resettable) NSString *token;
/** Test to see if @c token has been set. */
@property(nonatomic, readwrite) BOOL hasToken;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)
