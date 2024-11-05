# Hello World in 64-bit Assembly

## Prerequisites

- Linux

## Installing dependencies

### Debian based distributions

```sh
sudo apt-get install binutils nasm
```

### Arch Linux based distributions

```sh
sudo pacman -S binutils nasm
```

## Enable syntax highlighting in [juCi++](https://gitlab.com/cppit/jucipp)

```sh
git clone https://gitlab.com/ntnu-tdat3020/assembly-example
sudo cp assembly-example/asm-intel.lang /usr/share/gtksourceview-3.0/language-specs/
juci assembly-example
```

## Compiling and running

The `-f elf64` flag below tells the compiler that the source uses 64-bit instructions

### Alternative 1

In a terminal:

```sh
cd assembly-example
nasm -f elf64 hello.s  # Compile source to object file that contains machine code
                       # and usually also references to functions or variables found
                       # in other object files or libraries.
ld hello.o -o hello    # Link object file and create executable. Normally,
                       # the machine code of several object files are here combined into
                       # one executable, but references to dynamic libraries are kept.
./hello                # Run executable
```

### Alternative 2 using [juCi++](https://gitlab.com/cppit/jucipp)

Choose Run Command in the Project menu, and run the following command:

```sh
nasm -f elf64 hello.s && ld hello.o -o hello && ./hello
```

Note: if you make changes to the `hello.s` source file, remember to save it before running the above command.

---

You can also instead add the following command object to Commands in the juCi++ menu:

```json
{
  "key": "<primary>Return",
  "path": "^.*\\.s$",
  "compile": "nasm -f elf64 <path_match> && ld `basename -s .s <path_match>`.o -o `basename -s .s <path_match>`",
  "run": "./`basename -s .s <path_match>`"
}
```

And compile and run using Ctrl+Return.
