/*
** EPITECH PROJECT, 2024
** libmy_core
** File description:
** core.h
** Header file for the core functions of my library
*/

#ifndef MY_CORE_H
    #define MY_CORE_H
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdint.h>
    #include <fcntl.h>

int my_showmem(const char *str, int size);
void my_sort_int_array(int *array, int size);
void my_swap(int *a, int *b);
char *my_revstr(char *str);
int check_nums(const char *str);
char *my_trim(const char *str);

#endif
