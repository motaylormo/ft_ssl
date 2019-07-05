message: `"abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq"`

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
h[0] = 67452301
h[1] = efcdab89
h[2] = 98badcfe
h[3] = 10325476
h[4] = c3d2e1f0
```

## Words (first block)
512-bit block of the binary, transformed into 80, 32-bit "words". The first 16 words are just 32-bit sections of the block, flipped to little endian. The rest are produced by running those first 16 through a fuction.
```
W[ 0] = 61626364    W[16] = 0a063a3e    W[32] = 0989cbe8    W[48] = e8be56b0    W[64] = 152198d6
W[ 1] = 62636465    W[17] = d8dadcdf    W[33] = f24843fe    W[49] = 1a0ae652    W[65] = 7b3f1982
W[ 2] = 63646566    W[18] = dadcdec0    W[34] = 5c40d0ba    W[50] = cd5611c8    W[66] = 37f2d5b7
W[ 3] = 64656667    W[19] = c8d2b4be    W[35] = a8d9cc3b    W[51] = 46ef29dc    W[67] = 8596323e
W[ 4] = 65666768    W[20] = 6f757b5b    W[36] = b2b9666e    W[52] = 60d3da6d    W[68] = 810790d6
W[ 5] = 66676869    W[21] = 757b5967    W[37] = ba7b71b7    W[53] = ddf3ba6e    W[69] = bea0a942
W[ 6] = 6768696a    W[22] = 8da16d70    W[38] = 20b28a72    W[54] = 2737f5e9    W[70] = 11c7e1b1
W[ 7] = 68696a6b    W[23] = daeefaba    W[39] = b28af500    W[55] = 4888a710    W[71] = 6158d101
W[ 8] = 696a6b6c    W[24] = faf6cab6    W[40] = 8ac87842    W[56] = d2a1177b    W[72] = 5fcd77d9
W[ 9] = 6a6b6c6d    W[25] = a6fb675a    W[41] = 289addf4    W[57] = 9999633b    W[73] = 7f2f12e6
W[10] = 6b6c6d6e    W[26] = 0c604cc8    W[42] = 56d51f21    W[58] = d6c69d03    W[74] = f868cfb1
W[11] = 6c6d6e6f    W[27] = 604cc02c    W[43] = d96b7fd2    W[59] = ccf6127b    W[75] = d6e997e9
W[12] = 6d6e6f70    W[28] = 49c0e6e2    W[44] = 3868e778    W[60] = 7c58fe6d    W[76] = f526b852
W[13] = 6e6f7071    W[29] = 2ee8cbbc    W[45] = ab5e4848    W[61] = fdd99c68    W[77] = b7578dcc
W[14] = 80000000    W[30] = cfd72ec4    W[46] = 7f0e2118    W[62] = f8e32074    W[78] = 55d99df4
W[15] = 00000000    W[31] = 97e9810e    W[47] = de87a111    W[63] = e0ba3c7d    W[79] = 1ff69958
```

## Compression function (first block)
Hex values for a b c d after each pass in the compression function:
```
        (a)         (b)         (c)         (d)         (e)
