/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-malo.chauvry
** File description:
** drawing.c
*/
#include <math.h>

#include "paint.h"
#include "paint_f.h"
#include "my.h"

static void inbound_draw(image_t *image, unsigned int x, unsigned int y,
    status_t *status)
{
    sfVector2u size = sfImage_getSize(image->image);

    if (x > size.x - 1 || y > size.y - 1)
        return;
    if (status->brush_type != ERASE) {
        sfImage_setPixel(image->image, x, y, status->color);
        if (x + 1 < size.x)
            sfImage_setPixel(image->image, x + 1, y, status->color);
    } else {
        sfImage_setPixel(image->image, x, y, sfWhite);
        if (x + 1 < size.x)
            sfImage_setPixel(image->image, x + 1, y, sfWhite);
    }
}

void set_pixels(image_t *image, status_t *status)
{
    int size = status->brush_size;
    sfVector2u mp = (sfVector2u){status->ms_pos.x, status->ms_pos.y};

    for (int y = size; size > 0; size--) {
        y = size;
        for (int x = 0; x <= y; x++) {
            inbound_draw(image, (mp.x + x), (mp.y + y), status);
            inbound_draw(image, (mp.x + x), (mp.y - y), status);
            inbound_draw(image, (mp.x - x), (mp.y + y), status);
            inbound_draw(image, (mp.x - x), (mp.y - y), status);
            inbound_draw(image, (mp.x + y), (mp.y + x), status);
            inbound_draw(image, (mp.x + y), (mp.y - x), status);
            inbound_draw(image, (mp.x - y), (mp.y + x), status);
            inbound_draw(image, (mp.x - y), (mp.y - x), status);
            y -= (sqrt(x * x + y * y) > size) ? 1 : 0;
        }
    }
}
