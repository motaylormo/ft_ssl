* **message:** `"The house stood on a slight rise just on the edge of the village."`
* **key:** `daf91e7c5a178dfe`

# Message blocks

In the last block, because there is only 1 byte of message left, you pad the rest of the bytes in the block with the number of bytes which are empty (in this case, 7, `0x07`).

| plaintext<br>ascii | plaintext<br>hexadecimal | encrypted<br>ascii | encrypted<br>hexadecimal |
| ------------------ | ------------------------ | ------------------ | ------------------------ |
| `The hous` | `73756f6820656854` | <pre>)M�A�{�</pre> | `18cf7ba841804d29`
| `e stood ` | `20646f6f74732065` | <pre>�_>�h+V,</pre> | `2c562b68b93e5fc0`
| `on a sli` | `696c732061206e6f` | <pre>�fUx%���</pre> | `da92b42578556685`
| `ght rise` | `6573697220746867` | <pre>j#�`�`T</pre> | `54600ec160ec236a`
| ` just on` | `6e6f207473756a20` | <pre>Z:?��</pre> | `0f13b9ba173f3a5a`
| ` the edg` | `6764652065687420` | <pre>�:c�
���</pre> | `e1cebe0a8b633ac9`
| `e of the` | `65687420666f2065` | <pre>�b?�z�0�</pre> | `8330937aaf3f62ae`
| ` village` | `6567616c6c697620` | <pre>�"��,T^</pre> | `5e542c8018a52281`
| `.` | `070707070707072e` | <pre>9`8b��</pre> | `c499621138046039`

Plaintext message:
<pre>The house stood on a slight rise just on the edge of the village.</pre>

Encrypted message:

<pre>)M€A¨{ÏÀ_>¹h+V,…fUx%´’Új#ì`Á`TZ:?º¹É:c‹
¾Îá®b?¯z“0ƒ"¥€,T^9`8b™Ä</pre>
