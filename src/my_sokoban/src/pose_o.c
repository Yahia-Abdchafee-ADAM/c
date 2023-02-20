#include <stdlib.h>
#include <stddef.h>
#include "my_sokoban.h"

int replace_o(char **map_arr, int count_o, int i, int j)
{
    if (map_arr[i][j] == 'O')
        count_o++;
}

void find_o_pose(char **map_arr, int i, int j, pos_t *p)
{
    if (map_arr[i][j] == 'O') {
        p->lp_o[p->nbr_o] = i;
        p->cp_o[p->nbr_o] = j;
        p->nbr_o++;
    }
}

void pose_o(char **map_arr, pos_t *p)
{
    int count_o = 0;

    p->nbr_o = 0;
    for (int i = 0;map_arr[i] != NULL; i++) {
        for (int j = 0; map_arr[i][j] != '\0'; j++)
            count_o = replace_o(map_arr, count_o, i, j);
    }
    p->lp_o = malloc(sizeof(int) * (count_o + 1));
    p->cp_o = malloc(sizeof(int) * (count_o + 1));
    for (int i = 0; map_arr[i] != NULL; i++) {
        for (int j = 0; map_arr[i][j] != '\0'; j++)
            find_o_pose(map_arr, i, j, p);
    }
    p->lp_o[p->nbr_o] = -42;
    p->cp_o[p->nbr_o] = -42;
}

int cheak_pos_o(char **map_arr, int *lp_o, int *cp_o)
{
    int win = 0;

    for (int i = 0; lp_o[i] != -42; i++) {
        if (map_arr[lp_o[i]][cp_o[i]] == ' ')
            map_arr[lp_o[i]][cp_o[i]] = 'O';
        if (map_arr[lp_o[i]][cp_o[i]] == 'O'
        || map_arr[lp_o[i]][cp_o[i]] == 'P')
            win = 1;
    }
    if (win == 0)
        return (1);
    return (0);
}
