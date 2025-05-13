/*
** EPITECH PROJECT, 2024
** C Pool Day 03 - Task 06
** File description:
** This file contains my definition of the my_put_nbr
** which shows the number given
*/
#include "../include/core.h"
#include "../include/io.h"

void my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        my_put_nbr(147483648);
        return;
    }
    if (nb <= -1) {
        nb = nb * -1;
        my_putchar('-');
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
}
