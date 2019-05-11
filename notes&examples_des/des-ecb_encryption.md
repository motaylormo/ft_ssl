```
message = "The house stood on a slight rise just on the edge of the village."
key = 3e9b8a463a57720d
```

## Blocks
| Ascii | Binary | Hex |
| ----- | ------ | --- |
| `"The hous"` | `01010100 01101000 01100101 00100000`<br>`01101000 01101111 01110101 01110011` | `54686520686f7573`
| `"e stood "` | `01100101 00100000 01110011 01110100`<br>`01101111 01101111 01100100 00100000` | `652073746f6f6420`
| `"on a sli"` | `01101111 01101110 00100000 01100001`<br>`00100000 01110011 01101100 01101001` | `6f6e206120736c69`
| `"ght rise"` | `01100111 01101000 01110100 00100000`<br>`01110010 01101001 01110011 01100101` | `6768742072697365`
| `" just on"` | `00100000 01101010 01110101 01110011`<br>`01110100 00100000 01101111 01101110` | `206a757374206f6e`
| `" the edg"` | `00100000 01110100 01101000 01100101`<br>`00100000 01100101 01100100 01100111` | `2074686520656467`
| `"e of the"` | `01100101 00100000 01101111 01100110`<br>`00100000 01110100 01101000 01100101` | `65206f6620746865`
| `" village"` | `00100000 01110110 01101001 01101100`<br>`01101100 01100001 01100111 01100101` | `2076696c6c616765`
| `"."` | `00101110 00000111 00000111 00000111`<br>`00000111 00000111 00000111 00000111` | `2e07070707070707`

In the last block, because there is only 1 byte of message left, you pad the rest of the bytes in the block with the number of bytes which are empty (in this case, 7).

## Encryption (Block 0)
### Beginning
We start with our block:<br>
```
block = 54686520686f7573
```

Run that through the initial permutation:<br>
```
ip = f7c165e400fe32a0
```

Split that into 2 halves:<br>
```
 left = f7c165e4
right = 00fe32a0
```

### Rounds
"Left" and "right" are left and right's _input_ values, not output values. Right's output value is left XOR feistel, and left's output value is the old right.

|    | left       | right      | subkey         | feistel    | left XOR feistel
| -- | ---------- | ---------- | -------------- | ---------- | ----------------
| 0  | `f7c165e4` | `00fe32a0` | `445e882fac8f` | `b7dd0321` | `401c66c5`
| 1  | `00fe32a0` | `401c66c5` | `3401e03237fb` | `cefa6df0` | `ce045f50`
| 2  | `401c66c5` | `ce045f50` | `924835ffb923` | `075fc309` | `4743a5cc`
| 3  | `ce045f50` | `4743a5cc` | `8d2314666f7a` | `98e37c9a` | `56e723ca`
| 4  | `4743a5cc` | `56e723ca` | `0616ad7db95e` | `c8577f6c` | `8f14daa0`
| 5  | `56e723ca` | `8f14daa0` | `db1060e5d4fa` | `42701fa4` | `14973c6e`
| 6  | `8f14daa0` | `14973c6e` | `88cae84dbe6f` | `cd7ca524` | `42687f84`
| 7  | `14973c6e` | `42687f84` | `90730ebedcfc` | `9c4f7358` | `88d84f36`
| 8  | `42687f84` | `88d84f36` | `360e86db7c2e` | `7e5a7ce0` | `3c320364`
| 9  | `88d84f36` | `3c320364` | `7a3010ec7bb8` | `92ed4507` | `1a350a31`
| 10 | `3c320364` | `1a350a31` | `0c847cb17a7f` | `fb35bd0c` | `c707be68`
| 11 | `1a350a31` | `c707be68` | `c6401ef79ab2` | `05019999` | `1f3493a8`
| 12 | `c707be68` | `1f3493a8` | `2e8b20952f7f` | `2f587e35` | `e85fc05d`
| 13 | `1f3493a8` | `e85fc05d` | `8a382b3fbad4` | `6f800970` | `70b49ad8`
| 14 | `e85fc05d` | `70b49ad8` | `a9265871e5f7` | `e880a35d` | `00df6300`
| 15 | `70b49ad8` | `00df6300` | `31509ef6fb8d` | `72d72b63` | `0263b1bb`

