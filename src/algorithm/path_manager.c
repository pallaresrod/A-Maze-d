/*
** EPITECH PROJECT, 2025
** amazed [WSL: Ubuntu-24.04]
** File description:
** path_manager
*/

#include "../../include/amazed.h"
#include "../../include/lib/string.h"

/**
 * @brief frees a path
 *
 * @param path the path to free
 */
void free_path(path_t *path)
{
    path_t *tmp;

    while (path) {
        tmp = path;
        path = path->next;
        free(tmp);
    }
}

/**
 * @brief frees the list of uniques paths
 *
 * @param paths list containing only the unique paths
 */
void free_unique_path_list(path_list_t *paths)
{
    path_list_t *tmp;

    while (paths) {
        tmp = paths;
        paths = paths->next;
        free(tmp);
    }
}

/**
 * @brief frees the list of paths
 *
 * @param paths the list to free
 */
void free_path_list(path_list_t *paths)
{
    path_list_t *tmp;

    while (paths) {
        tmp = paths;
        paths = paths->next;
        free_path(tmp->path);
        free(tmp);
    }
}

/**
 * @brief clones a path
 *
 * @param original the path to clone
 * @return path_t* the cloned path
 */
path_t *clone_path(path_t *original)
{
    path_t *new_head;

    if (!original)
        return NULL;
    new_head = malloc(sizeof(path_t));
    new_head->room = original->room;
    new_head->next = clone_path(original->next);
    return new_head;
}

/**
 * @brief add a path to the list of paths
 *
 * @param paths the list that has all the paths
 * @param new_path the new path to add
 */
void add_path_to_list(path_list_t **paths, path_t *new_path)
{
    path_list_t *new_node = malloc(sizeof(path_list_t));

    new_node->path = new_path;
    new_node->next = *paths;
    *paths = new_node;
}
