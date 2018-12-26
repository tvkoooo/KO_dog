// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: b_business_account.proto

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

NS_ASSUME_NONNULL_BEGIN

#pragma mark - B_business_account_BBusinessAccountRoot

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
@interface B_business_account_BBusinessAccountRoot : GPBRootObject
@end

#pragma mark - B_business_account_user_info

typedef GPB_ENUM(B_business_account_user_info_FieldNumber) {
  B_business_account_user_info_FieldNumber_UserId = 1,
  B_business_account_user_info_FieldNumber_UserName = 2,
  B_business_account_user_info_FieldNumber_UserNick = 3,
  B_business_account_user_info_FieldNumber_CreateTime = 4,
};

@interface B_business_account_user_info : GPBMessage

/** 用户id */
@property(nonatomic, readwrite) uint64_t userId;

@property(nonatomic, readwrite) BOOL hasUserId;
/** 用户名 */
@property(nonatomic, readwrite, copy, null_resettable) NSString *userName;
/** Test to see if @c userName has been set. */
@property(nonatomic, readwrite) BOOL hasUserName;

/** 用户昵称 */
@property(nonatomic, readwrite, copy, null_resettable) NSString *userNick;
/** Test to see if @c userNick has been set. */
@property(nonatomic, readwrite) BOOL hasUserNick;

/** 创建时间 */
@property(nonatomic, readwrite) uint32_t createTime;

@property(nonatomic, readwrite) BOOL hasCreateTime;
@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)