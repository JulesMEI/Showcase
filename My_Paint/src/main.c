/*
** EPITECH PROJECT, 2023
** main
** File description:
** main.c
*/
#include "my.h"
#include "paint.h"
#include "paint_f.h"

void print_help(void)
{
    mini_printf("USAGE :\n"
    "\t./my_paint\n"
    "DESCRIPTION :\n"
    "\tpaint remake, allows to draw pixels on a screen\n");
}

int main(int ac, char **av)
{
    if (ac > 1 && my_strcompare(av[1], "-h"))
        print_help();
    else
        return my_paint();
}
