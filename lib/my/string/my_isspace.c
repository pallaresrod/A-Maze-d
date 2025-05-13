/*
** EPITECH PROJECT, 2024
** libmy_string
** File description:
** my_isspace.c
*/

// https://devdocs.io/c/string/byte/isspace
int my_isspace(char c)
{
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}
