/*
** EPITECH PROJECT, 2024
** C Pool Day 08 - Task 01
** File description:
** This file contains my_strdup function
** Allocates memory and copies the string given
*/

#include "../include/core.h"
#include "../include/string.h"

char *my_strdup(char const *src)
{
    int str_length = my_strlen(src);
    char *new_string = malloc(str_length + 1);

    if (!new_string)
        return NULL;
    return my_strcpy(new_string, src);
}
