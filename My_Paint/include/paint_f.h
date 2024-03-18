/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-malo.chauvry
** File description:
** paint_f.h
*/
#include <SFML/Graphics.h>

#include "paint.h"

#ifndef PAINT_F_H_
    #define PAINT_F_H_

int my_paint(void);


int loop(ressources_t *res);

int get_ressources(ressources_t *ressources);
image_t *get_image(void);
sfCircleShape *get_circle(void);
sfRenderWindow *create_window(void);

void set_pixels(image_t *image_p, status_t *status);

void destroy_all(ressources_t *ressources, image_t *image,
    sfCircleShape *circle);

#endif //PAINT_F_
