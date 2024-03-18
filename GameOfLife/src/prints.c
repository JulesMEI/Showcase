/*
** EPITECH PROJECT, 2024
** prints.c
** File description:
** multiple prints for game_of_life project
*/
#include <stdio.h>
#include <unistd.h>

void print_usage(void)
{
    write(2, "USAGE\n"
        "\tgameoflife [filename] [n]\n"
        "DESCRIPTION\n"
        "\tConway's game of life reproduction\n"
        "\twill take [filename] as map parameter, must contain\n"
        "\tonly the 'X' and '.' characters in a rectangle formation.\n"
        "\tWill iterate [n] times and print the result "
        "to the standard output.\n"
        , 263);
}

void print_array(char const **array)
{
    for (size_t i = 0; array[i] != NULL; i++) {
        printf("%s\n", array[i]);
    }
}
