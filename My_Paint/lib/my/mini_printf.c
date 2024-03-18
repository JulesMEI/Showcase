/*
** EPITECH PROJECT, 2023
** mini_printf
** File description:
** mini_printf
*/

#include <stdarg.h>
#include <stdio.h>
#include "../../include/my.h"

void conditions(const char *str, int cnt, va_list ap)
{
    switch (str[cnt]) {
    case 's':
        my_putstr(va_arg(ap, char *));
        break;
    case 'd':
    case 'i':
        my_put_nbr(va_arg(ap, int));
        break;
    case '%':
        my_putchar('%');
        break;
    case 'c':
        my_putchar((char) va_arg(ap, int));
    }
}

int mini_printf(const char *format, ...)
{
    va_list ap;
    char *fparam;

    va_start(ap, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            conditions(format, i, ap);
        } else {
            my_putchar(format[i]);
        }
    }
    va_end(ap);
}
