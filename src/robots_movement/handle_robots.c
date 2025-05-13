/*
** EPITECH PROJECT, 2025
** amazed [WSL: Ubuntu-24.04]
** File description:
** main
*/

#include "../../include/amazed.h"
#include "../../include/lib/string.h"

void initialize_robot(robot_t *robot, int i, path_t *path)
{
    robot->number = i + 1;
    robot->current = path;
    robot->next_move = path->next;
    robot->finished = false;
    robot->moved_this_turn = false;
    robot->steps_taken = 0;
}

robot_t *assign_paths_to_robots(amazed_t *data, path_list_t *paths)
{
    int num_robots = data->robots;
    robot_t *robots = malloc(sizeof(robot_t) * num_robots);
    path_list_t *actual_pth = paths;

    if (!robots)
        return NULL;
    for (int i = 0; i < num_robots; i++) {
        if (!actual_pth)
            actual_pth = paths;
        initialize_robot(&robots[i], i, actual_pth->path);
        actual_pth = actual_pth->next;
    }
    return robots;
}
