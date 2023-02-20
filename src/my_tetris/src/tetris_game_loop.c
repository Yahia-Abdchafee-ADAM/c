#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include "tetris.h"
//
//void play_sound(char *sound)
//{
//    // load WAV file
//    SDL_AudioSpec wavSpec;
//    Uint32 wavLength;
//    Uint8 *wavBuffer;
//    SDL_LoadWAV(sound, &wavSpec, &wavBuffer, &wavLength);
//    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
//    // play audio
//    int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
//    SDL_PauseAudioDevice(deviceId, 0);
//}

SDL_Texture *create_texture_from_img(char *img_name, SDL_Renderer* renderer)
{
    SDL_Texture* texture;
    SDL_Surface* image = SDL_LoadBMP(img_name);

    if(!image) {
        printf("Erreur de chargement de l'image : %s\n",SDL_GetError());
        return NULL;
    }
    texture = SDL_CreateTextureFromSurface(renderer ,image);
    SDL_FreeSurface(image);
    return (texture);
}

bool change_teriminos(tetris_t *tetris)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (tetris->curent_tetrimino.matrice[i][j] == true &&
tetris->map_tetris[tetris->curent_tetrimino.y + i + 1][tetris->curent_tetrimino.x + j].c == true)
                return (true);
        }
    }
    return (false);
}

bool game_over(tetris_t *tetris)
{
    for (int i = 0; i < (WIGHT / TILE_SIZE); i++) {
        if (tetris->map_tetris[0][i].c == 1) {
            return (true);
        }
    }
    return (false);
}

void tetris_game_loop(tetris_t *tetris)
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_DisplayMode display_mode;
    SDL_Texture* texture;
    bool stop = false;
    bool menu_stop = false;
    unsigned int lastTime = 0;
    unsigned int currentTime = 0;

    window = SDL_CreateWindow("<--- Tetris --->", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIGHT, SCREEN_HIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_RenderClear(renderer);
    SDL_Init(SDL_INIT_AUDIO);
    //while (!menu_stop) {
    //    SDL_Event event;
    //    while (SDL_PollEvent(&event)) {
    //        if (event.type == SDL_QUIT) {
    //            menu_stop = true;
    //            stop = true;
    //        } else if (event.type == SDL_KEYUP)
    //            if (event.key.keysym.sym == SDLK_RETURN || event.key.keysym.sym == SDLK_SPACE)
    //                    menu_stop = true;
    //            if (event.key.keysym.sym == SDLK_q) {
    //                menu_stop = true;
    //                stop = true;
    //            }
    //    }
    //    SDL_RenderPresent(renderer);
    //}
    play_sound(tetris, START_SOUND);
    texture = create_texture_from_img("assets/imgs/tetris.bmp", renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
    display_tetris(renderer, texture, tetris);
    //SDL_Delay(4000);
    while (!stop) {
        currentTime = SDL_GetTicks();
        if (currentTime > lastTime + 255) {
            if (change_teriminos(tetris) == true) {
                change_tetris_map_in_the_midle(tetris);
                tetris->curent_tetrimino = tetriminos_cmp(tetris->tetriminos[random_number(0, 6)]);
                tetris->curent_tetrimino.color = tetris->color[random_number(0, 5)];
            } else {
                tetris->curent_tetrimino.y++;
                lastTime = currentTime;
            }
        }
        remove_line(tetris);
        if (game_over(tetris) == true) {
            stop = true;
            play_sound(tetris, GAME_OVER_SOUND);
            SDL_Delay(4000);
        }
        if (tetris->curent_tetrimino.y + tetris->y_screen >= get_ymax(tetris)) {
            change_tetris_map(tetris);
            tetris->curent_tetrimino = tetriminos_cmp(tetris->tetriminos[random_number(0, 6)]);
            tetris->curent_tetrimino.color = tetris->color[random_number(0, 5)];
        }
        event(&stop, tetris, &currentTime, &lastTime);
        display_tetris(renderer, texture, tetris);
    }
    tetris_destroy(window, renderer, texture, tetris);
}
