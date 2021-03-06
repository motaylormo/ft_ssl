**message:**<br>`"abc"`

## Padded message
Message transformed into padded binary<br>(message + 1 + 0s + number of message bits as a 64-bit *big* endian number)
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
H[0] = 6a09e667
H[1] = bb67ae85
H[2] = 3c6ef372
H[3] = a54ff53a
H[4] = 510e527f
H[5] = 9b05688c
H[6] = 1f83d9ab
H[7] = 5be0cd19
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
init) 6a09e667    bb67ae85    3c6ef372    a54ff53a    510e527f    9b05688c    1f83d9ab    5be0cd19
   0) 5d6aebcd    6a09e667    bb67ae85    3c6ef372    fa2a4622    510e527f    9b05688c    1f83d9ab
   1) 5a6ad9ad    5d6aebcd    6a09e667    bb67ae85    78ce7989    fa2a4622    510e527f    9b05688c
   2) c8c347a7    5a6ad9ad    5d6aebcd    6a09e667    f92939eb    78ce7989    fa2a4622    510e527f
   3) d550f666    c8c347a7    5a6ad9ad    5d6aebcd    24e00850    f92939eb    78ce7989    fa2a4622
   4) 04409a6a    d550f666    c8c347a7    5a6ad9ad    43ada245    24e00850    f92939eb    78ce7989
   5) 2b4209f5    04409a6a    d550f666    c8c347a7    714260ad    43ada245    24e00850    f92939eb
   6) e5030380    2b4209f5    04409a6a    d550f666    9b27a401    714260ad    43ada245    24e00850
   7) 85a07b5f    e5030380    2b4209f5    04409a6a    0c657a79    9b27a401    714260ad    43ada245
   8) 8e04ecb9    85a07b5f    e5030380    2b4209f5    32ca2d8c    0c657a79    9b27a401    714260ad
   9) 8c87346b    8e04ecb9    85a07b5f    e5030380    1cc92596    32ca2d8c    0c657a79    9b27a401
  10) 4798a3f4    8c87346b    8e04ecb9    85a07b5f    436b23e8    1cc92596    32ca2d8c    0c657a79
  11) f71fc5a9    4798a3f4    8c87346b    8e04ecb9    816fd6e9    436b23e8    1cc92596    32ca2d8c
  12) 87912990    f71fc5a9    4798a3f4    8c87346b    1e578218    816fd6e9    436b23e8    1cc92596
  13) d932eb16    87912990    f71fc5a9    4798a3f4    745a48de    1e578218    816fd6e9    436b23e8
  14) c0645fde    d932eb16    87912990    f71fc5a9    0b92f20c    745a48de    1e578218    816fd6e9
  15) b0fa238e    c0645fde    d932eb16    87912990    07590dcd    0b92f20c    745a48de    1e578218
  16) 21da9a9b    b0fa238e    c0645fde    d932eb16    8034229c    07590dcd    0b92f20c    745a48de
  17) c2fbd9d1    21da9a9b    b0fa238e    c0645fde    846ee454    8034229c    07590dcd    0b92f20c
  18) fe777bbf    c2fbd9d1    21da9a9b    b0fa238e    cc899961    846ee454    8034229c    07590dcd
  19) e1f20c33    fe777bbf    c2fbd9d1    21da9a9b    b0638179    cc899961    846ee454    8034229c
  20) 9dc68b63    e1f20c33    fe777bbf    c2fbd9d1    8ada8930    b0638179    cc899961    846ee454
  21) c2606d6d    9dc68b63    e1f20c33    fe777bbf    e1257970    8ada8930    b0638179    cc899961
  22) a7a3623f    c2606d6d    9dc68b63    e1f20c33    49f5114a    e1257970    8ada8930    b0638179
  23) c5d53d8d    a7a3623f    c2606d6d    9dc68b63    aa47c347    49f5114a    e1257970    8ada8930
  24) 1c2c2838    c5d53d8d    a7a3623f    c2606d6d    2823ef91    aa47c347    49f5114a    e1257970
  25) cde8037d    1c2c2838    c5d53d8d    a7a3623f    14383d8e    2823ef91    aa47c347    49f5114a
  26) b62ec4bc    cde8037d    1c2c2838    c5d53d8d    c74c6516    14383d8e    2823ef91    aa47c347
  27) 77d37528    b62ec4bc    cde8037d    1c2c2838    edffbff8    c74c6516    14383d8e    2823ef91
  28) 363482c9    77d37528    b62ec4bc    cde8037d    6112a3b7    edffbff8    c74c6516    14383d8e
  29) a0060b30    363482c9    77d37528    b62ec4bc    ade79437    6112a3b7    edffbff8    c74c6516
  30) ea992a22    a0060b30    363482c9    77d37528    0109ab3a    ade79437    6112a3b7    edffbff8
  31) 73b33bf5    ea992a22    a0060b30    363482c9    ba591112    0109ab3a    ade79437    6112a3b7
  32) 98e12507    73b33bf5    ea992a22    a0060b30    9cd9f5f6    ba591112    0109ab3a    ade79437
  33) fe604df5    98e12507    73b33bf5    ea992a22    59249dd3    9cd9f5f6    ba591112    0109ab3a
  34) a9a7738c    fe604df5    98e12507    73b33bf5    085f3833    59249dd3    9cd9f5f6    ba591112
  35) 65a0cfe4    a9a7738c    fe604df5    98e12507    f4b002d6    085f3833    59249dd3    9cd9f5f6
  36) 41a65cb1    65a0cfe4    a9a7738c    fe604df5    0772a26b    f4b002d6    085f3833    59249dd3
  37) 34df1604    41a65cb1    65a0cfe4    a9a7738c    a507a53d    0772a26b    f4b002d6    085f3833
  38) 6dc57a8a    34df1604    41a65cb1    65a0cfe4    f0781bc8    a507a53d    0772a26b    f4b002d6
  39) 79ea687a    6dc57a8a    34df1604    41a65cb1    1efbc0a0    f0781bc8    a507a53d    0772a26b
  40) d6670766    79ea687a    6dc57a8a    34df1604    26352d63    1efbc0a0    f0781bc8    a507a53d
  41) df46652f    d6670766    79ea687a    6dc57a8a    838b2711    26352d63    1efbc0a0    f0781bc8
  42) 17aa0dfe    df46652f    d6670766    79ea687a    decd4715    838b2711    26352d63    1efbc0a0
  43) 9d4baf93    17aa0dfe    df46652f    d6670766    fda24c2e    decd4715    838b2711    26352d63
  44) 26628815    9d4baf93    17aa0dfe    df46652f    a80f11f0    fda24c2e    decd4715    838b2711
  45) 72ab4b91    26628815    9d4baf93    17aa0dfe    b7755da1    a80f11f0    fda24c2e    decd4715
  46) a14c14b0    72ab4b91    26628815    9d4baf93    d57b94a9    b7755da1    a80f11f0    fda24c2e
  47) 4172328d    a14c14b0    72ab4b91    26628815    fecf0bc6    d57b94a9    b7755da1    a80f11f0
  48) 05757ceb    4172328d    a14c14b0    72ab4b91    bd714038    fecf0bc6    d57b94a9    b7755da1
  49) f11bfaa8    05757ceb    4172328d    a14c14b0    6e5c390c    bd714038    fecf0bc6    d57b94a9
  50) 7a0508a1    f11bfaa8    05757ceb    4172328d    52f1ccf7    6e5c390c    bd714038    fecf0bc6
  51) 886e7a22    7a0508a1    f11bfaa8    05757ceb    49231c1e    52f1ccf7    6e5c390c    bd714038
  52) 101fd28f    886e7a22    7a0508a1    f11bfaa8    529e7d00    49231c1e    52f1ccf7    6e5c390c
  53) f5702fdb    101fd28f    886e7a22    7a0508a1    9f4787c3    529e7d00    49231c1e    52f1ccf7
  54) 3ec45cdb    f5702fdb    101fd28f    886e7a22    e50e1b4f    9f4787c3    529e7d00    49231c1e
  55) 38cc9913    3ec45cdb    f5702fdb    101fd28f    54cb266b    e50e1b4f    9f4787c3    529e7d00
  56) fcd1887b    38cc9913    3ec45cdb    f5702fdb    9b5e906c    54cb266b    e50e1b4f    9f4787c3
  57) c062d46f    fcd1887b    38cc9913    3ec45cdb    7e44008e    9b5e906c    54cb266b    e50e1b4f
  58) ffb70472    c062d46f    fcd1887b    38cc9913    6d83bfc6    7e44008e    9b5e906c    54cb266b
  59) b6ae8fff    ffb70472    c062d46f    fcd1887b    b21bad3d    6d83bfc6    7e44008e    9b5e906c
  60) b85e2ce9    b6ae8fff    ffb70472    c062d46f    961f4894    b21bad3d    6d83bfc6    7e44008e
  61) 04d24d6c    b85e2ce9    b6ae8fff    ffb70472    948d25b6    961f4894    b21bad3d    6d83bfc6
  62) d39a2165    04d24d6c    b85e2ce9    b6ae8fff    fb121210    948d25b6    961f4894    b21bad3d
  63) 506e3058    d39a2165    04d24d6c    b85e2ce9    5ef50f24    fb121210    948d25b6    961f4894
```

Add those values back to the hash:
```
H[0] + a = 6a09e667 + 506e3058 = ba7816bf
H[1] + b = bb67ae85 + d39a2165 = 8f01cfea
H[2] + c = 3c6ef372 + 04d24d6c = 414140de
H[3] + d = a54ff53a + b85e2ce9 = 5dae2223
H[4] + e = 510e527f + 5ef50f24 = b00361a3
H[5] + f = 9b05688c + fb121210 = 96177a9c
H[6] + g = 1f83d9ab + 948d25b6 = b410ff61
H[7] + h = 5be0cd19 + 961f4894 = f20015ad
```

Since there is only 1 block, this is the end.

## Final hash
```
ba7816bf 8f01cfea 414140de 5dae2223 b00361a3 96177a9c b410ff61 f20015ad
```
