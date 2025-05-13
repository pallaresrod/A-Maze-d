/*
** EPITECH PROJECT, 2024
** C Pool Day 03 - Task 01
** File description:
** This file contains my definition of the my_print_alpha
** that prints the whole alphabet in lowercase
*/

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
        i++;
    }
    return 1;
}
