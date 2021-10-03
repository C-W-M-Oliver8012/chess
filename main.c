#include "defs.h"
#include "board.h"
#include "movegen.h"
#include <time.h>

int main(void) {
   u16 start = clock();

   const Bconst bconst = get_bconst();

   const Board board = get_default_board(bconst.b_indexes);
   print_board(&board);

   const Smove_list smove_list = movegen(&board, &bconst);

   for (u16 i = 0; i < smove_list.len; i++) {
      printf(
         "%d: %s%s\n",
         i + 1,
         bconst.sqr_names[smove_list.list[i].source],
         bconst.sqr_names[smove_list.list[i].dest]
      );
   }
   u16 end = clock();
   double time = ((double)end - (double)start) / CLOCKS_PER_SEC;
   printf("Program completed in %f seconds.\n", time);

   return 0;
}
