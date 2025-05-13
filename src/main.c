/*
** EPITECH PROJECT, 2025
** amazed [WSL: Ubuntu-24.04]
** File description:
** main
*/

#include "../include/amazed.h"
#include "../include/lib/string.h"
#include "../include/lib/io.h"

//testing function

// void print_all_paths(path_list_t *paths)
// {
//     for (; paths; paths = paths->next) {
//         path_t *step = paths->path;
//         while (step) {
//             printf("%s", step->room->id);
//             if (step->next)
//                 printf(" -> ");
//             step = step->next;
//         }
//         printf("\n");
//     }
// }
// print_all_paths(all_paths);
// printf("\nNEXT\n");
// print_all_paths(unique_paths);

/**
 * @brief main fucntion in the program
 *
 * @param argc number of arguments passed
 * @param argv arguments passed
 * @return int status, if ok return 0 if noot 84
 */
int main(int argc, char **argv)
{
    amazed_t *data = NULL;
    path_list_t *all_paths = NULL;
    path_list_t *unique_paths = NULL;
    char *input = NULL;

    if (argc != 1)
        return 84;
    if (amazed(&data, input) == 84)
        return 84;
    find_paths_recursive(data->start, NULL, &all_paths);
    reverse_paths(all_paths);
    sorting_paths(all_paths);
    unique_paths = filter_paths(all_paths);
    handle_robot_movement(data, unique_paths);
    free_path_list(all_paths);
    free_unique_path_list(unique_paths);
    free_data(data);
    return 0;
}
