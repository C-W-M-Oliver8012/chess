#!/bin/bash

cc="clang"
cflags="-std=c17 -Wall -Wextra -O2"
cfiles="main.c board.c"
print="$cc $cflags $cfiles -o GhostyChess"

$cc $cflags $cfiles -o GhostyChess

echo $print
