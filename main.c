#include "defs.h"
#include <time.h>

int main(void) {
   const Board board = get_default_board();
   print_board(&board);

   Smove_list smove_list = movegen(&board);

   for (unsigned i = 0; i < smove_list.len; i++) {
      printf("%d: ", i + 1);
      print_move(&board, &smove_list.list[i]);
      printf("\n");
   }

   clock_t start, end;
   start = clock();
   u64 nodes = perft(&board, 7);
   end = clock();
   printf("%lu nodes in %f seconds.\n", nodes, (double)(end - start) / CLOCKS_PER_SEC);

   return 0;
}
