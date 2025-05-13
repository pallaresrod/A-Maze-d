/*
** EPITECH PROJECT, 2024
** C Pool Day 08 - Task 04
** File description:
** my_str_to_word_array
** split string into words
*/

#include "../include/core.h"

static int is_minus(int *i, char *str)
{
    int minus = 1;

    if (str[0] == '-') {
        (*i)++;
        minus = -1;
    }
    return minus;
}

float obtain_decimal(char *str, int *i)
{
    float nbr = 0;
    float multiplier = 0.1;

    if (str[*i] == '.')
        (*i)++;
    while (str[*i]) {
        nbr += (str[*i] - '0') * multiplier;
        multiplier *= 0.1;
        (*i)++;
    }
    return nbr;
}

float obtain_int(int *i, char *str)
{
    float nbr = 0;

    while (str[*i] && str[*i] != '.') {
        nbr = nbr * 10 + (str[*i] - '0');
        (*i)++;
    }
    return nbr;
}

float my_str_to_float(char *str)
{
    float nbr = 0;
    int i = 0;
    int minus = 1;
    float result;

    minus = is_minus(&i, str);
    nbr = obtain_int(&i, str);
    nbr += obtain_decimal(str, &i);
    result = nbr * minus;
    return result;
}
