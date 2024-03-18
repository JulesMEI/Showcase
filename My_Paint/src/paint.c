/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-malo.chauvry
** File description:
** paint.c
*/
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>

#include <stdlib.h>

#include "paint.h"
#include "paint_f.h"

int my_paint(void)
{
    ressources_t *ressources = malloc(sizeof(ressources_t));

    ressources->window = create_window();
    if (!get_ressources(ressources))
        return 0;
    return loop(ressources);
}
