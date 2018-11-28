// Generated by the protocol buffer compiler.  DO NOT EDIT!

package protodef.nano;

@SuppressWarnings("hiding")
public interface s_proxy_curl {

  // enum msg
  public static final int min_id = 16777472;
  public static final int max_id = 16777727;

  public static final class json_data_rq extends
      com.google.protobuf.nano.MessageNano {

    // enum msg
    public static final int id = 16777472;

    private static volatile json_data_rq[] _emptyArray;
    public static json_data_rq[] emptyArray() {
      // Lazily initializes the empty array
      if (_emptyArray == null) {
        synchronized (
            com.google.protobuf.nano.InternalNano.LAZY_INIT_LOCK) {
          if (_emptyArray == null) {
            _emptyArray = new json_data_rq[0];
          }
        }
      }
      return _emptyArray;
    }

    // required bytes buffer = 1;
    public byte[] buffer;

    public json_data_rq() {
      clear();
    }

    public json_data_rq clear() {
      buffer = com.google.protobuf.nano.WireFormatNano.EMPTY_BYTES;
      cachedSize = -1;
      return this;
    }

    @Override
    public void writeTo(com.google.protobuf.nano.CodedOutputByteBufferNano output)
        throws java.io.IOException {
      output.writeBytes(1, this.buffer);
      super.writeTo(output);
    }

    @Override
    protected int computeSerializedSize() {
      int size = super.computeSerializedSize();
      size += com.google.protobuf.nano.CodedOutputByteBufferNano
          .computeBytesSize(1, this.buffer);
      return size;
    }

    @Override
    public json_data_rq mergeFrom(
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
            this.buffer = input.readBytes();
            break;
          }
        }
      }
    }

    public static json_data_rq parseFrom(byte[] data)
        throws com.google.protobuf.nano.InvalidProtocolBufferNanoException {
      return com.google.protobuf.nano.MessageNano.mergeFrom(new json_data_rq(), data);
    }

    public static json_data_rq parseFrom(
            com.google.protobuf.nano.CodedInputByteBufferNano input)
        throws java.io.IOException {
      return new json_data_rq().mergeFrom(input);
    }
  }

  public static final class json_data_rs extends
      com.google.protobuf.nano.MessageNano {

    // enum msg
    public static final int id = 16777473;

    private static volatile json_data_rs[] _emptyArray;
    public static json_data_rs[] emptyArray() {
      // Lazily initializes the empty array
      if (_emptyArray == null) {
        synchronized (
            com.google.protobuf.nano.InternalNano.LAZY_INIT_LOCK) {
          if (_emptyArray == null) {
            _emptyArray = new json_data_rs[0];
          }
        }
      }
      return _emptyArray;
    }

    // required .b_error.info error = 1;
    public protodef.nano.b_error.info error;

    // required uint32 curl_code = 2 [default = 0];
    public int curlCode;

    // required bytes buffer = 3;
    public byte[] buffer;

    public json_data_rs() {
      clear();
    }

    public json_data_rs clear() {
      error = null;
      curlCode = 0;
      buffer = com.google.protobuf.nano.WireFormatNano.EMPTY_BYTES;
      cachedSize = -1;
      return this;
    }

    @Override
    public void writeTo(com.google.protobuf.nano.CodedOutputByteBufferNano output)
        throws java.io.IOException {
      if (this.error != null) {
        output.writeMessage(1, this.error);
      }
      output.writeUInt32(2, this.curlCode);
      output.writeBytes(3, this.buffer);
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
          .computeUInt32Size(2, this.curlCode);
      size += com.google.protobuf.nano.CodedOutputByteBufferNano
          .computeBytesSize(3, this.buffer);
      return size;
    }

    @Override
    public json_data_rs mergeFrom(
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
          case 16: {
            this.curlCode = input.readUInt32();
            break;
          }
          case 26: {
            this.buffer = input.readBytes();
            break;
          }
        }
      }
    }

    public static json_data_rs parseFrom(byte[] data)
        throws com.google.protobuf.nano.InvalidProtocolBufferNanoException {
      return com.google.protobuf.nano.MessageNano.mergeFrom(new json_data_rs(), data);
    }

    public static json_data_rs parseFrom(
            com.google.protobuf.nano.CodedInputByteBufferNano input)
        throws java.io.IOException {
      return new json_data_rs().mergeFrom(input);
    }
  }
}
