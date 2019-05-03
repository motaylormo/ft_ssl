# ft_ssl
Recoding parts of OpenSSL. Cryptographic hashing algorithms MD5, SHA-256, SHA-224, SHA-1, SHA-512, and SHA-384. DES both ECB and CBC. Made to run on little-endian machines. In `C`.

This is my version of the **[42](https://www.42.us.org/)** cadet projects `ft_ssl_md5` and `ft_ssl_des`.

# Cryptographic hashing
Several deliberate features of cryptographic hash functions (for example, the fact that they're one-way and you can't back-evaluate, or how the _slightest_ difference makes the output look _entirely_ different) make it **very difficult** to figure out why a program is not working properly.

So I created the **[notes&examples_hashing](https://github.com/motaylormo/ft_ssl/tree/master/notes%26examples_hashing)** folder: They're meticulous traces of what the values should be every step along the way for test cases, so you can compare that to the values _you_ have and figure out where you're going wrong.

### Algorithms
<table>
  <tr>
    <th text-align=right>Algorithm</th>
    <th>Digest size</th>
    <th>Block size</th>
    <th>Words</th>
    <th>Rounds</th>
    <th>Checksum</th>
  </tr>
  <tr>
    <td>MD5</td>
    <td>128 bits<br>(4 * 32-bits)</td>
    <td>512 bits</td>
    <td>16 (32-bits each)</td>
    <td>64</td>
    <td>32 chars<br>(128 bits / 4)</td>
  </tr>
  <tr>
    <td>SHA-256</td>
    <td rowspan=2>256 bits<br>(8 * 32-bits)</td>
    <td rowspan=2>512 bits</td>
    <td rowspan=2>64 (32-bits each)</td>
    <td rowspan=2>64</td>
    <td>64 chars<br>(256 bits / 4)</td>
  </tr>
  <tr>
    <td>SHA-224</td>
    <td>56 chars<br>(224 bits) / 4)</td>
  </tr>
  <tr>
    <td>SHA-1</td>
    <td>160 bits<br>(5 * 32-bits)</td>
    <td>512 bits</td>
    <td>80 (32-bits each)</td>
    <td>80</td>
    <td>40 chars<br>(160 bits / 4)</td>
  </tr>
  <tr>
    <td>SHA-512</td>
    <td rowspan=2>512 bits<br>(8 * 64-bits)</td>
    <td rowspan=2>1024 bits</td>
    <td rowspan=2>80 (64-bits each)</td>
    <td rowspan=2>80</td>
    <td>128 chars<br>(512 bits / 4)</td>
  </tr>
  <tr>
    <td>SHA-384</td>
    <td>96 chars<br>(384 bits / 4)</td>
  </tr>
</table>

SHA-224 is a variant of SHA-256, and SHA-384 is a variant of SHA-512. They're just the same as their root algorithms, except:
1. The internal state has different initialization values.
2. It the same size digest all the way through, but at the very end, these variants only take a portion of that for the checksum output. SHA-224 uses the first 224 of 256 bits. SHA-384 uses the first 284 of 512-bits. The rest are discarded.

### Terminology
* The **message** is the input.
    * The **padded message** is the message with padding added to the end so that it is of a length that divides neatly into the block size.
    * The **block** is a portion of the padded message.
    * The **words** are the block, usually after undergoing a transformation. Typically the first 16 words are just the block, and the rest are derived from those first 16. This is the form of the block used by the compression function.
* The **digest** is the bitfield that is transformed throughout the algorithm. Because it's ever-changing, it's a somewhat vague term. Also sometimes called the **hash**.
    * The **internal state** is the part that is initialized at the beginning, and then added to after each compression of a data block.
    * The **checksum** is the output; the final internal state, converted to hexadecimal.
* The **compression function** is the real guts of a cryptographic hashing algorithm. It runs once per block of message. It takes in the current internal state, and a set of words (ie the block). It spits out a set of numbers which are then added back into the internal state.
    * The **rounds** are the sets of transformations that happen each time the compression function is run.

### Not really terminology, but naming conventions
* The internal state is usually an array called `h[]`. ("h" for "hash".)
* The working variables inside the compression function are typically lettered: `a`, `b`, `c`, `d`, ect.
* `k[]` is an array of constants used within the compression function. (Possibly `k` for "key"? Or `k` as a phonetic version of "constant," since `c` is already a working variable?)
* The words are sometimes seen called `w[]` and sometimes `m[]`. (`m` for "message," but since they've been transformed by this point, I think `w` for "words" is a clearer name.)

# DES encryption
### Block cipher modes of operation
**ECB (Electronic Codebook)** is the most straight-forward one.
![Wikipedia's ECB diagram](https://upload.wikimedia.org/wikipedia/commons/d/d6/ECB_encryption.svg)

**CBC (Cipher Block Chaining)** has each block XORed with the previous block. The blocks are all linked together, like a chain. For the very first block, it's XORed with the IV (initialization vector).
![Wikipedia's CBC encryption diagram](https://upload.wikimedia.org/wikipedia/commons/8/80/CBC_encryption.svg)
![Wikipedia's CBC decryption diagram](https://upload.wikimedia.org/wikipedia/commons/2/2a/CBC_decryption.svg)

### Tables
DES uses a _bunch_ of tables. They are detalied on wikipedia **[here](https://en.wikipedia.org/wiki/DES_supplementary_material)**.

Permutations involve reordering bits in accordance to the table. For example if the first number of the table is 10, then the first bit of the output will be the 10th bit of the input.

Keep in mind that these permutation tables _are not 0-indexed!_
* **Initial permutation** is the first thing done to a block during encryption/decryption. It reorders 64 bits.
* **Final permutation** is the last thing done to a block during encryption/decryption. It reorders 64 bits.
* Within the feistel function:
    * **Expansion** expands it from 32-bits to 48-bits.
    * **Permutation**, also called **pbox permutation**, reorders 32 bits.
* Within the key schedule:
    * **Permuted choice 1** is the first thing done to a key. It takes 64 bits as input, and returns 56 bits as output.
    * **Permuted choice 2** is the last thing done to a subkey. It takes 56 bits as input, and returns 48 bits as output.

The **s-boxes (substitution boxes)** take 48 bits as input, and return 32 bits as output.
1. The 48 bits are split into 8 groups of 6 bits.
2. In each sextet, the first and last bit are combined into a 2-bit number, and the middle 4 bits are another number.
3. In the format of `[nth of the sextet][2-bit number][4-bit number value]`, look it up in the substitution boxes.
4. Save that number from that index as 4-bits in your output 32.

### Terminology
* **des** stands for **Data Encryption Standard**.
* **pbkdf (password-based key derivation function** in a function which turns the password into a key and iv.
    * The **password** is a string
    * The **salt** is 64-bits, typically randomly generated, which are concatenated onto the end of the password.
    * The **key** is 64-bits, typically created by the pbkdf, from which the subkeys are derived.
    * The **iv (initialization vector)** is 64-bits, typically created by the pbkdf, which is used in CBC mode.
* The **message** is the input.
    * The **block** is a 64-bit portion of the padded message.
* **f function (Feistel function)** is the main part of a round in DES. 
