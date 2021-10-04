#ifndef DEFS
#define DEFS

#include <stdio.h>
#include <string.h>
#include <stdint.h>

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

typedef uint_fast8_t u8;
typedef int_fast8_t i8;

typedef uint_fast16_t u16;
typedef int_fast16_t i16;

typedef uint_fast32_t u32;
typedef int_fast32_t i32;

typedef uint_fast64_t u64;
typedef int_fast64_t i64;

typedef struct Bconst {
   u8 b_indexes[64];
   char *sqr_names[BOARD_SIZE];
   u8 wpawn_start[BOARD_SIZE];
   u8 bpawn_start[BOARD_SIZE];
   u8 wpawn_promotion[BOARD_SIZE];
   u8 bpawn_promotion[BOARD_SIZE];
   i16 knight_offsets[8];
   i16 bishop_offsets[4];
   i16 rook_offsets[4];
   i16 queen_offsets[8];
   i16 king_offsets[8];
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
   u16 len;
} Smove_list;

#endif
