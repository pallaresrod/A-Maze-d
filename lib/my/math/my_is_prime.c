/*
** EPITECH PROJECT, 2024
** C Pool Day 03 - Task 06
** File description:
** This file contains my definition of is_prime
** returns 1 if prime 0 if not
*/
int my_is_prime(int nb)
{
    if (nb < 0) {
        nb *= -1;
    }
    if (nb == 0 || nb == 1) {
        return 0;
    }
    for (int i = 2; i <= nb / 2; i++) {
        if ((nb % i) == 0) {
            return 0;
        }
    }
    return 1;
}
