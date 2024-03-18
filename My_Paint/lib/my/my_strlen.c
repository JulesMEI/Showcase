/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** strlen remake
*/
#include <stddef.h>

int my_strlen(const char *src)
{
    int cnt = 0;

    while (src[cnt] != '\0')
        cnt++;
    return cnt;
}

int array_len(char **array)
{
    int size = 0;

    while (array[size] != NULL)
        size++;
    return size;
}
