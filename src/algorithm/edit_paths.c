/*
** EPITECH PROJECT, 2025
** amazed [WSL: Ubuntu-24.04]
** File description:
** reverse_paths
*/

#include "../../include/amazed.h"
#include "../../include/lib/string.h"

/**
 * @brief helper function to paths_conflict()
 * checks if the room is the start or the end
 *
 * @param room the room to check
 * @return true if the room is the start or end
 * @return false if is any other room
 */
static bool is_room_conflicting(room_t *room)
{
    return !(room->start || room->end);
}

/**
 * @brief check if a room is in the same position
 * in both the paths
 *
 * @param a one path
 * @param b other path
 * @return true if there is the same room
 * @return false if there isn't the same room
 */
static bool paths_conflict(path_t *a, path_t *b)
{
    while (a && b) {
        if (!is_room_conflicting(a->room) || !is_room_conflicting(b->room)) {
            a = a->next;
            b = b->next;
            continue;
        }
        if (a->room == b->room)
            return true;
        a = a->next;
        b = b->next;
    }
    return false;
}

/**
 * @brief checks if the path is unique by going through
 * all the paths that have already been added to the unique
 * paths list and seeig if there is any conflict
 *
 * @param path the path that is being checked
 * @param accepted_paths all the unique paths
 * @return true if the path is unique
 * @return false if there is conflict
 */
static bool path_is_unique(path_t *path, path_list_t *accepted_paths)
{
    for (; accepted_paths; accepted_paths = accepted_paths->next) {
        if (paths_conflict(path, accepted_paths->path))
            return false;
    }
    return true;
}

/**
 * @brief goes through the list of paths checking if they
 * are unique, if they are then adds them to a new list
 *
 * @param all_paths the list of all the paths
 * @return path_list_t* list of the paths filtered so all
 * of them are unique
 */
path_list_t *filter_paths(path_list_t *all_paths)
{
    path_list_t *result = NULL;
    path_list_t *new_node = NULL;
    path_list_t **last_ptr = &result;

    for (path_list_t *current = all_paths; current; current = current->next) {
        if (path_is_unique(current->path, result)) {
            new_node = malloc(sizeof(path_list_t));
            new_node->path = current->path;
            new_node->next = NULL;
            *last_ptr = new_node;
            last_ptr = &new_node->next;
        }
    }
    return result;
}

/**
 * @brief handles reversing a path
 *
 * @param head the start of the path
 */
void reverse_path(path_t **head)
{
    path_t *prev = NULL;
    path_t *current = *head;
    path_t *next = NULL;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

/**
 * @brief reverses the order of all the paths in the list,
 *
 * @param paths the list of paths to reverse
 */
void reverse_paths(path_list_t *paths)
{
    while (paths) {
        reverse_path(&paths->path);
        paths = paths->next;
    }
}
