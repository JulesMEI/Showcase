/*
** EPITECH PROJECT, 2024
** free_strarray
** File description:
** free strarray
*/

#include <stdlib.h>

void free_strarray(char **strarray)
{
    for (int i = 0; strarray[i] != 0; i++)
        free(strarray[i]);
    free(strarray);
}
