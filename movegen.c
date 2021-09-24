#include "defs.h"

const char *sqr_names[BOARD_SIZE] = {
   "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-",
   "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-",
   "-", "-", "-", "-", "a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8", "-", "-", "-", "-",
   "-", "-", "-", "-", "a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7", "-", "-", "-", "-",
   "-", "-", "-", "-", "a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6", "-", "-", "-", "-",
   "-", "-", "-", "-", "a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5", "-", "-", "-", "-",
   "-", "-", "-", "-", "a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4", "-", "-", "-", "-",
   "-", "-", "-", "-", "a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3", "-", "-", "-", "-",
   "-", "-", "-", "-", "a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2", "-", "-", "-", "-",
   "-", "-", "-", "-", "a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1", "-", "-", "-", "-",
   "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-",
   "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-",
};

const u8 WPAWN_START[BOARD_SIZE] = {
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

const u8 BPAWN_START[BOARD_SIZE] = {
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

const u8 WPAWN_PROMOTION[BOARD_SIZE] = {
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

const u8 BPAWN_PROMOTION[BOARD_SIZE] = {
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

void add_move(
   const u8 source,
   const u8 dest,
   const u8 ptype,
   Smove_list *smove_list
) {
   smove_list->list[smove_list->len].source = source;
   smove_list->list[smove_list->len].dest = dest;
   smove_list->list[smove_list->len].ptype = ptype;
   smove_list->len = smove_list->len + 1;
}

void pawn_moves(const Board *board, const u8 source, Smove_list *smove_list) {
   u8 up_one, up_two, starting_pos, attack_one, attack_two, promotion;
   u8 pawn, knight, bishop, rook, queen;
   if (board->stm == WTURN) {
      pawn = PAWN | CBIT;
      knight = KNIGHT | CBIT;
      bishop = BISHOP | CBIT;
      rook = ROOK | CBIT;
      queen = QUEEN | CBIT;
      up_one = source - 16;
      up_two = source - 32;
      starting_pos = WPAWN_START[source];
      attack_one = source - 17;
      attack_two = source - 15;
      promotion = WPAWN_PROMOTION[up_one];
   } else {
      pawn = PAWN;
      knight = KNIGHT;
      bishop = BISHOP;
      rook = ROOK;
      queen = QUEEN;
      up_one = source + 16;
      up_two = source + 32;
      starting_pos = BPAWN_START[source];
      attack_one = source + 15;
      attack_two = source + 17;
      promotion = BPAWN_PROMOTION[up_one];
   }

   if (board->sqrs[up_one] == EMPTY) {
      if (promotion == 1) {
         add_move(source, up_one, knight, smove_list);
         add_move(source, up_one, bishop, smove_list);
         add_move(source, up_one, rook, smove_list);
         add_move(source, up_one, queen, smove_list);
      } else {
         add_move(source, up_one, pawn, smove_list);
      }

      if (starting_pos == 1 && board->sqrs[up_two] == EMPTY) {
         add_move(source, up_two, pawn, smove_list);
      }
   }

   if (board->sqrs[attack_one] != OFF_BOARD
         && board->sqrs[attack_one] != EMPTY
         && (board->pc_list[board->sqrs[source]].ptype & CBIT)
            != (board->pc_list[board->sqrs[attack_one]].ptype & CBIT))
   {
      if (promotion == 1) {
         add_move(source, attack_one, knight, smove_list);
         add_move(source, attack_one, bishop, smove_list);
         add_move(source, attack_one, rook, smove_list);
         add_move(source, attack_one, queen, smove_list);
      } else {
         add_move(source, attack_one, pawn, smove_list);
      }
   }

   if (board->sqrs[attack_two] != OFF_BOARD
         && board->sqrs[attack_two] != EMPTY
         && (board->pc_list[board->sqrs[source]].ptype & CBIT)
            != (board->pc_list[board->sqrs[attack_two]].ptype & CBIT))
   {
      if (promotion == 1) {
         add_move(source, attack_two, knight, smove_list);
         add_move(source, attack_two, bishop, smove_list);
         add_move(source, attack_two, rook, smove_list);
         add_move(source, attack_two, queen, smove_list);
      } else {
         add_move(source, attack_two, pawn, smove_list);
      }
   }
}

void leaper_moves(
   const Board *board,
   const u8 source,
   const i8 *offsets,
   const u8 len,
   Smove_list *smove_list
) {
   const u8 pc_source = board->sqrs[source];

   for (unsigned i = 0; i < len; i++) {
      const u8 dest = source + offsets[i];
      const u8 pc_dest = board->sqrs[dest];

      if (board->sqrs[dest] == OFF_BOARD) {
         continue;
      } else if (board->sqrs[dest] == EMPTY) {
         add_move(source, dest, board->pc_list[pc_source].ptype, smove_list);
      } else if ((board->pc_list[pc_source].ptype & CBIT)
         != (board->pc_list[pc_dest].ptype & CBIT))
      {
         add_move(source, dest, board->pc_list[pc_source].ptype, smove_list);
      }
   }
}

void slider_moves(
   const Board *board,
   const u8 source,
   const i8 *offsets,
   const u8 len,
   Smove_list *smove_list
) {
   const u8 pc_source = board->sqrs[source];

   for (unsigned i = 0; i < len; i++) {
      u8 dest = source;
      while(1) {
         dest = dest + offsets[i];
         const u8 pc_dest = board->sqrs[dest];

         if (board->sqrs[dest] == OFF_BOARD) {
            break;
         } else if (board->sqrs[dest] == EMPTY) {
            add_move(source, dest, board->pc_list[pc_source].ptype, smove_list);
         } else if ((board->pc_list[pc_source].ptype & CBIT)
            != (board->pc_list[pc_dest].ptype & CBIT))
         {
            add_move(source, dest, board->pc_list[pc_source].ptype, smove_list);
            break;
         } else {
            break;
         }
      }
   }
}

Smove_list movegen(const Board *board) {
   Smove_list smove_list;
   smove_list.len = 0;

   const i8 knight_moves[8] = {-18, -33, -31, -14, 14, 31, 33, 18};
   const i8 bishop_moves[4] = {-17, -15, 15, 17};
   const i8 rook_moves[4] = {-16, -1, 1, 16};
   const i8 queen_moves[8] = {-17, -16, -15, -1, 1, 15, 16, 17};

   // loop through piece list
   for (u8 i = board->stm; i < board->stm + 16; i++) {
      // if piece is still on the board
      if (board->sqrs[board->pc_list[i].loc] == i) {
         if ((board->pc_list[i].ptype & PAWN) != 0) {
            pawn_moves(board, board->pc_list[i].loc, &smove_list);
         } else if ((board->pc_list[i].ptype & KNIGHT) != 0) {
            leaper_moves(board, board->pc_list[i].loc, knight_moves, 8, &smove_list);
         } else if ((board->pc_list[i].ptype & BISHOP) != 0) {
            slider_moves(board, board->pc_list[i].loc, bishop_moves, 4, &smove_list);
         } else if ((board->pc_list[i].ptype & ROOK) != 0) {
            slider_moves(board, board->pc_list[i].loc, rook_moves, 4, &smove_list);
         } else if ((board->pc_list[i].ptype & QUEEN) != 0) {
            slider_moves(board, board->pc_list[i].loc, queen_moves, 8, &smove_list);
         } else if ((board->pc_list[i].ptype & KNIGHT) != 0) {
            leaper_moves(board, board->pc_list[i].loc, queen_moves, 8, &smove_list);
         }
      }
   }

   return smove_list;
}

void print_move(const Board *board, const Smove *smove) {
   char pc = ' ';
   // not pretty but defines a promotion
   if ((board->stm == WTURN
      && (board->pc_list[board->sqrs[smove->source]].ptype & PAWN) != 0
      && WPAWN_PROMOTION[smove->dest] == 1)
      || (board->stm == BTURN
      && (board->pc_list[board->sqrs[smove->source]].ptype & PAWN) != 0
      && BPAWN_PROMOTION[smove->dest] == 1)
   ) {
      if ((smove->ptype & KNIGHT) != 0) {
         pc = 'n';
      } else if ((smove->ptype & BISHOP) != 0) {
         pc = 'b';
      } else if ((smove->ptype & ROOK) != 0) {
         pc = 'r';
      } else if ((smove->ptype & QUEEN) != 0) {
         pc = 'q';
      }
   }
   printf("%s%s%c", sqr_names[smove->source], sqr_names[smove->dest], pc);
}
