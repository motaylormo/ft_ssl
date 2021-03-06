This is my version of the **[42](https://www.42.us.org/)** cadet projects `ft_ssl_md5` and `ft_ssl_des` from the encryption branch.

# ft_ssl
Recoding parts of OpenSSL. In `C`. Made to run on little-endian machines. Meticulously documented in beautiful LaTex PDFs.

# Commands

| Cryptographic hash | DES                | Base64             |
| ------------------ | ------------------ | ------------------ |
| [documentation](./documentation/hashing.pdf) | [documentation](./documentation/DES.pdf)
| [test cases](./test_cases/hashing)           | [test cases](./test_cases/des)
| `md5`<br>`sha1`<br>`sha256`<br>`sha224`<br>`sha512`<br>`sha384` | `des-ecb`<br>`des-cbc`<br>`des` | `base64` |

## Flags
* **Default input:** stdin
* **Default output:** stdout
* **Default mode:** encrypt
<table style="vertical-align:center;">
	<tr>
		<td></td>
		<th colspan="3">Flags</th>
	</tr>
	<tr>
		<th>Hashs</th>
		<td colspan="2">
			<code>-s</code>, input is the given string
		</td>
		<td rowspan="3">
			<code>-i</code>, input file to read from<br>
			<code>-o</code>, output file to write to
		</td>
	</tr>
	<tr>
		<th>DES</th>
		<td>
			<code>-p</code>, password in ascii<br>
			<code>-s</code>, salt in hex<br>
			<code>-k</code>, key in hex<br>
			<code>-v</code>, initialization vector in hex<br>
			<code>-a</code>, decode/encode the input/output in base64,<br>depending on encrypt mode
		</td>
		<td rowspan="2">
			<code>-d</code>, decrypt mode<br>
			<code>-e</code>, encrypt mode
		</td>
	</tr>
		<tr>
		<th>Base64</th>
		<td></td>
	</tr>
</table>

# Test cases
Several deliberate features of cryptographic hash functions—for example, the fact that they're one-way and you can't back-evaluate, or how the _slightest_ difference makes the output look _entirely_ different—make it **very difficult** to figure out why a program is not working properly.

So I created test cases: They're meticulous traces of what the values should be every step along the way, so you can compare that to the values _you_ have and figure out where you're going wrong.

# Linkies
* [This](https://wiki.openssl.org/index.php/Enc) is a really good list of all the flags for real OpenSSL.
* [This](https://csrc.nist.gov/csrc/media/publications/fips/180/2/archive/2002-08-01/documents/fips180-2.pdf) is good documentation for SHA.
* [This](http://page.math.tu-berlin.de/~kant/teaching/hess/krypto-ws2006/des.htm) is the best DES resource I could find, but it's very old, and 0-indexed inconsistently.
* [This](https://academic.csuohio.edu/yuc/security/Chapter_06_Data_Encription_Standard.pdf) is more DES documentation.
* Wikipedia:
	* Cryptographic hashs
		* [MD5](https://en.wikipedia.org/wiki/MD5)
		* [SHA-1](https://en.wikipedia.org/wiki/SHA-1)
		* [SHA-256](https://en.wikipedia.org/wiki/SHA-2)
	* DES
		* [DES](https://en.wikipedia.org/wiki/Data_Encryption_Standard)
		* [DES tables](https://en.wikipedia.org/wiki/DES_supplementary_material)
		* [Modes of operation](https://en.wikipedia.org/wiki/Block_cipher_mode_of_operation)
		* [Salt](https://en.wikipedia.org/wiki/Salt_(cryptography))
	* [Base64](https://en.wikipedia.org/wiki/Base64)
