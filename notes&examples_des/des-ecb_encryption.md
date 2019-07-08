* **message:** `"The house stood on a slight rise just on the edge of the village."`
* **key:** `daf91e7c5a178dfe`

# Message blocks
In the last block, because there is only 1 byte of message left, you pad the rest of the bytes in the block with the number of bytes which are empty (in this case, 7, `0x07`).

| plaintext<br>ascii | plaintext<br>hexadecimal | encrypted<br>ascii | encrypted<br>hexadecimal |
| ------------------ | ------------------------ | ------------------ | ------------------------ |
| `The hous` | `73756f6820656854` | ```)M�A�{�``` | `18cf7ba841804d29`
| `e stood ` | `20646f6f74732065` | ```�_>�h+V,``` | `2c562b68b93e5fc0`
| `on a sli` | `696c732061206e6f` | ```�fUx%���``` | `da92b42578556685`
| `ght rise` | `6573697220746867` | ```j#�`�`T``` | `54600ec160ec236a`
| ` just on` | `6e6f207473756a20` | ```Z:?��``` | `0f13b9ba173f3a5a`
| ` the edg` | `6764652065687420` | ```�:c�```<br>```���``` | `e1cebe0a8b633ac9`
| `e of the` | `65687420666f2065` | ```�b?�z�0�``` | `8330937aaf3f62ae`
| ` village` | `6567616c6c697620` | ```�"��,T^``` | `5e542c8018a52281`
| `.` | `070707070707072e` | ```9`8b��``` | `c499621138046039`

**Plaintext message:**
<pre>The house stood on a slight rise just on the edge of the village.</pre>

**Encrypted message:**
<pre>)M€A¨{ÏÀ_>¹h+V,…fUx%´’Új#ì`Á`TZ:?º¹É:c‹
¾Îá®b?¯z“0ƒ"¥€,T^9`8b™Ä</pre>
