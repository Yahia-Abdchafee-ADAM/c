#include "tetris.h"

void remove_line(tetris_t *tetris)
{
    int j = 0;

    for (int i = 0; i < (HIGHT / TILE_SIZE); i++) {
        for (j = 0; j < (WIGHT / TILE_SIZE); j++) {
            if (tetris->map_tetris[i][j].c == false)
                break;
        }
        if (j == (WIGHT / TILE_SIZE)) {
            play_sound(tetris, REMOVE_LINE_SOUND);
            for (int o = i; o != 1; o--) {
                for (int z = 0; z < (WIGHT / TILE_SIZE); z++) {
                    tetris->map_tetris[o][z].c = tetris->map_tetris[o - 1][z].c;
                    tetris->map_tetris[o][z].color = tetris->map_tetris[o - 1][z].color;
                }
            }
        }
    }
}

void change_tetris_map_in_the_midle(tetris_t *tetris)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (tetris->curent_tetrimino.matrice[i][j]) {
                tetris->map_tetris[tetris->curent_tetrimino.y + i][tetris->curent_tetrimino.x + j].c = tetris->curent_tetrimino.matrice[i][j];
                tetris->map_tetris[tetris->curent_tetrimino.y + i][tetris->curent_tetrimino.x + j].color = tetris->curent_tetrimino.color;
            }
        }
    }
}

void change_tetris_map(tetris_t *tetris)
{
    int y_max = get_ymax(tetris);
 
    if (y_max == 40 || y_max == 41 || y_max == 42 || y_max == 43) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (tetris->curent_tetrimino.matrice[i][j]) {
                    tetris->map_tetris[tetris->curent_tetrimino.y + i - 2][tetris->curent_tetrimino.x + j].c = tetris->curent_tetrimino.matrice[i][j];
                    tetris->map_tetris[tetris->curent_tetrimino.y + i - 2][tetris->curent_tetrimino.x + j].color = tetris->curent_tetrimino.color;
                }
            }
        }
        return;
    }
}

void init_tetris_map(tetris_t *tetris)
{
    tetris->map_tetris = malloc(sizeof(element_t*) * ((HIGHT / TILE_SIZE) + 4));

    for (int i = 0; i < (HIGHT / TILE_SIZE) + 4; i++)
        tetris->map_tetris[i] = malloc(sizeof(element_t) * ((WIGHT / TILE_SIZE)));
    for (int i = 0; i < (HIGHT / TILE_SIZE); i++)
        for (int j = 0; j < (WIGHT / TILE_SIZE); j++) {
            tetris->map_tetris[i][j].c = 0;
            tetris->map_tetris[i][j].color = (SDL_Color){255, 165, 0, 255};
        }
}
