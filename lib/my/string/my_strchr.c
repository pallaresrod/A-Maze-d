/*
** EPITECH PROJECT, 2024
** libmy_string
** File description:
** my_strchr.c
*/

#include "../include/core.h"

char *my_strchr(const char *str, int c)
{
    while (*str != '\0') {
        if (*str == (char)c)
            return (char *)str;
        str++;
    }
    if (c == '\0')
        return (char *)str;
    return NULL;
}
