# joinby
A little bin to convert whitespaces to commas (via command line or pipes)

## Usage

Once the bin is built and in your `$PATH`, the `joinby` command can by run 2 different ways:

```bash
# Usage #1:
$ joinby [char] [args...]

# Usage #2
$ ... | joinby [char]
```


The following examples will produce the same result:

```bash
$ joinby ',' this will be joined by commas

# and

$ echo "this will be joined by commas" | joinby ','

# Output:
this,will,be,joined,by,commas
```

## Installation

Build the `joinby.cpp` file using any compiler with c++17. 

For MacOS with `clang++`, this command may work:

```bash
clang++ -std=c++17 -stdlib=libc++ -Wall -pedantic joinby.cpp -o joinby
```

Then copy the bin to `/usr/local/bin`

```bash
mv joinby /usr/local/bin
```
