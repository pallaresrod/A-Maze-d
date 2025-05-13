/*
** EPITECH PROJECT, 2024
** C Pool Day 05 - Task 05
** File description:
** This file contains my definition of sqr root
** computes square root
*/

int my_compute_square_root(int nb)
{
    if (nb <= 0) {
        return 0;
    }
    for (int i = 1; i <= nb; i++) {
        if ((i * i) == nb) {
            return i;
        }
    }
    return 0;
}
