/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** converts string into word array
*/
#include <stdlib.h>
#include <stdbool.h>
#include "../../include/my.h"

char **mallocheight(char *str, char splitvalue)
{
    int cnt = 2;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == splitvalue)
            cnt++;
    return malloc(sizeof(char *) * cnt);
}

void clean_array(char ***src)
{
    char **array = *src;
    int i = 0;

    if (!array[0][0])
        return;
    while (my_strlen(array[0]) == 0) {
        for (int i = 0; array[i] != NULL; i++)
            array[i] = array[i + 1];
    }
    for (i = 0; array[i + 1]; i++);
    if (my_strlen(array[i]) == 0)
        array[i] = NULL;
}

char *get_first_word(char *str)
{
    int i = 0;

    for (i = 0; str[i] == ' '; i++);
    return &str[i];
}

char **my_split(char *str, char splitvalue, bool addstop)
{
    int y = 1;
    char **arr = mallocheight(str, splitvalue);

    arr[0] = get_first_word(str);
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] == splitvalue || str[i] == '\n')
        && (str[i + 1] == splitvalue || str[i + 1] == '\0') && addstop) {
            str[i] = '\0';
            continue;
        }
        if (str[i] == splitvalue) {
            arr[y] = &str[i + 1];
            y++;
        }
        if (str[i] == splitvalue && addstop)
            str[i] = '\0';
    }
    arr[y] = NULL;
    clean_array(&arr);
    return arr;
}
