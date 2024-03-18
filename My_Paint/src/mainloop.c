/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-malo.chauvry
** File description:
** mainloop.c
*/
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#include "paint.h"
#include "paint_f.h"

static void draw_calls(status_t *status, sfRenderWindow *win, sfEvent evt,
    image_t *image)
{
    if (evt.type == sfEvtMouseButtonPressed && !status->clicked) {
        status->clicked = true;
        status->ms_pos = sfMouse_getPositionRenderWindow(win);
        set_pixels(image, status);
    }
    if (evt.type == sfEvtMouseButtonReleased)
        status->clicked = false;
    if (status->clicked && evt.type == sfEvtMouseMoved) {
        status->ms_pos = sfMouse_getPositionRenderWindow(win);
        set_pixels(image, status);
    }
}

static void change_color(status_t *status, sfEvent evt)
{
    if (evt.type == sfEvtKeyPressed) {
        if (sfKeyboard_isKeyPressed(sfKeyNum1))
            status->color = sfBlack;
        if (sfKeyboard_isKeyPressed(sfKeyNum2))
            status->color = sfWhite;
        if (sfKeyboard_isKeyPressed(sfKeyNum3))
            status->color = sfRed;
        if (sfKeyboard_isKeyPressed(sfKeyNum4))
            status->color = sfGreen;
        if (sfKeyboard_isKeyPressed(sfKeyNum5))
            status->color = sfBlue;
        if (sfKeyboard_isKeyPressed(sfKeyNum6))
            status->color = sfYellow;
        if (sfKeyboard_isKeyPressed(sfKeyNum7))
            status->color = sfMagenta;
        if (sfKeyboard_isKeyPressed(sfKeyNum8))
            status->color = sfCyan;
    }
}

static void change_brush(status_t *status, sfEvent evt)
{
    if (evt.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyB)) {
        status->brush_type = PENCIL;
    }
    if (evt.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyE)) {
        status->brush_type = ERASE;
    }
    if (evt.type == sfEvtMouseWheelScrolled && evt.mouseWheelScroll.delta > 0
        && status->brush_size < 200)
        status->brush_size += 2;
    if (evt.type == sfEvtMouseWheelScrolled && evt.mouseWheelScroll.delta < 0
        && status->brush_size > 1)
        status->brush_size -= 2;
}

static void scanevents(sfRenderWindow *win, image_t *image, status_t *status)
{
    sfEvent evt;

    while (sfRenderWindow_pollEvent(win, &evt)) {
        if (evt.type == sfEvtClosed || (evt.type == sfEvtKeyPressed &&
            (sfKeyboard_isKeyPressed(sfKeyEscape) ||
            sfKeyboard_isKeyPressed(sfKeyQ))))
            sfRenderWindow_close(win);
        if (evt.type == sfEvtKeyPressed && (sfKeyboard_isKeyPressed(sfKeyS)))
            sfImage_saveToFile(image->image, "paint.png");
        if (evt.type == sfEvtKeyPressed &&
            (sfKeyboard_isKeyPressed(sfKeyTab)))
            status->toolbar = !status->toolbar;
        if (evt.type == sfEvtKeyPressed && (sfKeyboard_isKeyPressed(sfKeyR))) {
            sfImage_destroy(image->image);
            image->image = sfImage_createFromColor(1920, 1080, sfWhite);
        }
        change_color(status, evt);
        draw_calls(status, win, evt, image);
        change_brush(status, evt);
    }
}

static void draw_brush(ressources_t *res, status_t stat)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(res->window);

    if (stat.brush_type < MAXCURSOR) {
        sfSprite_setPosition(res->cursors_sp[stat.brush_type],
            (sfVector2f){mouse_pos.x, mouse_pos.y});
        sfRenderWindow_drawSprite(res->window,
            res->cursors_sp[stat.brush_type], NULL);
    }
}

static void draw_circle(sfRenderWindow *window, sfCircleShape *circle,
    status_t status)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    sfCircleShape_setRadius(circle, status.brush_size);
    sfCircleShape_setOutlineColor(circle, status.color);
    sfCircleShape_setOrigin(circle, (sfVector2f){status.brush_size,
        status.brush_size});
    sfCircleShape_setPosition(circle, (sfVector2f){mouse_pos.x, mouse_pos.y});
    sfRenderWindow_drawCircleShape(window, circle, NULL);
}

static void render_window(ressources_t *res, image_t *image, status_t status,
    sfCircleShape *circle)
{
    sfTexture_updateFromImage(image->texture, image->image, 0, 0);
    sfRenderWindow_clear(res->window, sfBlack);
    sfRenderWindow_drawSprite(res->window, image->sprite, NULL);
    draw_circle(res->window, circle, status);
    if (status.toolbar == true)
        sfRenderWindow_drawSprite(res->window, res->help->sprite, NULL);
    draw_brush(res, status);
    sfRenderWindow_display(res->window);
}

int loop(ressources_t *ressources)
{
    status_t status = {0, sfTrue, sfBlack, 25, {0, 0}, false};
    image_t *image = get_image();
    sfCircleShape *circle = get_circle();

    while (sfRenderWindow_isOpen(ressources->window)) {
        scanevents(ressources->window, image, &status);
        render_window(ressources, image, status, circle);
    }
    destroy_all(ressources, image, circle);
    return 0;
}
