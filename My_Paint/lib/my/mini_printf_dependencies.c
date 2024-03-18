/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** my_putstr
*/

#include <unistd.h>
#include "../../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_puterrchar(char c)
{
    write(2, &c, 1);
}

void my_putstr(char const *str)
{
    if (!str)
        return;
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
}

int my_puterrstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_puterrchar(str[i]);
    }
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
    return nb;
}
