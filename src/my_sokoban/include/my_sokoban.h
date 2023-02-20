#include "struct.h"

#ifndef MY_SOKOBAN_H_
    #define MY_SOKOBAN_H_

void help(void);
char **open_directory(char *directory_name);
void *thread_1(void *argv);
int handling_error(char *map);
int my_pop(char **map_arr, pos_t *p);
void free_tab(char **map_arr);
void pose_o(char **map_arr, pos_t *p);
int ending_game(pos_t *p);
int cheak_pos_o(char **map_arr, int *lp_o, int *cp_o);
void pose_p(pos_t *p);
char **cheak_direction(char **map_arr, int key, pos_t *p);
int verif_game_over(char **map_arr, pos_t *p);
char *read_file(char *filepath);
int my_sokoban(int ac, char **av);
char **my_str_to_word_arr(char *str, char *str2);
void init_color_s(void);
void my_time(void);
void inite_my_value(pos_t *p);

#endif /* !MY_SOKOBAN_H_ */
