#include "defs.h"
#include "board.h"

int main(void) {
   const Bconst bconst = get_bconst();

   const Board board = get_default_board(bconst.b_indexes);
   print_board(&board);

   return 0;
}
