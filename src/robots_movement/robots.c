/*
** EPITECH PROJECT, 2025
** amazed [WSL: Ubuntu-24.04]
** File description:
** main
*/

#include "../../include/amazed.h"
#include "../../include/lib/string.h"
#include "../../include/lib/io.h"

static int calculate_path_length(path_t *path)
{
    int length = 0;
    path_t *current = path;

    while (current) {
        length++;
        current = current->next;
    }
    return length;
}

void turn_moved_to_false(robot_t *robots, int num_robots)
{
    for (int i = 0; i < num_robots; i++) {
        robots[i].moved_this_turn = false;
    }
}

static bool process_robot_movement(robot_t *rbt,
    movement_context_t *contxt, int idx)
{
    bool moved = false;

    if (!rbt->finished && !rbt->moved_this_turn) {
        if (move_robot(rbt, contxt->all_robots, contxt->num_robots, idx)) {
            moved = true;
            print_robot_move(rbt, *(contxt->first_move));
            *(contxt->first_move) = false;
        }
    }
    return moved;
}

bool do_firts_the_last(robot_t *robots, int num_robots)
{
    bool movement = false;
    bool first_move = true;
    movement_context_t context = {robots, num_robots, &first_move};

    turn_moved_to_false(robots, num_robots);
    sort_robots_by_distance_to_end(robots, num_robots);
    for (int i = 0; i < num_robots; i++) {
        if (process_robot_movement(&robots[i], &context, i)) {
            movement = true;
        }
    }
    if (movement)
        my_printf("\n");
    return movement;
}

void handle_robot_movement(amazed_t *data, path_list_t *paths)
{
    int num_robots;
    robot_t *robots = assign_paths_to_robots(data, paths);

    if (!robots)
        return;
    num_robots = data->robots;
    print_amazed(data, num_robots);
    run_loop(robots, num_robots);
    free(robots);
}
