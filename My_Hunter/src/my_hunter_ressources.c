/*
** EPITECH PROJECT, 2023
** my_hunter_ressources
** File description:
** gets necessary ressources for my hunter main
*/
#include "my_hunter.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <stdio.h>

//recovers sound effect
int getsound(ressources_t *input)
{
    input->quack = sfSound_create();
    input->bang = sfSound_create();
    input->flap = sfSound_create();
    input->fall = sfSound_create();
    input->land = sfSound_create();
    input->quackbuf = sfSoundBuffer_createFromFile("ressources/Quack.ogg");
    input->bangbuf = sfSoundBuffer_createFromFile("ressources/Bang.ogg");
    input->flapbuf = sfSoundBuffer_createFromFile("ressources/Flap.ogg");
    input->fallbuf = sfSoundBuffer_createFromFile("ressources/Fall.ogg");
    input->landbuf = sfSoundBuffer_createFromFile("ressources/Land.ogg");
    if (!input->quackbuf || !input->bangbuf || !input->flapbuf ||
        !input->fallbuf || !input->landbuf)
        return 0;
    sfSound_setBuffer(input->quack, input->quackbuf);
    sfSound_setBuffer(input->bang, input->bangbuf);
    sfSound_setBuffer(input->flap, input->flapbuf);
    sfSound_setBuffer(input->fall, input->fallbuf);
    sfSound_setBuffer(input->land, input->landbuf);
    return 1;
}

//recovers textures from designated files
int gettexture(ressources_t *re)
{
    re->ducktext = sfTexture_createFromFile("ressources/duck.png", NULL);
    re->bgtext = sfTexture_createFromFile("ressources/Back.png", NULL);
    re->fgtext = sfTexture_createFromFile("ressources/Fore.png", NULL);
    re->deadtext = sfTexture_createFromFile("ressources/dead.png", NULL);
    if (!re->ducktext || !re->bgtext || !re->fgtext || !re->deadtext)
        return 0;
    else
        return 1;
}

//initializes diverse values to setup the game properly
void initializevalues(ressources_t *ressources, checks_t *events)
{
    events->isduckalive = 0;
    events->duckdirection = RIGHT;
    events->timeuntilquack = 1;
    events->timeuntilrespawn = 0;
    ressources->duckspeed = 3;
    ressources->spvector.x = 0;
    ressources->spvector.y = 800;
    ressources->deadvect.x = 0;
    ressources->deadvect.y = 0;
    ressources->rect.height = 220;
    ressources->rect.width = 330;
    ressources->rect.top = 0;
    ressources->rect.left = 0;
    ressources->rectdead.height = 110;
    ressources->rectdead.width = 110;
    ressources->rectdead.top = 0;
    ressources->rectdead.left = 0;
}

//recovers sprite and gives it dependant values
int getsprite(ressources_t *ressources)
{
    sfVector2f bgsize = {4, 4};

    if (!gettexture(ressources))
        return 0;
    ressources->duckspr = sfSprite_create();
    ressources->deadspr = sfSprite_create();
    ressources->bgspr = sfSprite_create();
    ressources->fgspr = sfSprite_create();
    sfSprite_setTexture(ressources->duckspr, ressources->ducktext, sfTrue);
    sfSprite_setTexture(ressources->bgspr, ressources->bgtext, sfTrue);
    sfSprite_setTexture(ressources->fgspr, ressources->fgtext, sfTrue);
    sfSprite_setTexture(ressources->deadspr, ressources->deadtext, sfTrue);
    sfSprite_setScale(ressources->bgspr, bgsize);
    sfSprite_setScale(ressources->fgspr, bgsize);
    ressources->rect.height = 110;
    ressources->rect.width = 110;
    sfSprite_setTextureRect(ressources->duckspr, ressources->rect);
    sfSprite_setTextureRect(ressources->deadspr, ressources->rect);
    return 1;
}

//starts every clocks
int startclocks(timers_t *timers)
{
    timers->moveclock = sfClock_create();
    timers->animclock = sfClock_create();
    if (!timers->moveclock || !timers->animclock)
        return 0;
    return 1;
}
