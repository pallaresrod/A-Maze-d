/*
** EPITECH PROJECT, 2024
** C Pool Day 03 - Task 01
** File description:
** This file contains my definition of the my_print_alpha
** that prints the whole alphabet in lowercase
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A');
        }
        i++;
    }
    return str;
}
