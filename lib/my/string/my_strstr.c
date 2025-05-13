/*
** EPITECH PROJECT, 2024
** C Pool Day 03 - Task 01
** File description:
** This file contains my definition of the my_print_alpha
** that prints the whole alphabet in lowercase
*/
#include "../include/core.h"

int compare_substring(char *str, const char *to_find)
{
    int j;

    for (j = 0; to_find[j] != '\0'; j++) {
        if (str[j] != to_find[j]) {
            return -1;
        }
    }
    return 0;
}

char *my_strstr(char *str, const char *to_find)
{
    int i;

    if (!*to_find) {
        return str;
    }
    for (i = 0; str[i] != '\0'; i++) {
        if (compare_substring(&str[i], to_find) == 0) {
            return &str[i];
        }
    }
    return NULL;
}
