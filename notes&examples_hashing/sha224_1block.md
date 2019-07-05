**message:**<br>`"abc"`

## Padded message
Message transformed into padded binary<br>(message + 1 + 0s + message bits len in *big* endian)
```
01100001 01100010 01100011 10000000  00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000  00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000  00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000  00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000  00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000  00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000  00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000  00000000 00000000 00000000 00011000
```

## Hash intialized
```
H[0] = c1059ed8
H[1] = 367cd507
H[2] = 3070dd17
H[3] = f70e5939
H[4] = ffc00b31
H[5] = 68581511
H[6] = 64f98fa7
H[7] = befa4fa4
```

## Words (first block)
512-bit block of the binary, transformed into 64, 32-bit "words". The first 16 words are just 32-bit sections of the block, flipped to little endian. The rest are produced by running those first 16 through a fuction.
```
W[ 0] = 61626380    W[16] = 61626380    W[32] = 93f5997f    W[48] = fb3e89cb
W[ 1] = 00000000    W[17] = 000f0000    W[33] = 3b68ba73    W[49] = cc7617db
W[ 2] = 00000000    W[18] = 7da86405    W[34] = aff4ffc1    W[50] = b9e66c34
W[ 3] = 00000000    W[19] = 600003c6    W[35] = f10a5c62    W[51] = a9993667
W[ 4] = 00000000    W[20] = 3e9d7b78    W[36] = 0a8b3996    W[52] = 84badedd
W[ 5] = 00000000    W[21] = 0183fc00    W[37] = 72af830a    W[53] = c21462bc
W[ 6] = 00000000    W[22] = 12dcbfdb    W[38] = 9409e33e    W[54] = 1487472c
W[ 7] = 00000000    W[23] = e2e2c38e    W[39] = 24641522    W[55] = b20f7a99
W[ 8] = 00000000    W[24] = c8215c1a    W[40] = 9f47bf94    W[56] = ef57b9cd
W[ 9] = 00000000    W[25] = b73679a2    W[41] = f0a64f5a    W[57] = ebe6b238
W[10] = 00000000    W[26] = e5bc3909    W[42] = 3e246a79    W[58] = 9fe3095e
W[11] = 00000000    W[27] = 32663c5b    W[43] = 27333ba3    W[59] = 78bc8d4b
W[12] = 00000000    W[28] = 9d209d67    W[44] = 0c4763f2    W[60] = a43fcf15
W[13] = 00000000    W[29] = ec8726cb    W[45] = 840abf27    W[61] = 668b2ff8
W[14] = 00000000    W[30] = 702138a4    W[46] = 7a290d5d    W[62] = eeaba2cc
W[15] = 00000018    W[31] = d3b7973b    W[47] = 065c43da    W[63] = 12b1edeb
```

