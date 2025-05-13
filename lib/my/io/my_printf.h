/*
** EPITECH PROJECT, 2024
** my_printf() header file
** File description:
** Header file for the my_printf project
** Writing, to me, is simply thinking through my fingers. ~ Isaac Asimov
*/

#ifndef PRINTF_H
    #define PRINTF_H
    #include <stdarg.h>
    #include <stdint.h>

typedef struct flag {
    char flag;
    void (*function) (void *);
} flag_t;

void int_flag(void *arg);
void char_flag(void *arg);
void str_flag(void *arg);
#endif
