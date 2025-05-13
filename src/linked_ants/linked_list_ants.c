/*
** EPITECH PROJECT, 2025
** amazed [WSL: Ubuntu-24.04]
** File description:
** main
*/

#include "../../include/amazed.h"
#include "../../include/lib/string.h"

static room_t *find_room(amazed_t *data, char *id)
{
    room_t *temp = data->rooms;

    while (temp != NULL) {
        if (my_strcmp(temp->id, id) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

static void create_room_two(char **room_info, amazed_t *data,
    room_t *new_room, room_t *temp)
{
    for (int j = 0; room_info[j] != NULL; j++)
        free(room_info[j]);
    free(room_info);
    if (data->rooms == NULL) {
        data->rooms = new_room;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_room;
}

static void fill_room(room_t *new_room, char **room_info,
    amazed_t *data)
{
    new_room->x = my_str_to_nbr(room_info[1]);
    new_room->y = my_str_to_nbr(room_info[2]);
    new_room->next = NULL;
    new_room->visited = false;
    new_room->back = NULL;
    new_room->links = NULL;
    new_room->robot = 0;
}

static void create_room(amazed_t *data, int i, bool start, bool end)
{
    room_t *new_room = malloc(sizeof(room_t));
    room_t *temp = data->rooms;
    char **room_info = str_to_word_arr(data->input[i], ' ');

    if (room_info == NULL || room_info[0] == NULL)
        return;
    new_room->id = my_strdup(room_info[0]);
    new_room->start = start;
    new_room->end = end;
    fill_room(new_room, room_info, data);
    if (start == true)
        data->start = new_room;
    if (end == true)
        data->end = new_room;
    create_room_two(room_info, data, new_room, temp);
}

static void add_link(room_t *from, room_t *to)
{
    link_t *new_link = malloc(sizeof(link_t));
    link_t *temp = from->links;

    while (temp != NULL) {
        if (temp->room == to)
            return;
        temp = temp->next;
    }
    new_link->room = to;
    new_link->next = from->links;
    from->links = new_link;
}

static void create_link(amazed_t *data, int i)
{
    room_t *room1;
    room_t *room2;
    char **link_info = str_to_word_arr(data->input[i], '-');

    if (link_info == NULL || link_info[0] == NULL || link_info[1] == NULL)
        return;
    room1 = find_room(data, link_info[0]);
    room2 = find_room(data, link_info[1]);
    if (room1 != NULL && room2 != NULL) {
        add_link(room1, room2);
        add_link(room2, room1);
    }
    for (int j = 0; link_info[j] != NULL; j++)
        free(link_info[j]);
    free(link_info);
}

void handle_start_end(amazed_t *data, int i, bool *is_start,
    bool *is_end)
{
    if (my_strcmp(data->input[i], "##start") == 0)
        *is_start = true;
    if (my_strcmp(data->input[i], "##end") == 0 && *is_start == false)
        *is_end = true;
}

void handle_linked(amazed_t *data)
{
    int i = 1;
    bool is_start = false;
    bool is_end = false;

    for (i = 1; data->input[i] != NULL; i++) {
        if (data->input[i][0] == '#') {
            handle_start_end(data, i, &is_start, &is_end);
            continue;
        }
        if (my_strchr(data->input[i], '-') != NULL) {
            create_link(data, i);
            continue;
        }
        create_room(data, i, is_start, is_end);
        is_start = false;
        is_end = false;
    }
}
