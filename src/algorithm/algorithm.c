/*
** EPITECH PROJECT, 2025
** amazed [WSL: Ubuntu-24.04]
** File description:
** main
*/

#include "../../include/amazed.h"
#include "../../include/lib/string.h"
#include "../../include/lib/io.h"

/**
 * @brief recursively explores every path to the end, checks
 * the visited room and builds a path as it goes that it stores
 * in the list of paths
 *
 * @param current room we are currently in
 * @param path_so_far the built path so far
 * @param all_paths all the found paths
 */
void find_paths_recursive(room_t *current, path_t *path_so_far,
    path_list_t **all_paths)
{
    path_t *new_path_node;
    path_t *path_copy = NULL;

    if (current->visited)
        return;
    new_path_node = malloc(sizeof(path_t));
    current->visited = true;
    new_path_node->room = current;
    new_path_node->next = path_so_far;
    if (current->end) {
        path_copy = clone_path(new_path_node);
        add_path_to_list(all_paths, path_copy);
        free(new_path_node);
        current->visited = false;
        return;
    }
    for (link_t *link = current->links; link; link = link->next)
        find_paths_recursive(link->room, new_path_node, all_paths);
    free(new_path_node);
    current->visited = false;
}
