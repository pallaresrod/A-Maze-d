/*
** EPITECH PROJECT, 2024
** C Pool Day 03 - Task 04
** File description:
** This file contains my definition of the my_isneg
** returns if a value is positive or negative
*/

#include "../include/io.h"

int my_isneg(int nb)
{
    if (nb >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    return 0;
}
