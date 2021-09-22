#ifndef DEFS
#define DEFS

#include <stdio.h>
#include <string.h>

#define BOARD_SIZE 192
#define PC_LIST_SIZE 34

#define OFF_BOARD 0
#define EMPTY 1

#define PAWN 1
#define KNIGHT 2
#define BISHOP 4
#define ROOK 8
#define QUEEN 16
#define KING 32
#define CBIT 64   // the bit will be set to 1 for white and 0 for black

#define WTURN 2
#define BTURN 18

#define WKING 17
#define BKING 33

typedef unsigned char u8;

typedef struct Pc {
   u8 ptype;
   u8 loc;
} Pc;

typedef struct Board {
   u8 sqrs[BOARD_SIZE];
   Pc pc_list[PC_LIST_SIZE];
   u8 stm;
} Board;


// board.c
Board get_empty_board();
Board get_default_board();
Board fen(char *fen);
void print_board(Board *board);

#endif
