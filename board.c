#include "defs.h"

const u8 B_INDEXES[64] = {
    36,  37,  38,  39,  40,  41,  42,  43,
    52,  53,  54,  55,  56,  57,  58,  59,
    68,  69,  70,  71,  72,  73,  74,  75,
    84,  85,  86,  87,  88,  89,  90,  91,
   100, 101, 102, 103, 104, 105, 106, 107,
   116, 117, 118, 119, 120, 121, 122, 123,
   132, 133, 134, 135, 136, 137, 138, 139,
   148, 149, 150, 151, 152, 153, 154, 155,
};

Board get_empty_board() {
   Board board;

   // init sqrs
   for (unsigned i = 0; i < BOARD_SIZE; i++) {
      board.sqrs[i] = OFF_BOARD;
   }

   // create empty sqrs
   for (unsigned i = 0; i < 64; i++) {
      board.sqrs[B_INDEXES[i]] = EMPTY;
   }

   // init pc_list
   for (unsigned i = 0; i < PC_LIST_SIZE; i++) {
      board.pc_list[i].ptype = 0;
      board.pc_list[i].loc = 0;
   }

   // stm
   board.stm = WTURN;

   return board;
}

Board get_default_board() {
   return fen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
}

Board fen(char *fen) {
   Board board = get_empty_board();

   unsigned len = strlen(fen);

   if (len == 0) return board;

   u8 square, fen_index, fen_seg, wpc, bpc;
   square = fen_index = fen_seg = 0;
   wpc = WTURN;
   bpc = BTURN;
   while (fen_index < len && fen[fen_index] == ' ') fen_index++;
   while (fen_index < len) {
      if (fen_seg == 0) {
         if (square > 63) break;
         if (fen[fen_index] == 'p') {
            board.pc_list[bpc].ptype = PAWN;
            board.pc_list[bpc].loc = B_INDEXES[square];
            board.sqrs[B_INDEXES[square]] = bpc;
            bpc++;
            square++;
         } else if (fen[fen_index] == 'n') {
            board.pc_list[bpc].ptype = KNIGHT;
            board.pc_list[bpc].loc = B_INDEXES[square];
            board.sqrs[B_INDEXES[square]] = bpc;
            bpc++;
            square++;
         } else if (fen[fen_index] == 'b') {
            board.pc_list[bpc].ptype = BISHOP;
            board.pc_list[bpc].loc = B_INDEXES[square];
            board.sqrs[B_INDEXES[square]] = bpc;
            bpc++;
            square++;
         } else if (fen[fen_index] == 'r') {
            board.pc_list[bpc].ptype = ROOK;
            board.pc_list[bpc].loc = B_INDEXES[square];
            board.sqrs[B_INDEXES[square]] = bpc;
            bpc++;
            square++;
         } else if (fen[fen_index] == 'q') {
            board.pc_list[bpc].ptype = QUEEN;
            board.pc_list[bpc].loc = B_INDEXES[square];
            board.sqrs[B_INDEXES[square]] = bpc;
            bpc++;
            square++;
         } else if (fen[fen_index] == 'k') {
            board.pc_list[BKING].ptype = KING;
            board.pc_list[BKING].loc = B_INDEXES[square];
            board.sqrs[B_INDEXES[square]] = BKING;
            square++;
         } else if (fen[fen_index] == 'P') {
            board.pc_list[wpc].ptype = PAWN | CBIT;
            board.pc_list[wpc].loc = B_INDEXES[square];
            board.sqrs[B_INDEXES[square]] = wpc;
            wpc++;
            square++;
         } else if (fen[fen_index] == 'N') {
            board.pc_list[wpc].ptype = KNIGHT | CBIT;
            board.pc_list[wpc].loc = B_INDEXES[square];
            board.sqrs[B_INDEXES[square]] = wpc;
            wpc++;
            square++;
         } else if (fen[fen_index] == 'B') {
            board.pc_list[wpc].ptype = BISHOP | CBIT;
            board.pc_list[wpc].loc = B_INDEXES[square];
            board.sqrs[B_INDEXES[square]] = wpc;
            wpc++;
            square++;
         } else if (fen[fen_index] == 'R') {
            board.pc_list[wpc].ptype = ROOK | CBIT;
            board.pc_list[wpc].loc = B_INDEXES[square];
            board.sqrs[B_INDEXES[square]] = wpc;
            wpc++;
            square++;
         } else if (fen[fen_index] == 'Q') {
            board.pc_list[wpc].ptype = QUEEN | CBIT;
            board.pc_list[wpc].loc = B_INDEXES[square];
            board.sqrs[B_INDEXES[square]] = wpc;
            wpc++;
            square++;
         } else if (fen[fen_index] == 'K') {
            board.pc_list[WKING].ptype = KING | CBIT;
            board.pc_list[WKING].loc = B_INDEXES[square];
            board.sqrs[B_INDEXES[square]] = WKING;
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
            u8 n = (u8)fen[fen_index] - 48;
            for (unsigned t = 0; t < n; t++) {
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

void print_board(Board *board) {
   char pieces[2][6] = {
      {'I', 'N', 'B', 'R', 'Q', 'K'},
      {'i', 'n', 'b', 'r', 'q', 'k'},
   };

   if (board->stm == WTURN) {
      printf("      stm: white\n");
   } else {
      printf("      stm: black\n");
   }
   for (unsigned rank = 2; rank < 10; rank++) {
      printf(" (%d) ", 10 - rank);
      for (unsigned file = 4; file < 12; file++) {
         unsigned index = rank * 16 + file;

         if (board->sqrs[index] == EMPTY) {
            printf(" . ");
         } else {
            unsigned p = board->sqrs[index];
            unsigned color = 0;
            unsigned pc_index = 0;

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
