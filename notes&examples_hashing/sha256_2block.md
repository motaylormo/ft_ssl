**message:**<br>`"abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq"`

## Padded message
Message transformed into padded binary<br>(message + 1 + 0s + message bits len in *big* endian)
```
01100001 01100010 01100011 01100100  01100010 01100011 01100100 01100101
01100011 01100100 01100101 01100110  01100100 01100101 01100110 01100111
01100101 01100110 01100111 01101000  01100110 01100111 01101000 01101001
01100111 01101000 01101001 01101010  01101000 01101001 01101010 01101011
01101001 01101010 01101011 01101100  01101010 01101011 01101100 01101101
01101011 01101100 01101101 01101110  01101100 01101101 01101110 01101111
01101101 01101110 01101111 01110000  01101110 01101111 01110000 01110001
10000000 00000000 00000000 00000000  00000000 00000000 00000000 00000000

00000000 00000000 00000000 00000000  00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000  00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000  00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000  00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000  00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000  00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000  00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000  00000000 00000000 00000001 11000000
```

## Hash intialized
```
h[0] = 6a09e667
h[1] = bb67ae85
h[2] = 3c6ef372
h[3] = a54ff53a
h[4] = 510e527f
h[5] = 9b05688c
h[6] = 1f83d9ab
h[7] = 5be0cd19

```

## Words (first block)
512-bit block of the binary, transformed into 64, 32-bit "words". The first 16 words are just 32-bit sections of the block, flipped to little endian. The rest are produced by running those first 16 through a fuction.
```
W[ 0] = 61626364    W[16] = eb8012ad    W[32] = a835e16a    W[48] = 0b706583
W[ 1] = 62636465    W[17] = a7c3ae92    W[33] = 1dff4429    W[49] = 179312ca
W[ 2] = 63646566    W[18] = 76e93ba2    W[34] = d6e15959    W[50] = 503054e9
W[ 3] = 64656667    W[19] = ba42e743    W[35] = c397cd6e    W[51] = ba125c39
W[ 4] = 65666768    W[20] = 92a92204    W[36] = 6f1801ca    W[52] = 7e9392c9
W[ 5] = 66676869    W[21] = d847e75e    W[37] = 21574205    W[53] = d5cbaa1e
W[ 6] = 6768696a    W[22] = 9e160036    W[38] = 35ff7a84    W[54] = 78e0585d
W[ 7] = 68696a6b    W[23] = b280a7cb    W[39] = 9743ee78    W[55] = f6e7611c
W[ 8] = 696a6b6c    W[24] = ddeb1516    W[40] = e44183e7    W[56] = 8ac830ce
W[ 9] = 6a6b6c6d    W[25] = f36586f4    W[41] = 0d09f00d    W[57] = 8b47a303
W[10] = 6b6c6d6e    W[26] = 969cd048    W[42] = 9c89af54    W[58] = fd6e627f
W[11] = 6c6d6e6f    W[27] = e959d99d    W[43] = 042d5bef    W[59] = 8c6e2c6a
W[12] = 6d6e6f70    W[28] = 6accc0ec    W[44] = 71f134d0    W[60] = 4001adf1
W[13] = 6e6f7071    W[29] = f54cb098    W[45] = 0f94f463    W[61] = 1a3dd097
W[14] = 80000000    W[30] = 2af1b2da    W[46] = 7e49dc63    W[62] = a9df6f62
W[15] = 00000000    W[31] = ee59c4c9    W[47] = 6f65c997    W[63] = 6aa60a39
```

