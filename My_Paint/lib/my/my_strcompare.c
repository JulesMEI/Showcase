/*
** EPITECH PROJECT, 2023
** my_strcompare
** File description:
** compares two strings and returns 1 if both are similar
** or 0 if they are different
*/
int my_str_n_compare(const char *src, const char *comp, unsigned int max)
{
    for (int i = 0; src[i] != '\0' && i < max; i++)
        if (src[i] != comp[i])
            return 0;
    return 1;
}

int my_strcompare(const char *src, const char *comp)
{
    for (int i = 0; src[i] != '\0'; i++)
        if (src[i] != comp[i])
            return 0;
    return 1;
}
