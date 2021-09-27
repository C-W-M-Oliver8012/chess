#include "defs.h"

int main(void) {
   Bconst bconst;
   init_bconst(&bconst);

   const Board board = get_default_board(bconst.b_indexes);
   print_board(&board);

   return 0;
}
