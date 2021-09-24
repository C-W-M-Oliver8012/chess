#include "defs.h"

void make_move(Board *board, Smove *smove) {
   board->sqrs[smove->dest] = board->sqrs[smove->source];
   board->sqrs[smove->source] = EMPTY;

   board->pc_list[board->sqrs[smove->dest]].ptype = smove->ptype;
   board->pc_list[board->sqrs[smove->dest]].loc = smove->dest;

   if (board->stm == WTURN) {
      board->stm = BTURN;
   } else {
      board->stm = WTURN;
   }
}
