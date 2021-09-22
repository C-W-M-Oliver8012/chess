#include "defs.h"

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
   u8 pawn, up_one, up_two, starting_pos, attack_one, attack_two;
   if (board->stm == WTURN) {
      pawn = PAWN | CBIT;
      up_one = source - 16;
      up_two = source - 32;
      starting_pos = WPAWN_START[source];
      attack_one = source - 17;
      attack_two = source - 15;
   } else {
      pawn = PAWN;
      up_one = source + 16;
      up_two = source + 32;
      starting_pos = BPAWN_START[source];
      attack_one = source + 15;
      attack_two = source + 17;
   }

   if (board->sqrs[up_one] == EMPTY) {
      add_move(source, up_one, pawn, smove_list);

      if (starting_pos == 1 && board->sqrs[up_two] == EMPTY) {
         add_move(source, up_two, pawn, smove_list);
      }
   }

   if (board->sqrs[attack_one] != OFF_BOARD
         && board->sqrs[attack_one] != EMPTY
         && (board->pc_list[board->sqrs[source]].ptype & CBIT)
            != (board->pc_list[board->sqrs[attack_one]].ptype & CBIT))
   {
      add_move(source, attack_one, pawn, smove_list);
   }

   if (board->sqrs[attack_two] != OFF_BOARD
         && board->sqrs[attack_two] != EMPTY
         && (board->pc_list[board->sqrs[source]].ptype & CBIT)
            != (board->pc_list[board->sqrs[attack_two]].ptype & CBIT))
   {
      add_move(source, attack_one, pawn, smove_list);
   }
}

Smove_list movegen(const Board *board) {
   Smove_list smove_list;
   smove_list.len = 0;

   // loop through piece list
   for (u8 i = board->stm; i < board->stm + 16; i++) {
      // if piece is still on the board
      if (board->sqrs[board->pc_list[i].loc] == i) {
         if ((board->pc_list[i].ptype & PAWN) != 0) {
            pawn_moves(board, board->pc_list[i].loc, &smove_list);
         }
      }
   }

   return smove_list;
}

void print_move(const Smove *smove) {
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

   printf("%s%s", sqr_names[smove->source], sqr_names[smove->dest]);
}
