/*
** EPITECH PROJECT, 2024
** mini_printf()
** File description:
** Definition of mini_printf()
** "Writing, to me, is simply thinking through my fingers." ~ Isaac Asimov
*/

#include "my_printf.h"
#include "../include/core.h"
#include "../include/io.h"

const flag_t FLAGS[4] = {
    {'d', &int_flag},
    {'i', &int_flag},
    {'s', &str_flag},
    {'c', &char_flag},
};

void char_flag(void *arg)
{
    char *value = (char *)arg;

    write(1, &value, 1);
}

void str_flag(void *arg)
{
    char *value = (char *)arg;

    while (*value != '\0') {
        write(1, value, 1);
        value++;
    }
}

void int_flag(void *arg)
{
    intptr_t value = (intptr_t)arg;

    my_put_nbr(value);
}

void select_flag(char c, void *arg)
{
    for (int i = 0; i < 4; i++) {
        if (c == '%') {
            break;
        }
        if (c == FLAGS[i].flag) {
            FLAGS[i].function(arg);
            break;
        }
    }
}

int my_printf(const char *format, ...)
{
    int i = 0;
    va_list args;

    va_start(args, format);
    while (format[i] != '\0') {
        if (format[i] == '%' && format[i + 1] == '%') {
            my_putchar('%');
            i += 2;
            continue;
        }
        if (format[i] == '%') {
            i++;
            select_flag(format[i], va_arg(args, void *));
        } else {
            my_putchar(format[i]);
        }
        i++;
    }
    va_end(args);
    return 0;
}
