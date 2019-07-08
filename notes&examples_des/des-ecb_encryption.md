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

## Block 1 (`"The hous"`)
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
</details>
