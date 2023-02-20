#include <stdlib.h>

char *my_int_to_str(int nbr)
{
    char *result;
    int len_nbr = 1;
    int z = 10;
    int i = 0;

    for (int len_nbr_find = 0; len_nbr_find != 1; z = z * 10) {
        if (nbr >= z)
            len_nbr++;
        else
            len_nbr_find = 1;
    }
    z = z / 100;
    result = malloc(sizeof(char) * (len_nbr + 1));
    for (i = 0; i < len_nbr; i++) {
        result[i] = (nbr / z) + '0';
        nbr = nbr - (z * ((nbr / z)));
        z = z / 10;
    }
    result[i] = '\0';
    return (result);
}
