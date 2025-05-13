/*
** EPITECH PROJECT, 2024
** C Pool Day 04 - Task 06
** File description:
** This file contains my definition of the my_sort_int_array
** sorts the array using bubble sort
*/
void custom_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

int compare_and_swap(int *array, int j)
{
    if (array[j] > array[j + 1]) {
        custom_swap(&array[j], &array[j + 1]);
        return 1;
    }
    return 0;
}

int perform_pass(int *array, int size, int pass_num)
{
    int values_changed = 0;

    for (int j = 0; j < size - pass_num - 1; j++) {
        values_changed += compare_and_swap(array, j);
    }
    return values_changed;
}

void my_sort_int_array(int *array, int size)
{
    for (int i = 0; i < size - 1; i++) {
        if (perform_pass(array, size, i) == 0) {
            break;
        }
    }
}
