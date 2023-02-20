#include <SDL2/SDL.h>
#include <unistd.h>
#include "tetris.h"

void draw(tetris_t *tetris, tetrimino_t tetrimnos, SDL_Renderer* renderer) {
    SDL_Rect rect;
    rect.w = TILE_SIZE;
    rect.h = TILE_SIZE;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (tetrimnos.matrice[i][j]) {
                rect.x = (tetris->x_screen + tetrimnos.x + j) * TILE_SIZE;
                rect.y = (tetris->y_screen + tetrimnos.y + i) * TILE_SIZE;
                SDL_SetRenderDrawColor(renderer, tetrimnos.color.r, tetrimnos.color.g, tetrimnos.color.b, 255);
                SDL_RenderFillRect(renderer, &rect);
                SDL_SetRenderDrawColor(renderer, 219, 219, 219, 255);
                SDL_RenderDrawRect(renderer, &rect);
            }
        }
    }
}

void draw_map(tetris_t *tetris, SDL_Renderer* renderer) {
    SDL_Rect rect;
    rect.w = TILE_SIZE;
    rect.h = TILE_SIZE;

    for (int i = 0; i < (HIGHT / TILE_SIZE); i++) {
        for (int j = 0; j < (WIGHT / TILE_SIZE); j++) {
            if (tetris->map_tetris[i][j].c) {
                rect.x = (((SCREEN_WIGHT / TILE_SIZE) / 2) - ((WIGHT / TILE_SIZE) / 2) + j) * TILE_SIZE;
                rect.y = (7 + i) * TILE_SIZE;
                SDL_SetRenderDrawColor(renderer, tetris->map_tetris[i][j].color.r, tetris->map_tetris[i][j].color.g, tetris->map_tetris[i][j].color.b, 255);
                SDL_RenderFillRect(renderer, &rect);
                SDL_SetRenderDrawColor(renderer, 219, 219, 219, 255);
                SDL_RenderDrawRect(renderer, &rect);
            }
        }
    }
}

void display_tetris(SDL_Renderer* renderer, SDL_Texture* texture, tetris_t *tetris)
{
    SDL_Rect rect;

    rect.w = WIGHT;
    rect.h = HIGHT;
    rect.y = 7 * TILE_SIZE;
    rect.x = (((SCREEN_WIGHT / 2 - WIGHT / 2) / TILE_SIZE) * TILE_SIZE);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 219, 219, 219, 255);
    SDL_RenderDrawRect(renderer, &rect);
    draw_map(tetris, renderer);
    draw(tetris, tetris->curent_tetrimino, renderer);
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
}
