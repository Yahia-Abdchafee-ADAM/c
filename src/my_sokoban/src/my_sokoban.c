#include <stdlib.h>
#include <ncurses.h>
#include "my.h"
#include "my_sokoban.h"

void intermediate_sokoban(pos_t *p)
{
    int key = 0;
    int win = 0;
    int game_over = 0;

    while (1) {
        key = my_pop(p->maps[p->level].level, p);
        p->maps[p->level].level = cheak_direction
        (p->maps[p->level].level, key, p);
        win = cheak_pos_o(p->maps[p->level].level, p->lp_o, p->cp_o);
        if ((win == 1 || key == '\n'))
            break;
        game_over = verif_game_over(p->maps[p->level].level, p);
        if (game_over == p->nbr_o || key == 32) {
            p->level--;
            break;
        }
    }
}

int my_sokoban(int ac, char **av)
{

   pos_t p;

   if (ac == 2) {
      if ((my_strcmp(av[1], "-h") == 1) || (my_strcmp(av[1], "--help") == 1))
          help();
   }
   p.map = read_file("maps/my_sokoban.txt");
   if (my_strcmp(p.map, "-1") == 1)
      return (ERROR);
   inite_my_value(&p);

    while (p.level != 13) {
        p.maps[p.level].level = my_str_to_word_arr
        (p.maps[p.level].str, "\n");
        pose_p(&p);
        pose_o(p.maps[p.level].level, &p);
        intermediate_sokoban(&p);
        p.level++;
    }
    return (ending_game(&p));
}
