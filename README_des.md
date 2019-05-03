# DES encryption
**DES** stands for **Data Encryption Standard**.

# Functions
* The **PBKDF (password-based key derivation function** in a function which derives a key and IV from the password.
    * The **password** is a string.
    * The **salt** is 64-bits, typically randomly generated, which are concatenated onto the end of the password.
    * The **key** is 64-bits, typically created by the PBKDF, from which the subkeys are derived.
    * The **IV (initialization vector)** is 64-bits, typically created by the PBKDF, which is used in CBC mode.
* The **key schedule** derives the subkeys from the key.
    * Input: 1 key (64-bits)
    * Output: 16 subkeys (each 48-bits)
* The encryption/decryption function is run on each 64-bit block of message.
...1. Initial permutation
...2. Split into left and right halves
...3. Run the 16 rounds
...4. Concatenate the halves back togeher
...4. Final permutation
* The **F-function (Feistel function)** is a major feature of a round in DES.
    * Input: Half-block (32-bits)
    * Output: Half-block (32-bits)

# Tables
DES uses a _bunch_ of tables. They are detalied on wikipedia **[here](https://en.wikipedia.org/wiki/DES_supplementary_material)**.

### Permutations
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

### Substitution boxes
The **s-boxes (substitution boxes)** take 48 bits as input, and return 32 bits as output.
1. The 48 bits are split into 8 groups of 6 bits.
2. In each sextet, the first and last bit are combined into a 2-bit number, and the middle 4 bits are another number.
3. In the format of `[nth of the sextet][2-bit number][4-bit number value]`, look it up in the substitution boxes.
4. Save that number from that index as 4-bits in your output 32.

# Block cipher modes of operation
This program has ECB and CBC. Other ones exist, but I did not include any others.

### ECB (Electronic Codebook)
ECB is simplest one.
![Wikipedia's ECB diagram](https://upload.wikimedia.org/wikipedia/commons/d/d6/ECB_encryption.svg)

### CBC (Cipher Block Chaining)
CBC has each block XORed with the previous block. The blocks are all linked together, like a chain. For the very first block, it's XORed with the IV (initialization vector).
![Wikipedia's CBC encryption diagram](https://upload.wikimedia.org/wikipedia/commons/8/80/CBC_encryption.svg)
![Wikipedia's CBC decryption diagram](https://upload.wikimedia.org/wikipedia/commons/2/2a/CBC_decryption.svg)
