#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int my_strlen(char const *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}

char *my_strdup(char const *src)
{
    int len_str = my_strlen(src);
    char *dest = malloc(sizeof(char) * (len_str + 1));
    int i = 0;

    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}

char **do_my_array(char *str, char **arr, int len_arr, char c)
{
    int len_str = 0;

    for (int i = 0; i != len_arr; i++) {
        for (; (str[len_str] != c && str[len_str] != '\0'); len_str++);
        arr[i] = malloc(sizeof(char) * (len_str + 1));
        arr[i][len_str] = '\0';
        for (int z = 0; (str[z] != c && str[z] != '\0') ; z++)
            arr[i][z] = (str[z]);
        str += (len_str + 1);
        len_str = 0;
    }
    return (arr);
}

char **ar_arrange(char **arr)
{
    char **dest = NULL;
    int d = 0;
    int len_dest = 0;

    for (int i = 0; arr[i] != NULL; i++) {
        if (arr[i][0] != '\0') {
            len_dest ++;
        }
    }
    dest = malloc(sizeof(char*) * (len_dest + 1));
    for (int i = 0; arr[i] != NULL; i++) {
        if (arr[i][0] != '\0') {
            dest[d] = arr[i];
            d++;
        } else
            free(arr[i]);
    }
    dest[d] = NULL;
    return (dest);
}

char *get_delimin(char *delimitor, char *str, int i)
{
    char c = '$';

    for (int j = 0; delimitor[j] != '\0'; j++)
        if (str[i] == delimitor[j])
            str[i] = c;
    return (str);
}

char **my_strtok(char const *string, char *delimitor)
{
    char c = '$';
    int len_arr = 1;
    char **arr = NULL;
    char *str = my_strdup(string);

    for (int i = 0; str[i] != '\0'; i++)
        str = get_delimin(delimitor, str, i);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            len_arr++;
    }
    arr = malloc(sizeof(char*) * (len_arr + 1));
    arr[len_arr] = NULL;
    arr = do_my_array(str, arr, len_arr, c);
    arr = ar_arrange(arr);
    free(str);
    return (arr);
}