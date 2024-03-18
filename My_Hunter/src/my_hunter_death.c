/*
** EPITECH PROJECT, 2023
** my_hunter_death
** File description:
** handles the death animation and other shenanigans
*/
#include "my_hunter.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <stdio.h>

void deadduckmove(ressources_t *ressources, checks_t *events)
{
    if (ressources->deadvect.y <= 1000)
        ressources->deadvect.y += 5;
    sfSprite_setPosition(ressources->deadspr, ressources->deadvect);
    if (ressources->deadvect.y >= 800 && ressources->deadvect.y <= 804) {
        sfSound_play(ressources->land);
        sfSound_stop(ressources->fall);
    }
    if (ressources->deadvect.y > 1000) {
        events->isduckalive = 0;
        events->timeuntilrespawn = 0;
        ressources->rectdead.left = 0;
    }
}

void deadduckanim(ressources_t *ressources)
{
    if (ressources->rectdead.left < 220)
        ressources->rectdead.left += 110;
    else
        ressources->rectdead.left = 110;
    sfSprite_setTextureRect(ressources->deadspr, ressources->rectdead);
}

void deadduckhandling(timers_t *timer, ressources_t *res, checks_t *events)
{
    sfSprite_setTextureRect(res->deadspr, res->rectdead);
    if (timer->quartsec >= 0.5) {
        events->timeuntilrespawn += 1;
        sfClock_restart(timer->animclock);
        if (events->timeuntilrespawn == 3)
            sfSound_play(res->fall);
        if (events->timeuntilrespawn > 2) {
            deadduckanim(res);
        }
    }
    if (events->timeuntilrespawn > 2)
        if (timer->hundthsec >= 1) {
            deadduckmove(res, events);
            sfClock_restart(timer->moveclock);
    }
}
