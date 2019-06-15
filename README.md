This is my version of the **[42](https://www.42.us.org/)** cadet projects `ft_ssl_md5` and `ft_ssl_des` from the encryption branch.

# ft_ssl
Recoding parts of OpenSSL. In `C`. Made to run on little-endian machines.

* Cryptographic hashing algorithms (see the **[hashing README](./README_hashing.md)**)
    * MD5
    * SHA-1
    * SHA-256
    * SHA-224
    * SHA-512
    * SHA-384
* DES (see the **[des README](./README_des.md)**)
    * ECB
    * CBC

# notes&examples
Several deliberate features of cryptographic hash functions (for example, the fact that they're one-way and you can't back-evaluate, or how the _slightest_ difference makes the output look _entirely_ different) make it **very difficult** to figure out why a program is not working properly.

So I created the **[notes&examples_hashing](./notes%26examples_hashing)** folder: They're meticulous traces of what the values should be every step along the way for cryptographic hash test cases, so you can compare that to the values _you_ have and figure out where you're going wrong.

**[notes&examples_des](./notes%26examples_des)** is the same idea for DES, but to a lesser extent.

**[This](https://wiki.openssl.org/index.php/Enc)** is a really good list of all the flags for real OpenSSL.
