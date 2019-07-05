message: `"abc"`

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
h[0] = 67452301
h[1] = efcdab89
h[2] = 98badcfe
h[3] = 10325476
h[4] = c3d2e1f0
```

## Words (first block)
512-bit block of the binary, transformed into 80, 32-bit "words". The first 16 words are just 32-bit sections of the block, flipped to little endian. The rest are produced by running those first 16 through a fuction.
```
W[ 0] = 61626380    W[16] = c2c4c700    W[32] = 8e9a9202    W[48] = da9415ed    W[64] = 7cd45c9d
W[ 1] = 00000000    W[17] = 00000000    W[33] = 00000600    W[49] = 26380a16    W[65] = 000f0000
W[ 2] = 00000000    W[18] = 00000030    W[34] = b131c0f0    W[50] = 626383a1    W[66] = fb50753a
W[ 3] = 00000000    W[19] = 85898e01    W[35] = 16263bc6    W[51] = 4ebf54de    W[67] = ec6765e8
W[ 4] = 00000000    W[20] = 00000000    W[36] = 4ebed41e    W[52] = 3835b44b    W[68] = ba3c2be2
W[ 5] = 00000000    W[21] = 00000060    W[37] = 626380a1    W[53] = 0000f600    W[69] = 0060c000
W[ 6] = 00000000    W[22] = 0b131c03    W[38] = 16263806    W[54] = 1e84c7a3    W[70] = 3a37cd05
W[ 7] = 00000000    W[23] = 00000030    W[39] = 000018c0    W[55] = 98e04d98    W[71] = 458546f4
W[ 8] = 00000000    W[24] = 85898ec1    W[40] = d2e138c4    W[56] = 651d16a0    W[72] = b8599dd6
W[ 9] = 00000000    W[25] = 16263806    W[41] = 00000f00    W[57] = 62658ca1    W[73] = 380a1a26
W[10] = 00000000    W[26] = 00000000    W[42] = 3afb5079    W[58] = 458544d6    W[74] = 01e02203
W[11] = 00000000    W[27] = 00000180    W[43] = 898e04e5    W[59] = 44584cb7    W[75] = e7cc3456
W[12] = 00000000    W[28] = 2c4c700c    W[44] = e2ba3c2b    W[60] = 7ba06619    W[76] = e6e60b69
W[13] = 00000000    W[29] = 000000f0    W[45] = 000060c0    W[61] = 6380aea2    W[77] = 00f60a00
W[14] = 00000000    W[30] = 93afb507    W[46] = 053a37cd    W[62] = 0ae55269    W[78] = 5795ef4f
W[15] = 00000018    W[31] = 5898e048    W[47] = 74458547    W[63] = 627b49a1    W[79] = 822e0879
```

## Compression function (first block)
Hex values for a b c d after each pass in the compression function:
```
        (a)         (b)         (c)         (d)         (e)  
