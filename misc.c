
#include "header.h"

// File for simple function to use in other files

int char_is_in(char c, char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return i;
    return -1;
}

int str_is_in(char *str, char **arr)
{
    int i;

    for (i = 0; arr[i] != NULL; i++)
        if (strcmp(arr[i],  str) == 0)
            return i;
    return -1;
}