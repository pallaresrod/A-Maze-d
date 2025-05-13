/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** radar
*/

#include "../include/string.h"
#include "../include/core.h"

int chars_removed(char c)
{
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

const char *find_start(const char *str)
{
    const char *start;

    if (!str)
        return NULL;
    start = str;
    while (*start && chars_removed(*start)) {
        start++;
    }
    return start;
}

const char *find_end(const char *str, const char *start)
{
    size_t len;
    const char *end;

    if (!str || !start)
        return NULL;
    len = my_strlen(str);
    end = str + len - 1;
    while (end > start && chars_removed(*end)) {
        end--;
    }
    return end;
}

char *create_trimmed_string(const char *start, const char *end)
{
    size_t len;
    size_t i;
    char *result;

    if (!start || !end || end < start)
        return NULL;
    len = end - start + 1;
    result = malloc(len + 1);
    if (!result)
        return NULL;
    for (i = 0; i < len; i++) {
        result[i] = start[i];
    }
    result[len] = '\0';
    return result;
}

char *my_trim(const char *str)
{
    const char *start;
    char *result;
    const char *end;

    if (!str)
        return NULL;
    start = find_start(str);
    if (*start == '\0') {
        result = malloc(1);
        if (!result)
            return NULL;
        *result = '\0';
        return result;
    }
    end = find_end(str, start);
    return create_trimmed_string(start, end);
}
