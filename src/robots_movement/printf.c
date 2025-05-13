/*
** EPITECH PROJECT, 2025
** amazed [WSL: Ubuntu-24.04]
** File description:
** main
*/

#include "../../include/amazed.h"
#include "../../include/lib/io.h"
#include "../../include/lib/string.h"

static void print_rooms(room_t *rooms)
{
    my_printf("#rooms\n");
    for (room_t *room = rooms; room; room = room->next) {
        if (room->start)
            my_printf("##start\n");
        if (room->end)
            my_printf("##end\n");
        my_printf("%s %d %d\n", room->id, room->x, room->y);
    }
}

void print_tunnel(room_t *room, link_t *link)
{
    if (my_strcmp(room->id, link->room->id) < 0)
        my_printf("%s-%s\n", room->id, link->room->id);
}

void print_tunnels(room_t *rooms)
{
    my_printf("#tunnels\n");
    for (room_t *room = rooms; room; room = room->next) {
        for (link_t *link = room->links; link; link = link->next) {
            print_tunnel(room, link);
        }
    }
}

void print_amazed(amazed_t *data, int num_robots)
{
    my_printf("#number_of_robots\n%d\n", num_robots);
    print_rooms(data->rooms);
    print_tunnels(data->rooms);
    my_printf("#moves\n");
}

void print_robot_move(robot_t *robot, bool first_move)
{
    if (!first_move)
        my_printf(" ");
    my_printf("P%d-%s", robot->number, robot->current->room->id);
}
