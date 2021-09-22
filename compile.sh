#!/bin/bash

cc="clang"
cflags="-std=c17 -Wall -Wextra -Ofast"
cfiles="main.c board.c movegen.c"
print="$cc $cflags $cfiles -o GhostyChess"

$cc $cflags $cfiles -o GhostyChess

echo $print
