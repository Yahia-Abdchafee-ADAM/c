#include <unistd.h>
#include <SFML/Audio.h>

#ifndef __NAVY_H__
    #define __NAVY_H__

typedef struct navy_s {
    char *map;
    char *player_one_map;
    char *player_two_map;
    pid_t player_one_pid;
    pid_t player_two_pid;
    char **dico_of_attack;
    sfMusic *music;
} navy_t;

int my_strcmp(char const *s1, char const *s2);
char **my_strtok(char const *string, char *delimitor);
int write_in_file(char *file_name, char *string);
int player_two(navy_t *navy, char **av);
int player_one(navy_t *n, char **av);
void music(navy_t *navy);
char *my_int_to_str(int nbr);
char *read_file(char *file_name);
int create_file(char *file_name);
int attack_value(char *attack);

#endif  /* __NAVY_H__ */
