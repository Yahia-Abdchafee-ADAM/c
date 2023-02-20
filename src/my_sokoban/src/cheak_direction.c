#include <stddef.h>
#include "my_sokoban.h"

char **cheak_high_direction (char **map_arr, int key, pos_t *p)
{
    if (key == 68 && map_arr[p->lp][p->cp - 1] != '#') {
        if (map_arr[p->lp][p->cp - 1] == 'X'
        && map_arr[p->lp][p->cp - 2] == 'X')
            return (map_arr);
        if (map_arr[p->lp][p->cp - 1] == 'X'
        && map_arr[p->lp][p->cp - 2] != '#')
            map_arr[p->lp][p->cp - 2] = 'X';
        if (!(map_arr[p->lp][p->cp - 1] == 'X'
        && map_arr[p->lp][p->cp - 2] == '#')) {
            map_arr[p->lp][p->cp] = ' ';
            p->cp--;
        }
    }
    return (map_arr);
}

char **cheak_left_and_high_direction (char **map_arr, int key, pos_t *p)
{
    if (key == 65 && map_arr[p->lp - 1][p->cp] != '#') {
        if (map_arr[p->lp - 1][p->cp] == 'X'
        && map_arr[p->lp - 2][p->cp] == 'X')
            return (map_arr);
        if (map_arr[p->lp - 1][p->cp] == 'X'
        && map_arr[p->lp - 2][p->cp] != '#')
            map_arr[p->lp - 2][p->cp] = 'X';
        if (!(map_arr[p->lp - 1][p->cp] == 'X'
        && map_arr[p->lp - 2][p->cp] == '#')) {
            map_arr[p->lp][p->cp] = ' ';
            p->lp--;
        }
    }
    map_arr = cheak_high_direction(map_arr, key, p);
    return (map_arr);
}

char **cheak_down_direction(char **map_arr, int key, pos_t *p)
{
    if (map_arr[p->lp + 1][p->cp] == 'X'
    && map_arr[p->lp + 2][p->cp] == 'X')
        return (map_arr);
    if (map_arr[p->lp + 1][p->cp] == 'X'
    && map_arr[p->lp + 2][p->cp] != '#')
        map_arr[p->lp + 2][p->cp] = 'X';
    if (!(map_arr[p->lp + 1][p->cp] == 'X'
    && map_arr[p->lp + 2][p->cp] == '#')) {
        map_arr[p->lp][p->cp] = ' ';
        p->lp++;
    }
    return (map_arr);
}

char **cheak_direction(char **map_arr, int key, pos_t *p)
{
    map_arr = cheak_left_and_high_direction(map_arr, key, p);
    if (key == 67 && map_arr[p->lp][p->cp + 1] != '#') {
        if (map_arr[p->lp][p->cp + 1] == 'X'
        && map_arr[p->lp][p->cp + 2] == 'X')
            return (map_arr);
        if (map_arr[p->lp][p->cp + 1] == 'X'
        && map_arr[p->lp][p->cp + 2] != '#')
            map_arr[p->lp][p->cp + 2] = 'X';
        if (!(map_arr[p->lp][p->cp + 1] == 'X'
        && map_arr[p->lp][p->cp + 2] == '#')) {
            map_arr[p->lp][p->cp] = ' ';
            p->cp++;
        }
    }
    if (key == 66 && map_arr[p->lp + 1] != NULL) {
        if (map_arr[p->lp + 1][p->cp] != '#')
            map_arr = cheak_down_direction(map_arr, key, p);
    }
    map_arr[p->lp][p->cp] = 'P';
    return (map_arr);
}