init) 67452301    efcdab89    98badcfe    10325476    c3d2e1f0
   0) 0116fc17    67452301    7bf36ae2    98badcfe    10325476
   1) ebf3b452    0116fc17    59d148c0    7bf36ae2    98badcfe
   2) 5109913a    ebf3b452    c045bf05    59d148c0    7bf36ae2
   3) 2c4f6eac    5109913a    bafced14    c045bf05    59d148c0
   4) 33f4ae5b    2c4f6eac    9442644e    bafced14    c045bf05
   5) 96b85189    33f4ae5b    0b13dbab    9442644e    bafced14
   6) db04cb58    96b85189    ccfd2b96    0b13dbab    9442644e
   7) 45833f0f    db04cb58    65ae1462    ccfd2b96    0b13dbab
   8) c565c35e    45833f0f    36c132d6    65ae1462    ccfd2b96
   9) 6350afda    c565c35e    d160cfc3    36c132d6    65ae1462
  10) 8993ea77    6350afda    b15970d7    d160cfc3    36c132d6
  11) e19ecaa2    8993ea77    98d42bf6    b15970d7    d160cfc3
  12) 8603481e    e19ecaa2    e264fa9d    98d42bf6    b15970d7
  13) 32f94a85    8603481e    b867b2a8    e264fa9d    98d42bf6
  14) b2e7a8be    32f94a85    a180d207    b867b2a8    e264fa9d
  15) 42637e39    b2e7a8be    4cbe52a1    a180d207    b867b2a8
  16) 6b068048    42637e39    acb9ea2f    4cbe52a1    a180d207
  17) 426b9c35    6b068048    5098df8e    acb9ea2f    4cbe52a1
  18) 944b1bd1    426b9c35    1ac1a012    5098df8e    acb9ea2f
  19) 6c445652    944b1bd1    509ae70d    1ac1a012    5098df8e
  20) 95836da5    6c445652    6512c6f4    509ae70d    1ac1a012
  21) 09511177    95836da5    9b111594    6512c6f4    509ae70d
  22) e2b92dc4    09511177    6560db69    9b111594    6512c6f4
  23) fd224575    e2b92dc4    c254445d    6560db69    9b111594
  24) eeb82d9a    fd224575    38ae4b71    c254445d    6560db69
  25) 5a142c1a    eeb82d9a    7f48915d    38ae4b71    c254445d
  26) 2972f7c7    5a142c1a    bbae0b66    7f48915d    38ae4b71
  27) d526a644    2972f7c7    96850b06    bbae0b66    7f48915d
  28) e1122421    d526a644    ca5cbdf1    96850b06    bbae0b66
  29) 05b457b2    e1122421    3549a991    ca5cbdf1    96850b06
  30) a9c84bec    05b457b2    78448908    3549a991    ca5cbdf1
  31) 52e31f60    a9c84bec    816d15ec    78448908    3549a991
  32) 5af3242c    52e31f60    2a7212fb    816d15ec    78448908
  33) 31c756a9    5af3242c    14b8c7d8    2a7212fb    816d15ec
  34) e9ac987c    31c756a9    16bcc90b    14b8c7d8    2a7212fb
  35) ab7c32ee    e9ac987c    4c71d5aa    16bcc90b    14b8c7d8
  36) 5933fc99    ab7c32ee    3a6b261f    4c71d5aa    16bcc90b
  37) 43f87ae9    5933fc99    aadf0cbb    3a6b261f    4c71d5aa
  38) 24957f22    43f87ae9    564cff26    aadf0cbb    3a6b261f
  39) adeb7478    24957f22    50fe1eba    564cff26    aadf0cbb
  40) d70e5010    adeb7478    89255fc8    50fe1eba    564cff26
  41) 79bcfb08    d70e5010    2b7add1e    89255fc8    50fe1eba
  42) f9bcb8de    79bcfb08    35c39404    2b7add1e    89255fc8
  43) 633e9561    f9bcb8de    1e6f3ec2    35c39404    2b7add1e
  44) 98c1ea64    633e9561    be6f2e37    1e6f3ec2    35c39404
  45) c6ea241e    98c1ea64    58cfa558    be6f2e37    1e6f3ec2
  46) a2ad4f02    c6ea241e    26307a99    58cfa558    be6f2e37
  47) c8a69090    a2ad4f02    b1ba8907    26307a99    58cfa558
  48) 88341600    c8a69090    a8ab53c0    b1ba8907    26307a99
  49) 7e846f58    88341600    3229a424    a8ab53c0    b1ba8907
  50) 86e358ba    7e846f58    220d0580    3229a424    a8ab53c0
  51) 8d2e76c8    86e358ba    1fa11bd6    220d0580    3229a424
  52) ce892e10    8d2e76c8    a1b8d62e    1fa11bd6    220d0580
  53) edea95b1    ce892e10    234b9db2    a1b8d62e    1fa11bd6
  54) 36d1230a    edea95b1    33a24b84    234b9db2    a1b8d62e
  55) 776c3910    36d1230a    7b7aa56c    33a24b84    234b9db2
  56) a681b723    776c3910    8db448c2    7b7aa56c    33a24b84
  57) ac0a794f    a681b723    1ddb0e44    8db448c2    7b7aa56c
  58) f03d3782    ac0a794f    e9a06dc8    1ddb0e44    8db448c2
  59) 9ef775c3    f03d3782    eb029e53    e9a06dc8    1ddb0e44
  60) 36254b13    9ef775c3    bc0f4de0    eb029e53    e9a06dc8
  61) 4080d4dc    36254b13    e7bddd70    bc0f4de0    eb029e53
  62) 2bfaf7a8    4080d4dc    cd8952c4    e7bddd70    bc0f4de0
  63) 513f9ca0    2bfaf7a8    10203537    cd8952c4    e7bddd70
  64) e5895c81    513f9ca0    0afebdea    10203537    cd8952c4
  65) 1037d2d5    e5895c81    144fe728    0afebdea    10203537
  66) 14a82da9    1037d2d5    79625720    144fe728    0afebdea
  67) 6d17c9fd    14a82da9    440df4b5    79625720    144fe728
  68) 2c7b07bd    6d17c9fd    452a0b6a    440df4b5    79625720
  69) fdf6efff    2c7b07bd    5b45f27f    452a0b6a    440df4b5
  70) 112b96e3    fdf6efff    4b1ec1ef    5b45f27f    452a0b6a
  71) 84065712    112b96e3    ff7dbbff    4b1ec1ef    5b45f27f
  72) ab89fb71    84065712    c44ae5b8    ff7dbbff    4b1ec1ef
  73) c5210e35    ab89fb71    a10195c4    c44ae5b8    ff7dbbff
  74) 352d9f4b    c5210e35    6ae27edc    a10195c4    c44ae5b8
  75) 1a0e0e0a    352d9f4b    7148438d    6ae27edc    a10195c4
  76) d0d47349    1a0e0e0a    cd4b67d2    7148438d    6ae27edc
  77) ad38620d    d0d47349    86838382    cd4b67d2    7148438d
  78) d3ad7c25    ad38620d    74351cd2    86838382    cd4b67d2
  79) 8ce34517    d3ad7c25    6b4e1883    74351cd2    86838382
