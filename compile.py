import os

cc = "clang"
cflags = "-std=c18 -Wall -Wextra -Ofast -march=native"
cfiles = "main.c board.c"
command = "%s %s %s -o GhostyChess" % (cc, cflags, cfiles)

os.system(command)

print(command)
