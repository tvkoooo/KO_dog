// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: s_basis.proto

package protodef;

public final class s_basis {
  private s_basis() {}
  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistryLite registry) {
  }

  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistry registry) {
    registerAllExtensions(
        (com.google.protobuf.ExtensionRegistryLite) registry);
  }
  /**
   * <pre>
   *&#47;///////////////////////////////////////////////////////////////
   * msg area.
   * </pre>
   *
   * Protobuf enum {@code s_basis.msg}
   */
  public enum msg
      implements com.google.protobuf.ProtocolMessageEnum {
    /**
     * <code>min_id = 16781312;</code>
     */
    min_id(16781312),
    /**
     * <code>max_id = 16781567;</code>
     */
    max_id(16781567),
    ;

    /**
     * <code>min_id = 16781312;</code>
     */
    public static final int min_id_VALUE = 16781312;
    /**
     * <code>max_id = 16781567;</code>
     */
    public static final int max_id_VALUE = 16781567;


    public final int getNumber() {
      return value;
    }

    /**
     * @deprecated Use {@link #forNumber(int)} instead.
     */
    @java.lang.Deprecated
    public static msg valueOf(int value) {
      return forNumber(value);
    }

    public static msg forNumber(int value) {
      switch (value) {
        case 16781312: return min_id;
        case 16781567: return max_id;
        default: return null;
      }
    }

    public static com.google.protobuf.Internal.EnumLiteMap<msg>
        internalGetValueMap() {
      return internalValueMap;
    }
    private static final com.google.protobuf.Internal.EnumLiteMap<
        msg> internalValueMap =
          new com.google.protobuf.Internal.EnumLiteMap<msg>() {
            public msg findValueByNumber(int number) {
              return msg.forNumber(number);
            }
          };

    public final com.google.protobuf.Descriptors.EnumValueDescriptor
        getValueDescriptor() {
      return getDescriptor().getValues().get(ordinal());
    }
    public final com.google.protobuf.Descriptors.EnumDescriptor
        getDescriptorForType() {
      return getDescriptor();
    }
    public static final com.google.protobuf.Descriptors.EnumDescriptor
        getDescriptor() {
      return protodef.s_basis.getDescriptor().getEnumTypes().get(0);
    }

    private static final msg[] VALUES = values();

    public static msg valueOf(
        com.google.protobuf.Descriptors.EnumValueDescriptor desc) {
      if (desc.getType() != getDescriptor()) {
        throw new java.lang.IllegalArgumentException(
          "EnumValueDescriptor is not for this type.");
      }
      return VALUES[desc.getIndex()];
    }

    private final int value;

    private msg(int value) {
      this.value = value;
    }

    // @@protoc_insertion_point(enum_scope:s_basis.msg)
  }

  public interface heartbeat_evOrBuilder extends
      // @@protoc_insertion_point(interface_extends:s_basis.heartbeat_ev)
      com.google.protobuf.MessageOrBuilder {

    /**
     * <pre>
     * 事件发生时间戳(毫秒)
     * </pre>
     *
     * <code>required uint64 event_time = 1 [default = 0];</code>
     */
    boolean hasEventTime();
    /**
     * <pre>
     * 事件发生时间戳(毫秒)
     * </pre>
     *
     * <code>required uint64 event_time = 1 [default = 0];</code>
     */
    long getEventTime();

    /**
     * <pre>
     *用户ID
     * </pre>
     *
     * <code>required uint64 uid = 2 [default = 0];</code>
     */
    boolean hasUid();
    /**
     * <pre>
     *用户ID
     * </pre>
     *
     * <code>required uint64 uid = 2 [default = 0];</code>
     */
    long getUid();

    /**
     * <pre>
     *发出的时间点(ms毫秒)
     * </pre>
     *
     * <code>required uint64 timecode_native = 3 [default = 0];</code>
     */
    boolean hasTimecodeNative();
    /**
     * <pre>
     *发出的时间点(ms毫秒)
     * </pre>
     *
     * <code>required uint64 timecode_native = 3 [default = 0];</code>
     */
    long getTimecodeNative();

    /**
     * <pre>
     * Earth(j,w).
     * </pre>
     *
     * <code>required .b_math.coord coord_info = 4;</code>
     */
    boolean hasCoordInfo();
    /**
     * <pre>
     * Earth(j,w).
     * </pre>
     *
     * <code>required .b_math.coord coord_info = 4;</code>
     */
    protodef.b_math.coord getCoordInfo();
    /**
     * <pre>
     * Earth(j,w).
     * </pre>
     *
     * <code>required .b_math.coord coord_info = 4;</code>
     */
    protodef.b_math.coordOrBuilder getCoordInfoOrBuilder();
  }
  /**
   * <pre>
   *&#47;///////////////////////////////////////////////////////////////
   * heartbeat
   * </pre>
   *
   * Protobuf type {@code s_basis.heartbeat_ev}
   */
  public  static final class heartbeat_ev extends
      com.google.protobuf.GeneratedMessageV3 implements
      // @@protoc_insertion_point(message_implements:s_basis.heartbeat_ev)
      heartbeat_evOrBuilder {
    // Use heartbeat_ev.newBuilder() to construct.
    private heartbeat_ev(com.google.protobuf.GeneratedMessageV3.Builder<?> builder) {
      super(builder);
    }
    private heartbeat_ev() {
      eventTime_ = 0L;
      uid_ = 0L;
      timecodeNative_ = 0L;
    }

    @java.lang.Override
    public final com.google.protobuf.UnknownFieldSet
    getUnknownFields() {
      return this.unknownFields;
    }
    private heartbeat_ev(
        com.google.protobuf.CodedInputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      this();
      int mutable_bitField0_ = 0;
      com.google.protobuf.UnknownFieldSet.Builder unknownFields =
          com.google.protobuf.UnknownFieldSet.newBuilder();
      try {
        boolean done = false;
        while (!done) {
          int tag = input.readTag();
          switch (tag) {
            case 0:
              done = true;
              break;
            default: {
              if (!parseUnknownField(input, unknownFields,
                                     extensionRegistry, tag)) {
                done = true;
              }
              break;
            }
            case 8: {
              bitField0_ |= 0x00000001;
              eventTime_ = input.readUInt64();
              break;
            }
            case 16: {
              bitField0_ |= 0x00000002;
              uid_ = input.readUInt64();
              break;
            }
            case 24: {
              bitField0_ |= 0x00000004;
              timecodeNative_ = input.readUInt64();
              break;
            }
            case 34: {
              protodef.b_math.coord.Builder subBuilder = null;
              if (((bitField0_ & 0x00000008) == 0x00000008)) {
                subBuilder = coordInfo_.toBuilder();
              }
              coordInfo_ = input.readMessage(protodef.b_math.coord.PARSER, extensionRegistry);
              if (subBuilder != null) {
                subBuilder.mergeFrom(coordInfo_);
                coordInfo_ = subBuilder.buildPartial();
              }
              bitField0_ |= 0x00000008;
              break;
            }
          }
        }
      } catch (com.google.protobuf.InvalidProtocolBufferException e) {
        throw e.setUnfinishedMessage(this);
      } catch (java.io.IOException e) {
        throw new com.google.protobuf.InvalidProtocolBufferException(
            e).setUnfinishedMessage(this);
      } finally {
        this.unknownFields = unknownFields.build();
        makeExtensionsImmutable();
      }
    }
    public static final com.google.protobuf.Descriptors.Descriptor
        getDescriptor() {
      return protodef.s_basis.internal_static_s_basis_heartbeat_ev_descriptor;
    }

    protected com.google.protobuf.GeneratedMessageV3.FieldAccessorTable
        internalGetFieldAccessorTable() {
      return protodef.s_basis.internal_static_s_basis_heartbeat_ev_fieldAccessorTable
          .ensureFieldAccessorsInitialized(
              protodef.s_basis.heartbeat_ev.class, protodef.s_basis.heartbeat_ev.Builder.class);
    }

    /**
     * Protobuf enum {@code s_basis.heartbeat_ev.msg}
     */
    public enum msg
        implements com.google.protobuf.ProtocolMessageEnum {
      /**
       * <code>id = 16781312;</code>
       */
      id(16781312),
      ;

      /**
       * <code>id = 16781312;</code>
       */
      public static final int id_VALUE = 16781312;


      public final int getNumber() {
        return value;
      }

      /**
       * @deprecated Use {@link #forNumber(int)} instead.
       */
      @java.lang.Deprecated
      public static msg valueOf(int value) {
        return forNumber(value);
      }

      public static msg forNumber(int value) {
        switch (value) {
          case 16781312: return id;
          default: return null;
        }
      }

      public static com.google.protobuf.Internal.EnumLiteMap<msg>
          internalGetValueMap() {
        return internalValueMap;
      }
      private static final com.google.protobuf.Internal.EnumLiteMap<
          msg> internalValueMap =
            new com.google.protobuf.Internal.EnumLiteMap<msg>() {
              public msg findValueByNumber(int number) {
                return msg.forNumber(number);
              }
            };

      public final com.google.protobuf.Descriptors.EnumValueDescriptor
          getValueDescriptor() {
        return getDescriptor().getValues().get(ordinal());
      }
      public final com.google.protobuf.Descriptors.EnumDescriptor
          getDescriptorForType() {
        return getDescriptor();
      }
      public static final com.google.protobuf.Descriptors.EnumDescriptor
          getDescriptor() {
        return protodef.s_basis.heartbeat_ev.getDescriptor().getEnumTypes().get(0);
      }

      private static final msg[] VALUES = values();

      public static msg valueOf(
          com.google.protobuf.Descriptors.EnumValueDescriptor desc) {
        if (desc.getType() != getDescriptor()) {
          throw new java.lang.IllegalArgumentException(
            "EnumValueDescriptor is not for this type.");
        }
        return VALUES[desc.getIndex()];
      }

      private final int value;

      private msg(int value) {
        this.value = value;
      }

      // @@protoc_insertion_point(enum_scope:s_basis.heartbeat_ev.msg)
    }

    private int bitField0_;
    public static final int EVENT_TIME_FIELD_NUMBER = 1;
    private long eventTime_;
    /**
     * <pre>
     * 事件发生时间戳(毫秒)
     * </pre>
     *
     * <code>required uint64 event_time = 1 [default = 0];</code>
     */
    public boolean hasEventTime() {
      return ((bitField0_ & 0x00000001) == 0x00000001);
    }
    /**
     * <pre>
     * 事件发生时间戳(毫秒)
     * </pre>
     *
     * <code>required uint64 event_time = 1 [default = 0];</code>
     */
    public long getEventTime() {
      return eventTime_;
    }

    public static final int UID_FIELD_NUMBER = 2;
    private long uid_;
    /**
     * <pre>
     *用户ID
     * </pre>
     *
     * <code>required uint64 uid = 2 [default = 0];</code>
     */
    public boolean hasUid() {
      return ((bitField0_ & 0x00000002) == 0x00000002);
    }
    /**
     * <pre>
     *用户ID
     * </pre>
     *
     * <code>required uint64 uid = 2 [default = 0];</code>
     */
    public long getUid() {
      return uid_;
    }

    public static final int TIMECODE_NATIVE_FIELD_NUMBER = 3;
    private long timecodeNative_;
    /**
     * <pre>
     *发出的时间点(ms毫秒)
     * </pre>
     *
     * <code>required uint64 timecode_native = 3 [default = 0];</code>
     */
    public boolean hasTimecodeNative() {
      return ((bitField0_ & 0x00000004) == 0x00000004);
    }
    /**
     * <pre>
     *发出的时间点(ms毫秒)
     * </pre>
     *
     * <code>required uint64 timecode_native = 3 [default = 0];</code>
     */
    public long getTimecodeNative() {
      return timecodeNative_;
    }

    public static final int COORD_INFO_FIELD_NUMBER = 4;
    private protodef.b_math.coord coordInfo_;
    /**
     * <pre>
     * Earth(j,w).
     * </pre>
     *
     * <code>required .b_math.coord coord_info = 4;</code>
     */
    public boolean hasCoordInfo() {
      return ((bitField0_ & 0x00000008) == 0x00000008);
    }
    /**
     * <pre>
     * Earth(j,w).
     * </pre>
     *
     * <code>required .b_math.coord coord_info = 4;</code>
     */
    public protodef.b_math.coord getCoordInfo() {
      return coordInfo_ == null ? protodef.b_math.coord.getDefaultInstance() : coordInfo_;
    }
    /**
     * <pre>
     * Earth(j,w).
     * </pre>
     *
     * <code>required .b_math.coord coord_info = 4;</code>
     */
    public protodef.b_math.coordOrBuilder getCoordInfoOrBuilder() {
      return coordInfo_ == null ? protodef.b_math.coord.getDefaultInstance() : coordInfo_;
    }

    private byte memoizedIsInitialized = -1;
    public final boolean isInitialized() {
      byte isInitialized = memoizedIsInitialized;
      if (isInitialized == 1) return true;
      if (isInitialized == 0) return false;

      if (!hasEventTime()) {
        memoizedIsInitialized = 0;
        return false;
      }
      if (!hasUid()) {
        memoizedIsInitialized = 0;
        return false;
      }
      if (!hasTimecodeNative()) {
        memoizedIsInitialized = 0;
        return false;
      }
      if (!hasCoordInfo()) {
        memoizedIsInitialized = 0;
        return false;
      }
      if (!getCoordInfo().isInitialized()) {
        memoizedIsInitialized = 0;
        return false;
      }
      memoizedIsInitialized = 1;
      return true;
    }

    public void writeTo(com.google.protobuf.CodedOutputStream output)
                        throws java.io.IOException {
      if (((bitField0_ & 0x00000001) == 0x00000001)) {
        output.writeUInt64(1, eventTime_);
      }
      if (((bitField0_ & 0x00000002) == 0x00000002)) {
        output.writeUInt64(2, uid_);
      }
      if (((bitField0_ & 0x00000004) == 0x00000004)) {
        output.writeUInt64(3, timecodeNative_);
      }
      if (((bitField0_ & 0x00000008) == 0x00000008)) {
        output.writeMessage(4, getCoordInfo());
      }
      unknownFields.writeTo(output);
    }

    public int getSerializedSize() {
      int size = memoizedSize;
      if (size != -1) return size;

      size = 0;
      if (((bitField0_ & 0x00000001) == 0x00000001)) {
        size += com.google.protobuf.CodedOutputStream
          .computeUInt64Size(1, eventTime_);
      }
      if (((bitField0_ & 0x00000002) == 0x00000002)) {
        size += com.google.protobuf.CodedOutputStream
          .computeUInt64Size(2, uid_);
      }
      if (((bitField0_ & 0x00000004) == 0x00000004)) {
        size += com.google.protobuf.CodedOutputStream
          .computeUInt64Size(3, timecodeNative_);
      }
      if (((bitField0_ & 0x00000008) == 0x00000008)) {
        size += com.google.protobuf.CodedOutputStream
          .computeMessageSize(4, getCoordInfo());
      }
      size += unknownFields.getSerializedSize();
      memoizedSize = size;
      return size;
    }

    private static final long serialVersionUID = 0L;
    @java.lang.Override
    public boolean equals(final java.lang.Object obj) {
      if (obj == this) {
       return true;
      }
      if (!(obj instanceof protodef.s_basis.heartbeat_ev)) {
        return super.equals(obj);
      }
      protodef.s_basis.heartbeat_ev other = (protodef.s_basis.heartbeat_ev) obj;

      boolean result = true;
      result = result && (hasEventTime() == other.hasEventTime());
      if (hasEventTime()) {
        result = result && (getEventTime()
            == other.getEventTime());
      }
      result = result && (hasUid() == other.hasUid());
      if (hasUid()) {
        result = result && (getUid()
            == other.getUid());
      }
      result = result && (hasTimecodeNative() == other.hasTimecodeNative());
      if (hasTimecodeNative()) {
        result = result && (getTimecodeNative()
            == other.getTimecodeNative());
      }
      result = result && (hasCoordInfo() == other.hasCoordInfo());
      if (hasCoordInfo()) {
        result = result && getCoordInfo()
            .equals(other.getCoordInfo());
      }
      result = result && unknownFields.equals(other.unknownFields);
      return result;
    }

    @java.lang.Override
    public int hashCode() {
      if (memoizedHashCode != 0) {
        return memoizedHashCode;
      }
      int hash = 41;
      hash = (19 * hash) + getDescriptor().hashCode();
      if (hasEventTime()) {
        hash = (37 * hash) + EVENT_TIME_FIELD_NUMBER;
        hash = (53 * hash) + com.google.protobuf.Internal.hashLong(
            getEventTime());
      }
      if (hasUid()) {
        hash = (37 * hash) + UID_FIELD_NUMBER;
        hash = (53 * hash) + com.google.protobuf.Internal.hashLong(
            getUid());
      }
      if (hasTimecodeNative()) {
        hash = (37 * hash) + TIMECODE_NATIVE_FIELD_NUMBER;
        hash = (53 * hash) + com.google.protobuf.Internal.hashLong(
            getTimecodeNative());
      }
      if (hasCoordInfo()) {
        hash = (37 * hash) + COORD_INFO_FIELD_NUMBER;
        hash = (53 * hash) + getCoordInfo().hashCode();
      }
      hash = (29 * hash) + unknownFields.hashCode();
      memoizedHashCode = hash;
      return hash;
    }

    public static protodef.s_basis.heartbeat_ev parseFrom(
        java.nio.ByteBuffer data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static protodef.s_basis.heartbeat_ev parseFrom(
        java.nio.ByteBuffer data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static protodef.s_basis.heartbeat_ev parseFrom(
        com.google.protobuf.ByteString data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static protodef.s_basis.heartbeat_ev parseFrom(
        com.google.protobuf.ByteString data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static protodef.s_basis.heartbeat_ev parseFrom(byte[] data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static protodef.s_basis.heartbeat_ev parseFrom(
        byte[] data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static protodef.s_basis.heartbeat_ev parseFrom(java.io.InputStream input)
        throws java.io.IOException {
      return com.google.protobuf.GeneratedMessageV3
          .parseWithIOException(PARSER, input);
    }
    public static protodef.s_basis.heartbeat_ev parseFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return com.google.protobuf.GeneratedMessageV3
          .parseWithIOException(PARSER, input, extensionRegistry);
    }
    public static protodef.s_basis.heartbeat_ev parseDelimitedFrom(java.io.InputStream input)
        throws java.io.IOException {
      return com.google.protobuf.GeneratedMessageV3
          .parseDelimitedWithIOException(PARSER, input);
    }
    public static protodef.s_basis.heartbeat_ev parseDelimitedFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return com.google.protobuf.GeneratedMessageV3
          .parseDelimitedWithIOException(PARSER, input, extensionRegistry);
    }
    public static protodef.s_basis.heartbeat_ev parseFrom(
        com.google.protobuf.CodedInputStream input)
        throws java.io.IOException {
      return com.google.protobuf.GeneratedMessageV3
          .parseWithIOException(PARSER, input);
    }
    public static protodef.s_basis.heartbeat_ev parseFrom(
        com.google.protobuf.CodedInputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return com.google.protobuf.GeneratedMessageV3
          .parseWithIOException(PARSER, input, extensionRegistry);
    }

    public Builder newBuilderForType() { return newBuilder(); }
    public static Builder newBuilder() {
      return DEFAULT_INSTANCE.toBuilder();
    }
    public static Builder newBuilder(protodef.s_basis.heartbeat_ev prototype) {
      return DEFAULT_INSTANCE.toBuilder().mergeFrom(prototype);
    }
    public Builder toBuilder() {
      return this == DEFAULT_INSTANCE
          ? new Builder() : new Builder().mergeFrom(this);
    }

    @java.lang.Override
    protected Builder newBuilderForType(
        com.google.protobuf.GeneratedMessageV3.BuilderParent parent) {
      Builder builder = new Builder(parent);
      return builder;
    }
    /**
     * <pre>
     *&#47;///////////////////////////////////////////////////////////////
     * heartbeat
     * </pre>
     *
     * Protobuf type {@code s_basis.heartbeat_ev}
     */
    public static final class Builder extends
        com.google.protobuf.GeneratedMessageV3.Builder<Builder> implements
        // @@protoc_insertion_point(builder_implements:s_basis.heartbeat_ev)
        protodef.s_basis.heartbeat_evOrBuilder {
      public static final com.google.protobuf.Descriptors.Descriptor
          getDescriptor() {
        return protodef.s_basis.internal_static_s_basis_heartbeat_ev_descriptor;
      }

      protected com.google.protobuf.GeneratedMessageV3.FieldAccessorTable
          internalGetFieldAccessorTable() {
        return protodef.s_basis.internal_static_s_basis_heartbeat_ev_fieldAccessorTable
            .ensureFieldAccessorsInitialized(
                protodef.s_basis.heartbeat_ev.class, protodef.s_basis.heartbeat_ev.Builder.class);
      }

      // Construct using protodef.s_basis.heartbeat_ev.newBuilder()
      private Builder() {
        maybeForceBuilderInitialization();
      }

      private Builder(
          com.google.protobuf.GeneratedMessageV3.BuilderParent parent) {
        super(parent);
        maybeForceBuilderInitialization();
      }
      private void maybeForceBuilderInitialization() {
        if (com.google.protobuf.GeneratedMessageV3
                .alwaysUseFieldBuilders) {
          getCoordInfoFieldBuilder();
        }
      }
      public Builder clear() {
        super.clear();
        eventTime_ = 0L;
        bitField0_ = (bitField0_ & ~0x00000001);
        uid_ = 0L;
        bitField0_ = (bitField0_ & ~0x00000002);
        timecodeNative_ = 0L;
        bitField0_ = (bitField0_ & ~0x00000004);
        if (coordInfoBuilder_ == null) {
          coordInfo_ = null;
        } else {
          coordInfoBuilder_.clear();
        }
        bitField0_ = (bitField0_ & ~0x00000008);
        return this;
      }

      public com.google.protobuf.Descriptors.Descriptor
          getDescriptorForType() {
        return protodef.s_basis.internal_static_s_basis_heartbeat_ev_descriptor;
      }

      public protodef.s_basis.heartbeat_ev getDefaultInstanceForType() {
        return protodef.s_basis.heartbeat_ev.getDefaultInstance();
      }

      public protodef.s_basis.heartbeat_ev build() {
        protodef.s_basis.heartbeat_ev result = buildPartial();
        if (!result.isInitialized()) {
          throw newUninitializedMessageException(result);
        }
        return result;
      }

      public protodef.s_basis.heartbeat_ev buildPartial() {
        protodef.s_basis.heartbeat_ev result = new protodef.s_basis.heartbeat_ev(this);
        int from_bitField0_ = bitField0_;
        int to_bitField0_ = 0;
        if (((from_bitField0_ & 0x00000001) == 0x00000001)) {
          to_bitField0_ |= 0x00000001;
        }
        result.eventTime_ = eventTime_;
        if (((from_bitField0_ & 0x00000002) == 0x00000002)) {
          to_bitField0_ |= 0x00000002;
        }
        result.uid_ = uid_;
        if (((from_bitField0_ & 0x00000004) == 0x00000004)) {
          to_bitField0_ |= 0x00000004;
        }
        result.timecodeNative_ = timecodeNative_;
        if (((from_bitField0_ & 0x00000008) == 0x00000008)) {
          to_bitField0_ |= 0x00000008;
        }
        if (coordInfoBuilder_ == null) {
          result.coordInfo_ = coordInfo_;
        } else {
          result.coordInfo_ = coordInfoBuilder_.build();
        }
        result.bitField0_ = to_bitField0_;
        onBuilt();
        return result;
      }

      public Builder clone() {
        return (Builder) super.clone();
      }
      public Builder setField(
          com.google.protobuf.Descriptors.FieldDescriptor field,
          Object value) {
        return (Builder) super.setField(field, value);
      }
      public Builder clearField(
          com.google.protobuf.Descriptors.FieldDescriptor field) {
        return (Builder) super.clearField(field);
      }
      public Builder clearOneof(
          com.google.protobuf.Descriptors.OneofDescriptor oneof) {
        return (Builder) super.clearOneof(oneof);
      }
      public Builder setRepeatedField(
          com.google.protobuf.Descriptors.FieldDescriptor field,
          int index, Object value) {
        return (Builder) super.setRepeatedField(field, index, value);
      }
      public Builder addRepeatedField(
          com.google.protobuf.Descriptors.FieldDescriptor field,
          Object value) {
        return (Builder) super.addRepeatedField(field, value);
      }
      public Builder mergeFrom(com.google.protobuf.Message other) {
        if (other instanceof protodef.s_basis.heartbeat_ev) {
          return mergeFrom((protodef.s_basis.heartbeat_ev)other);
        } else {
          super.mergeFrom(other);
          return this;
        }
      }

      public Builder mergeFrom(protodef.s_basis.heartbeat_ev other) {
        if (other == protodef.s_basis.heartbeat_ev.getDefaultInstance()) return this;
        if (other.hasEventTime()) {
          setEventTime(other.getEventTime());
        }
        if (other.hasUid()) {
          setUid(other.getUid());
        }
        if (other.hasTimecodeNative()) {
          setTimecodeNative(other.getTimecodeNative());
        }
        if (other.hasCoordInfo()) {
          mergeCoordInfo(other.getCoordInfo());
        }
        this.mergeUnknownFields(other.unknownFields);
        onChanged();
        return this;
      }

      public final boolean isInitialized() {
        if (!hasEventTime()) {
          return false;
        }
        if (!hasUid()) {
          return false;
        }
        if (!hasTimecodeNative()) {
          return false;
        }
        if (!hasCoordInfo()) {
          return false;
        }
        if (!getCoordInfo().isInitialized()) {
          return false;
        }
        return true;
      }

      public Builder mergeFrom(
          com.google.protobuf.CodedInputStream input,
          com.google.protobuf.ExtensionRegistryLite extensionRegistry)
          throws java.io.IOException {
        protodef.s_basis.heartbeat_ev parsedMessage = null;
        try {
          parsedMessage = PARSER.parsePartialFrom(input, extensionRegistry);
        } catch (com.google.protobuf.InvalidProtocolBufferException e) {
          parsedMessage = (protodef.s_basis.heartbeat_ev) e.getUnfinishedMessage();
          throw e.unwrapIOException();
        } finally {
          if (parsedMessage != null) {
            mergeFrom(parsedMessage);
          }
        }
        return this;
      }
      private int bitField0_;

      private long eventTime_ ;
      /**
       * <pre>
       * 事件发生时间戳(毫秒)
       * </pre>
       *
       * <code>required uint64 event_time = 1 [default = 0];</code>
       */
      public boolean hasEventTime() {
        return ((bitField0_ & 0x00000001) == 0x00000001);
      }
      /**
       * <pre>
       * 事件发生时间戳(毫秒)
       * </pre>
       *
       * <code>required uint64 event_time = 1 [default = 0];</code>
       */
      public long getEventTime() {
        return eventTime_;
      }
      /**
       * <pre>
       * 事件发生时间戳(毫秒)
       * </pre>
       *
       * <code>required uint64 event_time = 1 [default = 0];</code>
       */
      public Builder setEventTime(long value) {
        bitField0_ |= 0x00000001;
        eventTime_ = value;
        onChanged();
        return this;
      }
      /**
       * <pre>
       * 事件发生时间戳(毫秒)
       * </pre>
       *
       * <code>required uint64 event_time = 1 [default = 0];</code>
       */
      public Builder clearEventTime() {
        bitField0_ = (bitField0_ & ~0x00000001);
        eventTime_ = 0L;
        onChanged();
        return this;
      }

      private long uid_ ;
      /**
       * <pre>
       *用户ID
       * </pre>
       *
       * <code>required uint64 uid = 2 [default = 0];</code>
       */
      public boolean hasUid() {
        return ((bitField0_ & 0x00000002) == 0x00000002);
      }
      /**
       * <pre>
       *用户ID
       * </pre>
       *
       * <code>required uint64 uid = 2 [default = 0];</code>
       */
      public long getUid() {
        return uid_;
      }
      /**
       * <pre>
       *用户ID
       * </pre>
       *
       * <code>required uint64 uid = 2 [default = 0];</code>
       */
      public Builder setUid(long value) {
        bitField0_ |= 0x00000002;
        uid_ = value;
        onChanged();
        return this;
      }
      /**
       * <pre>
       *用户ID
       * </pre>
       *
       * <code>required uint64 uid = 2 [default = 0];</code>
       */
      public Builder clearUid() {
        bitField0_ = (bitField0_ & ~0x00000002);
        uid_ = 0L;
        onChanged();
        return this;
      }

      private long timecodeNative_ ;
      /**
       * <pre>
       *发出的时间点(ms毫秒)
       * </pre>
       *
       * <code>required uint64 timecode_native = 3 [default = 0];</code>
       */
      public boolean hasTimecodeNative() {
        return ((bitField0_ & 0x00000004) == 0x00000004);
      }
      /**
       * <pre>
       *发出的时间点(ms毫秒)
       * </pre>
       *
       * <code>required uint64 timecode_native = 3 [default = 0];</code>
       */
      public long getTimecodeNative() {
        return timecodeNative_;
      }
      /**
       * <pre>
       *发出的时间点(ms毫秒)
       * </pre>
       *
       * <code>required uint64 timecode_native = 3 [default = 0];</code>
       */
      public Builder setTimecodeNative(long value) {
        bitField0_ |= 0x00000004;
        timecodeNative_ = value;
        onChanged();
        return this;
      }
      /**
       * <pre>
       *发出的时间点(ms毫秒)
       * </pre>
       *
       * <code>required uint64 timecode_native = 3 [default = 0];</code>
       */
      public Builder clearTimecodeNative() {
        bitField0_ = (bitField0_ & ~0x00000004);
        timecodeNative_ = 0L;
        onChanged();
        return this;
      }

      private protodef.b_math.coord coordInfo_ = null;
      private com.google.protobuf.SingleFieldBuilderV3<
          protodef.b_math.coord, protodef.b_math.coord.Builder, protodef.b_math.coordOrBuilder> coordInfoBuilder_;
      /**
       * <pre>
       * Earth(j,w).
       * </pre>
       *
       * <code>required .b_math.coord coord_info = 4;</code>
       */
      public boolean hasCoordInfo() {
        return ((bitField0_ & 0x00000008) == 0x00000008);
      }
      /**
       * <pre>
       * Earth(j,w).
       * </pre>
       *
       * <code>required .b_math.coord coord_info = 4;</code>
       */
      public protodef.b_math.coord getCoordInfo() {
        if (coordInfoBuilder_ == null) {
          return coordInfo_ == null ? protodef.b_math.coord.getDefaultInstance() : coordInfo_;
        } else {
          return coordInfoBuilder_.getMessage();
        }
      }
      /**
       * <pre>
       * Earth(j,w).
       * </pre>
       *
       * <code>required .b_math.coord coord_info = 4;</code>
       */
      public Builder setCoordInfo(protodef.b_math.coord value) {
        if (coordInfoBuilder_ == null) {
          if (value == null) {
            throw new NullPointerException();
          }
          coordInfo_ = value;
          onChanged();
        } else {
          coordInfoBuilder_.setMessage(value);
        }
        bitField0_ |= 0x00000008;
        return this;
      }
      /**
       * <pre>
       * Earth(j,w).
       * </pre>
       *
       * <code>required .b_math.coord coord_info = 4;</code>
       */
      public Builder setCoordInfo(
          protodef.b_math.coord.Builder builderForValue) {
        if (coordInfoBuilder_ == null) {
          coordInfo_ = builderForValue.build();
          onChanged();
        } else {
          coordInfoBuilder_.setMessage(builderForValue.build());
        }
        bitField0_ |= 0x00000008;
        return this;
      }
      /**
       * <pre>
       * Earth(j,w).
       * </pre>
       *
       * <code>required .b_math.coord coord_info = 4;</code>
       */
      public Builder mergeCoordInfo(protodef.b_math.coord value) {
        if (coordInfoBuilder_ == null) {
          if (((bitField0_ & 0x00000008) == 0x00000008) &&
              coordInfo_ != null &&
              coordInfo_ != protodef.b_math.coord.getDefaultInstance()) {
            coordInfo_ =
              protodef.b_math.coord.newBuilder(coordInfo_).mergeFrom(value).buildPartial();
          } else {
            coordInfo_ = value;
          }
          onChanged();
        } else {
          coordInfoBuilder_.mergeFrom(value);
        }
        bitField0_ |= 0x00000008;
        return this;
      }
      /**
       * <pre>
       * Earth(j,w).
       * </pre>
       *
       * <code>required .b_math.coord coord_info = 4;</code>
       */
      public Builder clearCoordInfo() {
        if (coordInfoBuilder_ == null) {
          coordInfo_ = null;
          onChanged();
        } else {
          coordInfoBuilder_.clear();
        }
        bitField0_ = (bitField0_ & ~0x00000008);
        return this;
      }
      /**
       * <pre>
       * Earth(j,w).
       * </pre>
       *
       * <code>required .b_math.coord coord_info = 4;</code>
       */
      public protodef.b_math.coord.Builder getCoordInfoBuilder() {
        bitField0_ |= 0x00000008;
        onChanged();
        return getCoordInfoFieldBuilder().getBuilder();
      }
      /**
       * <pre>
       * Earth(j,w).
       * </pre>
       *
       * <code>required .b_math.coord coord_info = 4;</code>
       */
      public protodef.b_math.coordOrBuilder getCoordInfoOrBuilder() {
        if (coordInfoBuilder_ != null) {
          return coordInfoBuilder_.getMessageOrBuilder();
        } else {
          return coordInfo_ == null ?
              protodef.b_math.coord.getDefaultInstance() : coordInfo_;
        }
      }
      /**
       * <pre>
       * Earth(j,w).
       * </pre>
       *
       * <code>required .b_math.coord coord_info = 4;</code>
       */
      private com.google.protobuf.SingleFieldBuilderV3<
          protodef.b_math.coord, protodef.b_math.coord.Builder, protodef.b_math.coordOrBuilder> 
          getCoordInfoFieldBuilder() {
        if (coordInfoBuilder_ == null) {
          coordInfoBuilder_ = new com.google.protobuf.SingleFieldBuilderV3<
              protodef.b_math.coord, protodef.b_math.coord.Builder, protodef.b_math.coordOrBuilder>(
                  getCoordInfo(),
                  getParentForChildren(),
                  isClean());
          coordInfo_ = null;
        }
        return coordInfoBuilder_;
      }
      public final Builder setUnknownFields(
          final com.google.protobuf.UnknownFieldSet unknownFields) {
        return super.setUnknownFields(unknownFields);
      }

      public final Builder mergeUnknownFields(
          final com.google.protobuf.UnknownFieldSet unknownFields) {
        return super.mergeUnknownFields(unknownFields);
      }


      // @@protoc_insertion_point(builder_scope:s_basis.heartbeat_ev)
    }

    // @@protoc_insertion_point(class_scope:s_basis.heartbeat_ev)
    private static final protodef.s_basis.heartbeat_ev DEFAULT_INSTANCE;
    static {
      DEFAULT_INSTANCE = new protodef.s_basis.heartbeat_ev();
    }

    public static protodef.s_basis.heartbeat_ev getDefaultInstance() {
      return DEFAULT_INSTANCE;
    }

    @java.lang.Deprecated public static final com.google.protobuf.Parser<heartbeat_ev>
        PARSER = new com.google.protobuf.AbstractParser<heartbeat_ev>() {
      public heartbeat_ev parsePartialFrom(
          com.google.protobuf.CodedInputStream input,
          com.google.protobuf.ExtensionRegistryLite extensionRegistry)
          throws com.google.protobuf.InvalidProtocolBufferException {
          return new heartbeat_ev(input, extensionRegistry);
      }
    };

    public static com.google.protobuf.Parser<heartbeat_ev> parser() {
      return PARSER;
    }

    @java.lang.Override
    public com.google.protobuf.Parser<heartbeat_ev> getParserForType() {
      return PARSER;
    }

    public protodef.s_basis.heartbeat_ev getDefaultInstanceForType() {
      return DEFAULT_INSTANCE;
    }

  }

  private static final com.google.protobuf.Descriptors.Descriptor
    internal_static_s_basis_heartbeat_ev_descriptor;
  private static final 
    com.google.protobuf.GeneratedMessageV3.FieldAccessorTable
      internal_static_s_basis_heartbeat_ev_fieldAccessorTable;

  public static com.google.protobuf.Descriptors.FileDescriptor
      getDescriptor() {
    return descriptor;
  }
  private static  com.google.protobuf.Descriptors.FileDescriptor
      descriptor;
  static {
    java.lang.String[] descriptorData = {
      "\n\rs_basis.proto\022\007s_basis\032\014b_math.proto\"\206" +
      "\001\n\014heartbeat_ev\022\025\n\nevent_time\030\001 \002(\004:\0010\022\016" +
      "\n\003uid\030\002 \002(\004:\0010\022\032\n\017timecode_native\030\003 \002(\004:" +
      "\0010\022!\n\ncoord_info\030\004 \002(\0132\r.b_math.coord\"\020\n" +
      "\003msg\022\t\n\002id\020\200\240\200\010*#\n\003msg\022\r\n\006min_id\020\200\240\200\010\022\r\n" +
      "\006max_id\020\377\241\200\010B9\n\010protodefB\007s_basisZ\020proto" +
      "def/s_basis\242\002\007S_basis\252\002\007s_basis"
    };
    com.google.protobuf.Descriptors.FileDescriptor.InternalDescriptorAssigner assigner =
        new com.google.protobuf.Descriptors.FileDescriptor.    InternalDescriptorAssigner() {
          public com.google.protobuf.ExtensionRegistry assignDescriptors(
              com.google.protobuf.Descriptors.FileDescriptor root) {
            descriptor = root;
            return null;
          }
        };
    com.google.protobuf.Descriptors.FileDescriptor
      .internalBuildGeneratedFileFrom(descriptorData,
        new com.google.protobuf.Descriptors.FileDescriptor[] {
          protodef.b_math.getDescriptor(),
        }, assigner);
    internal_static_s_basis_heartbeat_ev_descriptor =
      getDescriptor().getMessageTypes().get(0);
    internal_static_s_basis_heartbeat_ev_fieldAccessorTable = new
      com.google.protobuf.GeneratedMessageV3.FieldAccessorTable(
        internal_static_s_basis_heartbeat_ev_descriptor,
        new java.lang.String[] { "EventTime", "Uid", "TimecodeNative", "CoordInfo", });
    protodef.b_math.getDescriptor();
  }

  // @@protoc_insertion_point(outer_class_scope)
}