## Compression function (first block)
Hex values for the working variables after each pass in the compression function:
```
        (a)         (b)         (c)         (d)         (e)         (f)         (g)         (h)
init) c1059ed8    367cd507    3070dd17    f70e5939    ffc00b31    68581511    64f98fa7    befa4fa4
   0) 0e96b2da    c1059ed8    367cd507    3070dd17    0434225e    ffc00b31    68581511    64f98fa7
   1) c20dab6b    0e96b2da    c1059ed8    367cd507    9cab416f    0434225e    ffc00b31    68581511
   2) ab113b7a    c20dab6b    0e96b2da    c1059ed8    82177fe8    9cab416f    0434225e    ffc00b31
   3) 8253cc1a    ab113b7a    c20dab6b    0e96b2da    8346b27d    82177fe8    9cab416f    0434225e
   4) 08a0dc0c    8253cc1a    ab113b7a    c20dab6b    05b557db    8346b27d    82177fe8    9cab416f
   5) b2ca3a91    08a0dc0c    8253cc1a    ab113b7a    898dc7bb    05b557db    8346b27d    82177fe8
   6) 0b6b9023    b2ca3a91    08a0dc0c    8253cc1a    a2e49147    898dc7bb    05b557db    8346b27d
   7) f09d116d    0b6b9023    b2ca3a91    08a0dc0c    7a84120d    a2e49147    898dc7bb    05b557db
   8) ed6fa633    f09d116d    0b6b9023    b2ca3a91    c037faad    7a84120d    a2e49147    898dc7bb
   9) 55e6a367    ed6fa633    f09d116d    0b6b9023    aae50091    c037faad    7a84120d    a2e49147
  10) 0817e82b    55e6a367    ed6fa633    f09d116d    c8c53a2c    aae50091    c037faad    7a84120d
  11) 17142334    0817e82b    55e6a367    ed6fa633    dd4c7be9    c8c53a2c    aae50091    c037faad
  12) fc4f023e    17142334    0817e82b    55e6a367    87bea51a    dd4c7be9    c8c53a2c    aae50091
  13) be316902    fc4f023e    17142334    0817e82b    65141125    87bea51a    dd4c7be9    c8c53a2c
  14) 1d80d178    be316902    fc4f023e    17142334    4545f53a    65141125    87bea51a    dd4c7be9
  15) 9f341a45    1d80d178    be316902    fc4f023e    6a61c411    4545f53a    65141125    87bea51a
  16) 0f324db9    9f341a45    1d80d178    be316902    06c80d6a    6a61c411    4545f53a    65141125
  17) ffe7012b    0f324db9    9f341a45    1d80d178    b7b601f4    06c80d6a    6a61c411    4545f53a
  18) 62932ab8    ffe7012b    0f324db9    9f341a45    763b627a    b7b601f4    06c80d6a    6a61c411
  19) 5207d867    62932ab8    ffe7012b    0f324db9    7fbba936    763b627a    b7b601f4    06c80d6a
  20) 07d55ccb    5207d867    62932ab8    ffe7012b    9ba5a6ea    7fbba936    763b627a    b7b601f4
  21) dece98a4    07d55ccb    5207d867    62932ab8    293ffb5d    9ba5a6ea    7fbba936    763b627a
  22) e62a812e    dece98a4    07d55ccb    5207d867    28fe0fd9    293ffb5d    9ba5a6ea    7fbba936
  23) 57206fb8    e62a812e    dece98a4    07d55ccb    c76084ea    28fe0fd9    293ffb5d    9ba5a6ea
  24) 6a6abcf0    57206fb8    e62a812e    dece98a4    b2614c5e    c76084ea    28fe0fd9    293ffb5d
  25) 937514f0    6a6abcf0    57206fb8    e62a812e    b42ec21c    b2614c5e    c76084ea    28fe0fd9
  26) 82af3ffb    937514f0    6a6abcf0    57206fb8    be6f6760    b42ec21c    b2614c5e    c76084ea
  27) eca3bcd5    82af3ffb    937514f0    6a6abcf0    1dccbb10    be6f6760    b42ec21c    b2614c5e
  28) 2d1576c4    eca3bcd5    82af3ffb    937514f0    01641929    1dccbb10    be6f6760    b42ec21c
  29) fe3c8658    2d1576c4    eca3bcd5    82af3ffb    fc4b36c5    01641929    1dccbb10    be6f6760
  30) 0d7cce07    fe3c8658    2d1576c4    eca3bcd5    a4a4a3a4    fc4b36c5    01641929    1dccbb10
  31) cce1951d    0d7cce07    fe3c8658    2d1576c4    4be9475c    a4a4a3a4    fc4b36c5    01641929
  32) 09b76257    cce1951d    0d7cce07    fe3c8658    0ccddd86    4be9475c    a4a4a3a4    fc4b36c5
  33) f827767e    09b76257    cce1951d    0d7cce07    db116db7    0ccddd86    4be9475c    a4a4a3a4
  34) e4a0bb48    f827767e    09b76257    cce1951d    994e2bac    db116db7    0ccddd86    4be9475c
  35) d8bb1041    e4a0bb48    f827767e    09b76257    5b730abb    994e2bac    db116db7    0ccddd86
  36) 2a2e32f4    d8bb1041    e4a0bb48    f827767e    22e15c59    5b730abb    994e2bac    db116db7
  37) 0d275ca8    2a2e32f4    d8bb1041    e4a0bb48    f6c39382    22e15c59    5b730abb    994e2bac
  38) 7902369c    0d275ca8    2a2e32f4    d8bb1041    d9f8c2e0    f6c39382    22e15c59    5b730abb
  39) f3c80288    7902369c    0d275ca8    2a2e32f4    00e3a7bb    d9f8c2e0    f6c39382    22e15c59
  40) 483bba4d    f3c80288    7902369c    0d275ca8    f0a8198c    00e3a7bb    d9f8c2e0    f6c39382
  41) d75d4d26    483bba4d    f3c80288    7902369c    fcecdcd4    f0a8198c    00e3a7bb    d9f8c2e0
  42) 0744b618    d75d4d26    483bba4d    f3c80288    03186faa    fcecdcd4    f0a8198c    00e3a7bb
  43) 9cce9f01    0744b618    d75d4d26    483bba4d    a56f6bbf    03186faa    fcecdcd4    f0a8198c
  44) a3701bd9    9cce9f01    0744b618    d75d4d26    af1bef5f    a56f6bbf    03186faa    fcecdcd4
  45) 131d4c09    a3701bd9    9cce9f01    0744b618    ecb77e1b    af1bef5f    a56f6bbf    03186faa
  46) fb3777d9    131d4c09    a3701bd9    9cce9f01    1d601f44    ecb77e1b    af1bef5f    a56f6bbf
  47) 847ea00e    fb3777d9    131d4c09    a3701bd9    503a7b95    1d601f44    ecb77e1b    af1bef5f
  48) aaa69347    847ea00e    fb3777d9    131d4c09    5eeb9930    503a7b95    1d601f44    ecb77e1b
  49) 505caf28    aaa69347    847ea00e    fb3777d9    ce695893    5eeb9930    503a7b95    1d601f44
  50) 675e0b02    505caf28    aaa69347    847ea00e    c22dd75f    ce695893    5eeb9930    503a7b95
  51) abd26099    675e0b02    505caf28    aaa69347    1409c3f8    c22dd75f    ce695893    5eeb9930
  52) 0df9857a    abd26099    675e0b02    505caf28    2d864d9f    1409c3f8    c22dd75f    ce695893
  53) 308b8799    0df9857a    abd26099    675e0b02    02524f02    2d864d9f    1409c3f8    c22dd75f
  54) 909cc059    308b8799    0df9857a    abd26099    6f2a444a    02524f02    2d864d9f    1409c3f8
  55) 8d25bd94    909cc059    308b8799    0df9857a    1273c622    6f2a444a    02524f02    2d864d9f
  56) f32141da    8d25bd94    909cc059    308b8799    1771ed3f    1273c622    6f2a444a    02524f02
  57) 8ce24395    f32141da    8d25bd94    909cc059    f52f66a6    1771ed3f    1273c622    6f2a444a
  58) 07bcd846    8ce24395    f32141da    8d25bd94    149db547    f52f66a6    1771ed3f    1273c622
  59) 622d5e5b    07bcd846    8ce24395    f32141da    b6f4c630    149db547    f52f66a6    1771ed3f
  60) c693fc7a    622d5e5b    07bcd846    8ce24395    13dfb889    b6f4c630    149db547    f52f66a6
  61) 55d1c760    c693fc7a    622d5e5b    07bcd846    7e730e00    13dfb889    b6f4c630    149db547
  62) fd89031b    55d1c760    c693fc7a    622d5e5b    55489ee6    7e730e00    13dfb889    b6f4c630
  63) 6203de4a    fd89031b    55d1c760    c693fc7a    2aedb1b3    55489ee6    7e730e00    13dfb889
```

Add those values back to the hash:
```
H[0] + a = c1059ed8 + 6203de4a = 23097d22
H[1] + b = 367cd507 + fd89031b = 3405d822
H[2] + c = 3070dd17 + 55d1c760 = 8642a477
H[3] + d = f70e5939 + c693fc7a = bda255b3
H[4] + e = ffc00b31 + 2aedb1b3 = 2aadbce4
H[5] + f = 68581511 + 55489ee6 = bda0b3f7
H[6] + g = 64f98fa7 + 7e730e00 = e36c9da7
H[7] + h = befa4fa4 + 13dfb889 = d2da082d
```

Since there is only 1 block, this is the end.

## Cut down to 224 bits
Discard the final 32-bit chunk of the hash:
```
256 bits:  23097d22   3405d822   8642a477   bda255b3   2aadbce4   bda0b3f7   e36c9da7   d2da082d
224 bits:  23097d22   3405d822   8642a477   bda255b3   2aadbce4   bda0b3f7   e36c9da7
```

## Final hash
```
23097d22 3405d822 8642a477 bda255b3 2aadbce4 bda0b3f7 e36c9da7
```
