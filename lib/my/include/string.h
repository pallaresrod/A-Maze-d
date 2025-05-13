/*
** EPITECH PROJECT, 2024
** libmy_string
** File description:
** string.h
** Header file for the string functions of my library
*/

#ifndef MY_STRING_H
    #define MY_STRING_H
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdint.h>
    #include <fcntl.h>

char *my_revstr(char *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, const char *src);
int my_strcmp(const char *s1, const char *s2);
char *my_strcpy(char *dest, const char *src);
char *my_strdup(const char *src);
int my_str_isalpha(const char *str);
int my_str_islower(const char *str);
int my_str_isnum(const char *str);
int my_str_isprintable(const char *str);
int my_str_isupper(const char *str);
int my_strlen(const char *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, const char *src, int n);
int my_strncmp(const char *s1, const char *s2, int n);
char *my_strncpy(char *dest, const char *src, int n);
char *my_strstr(char *str, const char *to_find);
char **str_to_word_arr(char *str, char end);
char *my_strupcase(char *str);
char *my_nbr_to_str(int nb);
float my_str_to_float(char *str);
int my_getnbr(const char *str);
char *my_strchr(const char *str, int c);
int my_isspace(char c);
int my_str_to_nbr(char const *str);
char *my_strndup(char const *src, int n);

#endif
