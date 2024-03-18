/*
** EPITECH PROJECT, 2024
** Conway.h
** File description:
** Functions, structs and other components needed
** for the Gameoflife epitech project
*/

#ifndef CONWAY_H_
    #define CONWAY_H_

int game_of_life(char **av);
char **get_map(char const *filename);
char **strarray_dup(char **strarray);
void strarray_copy(char const **arraysrc, char **arraydest);
void free_strarray(char **strarray);
int my_atoi(char const *input);
void trasform_cell(char **result_map, int const x,
    int const y, int const nb_neighbour);
void print_usage(void);
void print_array(char const **array);

#endif
