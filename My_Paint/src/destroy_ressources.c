/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-malo.chauvry
** File description:
** destroy_ressources.c
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#include <stdlib.h>

#include "my.h"
#include "paint.h"
#include "paint_f.h"


static void destroy_sprites(ressources_t *res)
{
    for (enum CURSORS i = PENCIL; i < MAXCURSOR; i++) {
        sfSprite_destroy(res->cursors_sp[i]);
    }
    free(res->cursors_sp);
}

static void destroy_textures(ressources_t *res)
{
    for (enum CURSORS i = PENCIL; i < MAXCURSOR; i++)
        sfTexture_destroy(res->cursors_tx[i]);
    free(res->cursors_tx);
}

static void destroy_image(image_t *image)
{
    sfSprite_destroy(image->sprite);
    sfTexture_destroy(image->texture);
    sfImage_destroy(image->image);
    free(image);
}

static void destroy_help(ressources_t *res)
{
    sfSprite_destroy(res->help->sprite);
    sfTexture_destroy(res->help->texture);
    free(res->help);
}

void destroy_all(ressources_t *ressources, image_t *image,
    sfCircleShape *circle)
{
    destroy_sprites(ressources);
    destroy_textures(ressources);
    destroy_help(ressources);
    sfCircleShape_destroy(circle);
    destroy_image(image);
    free(ressources);
}
