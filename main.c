#include "defs.h"

int main(void) {
   const Board board = get_default_board();
   print_board(&board);

   Smove_list smove_list = movegen(&board);

   for (unsigned i = 0; i < smove_list.len; i++) {
      printf("%d: ", i + 1);
      print_move(&smove_list.list[i]);
      printf("\n");
   }

   return 0;
}
