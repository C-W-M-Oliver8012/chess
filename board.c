#include "board.h"

Bconst get_bconst(void) {
   Bconst bconst;

   const u8 b_indexes[64] = {
      36,  37,  38,  39,  40,  41,  42,  43,
      52,  53,  54,  55,  56,  57,  58,  59,
      68,  69,  70,  71,  72,  73,  74,  75,
      84,  85,  86,  87,  88,  89,  90,  91,
     100, 101, 102, 103, 104, 105, 106, 107,
     116, 117, 118, 119, 120, 121, 122, 123,
     132, 133, 134, 135, 136, 137, 138, 139,
     148, 149, 150, 151, 152, 153, 154, 155,
  };

  char *sqr_names[BOARD_SIZE] = {
     "--", "--", "--", "--", "--", "--", "--", "--", "--", "--", "--", "--", "--", "--", "--", "--",
     "--", "--", "--", "--", "--", "--", "--", "--", "--", "--", "--", "--", "--", "--", "--", "--",
     "--", "--", "--", "--", "a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8", "--", "--", "--", "--",
     "--", "--", "--", "--", "a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7", "--", "--", "--", "--",
     "--", "--", "--", "--", "a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6", "--", "--", "--", "--",
     "--", "--", "--", "--", "a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5", "--", "--", "--", "--",
     "--", "--", "--", "--", "a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4", "--", "--", "--", "--",
     "--", "--", "--", "--", "a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3", "--", "--", "--", "--",
     "--", "--", "--", "--", "a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2", "--", "--", "--", "--",
     "--", "--", "--", "--", "a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1", "--", "--", "--", "--",
     "--", "--", "--", "--", "--", "--", "--", "--", "--", "--", "--", "--", "--", "--", "--", "--",
     "--", "--", "--", "--", "--", "--", "--", "--", "--", "--", "--", "--", "--", "--", "--", "--",
   };

   const u8 wpawn_start[BOARD_SIZE] = {
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

   const u8 bpawn_start[BOARD_SIZE] = {
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

   const u8 wpawn_promotion[BOARD_SIZE] = {
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

   const u8 bpawn_promotion[BOARD_SIZE] = {
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

   const i16 knight_offsets[8] = {-18, -31, -33, -14, 14, 33, 31, 18};
   const i16 bishop_offsets[4] = {-17, -15, 15, 17};
   const i16 rook_offsets[4] = {-16, -1, 1, 16};
   const i16 queen_offsets[8] = {-17, -16, -15, -1, 1, 15, 16, 17};
   const i16 king_offsets[8] = {-17, -16, -15, -1, 1, 15, 16, 17};

   // init b_indexes
   for (u16 i = 0; i < 64; i++) {
      bconst.b_indexes[i] = b_indexes[i];
   }

   // init sqr_names
   for (u16 i = 0; i < BOARD_SIZE; i++) {
      bconst.sqr_names[i] = sqr_names[i];
   }

   // init wpawn_start
   for (u16 i = 0; i < BOARD_SIZE; i++) {
      bconst.wpawn_start[i] = wpawn_start[i];
   }

   // init bpawn_start
   for (u16 i = 0; i < BOARD_SIZE; i++) {
      bconst.bpawn_start[i] = bpawn_start[i];
   }

   // init wpawn_promotion
   for (u16 i = 0; i < BOARD_SIZE; i++) {
      bconst.wpawn_promotion[i] = wpawn_promotion[i];
   }

   // init bpawn_promotion
   for (u16 i = 0; i < BOARD_SIZE; i++) {
      bconst.bpawn_promotion[i] = bpawn_promotion[i];
   }

   // init knight_offsets
   for (u16 i = 0; i < 8; i++) {
      bconst.knight_offsets[i] = knight_offsets[i];
   }

   // init bishop_offsets
   for (u16 i = 0; i < 4; i++) {
      bconst.bishop_offsets[i] = bishop_offsets[i];
   }

   // init rook_offsets
   for (u16 i = 0; i < 4; i++) {
      bconst.rook_offsets[i] = rook_offsets[i];
   }

   // init queen_offsets
   for (u16 i = 0; i < 8; i++) {
      bconst.queen_offsets[i] = queen_offsets[i];
   }

   // init king_offsets
   for (u16 i = 0; i < 8; i++) {
      bconst.king_offsets[i] = king_offsets[i];
   }

   return bconst;
}

Board get_empty_board(const u8 *b_indexes) {
   Board board;

   // init ploc
   for (u16 i = 0; i < BOARD_SIZE; i++) {
      board.ploc[i] = OFF_BOARD;
   }

   // create empty ploc
   for (u16 i = 0; i < 64; i++) {
      board.ploc[b_indexes[i]] = EMPTY;
   }

   // init pc_list
   for (u16 i = 0; i < PC_LIST_SIZE; i++) {
      board.pc_list[i].ptype = 0;
      board.pc_list[i].bloc = 0;
   }

   // stm
   board.stm = WTURN;

   return board;
}

Board get_default_board(const u8 *b_indexes) {
   return fen(
      "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1",
      b_indexes
   );
}

Board fen(const char *fen, const u8 *b_indexes) {
   Board board = get_empty_board(b_indexes);

   const u16 len = strlen(fen);

   if (len == 0) return board;

   u16 square, fen_index, fen_seg, wpc, bpc;
   square = fen_index = fen_seg = 0;
   wpc = WTURN;
   bpc = BTURN;
   while (fen_index < len && fen[fen_index] == ' ') fen_index++;
   while (fen_index < len) {
      if (fen_seg == 0) {
         if (square > 63 || wpc >= BTURN || bpc >= PC_LIST_SIZE) break;
         if (fen[fen_index] == 'p') {
            board.pc_list[bpc].ptype = PAWN;
            board.pc_list[bpc].bloc = b_indexes[square];
            board.ploc[b_indexes[square]] = bpc;
            bpc++;
            square++;
         } else if (fen[fen_index] == 'n') {
            board.pc_list[bpc].ptype = KNIGHT;
            board.pc_list[bpc].bloc = b_indexes[square];
            board.ploc[b_indexes[square]] = bpc;
            bpc++;
            square++;
         } else if (fen[fen_index] == 'b') {
            board.pc_list[bpc].ptype = BISHOP;
            board.pc_list[bpc].bloc = b_indexes[square];
            board.ploc[b_indexes[square]] = bpc;
            bpc++;
            square++;
         } else if (fen[fen_index] == 'r') {
            board.pc_list[bpc].ptype = ROOK;
            board.pc_list[bpc].bloc = b_indexes[square];
            board.ploc[b_indexes[square]] = bpc;
            bpc++;
            square++;
         } else if (fen[fen_index] == 'q') {
            board.pc_list[bpc].ptype = QUEEN;
            board.pc_list[bpc].bloc = b_indexes[square];
            board.ploc[b_indexes[square]] = bpc;
            bpc++;
            square++;
         } else if (fen[fen_index] == 'k') {
            board.pc_list[BKING].ptype = KING;
            board.pc_list[BKING].bloc = b_indexes[square];
            board.ploc[b_indexes[square]] = BKING;
            square++;
         } else if (fen[fen_index] == 'P') {
            board.pc_list[wpc].ptype = PAWN | CBIT;
            board.pc_list[wpc].bloc = b_indexes[square];
            board.ploc[b_indexes[square]] = wpc;
            wpc++;
            square++;
         } else if (fen[fen_index] == 'N') {
            board.pc_list[wpc].ptype = KNIGHT | CBIT;
            board.pc_list[wpc].bloc = b_indexes[square];
            board.ploc[b_indexes[square]] = wpc;
            wpc++;
            square++;
         } else if (fen[fen_index] == 'B') {
            board.pc_list[wpc].ptype = BISHOP | CBIT;
            board.pc_list[wpc].bloc = b_indexes[square];
            board.ploc[b_indexes[square]] = wpc;
            wpc++;
            square++;
         } else if (fen[fen_index] == 'R') {
            board.pc_list[wpc].ptype = ROOK | CBIT;
            board.pc_list[wpc].bloc = b_indexes[square];
            board.ploc[b_indexes[square]] = wpc;
            wpc++;
            square++;
         } else if (fen[fen_index] == 'Q') {
            board.pc_list[wpc].ptype = QUEEN | CBIT;
            board.pc_list[wpc].bloc = b_indexes[square];
            board.ploc[b_indexes[square]] = wpc;
            wpc++;
            square++;
         } else if (fen[fen_index] == 'K') {
            board.pc_list[WKING].ptype = KING | CBIT;
            board.pc_list[WKING].bloc = b_indexes[square];
            board.ploc[b_indexes[square]] = WKING;
            square++;
         } else if (fen[fen_index] == '1'
            || fen[fen_index] == '2'
            || fen[fen_index] == '3'
            || fen[fen_index] == '4'
            || fen[fen_index] == '5'
            || fen[fen_index] == '6'
            || fen[fen_index] == '7'
            || fen[fen_index] == '8'
         ) {
            const u8 num_spaces = fen[fen_index] - 48;
            for (u16 i = 0; i < num_spaces; i++) {
               square++;
            }
         }
      } else if (fen_seg == 1) {
         if (fen[fen_index] == 'w' || fen[fen_index] == 'W') {
            board.stm = WTURN;
         } else if (fen[fen_index] == 'b' || fen[fen_index] == 'B') {
            board.stm = BTURN;
         }
      }
      fen_index++;
      if (fen_index < len && fen[fen_index] == ' ') {
         fen_seg++;
         while (fen_index < len && fen[fen_index] == ' ') fen_index++;
      }
   }

   return board;
}

void print_board(const Board *board) {
   const char pieces[2][6] = {
      {'I', 'N', 'B', 'R', 'Q', 'K'},
      {'i', 'n', 'b', 'r', 'q', 'k'},
   };

   // prints the side to move
   if (board->stm == WTURN) {
      printf("      stm: white\n");
   } else {
      printf("      stm: black\n");
   }

   // prints board and pieces
   for (u16 rank = 2; rank < 10; rank++) {
      printf(" (%u) ", 10 - rank);
      for (u16 file = 4; file < 12; file++) {
         const u16 index = rank * 16 + file;

         if (board->ploc[index] == EMPTY) {
            printf(" . ");
         } else {
            const u16 p = board->ploc[index];
            u16 color = 0;
            u16 pc_index = 0;

            // get color
            if ((board->pc_list[p].ptype & CBIT) != 0) {
               color = 0;
            } else {
               color = 1;
            }

            // get piece type
            if ((board->pc_list[p].ptype & PAWN) != 0) {
               pc_index = 0;
            } else if ((board->pc_list[p].ptype & KNIGHT) != 0) {
               pc_index = 1;
            } else if ((board->pc_list[p].ptype & BISHOP) != 0) {
               pc_index = 2;
            } else if ((board->pc_list[p].ptype & ROOK) != 0) {
               pc_index = 3;
            } else if ((board->pc_list[p].ptype & QUEEN) != 0) {
               pc_index = 4;
            } else if ((board->pc_list[p].ptype & KING) != 0) {
               pc_index = 5;
            }

            printf(" %c ", pieces[color][pc_index]);
         }
      }
      printf("\n");
   }
   printf("     (a)(b)(c)(d)(e)(f)(g)(h)\n\n");
}
