/*
** EPITECH PROJECT, 2024
** C Pool Day 03 - Task 02
** File description:
** This file contains my definition of the my_putstr
** displays one-by-one the characters of a string
*/

#include "../include/io.h"

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        my_putchar(str[i]);
        i++;
    }
}
