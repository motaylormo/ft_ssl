* **message:** `"The house stood on a slight rise just on the edge of the village."`
* **key:** `daf91e7c5a178dfe`

# Message blocks
| plaintext<br>ascii | plaintext<br>hexadecimal | encrypted<br>ascii | encrypted<br>hexadecimal |
| ------------------ | ------------------------ | ------------------ | ------------------------ |
| `The hous` | `54686520686f7573` | ```)M�A�{�```  | `294d8041a87bcf18` |
| `e stood ` | `652073746f6f6420` | ```�_>�h+V,``` | `c05f3eb9682b562c` |
| `on a sli` | `6f6e206120736c69` | ```�fUx%���``` | `8566557825b492da` |
| `ght rise` | `6768742072697365` | ```j#�`�`T```  | `6a23ec60c10e6054` |
| ` just on` | `206a757374206f6e` | ```Z:?��```    | `5a3a3f17bab9130f` |
| ` the edg` | `2074686520656467` | ```�:c�```<br>```���``` | `c93a638b0abecee1` |
| `e of the` | `65206f6620746865` | ```�b?�z�0�``` | `ae623faf7a933083` |
| ` village` | `2076696c6c616765` | ```�"��,T^```  | `8122a518802c545e` |
| `.`        | `2e07070707070707` | ```9`8b��```   | `39600438116299c4` |

**Plaintext message:**
<pre>The house stood on a slight rise just on the edge of the village.</pre>

**Encrypted message:**
<pre>)M€A¨{ÏÀ_>¹h+V,…fUx%´’Új#ì`Á`TZ:?º¹É:c‹
¾Îá®b?¯z“0ƒ"¥€,T^9`8b™Ä</pre>

# Block 1 (`"The hous"`)
<details><summary></summary>

* Block: `54686520686f7573`
* PC-1: `f7c165e400fe32a0`

| round | left | right | subkey | feistel | feistel XOR left |
| ----- | ---- | ----- | ------ | ------- | ---------------- |
|  0 | `f7c165e4` | `00fe32a0` | `b9c2fcfffd4c` | `c9fb7f8a` | `3e3a1a6e`
|  1 | `00fe32a0` | `3e3a1a6e` | `a5fc9a5f9eef` | `b88933e7` | `b8770147`
|  2 | `3e3a1a6e` | `b8770147` | `762fc2defdf9` | `d971feb8` | `e74be4d6`
|  3 | `b8770147` | `e74be4d6` | `7afc112bff7d` | `b86fc111` | `0018c056`
|  4 | `e74be4d6` | `0018c056` | `4da55efbfdb2` | `3703aaed` | `d0484e3b`
|  5 | `0018c056` | `d0484e3b` | `66c49fed4f3f` | `f5c2e524` | `f5da2572`
|  6 | `d0484e3b` | `f5da2572` | `7f8922df7ade` | `b7041ca1` | `674c529a`
|  7 | `f5da2572` | `674c529a` | `aaa8bbf5d3fd` | `e9d37450` | `1c095122`
|  8 | `674c529a` | `1c095122` | `89f2c7ffee9c` | `27c4eaae` | `4088b834`
|  9 | `1c095122` | `4088b834` | `315fce7977df` | `d084844a` | `cc8dd568`
| 10 | `4088b834` | `cc8dd568` | `7071e1bff0af` | `7f5da68e` | `3fd51eba`
| 11 | `cc8dd568` | `3fd51eba` | `91cd75e67fe7` | `80b8a96d` | `4c357c05`
| 12 | `3fd51eba` | `4c357c05` | `c56397beabff` | `1a51ac9e` | `2584b224`
| 13 | `4c357c05` | `2584b224` | `3797a5f7dfd3` | `89ce96a0` | `c5fbeaa5`
| 14 | `2584b224` | `c5fbeaa5` | `db10e35fa77b` | `71b54144` | `5431f360`
| 15 | `c5fbeaa5` | `5431f360` | `49aa7bf4d7ff` | `af5ba8ce` | `6aa0426b`
* Catted halves: `6aa0426b5431f360`
* PC-2: `294d8041a87bcf18`

| round | half block | subkey | expanded | e XOR subkey | s-box | p-box |
| ----- | ---------- | ------ | -------- | ------------ | ----- | ----- |
|  0 | `00fe32a0` | `b9c2fcfffd4c` | `0017fc1a5500` | `b9d500e5a84c` | `bbc7a76b` | `c9fb7f8a`
|  1 | `3e3a1a6e` | `a5fc9a5f9eef` | `1fc1f40f435c` | `ba3d6e50ddb3` | `b8ed398c` | `b88933e7`
|  2 | `b8770147` | `762fc2defdf9` | `df03ae802a0f` | `a92c6c5ed7f6` | `6747af6d` | `d971feb8`
|  3 | `e74be4d6` | `7afc112bff7d` | `70ea57f096ad` | `0a1646db69d0` | `4dc35a8a` | `b86fc111`
|  4 | `0018c056` | `4da55efbfdb2` | `0000f16002ac` | `4da5af9bff1e` | `6078bd97` | `3703aaed`
|  5 | `d0484e3b` | `66c49fed4f3f` | `ea025025c1f7` | `8cc6cfc88ec8` | `c3b39926` | `f5c2e524`
|  6 | `f5da2572` | `7f8922df7ade` | `7abef410aba5` | `0537d6cfd17b` | `0015f8b5` | `b7041ca1`
|  7 | `674c529a` | `aaa8bbf5d3fd` | `30ea582a54f4` | `9a42e3df8709` | `874f916a` | `e9d37450`
|  8 | `1c095122` | `89f2c7ffee9c` | `0f8052aa2904` | `86729555c798` | `f132f515` | `27c4eaae`
|  9 | `4088b834` | `315fce7977df` | `2014515f01a8` | `114b9f267677` | `d2094c20` | `d084844a`
| 10 | `cc8dd568` | `7071e1bff0af` | `65945beaab51` | `15e5ba555bfe` | `7a72fd78` | `7f5da68e`
| 11 | `3fd51eba` | `91cd75e67fe7` | `1ffeaa8fd5f4` | `8e33df69aa13` | `c8a907c5` | `80b8a96d`
| 12 | `4c357c05` | `c56397beabff` | `a581aabf800a` | `60e23d012bf5` | `54622d79` | `1a51ac9e`
| 13 | `2584b224` | `3797a5f7dfd3` | `10bc095a4108` | `272bacad9edb` | `e807e02e` | `89ce96a0`
| 14 | `c5fbeaa5` | `db10e35fa77b` | `e0bff7f5550b` | `3baf14aaf270` | `83e8da40` | `71b54144`
| 15 | `5431f360` | `49aa7bf4d7ff` | `2a81a3fa6b00` | `632bd80ebcff` | `587bb55b` | `af5ba8ce`
</details>

