#!/bin/bash

source_files=$(find . -maxdepth 1 -name "*.c")

if gcc $source_files -ledit -Wall -Wextra -o output; then
  ./output "$@"
else
  echo "^^^^^^^^^^ Somthing went wrong ^^^^^^^^^^^^^^"
fi
