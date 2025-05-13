/*
** EPITECH PROJECT, 2024
** C Pool Day 03 - Task 07
** File description:
** Finds the closest superior prime from the given num
** or returns self if self is prime
*/

int cute_is_prime(int nb)
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

int my_find_prime_sup(int nb)
{
    while (cute_is_prime(nb) != 1) {
        nb++;
    }
    return nb;
}
