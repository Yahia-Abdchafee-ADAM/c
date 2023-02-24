#include <unistd.h>
#include <SFML/Audio.h>

#ifndef __NAVY_H__
    #define __NAVY_H__

#define SIZE 10
#define RESET "\033[0m" /* no color for reset the color*/
#define	RED   "\033[31m" /* Red color for Sunken ships*/
#define	GREEN "\033[32m" /* Green color for ships*/
#define	CYAN  "\033[36m" /* Cyan color for watter*/

typedef struct navy_s {
    char **player_one_map;
    char **player_two_map;
    int player_one_pid;
    int player_two_pid;
    char **dico_of_attack;
    sfMusic *music;
} navy_t;

char **my_strtok(char const *string, char *delimitor);
void print_ennemy_board(char **board);
void print_myboard(char **board);
int write_array_in_file(char *file_name, char **arr, int size);
int my_strcmp(char const *s1, char const *s2);
char **my_strtok(char const *string, char *delimitor);
int write_in_file(char *file_name, char *string);
int player_two(navy_t *navy, char **av);
int player_one(navy_t *n, char **av);
void music(navy_t *navy);
char *my_int_to_str(int nbr);
char *read_file(char *file_name);
int create_file(char *file_name);
char **generate_random_map(void);
int get_ship_number(char **map);

#endif  /* __NAVY_H__ */