## Block 2 (`"e stood "`)
<details><summary></summary>

* Block: `652073746f6f6420`
* PC-1: `7d0c793500ff3034`

| round | left | right | subkey | feistel | feistel XOR left |
| ----- | ---- | ----- | ------ | ------- | ---------------- |
|  0 | `7d0c7935` | `00ff3034` | `b9c2fcfffd4c` | `f29953e2` | `8f952ad7`
|  1 | `00ff3034` | `8f952ad7` | `a5fc9a5f9eef` | `f958dd7e` | `f9a7ed4a`
|  2 | `8f952ad7` | `f9a7ed4a` | `762fc2defdf9` | `0b0ba0b0` | `849e8a67`
|  3 | `f9a7ed4a` | `849e8a67` | `7afc112bff7d` | `e3ca732f` | `1a6d9e65`
|  4 | `849e8a67` | `1a6d9e65` | `4da55efbfdb2` | `bff6eb6e` | `3b686109`
|  5 | `1a6d9e65` | `3b686109` | `66c49fed4f3f` | `a9410109` | `b32c9f6c`
|  6 | `3b686109` | `b32c9f6c` | `7f8922df7ade` | `ecf9b709` | `d791d600`
|  7 | `b32c9f6c` | `d791d600` | `aaa8bbf5d3fd` | `95e4ae73` | `26c8311f`
|  8 | `d791d600` | `26c8311f` | `89f2c7ffee9c` | `4d037dda` | `9a92abda`
|  9 | `26c8311f` | `9a92abda` | `315fce7977df` | `ba8405a9` | `9c4c34b6`
| 10 | `9a92abda` | `9c4c34b6` | `7071e1bff0af` | `260b504b` | `bc99fb91`
| 11 | `9c4c34b6` | `bc99fb91` | `91cd75e67fe7` | `ee488300` | `7204b7b6`
| 12 | `bc99fb91` | `7204b7b6` | `c56397beabff` | `85c99cea` | `3950677b`
| 13 | `7204b7b6` | `3950677b` | `3797a5f7dfd3` | `da6686ec` | `a862315a`
| 14 | `3950677b` | `a862315a` | `db10e35fa77b` | `30ecd91d` | `09bcbe66`
| 15 | `a862315a` | `09bcbe66` | `49aa7bf4d7ff` | `fb2cf770` | `534ec62a`
* Catted halves: `534ec62a09bcbe66`
* PC-2: `c05f3eb9682b562c`

| round | half block | subkey | expanded | e XOR subkey | s-box | p-box |
| ----- | ---------- | ------ | -------- | ------------ | ----- | ----- |
|  0 | `00ff3034` | `b9c2fcfffd4c` | `0017fe9a01a8` | `b9d50265fce4` | `bbcd3854` | `f29953e2`
|  1 | `8f952ad7` | `a5fc9a5f9eef` | `c5fcaa9556af` | `600030cac840` | `5faf9c6d` | `f958dd7e`
|  2 | `f9a7ed4a` | `762fc2defdf9` | `7f3d0ff5aa55` | `0912cd2b57ac` | `4c40a11e` | `0b0ba0b0`
|  3 | `849e8a67` | `7afc112bff7d` | `c094fd45430f` | `ba68ec6ebc72` | `bba79596` | `e3ca732f`
|  4 | `1a6d9e65` | `4da55efbfdb2` | `8f435bcfc30a` | `c2e605343eb8` | `f1bbdf5f` | `bff6eb6e`
|  5 | `3b686109` | `66c49fed4f3f` | `9f6b50302852` | `f9afcfdd676d` | `00c39488` | `a9410109`
|  6 | `b32c9f6c` | `7f8922df7ade` | `5a69594feb59` | `25e07b909187` | `ead717e8` | `ecf9b709`
|  7 | `d791d600` | `aaa8bbf5d3fd` | `6afca3eac001` | `c054181f13fc` | `f41bcba5` | `95e4ae73`
|  8 | `26c8311f` | `89f2c7ffee9c` | `90d6501a28fe` | `192497e5c662` | `17dca52b` | `4d037dda`
|  9 | `9a92abda` | `315fce7977df` | `4f54a5557ef5` | `7e0b6b2c092a` | `80817cbc` | `ba8405a9`
| 10 | `9c4c34b6` | `7071e1bff0af` | `4f82581a95ad` | `3ff3b9a56502` | `195c1492` | `260b504b`
| 11 | `bc99fb91` | `91cd75e67fe7` | `df94f3ff7ca3` | `4e5986190344` | `6a931018` | `ee488300`
| 12 | `7204b7b6` | `c56397beabff` | `3a40095afdac` | `ff239ee45653` | `d85fa425` | `85c99cea`
| 13 | `3950677b` | `3797a5f7dfd3` | `9f2aa030ebf6` | `a8bd05c73425` | `622b6e3e` | `da6686ec`
| 14 | `a862315a` | `db10e35fa77b` | `5503041a2af5` | `8e13e7458d8e` | `cda65e81` | `30ecd91d`
| 15 | `09bcbe66` | `49aa7bf4d7ff` | `053df95fc30c` | `4c9782ab14f3` | `6f8ddb3c` | `fb2cf770`
</details>

## Block 3 (`"on a sli"`)
<details><summary></summary>