init) 67452301    efcdab89    98badcfe    10325476    c3d2e1f0
   0) 0116fc33    67452301    7bf36ae2    98badcfe    10325476
   1) 8990536d    0116fc33    59d148c0    7bf36ae2    98badcfe
   2) a1390f08    8990536d    c045bf0c    59d148c0    7bf36ae2
   3) cdd8e11b    a1390f08    626414db    c045bf0c    59d148c0
   4) cfd499de    cdd8e11b    284e43c2    626414db    c045bf0c
   5) 3fc7ca40    cfd499de    f3763846    284e43c2    626414db
   6) 993e30c1    3fc7ca40    b3f52677    f3763846    284e43c2
   7) 9e8c07d4    993e30c1    0ff1f290    b3f52677    f3763846
   8) 4b6ae328    9e8c07d4    664f8c30    0ff1f290    b3f52677
   9) 8351f929    4b6ae328    27a301f5    664f8c30    0ff1f290
  10) fbda9e89    8351f929    12dab8ca    27a301f5    664f8c30
  11) 63188fe4    fbda9e89    60d47e4a    12dab8ca    27a301f5
  12) 4607b664    63188fe4    7ef6a7a2    60d47e4a    12dab8ca
  13) 9128f695    4607b664    18c623f9    7ef6a7a2    60d47e4a
  14) 196bee77    9128f695    1181ed99    18c623f9    7ef6a7a2
  15) 20bdd62f    196bee77    644a3da5    1181ed99    18c623f9
  16) 4e925823    20bdd62f    c65afb9d    644a3da5    1181ed99
  17) 82aa6728    4e925823    c82f758b    c65afb9d    644a3da5
  18) dc64901d    82aa6728    d3a49608    c82f758b    c65afb9d
  19) fd9e1d7d    dc64901d    20aa99ca    d3a49608    c82f758b
  20) 1a37b0ca    fd9e1d7d    77192407    20aa99ca    d3a49608
  21) 33a23bfc    1a37b0ca    7f67875f    77192407    20aa99ca
  22) 21283486    33a23bfc    868dec32    7f67875f    77192407
  23) d541f12d    21283486    0ce88eff    868dec32    7f67875f
  24) c7567dc6    d541f12d    884a0d21    0ce88eff    868dec32
  25) 48413ba4    c7567dc6    75507c4b    884a0d21    0ce88eff
  26) be35fbd5    48413ba4    b1d59f71    75507c4b    884a0d21
  27) 4aa84d97    be35fbd5    12104ee9    b1d59f71    75507c4b
  28) 8370b52e    4aa84d97    6f8d7ef5    12104ee9    b1d59f71
  29) c5fbaf5d    8370b52e    d2aa1365    6f8d7ef5    12104ee9
  30) 1267b407    c5fbaf5d    a0dc2d4b    d2aa1365    6f8d7ef5
  31) 3b845d33    1267b407    717eebd7    a0dc2d4b    d2aa1365
  32) 046faa0a    3b845d33    c499ed01    717eebd7    a0dc2d4b
  33) 2c0ebc11    046faa0a    cee1174c    c499ed01    717eebd7
  34) 21796ad4    2c0ebc11    811bea82    cee1174c    c499ed01
  35) dcbbb0cb    21796ad4    4b03af04    811bea82    cee1174c
  36) 0f511fd8    dcbbb0cb    085e5ab5    4b03af04    811bea82
  37) dc63973f    0f511fd8    f72eec32    085e5ab5    4b03af04
  38) 4c986405    dc63973f    03d447f6    f72eec32    085e5ab5
  39) 32de1cba    4c986405    f718e5cf    03d447f6    f72eec32
  40) fc87dedf    32de1cba    53261901    f718e5cf    03d447f6
  41) 970a0d5c    fc87dedf    8cb7872e    53261901    f718e5cf
  42) 7f193dc5    970a0d5c    ff21f7b7    8cb7872e    53261901
  43) ee1b1aaf    7f193dc5    25c28357    ff21f7b7    8cb7872e
  44) 40f28e09    ee1b1aaf    5fc64f71    25c28357    ff21f7b7
  45) 1c51e1f2    40f28e09    fb86c6ab    5fc64f71    25c28357
  46) a01b846c    1c51e1f2    503ca382    fb86c6ab    5fc64f71
  47) bead02ca    a01b846c    8714787c    503ca382    fb86c6ab
  48) baf39337    bead02ca    2806e11b    8714787c    503ca382
  49) 120731c5    baf39337    afab40b2    2806e11b    8714787c
  50) 641db2ce    120731c5    eebce4cd    afab40b2    2806e11b
  51) 3847ad66    641db2ce    4481cc71    eebce4cd    afab40b2
  52) e490436d    3847ad66    99076cb3    4481cc71    eebce4cd
  53) 27e9f1d8    e490436d    8e11eb59    99076cb3    4481cc71
  54) 7b71f76d    27e9f1d8    792410db    8e11eb59    99076cb3
  55) 5e6456af    7b71f76d    09fa7c76    792410db    8e11eb59
  56) c846093f    5e6456af    5edc7ddb    09fa7c76    792410db
  57) d262ff50    c846093f    d79915ab    5edc7ddb    09fa7c76
  58) 09d785fd    d262ff50    f211824f    d79915ab    5edc7ddb
  59) 3f52de5a    09d785fd    3498bfd4    f211824f    d79915ab
  60) d756c147    3f52de5a    4275e17f    3498bfd4    f211824f
  61) 548c9cb2    d756c147    8fd4b796    4275e17f    3498bfd4
  62) b66c020b    548c9cb2    f5d5b051    8fd4b796    4275e17f
  63) 6b61c9e1    b66c020b    9523272c    f5d5b051    8fd4b796
  64) 19dfa7ac    6b61c9e1    ed9b0082    9523272c    f5d5b051
  65) 101655f9    19dfa7ac    5ad87278    ed9b0082    9523272c
  66) 0c3df2b4    101655f9    0677e9eb    5ad87278    ed9b0082
  67) 78dd4d2b    0c3df2b4    4405957e    0677e9eb    5ad87278
  68) 497093c0    78dd4d2b    030f7cad    4405957e    0677e9eb
  69) 3f2588c2    497093c0    de37534a    030f7cad    4405957e
  70) c199f8c7    3f2588c2    125c24f0    de37534a    030f7cad
  71) 39859de7    c199f8c7    8fc96230    125c24f0    de37534a
  72) edb42de4    39859de7    f0667e31    8fc96230    125c24f0
  73) 11793f6f    edb42de4    ce616779    f0667e31    8fc96230
  74) 5ee76897    11793f6f    3b6d0b79    ce616779    f0667e31
  75) 63f7dab7    5ee76897    c45e4fdb    3b6d0b79    ce616779
  76) a079b7d9    63f7dab7    d7b9da25    c45e4fdb    3b6d0b79
  77) 860d21cc    a079b7d9    d8fdf6ad    d7b9da25    c45e4fdb
  78) 5738d5e1    860d21cc    681e6df6    d8fdf6ad    d7b9da25
  79) 42541b35    5738d5e1    21834873    681e6df6    d8fdf6ad
```

Add those values back to the hash:
```
H[0] + a = 67452301 + 42541b35 = a9993e36
H[1] + b = efcdab89 + 5738d5e1 = 4706816a
H[2] + c = 98badcfe + 21834873 = ba3e2571
H[3] + d = 10325476 + 681e6df6 = 7850c26c
H[4] + e = c3d2e1f0 + d8fdf6ad = 9cd0d89d
```

Since there is only 1 block, this is the end.

## Final hash
```
a9993e36 4706816a ba3e2571 7850c26c 9cd0d89d
```
