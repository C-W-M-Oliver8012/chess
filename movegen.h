#ifndef MOVEGEN
#define MOVEGEN

#include "defs.h"

Smove_list movegen(const Board *board, const Bconst *bconst);
void print_smove(const Bconst *bconst, const Smove *smove);
void print_smove_list(const Bconst *bconst, const Smove_list *smove_list);

#endif