* Block: `6f6e206120736c69`
* PC-1: `eb2043a900ffc323`

| round | left | right | subkey | feistel | feistel XOR left |
| ----- | ---- | ----- | ------ | ------- | ---------------- |
|  0 | `eb2043a9` | `00ffc323` | `b9c2fcfffd4c` | `49bf4d69` | `a29f0ec0`
|  1 | `00ffc323` | `a29f0ec0` | `a5fc9a5f9eef` | `b626a649` | `b6d9656a`
|  2 | `a29f0ec0` | `b6d9656a` | `762fc2defdf9` | `e96b1671` | `4bf418b1`
|  3 | `b6d9656a` | `4bf418b1` | `7afc112bff7d` | `149fd240` | `a246b72a`
|  4 | `4bf418b1` | `a246b72a` | `4da55efbfdb2` | `c76b9dac` | `8c9f851d`
|  5 | `a246b72a` | `8c9f851d` | `66c49fed4f3f` | `7cf5e5d2` | `deb352f8`
|  6 | `8c9f851d` | `deb352f8` | `7f8922df7ade` | `1dd0bc7a` | `914f3967`
|  7 | `deb352f8` | `914f3967` | `aaa8bbf5d3fd` | `52238433` | `8c90d6cb`
|  8 | `914f3967` | `8c90d6cb` | `89f2c7ffee9c` | `430faf11` | `d2409676`
|  9 | `8c90d6cb` | `d2409676` | `315fce7977df` | `e5dac4a5` | `694a126e`
| 10 | `d2409676` | `694a126e` | `7071e1bff0af` | `98a076a1` | `4ae0e0d7`
| 11 | `694a126e` | `4ae0e0d7` | `91cd75e67fe7` | `cbdfe01f` | `a295f271`
| 12 | `4ae0e0d7` | `a295f271` | `c56397beabff` | `38148666` | `72f466b1`
| 13 | `a295f271` | `72f466b1` | `3797a5f7dfd3` | `0aa6e9bc` | `a8331bcd`
| 14 | `72f466b1` | `a8331bcd` | `db10e35fa77b` | `93ceee73` | `e13a88c2`
| 15 | `a8331bcd` | `e13a88c2` | `49aa7bf4d7ff` | `26df2cd8` | `8eec3715`
* Catted halves: `8eec3715e13a88c2`
* PC-2: `8566557825b492da`

| round | half block | subkey | expanded | e XOR subkey | s-box | p-box |
| ----- | ---------- | ------ | -------- | ------------ | ----- | ----- |
|  0 | `00ffc323` | `b9c2fcfffd4c` | `8017ffe06906` | `39d5031f944a` | `8bc8c6ef` | `49bf4d69`
|  1 | `a29f0ec0` | `a5fc9a5f9eef` | `5054fe85d601` | `f5a864da48ee` | `60195fb2` | `b626a649`
|  2 | `b6d9656a` | `762fc2defdf9` | `5ad6f2b0ab55` | `2cf9306e56ac` | `2e4f92ae` | `e96b1671`
|  3 | `4bf418b1` | `7afc112bff7d` | `a57fa80f15a2` | `df83b924eadf` | `e95c4842` | `149fd240`
|  4 | `a246b72a` | `4da55efbfdb2` | `50420d5ae955` | `1de753a114e7` | `4af7a637` | `c76b9dac`
|  5 | `8c9f851d` | `66c49fed4f3f` | `c594ffc0a8fb` | `a350602de7c4` | `d7da7b68` | `7cf5e5d2`
|  6 | `deb352f8` | `7f8922df7ade` | `6fd5a6aa57f1` | `105c84752d2f` | `d41e8d6d` | `1dd0bc7a`
|  7 | `914f3967` | `aaa8bbf5d3fd` | `ca2a5e9f2b0f` | `6082e56af8f2` | `56400ab6` | `52238433`
|  8 | `8c90d6cb` | `89f2c7ffee9c` | `c594a16ad657` | `4c66669538cb` | `6ec0c1b3` | `430faf11`
|  9 | `d2409676` | `315fce7977df` | `6a42014ac3ad` | `5b1dcf33b472` | `cb33b0e6` | `e5dac4a5`
| 10 | `694a126e` | `7071e1bff0af` | `352a540a435c` | `455bb5b5b3f3` | `a1052bac` | `98a076a1`
| 11 | `4ae0e0d7` | `91cd75e67fe7` | `a557017016ae` | `349a74966949` | `df63c5da` | `cbdfe01f`
| 12 | `a295f271` | `c56397beabff` | `d054abfa43a3` | `15373c44e85c` | `7028586c` | `38148666`
| 13 | `72f466b1` | `3797a5f7dfd3` | `ba57a830d5a2` | `8dc00dc70a71` | `c5a0671f` | `0aa6e9bc`
| 14 | `a8331bcd` | `db10e35fa77b` | `d501a68f7e5b` | `0e1145d0d920` | `fd0bc9b7` | `93ceee73`
| 15 | `e13a88c2` | `49aa7bf4d7ff` | `7029f5451605` | `39838eb1c1fa` | `8c5a7573` | `26df2cd8`
</details>

## Block 4 (`"ght rise"`)
<details><summary></summary>

* Block: `6768742072697365`
* PC-1: `f75485e100ff2251`

