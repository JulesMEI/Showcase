/*
** EPITECH PROJECT, 2023
** my_strcopy
** File description:
** strcopy remake
*/
#include <stdio.h>
#include <stdlib.h>
#include "../../include/my.h"

char *my_strcopy(const char *src)
{
    int cnt;
    int size;
    char *dest;

    size = my_strlen(src);
    dest = malloc(size + 1);
    for (cnt = 0; src[cnt] != '\0'; cnt++)
        dest[cnt] = src[cnt];
    dest[cnt] = '\0';
    return (dest);
}
