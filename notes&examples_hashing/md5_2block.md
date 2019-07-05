**message:**<br>`"abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq"`

## Message padded
Message transformed into padded binary<br>(message + 1 + 0s + message bits len in *little* endian)
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
11000000 00000001 00000000 00000000  00000000 00000000 00000000 00000000
```

## Hash intialized
```
h[0] = 67452301
h[1] = efcdab89
h[2] = 98badcfe
h[3] = 10325476
```

## Words (first block)
512-bit block of the binary, clumped into 32-bit "words"
```
W[ 0] = 64636261
W[ 1] = 65646362
W[ 2] = 66656463
W[ 3] = 67666564
W[ 4] = 68676665
W[ 5] = 69686766
W[ 6] = 6a696867
W[ 7] = 6b6a6968
W[ 8] = 6c6b6a69
W[ 9] = 6d6c6b6a
W[10] = 6e6d6c6b
W[11] = 6f6e6d6c
W[12] = 706f6e6d
W[13] = 71706f6e
W[14] = 00000080
W[15] = 00000000
```

## Compression function (first block)
Hex values for the working variables after each pass in the compression function:
```
        (a)         (b)         (c)         (d)
init) 67452301    efcdab89    98badcfe    10325476
   0) 10325476    d6d117a6    efcdab89    98badcfe
   1) 98badcfe    7a817a7a    d6d117a6    efcdab89
   2) efcdab89    06417096    7a817a7a    d6d117a6
   3) d6d117a6    c9bc516b    06417096    7a817a7a
   4) 7a817a7a    24c0379e    c9bc516b    06417096
   5) 06417096    54517a7d    24c0379e    c9bc516b
   6) c9bc516b    f8aec80b    54517a7d    24c0379e
   7) 24c0379e    d510737e    f8aec80b    54517a7d
   8) 54517a7d    4bd1e8e3    d510737e    f8aec80b
   9) f8aec80b    5fb1ecc7    4bd1e8e3    d510737e
  10) d510737e    77f65222    5fb1ecc7    4bd1e8e3
  11) 4bd1e8e3    d2c1b58a    77f65222    5fb1ecc7
  12) 5fb1ecc7    b3a2124d    d2c1b58a    77f65222
  13) 77f65222    a5813ca5    b3a2124d    d2c1b58a
  14) d2c1b58a    f3ff6105    a5813ca5    b3a2124d
  15) b3a2124d    f22edec0    f3ff6105    a5813ca5
  16) a5813ca5    268df0e0    f22edec0    f3ff6105
  17) f3ff6105    993c0ac5    268df0e0    f22edec0
  18) f22edec0    ee249263    993c0ac5    268df0e0
  19) 268df0e0    21348a3d    ee249263    993c0ac5
  20) 993c0ac5    cc74e396    21348a3d    ee249263
  21) ee249263    10a02744    cc74e396    21348a3d
  22) 21348a3d    c7bacc0d    10a02744    cc74e396
  23) cc74e396    d29f2e18    c7bacc0d    10a02744
  24) 10a02744    3e608bfe    d29f2e18    c7bacc0d
  25) c7bacc0d    3813f9d1    3e608bfe    d29f2e18
  26) d29f2e18    b24f91eb    3813f9d1    3e608bfe
  27) 3e608bfe    a7eafd74    b24f91eb    3813f9d1
  28) 3813f9d1    2866baf3    a7eafd74    b24f91eb
  29) b24f91eb    c8650275    2866baf3    a7eafd74
  30) a7eafd74    08adc5d8    c8650275    2866baf3
  31) 2866baf3    9ca4a07b    08adc5d8    c8650275
  32) c8650275    8000d799    9ca4a07b    08adc5d8
  33) 08adc5d8    e0ada61b    8000d799    9ca4a07b
  34) 9ca4a07b    470d87de    e0ada61b    8000d799
  35) 8000d799    f8ee9d45    470d87de    e0ada61b
  36) e0ada61b    901cb943    f8ee9d45    470d87de
  37) 470d87de    2c1cc76a    901cb943    f8ee9d45
  38) f8ee9d45    4c2fb58c    2c1cc76a    901cb943
  39) 901cb943    2ebadb54    4c2fb58c    2c1cc76a
  40) 2c1cc76a    b9dfedeb    2ebadb54    4c2fb58c
  41) 4c2fb58c    1887b09e    b9dfedeb    2ebadb54
  42) 2ebadb54    ea1dc905    1887b09e    b9dfedeb
  43) b9dfedeb    829241ff    ea1dc905    1887b09e
  44) 1887b09e    95286126    829241ff    ea1dc905
  45) ea1dc905    6a3ec491    95286126    829241ff
  46) 829241ff    94844bd6    6a3ec491    95286126
  47) 95286126    2890e74b    94844bd6    6a3ec491
  48) 6a3ec491    eb378850    2890e74b    94844bd6
  49) 94844bd6    f95a93c3    eb378850    2890e74b
  50) 2890e74b    3b2cbdf3    f95a93c3    eb378850
  51) eb378850    9ff7665e    3b2cbdf3    f95a93c3
  52) f95a93c3    178069b7    9ff7665e    3b2cbdf3
  53) 3b2cbdf3    deced296    178069b7    9ff7665e
  54) 9ff7665e    473c9c02    deced296    178069b7
  55) 178069b7    d4f42e30    473c9c02    deced296
  56) deced296    6c75a8d9    d4f42e30    473c9c02
  57) 473c9c02    6a72b4ec    6c75a8d9    d4f42e30
  58) d4f42e30    3ccc62c6    6a72b4ec    6c75a8d9
  59) 6c75a8d9    85f9a7f4    3ccc62c6    6a72b4ec
  60) 6a72b4ec    de806451    85f9a7f4    3ccc62c6
  61) 3ccc62c6    783cd016    de806451    85f9a7f4
  62) 85f9a7f4    a356097a    783cd016    de806451
  63) de806451    fe4d4f80    a356097a    783cd016
