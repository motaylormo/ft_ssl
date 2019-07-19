This is my version of the **[42](https://www.42.us.org/)** cadet projects `ft_ssl_md5` and `ft_ssl_des` from the encryption branch.

# ft_ssl
Recoding parts of OpenSSL. In `C`. Made to run on little-endian machines.

# Commands

| Cryptographic hash | DES                | Base64             |
| ------------------ | ------------------ | ------------------ |
| [README](./_notes_hashing/README_hashing.md) | [README](./_notes_des/README_des.md) | [README](./_notes_base64/README_base64.md)
| [test cases](./_notes_hashing/test_cases) | [test cases](./_notes_des/test_cases) | [test cases](./_notes_base64/test_cases.md)
| [documentation](./_notes_hashing/fancy_documentation)
| `md5`<br>`sha1`<br>`sha256`<br>`sha224`<br>`sha512`<br>`sha384` | `des-ecb`<br>`des-cbc`<br>`des` | `base64` |

### Flags
* **Default input:** stdin
* **Default output:** stdout
* **Default mode:** encrypt
<table style="vertical-align:center;">
	<tr align="center">
		<td></td>
		<td colspan="3"><b>Flags</b></td>
	</tr>
	<tr>
		<td><b>Hashs</b></td>
		<td colspan="2">
			<code>-s</code>, input is the given string
		</td>
		<td rowspan="3" width="25               %">
			<code>-i</code>, input file to read from<br>
			<code>-o</code>, output file to write to
		</td>
	</tr>
	<tr>
		<td><b>DES</b><br></td>
		<td>
			<code>-a</code>, decode/encode the input/output in base64, depending on the encrypt mode<br>
			<code>-p</code>, password in ascii<br>
			<code>-s</code>, salt in hex<br>
			<code>-k</code>, key in hex<br>
			<code>-v</code>, initialization vector in hex
		</td>
		<td rowspan="2" width="20%">
			<code>-d</code>, decrypt mode<br>
			<code>-e</code>, encrypt mode
		</td>
	</tr>
		<tr>
		<td><b>Base64</b></td>
		<td></td>
	</tr>
</table>

# Test cases
Several deliberate features of cryptographic hash functions—for example, the fact that they're one-way and you can't back-evaluate, or how the _slightest_ difference makes the output look _entirely_ different—make it **very difficult** to figure out why a program is not working properly.

So I created test cases: They're meticulous traces of what the values should be every step along the way, so you can compare that to the values _you_ have and figure out where you're going wrong.

# Usage
Real OpenSSL's usage prints out its options in the format of 4 columns, each 18 chracters wide. This remains constant, regardless of the window's width; it does not resize to fit.

I did the same, but I listed the flags there as well.

# Linkies
* [This](https://wiki.openssl.org/index.php/Enc) is a really good list of all the flags for real OpenSSL.
* [This](https://csrc.nist.gov/csrc/media/publications/fips/180/2/archive/2002-08-01/documents/fips180-2.pdf) is good documentation for SHA.
* [This](http://page.math.tu-berlin.de/~kant/teaching/hess/krypto-ws2006/des.htm) is the best DES resource I could find, but it's very old, and 0-indexed inconsistently.
