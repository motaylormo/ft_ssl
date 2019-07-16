**message:**<br>`"abc"`

## Padded message
Message transformed into padded binary<br>(message + 1 + 0s + number of message bits as a 64-bit *little* endian number)
```
01100001 01100010 01100011 10000000  00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000  00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000  00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000  00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000  00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000  00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000  00000000 00000000 00000000 00000000
00011000 00000000 00000000 00000000  00000000 00000000 00000000 00000000
```

## Hash intialized
```
H[0] = 67452301
H[1] = efcdab89
H[2] = 98badcfe
H[3] = 10325476
```

## Words (first block)
512-bit block of the binary, clumped into 32-bit "words"
```
W[ 0] = 80636261
W[ 1] = 00000000
W[ 2] = 00000000
W[ 3] = 00000000
W[ 4] = 00000000
W[ 5] = 00000000
W[ 6] = 00000000
W[ 7] = 00000000
W[ 8] = 00000000
W[ 9] = 00000000
W[10] = 00000000
W[11] = 00000000
W[12] = 00000000
W[13] = 00000000
W[14] = 00000018
W[15] = 00000000
```

## Compression function (first block)
Hex values for the working variables after each pass in the compression function:
```
        (a)         (b)         (c)         (d)
init) 67452301    efcdab89    98badcfe    10325476
   0) 10325476    d6d117b4    efcdab89    98badcfe
   1) 98badcfe    344a8432    d6d117b4    efcdab89
   2) efcdab89    2f6fbd72    344a8432    d6d117b4
   3) d6d117b4    7ad956f2    2f6fbd72    344a8432
   4) 344a8432    c73741ef    7ad956f2    2f6fbd72
   5) 2f6fbd72    8bac3051    c73741ef    7ad956f2
   6) 7ad956f2    207dc67b    8bac3051    c73741ef
   7) c73741ef    928d99f6    207dc67b    8bac3051
   8) 8bac3051    854b3712    928d99f6    207dc67b
   9) 207dc67b    74e2f284    854b3712    928d99f6
  10) 928d99f6    3020401c    74e2f284    854b3712
  11) 854b3712    5ed49596    3020401c    74e2f284
  12) 74e2f284    dda9b9a6    5ed49596    3020401c
  13) 3020401c    a1051895    dda9b9a6    5ed49596
  14) 5ed49596    e396856b    a1051895    dda9b9a6
  15) dda9b9a6    72aff2e0    e396856b    a1051895
  16) a1051895    3e9e9126    72aff2e0    e396856b
  17) e396856b    4a1d804e    3e9e9126    72aff2e0
  18) 72aff2e0    e25e1652    4a1d804e    3e9e9126
  19) 3e9e9126    b5b204e4    e25e1652    4a1d804e
  20) 4a1d804e    59a8ffda    b5b204e4    e25e1652
  21) e25e1652    6d002f1e    59a8ffda    b5b204e4
  22) b5b204e4    abfc7920    6d002f1e    59a8ffda
  23) 59a8ffda    47092c07    abfc7920    6d002f1e
  24) 6d002f1e    b7f268cf    47092c07    abfc7920
  25) abfc7920    09388eff    b7f268cf    47092c07
  26) 47092c07    fe1623b1    09388eff    b7f268cf
  27) b7f268cf    786acb8f    fe1623b1    09388eff
  28) 09388eff    790a77fb    786acb8f    fe1623b1
  29) fe1623b1    9f47e4f8    790a77fb    786acb8f
  30) 786acb8f    a62884aa    9f47e4f8    790a77fb
  31) 790a77fb    726342d3    a62884aa    9f47e4f8
  32) 9f47e4f8    b3707ebf    726342d3    a62884aa
  33) a62884aa    60127b2e    b3707ebf    726342d3
  34) 726342d3    8d212ff5    60127b2e    b3707ebf
  35) b3707ebf    3b0875c7    8d212ff5    60127b2e
  36) 60127b2e    21b117b9    3b0875c7    8d212ff5
  37) 8d212ff5    6e7429d5    21b117b9    3b0875c7
  38) 3b0875c7    3575227e    6e7429d5    21b117b9
  39) 21b117b9    5a2f5ea5    3575227e    6e7429d5
  40) 6e7429d5    11de1779    5a2f5ea5    3575227e
  41) 3575227e    fadcaa38    11de1779    5a2f5ea5
  42) 5a2f5ea5    31c465ca    fadcaa38    11de1779
  43) 11de1779    4c6124f4    31c465ca    fadcaa38
  44) fadcaa38    7f2e507b    4c6124f4    31c465ca
  45) 31c465ca    99d9679d    7f2e507b    4c6124f4
  46) 4c6124f4    8fae6399    99d9679d    7f2e507b
  47) 7f2e507b    7beb9700    8fae6399    99d9679d
  48) 99d9679d    7b201df8    7beb9700    8fae6399
  49) 8fae6399    f4e8e96e    7b201df8    7beb9700
  50) 7beb9700    b298cefd    f4e8e96e    7b201df8
  51) 7b201df8    8bf025c4    b298cefd    f4e8e96e
  52) f4e8e96e    06cc5e8a    8bf025c4    b298cefd
  53) b298cefd    5b0d97aa    06cc5e8a    8bf025c4
  54) 8bf025c4    7d632dd0    5b0d97aa    06cc5e8a
  55) 06cc5e8a    3bfa2c27    7d632dd0    5b0d97aa
  56) 5b0d97aa    7f81cc35    3bfa2c27    7d632dd0
  57) 7d632dd0    094454ab    7f81cc35    3bfa2c27
  58) 3bfa2c27    4f9dbe3f    094454ab    7f81cc35
  59) 7f81cc35    7327d604    4f9dbe3f    094454ab
  60) 094454ab    310ade8f    7327d604    4f9dbe3f
  61) 4f9dbe3f    624d8cb2    310ade8f    7327d604
  62) 7327d604    e484b9d8    624d8cb2    310ade8f
  63) 310ade8f    c08226b3    e484b9d8    624d8cb2
```

Add those values back to the hash:
```
H[0] + a = 67452301 + 310ade8f = 98500190
H[1] + b = efcdab89 + c08226b3 = b04fd23c
H[2] + c = 98badcfe + e484b9d8 = 7d3f96d6
H[3] + d = 10325476 + 624d8cb2 = 727fe128
```

Since there is only 1 block, this is the end.

## Endian flip
Flip the endianness of the final hash:
```
 Pre:  98500190    b04fd23c    7d3f96d6    727fe128
Post:  90015098    3cd24fb0    d6963f7d    28e17f72
```

## Final hash
```
90015098 3cd24fb0 d6963f7d 28e17f72
```
