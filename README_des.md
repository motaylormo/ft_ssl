# DES encryption
**DES** stands for **Data Encryption Standard**.

# Tables
DES uses a _bunch_ of tables. They are detalied on wikipedia **[here](https://en.wikipedia.org/wiki/DES_supplementary_material)**.

### Permutations
Permutations involve reordering bits in accordance to the table. For example if the first number of the table is 10, then the first bit of the output will be the 10th bit of the input.

Keep in mind that these permutation tables _are not 0-indexed!_
* **Initial permutation (IP)** is the first thing done to a block during encryption/decryption. It reorders 64 bits.
* **Final permutation (IP<super>−1</super>)** is the last thing done to a block during encryption/decryption. It reorders 64 bits.
* Within the feistel function:
    * **Expansion (E)** expands it from 32-bits to 48-bits.
    * **Permutation (P)**, also called **pbox permutation**, reorders 32 bits.
* Within the key schedule:
    * **Permuted choice 1 (PC-1)** is the first thing done to a key. It takes 64 bits as input, and returns 56 bits as output.
    * **Permuted choice 2 (PC-2)** is the last thing done to a subkey. It takes 56 bits as input, and returns 48 bits as output.

### Substitution boxes
**Substitution boxes (S-boxes)** transform 48-bits into 32-bits.
1. The 48 bits are split into 8 groups of 6 bits.
2. In each sextet, the first and last bit are combined into a 2-bit number, and the middle 4 bits are another number.
3. In the format of `[nth of the sextet][2-bit number][4-bit number value]`, look it up in the substitution boxes.
4. Save that number from that index as 4-bits in your output 32.

# Functions
* The **PBKDF (password-based key derivation function)** in a function which derives a key and IV from the password.
    * The **password** is a string.
    * The **salt** is 64-bits, typically randomly generated, which are concatenated onto the end of the password.
    * The **key** is 64-bits, typically created by the PBKDF, from which the subkeys are derived.
    * The **IV (initialization vector)** is 64-bits, typically created by the PBKDF, which is used in CBC mode.
* The **key schedule** derives the subkeys from the key.
    * Input: 1 key (64-bits)
    * Output: 16 subkeys (each 48-bits)
* The encryption/decryption function is run on each 64-bit block of message.
* The **F-function (Feistel function)** is a major feature of a round in DES, and is run on a half-block (32-bits)

# Pseudocode & Diagrams
### PBKDF
```
pbkdf (password) {
   generate salt
   md5(concatenate password + salt)
   split hash into left and right halves
   key = left
   iv = right
}
```
### Key schedule
<img src="https://upload.wikimedia.org/wikipedia/commons/0/06/DES-key-schedule.png" width="300px" />

```
key schedule (key) {
     Permuted choice 1
     split into left and right halves
     for 16 rounds {
          left-rotate both halves by the number specified in rotation table
          concatenate left + right half
          subkey[round] = permuted choice 2
     }
}
```
### Encryption/decryption
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/6/6a/DES-main-network.png/500px-DES-main-network.png" width="300px" />

```
encryption/decryption (block, subkeys[16]) {
     initial permutation
     split into left and right halves
     for 16 rounds {
          xor sum = left ^ feistel(right, subkey[round])
          left = right
          right = xor sum
     }
     concatenate right + left half
     final permutation
}
```
### Feistel function
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/2/25/Data_Encription_Standard_Flow_Diagram.svg/500px-Data_Encription_Standard_Flow_Diagram.svg.png" width="300px" />

```
feistel (half block, subkey) {
     expansion
     expanded ^ subkey
     substitution boxes
     permutation
}
```


# Block cipher modes of operation
This program has ECB and CBC. Other ones exist, but I did not include any others.

### ECB (Electronic Codebook)
ECB is simplest one.
![Wikipedia's ECB diagram](https://upload.wikimedia.org/wikipedia/commons/d/d6/ECB_encryption.svg)

### CBC (Cipher Block Chaining)
CBC has each block XORed with the previous block. The blocks are all linked together, like a chain. For the very first block, it's XORed with the IV (initialization vector).
![Wikipedia's CBC encryption diagram](https://upload.wikimedia.org/wikipedia/commons/8/80/CBC_encryption.svg)
![Wikipedia's CBC decryption diagram](https://upload.wikimedia.org/wikipedia/commons/2/2a/CBC_decryption.svg)
