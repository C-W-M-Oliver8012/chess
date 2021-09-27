#ifndef BOARD
#define BOARD

#include "defs.h"

Bconst get_bconst();
Board get_empty_board(const u8 *b_indexes);
Board get_default_board(const u8 *b_indexes);
Board fen(const char *fen, const u8 *b_indexes);
void print_board(const Board *board);

#endif
