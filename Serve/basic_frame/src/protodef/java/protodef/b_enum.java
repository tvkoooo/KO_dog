// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: b_enum.proto

package protodef;

public final class b_enum {
  private b_enum() {}
  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistryLite registry) {
  }

  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistry registry) {
    registerAllExtensions(
        (com.google.protobuf.ExtensionRegistryLite) registry);
  }
  /**
   * Protobuf enum {@code b_enum.reply_t}
   */
  public enum reply_t
      implements com.google.protobuf.ProtocolMessageEnum {
    /**
     * <pre>
     * 接受
     * </pre>
     *
     * <code>accept = 0;</code>
     */
    accept(0),
    /**
     * <pre>
     * 拒绝
     * </pre>
     *
     * <code>refuse = 1;</code>
     */
    refuse(1),
    ;

    /**
     * <pre>
     * 接受
     * </pre>
     *
     * <code>accept = 0;</code>
     */
    public static final int accept_VALUE = 0;
    /**
     * <pre>
     * 拒绝
     * </pre>
     *
     * <code>refuse = 1;</code>
     */
    public static final int refuse_VALUE = 1;


    public final int getNumber() {
      return value;
    }

    /**
     * @deprecated Use {@link #forNumber(int)} instead.
     */
    @java.lang.Deprecated
    public static reply_t valueOf(int value) {
      return forNumber(value);
    }

    public static reply_t forNumber(int value) {
      switch (value) {
        case 0: return accept;
        case 1: return refuse;
        default: return null;
      }
    }

    public static com.google.protobuf.Internal.EnumLiteMap<reply_t>
        internalGetValueMap() {
      return internalValueMap;
    }
    private static final com.google.protobuf.Internal.EnumLiteMap<
        reply_t> internalValueMap =
          new com.google.protobuf.Internal.EnumLiteMap<reply_t>() {
            public reply_t findValueByNumber(int number) {
              return reply_t.forNumber(number);
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
      return protodef.b_enum.getDescriptor().getEnumTypes().get(0);
    }

    private static final reply_t[] VALUES = values();

    public static reply_t valueOf(
        com.google.protobuf.Descriptors.EnumValueDescriptor desc) {
      if (desc.getType() != getDescriptor()) {
        throw new java.lang.IllegalArgumentException(
          "EnumValueDescriptor is not for this type.");
      }
      return VALUES[desc.getIndex()];
    }

    private final int value;

    private reply_t(int value) {
      this.value = value;
    }

    // @@protoc_insertion_point(enum_scope:b_enum.reply_t)
  }

  /**
   * Protobuf enum {@code b_enum.operate_t}
   */
  public enum operate_t
      implements com.google.protobuf.ProtocolMessageEnum {
    /**
     * <pre>
     * 确定
     * </pre>
     *
     * <code>ensure = 0;</code>
     */
    ensure(0),
    /**
     * <pre>
     * 取消
     * </pre>
     *
     * <code>cancel = 1;</code>
     */
    cancel(1),
    ;

    /**
     * <pre>
     * 确定
     * </pre>
     *
     * <code>ensure = 0;</code>
     */
    public static final int ensure_VALUE = 0;
    /**
     * <pre>
     * 取消
     * </pre>
     *
     * <code>cancel = 1;</code>
     */
    public static final int cancel_VALUE = 1;


    public final int getNumber() {
      return value;
    }

    /**
     * @deprecated Use {@link #forNumber(int)} instead.
     */
    @java.lang.Deprecated
    public static operate_t valueOf(int value) {
      return forNumber(value);
    }

    public static operate_t forNumber(int value) {
      switch (value) {
        case 0: return ensure;
        case 1: return cancel;
        default: return null;
      }
    }

    public static com.google.protobuf.Internal.EnumLiteMap<operate_t>
        internalGetValueMap() {
      return internalValueMap;
    }
    private static final com.google.protobuf.Internal.EnumLiteMap<
        operate_t> internalValueMap =
          new com.google.protobuf.Internal.EnumLiteMap<operate_t>() {
            public operate_t findValueByNumber(int number) {
              return operate_t.forNumber(number);
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
      return protodef.b_enum.getDescriptor().getEnumTypes().get(1);
    }

    private static final operate_t[] VALUES = values();

    public static operate_t valueOf(
        com.google.protobuf.Descriptors.EnumValueDescriptor desc) {
      if (desc.getType() != getDescriptor()) {
        throw new java.lang.IllegalArgumentException(
          "EnumValueDescriptor is not for this type.");
      }
      return VALUES[desc.getIndex()];
    }

    private final int value;

    private operate_t(int value) {
      this.value = value;
    }

    // @@protoc_insertion_point(enum_scope:b_enum.operate_t)
  }

  /**
   * <pre>
   * 数据表操作码
   * </pre>
   *
   * Protobuf enum {@code b_enum.opcode_t}
   */
  public enum opcode_t
      implements com.google.protobuf.ProtocolMessageEnum {
    /**
     * <pre>
     * 替换本地所有
     * </pre>
     *
     * <code>assign = 0;</code>
     */
    assign(0),
    /**
     * <pre>
     * 更新本地指定
     * </pre>
     *
     * <code>update = 1;</code>
     */
    update(1),
    /**
     * <pre>
     * 直接插入新值
     * </pre>
     *
     * <code>insert = 2;</code>
     */
    insert(2),
    /**
     * <pre>
     * 清除本地指定
     * </pre>
     *
     * <code>remove = 3;</code>
     */
    remove(3),
    /**
     * <pre>
     * 清除本地所有
     * </pre>
     *
     * <code>delete = 4;</code>
     */
    delete(4),
    ;

    /**
     * <pre>
     * 替换本地所有
     * </pre>
     *
     * <code>assign = 0;</code>
     */
    public static final int assign_VALUE = 0;
    /**
     * <pre>
     * 更新本地指定
     * </pre>
     *
     * <code>update = 1;</code>
     */
    public static final int update_VALUE = 1;
    /**
     * <pre>
     * 直接插入新值
     * </pre>
     *
     * <code>insert = 2;</code>
     */
    public static final int insert_VALUE = 2;
    /**
     * <pre>
     * 清除本地指定
     * </pre>
     *
     * <code>remove = 3;</code>
     */
    public static final int remove_VALUE = 3;
    /**
     * <pre>
     * 清除本地所有
     * </pre>
     *
     * <code>delete = 4;</code>
     */
    public static final int delete_VALUE = 4;


    public final int getNumber() {
      return value;
    }

    /**
     * @deprecated Use {@link #forNumber(int)} instead.
     */
    @java.lang.Deprecated
    public static opcode_t valueOf(int value) {
      return forNumber(value);
    }

    public static opcode_t forNumber(int value) {
      switch (value) {
        case 0: return assign;
        case 1: return update;
        case 2: return insert;
        case 3: return remove;
        case 4: return delete;
        default: return null;
      }
    }

    public static com.google.protobuf.Internal.EnumLiteMap<opcode_t>
        internalGetValueMap() {
      return internalValueMap;
    }
    private static final com.google.protobuf.Internal.EnumLiteMap<
        opcode_t> internalValueMap =
          new com.google.protobuf.Internal.EnumLiteMap<opcode_t>() {
            public opcode_t findValueByNumber(int number) {
              return opcode_t.forNumber(number);
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
      return protodef.b_enum.getDescriptor().getEnumTypes().get(2);
    }

    private static final opcode_t[] VALUES = values();

    public static opcode_t valueOf(
        com.google.protobuf.Descriptors.EnumValueDescriptor desc) {
      if (desc.getType() != getDescriptor()) {
        throw new java.lang.IllegalArgumentException(
          "EnumValueDescriptor is not for this type.");
      }
      return VALUES[desc.getIndex()];
    }

    private final int value;

    private opcode_t(int value) {
      this.value = value;
    }

    // @@protoc_insertion_point(enum_scope:b_enum.opcode_t)
  }


  public static com.google.protobuf.Descriptors.FileDescriptor
      getDescriptor() {
    return descriptor;
  }
  private static  com.google.protobuf.Descriptors.FileDescriptor
      descriptor;
  static {
    java.lang.String[] descriptorData = {
      "\n\014b_enum.proto\022\006b_enum*!\n\007reply_t\022\n\n\006acc" +
      "ept\020\000\022\n\n\006refuse\020\001*#\n\toperate_t\022\n\n\006ensure" +
      "\020\000\022\n\n\006cancel\020\001*F\n\010opcode_t\022\n\n\006assign\020\000\022\n" +
      "\n\006update\020\001\022\n\n\006insert\020\002\022\n\n\006remove\020\003\022\n\n\006de" +
      "lete\020\004B6\n\010protodefB\006b_enumZ\017protodef/b_e" +
      "num\242\002\007B_enum_\252\002\006b_enum"
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
  }

  // @@protoc_insertion_point(outer_class_scope)
}
