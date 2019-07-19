[Wikipedia](https://en.wikipedia.org/wiki/Base64) is pretty useful on this one.

# Encoding
Encoding runs on blocks of 3 bytes at a time. These 3 bytes are lined up in a 24-bit string. Groups of 6 bits are converted into individual numbers from left to right, which are then converted into their corresponding Base64 character values.

# Decoding
4 characters are typically converted back to 3 bytes. The exceptions are when padding characters exist.

| Encoded | Padding | Bytes |
| ------- | ------- | ----- |
| `TWFu`  | none    | 3
| `TWE=`  | `=`     | 2
| `TQ==`  | `==`    | 1

# Length
The ratio of output bytes to input bytes is 4:3 (33% overhead). Specifically, given an input of n bytes, the output will be `(n / 3) * 4` bytes long.
