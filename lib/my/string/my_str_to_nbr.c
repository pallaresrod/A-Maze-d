/*
** EPITECH PROJECT, 2024
** C Pool Day 03 - Task 05
** File description:
** This file contains my definition of my_str_to_nbr
** that converts a string to an integer
*/

int is_overflow(long final_num, int sign)
{
    if (sign == 1 && final_num > 2147483647) {
        return 1;
    }
    if (sign == -1 && final_num > 2147483648) {
        return 1;
    }
    return 0;
}

int my_str_to_nbr(char const *str)
{
    int i = 0;
    int neg = 1;
    long final_num = 0;
    int digit_count = 0;

    while (str[i] == '+' || str[i] == ' ' || str[i] == '-') {
        if (str[i] == '-') {
            neg = -neg;
        }
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        final_num = final_num * 10 + (str[i] - '0');
        digit_count++;
        i++;
        if (is_overflow(final_num, neg)) {
            return 0;
        }
    }
    return final_num ? (int)(final_num * neg) : 0;
}