## Compression function (first block)
Hex values for the working variables after each pass in the compression function:
```
        (a)         (b)         (c)         (d)         (e)         (f)         (g)         (h)
init) 6a09e667    bb67ae85    3c6ef372    a54ff53a    510e527f    9b05688c    1f83d9ab    5be0cd19
   0) 5d6aebb1    6a09e667    bb67ae85    3c6ef372    fa2a4606    510e527f    9b05688c    1f83d9ab
   1) 2f2d5fcf    5d6aebb1    6a09e667    bb67ae85    4eb1cfce    fa2a4606    510e527f    9b05688c
   2) 97651825    2f2d5fcf    5d6aebb1    6a09e667    62d5c49e    4eb1cfce    fa2a4606    510e527f
   3) 4a8d64d5    97651825    2f2d5fcf    5d6aebb1    6494841b    62d5c49e    4eb1cfce    fa2a4606
   4) f921c212    4a8d64d5    97651825    2f2d5fcf    05c4f88a    6494841b    62d5c49e    4eb1cfce
   5) 55c8ef48    f921c212    4a8d64d5    97651825    7ff91c94    05c4f88a    6494841b    62d5c49e
   6) 485835b7    55c8ef48    f921c212    4a8d64d5    39a5b2ca    7ff91c94    05c4f88a    6494841b
   7) d237e6db    485835b7    55c8ef48    f921c212    a401d211    39a5b2ca    7ff91c94    05c4f88a
   8) 359f2bce    d237e6db    485835b7    55c8ef48    c09ffec4    a401d211    39a5b2ca    7ff91c94
   9) 3a474b2b    359f2bce    d237e6db    485835b7    9037b3b8    c09ffec4    a401d211    39a5b2ca
  10) b8e2b4cb    3a474b2b    359f2bce    d237e6db    443ed29e    9037b3b8    c09ffec4    a401d211
  11) 1762215c    b8e2b4cb    3a474b2b    359f2bce    ee1c97a8    443ed29e    9037b3b8    c09ffec4
  12) 101a4861    1762215c    b8e2b4cb    3a474b2b    839a0fc9    ee1c97a8    443ed29e    9037b3b8
  13) d68e6457    101a4861    1762215c    b8e2b4cb    9243f8af    839a0fc9    ee1c97a8    443ed29e
  14) dd16cbb3    d68e6457    101a4861    1762215c    9162aded    9243f8af    839a0fc9    ee1c97a8
  15) c3486194    dd16cbb3    d68e6457    101a4861    1496a54f    9162aded    9243f8af    839a0fc9
  16) b9dcacb1    c3486194    dd16cbb3    d68e6457    d4f64250    1496a54f    9162aded    9243f8af
  17) 046a193e    b9dcacb1    c3486194    dd16cbb3    885370b6    d4f64250    1496a54f    9162aded
  18) f402f058    046a193e    b9dcacb1    c3486194    6f433549    885370b6    d4f64250    1496a54f
  19) 2139187b    f402f058    046a193e    b9dcacb1    7c304206    6f433549    885370b6    d4f64250
  20) d70ac17d    2139187b    f402f058    046a193e    7cc6b262    7c304206    6f433549    885370b6
  21) 1b2b66b8    d70ac17d    2139187b    f402f058    d560b028    7cc6b262    7c304206    6f433549
  22) ae2e2d4f    1b2b66b8    d70ac17d    2139187b    f074fc95    d560b028    7cc6b262    7c304206
  23) 59fce6b9    ae2e2d4f    1b2b66b8    d70ac17d    a2c7d51d    f074fc95    d560b028    7cc6b262
  24) 4a885065    59fce6b9    ae2e2d4f    1b2b66b8    763597fb    a2c7d51d    f074fc95    d560b028
  25) 573221da    4a885065    59fce6b9    ae2e2d4f    36e74eb4    763597fb    a2c7d51d    f074fc95
  26) 128661da    573221da    4a885065    59fce6b9    1162d575    36e74eb4    763597fb    a2c7d51d
  27) 73f858af    128661da    573221da    4a885065    e77c797f    1162d575    36e74eb4    763597fb
  28) 74bcf468    73f858af    128661da    573221da    72abaecd    e77c797f    1162d575    36e74eb4
  29) df7151a0    74bcf468    73f858af    128661da    7629c961    72abaecd    e77c797f    1162d575
  30) eb43f3ed    df7151a0    74bcf468    73f858af    0635d880    7629c961    72abaecd    e77c797f
  31) 5581ab07    eb43f3ed    df7151a0    74bcf468    df980085    0635d880    7629c961    72abaecd
  32) 9fc905c8    5581ab07    eb43f3ed    df7151a0    a94d2af1    df980085    0635d880    7629c961
  33) 9ce5a62f    9fc905c8    5581ab07    eb43f3ed    6ef3b6bd    a94d2af1    df980085    0635d880
  34) 1df8e885    9ce5a62f    9fc905c8    5581ab07    2a9e048e    6ef3b6bd    a94d2af1    df980085
  35) 0786dce8    1df8e885    9ce5a62f    9fc905c8    de2a21d1    2a9e048e    6ef3b6bd    a94d2af1
  36) 2c55d3a6    0786dce8    1df8e885    9ce5a62f    b067c1af    de2a21d1    2a9e048e    6ef3b6bd
  37) a985b4be    2c55d3a6    0786dce8    1df8e885    f72bf353    b067c1af    de2a21d1    2a9e048e
  38) 91ac9d5d    a985b4be    2c55d3a6    0786dce8    68d8d590    f72bf353    b067c1af    de2a21d1
  39) 7e4d30b8    91ac9d5d    a985b4be    2c55d3a6    9f5b9b6d    68d8d590    f72bf353    b067c1af
  40) 7e056794    7e4d30b8    91ac9d5d    a985b4be    423b26c0    9f5b9b6d    68d8d590    f72bf353
  41) 508a16ab    7e056794    7e4d30b8    91ac9d5d    45459d97    423b26c0    9f5b9b6d    68d8d590
  42) b62c7013    508a16ab    7e056794    7e4d30b8    80a92a00    45459d97    423b26c0    9f5b9b6d
  43) 167361de    b62c7013    508a16ab    7e056794    41dd3844    80a92a00    45459d97    423b26c0
  44) de71e2f2    167361de    b62c7013    508a16ab    ff61c636    41dd3844    80a92a00    45459d97
  45) 18f0d19d    de71e2f2    167361de    b62c7013    6b88472c    ff61c636    41dd3844    80a92a00
  46) 165be9cd    18f0d19d    de71e2f2    167361de    a483f080    6b88472c    ff61c636    41dd3844
  47) 13d82741    165be9cd    18f0d19d    de71e2f2    a7802a4d    a483f080    6b88472c    ff61c636
  48) 017b9d99    13d82741    165be9cd    18f0d19d    aeb10b60    a7802a4d    a483f080    6b88472c
  49) 543c99a1    017b9d99    13d82741    165be9cd    16f134b6    aeb10b60    a7802a4d    a483f080
  50) 758ca97a    543c99a1    017b9d99    13d82741    100cf2ea    16f134b6    aeb10b60    a7802a4d
  51) 81c1cde0    758ca97a    543c99a1    017b9d99    5c47eb7b    100cf2ea    16f134b6    aeb10b60
  52) b8d55619    81c1cde0    758ca97a    543c99a1    1c806a61    5c47eb7b    100cf2ea    16f134b6
  53) 1d6de87a    b8d55619    81c1cde0    758ca97a    3443bed4    1c806a61    5c47eb7b    100cf2ea
  54) f907b313    1d6de87a    b8d55619    81c1cde0    61a41711    3443bed4    1c806a61    5c47eb7b
  55) 9e57c4a0    f907b313    1d6de87a    b8d55619    eec13548    61a41711    3443bed4    1c806a61
  56) 71629856    9e57c4a0    f907b313    1d6de87a    2f6c8c4e    eec13548    61a41711    3443bed4
  57) 7c015a2c    71629856    9e57c4a0    f907b313    cb9d3dd0    2f6c8c4e    eec13548    61a41711
  58) 921fccb6    7c015a2c    71629856    9e57c4a0    43d8a034    cb9d3dd0    2f6c8c4e    eec13548
  59) e18f259a    921fccb6    7c015a2c    71629856    51e15869    43d8a034    cb9d3dd0    2f6c8c4e
  60) bcfce922    e18f259a    921fccb6    7c015a2c    962d8621    51e15869    43d8a034    cb9d3dd0
  61) f6f443f8    bcfce922    e18f259a    921fccb6    acc75916    962d8621    51e15869    43d8a034
  62) 86126910    f6f443f8    bcfce922    e18f259a    2fc08f85    acc75916    962d8621    51e15869
  63) 1bdc6f6f    86126910    f6f443f8    bcfce922    25d2430a    2fc08f85    acc75916    962d8621
```

