This is my version of the **[42](https://www.42.us.org/)** cadet projects `ft_ssl_md5` and `ft_ssl_des` from the encryption branch.

# ft_ssl
Recoding parts of OpenSSL. In `C`. Made to run on little-endian machines.

# Stuffs
`-i`, input file to read from [default: stdin]<br>
`-o`, output file to write to [default: stdout]

<table style="vertical-align:center;">
	<tr align="center">
		<td><b></b></td>
		<td><b>Commands</b></td>
		<td colspan="2"><b>Flags</b></td>
	</tr>
	<tr>
		<td>
			<b>Hashs</b><br>
			<kbd><a href="./_notes_hashing/README_hashing.md">README</a></kbd><br>
			<kbd><a href="./_notes_hashing/test_cases">test cases</a></kbd><br>
			<kbd><a href="./_notes_hashing/fancy_documentation">documentation</a></kbd>
		</td>
		<td>
			<code>md5</code><br>
			<code>sha1</code><br>
			<code>sha256</code><br>
			<code>sha224</code><br>
			<code>sha512</code><br>
			<code>sha384</code>
		</td>
		<td colspan="2">
			<code>-s</code>, input is the given string [default: stdin]
		</td>
	</tr>
	<tr>
		<td>
			<b>DES</b><br>
			<kbd><a href="./_notes_des/README_des.md">README</a></kbd><br>
			<kbd><a href="./_notes_des/test_cases">test cases</a></kbd>
		</td>
		<td>
			<code>des-ecb</code><br>
			<code>des-cbc</code><br>
			<code>des</code>
		</td>
		<td width="50%">
			<code>-a</code>, decode/encode the input/output in base64, depending on the encrypt mode<br>
			<code>-p</code>, password in ascii<br>
			<code>-s</code>, salt in hex<br>
			<code>-k</code>, key in hex<br>
			<code>-v</code>, initialization vector in hex
		</td>
		<td width="50%" rowspan="2">
			<code>-d</code>, decrypt mode [default: encrypt]<br>
			<code>-e</code>, encrypt mode [default: encrypt]
		</td>
	</tr>
		<tr>
		<td>
			<b>Base64</b><br>
			<kbd><a href="./_notes_base64/README_base64.md">README</a></kbd>
		</td>
		<td><code>base64</code></td>
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
