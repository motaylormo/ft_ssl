This is my version of the **[42](https://www.42.us.org/)** cadet projects `ft_ssl_md5` and `ft_ssl_des` from the encryption branch.

# ft_ssl
Recoding parts of OpenSSL. In `C`. Made to run on little-endian machines.

### Cryptographic hashing algorithms <kbd>[README](./README_hashing.md)</kbd> <kbd>[test cases](./hashing/test_cases)</kbd>

| Commands | Flags |
| -------- | ----- |
| `md5`    | `-s`, input is the given string [default: stdin]
| `sha1`
| `sha256`
| `sha224`
| `sha512`
| `sha384`

### DES <kbd>[README](./README_des.md)</kbd> <kbd>[test cases](./des/test_cases)</kbd>

| Commands | Flags |
| -------- | ----- |
| `des-ecb`      | `-d`, decrypt mode [default: encrypt]
| `des-cbc`      | `-e`, encrypt mode [default: encrypt]
| `des`, des-cbc | `-i`, input file for message [default: stdin]
|                | `-o`, output file for message [default: stdout]
|                | `-a`, decode/encode the input/output in base64, depending on the encrypt mode
|                | `-p`, password in ascii
|                | `-s`, salt in hex
|                | `-k`, key in hex
|                | `-v`, initialization vector in hex

### Base 64 <kbd>[README](./README_base64.md)</kbd>

| Commands | Flags |
| -------- | ----- |
| `base64` | `-d`, decode mode [default: encrypt]
|          | `-e`, encode mode [default: encrypt]
|          | `-i`, input file [default: stdin]
|          | `-o`, output file [default: stdout]

# Test cases
Several deliberate features of cryptographic hash functions—for example, the fact that they're one-way and you can't back-evaluate, or how the _slightest_ difference makes the output look _entirely_ different—make it **very difficult** to figure out why a program is not working properly.

So I created test cases: They're meticulous traces of what the values should be every step along the way, so you can compare that to the values _you_ have and figure out where you're going wrong.

# Usage
Real OpenSSL's usage prints out its options in the format of 4 columns, each 18 chracters wide. This remains constant, regardless of the window's width; it does not resize to fit.

I did the same, but I listed the flags there as well.

# Other notes
* **[This](https://wiki.openssl.org/index.php/Enc)** is a really good list of all the flags for real OpenSSL.
