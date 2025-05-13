/*
** EPITECH PROJECT, 2024
** C Pool Day 04 - Task 01
** File description:
** This file contains my definition of the my_swap function
** swaps the contents of two integers
*/
#include "../include/core.h"

int check_nums(const char *str)
{
    if (str == NULL || *str == '\0') {
        return 84;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 84;
        }
    }
    return 0;
}
