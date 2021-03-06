// Generated by the protocol buffer compiler.  DO NOT EDIT!

package protodef.nano;

@SuppressWarnings("hiding")
public interface b_math {

  public static final class coord extends
      com.google.protobuf.nano.MessageNano {

    private static volatile coord[] _emptyArray;
    public static coord[] emptyArray() {
      // Lazily initializes the empty array
      if (_emptyArray == null) {
        synchronized (
            com.google.protobuf.nano.InternalNano.LAZY_INIT_LOCK) {
          if (_emptyArray == null) {
            _emptyArray = new coord[0];
          }
        }
      }
      return _emptyArray;
    }

    // required double j = 1 [default = 0];
    public double j;

    // required double w = 2 [default = 0];
    public double w;

    public coord() {
      clear();
    }

    public coord clear() {
      j = 0D;
      w = 0D;
      cachedSize = -1;
      return this;
    }

    @Override
    public void writeTo(com.google.protobuf.nano.CodedOutputByteBufferNano output)
        throws java.io.IOException {
      output.writeDouble(1, this.j);
      output.writeDouble(2, this.w);
      super.writeTo(output);
    }

    @Override
    protected int computeSerializedSize() {
      int size = super.computeSerializedSize();
      size += com.google.protobuf.nano.CodedOutputByteBufferNano
          .computeDoubleSize(1, this.j);
      size += com.google.protobuf.nano.CodedOutputByteBufferNano
          .computeDoubleSize(2, this.w);
      return size;
    }

    @Override
    public coord mergeFrom(
            com.google.protobuf.nano.CodedInputByteBufferNano input)
        throws java.io.IOException {
      while (true) {
        int tag = input.readTag();
        switch (tag) {
          case 0:
            return this;
          default: {
            if (!com.google.protobuf.nano.WireFormatNano.parseUnknownField(input, tag)) {
              return this;
            }
            break;
          }
          case 9: {
            this.j = input.readDouble();
            break;
          }
          case 17: {
            this.w = input.readDouble();
            break;
          }
        }
      }
    }

    public static coord parseFrom(byte[] data)
        throws com.google.protobuf.nano.InvalidProtocolBufferNanoException {
      return com.google.protobuf.nano.MessageNano.mergeFrom(new coord(), data);
    }

    public static coord parseFrom(
            com.google.protobuf.nano.CodedInputByteBufferNano input)
        throws java.io.IOException {
      return new coord().mergeFrom(input);
    }
  }

  public static final class vec2 extends
      com.google.protobuf.nano.MessageNano {

    private static volatile vec2[] _emptyArray;
    public static vec2[] emptyArray() {
      // Lazily initializes the empty array
      if (_emptyArray == null) {
        synchronized (
            com.google.protobuf.nano.InternalNano.LAZY_INIT_LOCK) {
          if (_emptyArray == null) {
            _emptyArray = new vec2[0];
          }
        }
      }
      return _emptyArray;
    }

    // required double x = 1 [default = 0];
    public double x;

    // required double y = 2 [default = 0];
    public double y;

    public vec2() {
      clear();
    }

    public vec2 clear() {
      x = 0D;
      y = 0D;
      cachedSize = -1;
      return this;
    }

    @Override
    public void writeTo(com.google.protobuf.nano.CodedOutputByteBufferNano output)
        throws java.io.IOException {
      output.writeDouble(1, this.x);
      output.writeDouble(2, this.y);
      super.writeTo(output);
    }

    @Override
    protected int computeSerializedSize() {
      int size = super.computeSerializedSize();
      size += com.google.protobuf.nano.CodedOutputByteBufferNano
          .computeDoubleSize(1, this.x);
      size += com.google.protobuf.nano.CodedOutputByteBufferNano
          .computeDoubleSize(2, this.y);
      return size;
    }

    @Override
    public vec2 mergeFrom(
            com.google.protobuf.nano.CodedInputByteBufferNano input)
        throws java.io.IOException {
      while (true) {
        int tag = input.readTag();
        switch (tag) {
          case 0:
            return this;
          default: {
            if (!com.google.protobuf.nano.WireFormatNano.parseUnknownField(input, tag)) {
              return this;
            }
            break;
          }
          case 9: {
            this.x = input.readDouble();
            break;
          }
          case 17: {
            this.y = input.readDouble();
            break;
          }
        }
      }
    }

    public static vec2 parseFrom(byte[] data)
        throws com.google.protobuf.nano.InvalidProtocolBufferNanoException {
      return com.google.protobuf.nano.MessageNano.mergeFrom(new vec2(), data);
    }

    public static vec2 parseFrom(
            com.google.protobuf.nano.CodedInputByteBufferNano input)
        throws java.io.IOException {
      return new vec2().mergeFrom(input);
    }
  }

