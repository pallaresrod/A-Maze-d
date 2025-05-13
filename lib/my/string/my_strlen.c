/*
** EPITECH PROJECT, 2024
** C Pool Day 03 - Task 03
** File description:
** This file contains my definition of the my_strlen
** returns the length of the string
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}
