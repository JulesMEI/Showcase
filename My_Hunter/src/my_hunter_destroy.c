/*
** EPITECH PROJECT, 2023
** my_hunter_destroy
** File description:
** destroys ressources in order to properly
** close the program
*/

#include "my_hunter.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <stdio.h>

void destroysys(timers_t *clo, sfRenderWindow *win)
{
    sfClock_destroy(clo->moveclock);
    sfClock_destroy(clo->animclock);
    sfRenderWindow_destroy(win);
}

void destroysnd(ressources_t *res)
{
    sfSound_destroy(res->quack);
    sfSound_destroy(res->bang);
    sfSound_destroy(res->flap);
    sfSound_destroy(res->fall);
    sfSound_destroy(res->land);
    sfSoundBuffer_destroy(res->quackbuf);
    sfSoundBuffer_destroy(res->bangbuf);
    sfSoundBuffer_destroy(res->flapbuf);
    sfSoundBuffer_destroy(res->fallbuf);
    sfSoundBuffer_destroy(res->landbuf);
}

void destroyimg(ressources_t *res)
{
    sfSprite_destroy(res->duckspr);
    sfSprite_destroy(res->bgspr);
    sfSprite_destroy(res->fgspr);
    sfSprite_destroy(res->deadspr);
    sfTexture_destroy(res->ducktext);
    sfTexture_destroy(res->bgtext);
    sfTexture_destroy(res->fgtext);
    sfTexture_destroy(res->deadtext);
}

//destroys all ressources
void destroyall(ressources_t *res, timers_t *clo, sfRenderWindow *win)
{
    destroyimg(res);
    destroysnd(res);
    destroysys(clo, win);
}