```
Add those values back to the hash:
```
H[0] + a = 67452301 + 8ce34517 = f4286818
H[1] + b = efcdab89 + d3ad7c25 = c37b27ae
H[2] + c = 98badcfe + 6b4e1883 = 0408f581
H[3] + d = 10325476 + 74351cd2 = 84677148
H[4] + e = c3d2e1f0 + 86838382 = 4a566572
```

## Words (second block)
The next 512-bit block of the binary, transformed into 80 32-bit "words":
```
W[ 0] = 00000000    W[16] = 00000000    W[32] = 00000000    W[48] = 000e0000    W[64] = 00000000
W[ 1] = 00000000    W[17] = 00000000    W[33] = 00007000    W[49] = 0000e000    W[65] = 00d80000
W[ 2] = 00000000    W[18] = 00000380    W[34] = 00000e00    W[50] = 00003600    W[66] = 0380e000
W[ 3] = 00000000    W[19] = 00000000    W[35] = 00003600    W[51] = 001cee00    W[67] = 004f0000
W[ 4] = 00000000    W[20] = 00000000    W[36] = 0000e000    W[52] = 00000000    W[68] = 00000000
W[ 5] = 00000000    W[21] = 00000700    W[37] = 00000e00    W[53] = 000df000    W[69] = 070e0000
W[ 6] = 00000000    W[22] = 00000000    W[38] = 00000000    W[54] = 00380000    W[70] = 00ee0000
W[ 7] = 00000000    W[23] = 00000380    W[39] = 0001ce00    W[55] = 0004c600    W[71] = 03751c00
W[ 8] = 00000000    W[24] = 00000e00    W[40] = 00000000    W[56] = 0000e000    W[72] = 0e000000
W[ 9] = 00000000    W[25] = 00000000    W[41] = 0000d800    W[57] = 0070ee00    W[73] = 00e0e000
W[10] = 00000000    W[26] = 00000000    W[42] = 00038000    W[58] = 000ee000    W[74] = 00363800
W[11] = 00000000    W[27] = 00001c00    W[43] = 00004f00    W[59] = 00369e00    W[75] = 1cee9000
W[12] = 00000000    W[28] = 00000000    W[44] = 00000000    W[60] = 00e00000    W[76] = 00000000
W[13] = 00000000    W[29] = 00000d80    W[45] = 00070e00    W[61] = 000ed600    W[77] = 0df09000
W[14] = 00000000    W[30] = 00003800    W[46] = 0000ee00    W[62] = 0000e000    W[78] = 3800e000
W[15] = 000001c0    W[31] = 00000480    W[47] = 00037500    W[63] = 01cea600    W[79] = 04c77400
```

## Compression function (second block)
Hex values for a b c d after each pass in the compression function:
```
        (a)         (b)         (c)         (d)         (e)  
