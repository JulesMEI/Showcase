/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** contains the prototypes of all functions in libmy.a
*/
#include <sys/stat.h>
#include <stdbool.h>

#ifndef MY_H_
    #define MY_H_

// takes a string as entry and returns it as an array containing
// strings for each splitvalue found contains a bool allowing one
// to keep or remove the given splitvalue
char **my_split(char *str, char splitvalue, bool addstop);
char *my_strfuse(char *first, char *second);
void my_putchar(char c);
void my_putstr(char const *str);
void my_puterrchar(char c);
int my_puterrstr(char const *str);
int my_put_err_nbr(int nb);
int my_strcompare(const char *src, const char *comp);
int my_str_n_compare(const char *src, const char *comp, unsigned int max);
int my_put_nbr(int nb);

// basic reconstruction of printf function
int mini_printf(const char *format, ...);
int error_mini_printf(const char *format, ...);
char *my_strcopy(const char *src);
int my_strlen(const char *src);
int array_len(char **array);
int my_atoi(const char *input);
int get_split_nbr(char *str, char splitvalue);

#endif /* MY_H_ */
