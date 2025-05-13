/*
** EPITECH PROJECT, 2024
** C Pool Day 08 - Task 04
** File description:
** my_nbr_to_str
** split string into words
*/

#include "../include/core.h"

int my_nbr_to_str_edge_cases(char *str, int *nb)
{
    if (*nb == 0) {
        str[0] = '0';
        return 2;
    }
    if (*nb < 0) {
        *nb = *nb * -1;
        str[0] = '-';
        return 1;
    }
    return 0;
}

static int is_minus(int minus, char *str, int i)
{
    if (minus == 1) {
        str[i] = '-';
        str[i + 1] = '\0';
        return 0;
    }
    if (minus == 2) {
        str[i + 1] = '\0';
        return 0;
    }
    str[i] = '\0';
    return 0;
}

char *my_nbr_to_str(int nb)
{
    int calc = 0;
    char *str = malloc(sizeof(int));
    int *nbp = &nb;
    int i = 0;
    int minus = my_nbr_to_str_edge_cases(str, nbp);

    if (!str)
        return NULL;
    while (nb > 0) {
        calc = nb % 10;
        nb = nb / 10;
        str[i] = calc + 48;
        i++;
    }
    is_minus(minus, str, i);
    my_revstr(str);
    return (str);
}
