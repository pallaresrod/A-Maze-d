/*
** EPITECH PROJECT, 2024
** C Pool Day 03 - Task 04
** File description:
** This file contains my definition of compute power rec
** n^p recursively
*/
int my_compute_power_rec(int nb, int p)
{
    int result = 1;

    if (p < 0) {
        return 0;
    }
    if (p > 0) {
        result = nb * my_compute_power_rec(nb, p - 1);
    }
    return result;
}
