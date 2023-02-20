#include "tetris.h"
#include <stdbool.h>

void display_matris(bool **matris)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            printf("%i", matris[i][j]);
        printf("\n");
    }
    printf("\n");
}

void display_tetris_map(element_t **map)
{
    for (int i = 0; i < (HIGHT / TILE_SIZE); i++) {
        for (int j = 0; j < (WIGHT / TILE_SIZE); j++)
            printf("%i", map[i][j].c);
        printf("\n");
    }
}


