// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: b_business_relation.proto

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

#pragma mark - B_business_relation_BBusinessRelationRoot

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
@interface B_business_relation_BBusinessRelationRoot : GPBRootObject
@end

#pragma mark - B_business_relation_user_relation

typedef GPB_ENUM(B_business_relation_user_relation_FieldNumber) {
  B_business_relation_user_relation_FieldNumber_UserId = 1,
  B_business_relation_user_relation_FieldNumber_FriendGroupId = 2,
  B_business_relation_user_relation_FieldNumber_FriendId = 3,
  B_business_relation_user_relation_FieldNumber_FriendRemark = 4,
  B_business_relation_user_relation_FieldNumber_BuildFriendTime = 5,
};

@interface B_business_relation_user_relation : GPBMessage

/** 用户id */
@property(nonatomic, readwrite) uint64_t userId;

@property(nonatomic, readwrite) BOOL hasUserId;
/** 关系组id */
@property(nonatomic, readwrite) uint64_t friendGroupId;

@property(nonatomic, readwrite) BOOL hasFriendGroupId;
/** 朋友id */
@property(nonatomic, readwrite) uint64_t friendId;

@property(nonatomic, readwrite) BOOL hasFriendId;
/** 朋友昵称 */
@property(nonatomic, readwrite, copy, null_resettable) NSString *friendRemark;
/** Test to see if @c friendRemark has been set. */
@property(nonatomic, readwrite) BOOL hasFriendRemark;

/** 朋友关系创建时间 */
@property(nonatomic, readwrite) uint32_t buildFriendTime;

@property(nonatomic, readwrite) BOOL hasBuildFriendTime;
@end

#pragma mark - B_business_relation_user_relation_group

typedef GPB_ENUM(B_business_relation_user_relation_group_FieldNumber) {
  B_business_relation_user_relation_group_FieldNumber_Id_p = 1,
  B_business_relation_user_relation_group_FieldNumber_UserId = 2,
  B_business_relation_user_relation_group_FieldNumber_FriendGroup = 3,
};

@interface B_business_relation_user_relation_group : GPBMessage

/** 朋友组索引key */
@property(nonatomic, readwrite) uint64_t id_p;

@property(nonatomic, readwrite) BOOL hasId_p;
/** 用户id */
@property(nonatomic, readwrite) uint64_t userId;

@property(nonatomic, readwrite) BOOL hasUserId;
/** 朋友组名 */
@property(nonatomic, readwrite, copy, null_resettable) NSString *friendGroup;
/** Test to see if @c friendGroup has been set. */
@property(nonatomic, readwrite) BOOL hasFriendGroup;

@end

#pragma mark - B_business_relation_friend_apply

typedef GPB_ENUM(B_business_relation_friend_apply_FieldNumber) {
  B_business_relation_friend_apply_FieldNumber_UserApplyId = 1,
  B_business_relation_friend_apply_FieldNumber_UserApplyName = 2,
  B_business_relation_friend_apply_FieldNumber_UserApplyNick = 3,
  B_business_relation_friend_apply_FieldNumber_UserApplyCreateTime = 4,
  B_business_relation_friend_apply_FieldNumber_UserApplyDescription = 5,
};

@interface B_business_relation_friend_apply : GPBMessage

/** 申请朋友id */
@property(nonatomic, readwrite) uint64_t userApplyId;

@property(nonatomic, readwrite) BOOL hasUserApplyId;
/** 申请朋友名 */
@property(nonatomic, readwrite, copy, null_resettable) NSString *userApplyName;
/** Test to see if @c userApplyName has been set. */
@property(nonatomic, readwrite) BOOL hasUserApplyName;

/** 申请朋友昵称 */
@property(nonatomic, readwrite, copy, null_resettable) NSString *userApplyNick;
/** Test to see if @c userApplyNick has been set. */
@property(nonatomic, readwrite) BOOL hasUserApplyNick;

/** 申请朋友名创建时间 */
@property(nonatomic, readwrite) uint32_t userApplyCreateTime;

@property(nonatomic, readwrite) BOOL hasUserApplyCreateTime;
/** 申请朋友申请理由 */
@property(nonatomic, readwrite, copy, null_resettable) NSString *userApplyDescription;
/** Test to see if @c userApplyDescription has been set. */
@property(nonatomic, readwrite) BOOL hasUserApplyDescription;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)
