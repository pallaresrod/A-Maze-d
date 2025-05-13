/*
** EPITECH PROJECT, 2025
** amazed [WSL: Ubuntu-24.04]
** File description:
** main
*/

#include "../../include/amazed.h"
#include "../../include/lib/io.h"

bool is_with_robot(robot_t *robots, int num_robots,
    room_t *room, int robot_num)
{
    if (room->start || room->end)
        return false;
    for (int i = 0; i < num_robots; i++) {
        if (i == robot_num)
            continue;
        if (!robots[i].finished && robots[i].current &&
            robots[i].current->room == room)
            return true;
    }
    return false;
}

bool move_robot(robot_t *robot, robot_t *robots,
    int n_robots, int robot_idx)
{
    if (robot->finished || !robot->next_move)
        return false;
    if (is_with_robot(robots, n_robots, robot->next_move->room, robot_idx))
        return false;
    robot->current = robot->next_move;
    robot->next_move = robot->current->next;
    robot->moved_this_turn = true;
    robot->steps_taken++;
    if (!robot->next_move)
        robot->finished = true;
    return true;
}
