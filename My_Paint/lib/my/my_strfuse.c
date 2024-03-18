/*
** EPITECH PROJECT, 2023
** main
** File description:
** my_strfuse.c
*/
#include "../../include/my.h"
#include <stdlib.h>
#include <stdio.h>

char *my_strfuse(char *first, char *second)
{
    int firstlen = my_strlen(first);
    int seclen = my_strlen(second);
    char *dest = malloc(sizeof(char) * firstlen + seclen + 1);

    for (int i = 0; first[i]; i++)
        dest[i] = first[i];
    for (int i = 0; second[i]; i++) {
        dest[firstlen] = second[i];
        firstlen++;
    }
    return dest;
}

char *strtopath(char *first, char *second)
{
    int firstlen = my_strlen(first);
    int seclen = my_strlen(second);
    char *dest = malloc(sizeof(char) * firstlen + seclen + 2);

    for (int i = 0; first[i]; i++)
        dest[i] = first[i];
    dest[firstlen] = '/';
    firstlen++;
    for (int i = 0; second[i]; i++) {
        dest[firstlen] = second[i];
        firstlen++;
    }
    return dest;
}