| round | left | right | subkey | feistel | feistel XOR left |
| ----- | ---- | ----- | ------ | ------- | ---------------- |
|  0 | `f75485e1` | `00ff2251` | `b9c2fcfffd4c` | `e19b5141` | `16cfd4a0`
|  1 | `00ff2251` | `16cfd4a0` | `a5fc9a5f9eef` | `8ed80de2` | `8e272fb3`
|  2 | `16cfd4a0` | `8e272fb3` | `762fc2defdf9` | `e63f6a79` | `f0f0bed9`
|  3 | `8e272fb3` | `f0f0bed9` | `7afc112bff7d` | `8350b851` | `0d7797e2`
|  4 | `f0f0bed9` | `0d7797e2` | `4da55efbfdb2` | `ed894af0` | `1d79f429`
|  5 | `0d7797e2` | `1d79f429` | `66c49fed4f3f` | `98f87695` | `958fe177`
|  6 | `1d79f429` | `958fe177` | `7f8922df7ade` | `2e472ca3` | `333ed88a`
|  7 | `958fe177` | `333ed88a` | `aaa8bbf5d3fd` | `f34042a8` | `66cfa3df`
|  8 | `333ed88a` | `66cfa3df` | `89f2c7ffee9c` | `eef749d9` | `ddc99153`
|  9 | `66cfa3df` | `ddc99153` | `315fce7977df` | `28c7fbe4` | `4e08583b`
| 10 | `ddc99153` | `4e08583b` | `7071e1bff0af` | `a209674f` | `7fc0f61c`
| 11 | `4e08583b` | `7fc0f61c` | `91cd75e67fe7` | `b2cf008f` | `fcc758b4`
| 12 | `7fc0f61c` | `fcc758b4` | `c56397beabff` | `dcb72627` | `a377d03b`
| 13 | `fcc758b4` | `a377d03b` | `3797a5f7dfd3` | `05ec7324` | `f92b2b90`
| 14 | `a377d03b` | `f92b2b90` | `db10e35fa77b` | `b738f518` | `144f2523`
| 15 | `f92b2b90` | `144f2523` | `49aa7bf4d7ff` | `24ab8f82` | `dd80a412`
* Catted halves: `dd80a412144f2523`
* PC-2: `6a23ec60c10e6054`

| round | half block | subkey | expanded | e XOR subkey | s-box | p-box |
| ----- | ---------- | ------ | -------- | ------------ | ----- | ----- |
|  0 | `00ff2251` | `b9c2fcfffd4c` | `8017fe9042a2` | `39d5026fbfee` | `8bcd90c2` | `e19b5141`
|  1 | `16cfd4a0` | `a5fc9a5f9eef` | `0ad65fea9500` | `af2ac5b50bef` | `989b207d` | `8ed80de2`
|  2 | `8e272fb3` | `762fc2defdf9` | `c5c10e95fda7` | `b3eecc4b005e` | `2f5957d7` | `e63f6a79`
|  3 | `f0f0bed9` | `7afc112bff7d` | `fa17a15fd6f3` | `80ebb074298e` | `440f81d1` | `8350b851`
|  4 | `0d7797e2` | `4da55efbfdb2` | `05abafcaff04` | `480ef13102b6` | `af59b00d` | `ed894af0`
|  5 | `1d79f429` | `66c49fed4f3f` | `8fabf3fa8152` | `e96f6c17ce6d` | `ad272be8` | `98f87695`
|  6 | `958fe177` | `7f8922df7ade` | `cabc5ff02baf` | `b5357d2f5171` | `105271bf` | `2e472ca3`
|  7 | `333ed88a` | `aaa8bbf5d3fd` | `1a69fd6f1454` | `b0c1469ac7a9` | `2303bc14` | `f34042a8`
|  8 | `66cfa3df` | `89f2c7ffee9c` | `b0d65fd07efe` | `3924982f9062` | `87db76db` | `eef749d9`
|  9 | `ddc99153` | `315fce7977df` | `efbe53ca2aa7` | `dee19db35d78` | `e1ee710f` | `28c7fbe4`
| 10 | `4e08583b` | `7071e1bff0af` | `a5c0502f01f6` | `d5b1b190f159` | `39e915b0` | `a209674f`
| 11 | `7fc0f61c` | `91cd75e67fe7` | `3ffe017ac0f8` | `ae33749cbf1f` | `98637c92` | `b2cf008f`
| 12 | `fcc758b4` | `c56397beabff` | `7f960eaf15a9` | `baf59911be56` | `b2714bee` | `dcb72627`
| 13 | `a377d03b` | `3797a5f7dfd3` | `d06bafea01f7` | `e7fc0a1dde24` | `a9b6c304` | `05ec7324`
| 14 | `f92b2b90` | `db10e35fa77b` | `7f2956957ca1` | `a439b5cadbda` | `4d959f70` | `b738f518`
| 15 | `144f2523` | `49aa7bf4d7ff` | `8a825e90a906` | `c32825647ef9` | `f8d03223` | `24ab8f82`
</details>

## Block 5 (`" just on"`)
<details><summary></summary>

* Block: `206a757374206f6e`
* PC-1: `de1cd44c00ffc2ca`

| round | left | right | subkey | feistel | feistel XOR left |
| ----- | ---- | ----- | ------ | ------- | ---------------- |
|  0 | `de1cd44c` | `00ffc2ca` | `b9c2fcfffd4c` | `539d6f6a` | `8d81bb26`
|  1 | `00ffc2ca` | `8d81bb26` | `a5fc9a5f9eef` | `881e2e0a` | `88e1ecc0`
|  2 | `8d81bb26` | `88e1ecc0` | `762fc2defdf9` | `dbb21ff6` | `5633a4d0`
|  3 | `88e1ecc0` | `5633a4d0` | `7afc112bff7d` | `196ddbd1` | `918c3711`
|  4 | `5633a4d0` | `918c3711` | `4da55efbfdb2` | `8ae582ab` | `dcd6267b`
|  5 | `918c3711` | `dcd6267b` | `66c49fed4f3f` | `323350ae` | `a3bf67bf`
|  6 | `dcd6267b` | `a3bf67bf` | `7f8922df7ade` | `219a7502` | `fd4c5379`
|  7 | `a3bf67bf` | `fd4c5379` | `aaa8bbf5d3fd` | `a3c9d840` | `0076bfff`
|  8 | `fd4c5379` | `0076bfff` | `89f2c7ffee9c` | `9b62ccd1` | `662e9fa8`
|  9 | `0076bfff` | `662e9fa8` | `315fce7977df` | `e3e49734` | `e39228cb`
| 10 | `662e9fa8` | `e39228cb` | `7071e1bff0af` | `eb7fed75` | `8d5172dd`
| 11 | `e39228cb` | `8d5172dd` | `91cd75e67fe7` | `4f88b4f1` | `ac1a9c3a`
| 12 | `8d5172dd` | `ac1a9c3a` | `c56397beabff` | `18d3ba3d` | `9582c8e0`
| 13 | `ac1a9c3a` | `9582c8e0` | `3797a5f7dfd3` | `7ac04c59` | `d6dad063`
| 14 | `9582c8e0` | `d6dad063` | `db10e35fa77b` | `a5b47f3f` | `3036b7df`
| 15 | `d6dad063` | `3036b7df` | `49aa7bf4d7ff` | `d7a55c8f` | `017f8cec`
* Catted halves: `017f8cec3036b7df`
* PC-2: `5a3a3f17bab9130f`

