/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-malo.chauvry
** File description:
** get_ressources.c
*/
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#include <stdlib.h>

#include "my.h"
#include "paint.h"
#include "paint_f.h"

const char *HELP_PATH[1] = {
    "ressources/Help_tp.png"
};

const char *CURS_PATHS[2] = {
    "ressources/Cursor_pencil.png",
    "ressources/Cursor_erase.png"
};

static int get_cursors(ressources_t *res)
{
    res->cursors_sp = malloc(sizeof(sfSprite *) * MAXCURSOR);
    for (enum CURSORS i = PENCIL; i < MAXCURSOR; i++) {
        res->cursors_sp[i] = sfSprite_create();
        sfSprite_setTexture(res->cursors_sp[i], res->cursors_tx[i], 1);
        sfSprite_setOrigin(res->cursors_sp[i], (sfVector2f){512, 512});
        sfSprite_setScale(res->cursors_sp[i], (sfVector2f){0.1, 0.1});
    }
    for (enum CURSORS i = PENCIL; i < MAXCURSOR; i++)
        if (!res->cursors_sp[i])
            return 0;
    return 1;
}

sfCircleShape *get_circle(void)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineThickness(circle, 2);
    return circle;
}

sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, "my_paint", sfClose || sfTitlebar,
        NULL);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}

static int get_textures(ressources_t *res)
{
    res->cursors_tx = malloc(sizeof(sfTexture *) * MAXCURSOR);
    for (enum CURSORS i = PENCIL; i < MAXCURSOR; i++)
        res->cursors_tx[i] = sfTexture_createFromFile(CURS_PATHS[i], NULL);
    for (enum CURSORS i = PENCIL; i < MAXCURSOR; i++)
        if (!res->cursors_tx[i])
            return 0;
    return 1;
}

static int get_help(ressources_t *res)
{
    res->help = malloc(sizeof(entities_t));
    res->help->texture = sfTexture_createFromFile(HELP_PATH[0], NULL);
    res->help->sprite = sfSprite_create();
    sfSprite_setTexture(res->help->sprite, res->help->texture, sfTrue);
    sfSprite_setPosition(res->help->sprite, (sfVector2f){50, 50});
    if (!res->help->sprite || !res->help->texture)
        return 0;
    return 1;
}

image_t *get_image(void)
{
    image_t *image = malloc(sizeof(image_t));

    image->image = sfImage_createFromColor(1920, 1080, sfWhite);
    image->texture = sfTexture_createFromImage(image->image, NULL);
    image->sprite = sfSprite_create();
    sfSprite_setTexture(image->sprite, image->texture, sfTrue);
    if (!image->image || !image->texture || !image->sprite)
        return NULL;
    return image;
}

int get_ressources(ressources_t *ressources)
{
    int err = 1;

    if (!get_textures(ressources))
        err = 0;
    if (!get_cursors(ressources))
        err = 0;
    if (!get_help(ressources))
        err = 0;
    return err;
}
