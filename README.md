# Lisp in C

Lisp in C (pronounced Lye-sp) is a tribute to ANSI Common Lisp but
without the object-oriented or functional features. This is a dynamically typed and interpreted language. It is however, still a work-in-progress.
Check out the TODOs below.

> The only exception to the CMake configuration is the `TESTONLY.c` file which
> utilises the `mpc.c` Micro Parser Combinator Library. The remaining files utilise self-written code or code from [BYOL](https://www.buildyourownlisp.com/). 

> **Linguistics Notes** : This language, as of now, has no defined formal grammar but rather imitates that of the `bash` command language with
> modified keywords.


## Instructions

The program for now can ONLY be executed in a **UNIX-based** machine such as Linux, MacOS or WSL.

#### Requirements

- Minimum `gcc 11.4.0` or `clang version 14.0.0`
- Editline library:
  - Can be installed with `apt install editline` on Ubuntu.

### Execution

**For terminal based code (interactive mode)**
```shell
./unix.sh
```

**For script-based code (script mode)**
```shell
./unix.sh your_file_name.extension
```

### This is a work-in-progress not a final product.

Currently, the following functions work:

- Own terminal window with `consout`, `clear` and `terminate` keywords
- Read script file and execute those same keywords.

### Small TODOs:

- Make termination valid in SCRIPT mode.
- Create a proper parser replacing `sampleParse()` in `runtime.c`.
- Create operations parsing.
- Accommodate `$` prefixed vars.

### Large TODOs:

- Create execution options on Windows machines
  - Complete the `build.ps1` powershell script.
  - Get the alternative for `editline` library for Windows.
  

### Any help is appreciated!