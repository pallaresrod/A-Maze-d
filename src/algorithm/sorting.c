/*
** EPITECH PROJECT, 2025
** amazed [WSL: Ubuntu-24.04]
** File description:
** sorting
*/

#include "../../include/amazed.h"
#include "../../include/lib/string.h"

/**
 * @brief calculates the length of a path
 *
 * @param path the path we want to calculate the length of
 * @return int the length of a path
 */
int path_length(path_t *path)
{
    int len = 0;

    while (path) {
        len++;
        path = path->next;
    }
    return len;
}

/**
 * @brief goes through the list and checks if the current path is
 * longer than the next, if it is then they get swapped, and moves on
 *
 * @param paths list of all the paths
 * @param end the end path
 * @return true if there was a swap of paths
 * @return false if there wasn't a swap, meaning all the paths are in order
 */
bool bubble_pass(path_list_t *paths, path_list_t *end)
{
    bool swapped = false;
    path_list_t *list = paths;
    path_t *tmp;
    int len1;
    int len2;

    while (list->next != end) {
        len1 = path_length(list->path);
        len2 = path_length(list->next->path);
        if (len1 > len2) {
            tmp = list->path;
            list->path = list->next->path;
            list->next->path = tmp;
            swapped = true;
        }
        list = list->next;
    }
    return swapped;
}

/**
 * @brief sorts the paths from shortest to longest
 *
 * @param paths the list of paths we want to sort
 */
void sorting_paths(path_list_t *paths)
{
    path_list_t *end = NULL;
    path_list_t *list = NULL;

    if (!paths)
        return;
    while (bubble_pass(paths, end)) {
        list = paths;
        while (list->next != end)
            list = list->next;
        end = list;
    }
}
