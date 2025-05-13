/*
** EPITECH PROJECT, 2025
** amazed [WSL: Ubuntu-24.04]
** File description:
** amazed
*/

#ifndef AMAZED_H
    #define AMAZED_H
    #include <stdbool.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>

typedef struct link_s {
    struct room_s *room;
    struct link_s *next;
} link_t;

typedef struct room_s {
    bool start;
    bool visited;
    bool end;
    char *id;
    int x;
    int y;
    int robot;
    struct link_s *links;
    struct room_s *back;
    struct room_s *next;
} room_t;

typedef struct path_s {
    room_t *room;
    struct path_s *next;
} path_t;

typedef struct path_list_s {
    path_t *path;
    struct path_list_s *next;
} path_list_t;

typedef struct robot_s {
    int number;
    path_t *current;
    path_t *next_move;
    bool finished;
    bool moved_this_turn;
    int steps_taken;
} robot_t;

typedef struct amazed_s {
    room_t *rooms;
    room_t *start;
    room_t *end;
    char **input;
    int robots;
    room_t *current;
} amazed_t;

typedef struct {
    robot_t *all_robots;
    int num_robots;
    bool *first_move;
} movement_context_t;

//linked
void handle_linked(amazed_t *data);

//amazed
int amazed(amazed_t **data, char *input);
void free_data(amazed_t *data);

//algorithm
void find_paths_recursive(room_t *current, path_t *path_so_far,
    path_list_t **all_paths);

//path_manager
path_t *clone_path(path_t *original);
void add_path_to_list(path_list_t **paths, path_t *new_path);
void free_path_list(path_list_t *paths);
void free_path(path_t *path);
void free_unique_path_list(path_list_t *paths);

//sorting
void sorting_paths(path_list_t *paths);

//edit_paths
void reverse_paths(path_list_t *paths);
path_list_t *filter_paths(path_list_t *all_paths);

//robots
void handle_robot_movement(amazed_t *data, path_list_t *paths);
robot_t *assign_paths_to_robots(amazed_t *data, path_list_t *paths);
void print_amazed(amazed_t *data, int num_robots);
bool move_robot(robot_t *robot, robot_t *robots,
    int n_robots, int robot_idx);
void print_robot_move(robot_t *robot, bool first_move);
void sort_robots_by_distance_to_end(robot_t *robots, int num_robots);
bool do_firts_the_last(robot_t *robots, int num_robots);
void turn_moved_to_false(robot_t *robots, int num_robots);
void run_loop(robot_t *robots, int num_robots);

#endif
