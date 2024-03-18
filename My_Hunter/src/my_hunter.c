/*
** EPITECH PROJECT, 2023
** MY_HUNTER.C
** File description:
** clicking on enemies to make them disappear
*/
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <stdio.h>
#include "my_hunter.h"

//checks if duck collision was hit
static void isducktouched(ressources_t *res, checks_t *events)
{
    sfVector2f vect = sfSprite_getPosition(res->duckspr);
    int X = events->mouse.x;
    int Y = events->mouse.y;

    if (X > vect.x && X < vect.x + 110) {
        if (Y > vect.y && Y < vect.y + 110) {
            events->isduckalive = 1;
            sfSprite_setPosition(res->deadspr, vect);
            res->deadvect.x = vect.x;
            res->deadvect.y = vect.y;
            res->spvector.x += 150;
            res->spvector.y = 800;
            sfSprite_setPosition(res->duckspr, res->spvector);
        }
    }
}

//checks if events are triggered
static void scanevents(sfRenderWindow *win, checks_t *ev, ressources_t *res)
{
    while (sfRenderWindow_pollEvent(win, &ev->currevent)) {
        if (ev->currevent.type == sfEvtMouseButtonPressed) {
            sfSound_play(res->bang);
            ev->mouse.x = sfMouse_getPositionRenderWindow(win).x;
            ev->mouse.y = sfMouse_getPositionRenderWindow(win).y;
            isducktouched(res, ev);
            return;
        }
        if (ev->currevent.type == sfEvtClosed)
            sfRenderWindow_close(win);
    }
}

//updates every clock
static void updateclock(timers_t *timer)
{
    timer->movetime = sfClock_getElapsedTime(timer->moveclock);
    timer->animtime = sfClock_getElapsedTime(timer->animclock);
    timer->hundthsec = timer->movetime.microseconds / 10000;
    timer->quartsec = timer->animtime.microseconds / 250000;
}

//gets all the necessary ressources
static int get_ressources(ressources_t *res, timers_t *timers, checks_t *ev)
{
    initializevalues(res, ev);
    if (!getsound(res))
        return 0;
    if (!getsprite(res))
        return 0;
    startclocks(timers);
    return 1;
}

//animates and makes a quack sound
static void quack(ressources_t *res, checks_t *events)
{
    if (events->timeuntilquack == 9 ) {
        events->timeuntilquack = 0;
        res->rect.left = 110;
        sfSound_play(res->quack);
        sfSprite_setTextureRect(res->duckspr, res->rect);
    }
}

//updates the status of the duck
static void updateduck(timers_t *timer, ressources_t *res, checks_t *events)
{
    if (events->isduckalive == 0) {
        if (timer->hundthsec >= 1) {
            duckmove(res, events);
            sfClock_restart(timer->moveclock);
        }
        if (timer->quartsec >= 0.5) {
            duckanimate(res, events);
            sfSound_play(res->flap);
            sfClock_restart(timer->animclock);
            events->timeuntilquack += 1;
            quack(res, events);
        }
    } else {
        deadduckhandling(timer, res, events);
    }
}

//renders the different window effects
static void drawwindow(sfRenderWindow *win, ressources_t res, checks_t ev)
{
    sfRenderWindow_clear(win, sfBlack);
    sfRenderWindow_drawSprite(win, res.bgspr, NULL);
    if (ev.isduckalive == 0)
        sfRenderWindow_drawSprite(win, res.duckspr, NULL);
    if (ev.isduckalive == 1)
        sfRenderWindow_drawSprite(win, res.deadspr, NULL);
    sfRenderWindow_drawSprite(win, res.fgspr, NULL);
    sfRenderWindow_display(win);
}

//refreshes the screen
static int refresh(sfRenderWindow *window)
{
    ressources_t ressources;
    timers_t timer;
    checks_t events;

    if (!get_ressources(&ressources, &timer, &events))
        return 0;
    while (sfRenderWindow_isOpen(window)) {
        updateclock(&timer);
        scanevents(window, &events, &ressources);
        updateduck(&timer, &ressources, &events);
        drawwindow(window, ressources, events);
    }
    destroyall(&ressources, &timer, window);
    return 1;
}

int main(void)
{
    sfRenderWindow *window;
    sfVideoMode mode = {1024, 800, 32};

    window = sfRenderWindow_create(mode, "my_hunter", sfClose, NULL);
    if (!window)
        return (84);
    if (!refresh(window)) {
        return (84);
    }
    return (0);
}
