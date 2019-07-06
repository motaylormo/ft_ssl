* **message:** `"The house stood on a slight rise just on the edge of the village."`
* **key:** `daf91e7c5a178dfe`

# Message blocks

| ascii | plaintext<br>hexadecimal | encrypted<br>hexadecimal |
| ------------ | ------------------ | ------------------ |
| `"The hous"` | `54686520686f7573` | `294d8041a87bcf18`
| `"e stood "` | `652073746f6f6420` | `c05f3eb9682b562c`
| `"on a sli"` | `6f6e206120736c69` | `8566557825b492da`
| `"ght rise"` | `6768742072697365` | `6a23ec60c10e6054`
| `" just on"` | `206a757374206f6e` | `5a3a3f17bab9130f`
| `" the edg"` | `2074686520656467` | `c93a638b0abecee1`
| `"e of the"` | `65206f6620746865` | `ae623faf7a933083`
| `" village"` | `2076696c6c616765` | `8122a518802c545e`
| `"."`        | `2e07070707070707` | `39600438116299c4`

In the last block, because there is only 1 byte of message left, you pad the rest of the bytes in the block with the number of bytes which are empty (in this case, 7, `0x07`).
