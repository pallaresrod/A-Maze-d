/*
** EPITECH PROJECT, 2024
** C Pool Day 03 - Task 01
** File description:
** This file contains my definition of the my_print_alpha
** that prints the whole alphabet in lowercase
*/

int get_length(char *str)
{
    int length = 0;

    while (str[length]) {
        length++;
    }
    return length;
}

char *my_revstr(char *str)
{
    int j = 0;
    int chars_to_check;
    char temporary;
    int length = get_length(str);

    chars_to_check = length / 2;
    while (j < chars_to_check) {
        temporary = str[j];
        str[j] = str[length - j - 1];
        str[length - j - 1] = temporary;
        j++;
    }
    return str;
}
