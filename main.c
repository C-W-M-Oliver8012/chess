#include "defs.h"
#include "board.h"
#include "movegen.h"

int main(void) {
   const Bconst bconst = get_bconst();

   const Board board = get_default_board(bconst.b_indexes);
   print_board(&board);

   u64 start = clock();
   const Smove_list smove_list = movegen(&board, &bconst);
   u64 end = clock();

   print_smove_list(&bconst, &smove_list);

   double time = ((double)end - (double)start) / CLOCKS_PER_SEC;
   printf("Program completed in %f seconds.\n", time);

   return 0;
}
