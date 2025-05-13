/*
** EPITECH PROJECT, 2025
** amazed [WSL: Ubuntu-24.04]
** File description:
** main
*/

#include "../../include/amazed.h"
#include "../../include/lib/string.h"
#include "../../include/lib/io.h"

static void sort(robot_t *robots, int limit)
{
    robot_t temp;

    for (int j = 0; j < limit; j++) {
        if (robots[j].finished || (!robots[j + 1].finished &&
            robots[j + 1].steps_taken > robots[j].steps_taken)) {
            temp = robots[j];
            robots[j] = robots[j + 1];
            robots[j + 1] = temp;
        }
    }
}

void sort_robots_by_distance_to_end(robot_t *robots, int num_robots)
{
    for (int i = 0; i < num_robots - 1; i++) {
        sort(robots, num_robots - i - 1);
    }
}

void run_loop(robot_t *robots, int num_robots)
{
    while (true) {
        if (!do_firts_the_last(robots, num_robots))
            break;
    }
}
