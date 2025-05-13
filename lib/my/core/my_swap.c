/*
** EPITECH PROJECT, 2024
** C Pool Day 04 - Task 01
** File description:
** This file contains my definition of the my_swap function
** swaps the contents of two integers
*/

void my_swap(int *a, int *b)
{
    int temporary;

    temporary = *a;
    *a = *b;
    *b = temporary;
}