Add those values back to the hash:
```
H[0] + a = 6a09e667 + 1bdc6f6f = 85e655d6
H[1] + b = bb67ae85 + 86126910 = 417a1795
H[2] + c = 3c6ef372 + f6f443f8 = 3363376a
H[3] + d = a54ff53a + bcfce922 = 624cde5c
H[4] + e = 510e527f + 25d2430a = 76e09589
H[5] + f = 9b05688c + 2fc08f85 = cac5f811
H[6] + g = 1f83d9ab + acc75916 = cc4b32c1
H[7] + h = 5be0cd19 + 962d8621 = f20e533a
```

## Words (second block)
The next 512-bit block of the binary, transformed into 64, 32-bit "words":
```
W[ 0] = 00000000    W[16] = 00000000    W[32] = 5df4b0c4    W[48] = 2b658dbd
W[ 1] = 00000000    W[17] = 00d80000    W[33] = e257036a    W[49] = e290f793
W[ 2] = 00000000    W[18] = 00000000    W[34] = c97bb6f1    W[50] = 9eebb24c
W[ 3] = 00000000    W[19] = 00003677    W[35] = c5b46f4d    W[51] = 9713b5de
W[ 4] = 00000000    W[20] = 00000000    W[36] = f8253c4e    W[52] = 41061ab7
W[ 5] = 00000000    W[21] = 1df5600d    W[37] = a558d189    W[53] = e022e23b
W[ 6] = 00000000    W[22] = 000001c0    W[38] = 78696285    W[54] = 0772079e
W[ 7] = 00000000    W[23] = 1c00501c    W[39] = ed07117f    W[55] = 7de22d9c
W[ 8] = 00000000    W[24] = 01b00000    W[40] = 107358f6    W[56] = c8b83778
W[ 9] = 00000000    W[25] = 220a8d94    W[41] = 390ae496    W[57] = 75a79849
W[10] = 00000000    W[26] = 0000a365    W[42] = 565010a2    W[58] = d93dbddb
W[11] = 00000000    W[27] = 177017e7    W[43] = c51d7d44    W[59] = 0a036c9d
W[12] = 00000000    W[28] = 63d38035    W[44] = 9e74c972    W[60] = cb4f6ac6
W[13] = 00000000    W[29] = 090ab713    W[45] = 6614b561    W[61] = 823f97e2
W[14] = 00000000    W[30] = 4c7539ca    W[46] = 30fc129d    W[62] = ea2f2a7a
W[15] = 000001c0    W[31] = 0f19a8c9    W[47] = 9ac684a8    W[63] = b9018b52
```