  public static final class vec3 extends
      com.google.protobuf.nano.MessageNano {

    private static volatile vec3[] _emptyArray;
    public static vec3[] emptyArray() {
      // Lazily initializes the empty array
      if (_emptyArray == null) {
        synchronized (
            com.google.protobuf.nano.InternalNano.LAZY_INIT_LOCK) {
          if (_emptyArray == null) {
            _emptyArray = new vec3[0];
          }
        }
      }
      return _emptyArray;
    }

    // required double x = 1 [default = 0];
    public double x;

    // required double y = 2 [default = 0];
    public double y;

    // required double z = 3 [default = 0];
    public double z;

    public vec3() {
      clear();
    }

    public vec3 clear() {
      x = 0D;
      y = 0D;
      z = 0D;
      cachedSize = -1;
      return this;
    }

    @Override
    public void writeTo(com.google.protobuf.nano.CodedOutputByteBufferNano output)
        throws java.io.IOException {
      output.writeDouble(1, this.x);
      output.writeDouble(2, this.y);
      output.writeDouble(3, this.z);
      super.writeTo(output);
    }

    @Override
    protected int computeSerializedSize() {
      int size = super.computeSerializedSize();
      size += com.google.protobuf.nano.CodedOutputByteBufferNano
          .computeDoubleSize(1, this.x);
      size += com.google.protobuf.nano.CodedOutputByteBufferNano
          .computeDoubleSize(2, this.y);
      size += com.google.protobuf.nano.CodedOutputByteBufferNano
          .computeDoubleSize(3, this.z);
      return size;
    }

    @Override
    public vec3 mergeFrom(
            com.google.protobuf.nano.CodedInputByteBufferNano input)
        throws java.io.IOException {
      while (true) {
        int tag = input.readTag();
        switch (tag) {
          case 0:
            return this;
          default: {
            if (!com.google.protobuf.nano.WireFormatNano.parseUnknownField(input, tag)) {
              return this;
            }
            break;
          }
          case 9: {
            this.x = input.readDouble();
            break;
          }
          case 17: {
            this.y = input.readDouble();
            break;
          }
          case 25: {
            this.z = input.readDouble();
            break;
          }
        }
      }
    }

    public static vec3 parseFrom(byte[] data)
        throws com.google.protobuf.nano.InvalidProtocolBufferNanoException {
      return com.google.protobuf.nano.MessageNano.mergeFrom(new vec3(), data);
    }

    public static vec3 parseFrom(
            com.google.protobuf.nano.CodedInputByteBufferNano input)
        throws java.io.IOException {
      return new vec3().mergeFrom(input);
    }
  }

