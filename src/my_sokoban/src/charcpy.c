#include <stdlib.h>

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

char *charcpy(char *str, char const c)
{
    int i = 0;
    int n = 0;
    char *dest;

    n = my_strlen(str);
    dest = malloc(sizeof(char) * (n + 2));
    while (str[i] != '\0') {
        dest[i] = str[i];
        i++;
    }
    dest[i] = c;
    dest[i + 1] = '\0';
    return (dest);
}
