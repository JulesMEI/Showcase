/*
** EPITECH PROJECT, 2024
** gameofile
** File description:
** main file for gameoflife project
*/
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>

#include "conway.h"

static int scan_neighbours(char **mapbuf, int posy, int posx)
{
    int start = posx - 1;
    int cell = 0;

    if (posx == 0)
        start++;
    if (posy != 0)
        for (int x = start; x < posx + 2; x++)
            cell += (mapbuf[posy - 1][x] == 'X') ? 1 : 0;
    if (posx != 0 && mapbuf[posy][posx - 1] == 'X')
        cell += 1;
    if (mapbuf[posy][posx + 1] == 'X')
        cell += 1;
    for (int x = start; mapbuf[posy + 1] != 0 && x < posx + 2; x++)
        if (mapbuf[posy + 1][x] == 'X')
            cell += 1;
    return cell;
}

static void change_map(char **map, char **mapbuf)
{
    for (int i = 0; mapbuf[i] != NULL; i++) {
        for (int j = 0; mapbuf[i][j] != '\0'; j++) {
            trasform_cell(map, j, i, scan_neighbours(mapbuf, i, j));
        }
    }
}

static void do_main_loop(char **map, char **mapbuf, size_t const iterations)
{
    initscr();
    noecho();
    cbreak();
    curs_set(0);

    for (size_t i = 0; i < iterations; i++) {
        change_map(map, mapbuf);
        strarray_copy((char const **)map, mapbuf);
        refresh();
        usleep(100000);
        for (int i = 0; mapbuf[i] != NULL; i++)
            mvprintw(i + (sizeof(mapbuf)), strlen(mapbuf[i]) / 2, mapbuf[i]);
    }
    endwin();
}

int game_of_life(char **av)
{
    char **map = NULL;
    char **mapbuf = NULL;
    int iterations = my_atoi(av[2]);

    if (iterations < 0) {
        return 84;
    }
    map = get_map(av[1]);
    if (!map) {
        return 84;
    }
    mapbuf = strarray_dup(map);
    do_main_loop(map, mapbuf, iterations);
    print_array((char const **)map);
    free_strarray(map);
    free_strarray(mapbuf);
    return 0;
}
