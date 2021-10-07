#ifndef DEFS
#define DEFS

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

#define BOARD_SIZE 192
#define PC_LIST_SIZE 34
#define SMOVE_LIST_SIZE 350

#define OFF_BOARD 0
#define EMPTY 1

#define PAWN 1
#define KNIGHT 2
#define BISHOP 3
#define ROOK 4
#define QUEEN 5
#define KING 6

#define PBITS 7
#define CBIT 8   // the bit will be set to 1 for white and 0 for black
#define FBITS 240

#define PROMOTION 16
#define EN_PASSANT 32
#define CASTLING 48
#define CLEAR_FBITS 15

#define WTURN 2
#define BTURN 18

#define WKING 17
#define BKING 33

typedef uint8_t u8;
typedef int8_t i8;
typedef uint16_t u16;
typedef int16_t i16;
typedef uint32_t u32;
typedef int32_t i32;
typedef uint64_t u64;
typedef int64_t i64;

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
