/*
** EPITECH PROJECT, 2024
** transform_cell
** File description:
** transform one cell based on neighbouring cells
*/

void trasform_cell(char **result_map, int const x,
    int const y, int const nb_neighbour)
{
    if (nb_neighbour == 3 && result_map[y][x] == '.')
        result_map[y][x] = 'X';
    if ((nb_neighbour < 2 || nb_neighbour > 3) && result_map[y][x] == 'X')
        result_map[y][x] = '.';
}
