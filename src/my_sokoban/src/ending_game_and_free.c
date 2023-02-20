#include <ncurses.h>
#include <stdlib.h>
#include <stddef.h>
#include <pthread.h>
#include "my_sokoban.h"

void free_tab(char **map_arr)
{
    for (int i = 0; map_arr[i] != NULL; i++)
        free(map_arr[i]);
    free(map_arr);
}

void free_maps(pos_t *p)
{
    free_tab(p->maps[0].level);
    free_tab(p->maps[1].level);
    free_tab(p->maps[2].level);
    free_tab(p->maps[3].level);
    free_tab(p->maps[4].level);
    free_tab(p->maps[5].level);
    free_tab(p->maps[6].level);
    free_tab(p->maps[7].level);
    free_tab(p->maps[8].level);
    free_tab(p->maps[9].level);
    free_tab(p->maps[10].level);
    free_tab(p->maps[11].level);
    free_tab(p->maps[12].level);
}

int ending_game(pos_t *p)
{
    free_maps(p);
    free(p->lp_o);
    free(p->cp_o);
    endwin();
    return (0);
}