| round | half block | subkey | expanded | e XOR subkey | s-box | p-box |
| ----- | ---------- | ------ | -------- | ------------ | ----- | ----- |
|  0 | `00ffc2ca` | `b9c2fcfffd4c` | `0017ffe05654` | `b9d5031fab18` | `bbc8cd75` | `539d6f6a`
|  1 | `8d81bb26` | `a5fc9a5f9eef` | `45bc03df690d` | `e0409980f7e2` | `3801456b` | `881e2e0a`
|  2 | `88e1ecc0` | `762fc2defdf9` | `451703f59601` | `3338c12b6bf8` | `b6adaa7f` | `dbb21ff6`
|  3 | `5633a4d0` | `7afc112bff7d` | `2ac1a7d096a0` | `503db6fb69dd` | `6dceea89` | `196ddbd1`
|  4 | `918c3711` | `4da55efbfdb2` | `ca3c581ae8a3` | `879906e11511` | `f043669c` | `8ae582ab`
|  5 | `dcd6267b` | `66c49fed4f3f` | `ef96ac10c3f7` | `895233fd8cc8` | `11643e56` | `323350ae`
|  6 | `a3bf67bf` | `7f8922df7ade` | `d07dfeb0fdff` | `aff4dc6f8721` | `99849162` | `219a7502`
|  7 | `fd4c5379` | `aaa8bbf5d3fd` | `ffaa582a6bf3` | `5502e3dfb80e` | `c94f9011` | `a3c9d840`
|  8 | `0076bfff` | `89f2c7ffee9c` | `8003ad5ffffe` | `09f16aa01162` | `450baabb` | `9b62ccd1`
|  9 | `662e9fa8` | `315fce7977df` | `30c15d4ffd50` | `019e93368a8f` | `e6a7d234` | `e3e49734`
| 10 | `e39228cb` | `7071e1bff0af` | `f07ca4151657` | `800d45aae6f8` | `4febd3ff` | `eb7fed75`
| 11 | `8d5172dd` | `91cd75e67fe7` | `c5aaa2ba56fb` | `5467d75c291c` | `ce1ca1bc` | `4f88b4f1`
| 12 | `ac1a9c3a` | `c56397beabff` | `5580f54f81f5` | `90e362f12a0a` | `e4660dcf` | `18d3ba3d`
| 13 | `9582c8e0` | `3797a5f7dfd3` | `4abc05651701` | `7d2ba092c8d2` | `870a1cb9` | `7ac04c59`
| 14 | `d6dad063` | `db10e35fa77b` | `ead6f56a0307` | `31c61635a47c` | `b5b5d7e5` | `a5b47f3f`
| 15 | `3036b7df` | `49aa7bf4d7ff` | `9a01ad5afefe` | `d3abd6ae2901` | `9375eeb1` | `d7a55c8f`
</details>

## Block 6 (`" the edg"`)
<details><summary></summary>

* Block: `2074686520656467`
* PC-1: `ee02eaa800ff0480`

| round | left | right | subkey | feistel | feistel XOR left |
| ----- | ---- | ----- | ------ | ------- | ---------------- |
|  0 | `ee02eaa8` | `00ff0480` | `b9c2fcfffd4c` | `dabf5bc3` | `34bdb16b`
|  1 | `00ff0480` | `34bdb16b` | `a5fc9a5f9eef` | `f7732d92` | `f78c2912`
|  2 | `34bdb16b` | `f78c2912` | `762fc2defdf9` | `3f999262` | `0b242309`
|  3 | `f78c2912` | `0b242309` | `7afc112bff7d` | `88b58daa` | `7f39a4b8`
|  4 | `0b242309` | `7f39a4b8` | `4da55efbfdb2` | `d53254d0` | `de1677d9`
|  5 | `7f39a4b8` | `de1677d9` | `66c49fed4f3f` | `0e1a5c02` | `7123f8ba`
|  6 | `de1677d9` | `7123f8ba` | `7f8922df7ade` | `3aa423ad` | `e4b25474`
|  7 | `7123f8ba` | `e4b25474` | `aaa8bbf5d3fd` | `a31aaa47` | `d23952fd`
|  8 | `e4b25474` | `d23952fd` | `89f2c7ffee9c` | `b737f9b7` | `5385adc3`
|  9 | `d23952fd` | `5385adc3` | `315fce7977df` | `81ec01cd` | `53d55330`
| 10 | `5385adc3` | `53d55330` | `7071e1bff0af` | `82c094e5` | `d1453926`
| 11 | `53d55330` | `d1453926` | `91cd75e67fe7` | `7f59757d` | `2c8c264d`
| 12 | `d1453926` | `2c8c264d` | `c56397beabff` | `cf5ea2b9` | `1e1b9b9f`
| 13 | `2c8c264d` | `1e1b9b9f` | `3797a5f7dfd3` | `0ce50397` | `206925da`
| 14 | `1e1b9b9f` | `206925da` | `db10e35fa77b` | `f7bde0e1` | `e9a67b7e`
| 15 | `206925da` | `e9a67b7e` | `49aa7bf4d7ff` | `e54b4557` | `c522608d`
* Catted halves: `c522608de9a67b7e`
* PC-2: `c93a638b0abecee1`

