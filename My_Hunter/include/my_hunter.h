/*
** EPITECH PROJECT, 2023
** MY_HUNTER.H
** File description:
** header file for the my_hunter project
*/
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>

#ifndef MY_HUNTER_H_
    #define MY_HUNTER_H_

typedef struct ressources {
    sfSprite *duckspr;
    sfSprite *bgspr;
    sfSprite *fgspr;
    sfSprite *deadspr;
    sfTexture *ducktext;
    sfTexture *deadtext;
    sfTexture *bgtext;
    sfTexture *fgtext;
    sfIntRect rect;
    sfIntRect rectdead;
    sfSound *quack;
    sfSound *bang;
    sfSound *flap;
    sfSound *fall;
    sfSound *land;
    sfSoundBuffer *quackbuf;
    sfSoundBuffer *bangbuf;
    sfSoundBuffer *flapbuf;
    sfSoundBuffer *fallbuf;
    sfSoundBuffer *landbuf;
    sfVector2f spvector;
    sfVector2f deadvect;
    int duckspeed;
} ressources_t;
typedef struct clock {
    sfClock *animclock;
    sfClock *moveclock;
    sfTime animtime;
    sfTime movetime;
    float twosec;
    float thqrtsecs;
    float quartsec;
    float hundthsec;
    float curtime;
    float prevtime;
} timers_t;
typedef struct events {
    sfEvent currevent;
    sfMouseButtonEvent mouse;
    int isduckalive;
    int duckdirection;
    int timeuntilquack;
    int timeuntilrespawn;
} checks_t;
typedef enum direction {
    LEFT,
    RIGHT
} dir_t;
int getsound(ressources_t *input);
int gettexture(ressources_t *re);
int getsprite(ressources_t *ressources);
int startclocks(timers_t *timers);
void duckmove(ressources_t *ressources, checks_t *events);
void duckanimate(ressources_t *ressources, checks_t *events);
void initializevalues(ressources_t *ressources, checks_t *events);
void deadduckmove(ressources_t *ressources, checks_t *events);
void deadduckanim(ressources_t *ressources);
void deadduckhandling(timers_t *timer, ressources_t *res, checks_t *events);
void destroysys(timers_t *clo, sfRenderWindow *win);
void destroysnd(ressources_t *res);
void destroyimg(ressources_t *res);
void destroyall(ressources_t *res, timers_t *clo, sfRenderWindow *win);
#endif //MY_HUNTER_H
