/*
** EPITECH PROJECT, 2024
** C Pool Day 03 - Task 01
** File description:
** This file contains my definition of the my_print_alpha
** that prints the whole alphabet in lowercase
*/
int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (n <= 0)
        return 0;
    while (n > 0) {
        if (s1[i] > s2[i])
            return (s1[i] - s2[i]);
        if (s1[i] < s2[i])
            return (s2[i] - s1[i]) * -1;
        if (s1[i] == '\0' && s2[i] == '\0')
            return 0;
        i++;
        n--;
    }
    return 0;
}
