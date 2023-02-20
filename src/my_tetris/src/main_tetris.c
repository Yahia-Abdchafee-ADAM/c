#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include "tetris.h"

void play_sound(tetris_t *tetris, int sound)
{
    int success = SDL_QueueAudio(tetris->sound[sound].deviceId, tetris->sound[sound].wavBuffer, tetris->sound[sound].wavLength);
    if (success < 0)
        fprintf(stderr, "error capture devices: %s\n",  SDL_GetError());
    SDL_PauseAudioDevice(tetris->sound[sound].deviceId, 0);
}

void init_sound(tetris_t *tetris)
{
    SDL_Init(SDL_INIT_AUDIO);
    if (SDL_LoadWAV(UP_SOUND_NAME, &tetris->sound[UP_SOUND].wavSpec, &tetris->sound[UP_SOUND].wavBuffer, &tetris->sound[UP_SOUND].wavLength) == NULL)
        fprintf(stderr, "Could not open %s: %s\n", UP_SOUND_NAME, SDL_GetError());
    if ((tetris->sound[UP_SOUND].deviceId = SDL_OpenAudioDevice(NULL, 0, &tetris->sound[UP_SOUND].wavSpec, NULL, 0)) < 0)
        fprintf(stderr, "Ivalid device %s: %s\n", UP_SOUND_NAME, SDL_GetError());
    if (SDL_LoadWAV(LEFT_RIGHT_SOUND_NAME, &tetris->sound[LEFT_RIGHT_SOUND].wavSpec, &tetris->sound[LEFT_RIGHT_SOUND].wavBuffer, &tetris->sound[LEFT_RIGHT_SOUND].wavLength) == NULL)
        fprintf(stderr, "Could not open %s: %s\n", LEFT_RIGHT_SOUND_NAME, SDL_GetError());
    if ((tetris->sound[LEFT_RIGHT_SOUND].deviceId = SDL_OpenAudioDevice(NULL, 0, &tetris->sound[LEFT_RIGHT_SOUND].wavSpec, NULL, 0)) < 0)
        fprintf(stderr, "Ivalid device %s: %s\n", UP_SOUND_NAME, SDL_GetError());
    if (SDL_LoadWAV(REMOVE_LINE_SOUND_NAME, &tetris->sound[REMOVE_LINE_SOUND].wavSpec, &tetris->sound[REMOVE_LINE_SOUND].wavBuffer, &tetris->sound[REMOVE_LINE_SOUND].wavLength) == NULL)
        fprintf(stderr, "Could not open %s: %s\n", REMOVE_LINE_SOUND_NAME, SDL_GetError());
    if ((tetris->sound[REMOVE_LINE_SOUND].deviceId = SDL_OpenAudioDevice(NULL, 0, &tetris->sound[REMOVE_LINE_SOUND].wavSpec, NULL, 0)) < 0)
        fprintf(stderr, "Ivalid device %s: %s\n", UP_SOUND_NAME, SDL_GetError());
    if (SDL_LoadWAV(GAME_OVER_SOUND_NAME, &tetris->sound[GAME_OVER_SOUND].wavSpec, &tetris->sound[GAME_OVER_SOUND].wavBuffer, &tetris->sound[GAME_OVER_SOUND].wavLength) == NULL)
        fprintf(stderr, "Could not open %s: %s\n", GAME_OVER_SOUND_NAME, SDL_GetError());
    if ((tetris->sound[GAME_OVER_SOUND].deviceId = SDL_OpenAudioDevice(NULL, 0, &tetris->sound[GAME_OVER_SOUND].wavSpec, NULL, 0)) < 0)
        fprintf(stderr, "Ivalid devicen %s: %s\n", UP_SOUND_NAME, SDL_GetError());
    if (SDL_LoadWAV(START_SOUND_NAME, &tetris->sound[START_SOUND].wavSpec, &tetris->sound[START_SOUND].wavBuffer, &tetris->sound[START_SOUND].wavLength) == NULL)
        fprintf(stderr, "Could not open %s: %s\n", START_SOUND_NAME, SDL_GetError());
    if ((tetris->sound[START_SOUND].deviceId = SDL_OpenAudioDevice(NULL, 0, &tetris->sound[START_SOUND].wavSpec, NULL, 0)) < 0)
        fprintf(stderr, "Ivalid device %s: %s\n", UP_SOUND_NAME, SDL_GetError());}

void init_tetris(tetris_t *tetris)
{
    tetris->x_screen = ((SCREEN_WIGHT / 2) - (WIGHT / 2)) / TILE_SIZE;
    tetris->y_screen = 6;
    tetris->color[0] = (SDL_Color){255, 0, 0, 255};
    tetris->color[1] = (SDL_Color){0, 255, 0, 255};
    tetris->color[2] = (SDL_Color){0, 0, 255, 255};
    tetris->color[3] = (SDL_Color){255, 255, 0, 255};
    tetris->color[4] = (SDL_Color){255, 0, 255, 255};
    tetris->color[5] = (SDL_Color){0, 255, 255, 255};
}

int my_tetris()
{
    tetris_t tetris;

    init_tetris(&tetris);
    init_sound(&tetris);
    init_tetriminos(&tetris);
    init_tetris_map(&tetris);
    tetris_game_loop(&tetris);
    return (0);
}

// int main()
// {
//     my_tetris();
// }
