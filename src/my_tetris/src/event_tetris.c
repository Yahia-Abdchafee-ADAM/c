#include <SDL2/SDL.h>
#include "tetris.h"
#include <stdbool.h>

int get_xmin(tetris_t *tetris)
{
    int x_min = tetris->x_screen;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (tetris->curent_tetrimino.matrice[j][i] == true)
                return (x_min);
        }
        x_min--;
    }
    return (x_min);
}

int get_ymax(tetris_t *tetris)
{
    int y_max = tetris->x_screen + 10;

    for (int i = 3; i >= 0; i--) {
        for (int j = 0; j < 4; j++) {
            if (tetris->curent_tetrimino.matrice[i][j] == true)
                return (y_max);
        }
        y_max++;
    }
    return (y_max);
}

int get_xmax(tetris_t *tetris)
{
    int x_max = 53;

    for (int i = 3; i >= 0; i--) {
        for (int j = 3; j >= 0; j--) {
            if (tetris->curent_tetrimino.matrice[j][i] == true)
                return (x_max);
        }
        x_max++;
    }
    return (x_max);
}

bool go_left(tetris_t *tetris)
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            if (tetris->curent_tetrimino.matrice[i][j] == true && tetris->map_tetris[tetris->curent_tetrimino.y + i][tetris->curent_tetrimino.x  + j - 1].c == true)
                return (false);
        }
    return (true);
}

bool go_right(tetris_t *tetris)
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            if (tetris->curent_tetrimino.matrice[i][j] == true && tetris->map_tetris[tetris->curent_tetrimino.y + i][tetris->curent_tetrimino.x  + j + 1].c == true)
                return (false);
        }
    return (true);
}

void event(bool *stop, tetris_t *tetris, unsigned int *current_time, unsigned int *last_time)
{
    SDL_Event event;

    int x_min = get_xmin(tetris);
    int x_max = get_xmax(tetris);

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            *stop = true;
        else if (event.type == SDL_KEYUP) {
            switch(event.key.keysym.sym) {
                case SDLK_q:
                    *stop = true;
                case SDLK_LEFT:
                    //play_sound(tetris, LEFT_RIGHT_SOUND);
                    if (tetris->curent_tetrimino.x + tetris->x_screen > x_min && go_left(tetris) == true)
                        tetris->curent_tetrimino.x--;
                    break;
                case SDLK_p:
                    //if (tetris->curent_tetrimino.x + tetris->x_screen > x_min && go_left(tetris) == true)
                    //    *last_time = *current_time;
                    //break;
                case SDLK_RIGHT:
                    //play_sound(tetris, LEFT_RIGHT_SOUND);
                    if (tetris->curent_tetrimino.x + tetris->x_screen < x_max && go_right(tetris) == true)
                        tetris->curent_tetrimino.x++;
                    break;
                case SDLK_UP:
                    //play_sound(tetris, UP_SOUND);
                    tetris->curent_tetrimino.matrice = rotate(tetris->curent_tetrimino.matrice, tetris->curent_tetrimino.size);
                    break;
                case SDLK_DOWN:
                    if (tetris->curent_tetrimino.y + tetris->y_screen >= get_ymax(tetris)) {
                        change_tetris_map(tetris);
                        tetris->curent_tetrimino = tetriminos_cmp(tetris->tetriminos[random_number(0, 6)]);
                        tetris->curent_tetrimino.color = tetris->color[random_number(0, 5)];
                    } else if (change_teriminos(tetris) == true) {
                        change_tetris_map_in_the_midle(tetris);
                        tetris->curent_tetrimino = tetriminos_cmp(tetris->tetriminos[random_number(0, 6)]);
                        tetris->curent_tetrimino.color = tetris->color[random_number(0, 5)];
                    } else
                        tetris->curent_tetrimino.y++;
                    break;
                default:
                    break;
            }
        }
    }
}
