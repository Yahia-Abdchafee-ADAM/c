#include <stddef.h>
#include "my_sokoban.h"

int verif_game_over_x(char **map_arr, int i, int j, pos_t *p)
{
    int verif = 0;

    if ((map_arr[i][j - 1] == '#' || map_arr[i][j - 1] == 'X')
    && (map_arr[i + 1][j] == '#' || map_arr[i + 1][j] == 'X'))
        verif = 1;
    if ((map_arr[i][j + 1] == '#' || map_arr[i][j + 1] == 'X')
    && (map_arr[i + 1][j] == '#' || map_arr[i + 1][j] == 'X'))
        verif = 1;
    if ((map_arr[i - 1][j] == '#' || map_arr[i - 1][j] == 'X')
    && (map_arr[i][j + 1] == '#' || map_arr[i][j + 1] == 'X'))
        verif = 1;
    if ((map_arr[i - 1][j] == '#' || map_arr[i - 1][j] == 'X')
    && (map_arr[i][j - 1] == '#' || map_arr[i][j - 1] == 'X'))
        verif = 1;
    return (verif);
}

void verif_x(char **map_arr, int i, int j, pos_t *p)
{
    int a = 0;

    if (map_arr[i][j] == 'X') {
        a = verif_game_over_x(map_arr, i, j, p);
        if (a == 1)
            p->game_over++;
    }
}

int verif_game_over(char **map_arr, pos_t *p)
{
    p->game_over = 0;
    int a = 0;

    for (int i = 0; map_arr[i] != NULL; i++) {
        for (int j = 0; map_arr[i][j] != '\0'; j++) {
            verif_x(map_arr, i, j, p);
        }
    }
    return (p->game_over);
}