| round | half block | subkey | expanded | e XOR subkey | s-box | p-box |
| ----- | ---------- | ------ | -------- | ------------ | ----- | ----- |
|  0 | `00ff0480` | `b9c2fcfffd4c` | `0017fe809400` | `b9d5027f694c` | `bbcd6adb` | `dabf5bc3`
|  1 | `34bdb16b` | `a5fc9a5f9eef` | `9a95fbda2b56` | `3f696185b5b9` | `16d3bb73` | `f7732d92`
|  2 | `f78c2912` | `762fc2defdf9` | `7afc581528a5` | `0cd39acbd55c` | `f85c985c` | `3f999262`
|  3 | `0b242309` | `7afc112bff7d` | `856908106852` | `ff95193b972f` | `d0c1666d` | `88b58daa`
|  4 | `7f39a4b8` | `4da55efbfdb2` | `3fe9f3d095f0` | `724cad2b6842` | `071daa62` | `d53254d0`
|  5 | `de1677d9` | `66c49fed4f3f` | `efc0ac3afef3` | `890433d7b1cc` | `1914007b` | `0e1a5c02`
|  6 | `7123f8ba` | `7f8922df7ade` | `3a2907ff15f4` | `45a025206f2a` | `a0a07f9c` | `3aa423ad`
|  7 | `e4b25474` | `aaa8bbf5d3fd` | `7095a42a83a9` | `da3d1fdf5054` | `782991d3` | `a31aaa47`
|  8 | `d23952fd` | `89f2c7ffee9c` | `ea41f2aa57fb` | `63b33555b967` | `55f5fbd7` | `b737f9b7`
|  9 | `5385adc3` | `315fce7977df` | `aa7c0bd5be06` | `9b23c5acc9d9` | `88abe680` | `81ec01cd`
| 10 | `53d55330` | `7071e1bff0af` | `2a7eaaaa69a0` | `5a0f4b15990f` | `c02f20b4` | `82c094e5`
| 11 | `d1453926` | `91cd75e67fe7` | `6a2a0a9f290d` | `fbe77f7956ea` | `0ffe9dfc` | `7f59757d`
| 12 | `2c8c264d` | `c56397beabff` | `95945810c25a` | `50f7cfae69a5` | `6e13e5de` | `cf5ea2b9`
| 13 | `1e1b9b9f` | `3797a5f7dfd3` | `8fc0f7cf7cfe` | `b8575238a32d` | `b4f26288` | `0ce50397`
| 14 | `206925da` | `db10e35fa77b` | `10035290bef4` | `cb13b1cf198f` | `cb59fbd4` | `f7bde0e1`
| 15 | `e9a67b7e` | `49aa7bf4d7ff` | `753d0c3f6bfd` | `3c9777cbbc02` | `1ffb90a2` | `e54b4557`
</details>

## Block 7 (`"e of the"`)
<details><summary></summary>

* Block: `65206f6620746865`
* PC-1: `ed20ad8500ff440c`

| round | left | right | subkey | feistel | feistel XOR left |
| ----- | ---- | ----- | ------ | ------- | ---------------- |
|  0 | `ed20ad85` | `00ff440c` | `b9c2fcfffd4c` | `c1bb7fca` | `2c9bd24f`
|  1 | `00ff440c` | `2c9bd24f` | `a5fc9a5f9eef` | `ceba3ef3` | `ce457aff`
|  2 | `2c9bd24f` | `ce457aff` | `762fc2defdf9` | `65bce23d` | `49273072`
|  3 | `ce457aff` | `49273072` | `7afc112bff7d` | `f29d03d2` | `3cd8792d`
|  4 | `49273072` | `3cd8792d` | `4da55efbfdb2` | `9e8d3cc2` | `d7aa0cb0`
|  5 | `3cd8792d` | `d7aa0cb0` | `66c49fed4f3f` | `b2cafef2` | `8e1287df`
|  6 | `d7aa0cb0` | `8e1287df` | `7f8922df7ade` | `e6867792` | `312c7b22`
|  7 | `8e1287df` | `312c7b22` | `aaa8bbf5d3fd` | `e5523b58` | `6b40bc87`
|  8 | `312c7b22` | `6b40bc87` | `89f2c7ffee9c` | `cb684d96` | `fa4436b4`
|  9 | `6b40bc87` | `fa4436b4` | `315fce7977df` | `bd5cea3c` | `d61c56bb`
| 10 | `fa4436b4` | `d61c56bb` | `7071e1bff0af` | `d79c6938` | `2dd85f8c`
| 11 | `d61c56bb` | `2dd85f8c` | `91cd75e67fe7` | `fff3ca5b` | `29ef9ce0`
| 12 | `2dd85f8c` | `29ef9ce0` | `c56397beabff` | `0f972996` | `224f761a`
| 13 | `29ef9ce0` | `224f761a` | `3797a5f7dfd3` | `c2eb9b3d` | `eb0407dd`
| 14 | `224f761a` | `eb0407dd` | `db10e35fa77b` | `8b106ba5` | `a95f1dbf`
| 15 | `eb0407dd` | `a95f1dbf` | `49aa7bf4d7ff` | `f9700a71` | `12740dac`
* Catted halves: `12740daca95f1dbf`
* PC-2: `ae623faf7a933083`

