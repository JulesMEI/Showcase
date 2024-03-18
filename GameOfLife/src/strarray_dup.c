/*
** EPITECH PROJECT, 2024
** strarray_dup
** File description:
** dup an strarray
*/

#include <stdlib.h>
#include <string.h>

static int strarray_len(char **strarray)
{
    int len = 0;

    if (strarray == 0)
        return -1;
    for (; strarray[len] != 0; len++);
    return len;
}

char **strarray_dup(char **strarray)
{
    int len = strarray_len(strarray);
    char **dup;

    if (len == 0)
        return 0;
    dup = malloc(sizeof(char *) * (len + 1));
    if (dup == 0)
        return 0;
    for (int i = 0; i < len; i++)
        dup[i] = strdup(strarray[i]);
    dup[len] = 0;
    return dup;
}

void strarray_copy(char const **arraysrc, char **arraydest)
{
    for (int i = 0; arraysrc[i] != NULL; i++)
        strcpy(arraydest[i], arraysrc[i]);
}
