/*
** EPITECH PROJECT, 2024
** Game of Life
** File description:
** Conway's game of life mini remake
*/
#include "conway.h"

int main(int ac, char **av)
{
    if (ac != 3) {
        print_usage();
        return 84;
    }
    return game_of_life(av);
}