| round | half block | subkey | expanded | e XOR subkey | s-box | p-box |
| ----- | ---------- | ------ | -------- | ------------ | ----- | ----- |
|  0 | `00ff440c` | `b9c2fcfffd4c` | `0017fea08058` | `b9d5025f7d14` | `bbcda763` | `c1bb7fca`
|  1 | `2c9bd24f` | `a5fc9a5f9eef` | `9594f7ea425e` | `30686db5dcb1` | `be1d23ff` | `ceba3ef3`
|  2 | `ce457aff` | `762fc2defdf9` | `e5c20abf57ff` | `93edc861aa06` | `ef30d7c4` | `65bce23d`
|  3 | `49273072` | `7afc112bff7d` | `25290e9a03a4` | `5fd51fb1fcd9` | `bec97850` | `f29d03d2`
|  4 | `3cd8792d` | `4da55efbfdb2` | `9f96f03f295a` | `d233aec4d4e8` | `985d6939` | `9e8d3cc2`
|  5 | `d7aa0cb0` | `66c49fed4f3f` | `6afd540595a1` | `0c39cbe8da9e` | `fd0f3937` | `b2cafef2`
|  6 | `8e1287df` | `7f8922df7ade` | `c5c0a540feff` | `ba49879f8421` | `b7957132` | `e6867792`
|  7 | `312c7b22` | `aaa8bbf5d3fd` | `1a29583f6904` | `b081e3cabaf9` | `269f9543` | `e5523b58`
|  8 | `6b40bc87` | `89f2c7ffee9c` | `b56a015f940e` | `3c98c6a07a92` | `1fa3a239` | `cb684d96`
|  9 | `fa4436b4` | `315fce7977df` | `7f42081ad5a9` | `4e1dc663a276` | `6d33dd4d` | `bd5cea3c`
| 10 | `d61c56bb` | `7071e1bff0af` | `eac0f82ad5f7` | `9ab119952558` | `8f91cd55` | `d79c6938`
| 11 | `2dd85f8c` | `91cd75e67fe7` | `15bef02ffc58` | `847385c983bf` | `f75b9edb` | `fff3ca5b`
| 12 | `29ef9ce0` | `c56397beabff` | `153f5fcf9700` | `d05cc8713cff` | `94f0e15b` | `0f972996`
| 13 | `224f761a` | `3797a5f7dfd3` | `10425ebac0f4` | `27d5fb4d1f27` | `eee70697` | `c2eb9b3d`
| 14 | `eb0407dd` | `db10e35fa77b` | `f5680800fefb` | `2e78eb5f5980` | `21a1a1dd` | `8b106ba5`
| 15 | `a95f1dbf` | `49aa7bf4d7ff` | `d52afe8fbdff` | `9c80857b6a00` | `260b9acd` | `f9700a71`
</details>

## Block 8 (`" village"`)
<details><summary></summary>

* Block: `2076696c6c616765`
* PC-1: `fe02dae400ff1c42`

| round | left | right | subkey | feistel | feistel XOR left |
| ----- | ---- | ----- | ------ | ------- | ---------------- |
|  0 | `fe02dae4` | `00ff1c42` | `b9c2fcfffd4c` | `c3af57e2` | `3dad8d06`
|  1 | `00ff1c42` | `3dad8d06` | `a5fc9a5f9eef` | `e7b07fd3` | `e74f6391`
|  2 | `3dad8d06` | `e74f6391` | `762fc2defdf9` | `27a9d617` | `1a045b11`
|  3 | `e74f6391` | `1a045b11` | `7afc112bff7d` | `853ee78c` | `6271841d`
|  4 | `1a045b11` | `6271841d` | `4da55efbfdb2` | `44eea1ae` | `5eeafabf`
|  5 | `6271841d` | `5eeafabf` | `66c49fed4f3f` | `20d8991c` | `42a91d01`
|  6 | `5eeafabf` | `42a91d01` | `7f8922df7ade` | `fac9b2f1` | `a423484e`
|  7 | `42a91d01` | `a423484e` | `aaa8bbf5d3fd` | `745a2db1` | `36f330b0`
|  8 | `a423484e` | `36f330b0` | `89f2c7ffee9c` | `b6d98ea0` | `12fac6ee`
|  9 | `36f330b0` | `12fac6ee` | `315fce7977df` | `aee37d39` | `98104d89`
| 10 | `12fac6ee` | `98104d89` | `7071e1bff0af` | `b338bafa` | `a1c27c14`
| 11 | `98104d89` | `a1c27c14` | `91cd75e67fe7` | `b285ce56` | `2a9583df`
| 12 | `a1c27c14` | `2a9583df` | `c56397beabff` | `122ceadd` | `b3ee96c9`
| 13 | `2a9583df` | `b3ee96c9` | `3797a5f7dfd3` | `eb1c1925` | `c1899afa`
| 14 | `b3ee96c9` | `c1899afa` | `db10e35fa77b` | `a6c83e4b` | `1526a882`
| 15 | `c1899afa` | `1526a882` | `49aa7bf4d7ff` | `01417eff` | `c0c8e405`
* Catted halves: `c0c8e4051526a882`
* PC-2: `8122a518802c545e`

| round | half block | subkey | expanded | e XOR subkey | s-box | p-box |
| ----- | ---------- | ------ | -------- | ------------ | ----- | ----- |
|  0 | `00ff1c42` | `b9c2fcfffd4c` | `0017fe8f8204` | `b9d502707f48` | `bbcde236` | `c3af57e2`
|  1 | `3dad8d06` | `a5fc9a5f9eef` | `1fbd5bc5a80c` | `ba41c19a36e3` | `b79db3f1` | `e7b07fd3`
|  2 | `e74f6391` | `762fc2defdf9` | `f0ea5eb07ca3` | `86c59c6e815a` | `fd7492b0` | `27a9d617`
|  3 | `1a045b11` | `7afc112bff7d` | `8f40082f68a2` | `f5bc190497df` | `69b1e762` | `853ee78c`
|  4 | `6271841d` | `4da55efbfdb2` | `b043a3c080fa` | `fde6fd3b7d48` | `dab26706` | `44eea1ae`
|  5 | `5eeafabf` | `66c49fed4f3f` | `afd7557f55fe` | `c913ca921ac1` | `cca61441` | `20d8991c`
|  6 | `42a91d01` | `7f8922df7ade` | `a055528fa802` | `dfdc7050d2dc` | `ee4f399c` | `fac9b2f1`
|  7 | `a423484e` | `aaa8bbf5d3fd` | `508106a5025d` | `fa29bd50d1a0` | `0e9239e7` | `745a2db1`
|  8 | `36f330b0` | `89f2c7ffee9c` | `1ad7a69a15a0` | `93256165fb3c` | `e8533875` | `b6d98ea0`
|  9 | `12fac6ee` | `315fce7977df` | `0a57f560d75c` | `3b083b19a083` | `85d717bf` | `aee37d39`
| 10 | `98104d89` | `7071e1bff0af` | `cf00a025bc53` | `bf71419a4cfc` | `7c0dbf55` | `b338bafa`
| 11 | `a1c27c14` | `91cd75e67fe7` | `503e043f80a9` | `c1f371d9ff4e` | `f5695831` | `b285ce56`
| 12 | `2a9583df` | `c56397beabff` | `9554abc07efe` | `50373c7ed501` | `6d286f91` | `122ceadd`
| 13 | `b3ee96c9` | `3797a5f7dfd3` | `da7f5d4ad653` | `ede8f8bd0980` | `0aa5d0dd` | `eb1c1925`
| 14 | `c1899afa` | `db10e35fa77b` | `603c53cf57f5` | `bb2cb090f08e` | `b81f15b1` | `a6c83e4b`
| 15 | `1526a882` | `49aa7bf4d7ff` | `0aa90d551404` | `430376a1c3fb` | `356ea5a5` | `01417eff`
</details>

