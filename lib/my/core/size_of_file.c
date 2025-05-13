/*
** EPITECH PROJECT, 2024
** C Pool Day 04 - Task 06
** File description:
** This file contains my definition of the my_sort_int_array
** sorts the array using bubble sort
*/
#include "include/core.h"

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

ssize_t count_file_bytes(int fd, char *buffer, size_t buffer_size)
{
    ssize_t total = 0;
    ssize_t bytes_read;

    while (1) {
        bytes_read = read(fd, buffer, buffer_size);
        if (bytes_read <= 0)
            break;
        total += bytes_read;
    }
    return (bytes_read < 0) ? -1 : total;
}

void cleanup(int fd, char *buffer)
{
    if (buffer)
        free(buffer);
    if (fd != -1)
        close(fd);
}

ssize_t get_file_size(const char *file_path)
{
    int fd;
    char *buffer;
    ssize_t size;
    size_t buffer_size = 1024;

    fd = open(file_path, O_RDONLY);
    if (fd == -1)
        return -1;
    buffer = malloc(buffer_size);
    if (!buffer) {
        cleanup(fd, NULL);
        return -1;
    }
    size = count_file_bytes(fd, buffer, buffer_size);
    cleanup(fd, buffer);
    return size;
}
