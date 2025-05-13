/*
** EPITECH PROJECT, 2025
** amazed [WSL: Ubuntu-24.04]
** File description:
** main
*/

#include "../include/amazed.h"
#include "../include/lib/string.h"

static char *concat_line(char *input, char *line, int read)
{
    char *temp = malloc(strlen(input) + read + 1);

    if (!temp) {
        free(input);
        return NULL;
    }
    my_strcpy(temp, input);
    my_strcat(temp, line);
    free(input);
    return temp;
}

static char *read_input(void)
{
    char *input = NULL;
    char *line = NULL;
    size_t len = 0;
    int read;

    input = my_strdup("");
    if (!input)
        return NULL;
    read = getline(&line, &len, stdin);
    while (read != -1 && read > 0) {
        input = concat_line(input, line, read);
        if (!input) {
            free(line);
            return NULL;
        }
        read = getline(&line, &len, stdin);
    }
    free(line);
    return input;
}

static int error_handling(char *file)
{
    if (file[0] == '\0') {
        return 84;
    }
    for (int i = 0; file[i] != '\0'; i++) {
        if (file[i] < 32 && file[i] != 10 || file[i] > 126) {
            printf("%i--%c", i, file[i]);
            return 84;
        }
    }
    return 0;
}

static void init_data(amazed_t *data)
{
    data->start = NULL;
    data->end = NULL;
    data->rooms = NULL;
    data->current = NULL;
}

static void free_file(char **file)
{
    for (int i = 0; file[i] != NULL; i++)
        free(file[i]);
    free(file);
}

static int create_linked(amazed_t *data, char *input)
{
    char **file = NULL;

    init_data(data);
    file = str_to_word_arr(input, '\n');
    if (!file) {
        free(input);
        free(data);
        return 84;
    }
    data->input = file;
    if (!file[0]) {
        free(input);
        free(data);
        return 84;
    }
    data->robots = my_str_to_nbr(file[0]);
    free(input);
    handle_linked(data);
    free_file(file);
    return 0;
}

int amazed(amazed_t **data, char *input)
{
    input = read_input();
    if (!input)
        return 84;
    if (error_handling(input) == 84) {
        free(input);
        return 84;
    }
    *data = malloc(sizeof(amazed_t));
    if (!*data) {
        free(input);
        return 84;
    }
    if (create_linked(*data, input) == 84) {
        free(*data);
        *data = NULL;
        return 84;
    }
    return 0;
}

void free_data(amazed_t *data)
{
    room_t *room = data->rooms;
    room_t *temp_room;
    link_t *link;
    link_t *temp_link;

    while (room != NULL) {
        link = room->links;
        while (link != NULL) {
            temp_link = link;
            link = link->next;
            free(temp_link);
        }
        temp_room = room;
        room = room->next;
        free(temp_room->id);
        free(temp_room);
    }
    free(data);
}