init) f4286818    c37b27ae    0408f581    84677148    4a566572
   0) 2df257e9    f4286818    b0dec9eb    0408f581    84677148
   1) 4d3dc58f    2df257e9    3d0a1a06    b0dec9eb    0408f581
   2) c352bb05    4d3dc58f    4b7c95fa    3d0a1a06    b0dec9eb
   3) eef743c6    c352bb05    d34f7163    4b7c95fa    3d0a1a06
   4) 41e34277    eef743c6    70d4aec1    d34f7163    4b7c95fa
   5) 5443915c    41e34277    bbbdd0f1    70d4aec1    d34f7163
   6) e7fa0377    5443915c    d078d09d    bbbdd0f1    70d4aec1
   7) c6946813    e7fa0377    1510e457    d078d09d    bbbdd0f1
   8) fdde1de1    c6946813    f9fe80dd    1510e457    d078d09d
   9) b8538aca    fdde1de1    f1a51a04    f9fe80dd    1510e457
  10) 6ba94f63    b8538aca    7f778778    f1a51a04    f9fe80dd
  11) 43a2792f    6ba94f63    ae14e2b2    7f778778    f1a51a04
  12) fecd7bbf    43a2792f    daea53d8    ae14e2b2    7f778778
  13) a2604ca8    fecd7bbf    d0e89e4b    daea53d8    ae14e2b2
  14) 258b0baa    a2604ca8    ffb35eef    d0e89e4b    daea53d8
  15) d9772360    258b0baa    2898132a    ffb35eef    d0e89e4b
  16) 5507db6e    d9772360    8962c2ea    2898132a    ffb35eef
  17) a51b58bc    5507db6e    365dc8d8    8962c2ea    2898132a
  18) c2eb709f    a51b58bc    9541f6db    365dc8d8    8962c2ea
  19) d8992153    c2eb709f    2946d62f    9541f6db    365dc8d8
  20) 37482f5f    d8992153    f0badc27    2946d62f    9541f6db
  21) ee8700bd    37482f5f    f6264854    f0badc27    2946d62f
  22) 9ad594b9    ee8700bd    cdd20bd7    f6264854    f0badc27
  23) 8fbaa5b9    9ad594b9    7ba1c02f    cdd20bd7    f6264854
  24) 88fb5867    8fbaa5b9    66b5652e    7ba1c02f    cdd20bd7
  25) eec50521    88fb5867    63eea96e    66b5652e    7ba1c02f
  26) 50bce434    eec50521    e23ed619    63eea96e    66b5652e
  27) 5c416daf    50bce434    7bb14148    e23ed619    63eea96e
  28) 2429be5f    5c416daf    142f390d    7bb14148    e23ed619
  29) 0a2fb108    2429be5f    d7105b6b    142f390d    7bb14148
  30) 17986223    0a2fb108    c90a6f97    d7105b6b    142f390d
  31) 8a4af384    17986223    028bec42    c90a6f97    d7105b6b
  32) 6b629993    8a4af384    c5e61888    028bec42    c90a6f97
  33) f15f04f3    6b629993    2292bce1    c5e61888    028bec42
  34) 295cc25b    f15f04f3    dad8a664    2292bce1    c5e61888
  35) 696da404    295cc25b    fc57c13c    dad8a664    2292bce1
  36) cef5ae12    696da404    ca573096    fc57c13c    dad8a664
  37) 87d5b80c    cef5ae12    1a5b6901    ca573096    fc57c13c
  38) 84e2a5f2    87d5b80c    b3bd6b84    1a5b6901    ca573096
  39) 03bb6310    84e2a5f2    21f56e03    b3bd6b84    1a5b6901
  40) c2d8f75f    03bb6310    a138a97c    21f56e03    b3bd6b84
  41) bfb25768    c2d8f75f    00eed8c4    a138a97c    21f56e03
  42) 28589152    bfb25768    f0b63dd7    00eed8c4    a138a97c
  43) ec1d3d61    28589152    2fec95da    f0b63dd7    00eed8c4
  44) 3caed7af    ec1d3d61    8a162454    2fec95da    f0b63dd7
  45) c3d033ea    3caed7af    7b074f58    8a162454    2fec95da
  46) 7316056a    c3d033ea    cf2bb5eb    7b074f58    8a162454
  47) 46f93b68    7316056a    b0f40cfa    cf2bb5eb    7b074f58
  48) dc8e7f26    46f93b68    9cc5815a    b0f40cfa    cf2bb5eb
  49) 850d411c    dc8e7f26    11be4eda    9cc5815a    b0f40cfa
  50) 7e4672c0    850d411c    b7239fc9    11be4eda    9cc5815a
  51) 89fbd41d    7e4672c0    21435047    b7239fc9    11be4eda
  52) 1797e228    89fbd41d    1f919cb0    21435047    b7239fc9
  53) 431d65bc    1797e228    627ef507    1f919cb0    21435047
  54) 2bdbb8cb    431d65bc    05e5f88a    627ef507    1f919cb0
  55) 6da72e7f    2bdbb8cb    10c7596f    05e5f88a    627ef507
  56) a8495a9b    6da72e7f    caf6ee32    10c7596f    05e5f88a
  57) e785655a    a8495a9b    db69cb9f    caf6ee32    10c7596f
  58) 5b086c42    e785655a    ea1256a6    db69cb9f    caf6ee32
  59) a65818f7    5b086c42    b9e15956    ea1256a6    db69cb9f
  60) 7aab101b    a65818f7    96c21b10    b9e15956    ea1256a6
  61) 93614c9c    7aab101b    e996063d    96c21b10    b9e15956
  62) f66d9bf4    93614c9c    deaac406    e996063d    96c21b10
  63) d504902b    f66d9bf4    24d85327    deaac406    e996063d
  64) 60a9da62    d504902b    3d9b66fd    24d85327    deaac406
  65) 8b687819    60a9da62    f541240a    3d9b66fd    24d85327
  66) 083e90c3    8b687819    982a7698    f541240a    3d9b66fd
  67) f6226bbf    083e90c3    62da1e06    982a7698    f541240a
  68) 76c0563b    f6226bbf    c20fa430    62da1e06    982a7698
  69) 989dd165    76c0563b    fd889aef    c20fa430    62da1e06
  70) 8b2c7573    989dd165    ddb0158e    fd889aef    c20fa430
  71) ae1b8e7b    8b2c7573    66277459    ddb0158e    fd889aef
  72) ca1840de    ae1b8e7b    e2cb1d5c    66277459    ddb0158e
  73) 16f3babb    ca1840de    eb86e39e    e2cb1d5c    66277459
  74) d28d83ad    16f3babb    b2861037    eb86e39e    e2cb1d5c
  75) 6bc02dfe    d28d83ad    c5bceeae    b2861037    eb86e39e
  76) d3a6e275    6bc02dfe    74a360eb    c5bceeae    b2861037
  77) da955482    d3a6e275    9af00b7f    74a360eb    c5bceeae
  78) 58c0aac0    da955482    74e9b89d    9af00b7f    74a360eb
  79) 906fd62c    58c0aac0    b6a55520    74e9b89d    9af00b7f
```

Add those values back to the hash:
```
H[0] + a = f4286818 + 906fd62c = 84983e44
H[1] + b = c37b27ae + 58c0aac0 = 1c3bd26e
H[2] + c = 0408f581 + b6a55520 = baae4aa1
H[3] + d = 84677148 + 74e9b89d = f95129e5
H[4] + e = 4a566572 + 9af00b7f = e54670f1
```

The padded binary is 2 blocks long. This is the end.

## Final hash
```
84983e44 1c3bd26e baae4aa1 f95129e5 e54670f1
```
