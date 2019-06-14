# DES encryption
**DES** stands for **Data Encryption Standard**.

# Tables
DES uses a _bunch_ of tables. They are detalied on wikipedia **[here](https://en.wikipedia.org/wiki/DES_supplementary_material)**.

### Permutations
Permutations involve reordering bits in accordance to the table. For example if the first number of the table is 10, then the first bit of the output will be the 10th bit of the input.

Keep in mind that the permutation tables _are not 0-indexed!_

| Permutation               | Input   | Output  |
| ------------------------- | ------- | ------- |
| Initial permutation (IP)  | 64 bits | 64 bits |
| Final permutation (IP⁻¹)  | 64 bits | 64 bits |
| Expansion permutation (E) | 32 bits | 48 bits |
| P-box permutation (P)     | 32 bits | 32 bits |
| Permuted choice 1 (PC-1)  | 64 bits | 56 bits |
| Permuted choice 2 (PC-2)  | 56 bits | 48 bits |

### Substitution boxes
**Substitution boxes (S-boxes)** transform 48-bits into 32-bits.
1. The 48 bits are split into 8 groups of 6 bits.
2. In each sextet, the first and last bit are combined into a 2-bit number, and the middle 4 bits are another number.
3. In the format of `[nth of the sextet][2-bit number][4-bit number value]`, look it up in the substitution boxes.
4. Save that number from that index as 4-bits in your output 32.

<details><summary><h4>Example</h4></summary>

Input (48-bits):<br>```011000 010001 011110 111010 100001 100110 010100 100111```

| Sextet   | 2-bit and 4-bit         | S-box lookup       | S-box value |
| -------- | ----------------------- | ------------------ | ----------- |
| `011000` | `00` = 0<br>`1100` = 12 | sbox[0][0][12] = 5 |  5 = `0101` |
| `010001` | `01` = 1<br>`1000` = 8  | sbox[1][1][8] = 12 | 12 = `1100` |
| `011110` | `00` = 0<br>`1111` = 15 | sbox[2][0][15] = 8 |  8 = `1000` |
| `111010` | `10` = 2<br>`1101` = 13 | sbox[3][2][13] = 2 |  2 = `0010` |
| `100001` | `11` = 3<br>`0000` = 0  | sbox[4][3][0] = 11 | 11 = `1011` |
| `100110` | `10` = 2<br>`0011` = 3  | sbox[5][2][3] = 5  |  5 = `0101` |
| `010100` | `00` = 0<br>`1010` = 10 | sbox[6][0][10] = 9 |  9 = `1001` |
| `100111` | `11` = 3<br>`0011` = 3  | sbox[7][3][3] = 7  |  7 = `0111` |

Output (32-bits):<br>```0101 1100 1000 0010 1011 0101 1001 0111```
</details>

# Functions
* The **PBKDF (password-based key derivation function)** in a function which derives a key and IV from the password.
    * The **password** is a string.
    * The **salt** is 64-bits which are concatenated onto the end of the password. Unless specified, it's randomly generated.
    * The **key** is 64-bits from which the subkeys are derived. Unless specified, it's created by the PBKDF.
    * The **IV (initialization vector)** is 64-bits which is used in CBC mode. Unless specified, it's created by the PBKDF.
* The **key schedule** derives the subkeys from the key.
    * Input: 1 key (64-bits)
    * Output: 16 subkeys (each 48-bits)
* The encryption/decryption function is run on each 64-bit block of message.
* The **F-function (Feistel function)** is a major feature of a round in DES, and is run on a half-block (32-bits)

# Block cipher modes of operation
This program has ECB and CBC. Other ones exist, but I did not include any others.

### ECB (Electronic Codebook)
ECB is simplest one. It's simply encrypted/decrypted block by block.

<img src="https://upload.wikimedia.org/wikipedia/commons/d/d6/ECB_encryption.svg" alt="Wikipedia's ECB diagram" width="100%" max-width="700px">

### CBC (Cipher Block Chaining)
CBC has each block XORed with the previous block. The blocks are all linked together, like a chain. For the very first block, it's XORed with the IV (initialization vector).

In both cases, it's XORed with the _un-encrypted_ block (aka the readable one).
* In encryption mode, this means the plaintext block (aka _before_ encryption)
* In decryption mode, this means the decrypted block (aka _after_ decryption)

<img src="https://upload.wikimedia.org/wikipedia/commons/8/80/CBC_encryption.svg" alt="Wikipedia's CBC encryption diagram" width="700px" max-width="100%">

<img src="https://upload.wikimedia.org/wikipedia/commons/2/2a/CBC_decryption.svg" alt="Wikipedia's CBC decryption diagram" width="700px" max-width="100%">
