/*
** EPITECH PROJECT, 2024
** C Pool Day 06 - Task 01
** File description:
** Definition of my_strcpy
** Copies a string into another
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
