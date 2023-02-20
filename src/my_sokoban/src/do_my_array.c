
#include <stdlib.h>
#include <stddef.h>

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
