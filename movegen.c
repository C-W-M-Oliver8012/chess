#include "movegen.h"

inline void add_move(u8 source, u8 dest, u8 ptype, Smove_list *smove_list) {
   smove_list->list[smove_list->len].source = source;
   smove_list->list[smove_list->len].dest = dest;
   smove_list->list[smove_list->len].ptype = ptype;
   smove_list->len = smove_list->len + 1;
}

Smove_list movegen(const Board *board, const Bconst *bconst) {
   Smove_list smove_list;
   smove_list.len = 0;

   u8 begin = board->stm;
   u8 end = board->stm + 16;

   u8 pawn, knight, bishop, rook, queen, king;
   if (board->stm == WTURN) {
      pawn = PAWN | CBIT;
      knight = KNIGHT | CBIT;
      bishop = BISHOP | CBIT;
      rook = ROOK | CBIT;
      queen = QUEEN | CBIT;
      king = KING | KING;
   } else {
      pawn = PAWN;
      knight = KNIGHT;
      bishop = BISHOP;
      rook = ROOK;
      queen = QUEEN;
      king = KING;
   }

   // loops through piece list
   for (u8 ploc = begin; ploc < end; ploc++) {
      u8 bloc = board->pc_list[ploc].bloc;
      u8 ptype = (board->pc_list[ploc].ptype & PBITS);
      u8 pcolor = (board->pc_list[ploc].ptype & CBIT);

      // if the piece is still on the board
      if (board->ploc[bloc] == ploc) {

         // if the piece is a pawn
         if (ptype == PAWN) {
            u8 one_up, two_up, starting_pos, promotion;

            if (board->stm == WTURN) {
               one_up = bloc - 16;
               two_up = bloc - 32;
               starting_pos = bconst->wpawn_start[bloc];
               promotion = bconst->wpawn_promotion[bloc];
            } else {
               one_up = bloc + 16;
               two_up = bloc + 32;
               starting_pos = bconst->bpawn_start[bloc];
               promotion = bconst->bpawn_promotion[bloc];
            }

            // moving pawn one up
            if (board->ploc[one_up] == EMPTY) {
               if (promotion == 1) {
                  add_move(bloc, one_up, (knight & PROMOTION), &smove_list);
                  add_move(bloc, one_up, (bishop & PROMOTION), &smove_list);
                  add_move(bloc, one_up, (rook & PROMOTION), &smove_list);
                  add_move(bloc, one_up, (queen & PROMOTION), &smove_list);
               } else {
                  add_move(bloc, one_up, pawn, &smove_list);
               }

               // moving pawn two up
               if (starting_pos == 1 && board->ploc[two_up] == EMPTY) {
                  add_move(bloc, two_up, pawn, &smove_list);
               }
            }

         // if piece is a knight
         } else if (ptype == KNIGHT) {
            for (u8 i = 0; i < 8; i++) {
               const u8 dest = bloc + bconst->knight_offsets[i];
               const u8 dploc = board->ploc[dest];
               const u8 dpcolor = (board->pc_list[dploc].ptype & CBIT);

               if (dploc == OFF_BOARD) {
                  continue;
               } else if (dploc == EMPTY || pcolor != dpcolor) {
                  add_move(bloc, dest, knight, &smove_list);
               }
            }

         // if piece is a bishop
         } else if (ptype == BISHOP) {
            for (u8 i = 0; i < 4; i++) {
               u8 dest = bloc;
               while (1) {
                  dest = dest + bconst->bishop_offsets[i];
                  const u8 dploc = board->ploc[dest];
                  const u8 dpcolor = (board->pc_list[dploc].ptype & CBIT);

                  if (dploc == OFF_BOARD) {
                     break;
                  } else if (dploc == EMPTY) {
                     add_move(bloc, dest, bishop, &smove_list);
                  } else if (pcolor != dpcolor) {
                     add_move(bloc, dest, bishop, &smove_list);
                     break;
                  } else {
                     break;
                  }
               }
            }

         // if piece is a rook
         } else if (ptype == ROOK) {
            for (u8 i = 0; i < 4; i++) {
               u8 dest = bloc;
               while (1) {
                  dest = dest + bconst->rook_offsets[i];
                  const u8 dploc = board->ploc[dest];
                  const u8 dpcolor = (board->pc_list[dploc].ptype & CBIT);

                  if (dploc == OFF_BOARD) {
                     break;
                  } else if (dploc == EMPTY) {
                     add_move(bloc, dest, rook, &smove_list);
                  } else if (pcolor != dpcolor) {
                     add_move(bloc, dest, rook, &smove_list);
                     break;
                  } else {
                     break;
                  }
               }
            }

         // if piece is a queen
         } else if (ptype == QUEEN) {
            for (u8 i = 0; i < 8; i++) {
               u8 dest = bloc;
               while (1) {
                  dest = dest + bconst->queen_offsets[i];
                  const u8 dploc = board->ploc[dest];
                  const u8 dpcolor = (board->pc_list[dploc].ptype & CBIT);

                  if (dploc == OFF_BOARD) {
                     break;
                  } else if (dploc == EMPTY) {
                     add_move(bloc, dest, queen, &smove_list);
                  } else if (pcolor != dpcolor) {
                     add_move(bloc, dest, queen, &smove_list);
                     break;
                  } else {
                     break;
                  }
               }
            }

         // if piece is a king
         } else if (ptype == KING) {
            for (u8 i = 0; i < 8; i++) {
               const u8 dest = bloc + bconst->king_offsets[i];
               const u8 dploc = board->ploc[dest];
               const u8 dpcolor = (board->pc_list[dploc].ptype & CBIT);

               if (dploc == OFF_BOARD) {
                  continue;
               } else if (dploc == EMPTY || pcolor != dpcolor) {
                  add_move(bloc, dest, king, &smove_list);
               }
            }
         }
      }
   }

   return smove_list;
}

void print_smove(const Bconst *bconst, const Smove *smove) {
   printf(
      "%s%s",
      bconst->sqr_names[smove->source],
      bconst->sqr_names[smove->dest]
   );
}

void print_smove_list(const Bconst *bconst, const Smove_list *smove_list) {
   for (u16 i = 0; i < smove_list->len; i++) {
      printf("%u: ", i + 1);
      print_smove(bconst, &smove_list->list[i]);
      printf("\n");
   }
}
