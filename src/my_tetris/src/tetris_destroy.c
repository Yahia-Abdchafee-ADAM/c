#include <SDL2/SDL.h>
#include "tetris.h"

void tetris_destroy(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* texture, tetris_t *tetris)
{
    for (int o = 0; o != 7; o++) {
        for (int i = 0; i < 4; i++)
            free(tetris->tetriminos[o].matrice[i]);
        free(tetris->tetriminos[o].matrice);
    }
    SDL_HideWindow(window);
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
