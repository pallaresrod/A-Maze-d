/*
** EPITECH PROJECT, 2024
** C Pool Day 03 - Task 01
** File description:
** This file contains my definition of the my_print_alpha
** that prints the whole alphabet in lowercase
*/
#include <stdio.h>

int is_not_alpha(char *str, int i, int new_word)
{
    if ((str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a')
        || str[i] > 'z') && str[i] != '\'') {
        new_word = 1;
    }
    if (str[i] >= '0' && str[i] <= '9') {
        new_word = 0;
    }
    return new_word;
}

char *my_strcapitalize(char *str)
{
    int i = 0;
    int new_word = 1;

    while (str[i] != '\0') {
        new_word = is_not_alpha(str, i, new_word);
        if (str[i] >= 'A' && str[i] <= 'Z' && new_word == 0) {
            str[i] = str[i] + ('a' - 'A');
        }
        if (str[i] >= 'A' && str[i] <= 'Z' && new_word == 1) {
            new_word = 0;
        }
        if (str[i] >= 'a' && str[i] <= 'z' && new_word == 1) {
            str[i] = str[i] - ('a' - 'A');
            new_word = 0;
        }
        i++;
    }
    return str;
}
