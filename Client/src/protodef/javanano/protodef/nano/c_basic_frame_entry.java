// Generated by the protocol buffer compiler.  DO NOT EDIT!

package protodef.nano;

@SuppressWarnings("hiding")
public interface c_basic_frame_entry {

  // enum msg
  public static final int min_id = 33558528;
  public static final int max_id = 33558783;

  public static final class knock_rq extends
      com.google.protobuf.nano.MessageNano {

    // enum msg
    public static final int id = 33558528;

    private static volatile knock_rq[] _emptyArray;
    public static knock_rq[] emptyArray() {
      // Lazily initializes the empty array
      if (_emptyArray == null) {
        synchronized (
            com.google.protobuf.nano.InternalNano.LAZY_INIT_LOCK) {
          if (_emptyArray == null) {
            _emptyArray = new knock_rq[0];
          }
        }
      }
      return _emptyArray;
    }

    // required string native_client_version = 1 [default = ""];
    public java.lang.String nativeClientVersion;

    // required string native_source_version = 2 [default = ""];
    public java.lang.String nativeSourceVersion;

    // required .b_math.coord coord_info = 3;
    public protodef.nano.b_math.coord coordInfo;

    public knock_rq() {
      clear();
    }

    public knock_rq clear() {
      nativeClientVersion = "";
      nativeSourceVersion = "";
      coordInfo = null;
      cachedSize = -1;
      return this;
    }

    @Override
    public void writeTo(com.google.protobuf.nano.CodedOutputByteBufferNano output)
        throws java.io.IOException {
      output.writeString(1, this.nativeClientVersion);
      output.writeString(2, this.nativeSourceVersion);
      if (this.coordInfo != null) {
        output.writeMessage(3, this.coordInfo);
      }
      super.writeTo(output);
    }

    @Override
    protected int computeSerializedSize() {
      int size = super.computeSerializedSize();
      size += com.google.protobuf.nano.CodedOutputByteBufferNano
          .computeStringSize(1, this.nativeClientVersion);
      size += com.google.protobuf.nano.CodedOutputByteBufferNano
          .computeStringSize(2, this.nativeSourceVersion);
      if (this.coordInfo != null) {
        size += com.google.protobuf.nano.CodedOutputByteBufferNano
          .computeMessageSize(3, this.coordInfo);
      }
      return size;
    }

    @Override
    public knock_rq mergeFrom(
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
          case 10: {
            this.nativeClientVersion = input.readString();
            break;
          }
          case 18: {
            this.nativeSourceVersion = input.readString();
            break;
          }
          case 26: {
            if (this.coordInfo == null) {
              this.coordInfo = new protodef.nano.b_math.coord();
            }
            input.readMessage(this.coordInfo);
            break;
          }
        }
      }
    }

    public static knock_rq parseFrom(byte[] data)
        throws com.google.protobuf.nano.InvalidProtocolBufferNanoException {
      return com.google.protobuf.nano.MessageNano.mergeFrom(new knock_rq(), data);
    }

    public static knock_rq parseFrom(
            com.google.protobuf.nano.CodedInputByteBufferNano input)
        throws java.io.IOException {
      return new knock_rq().mergeFrom(input);
    }
  }

  public static final class knock_rs extends
      com.google.protobuf.nano.MessageNano {

    // enum msg
    public static final int id = 33558529;

    private static volatile knock_rs[] _emptyArray;
    public static knock_rs[] emptyArray() {
      // Lazily initializes the empty array
      if (_emptyArray == null) {
        synchronized (
            com.google.protobuf.nano.InternalNano.LAZY_INIT_LOCK) {
          if (_emptyArray == null) {
            _emptyArray = new knock_rs[0];
          }
        }
      }
      return _emptyArray;
    }

    // required .b_error.info error = 1;
    public protodef.nano.b_error.info error;

    // required .b_network.address addr = 2;
    public protodef.nano.b_network.address addr;

    // required string remote_client_version = 3 [default = ""];
    public java.lang.String remoteClientVersion;

    // required string remote_source_version = 4 [default = ""];
    public java.lang.String remoteSourceVersion;

    // required string remote_server_version = 5 [default = ""];
    public java.lang.String remoteServerVersion;

    public knock_rs() {
      clear();
    }

    public knock_rs clear() {
      error = null;
      addr = null;
      remoteClientVersion = "";
      remoteSourceVersion = "";
      remoteServerVersion = "";
      cachedSize = -1;
      return this;
    }

    @Override
    public void writeTo(com.google.protobuf.nano.CodedOutputByteBufferNano output)
        throws java.io.IOException {
      if (this.error != null) {
        output.writeMessage(1, this.error);
      }
      if (this.addr != null) {
        output.writeMessage(2, this.addr);
      }
      output.writeString(3, this.remoteClientVersion);
      output.writeString(4, this.remoteSourceVersion);
      output.writeString(5, this.remoteServerVersion);
      super.writeTo(output);
    }

    @Override
    protected int computeSerializedSize() {
      int size = super.computeSerializedSize();
      if (this.error != null) {
        size += com.google.protobuf.nano.CodedOutputByteBufferNano
          .computeMessageSize(1, this.error);
      }
      if (this.addr != null) {
        size += com.google.protobuf.nano.CodedOutputByteBufferNano
          .computeMessageSize(2, this.addr);
      }
      size += com.google.protobuf.nano.CodedOutputByteBufferNano
          .computeStringSize(3, this.remoteClientVersion);
      size += com.google.protobuf.nano.CodedOutputByteBufferNano
          .computeStringSize(4, this.remoteSourceVersion);
      size += com.google.protobuf.nano.CodedOutputByteBufferNano
          .computeStringSize(5, this.remoteServerVersion);
      return size;
    }

    @Override
    public knock_rs mergeFrom(
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
          case 10: {
            if (this.error == null) {
              this.error = new protodef.nano.b_error.info();
            }
            input.readMessage(this.error);
            break;
          }
          case 18: {
            if (this.addr == null) {
              this.addr = new protodef.nano.b_network.address();
            }
            input.readMessage(this.addr);
            break;
          }
          case 26: {
            this.remoteClientVersion = input.readString();
            break;
          }
          case 34: {
            this.remoteSourceVersion = input.readString();
            break;
          }
          case 42: {
            this.remoteServerVersion = input.readString();
            break;
          }
        }
      }
    }

    public static knock_rs parseFrom(byte[] data)
        throws com.google.protobuf.nano.InvalidProtocolBufferNanoException {
      return com.google.protobuf.nano.MessageNano.mergeFrom(new knock_rs(), data);
    }

    public static knock_rs parseFrom(
            com.google.protobuf.nano.CodedInputByteBufferNano input)
        throws java.io.IOException {
      return new knock_rs().mergeFrom(input);
    }
  }

  public static final class exchange_key_rq extends
      com.google.protobuf.nano.MessageNano {

    // enum msg
    public static final int id = 33558544;

    private static volatile exchange_key_rq[] _emptyArray;
    public static exchange_key_rq[] emptyArray() {
      // Lazily initializes the empty array
      if (_emptyArray == null) {
        synchronized (
            com.google.protobuf.nano.InternalNano.LAZY_INIT_LOCK) {
          if (_emptyArray == null) {
            _emptyArray = new exchange_key_rq[0];
          }
        }
      }
      return _emptyArray;
    }

    // required bytes n = 1;
    public byte[] n;

    // required bytes e = 2;
    public byte[] e;

    // required uint32 version = 3 [default = 0];
    public int version;

    public exchange_key_rq() {
      clear();
    }

    public exchange_key_rq clear() {
      n = com.google.protobuf.nano.WireFormatNano.EMPTY_BYTES;
      e = com.google.protobuf.nano.WireFormatNano.EMPTY_BYTES;
      version = 0;
      cachedSize = -1;
      return this;
    }

    @Override
    public void writeTo(com.google.protobuf.nano.CodedOutputByteBufferNano output)
        throws java.io.IOException {
      output.writeBytes(1, this.n);
      output.writeBytes(2, this.e);
      output.writeUInt32(3, this.version);
      super.writeTo(output);
    }

    @Override
    protected int computeSerializedSize() {
      int size = super.computeSerializedSize();
      size += com.google.protobuf.nano.CodedOutputByteBufferNano
          .computeBytesSize(1, this.n);
      size += com.google.protobuf.nano.CodedOutputByteBufferNano
          .computeBytesSize(2, this.e);
      size += com.google.protobuf.nano.CodedOutputByteBufferNano
          .computeUInt32Size(3, this.version);
      return size;
    }

    @Override
    public exchange_key_rq mergeFrom(
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
          case 10: {
            this.n = input.readBytes();
            break;
          }
          case 18: {
            this.e = input.readBytes();
            break;
          }
          case 24: {
            this.version = input.readUInt32();
            break;
          }
        }
      }
    }

    public static exchange_key_rq parseFrom(byte[] data)
        throws com.google.protobuf.nano.InvalidProtocolBufferNanoException {
      return com.google.protobuf.nano.MessageNano.mergeFrom(new exchange_key_rq(), data);
    }

    public static exchange_key_rq parseFrom(
            com.google.protobuf.nano.CodedInputByteBufferNano input)
        throws java.io.IOException {
      return new exchange_key_rq().mergeFrom(input);
    }
  }

  public static final class exchange_key_rs extends
      com.google.protobuf.nano.MessageNano {

    // enum msg
    public static final int id = 33558545;

    private static volatile exchange_key_rs[] _emptyArray;
    public static exchange_key_rs[] emptyArray() {
      // Lazily initializes the empty array
      if (_emptyArray == null) {
        synchronized (
            com.google.protobuf.nano.InternalNano.LAZY_INIT_LOCK) {
          if (_emptyArray == null) {
            _emptyArray = new exchange_key_rs[0];
          }
        }
      }
      return _emptyArray;
    }

    // required .b_error.info error = 1;
    public protodef.nano.b_error.info error;

    // required bytes key = 2;
    public byte[] key;

    public exchange_key_rs() {
      clear();
    }

    public exchange_key_rs clear() {
      error = null;
      key = com.google.protobuf.nano.WireFormatNano.EMPTY_BYTES;
      cachedSize = -1;
      return this;
    }

    @Override
    public void writeTo(com.google.protobuf.nano.CodedOutputByteBufferNano output)
        throws java.io.IOException {
      if (this.error != null) {
        output.writeMessage(1, this.error);
      }
      output.writeBytes(2, this.key);
      super.writeTo(output);
    }

    @Override
    protected int computeSerializedSize() {
      int size = super.computeSerializedSize();
      if (this.error != null) {
        size += com.google.protobuf.nano.CodedOutputByteBufferNano
          .computeMessageSize(1, this.error);
      }
      size += com.google.protobuf.nano.CodedOutputByteBufferNano
          .computeBytesSize(2, this.key);
      return size;
    }

    @Override
    public exchange_key_rs mergeFrom(
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
          case 10: {
            if (this.error == null) {
              this.error = new protodef.nano.b_error.info();
            }
            input.readMessage(this.error);
            break;
          }
          case 18: {
            this.key = input.readBytes();
            break;
          }
        }
      }
    }

    public static exchange_key_rs parseFrom(byte[] data)
        throws com.google.protobuf.nano.InvalidProtocolBufferNanoException {
      return com.google.protobuf.nano.MessageNano.mergeFrom(new exchange_key_rs(), data);
    }

    public static exchange_key_rs parseFrom(
            com.google.protobuf.nano.CodedInputByteBufferNano input)
        throws java.io.IOException {
      return new exchange_key_rs().mergeFrom(input);
    }
  }
}
