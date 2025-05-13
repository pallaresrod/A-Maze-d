/*
** EPITECH PROJECT, 2024
** C Pool Day 03 - Task 04
** File description:
** printinf functions for printf
*/

#include "my_miniprintf.h"
#include "../../include/core.h"
#include "../../include/io.h"

int print_d(va_list *list, int *char_count)
{
    int d2 = va_arg(*list, int);

    my_put_nbr(d2);
    return 0;
}

int print_c(va_list *list, int *char_count)
{
    char c2 = (char)va_arg(*list, int);

    my_putchar(c2);
    return 0;
}

int print_s(va_list *list, int *char_count)
{
    char *s = va_arg(*list, char *);

    my_putstr(s);
    return 0;
}
