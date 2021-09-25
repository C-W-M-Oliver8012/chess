import os

cc = "clang"
cflags = "-std=c17 -Wall -Wextra -Ofast"
cfiles = "main.c board.c"
command = "%s %s %s -o GhostyChess" % (cc, cflags, cfiles)

os.system(command)

print(command)
