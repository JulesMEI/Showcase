/*
** EPITECH PROJECT, 2023
** duckmoves
** File description:
** handles duck movements and animations for my hunter project
*/
#include "my_hunter.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <stdio.h>

//handles the movement from left to right
void moveright(ressources_t *ressources, checks_t *events)
{
    ressources->spvector.x += ressources->duckspeed;
    sfSprite_setPosition(ressources->duckspr, ressources->spvector);
    ressources->rect.top = 0;
    sfSprite_setTextureRect(ressources->duckspr, ressources->rect);
    if (ressources->spvector.x >= 914)
        events->duckdirection = LEFT;
}

//handles the movement from right to left
void moveleft(ressources_t *ressources, checks_t *events)
{
    ressources->spvector.x -= ressources->duckspeed;
    sfSprite_setPosition(ressources->duckspr, ressources->spvector);
    ressources->rect.top = 110;
    sfSprite_setTextureRect(ressources->duckspr, ressources->rect);
    if (ressources->spvector.x <= 0)
        events->duckdirection = RIGHT;
}

void moveup(ressources_t *ressources)
{
    if (ressources->spvector.y > 200)
        ressources->spvector.y -= 3;
    if (ressources->spvector.y > 50)
        ressources->spvector.y -= 2;
}

//moves the duck
void duckmove(ressources_t *ressources, checks_t *events)
{
    moveup(ressources);
    if (events->duckdirection == RIGHT)
        moveright(ressources, events);
    if (events->duckdirection == LEFT)
        moveleft(ressources, events);
}

//handles the 3 frames animation of the duck
void duckanimate(ressources_t *ressources, checks_t *events)
{
    if (ressources->rect.left < 220) {
        if (events->timeuntilquack != 0)
            ressources->rect.left += 220;
        else
            ressources->rect.left += 110;
    } else
        ressources->rect.left = 0;
}
