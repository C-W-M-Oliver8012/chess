#ifndef DEFS
#define DEFS

#include <stdio.h>
#include <string.h>

#define BOARD_SIZE 192
#define PC_LIST_SIZE 34
#define SMOVE_LIST_SIZE 350

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
typedef signed char i8;
typedef unsigned long u64;

typedef struct Bconst {
   u8 b_indexes[64];
   char *sqr_names[BOARD_SIZE];
   u8 wpawn_start[BOARD_SIZE];
   u8 bpawn_start[BOARD_SIZE];
   u8 wpawn_promotion[BOARD_SIZE];
   u8 bpawn_promotion[BOARD_SIZE];
} Bconst;

typedef struct Pc {
   u8 ptype;
   u8 bloc;
} Pc;

typedef struct Board {
   u8 ploc[BOARD_SIZE];
   Pc pc_list[PC_LIST_SIZE];
   u8 stm;
} Board;

typedef struct Smove {
   u8 source;
   u8 dest;
   u8 ptype;
} Smove;

typedef struct Smove_list {
   Smove list[SMOVE_LIST_SIZE];
   u8 len;
} Smove_list;

#endif
