// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: b_error.proto

package protodef;

public final class b_error {
  private b_error() {}
  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistryLite registry) {
  }

  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistry registry) {
    registerAllExtensions(
        (com.google.protobuf.ExtensionRegistryLite) registry);
  }
  public interface infoOrBuilder extends
      // @@protoc_insertion_point(interface_extends:b_error.info)
      com.google.protobuf.MessageOrBuilder {

    /**
     * <pre>
     * 0 为成功
     * </pre>
     *
     * <code>required uint32 code = 1 [default = 0];</code>
     */
    boolean hasCode();
    /**
     * <pre>
     * 0 为成功
     * </pre>
     *
     * <code>required uint32 code = 1 [default = 0];</code>
     */
    int getCode();

    /**
     * <pre>
     * 错误描述
     * </pre>
     *
     * <code>required string desc = 2 [default = ""];</code>
     */
    boolean hasDesc();
    /**
     * <pre>
     * 错误描述
     * </pre>
     *
     * <code>required string desc = 2 [default = ""];</code>
     */
    java.lang.String getDesc();
    /**
     * <pre>
     * 错误描述
     * </pre>
     *
     * <code>required string desc = 2 [default = ""];</code>
     */
    com.google.protobuf.ByteString
        getDescBytes();
  }
  /**
   * <pre>
   * 错误信息
   * </pre>
   *
   * Protobuf type {@code b_error.info}
   */
  public  static final class info extends
      com.google.protobuf.GeneratedMessageV3 implements
      // @@protoc_insertion_point(message_implements:b_error.info)
      infoOrBuilder {
    // Use info.newBuilder() to construct.
    private info(com.google.protobuf.GeneratedMessageV3.Builder<?> builder) {
      super(builder);
    }
    private info() {
      code_ = 0;
      desc_ = "";
    }

    @java.lang.Override
    public final com.google.protobuf.UnknownFieldSet
    getUnknownFields() {
      return this.unknownFields;
    }
    private info(
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
              code_ = input.readUInt32();
              break;
            }
            case 18: {
              com.google.protobuf.ByteString bs = input.readBytes();
              bitField0_ |= 0x00000002;
              desc_ = bs;
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
      return protodef.b_error.internal_static_b_error_info_descriptor;
    }

    protected com.google.protobuf.GeneratedMessageV3.FieldAccessorTable
        internalGetFieldAccessorTable() {
      return protodef.b_error.internal_static_b_error_info_fieldAccessorTable
          .ensureFieldAccessorsInitialized(
              protodef.b_error.info.class, protodef.b_error.info.Builder.class);
    }

    private int bitField0_;
    public static final int CODE_FIELD_NUMBER = 1;
    private int code_;
    /**
     * <pre>
     * 0 为成功
     * </pre>
     *
     * <code>required uint32 code = 1 [default = 0];</code>
     */
    public boolean hasCode() {
      return ((bitField0_ & 0x00000001) == 0x00000001);
    }
    /**
     * <pre>
     * 0 为成功
     * </pre>
     *
     * <code>required uint32 code = 1 [default = 0];</code>
     */
    public int getCode() {
      return code_;
    }

    public static final int DESC_FIELD_NUMBER = 2;
    private volatile java.lang.Object desc_;
    /**
     * <pre>
     * 错误描述
     * </pre>
     *
     * <code>required string desc = 2 [default = ""];</code>
     */
    public boolean hasDesc() {
      return ((bitField0_ & 0x00000002) == 0x00000002);
    }
    /**
     * <pre>
     * 错误描述
     * </pre>
     *
     * <code>required string desc = 2 [default = ""];</code>
     */
    public java.lang.String getDesc() {
      java.lang.Object ref = desc_;
      if (ref instanceof java.lang.String) {
        return (java.lang.String) ref;
      } else {
        com.google.protobuf.ByteString bs = 
            (com.google.protobuf.ByteString) ref;
        java.lang.String s = bs.toStringUtf8();
        if (bs.isValidUtf8()) {
          desc_ = s;
        }
        return s;
      }
    }
    /**
     * <pre>
     * 错误描述
     * </pre>
     *
     * <code>required string desc = 2 [default = ""];</code>
     */
    public com.google.protobuf.ByteString
        getDescBytes() {
      java.lang.Object ref = desc_;
      if (ref instanceof java.lang.String) {
        com.google.protobuf.ByteString b = 
            com.google.protobuf.ByteString.copyFromUtf8(
                (java.lang.String) ref);
        desc_ = b;
        return b;
      } else {
        return (com.google.protobuf.ByteString) ref;
      }
    }

    private byte memoizedIsInitialized = -1;
    public final boolean isInitialized() {
      byte isInitialized = memoizedIsInitialized;
      if (isInitialized == 1) return true;
      if (isInitialized == 0) return false;

      if (!hasCode()) {
        memoizedIsInitialized = 0;
        return false;
      }
      if (!hasDesc()) {
        memoizedIsInitialized = 0;
        return false;
      }
      memoizedIsInitialized = 1;
      return true;
    }

    public void writeTo(com.google.protobuf.CodedOutputStream output)
                        throws java.io.IOException {
      if (((bitField0_ & 0x00000001) == 0x00000001)) {
        output.writeUInt32(1, code_);
      }
      if (((bitField0_ & 0x00000002) == 0x00000002)) {
        com.google.protobuf.GeneratedMessageV3.writeString(output, 2, desc_);
      }
      unknownFields.writeTo(output);
    }

    public int getSerializedSize() {
      int size = memoizedSize;
      if (size != -1) return size;

      size = 0;
      if (((bitField0_ & 0x00000001) == 0x00000001)) {
        size += com.google.protobuf.CodedOutputStream
          .computeUInt32Size(1, code_);
      }
      if (((bitField0_ & 0x00000002) == 0x00000002)) {
        size += com.google.protobuf.GeneratedMessageV3.computeStringSize(2, desc_);
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
      if (!(obj instanceof protodef.b_error.info)) {
        return super.equals(obj);
      }
      protodef.b_error.info other = (protodef.b_error.info) obj;

      boolean result = true;
      result = result && (hasCode() == other.hasCode());
      if (hasCode()) {
        result = result && (getCode()
            == other.getCode());
      }
      result = result && (hasDesc() == other.hasDesc());
      if (hasDesc()) {
        result = result && getDesc()
            .equals(other.getDesc());
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
      if (hasCode()) {
        hash = (37 * hash) + CODE_FIELD_NUMBER;
        hash = (53 * hash) + getCode();
      }
      if (hasDesc()) {
        hash = (37 * hash) + DESC_FIELD_NUMBER;
        hash = (53 * hash) + getDesc().hashCode();
      }
      hash = (29 * hash) + unknownFields.hashCode();
      memoizedHashCode = hash;
      return hash;
    }

    public static protodef.b_error.info parseFrom(
        java.nio.ByteBuffer data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static protodef.b_error.info parseFrom(
        java.nio.ByteBuffer data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static protodef.b_error.info parseFrom(
        com.google.protobuf.ByteString data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static protodef.b_error.info parseFrom(
        com.google.protobuf.ByteString data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static protodef.b_error.info parseFrom(byte[] data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static protodef.b_error.info parseFrom(
        byte[] data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static protodef.b_error.info parseFrom(java.io.InputStream input)
        throws java.io.IOException {
      return com.google.protobuf.GeneratedMessageV3
          .parseWithIOException(PARSER, input);
    }
    public static protodef.b_error.info parseFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return com.google.protobuf.GeneratedMessageV3
          .parseWithIOException(PARSER, input, extensionRegistry);
    }
    public static protodef.b_error.info parseDelimitedFrom(java.io.InputStream input)
        throws java.io.IOException {
      return com.google.protobuf.GeneratedMessageV3
          .parseDelimitedWithIOException(PARSER, input);
    }
    public static protodef.b_error.info parseDelimitedFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return com.google.protobuf.GeneratedMessageV3
          .parseDelimitedWithIOException(PARSER, input, extensionRegistry);
    }
    public static protodef.b_error.info parseFrom(
        com.google.protobuf.CodedInputStream input)
        throws java.io.IOException {
      return com.google.protobuf.GeneratedMessageV3
          .parseWithIOException(PARSER, input);
    }
    public static protodef.b_error.info parseFrom(
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
    public static Builder newBuilder(protodef.b_error.info prototype) {
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
     * 错误信息
     * </pre>
     *
     * Protobuf type {@code b_error.info}
     */
    public static final class Builder extends
        com.google.protobuf.GeneratedMessageV3.Builder<Builder> implements
        // @@protoc_insertion_point(builder_implements:b_error.info)
        protodef.b_error.infoOrBuilder {
      public static final com.google.protobuf.Descriptors.Descriptor
          getDescriptor() {
        return protodef.b_error.internal_static_b_error_info_descriptor;
      }

      protected com.google.protobuf.GeneratedMessageV3.FieldAccessorTable
          internalGetFieldAccessorTable() {
        return protodef.b_error.internal_static_b_error_info_fieldAccessorTable
            .ensureFieldAccessorsInitialized(
                protodef.b_error.info.class, protodef.b_error.info.Builder.class);
      }

      // Construct using protodef.b_error.info.newBuilder()
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
        }
      }
      public Builder clear() {
        super.clear();
        code_ = 0;
        bitField0_ = (bitField0_ & ~0x00000001);
        desc_ = "";
        bitField0_ = (bitField0_ & ~0x00000002);
        return this;
      }

      public com.google.protobuf.Descriptors.Descriptor
          getDescriptorForType() {
        return protodef.b_error.internal_static_b_error_info_descriptor;
      }

      public protodef.b_error.info getDefaultInstanceForType() {
        return protodef.b_error.info.getDefaultInstance();
      }

      public protodef.b_error.info build() {
        protodef.b_error.info result = buildPartial();
        if (!result.isInitialized()) {
          throw newUninitializedMessageException(result);
        }
        return result;
      }

      public protodef.b_error.info buildPartial() {
        protodef.b_error.info result = new protodef.b_error.info(this);
        int from_bitField0_ = bitField0_;
        int to_bitField0_ = 0;
        if (((from_bitField0_ & 0x00000001) == 0x00000001)) {
          to_bitField0_ |= 0x00000001;
        }
        result.code_ = code_;
        if (((from_bitField0_ & 0x00000002) == 0x00000002)) {
          to_bitField0_ |= 0x00000002;
        }
        result.desc_ = desc_;
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
        if (other instanceof protodef.b_error.info) {
          return mergeFrom((protodef.b_error.info)other);
        } else {
          super.mergeFrom(other);
          return this;
        }
      }

      public Builder mergeFrom(protodef.b_error.info other) {
        if (other == protodef.b_error.info.getDefaultInstance()) return this;
        if (other.hasCode()) {
          setCode(other.getCode());
        }
        if (other.hasDesc()) {
          bitField0_ |= 0x00000002;
          desc_ = other.desc_;
          onChanged();
        }
        this.mergeUnknownFields(other.unknownFields);
        onChanged();
        return this;
      }

      public final boolean isInitialized() {
        if (!hasCode()) {
          return false;
        }
        if (!hasDesc()) {
          return false;
        }
        return true;
      }

      public Builder mergeFrom(
          com.google.protobuf.CodedInputStream input,
          com.google.protobuf.ExtensionRegistryLite extensionRegistry)
          throws java.io.IOException {
        protodef.b_error.info parsedMessage = null;
        try {
          parsedMessage = PARSER.parsePartialFrom(input, extensionRegistry);
        } catch (com.google.protobuf.InvalidProtocolBufferException e) {
          parsedMessage = (protodef.b_error.info) e.getUnfinishedMessage();
          throw e.unwrapIOException();
        } finally {
          if (parsedMessage != null) {
            mergeFrom(parsedMessage);
          }
        }
        return this;
      }
      private int bitField0_;

      private int code_ ;
      /**
       * <pre>
       * 0 为成功
       * </pre>
       *
       * <code>required uint32 code = 1 [default = 0];</code>
       */
      public boolean hasCode() {
        return ((bitField0_ & 0x00000001) == 0x00000001);
      }
      /**
       * <pre>
       * 0 为成功
       * </pre>
       *
       * <code>required uint32 code = 1 [default = 0];</code>
       */
      public int getCode() {
        return code_;
      }
      /**
       * <pre>
       * 0 为成功
       * </pre>
       *
       * <code>required uint32 code = 1 [default = 0];</code>
       */
      public Builder setCode(int value) {
        bitField0_ |= 0x00000001;
        code_ = value;
        onChanged();
        return this;
      }
      /**
       * <pre>
       * 0 为成功
       * </pre>
       *
       * <code>required uint32 code = 1 [default = 0];</code>
       */
      public Builder clearCode() {
        bitField0_ = (bitField0_ & ~0x00000001);
        code_ = 0;
        onChanged();
        return this;
      }

      private java.lang.Object desc_ = "";
      /**
       * <pre>
       * 错误描述
       * </pre>
       *
       * <code>required string desc = 2 [default = ""];</code>
       */
      public boolean hasDesc() {
        return ((bitField0_ & 0x00000002) == 0x00000002);
      }
      /**
       * <pre>
       * 错误描述
       * </pre>
       *
       * <code>required string desc = 2 [default = ""];</code>
       */
      public java.lang.String getDesc() {
        java.lang.Object ref = desc_;
        if (!(ref instanceof java.lang.String)) {
          com.google.protobuf.ByteString bs =
              (com.google.protobuf.ByteString) ref;
          java.lang.String s = bs.toStringUtf8();
          if (bs.isValidUtf8()) {
            desc_ = s;
          }
          return s;
        } else {
          return (java.lang.String) ref;
        }
      }
      /**
       * <pre>
       * 错误描述
       * </pre>
       *
       * <code>required string desc = 2 [default = ""];</code>
       */
      public com.google.protobuf.ByteString
          getDescBytes() {
        java.lang.Object ref = desc_;
        if (ref instanceof String) {
          com.google.protobuf.ByteString b = 
              com.google.protobuf.ByteString.copyFromUtf8(
                  (java.lang.String) ref);
          desc_ = b;
          return b;
        } else {
          return (com.google.protobuf.ByteString) ref;
        }
      }
      /**
       * <pre>
       * 错误描述
       * </pre>
       *
       * <code>required string desc = 2 [default = ""];</code>
       */
      public Builder setDesc(
          java.lang.String value) {
        if (value == null) {
    throw new NullPointerException();
  }
  bitField0_ |= 0x00000002;
        desc_ = value;
        onChanged();
        return this;
      }
      /**
       * <pre>
       * 错误描述
       * </pre>
       *
       * <code>required string desc = 2 [default = ""];</code>
       */
      public Builder clearDesc() {
        bitField0_ = (bitField0_ & ~0x00000002);
        desc_ = getDefaultInstance().getDesc();
        onChanged();
        return this;
      }
      /**
       * <pre>
       * 错误描述
       * </pre>
       *
       * <code>required string desc = 2 [default = ""];</code>
       */
      public Builder setDescBytes(
          com.google.protobuf.ByteString value) {
        if (value == null) {
    throw new NullPointerException();
  }
  bitField0_ |= 0x00000002;
        desc_ = value;
        onChanged();
        return this;
      }
      public final Builder setUnknownFields(
          final com.google.protobuf.UnknownFieldSet unknownFields) {
        return super.setUnknownFields(unknownFields);
      }

      public final Builder mergeUnknownFields(
          final com.google.protobuf.UnknownFieldSet unknownFields) {
        return super.mergeUnknownFields(unknownFields);
      }


      // @@protoc_insertion_point(builder_scope:b_error.info)
    }

    // @@protoc_insertion_point(class_scope:b_error.info)
    private static final protodef.b_error.info DEFAULT_INSTANCE;
    static {
      DEFAULT_INSTANCE = new protodef.b_error.info();
    }

    public static protodef.b_error.info getDefaultInstance() {
      return DEFAULT_INSTANCE;
    }

    @java.lang.Deprecated public static final com.google.protobuf.Parser<info>
        PARSER = new com.google.protobuf.AbstractParser<info>() {
      public info parsePartialFrom(
          com.google.protobuf.CodedInputStream input,
          com.google.protobuf.ExtensionRegistryLite extensionRegistry)
          throws com.google.protobuf.InvalidProtocolBufferException {
          return new info(input, extensionRegistry);
      }
    };

    public static com.google.protobuf.Parser<info> parser() {
      return PARSER;
    }

    @java.lang.Override
    public com.google.protobuf.Parser<info> getParserForType() {
      return PARSER;
    }

    public protodef.b_error.info getDefaultInstanceForType() {
      return DEFAULT_INSTANCE;
    }

  }

  private static final com.google.protobuf.Descriptors.Descriptor
    internal_static_b_error_info_descriptor;
  private static final 
    com.google.protobuf.GeneratedMessageV3.FieldAccessorTable
      internal_static_b_error_info_fieldAccessorTable;

  public static com.google.protobuf.Descriptors.FileDescriptor
      getDescriptor() {
    return descriptor;
  }
  private static  com.google.protobuf.Descriptors.FileDescriptor
      descriptor;
  static {
    java.lang.String[] descriptorData = {
      "\n\rb_error.proto\022\007b_error\"\'\n\004info\022\017\n\004code" +
      "\030\001 \002(\r:\0010\022\016\n\004desc\030\002 \002(\t:\000B:\n\010protodefB\007b" +
      "_errorZ\020protodef/b_error\242\002\010B_error_\252\002\007b_" +
      "error"
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
        }, assigner);
    internal_static_b_error_info_descriptor =
      getDescriptor().getMessageTypes().get(0);
    internal_static_b_error_info_fieldAccessorTable = new
      com.google.protobuf.GeneratedMessageV3.FieldAccessorTable(
        internal_static_b_error_info_descriptor,
        new java.lang.String[] { "Code", "Desc", });
  }

  // @@protoc_insertion_point(outer_class_scope)
}
