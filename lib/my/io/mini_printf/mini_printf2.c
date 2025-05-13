/*
** EPITECH PROJECT, 2024
** C Pool Day 03 - Task 04
** File description:
** mini printf
*/
#include "my_miniprintf.h"
#include "../../include/core.h"
#include "../../include/io.h"


const flag_t specifiers[] =
{
    [0] = {.function = print_d, .specifier = 'd'},
    [1] = {.function = print_c, .specifier = 'c'},
    [2] = {.function = print_s, .specifier = 's'},
    [3] = {.function = print_d, .specifier = 'i'},
};

int print_not_flag(const char *format, int i, int *char_count)
{
    if (format[i] == '%') {
        my_putchar('%');
        *char_count = *char_count + 1;
        return 1;
    } else {
        my_putchar(format[i]);
        *char_count = *char_count + 1;
        return 0;
    }
}

int specifier_loop(char c, void *input, int *char_count)
{
    for (int i = 0; i < 5; i++) {
        if (c == specifiers[i].specifier) {
            specifiers[i].function(input, char_count);
        }
    }
}

int compare_specifiers(va_list *input, const char *format, int i, int *char_c)
{
    int old_i = i;
    int x = old_i;
    int i_count;

    for (x = old_i; format[x] != '\0'; x++) {
        specifier_loop(format[x], input, char_c);
    return (x - old_i);
    }
}

int mini_printf(const char *format, ...)
{
    va_list list;
    int count = 0;
    int *char_count = &count;
    int index;

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && format[i + 1] != '%') {
            i++;
            index = compare_specifiers(&list, format, i, char_count);
            i = i + index;
            continue;
        }
        if ((format[i] == '%' && format[i + 1] == '%') || (format[i] != '%')) {
            index = print_not_flag(format, i, char_count);
            i = i + index;
        }
    }
    va_end(list);
    return *char_count;
}
