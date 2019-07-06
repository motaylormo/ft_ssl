# PBKDF: turning the password into a key and IV
To start out, you need a password (string) and a salt (64 bits). If you are given a salt value by the user, use that. If not, generate a random one.

* **password:** `"towel"`
* **salt:** `4242424242424242`

Concatenate password and salt together:

* **hex:** `74 6f 77 65 6c 42 42 42 42 42 42 42 42`
* **ascii:** `"towelBBBBBBBB"`

MD5 hash that:

```
MD5 ("towelBBBBBBBB") = daf91e7c5a178dfe90650f38c6e46f2b
```

Split that in half. The left half becomes the key, the right half becomes the IV:
* **key:** `daf91e7c5a178dfe`
* **IV:** `90650f38c6e46f2b`

# Key Schedule: turing 1 key into 16 subkeys
