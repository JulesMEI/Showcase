/*
** EPITECH PROJECT, 2023
** mini_printf
** File description:
** mini_printf
*/

#include <stdarg.h>
#include <stdio.h>
#include "../../include/my.h"

void error_conditions(const char *str, int cnt, va_list ap)
{
    switch (str[cnt]) {
    case 's':
        my_puterrstr(va_arg(ap, char *));
        break;
    case '%':
        my_puterrchar('%');
        break;
    case 'c':
        my_puterrchar((char) va_arg(ap, int));
        break;
    case 'd':
    case 'i':
        my_put_err_nbr(va_arg(ap, int));
    }
}

int my_put_err_nbr(int nb)
{
    if (nb < 0) {
        my_puterrchar('-');
        nb = -nb;
    }
    if (nb >= 10) {
        my_put_err_nbr(nb / 10);
    }
    my_puterrchar(nb % 10 + '0');
    return nb;
}

int error_mini_printf(const char *format, ...)
{
    va_list ap;
    char *fparam;

    va_start(ap, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            error_conditions(format, i, ap);
        } else {
            my_puterrchar(format[i]);
        }
    }
    va_end(ap);
}
