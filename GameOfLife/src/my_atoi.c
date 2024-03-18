/*
** EPITECH PROJECT, 2023
** my_atoi
** File description:
** takes a string as parameter and returns it as an int
*/

int my_atoi(char const *input)
{
    int returnvalue = 0;
    int nbcheck = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        returnvalue += input[i] - '0';
        nbcheck = input[i] - '0';
        if (nbcheck < 0 || nbcheck > 9)
            return -1;
        if (input[i + 1] != '\0')
            returnvalue = returnvalue * 10;
    }
    return returnvalue;
}