## Compression function (second block)
Hex values for the working variables after each pass in the compression function:
```
        (a)         (b)         (c)         (d)         (e)         (f)         (g)         (h)
init) 85e655d6    417a1795    3363376a    624cde5c    76e09589    cac5f811    cc4b32c1    f20e533a
   0) 7c20c838    85e655d6    417a1795    3363376a    4670ae6e    76e09589    cac5f811    cc4b32c1
   1) 7c3c0f86    7c20c838    85e655d6    417a1795    8c51be64    4670ae6e    76e09589    cac5f811
   2) fd1eebdc    7c3c0f86    7c20c838    85e655d6    af71b9ea    8c51be64    4670ae6e    76e09589
   3) f268faa9    fd1eebdc    7c3c0f86    7c20c838    e20362ef    af71b9ea    8c51be64    4670ae6e
   4) 185a5d79    f268faa9    fd1eebdc    7c3c0f86    8dff3001    e20362ef    af71b9ea    8c51be64
   5) 3eeb6c06    185a5d79    f268faa9    fd1eebdc    fe20cda6    8dff3001    e20362ef    af71b9ea
   6) 89bba3f1    3eeb6c06    185a5d79    f268faa9    0a34df03    fe20cda6    8dff3001    e20362ef
   7) bf9a93a0    89bba3f1    3eeb6c06    185a5d79    059abdd1    0a34df03    fe20cda6    8dff3001
   8) 2c096744    bf9a93a0    89bba3f1    3eeb6c06    abfa465b    059abdd1    0a34df03    fe20cda6
   9) 2d964e86    2c096744    bf9a93a0    89bba3f1    aa27ed82    abfa465b    059abdd1    0a34df03
  10) 5b35025b    2d964e86    2c096744    bf9a93a0    10e77723    aa27ed82    abfa465b    059abdd1
  11) 5eb4ec40    5b35025b    2d964e86    2c096744    e11b4548    10e77723    aa27ed82    abfa465b
  12) 35ee996d    5eb4ec40    5b35025b    2d964e86    5c24e2a2    e11b4548    10e77723    aa27ed82
  13) d74080fa    35ee996d    5eb4ec40    5b35025b    68aa893f    5c24e2a2    e11b4548    10e77723
  14) 0cea5cbc    d74080fa    35ee996d    5eb4ec40    60356548    68aa893f    5c24e2a2    e11b4548
  15) 16a8cc79    0cea5cbc    d74080fa    35ee996d    0fcb1f6f    60356548    68aa893f    5c24e2a2
  16) f16f634e    16a8cc79    0cea5cbc    d74080fa    8b21cdc1    0fcb1f6f    60356548    68aa893f
  17) 23dcb6c2    f16f634e    16a8cc79    0cea5cbc    ca9182d3    8b21cdc1    0fcb1f6f    60356548
  18) dcff40fd    23dcb6c2    f16f634e    16a8cc79    69bf7b95    ca9182d3    8b21cdc1    0fcb1f6f
  19) 76f1a2bc    dcff40fd    23dcb6c2    f16f634e    0dc84bb1    69bf7b95    ca9182d3    8b21cdc1
  20) 20aad899    76f1a2bc    dcff40fd    23dcb6c2    cc4769f2    0dc84bb1    69bf7b95    ca9182d3
  21) d44dc81a    20aad899    76f1a2bc    dcff40fd    5bace62d    cc4769f2    0dc84bb1    69bf7b95
  22) f13ae55b    d44dc81a    20aad899    76f1a2bc    966aa287    5bace62d    cc4769f2    0dc84bb1
  23) a4195b91    f13ae55b    d44dc81a    20aad899    eddbd6ed    966aa287    5bace62d    cc4769f2
  24) 4984fa79    a4195b91    f13ae55b    d44dc81a    a530d939    eddbd6ed    966aa287    5bace62d
  25) aa6cb982    4984fa79    a4195b91    f13ae55b    0b5eeea4    a530d939    eddbd6ed    966aa287
  26) 9450fbbc    aa6cb982    4984fa79    a4195b91    09166dda    0b5eeea4    a530d939    eddbd6ed
  27) 0d936bab    9450fbbc    aa6cb982    4984fa79    6e495d4b    09166dda    0b5eeea4    a530d939
  28) d958b529    0d936bab    9450fbbc    aa6cb982    c2fa99b1    6e495d4b    09166dda    0b5eeea4
  29) 1cfa5eb0    d958b529    0d936bab    9450fbbc    6c49db9f    c2fa99b1    6e495d4b    09166dda
  30) 02ef3a5f    1cfa5eb0    d958b529    0d936bab    5da10665    6c49db9f    c2fa99b1    6e495d4b
  31) b0eab1c5    02ef3a5f    1cfa5eb0    d958b529    f6d93952    5da10665    6c49db9f    c2fa99b1
  32) 0bfba73c    b0eab1c5    02ef3a5f    1cfa5eb0    8b99e3a9    f6d93952    5da10665    6c49db9f
  33) 4bd1df96    0bfba73c    b0eab1c5    02ef3a5f    905e44ac    8b99e3a9    f6d93952    5da10665
  34) 9907f1b6    4bd1df96    0bfba73c    b0eab1c5    66c3043d    905e44ac    8b99e3a9    f6d93952
  35) ecde4e0d    9907f1b6    4bd1df96    0bfba73c    5dc119e6    66c3043d    905e44ac    8b99e3a9
  36) 2f11c939    ecde4e0d    9907f1b6    4bd1df96    fed4ce1d    5dc119e6    66c3043d    905e44ac
  37) d949682b    2f11c939    ecde4e0d    9907f1b6    32d99008    fed4ce1d    5dc119e6    66c3043d
  38) adca7a96    d949682b    2f11c939    ecde4e0d    c6cce4ff    32d99008    fed4ce1d    5dc119e6
  39) 221b8a5a    adca7a96    d949682b    2f11c939    0b82c5eb    c6cce4ff    32d99008    fed4ce1d
  40) 12d97845    221b8a5a    adca7a96    d949682b    e4213ca2    0b82c5eb    c6cce4ff    32d99008
  41) 2c794876    12d97845    221b8a5a    adca7a96    ff6759ba    e4213ca2    0b82c5eb    c6cce4ff
  42) 8300fca2    2c794876    12d97845    221b8a5a    e0e3457c    ff6759ba    e4213ca2    0b82c5eb
  43) f2ad6322    8300fca2    2c794876    12d97845    cc48c7f3    e0e3457c    ff6759ba    e4213ca2
  44) 0f154e11    f2ad6322    8300fca2    2c794876    6f9517cb    cc48c7f3    e0e3457c    ff6759ba
  45) 104a7db4    0f154e11    f2ad6322    8300fca2    5348e8f6    6f9517cb    cc48c7f3    e0e3457c
  46) 0b3303a7    104a7db4    0f154e11    f2ad6322    bbe1c39a    5348e8f6    6f9517cb    cc48c7f3
  47) d7354d5b    0b3303a7    104a7db4    0f154e11    aad55b6b    bbe1c39a    5348e8f6    6f9517cb
  48) b736d7a6    d7354d5b    0b3303a7    104a7db4    68f25260    aad55b6b    bbe1c39a    5348e8f6
  49) 2748e5ec    b736d7a6    d7354d5b    0b3303a7    d4b58576    68f25260    aad55b6b    bbe1c39a
  50) d8aabcf9    2748e5ec    b736d7a6    d7354d5b    27844711    d4b58576    68f25260    aad55b6b
  51) 1a6bcf6a    d8aabcf9    2748e5ec    b736d7a6    ff5e99d0    27844711    d4b58576    68f25260
  52) 4eca6fa0    1a6bcf6a    d8aabcf9    2748e5ec    989ed071    ff5e99d0    27844711    d4b58576
  53) ec02560a    4eca6fa0    1a6bcf6a    d8aabcf9    7151df8e    989ed071    ff5e99d0    27844711
  54) d9f0c115    ec02560a    4eca6fa0    1a6bcf6a    624150c4    7151df8e    989ed071    ff5e99d0
  55) 92952710    d9f0c115    ec02560a    4eca6fa0    226806d6    624150c4    7151df8e    989ed071
  56) 20d4d0e4    92952710    d9f0c115    ec02560a    4e515a4d    226806d6    624150c4    7151df8e
  57) 4348eb1f    20d4d0e4    92952710    d9f0c115    c21eddf9    4e515a4d    226806d6    624150c4
  58) 286fe5f0    4348eb1f    20d4d0e4    92952710    54076664    c21eddf9    4e515a4d    226806d6
  59) 1c4cddd9    286fe5f0    4348eb1f    20d4d0e4    f487a853    54076664    c21eddf9    4e515a4d
  60) a9f181dd    1c4cddd9    286fe5f0    4348eb1f    27ccb387    f487a853    54076664    c21eddf9
  61) b25cef29    a9f181dd    1c4cddd9    286fe5f0    2aa1bb13    27ccb387    f487a853    54076664
  62) 908c2123    b25cef29    a9f181dd    1c4cddd9    9a392956    2aa1bb13    27ccb387    f487a853
  63) 9ea7148b    908c2123    b25cef29    a9f181dd    2c5c4ed0    9a392956    2aa1bb13    27ccb387
```

Add those values back to the hash:
```
H[0] + a = 85e655d6 + 9ea7148b = 248d6a61
H[1] + b = 417a1795 + 908c2123 = d20638b8
H[2] + c = 3363376a + b25cef29 = e5c02693
H[3] + d = 624cde5c + a9f181dd = 0c3e6039
H[4] + e = 76e09589 + 2c5c4ed0 = a33ce459
H[5] + f = cac5f811 + 9a392956 = 64ff2167
H[6] + g = cc4b32c1 + 2aa1bb13 = f6ecedd4
H[7] + h = f20e533a + 27ccb387 = 19db06c1
```

The padded binary is 2 blocks long. This is the end.

## Final hash
```
248d6a61 d20638b8 e5c02693 0c3e6039 a33ce459 64ff2167 f6ecedd4 19db06c1
```
