# Algorithms
Mine has the following algorithms.
$ mkdir markdown-it-multimd-table
$ cd markdown-it-multimd-table
$ npm install markdown-it-multimd-table --prefix .
$ vim test.js

    var md = require('markdown-it')()
                .use(require('markdown-it-multimd-table'));

    const exampleTable =
    "|             |          Grouping           || \n" +
    "First Header  | Second Header | Third Header | \n" +
    " ------------ | :-----------: | -----------: | \n" +
    "Content       |          *Long Cell*        || \n" +
    "Content       |   **Cell**    |         Cell | \n" +
    "                                               \n" +
    "New section   |     More      |         Data | \n" +
    "And more      | With an escaped '\\|'       || \n" +
    "[Prototype table]                              \n";

    console.log(md.render(exampleTable));

$ node test.js > test.html
$ firefox test.html

<table>
  <tr>
    <th text-align=right>Algorithm</th>
    <th>Digest size</th>
    <th>Block size</th>
    <th>Words</th>
    <th>Rounds</th>
    <th>Checksum</th>
  </tr>
  <tr>
    <td>MD5</td>
    <td>128 bits<br>(4 * 32-bits)</td>
    <td>512 bits</td>
    <td>16 (32-bits each)</td>
    <td>64</td>
    <td>32 chars<br>(128 / 4)</td>
  </tr>
  <tr>
    <td>SHA-256</td>
    <td rowspan=2>256 bits<br>(8 * 32-bits)</td>
    <td rowspan=2>512 bits</td>
    <td rowspan=2>64 (32-bits each)</td>
    <td rowspan=2>64</td>
    <td>64 chars<br>(256 / 4)</td>
  </tr>
  <tr>
    <td>SHA-224</td>
    <td>56 chars<br>(224 / 4)</td>
  </tr>
  <tr>
    <td>SHA-1</td>
    <td>160 bits<br>(5 * 32-bits)</td>
    <td>512 bits</td>
    <td>80 (32-bits each)</td>
    <td>80</td>
    <td>40 chars<br>(160 / 4)</td>
  </tr>
  <tr>
    <td>SHA-512</td>
    <td rowspan=2>512 bits<br>(8 * 64-bits)</td>
    <td rowspan=2>1024 bits</td>
    <td rowspan=2>80 (64-bits each)</td>
    <td rowspan=2>80</td>
    <td>128 chars<br>(512 / 4)</td>
  </tr>
  <tr>
    <td>SHA-384</td>
    <td>96 chars<br>(384 / 4)</td>
  </tr>
</table>

SHA-224 is a variant of SHA-256, and SHA-384 is a variant of SHA-512. They're just the same as their root algorithms, except:
1. The internal state has different initialization values.
2. It the same size digest all the way through, but at the very end, these variants only take a portion of that for the checksum output. SHA-224 uses the first 224 of 256 bits. SHA-384 uses the first 284 of 512-bits. The rest are discarded.

# Terminology
* The **message** is the input.
    * The **padded message** is the message with padding added to the end so that it is of a length that divides neatly into the block size.
    * The **block** is a portion of the padded message.
    * The **words** are the block, usually after undergoing a transformation. Typically the first 16 words are just the block, and the rest are derived from those first 16. This is the form of the block used by the compression function.
* The **digest** is the bitfield that is transformed throughout the algorithm. Because it's ever-changing, it's a somewhat vague term. Also sometimes called the **hash**.
    * The **internal state** is the part that is initialized at the beginning, and then added to after each compression of a data block.
    * The **checksum** is the output; the final internal state, converted to hexadecimal.
* The **compression function** is the real guts of a cryptographic hashing algorithm. It runs once per block of message. It takes in the current internal state, and a set of words (ie the block). It spits out a set of numbers which are then added back into the internal state.
    * The **rounds** are the sets of transformations that happen each time the compression function is run.

### Not really terminology, but naming conventions
* The internal state is usually an array called `h[]`. ("h" for "hash".)
* The working variables inside the compression function are typically lettered: `a`, `b`, `c`, `d`, ect.
* `k[]` is an array of constants used within the compression function. (Possibly `k` for "key"? Or `k` as a phonetic version of "constant," since `c` is already a working variable?)
* The words are sometimes seen called `w[]` and sometimes `m[]`. (`m` for "message," but since they've been transformed by this point, I think `w` for "words" is a clearer name.)
