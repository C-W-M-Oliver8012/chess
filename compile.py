import os

cc = "clang"
cflags = "-std=c17 -Wall -Wextra -Ofast"
cfiles = "main.c board.c"
command = cc + " " + cflags + " " + cfiles + " -o GhostyChess"

os.system(command)

print(command)
