#include <stdlib.h>
#include <stddef.h>
#include "my_sokoban.h"

void if_pos_p(char **map_arr, pos_t *p, int i, int j)
{
    if (map_arr[i][j] == 'P') {
        p->cp = j;
        p->lp = i;
    }
}

void pose_p(pos_t *p)
{
    int i = 0;
    int j = 0;

    for (int i = 0; p->maps[p->level].level[i] != NULL; i++) {
        for (j = 0;  p->maps[p->level].level[i][j] != '\0'; j++)
            if_pos_p(p->maps[p->level].level, p, i, j);
    }
}