Inside `feistel(right, subkey)` for each round. "Half block" and "subkey" are the input. "P-box" is the output.

|    | half block | subkey         | expanded block | e XOR subkey   | s-boxes    | p-box
| -- | ---------- | -------------- | -------------- | -------------- | ---------- | ----------
| 0  | `00fe32a0` | `445e882fac8f` | `0017fc1a5500` | `44497435f98f` | `a8d3d8d4` | `b7dd0321`
| 1  | `401c66c5` | `3401e03237fb` | `a000f830d60a` | `94011802e1f1` | `8f9b237f` | `cefa6df0`
| 2  | `ce045f50` | `924835ffb923` | `65c0082feaa1` | `f7883dd05382` | `69d2c4d2` | `075fc309`
| 3  | `4743a5cc` | `8d2314666f7a` | `20ea07d0be58` | `adc913b6d122` | `95472f2b` | `98e37c9a`
| 4  | `56e723ca` | `0616ad7db95e` | `2ad70e907e54` | `2cc1a3edc70a` | `23ef456f` | `c8577f6c`
| 5  | `8f14daa0` | `db1060e5d4fa` | `45e8a96f5501` | `9ef8c98a81fb` | `22a62275` | `42701fa4`
| 6  | `14973c6e` | `88cae84dbe6f` | `0a94ae9f835c` | `825e46d23d33` | `4ab3c36c` | `cd7ca524`
| 7  | `42687f84` | `90730ebedcfc` | `2043503ffc08` | `b0305e8120f4` | `2ddf4d0a` | `9c4f7358`
| 8  | `88d84f36` | `360e86db7c2e` | `4516f025e9ad` | `731876fe9583` | `0b1e397f` | `7e5a7ce0`
| 9  | `3c320364` | `7a3010ec7bb8` | `1f81a4006b08` | `65b1b4ec10b0` | `99e34ab0` | `92ed4507`
| 10 | `1a350a31` | `0c847cb17a7f` | `8f41aa8541a2` | `83c5d6343bdd` | `42e5df79` | `fb35bd0c`
| 11 | `c707be68` | `c6401ef79ab2` | `60e80fdfc351` | `a6a8112859e3` | `44d4a481` | `05019999`
| 12 | `1f3493a8` | `2e8b20952f7f` | `0fe9a94a7d50` | `216289df522f` | `2d3691fd` | `2f587e35`
| 13 | `e85fc05d` | `8a382b3fbad4` | `f502ffe002fb` | `7f3ad4dfb82f` | `8698901d` | `6f800970`
| 14 | `70b49ad8` | `a9265871e5f7` | `3a15a94f56f0` | `9333f13eb307` | `e6a91588` | `e880a35d`
| 15 | `00df6300` | `31509ef6fb8d` | `0016feb06800` | `31466046938d` | `b2ca59d7` | `72d72b63`

### End
The halves from the final round:<br>
```
 left = 00df6300
right = 0263b1bb
```
Concatenate those together backwards (right + left):<br>
```
catted = 0263b1bb00df6300
```

Run that through the final permutation:<br>
```
fp = 3d792021251d3825
```

## Blocks
| Plaintext<br>(ascii) | Plaintext<br>(hex) | Encrypted<br>(ascii) | Encrypted<br>(hex) |
| -------------------- | ------------------ | -------------------- | ------------------ |
| `The hous` | `54686520686f7573`| `3d792021251d3825`| <pre>=y !%8%</pre>
| `e stood ` | `652073746f6f6420`| `49c05eba625f10f4`| <pre>I�^�b_�</pre>
| `on a sli` | `6f6e206120736c69`| `b1f4f82337449bd5`| <pre>���#7D��</pre>
| `ght rise` | `6768742072697365`| `0a13581429c483bc`| <pre>
X)ă�</pre>
| ` just on` | `206a757374206f6e`| `1cfe4ef7f2f41f75`| <pre>�N���u</pre>
| ` the edg` | `2074686520656467`| `ebdde1cb9e3ff54e`| <pre>���˞?�N</pre>
| `e of the` | `65206f6620746865`| `ff793c54facc24f7`| <pre>�y<T��$�</pre>
| ` village` | `2076696c6c616765`| `c53d6621021babb8`| <pre>�=f!�</pre>
| `.` | `2e07070707070707`| `604b6f2dc7c08a06`| <pre>`Ko-���</pre>