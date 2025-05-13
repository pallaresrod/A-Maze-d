/*
** EPITECH PROJECT, 2024
** C Pool Day 06 - Task 02
** File description:
** Definition of my_strncpy
** Copies a section of a string into another
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    while (i < n) {
        dest[i] = '\0';
        i++;
    }
    return dest;
}
