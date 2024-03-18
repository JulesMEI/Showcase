/*
** EPITECH PROJECT, 2023
** main
** File description:
** test.c
*/
#include <string.h>
#include "my.h"
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    char *input = strtopath("/bin", "ls");
    size_t len;
    char **output;
    int i = 0;

    mini_printf("%s\n", input);
}
