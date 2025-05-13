/*
** EPITECH PROJECT, 2024
** libmy_io
** File description:
** io.h
** Header file for the input/output functions of my library
*/

#ifndef MY_IO_H
    #define MY_IO_H

void my_putchar(char c);
void my_put_nbr(int nb);
void my_putstr(const char *str);
int my_showstr(const char *str);
void my_show_word_array(char const **array);
int my_printf(const char *format, ...);
int mini_printf(const char *format, ...);

#endif
