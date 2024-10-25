# Cint

This is a prototype of a programming language similar to that of python and is
dynamically typed and interpreted.

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
- Accommodate `$` prefixed vars.

### Large TODOs:

- Create execution options on Windows machines
  - Complete the `build.ps1` powershell script.
  - Get the alternative for `editline` library for Windows.
  

### Any help is appreciated!