## Block 9 (`"."`)
<details><summary></summary>

In the last block, because there is only 1 byte of message left, you pad the rest of the bytes in the block with the number of bytes which are empty (in this case, 7, `0x07`).

* Block: `2e07070707070707`
* PC-1: `0000fffe000101ff`

| round | left | right | subkey | feistel | feistel XOR left |
| ----- | ---- | ----- | ------ | ------- | ---------------- |
|  0 | `0000fffe` | `000101ff` | `b9c2fcfffd4c` | `10a770b0` | `10a78f4e`
|  1 | `000101ff` | `10a78f4e` | `a5fc9a5f9eef` | `7dd841bb` | `7dd94044`
|  2 | `10a78f4e` | `7dd94044` | `762fc2defdf9` | `dcf61bf1` | `cc5194bf`
|  3 | `7dd94044` | `cc5194bf` | `7afc112bff7d` | `820e079c` | `ffd747d8`
|  4 | `cc5194bf` | `ffd747d8` | `4da55efbfdb2` | `efef3aee` | `23beae51`
|  5 | `ffd747d8` | `23beae51` | `66c49fed4f3f` | `5d49fb11` | `a29ebcc9`
|  6 | `23beae51` | `a29ebcc9` | `7f8922df7ade` | `d69e0c77` | `f520a226`
|  7 | `a29ebcc9` | `f520a226` | `aaa8bbf5d3fd` | `62c94117` | `c057fdde`
|  8 | `f520a226` | `c057fdde` | `89f2c7ffee9c` | `069353d9` | `f3b3f1ff`
|  9 | `c057fdde` | `f3b3f1ff` | `315fce7977df` | `06ce886c` | `c69975b2`
| 10 | `f3b3f1ff` | `c69975b2` | `7071e1bff0af` | `c9fffda2` | `3a4c0c5d`
| 11 | `c69975b2` | `3a4c0c5d` | `91cd75e67fe7` | `d89dbfce` | `1e04ca7c`
| 12 | `3a4c0c5d` | `1e04ca7c` | `c56397beabff` | `aee59058` | `94a99c05`
| 13 | `1e04ca7c` | `94a99c05` | `3797a5f7dfd3` | `00ddd8eb` | `1ed91297`
| 14 | `94a99c05` | `1ed91297` | `db10e35fa77b` | `5482d525` | `c02b4920`
| 15 | `1ed91297` | `c02b4920` | `49aa7bf4d7ff` | `bc8096c6` | `a2598451`
* Catted halves: `a2598451c02b4920`
* PC-2: `39600438116299c4`

| round | half block | subkey | expanded | e XOR subkey | s-box | p-box |
| ----- | ---------- | ------ | -------- | ------------ | ----- | ----- |
|  0 | `000101ff` | `b9c2fcfffd4c` | `800002803ffe` | `39c2fe7fc2b2` | `85446b06` | `10a770b0`
|  1 | `10a78f4e` | `a5fc9a5f9eef` | `0a150fc5ea5c` | `afe9959a74b3` | `9f92bccc` | `7dd841bb`
|  2 | `7dd94044` | `762fc2defdf9` | `3fbef2a00208` | `4991307efff1` | `a69f6acf` | `dcf61bf1`
|  3 | `cc5194bf` | `7afc112bff7d` | `e582a3ca95ff` | `9f7eb2e16a82` | `2ca16432` | `820e079c`
|  4 | `ffd747d8` | `4da55efbfdb2` | `7ffeaea0fef1` | `325bf05b0343` | `ba7ff71f` | `efef3aee`
|  5 | `23beae51` | `66c49fed4f3f` | `907dfd55c2a2` | `f6b962b88d9d` | `6fd68989` | `5d49fb11`
|  6 | `a29ebcc9` | `7f8922df7ade` | `d054fd5f9653` | `afdddf80ec8d` | `9e3948f7` | `d69e0c77`
|  7 | `f520a226` | `aaa8bbf5d3fd` | `7aa90150410d` | `d001baa592f0` | `9fe21090` | `62c94117`
|  8 | `c057fdde` | `89f2c7ffee9c` | `6002afffbefd` | `e9f068005061` | `a5dc24d2` | `069353d9`
|  9 | `f3b3f1ff` | `315fce7977df` | `fa7da7fa3fff` | `cb2269834820` | `c83a4417` | `06ce886c`
| 10 | `c69975b2` | `7071e1bff0af` | `60d4f2babda5` | `10a513054d0a` | `dbc7e36f` | `c9fffda2`
| 11 | `3a4c0c5d` | `91cd75e67fe7` | `9f42580582fa` | `0e8f2de3fd1d` | `faed6d69` | `d89dbfce`
| 12 | `1e04ca7c` | `c56397beabff` | `0fc0096543f8` | `caa39edbe807` | `c45f5618` | `aee59058`
| 13 | `94a99c05` | `3797a5f7dfd3` | `ca9553cf800b` | `fd02f6385fd8` | `d94e64c5` | `00ddd8eb`
| 14 | `1ed91297` | `db10e35fa77b` | `8fd6f28a54ae` | `54c611d5f3d5` | `c3b408a6` | `5482d525`
| 15 | `c02b4920` | `49aa7bf4d7ff` | `600156a52901` | `29ab2d51fefe` | `f03d3828` | `bc8096c6`
</details>
