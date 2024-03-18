/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-malo.chauvry
** File description:
** paint.h
*/
#include <SFML/Graphics.h>

#include <stdbool.h>

#ifndef PAINT_H
    #define PAINT_H

    #define SPRITE_SIZE 768

typedef struct button_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfRectangleShape *rect;
    sfVector2i *position;
    sfVector2i *size;
    sfColor color;
} button_t;

typedef struct entities_s {
    sfSprite *sprite;
    sfTexture *texture;
} entities_t;

typedef struct status_s {
    int brush_type;
    bool toolbar;
    sfColor color;
    unsigned int brush_size;
    sfVector2i ms_pos;
    bool clicked;
} status_t;

typedef struct image_s {
    sfImage *image;
    sfTexture *texture;
    sfSprite *sprite;
}image_t;

typedef struct ressources_s {
    button_t **buttons;
    sfTexture **cursors_tx;
    sfSprite **cursors_sp;
    sfRenderWindow *window;
    entities_t *help;
} ressources_t;

enum BUTTON_CLR {
    BLACK,
    WHITE,
    RED,
    GREEN,
    BLUE,
    YELLOW,
    MAGENTA,
    CYAN,
    MAXCOLOR
};

enum CURSORS {
    PENCIL,
    ERASE,
    MAXCURSOR
};

#endif
