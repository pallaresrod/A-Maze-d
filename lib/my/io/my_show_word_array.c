/*
** EPITECH PROJECT, 2024
** C Pool Day 03 - Task 01
** File description:
** This file contains my definition of the my_print_alpha
** that prints the whole alphabet in lowercase
*/

#include "../include/io.h"

void my_show_word_array(char const **array)
{
    int i = 0;

    while (array[i] != 0) {
        my_putstr(array[i]);
        my_putchar('\n');
        i++;
    }
}