  public static final class vec4 extends
      com.google.protobuf.nano.MessageNano {

    private static volatile vec4[] _emptyArray;
    public static vec4[] emptyArray() {
      // Lazily initializes the empty array
      if (_emptyArray == null) {
        synchronized (
            com.google.protobuf.nano.InternalNano.LAZY_INIT_LOCK) {
          if (_emptyArray == null) {
            _emptyArray = new vec4[0];
          }
        }
      }
      return _emptyArray;
    }

    // required double x = 1 [default = 0];
    public double x;

    // required double y = 2 [default = 0];
    public double y;

    // required double z = 3 [default = 0];
    public double z;

    // required double w = 4 [default = 0];
    public double w;

    public vec4() {
      clear();
    }

    public vec4 clear() {
      x = 0D;
      y = 0D;
      z = 0D;
      w = 0D;
      cachedSize = -1;
      return this;
    }

    @Override
    public void writeTo(com.google.protobuf.nano.CodedOutputByteBufferNano output)
        throws java.io.IOException {
      output.writeDouble(1, this.x);
      output.writeDouble(2, this.y);
      output.writeDouble(3, this.z);
      output.writeDouble(4, this.w);
      super.writeTo(output);
    }

    @Override
    protected int computeSerializedSize() {
      int size = super.computeSerializedSize();
      size += com.google.protobuf.nano.CodedOutputByteBufferNano
          .computeDoubleSize(1, this.x);
      size += com.google.protobuf.nano.CodedOutputByteBufferNano
          .computeDoubleSize(2, this.y);
      size += com.google.protobuf.nano.CodedOutputByteBufferNano
          .computeDoubleSize(3, this.z);
      size += com.google.protobuf.nano.CodedOutputByteBufferNano
          .computeDoubleSize(4, this.w);
      return size;
    }

    @Override
    public vec4 mergeFrom(
            com.google.protobuf.nano.CodedInputByteBufferNano input)
        throws java.io.IOException {
      while (true) {
        int tag = input.readTag();
        switch (tag) {
          case 0:
            return this;
          default: {
            if (!com.google.protobuf.nano.WireFormatNano.parseUnknownField(input, tag)) {
              return this;
            }
            break;
          }
          case 9: {
            this.x = input.readDouble();
            break;
          }
          case 17: {
            this.y = input.readDouble();
            break;
          }
          case 25: {
            this.z = input.readDouble();
            break;
          }
          case 33: {
            this.w = input.readDouble();
            break;
          }
        }
      }
    }

    public static vec4 parseFrom(byte[] data)
        throws com.google.protobuf.nano.InvalidProtocolBufferNanoException {
      return com.google.protobuf.nano.MessageNano.mergeFrom(new vec4(), data);
    }

    public static vec4 parseFrom(
            com.google.protobuf.nano.CodedInputByteBufferNano input)
        throws java.io.IOException {
      return new vec4().mergeFrom(input);
    }
  }

  public static final class mat3 extends
      com.google.protobuf.nano.MessageNano {

    private static volatile mat3[] _emptyArray;
    public static mat3[] emptyArray() {
      // Lazily initializes the empty array
      if (_emptyArray == null) {
        synchronized (
            com.google.protobuf.nano.InternalNano.LAZY_INIT_LOCK) {
          if (_emptyArray == null) {
            _emptyArray = new mat3[0];
          }
        }
      }
      return _emptyArray;
    }

    // repeated double m = 1;
    public double[] m;

    public mat3() {
      clear();
    }

    public mat3 clear() {
      m = com.google.protobuf.nano.WireFormatNano.EMPTY_DOUBLE_ARRAY;
      cachedSize = -1;
      return this;
    }

    @Override
    public void writeTo(com.google.protobuf.nano.CodedOutputByteBufferNano output)
        throws java.io.IOException {
      if (this.m != null && this.m.length > 0) {
        for (int i = 0; i < this.m.length; i++) {
          output.writeDouble(1, this.m[i]);
        }
      }
      super.writeTo(output);
    }

    @Override
    protected int computeSerializedSize() {
      int size = super.computeSerializedSize();
      if (this.m != null && this.m.length > 0) {
        int dataSize = 8 * this.m.length;
        size += dataSize;
        size += 1 * this.m.length;
      }
      return size;
    }

    @Override
    public mat3 mergeFrom(
            com.google.protobuf.nano.CodedInputByteBufferNano input)
        throws java.io.IOException {
      while (true) {
        int tag = input.readTag();
        switch (tag) {
          case 0:
            return this;
          default: {
            if (!com.google.protobuf.nano.WireFormatNano.parseUnknownField(input, tag)) {
              return this;
            }
            break;
          }
          case 9: {
            int arrayLength = com.google.protobuf.nano.WireFormatNano
                .getRepeatedFieldArrayLength(input, 9);
            int i = this.m == null ? 0 : this.m.length;
            double[] newArray = new double[i + arrayLength];
            if (i != 0) {
              java.lang.System.arraycopy(this.m, 0, newArray, 0, i);
            }
            for (; i < newArray.length - 1; i++) {
              newArray[i] = input.readDouble();
              input.readTag();
            }
            // Last one without readTag.
            newArray[i] = input.readDouble();
            this.m = newArray;
            break;
          }
          case 10: {
            int length = input.readRawVarint32();
            int limit = input.pushLimit(length);
            int arrayLength = length / 8;
            int i = this.m == null ? 0 : this.m.length;
            double[] newArray = new double[i + arrayLength];
            if (i != 0) {
              java.lang.System.arraycopy(this.m, 0, newArray, 0, i);
            }
            for (; i < newArray.length; i++) {
              newArray[i] = input.readDouble();
            }
            this.m = newArray;
            input.popLimit(limit);
            break;
          }
        }
      }
    }

    public static mat3 parseFrom(byte[] data)
        throws com.google.protobuf.nano.InvalidProtocolBufferNanoException {
      return com.google.protobuf.nano.MessageNano.mergeFrom(new mat3(), data);
    }

    public static mat3 parseFrom(
            com.google.protobuf.nano.CodedInputByteBufferNano input)
        throws java.io.IOException {
      return new mat3().mergeFrom(input);
    }
  }

