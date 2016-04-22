package com.google.protobuf;

class BoundedByteString extends ByteString.BoundedByteString {
  BoundedByteString(byte[] bytes, int offset, int length) {
    super(bytes, offset, length);
  }
}
