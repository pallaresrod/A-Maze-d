/*
** EPITECH PROJECT, 2024
** C Pool Day 03 - Task 04
** File description:
** This file contains my definition of compute power rec
** headerfile
*/

#ifndef MY_H_
    #define MY_H_
    #include <unistd.h>
    #include <stddef.h>
    #include <stdarg.h>
    #include <stdio.h>
    #include <stdlib.h>

int print_d(va_list *list, int *char_count);
int print_c(va_list *list, int *char_count);
int print_s(va_list *list, int *char_count);
int specifier_loop(char c, void *input, int *char_count);
void my_putchar(char c);
void my_putstr(char const *str);
void my_put_nbr(int c);
int mini_printf(const char *format, ...);

typedef struct flag_s {
    int (*function)(va_list *list, int *char_count);
    char specifier;
} flag_t;

#endif
