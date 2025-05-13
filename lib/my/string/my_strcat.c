/*
** EPITECH PROJECT, 2024
** C Pool Day 03 - Task 04
** File description:
** This file contains my definition of compute power rec
** n^p recursively
*/

#include "../include/string.h"

char *my_strcat(char *dest, char const *src)
{
    int dest_length = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[dest_length + i] = src[i];
        i++;
    }
    dest[dest_length + i] = '\0';
    return dest;
}