  public static final class mat4 extends
      com.google.protobuf.nano.MessageNano {

    private static volatile mat4[] _emptyArray;
    public static mat4[] emptyArray() {
      // Lazily initializes the empty array
      if (_emptyArray == null) {
        synchronized (
            com.google.protobuf.nano.InternalNano.LAZY_INIT_LOCK) {
          if (_emptyArray == null) {
            _emptyArray = new mat4[0];
          }
        }
      }
      return _emptyArray;
    }

    // repeated double m = 1;
    public double[] m;

    public mat4() {
      clear();
    }

    public mat4 clear() {
      m = com.google.protobuf.nano.WireFormatNano.EMPTY_DOUBLE_ARRAY;
      cachedSize = -1;
      return this;
    }

    @Override
    public void writeTo(com.google.protobuf.nano.CodedOutputByteBufferNano output)
        throws java.io.IOException {
      if (this.m != null && this.m.length > 0) {
        for (int i = 0; i < this.m.length; i++) {
          output.writeDouble(1, this.m[i]);
        }
      }
      super.writeTo(output);
    }

    @Override
    protected int computeSerializedSize() {
      int size = super.computeSerializedSize();
      if (this.m != null && this.m.length > 0) {
        int dataSize = 8 * this.m.length;
        size += dataSize;
        size += 1 * this.m.length;
      }
      return size;
    }

    @Override
    public mat4 mergeFrom(
            com.google.protobuf.nano.CodedInputByteBufferNano input)
        throws java.io.IOException {
      while (true) {
        int tag = input.readTag();
        switch (tag) {
          case 0:
            return this;
          default: {
            if (!com.google.protobuf.nano.WireFormatNano.parseUnknownField(input, tag)) {
              return this;
            }
            break;
          }
          case 9: {
            int arrayLength = com.google.protobuf.nano.WireFormatNano
                .getRepeatedFieldArrayLength(input, 9);
            int i = this.m == null ? 0 : this.m.length;
            double[] newArray = new double[i + arrayLength];
            if (i != 0) {
              java.lang.System.arraycopy(this.m, 0, newArray, 0, i);
            }
            for (; i < newArray.length - 1; i++) {
              newArray[i] = input.readDouble();
              input.readTag();
            }
            // Last one without readTag.
            newArray[i] = input.readDouble();
            this.m = newArray;
            break;
          }
          case 10: {
            int length = input.readRawVarint32();
            int limit = input.pushLimit(length);
            int arrayLength = length / 8;
            int i = this.m == null ? 0 : this.m.length;
            double[] newArray = new double[i + arrayLength];
            if (i != 0) {
              java.lang.System.arraycopy(this.m, 0, newArray, 0, i);
            }
            for (; i < newArray.length; i++) {
              newArray[i] = input.readDouble();
            }
            this.m = newArray;
            input.popLimit(limit);
            break;
          }
        }
      }
    }

    public static mat4 parseFrom(byte[] data)
        throws com.google.protobuf.nano.InvalidProtocolBufferNanoException {
      return com.google.protobuf.nano.MessageNano.mergeFrom(new mat4(), data);
    }

    public static mat4 parseFrom(
            com.google.protobuf.nano.CodedInputByteBufferNano input)
        throws java.io.IOException {
      return new mat4().mergeFrom(input);
    }
  }
}
