#include <SDL2/SDL.h>
#include <stdbool.h>

#ifndef __TETRIS__H__
    #define __TETRIS__H__

/* SOUND */
#define UP_SOUND 0
#define LEFT_RIGHT_SOUND 1
#define REMOVE_LINE_SOUND 2
#define GAME_OVER_SOUND 3
#define START_SOUND 4

/* WINDOWS SIZE */
#define HIGHT 792
#define WIGHT 594
#define TILE_SIZE 22
#define SCREEN_HIGHT 1080
#define SCREEN_WIGHT 1920

/* COLOR */
#define MAX_COLOR 6

/* SOUND NAME */
#define UP_SOUND_NAME "assets/sounds/up_sound.wav"
#define START_SOUND_NAME "assets/sounds/start_sound.wav"
#define GAME_OVER_SOUND_NAME "assets/sounds/game_over_sound.wav"
#define REMOVE_LINE_SOUND_NAME "assets/sounds/remove_line_sound.wav"
#define LEFT_RIGHT_SOUND_NAME "assets/sounds/left_right_sound.wav"

//   255, 0, 0           red
//   0, 255, 0           green
//   0, 0, 255           bleu
//   255, 255, 0         yellow
//   255, 0, 255         violet
//   0, 255, 255        cyan

//   224, 255, 255       cyan
//   255, 255, 0         yellow
//   128, 0, 128         violet
//   0, 230, 64          bleu

typedef struct tetrimino_s {
    SDL_Color color;
    bool **matrice;
    int size;
    int x;
    int y;
} tetrimino_t;

typedef struct element_s {
    bool c;
    SDL_Color color;
} element_t;

typedef struct sound_s {
    SDL_AudioSpec wavSpec;
    Uint32 wavLength;
    Uint8 *wavBuffer;
    SDL_AudioDeviceID deviceId;
} sound_t;

typedef struct tetris_s {
    element_t **map_tetris;
    SDL_Window* window;
    SDL_Renderer* renderer;
    tetrimino_t curent_tetrimino;
    tetrimino_t tetriminos[7];
    SDL_Rect rectangle;
    int x_screen;
    int y_screen;
    SDL_Color color[MAX_COLOR];
    sound_t sound[5];
} tetris_t;

void play_sound(tetris_t *tetris, int sound);
int get_ymax(tetris_t *tetris);
int get_xmax(tetris_t *tetris);
int get_xmin(tetris_t *tetris);
void display_matris(bool **matris);
void remove_line(tetris_t *tetris);
bool change_teriminos(tetris_t *tetris);
void change_tetris_map(tetris_t *tetris);
void display_tetris_map(element_t **map);
bool **matris(bool tetrimino[4][4]);
void init_tetris_map(tetris_t *tetris);
bool **rotate(bool **matrix, int size);
void init_tetriminos(tetris_t *tetris);
void tetris_game_loop(tetris_t *tetris);
void event(bool *stop, tetris_t *tetris, unsigned int *current_time, unsigned int *last_time);
int random_number(int min_num, int max_num);
tetrimino_t tetriminos_cmp(tetrimino_t tetrimino);
void change_tetris_map_in_the_midle(tetris_t *tetris);
void change_tetris_map_in_the_midle(tetris_t *tetris);
void display_tetris(SDL_Renderer* renderer, SDL_Texture* monImage, tetris_t *tetris);
void tetris_destroy(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* texture, tetris_t *tetris);

#endif /* __TETRIS__H__ */

