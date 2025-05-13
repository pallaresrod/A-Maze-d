/*
** EPITECH PROJECT, 2024
** C Pool Day 08 - Task 04
** File description:
** my_str_to_word_array
** split string into words
*/

#include "../include/core.h"
#include "../include/string.h"
#include <stdbool.h>

void process_char(char *str, int *result_index, bool *saw_whitespace, char c)
{
    if (my_isspace(c)) {
        if (!*saw_whitespace) {
            str[*result_index] = ' ';
            (*result_index)++;
            *saw_whitespace = true;
        }
    } else {
        str[*result_index] = c;
        (*result_index)++;
        *saw_whitespace = false;
    }
}

static void remove_repeated_spaces(char *str)
{
    bool saw_whitespace = false;
    int result_index = 0;

    if (str == NULL)
        return;
    for (int i = 0; str[i] != '\0'; i++) {
        process_char(str, &result_index, &saw_whitespace, str[i]);
    }
    str[result_index] = '\0';
}

int counter_rows(char *str, char delim)
{
    int rows = 1;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == delim)
            rows++;
        i++;
    }
    return rows;
}

int max_cols(int max, int col)
{
    if (col > max)
        max = col;
    return max;
}

static int count_cols(char *str, char delim)
{
    int max = 0;
    int columns = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == delim) {
            max = max_cols(max, columns);
            columns = 0;
            continue;
        }
        columns++;
    }
    if (columns > max)
        max = columns;
    return max;
}

static char **malloc_arr(int rws, int cols)
{
    char **arr = malloc(sizeof(char *) * (rws + 1));
    int i = 0;

    if (!arr)
        return NULL;
    while (i < rws) {
        arr[i] = malloc(sizeof(char) * (cols + 1));
        if (!arr[i])
            return NULL;
        i++;
    }
    arr[rws] = NULL;
    return arr;
}

static void filler(char *str, char **arr, char end)
{
    int row = 0;
    int col = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == end) {
            arr[row][col] = '\0';
            row++;
            col = 0;
        } else {
            arr[row][col] = str[i];
            col++;
        }
        i++;
    }
    arr[row][col] = '\0';
}

char **str_to_word_arr(char *str, char end)
{
    char **arr;
    int rows;
    int cols;

    if (!str)
        return NULL;
    rows = counter_rows(str, end);
    cols = count_cols(str, end);
    arr = malloc_arr(rows, cols);
    if (!arr)
        return NULL;
    filler(str, arr, end);
    return arr;
}
