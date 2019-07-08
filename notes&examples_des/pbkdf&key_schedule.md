# PBKDF: turning the password into a key and IV
To start out, you need a password (string) and a salt (64 bits). If you are given a salt value by the user, use that. If not, generate a random one.

* **password:** `"towel"`
* **salt:** `4242424242424242`

Concatenate password and salt together:

| ascii             | hexadecimal |
| ----------------- | ----------- |
| `"towelBBBBBBBB"` |  `74 6f 77 65 6c 42 42 42 42 42 42 42 42`

MD5 hash that:
```MD5 ("towelBBBBBBBB") = daf91e7c5a178dfe90650f38c6e46f2b```

Split that in half. The left half becomes the key, the right half becomes the IV:
* **key:** `daf91e7c5a178dfe`
* **IV:** `90650f38c6e46f2b`

# Key Schedule: turing 1 key into 16 subkeys
We start with our 64-bit key:
`daf91e7c5a178dfe`

Run that through permuted choice 1, turing the key from 64-bits to 56-bits:
`0c39b8abb5ecdff`

Split that into 2 halves of 28-bits:

|       | hexadecimal |
| ----: | ----------- |
| left  | `c39b8ab`   |
| right | `b5ecdff`   |

Now the 16 rounds. Within each round,
1. the halves' bits are each rotated left by the number specified in the rotation table
2. concatenated together again (56-bits)
3. run through permuted choice 2 (56-bits to 48-bits)

| round | left | right | concatenated | PC-2 |
| ----: | ---- | ----- | ------------ | ---- |
|  0 | `8737157` | `6bd9bff` | `87371576bd9bff` | `b9c2fcfffd4c` |
|  1 | `0e6e2af` | `d7b37fe` | `0e6e2afd7b37fe` | `a5fc9a5f9eef` |
|  2 | `39b8abc` | `5ecdffb` | `39b8abc5ecdffb` | `762fc2defdf9` |
|  3 | `e6e2af0` | `7b37fed` | `e6e2af07b37fed` | `7afc112bff7d` |
|  4 | `9b8abc3` | `ecdffb5` | `9b8abc3ecdffb5` | `4da55efbfdb2` |
|  5 | `6e2af0e` | `b37fed7` | `6e2af0eb37fed7` | `66c49fed4f3f` |
|  6 | `b8abc39` | `cdffb5e` | `b8abc39cdffb5e` | `7f8922df7ade` |
|  7 | `e2af0e6` | `37fed7b` | `e2af0e637fed7b` | `aaa8bbf5d3fd` |
|  8 | `c55e1cd` | `6ffdaf6` | `c55e1cd6ffdaf6` | `89f2c7ffee9c` |
|  9 | `1578737` | `bff6bd9` | `1578737bff6bd9` | `315fce7977df` |
| 10 | `55e1cdc` | `ffdaf66` | `55e1cdcffdaf66` | `7071e1bff0af` |
| 11 | `5787371` | `ff6bd9b` | `5787371ff6bd9b` | `91cd75e67fe7` |
| 12 | `5e1cdc5` | `fdaf66f` | `5e1cdc5fdaf66f` | `c56397beabff` |
| 13 | `7873715` | `f6bd9bf` | `7873715f6bd9bf` | `3797a5f7dfd3` |
| 14 | `e1cdc55` | `daf66ff` | `e1cdc55daf66ff` | `db10e35fa77b` |
| 15 | `c39b8ab` | `b5ecdff` | `c39b8abb5ecdff` | `49aa7bf4d7ff` |

The PC-2 values are your subkeys for encryption mode:
```
subkey[ 0] = b9c2fcfffd4c
subkey[ 1] = a5fc9a5f9eef
subkey[ 2] = 762fc2defdf9
subkey[ 3] = 7afc112bff7d
subkey[ 4] = 4da55efbfdb2
subkey[ 5] = 66c49fed4f3f
subkey[ 6] = 7f8922df7ade
subkey[ 7] = aaa8bbf5d3fd
subkey[ 8] = 89f2c7ffee9c
subkey[ 9] = 315fce7977df
subkey[10] = 7071e1bff0af
subkey[11] = 91cd75e67fe7
subkey[12] = c56397beabff
subkey[13] = 3797a5f7dfd3
subkey[14] = db10e35fa77b
subkey[15] = 49aa7bf4d7ff
```

For decryption mode, you just invert the subkeys' order:
```
subkey[ 0] = 49aa7bf4d7ff
subkey[ 1] = db10e35fa77b
subkey[ 2] = 3797a5f7dfd3
subkey[ 3] = c56397beabff
subkey[ 4] = 91cd75e67fe7
subkey[ 5] = 7071e1bff0af
subkey[ 6] = 315fce7977df
subkey[ 7] = 89f2c7ffee9c
subkey[ 8] = aaa8bbf5d3fd
subkey[ 9] = 7f8922df7ade
subkey[10] = 66c49fed4f3f
subkey[11] = 4da55efbfdb2
subkey[12] = 7afc112bff7d
subkey[13] = 762fc2defdf9
subkey[14] = a5fc9a5f9eef
subkey[15] = b9c2fcfffd4c
```