```

Add those values back to the hash:
```
H[0] + a = 67452301 + de806451 = 45c58752
H[1] + b = efcdab89 + fe4d4f80 = ee1afb09
H[2] + c = 98badcfe + a356097a = 3c10e678
H[3] + d = 10325476 + 783cd016 = 886f248c
```

## Words (second block)
512-bit block of the binary, clumped into 32-bit "words"
```
W[ 0] = 00000000
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
W[14] = 000001c0
W[15] = 00000000
```

## Compression function (second block)
Hex values for the working variables after each pass in the compression function:
```
        (a)         (b)         (c)         (d)
init) 45c58752    ee1afb09    3c10e678    886f248c
   0) 886f248c    c124262d    ee1afb09    3c10e678
   1) 3c10e678    3d07dd01    c124262d    ee1afb09
   2) ee1afb09    37c0239b    3d07dd01    c124262d
   3) c124262d    fee962ce    37c0239b    3d07dd01
   4) 3d07dd01    326416c5    fee962ce    37c0239b
   5) 37c0239b    2ed4b28b    326416c5    fee962ce
   6) fee962ce    a7bc5746    2ed4b28b    326416c5
   7) 326416c5    3c491848    a7bc5746    2ed4b28b
   8) 2ed4b28b    7cfa48a9    3c491848    a7bc5746
   9) a7bc5746    d992d03f    7cfa48a9    3c491848
  10) 3c491848    d053196c    d992d03f    7cfa48a9
  11) 7cfa48a9    fd43b17c    d053196c    d992d03f
  12) d992d03f    ac194ed8    fd43b17c    d053196c
  13) d053196c    914e3c0e    ac194ed8    fd43b17c
  14) fd43b17c    69b301b9    914e3c0e    ac194ed8
  15) ac194ed8    6326023a    69b301b9    914e3c0e
  16) 914e3c0e    e0f4c0db    6326023a    69b301b9
  17) 69b301b9    66d89443    e0f4c0db    6326023a
  18) 6326023a    ee0bf0fb    66d89443    e0f4c0db
  19) e0f4c0db    d9ff1f54    ee0bf0fb    66d89443
  20) 66d89443    d9e7e563    d9ff1f54    ee0bf0fb
  21) ee0bf0fb    0317dfe9    d9e7e563    d9ff1f54
  22) d9ff1f54    78cfd1da    0317dfe9    d9e7e563
  23) d9e7e563    e7319c89    78cfd1da    0317dfe9
  24) 0317dfe9    db9b9917    e7319c89    78cfd1da
  25) 78cfd1da    f0a8be63    db9b9917    e7319c89
  26) e7319c89    cfc6d7f6    f0a8be63    db9b9917
  27) db9b9917    5e885adc    cfc6d7f6    f0a8be63
  28) f0a8be63    084418f8    5e885adc    cfc6d7f6
  29) cfc6d7f6    d13abf03    084418f8    5e885adc
  30) 5e885adc    4e76a0e3    d13abf03    084418f8
  31) 084418f8    4312f3f7    4e76a0e3    d13abf03
  32) d13abf03    8ce6d915    4312f3f7    4e76a0e3
  33) 4e76a0e3    06e307e6    8ce6d915    4312f3f7
  34) 4312f3f7    35ec8d11    06e307e6    8ce6d915
  35) 8ce6d915    086cfdd1    35ec8d11    06e307e6
  36) 06e307e6    d900a5c7    086cfdd1    35ec8d11
  37) 35ec8d11    ee655781    d900a5c7    086cfdd1
  38) 086cfdd1    d66dc331    ee655781    d900a5c7
  39) d900a5c7    b2c1dda6    d66dc331    ee655781
  40) ee655781    7918b7de    b2c1dda6    d66dc331
  41) d66dc331    525edf93    7918b7de    b2c1dda6
  42) b2c1dda6    fc002477    525edf93    7918b7de
  43) 7918b7de    6ec76c9a    fc002477    525edf93
  44) 525edf93    a73965eb    6ec76c9a    fc002477
  45) fc002477    6c6d5964    a73965eb    6ec76c9a
  46) 6ec76c9a    5df21a99    6c6d5964    a73965eb
  47) a73965eb    e8d7278d    5df21a99    6c6d5964
  48) 6c6d5964    4ae874dd    e8d7278d    5df21a99
  49) 5df21a99    97962ba4    4ae874dd    e8d7278d
  50) e8d7278d    ff2c1f12    97962ba4    4ae874dd
  51) 4ae874dd    8ab5e1a1    ff2c1f12    97962ba4
  52) 97962ba4    10244412    8ab5e1a1    ff2c1f12
  53) ff2c1f12    a41a9715    10244412    8ab5e1a1
  54) 8ab5e1a1    1b890962    a41a9715    10244412
  55) 10244412    a91688cf    1b890962    a41a9715
  56) a41a9715    bbff8467    a91688cf    1b890962
  57) 1b890962    7ff01c4b    bbff8467    a91688cf
  58) a91688cf    23b95d93    7ff01c4b    bbff8467
  59) bbff8467    ebbb4a92    23b95d93    7ff01c4b
  60) 7ff01c4b    c2298e30    ebbb4a92    23b95d93
  61) 23b95d93    c1f747fb    c2298e30    ebbb4a92
  62) ebbb4a92    9705fb32    c1f747fb    c2298e30
  63) c2298e30    dbf0a78d    9705fb32    c1f747fb
```

Add those values back to the hash:
```
H[0] + a = 45c58752 + c2298e30 = 07ef1582
H[1] + b = ee1afb09 + dbf0a78d = ca0ba296
H[2] + c = 3c10e678 + 9705fb32 = d316e1aa
H[3] + d = 886f248c + c1f747fb = 4a666c87
```

The padded binary is 2 blocks long. This is the end.

## Endian flip
Flip the endianness of the final hash:
```
 Pre:  07ef1582    ca0ba296    d316e1aa    4a666c87
Post:  8215ef07    96a20bca    aae116d3    876c664a
```

## Final hash
```
8215ef07 96a20bca aae116d3 876c664a
```
