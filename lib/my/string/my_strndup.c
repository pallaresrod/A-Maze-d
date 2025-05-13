/*
** EPITECH PROJECT, 2024
** C Pool Day 08 - Task 01
** File description:
** This file contains my_strdup function
** Allocates memory and copies the string given
*/

#include "../include/core.h"
#include "../include/string.h"

char *my_strndup(char const *src, int n)
{
    int str_length = my_strlen(src);
    int alloc_size = (str_length < n) ? str_length : n;
    char *new_string = malloc(alloc_size + 1);

    if (!new_string)
        return NULL;
    new_string[alloc_size] = '\0';
    return my_strncpy(new_string, src, alloc_size);
}
