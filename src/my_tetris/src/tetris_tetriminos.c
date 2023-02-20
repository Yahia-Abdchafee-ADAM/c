#include "tetris.h"
#include <stdbool.h>

bool **verif_rotate_matris(bool **matris)
{
    bool line = false;
    bool column = false;

    while (!line && !column) {
        if ((matris[0][0] == true || matris[0][1] == true) || (matris[0][2] == true || matris[0][3] == true))
            line = true;
        if ((matris[0][0] == true || matris[1][0] == true) || (matris[2][0] == true || matris[3][0] == true))
            column = true;
        if (!line) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 4; j++) {
                    matris[i][j] = matris[i + 1][j];
                }
            }
            matris[3][0] = 0;
            matris[3][1] = 0;
            matris[3][2] = 0;
            matris[3][3] = 0;
        }
        if (!column) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    matris[i][j] = matris[i][j + 1];
                }
            }
            matris[0][3] = 0;
            matris[1][3] = 0;
            matris[2][3] = 0;
            matris[3][3] = 0;
        }
    }
    return (matris);
}

bool **rotate(bool **matrix, int size)
{
    bool **tmp = matris((bool[4][4]){{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}});

    if (size == 2) {
        free(tmp);
        return (matrix);
    }
    tmp[0][3] = matrix[0][0];
    tmp[1][3] = matrix[0][1];
    tmp[2][3] = matrix[0][2];
    tmp[3][3] = matrix[0][3];
    tmp[0][2] = matrix[1][0];
    tmp[1][2] = matrix[1][1];
    tmp[2][2] = matrix[1][2];
    tmp[3][2] = matrix[1][3];
    tmp[0][1] = matrix[2][0];
    tmp[1][1] = matrix[2][1];
    tmp[2][1] = matrix[2][2];
    tmp[3][1] = matrix[2][3];
    tmp[0][0] = matrix[3][0];
    tmp[1][0] = matrix[3][1];
    tmp[2][0] = matrix[3][2];
    tmp[3][0] = matrix[3][3];
    for (int i = 0; i < 4; i++)
        free(matrix[i]);
    free(matrix);
    tmp = verif_rotate_matris(tmp);
    return tmp;
}

bool **matris(bool tetrimino[4][4])
{
    bool **matris = malloc(sizeof(bool*) * 4);

    for (int i = 0; i < 4; i++) {
        matris[i] = malloc(sizeof(bool) * 4);
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            matris[i][j] = tetrimino[i][j];
    }
    return (matris);
}

tetrimino_t tetriminos_cmp(tetrimino_t tetrimino)
{
    tetrimino_t tetrimino_cmp;
    bool **matris = malloc(sizeof(bool*) * 4);

    for (int i = 0; i < 4; i++) {
        matris[i] = malloc(sizeof(bool) * 4);
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            matris[i][j] = tetrimino.matrice[i][j];
    }
    tetrimino_cmp.matrice = matris;
    tetrimino_cmp.color = tetrimino.color;
    tetrimino_cmp.size = tetrimino.size;
    tetrimino_cmp.x = tetrimino.x;
    tetrimino_cmp.y = tetrimino.y;
    return (tetrimino_cmp);
}

void init_tetriminos(tetris_t *tetris)
{
    bool tetrimino[4][4] = {{0,0,1,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}};

    tetris->tetriminos[0].matrice = matris((bool[4][4]){
{0,0,1,0},
{1,1,1,0},
{0,0,0,0},
{0,0,0,0}});

    tetris->tetriminos[1].matrice = matris((bool[4][4]){
{1,1,0,0},
{0,1,1,0},
{0,0,0,0},
{0,0,0,0}});

    tetris->tetriminos[2].matrice = matris((bool[4][4]){
{1,1,1,1},
{0,0,0,0},
{0,0,0,0},
{0,0,0,0}});

    tetris->tetriminos[3].matrice = matris((bool[4][4]){
{1,0,0,0},
{1,1,1,0},
{0,0,0,0},
{0,0,0,0}});

    tetris->tetriminos[4].matrice = matris((bool[4][4]){
{1,1,0,0},
{1,1,0,0},
{0,0,0,0},
{0,0,0,0}});

    tetris->tetriminos[5].matrice = matris((bool[4][4]){
{0,1,1,0},
{1,1,0,0},
{0,0,0,0},
{0,0,0,0}});

    tetris->tetriminos[6].matrice = matris((bool[4][4]){
{0,1,0,0},
{1,1,1,0},
{0,0,0,0},
{0,0,0,0}});

    tetris->tetriminos[1].size = 3;
    tetris->tetriminos[2].size = 4;
    tetris->tetriminos[3].size = 3;
    tetris->tetriminos[4].size = 2;
    tetris->tetriminos[5].size = 3;
    tetris->tetriminos[0].size = 3;
    tetris->tetriminos[6].size = 3;
    tetris->tetriminos[0].color = (SDL_Color){255, 165, 0, 255};
    tetris->tetriminos[2].color = (SDL_Color){224, 255, 255, 255};
    tetris->tetriminos[1].color = (SDL_Color){255, 0, 0, 255};
    tetris->tetriminos[3].color = (SDL_Color){0, 0, 255, 255};
    tetris->tetriminos[4].color = (SDL_Color){255, 255, 0, 255};
    tetris->tetriminos[5].color = (SDL_Color){255, 165, 0, 255};
    tetris->tetriminos[6].color = (SDL_Color){128, 0, 128, 255};
    for (int i = 0; i != 7; i++) {
        tetris->tetriminos[i].x = (WIGHT / 2 - 4) / TILE_SIZE;
        tetris->tetriminos[i].y = 0;
    }
    tetris->curent_tetrimino =  tetris->tetriminos[random_number(0, 6)];
}
