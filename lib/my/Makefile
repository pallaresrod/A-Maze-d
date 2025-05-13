##
## EPITECH PROJECT, 2024
## My Library
## File description:
## Makefile
## libmy makefile
##

SRC =     string/my_str_to_nbr.c\
          core/my_showmem.c\
          core/my_sort_int_array.c\
          core/my_swap.c\
          core/check_nums.c\
          io/my_putchar.c\
          io/my_put_nbr.c\
          io/my_putstr.c\
          io/my_showstr.c\
          io/my_show_word_array.c\
          io/my_printf.c\
          math/my_compute_power_rec.c\
          math/my_compute_square_root.c\
          math/my_find_prime_sup.c\
          math/my_isneg.c\
          math/my_is_prime.c\
          string/my_revstr.c\
          string/my_strcapitalize.c\
          string/my_strcat.c\
          string/my_strcmp.c\
          string/my_strcpy.c\
          string/my_strdup.c\
          string/my_str_isalpha.c\
          string/my_str_islower.c\
          string/my_str_isnum.c\
          string/my_str_isprintable.c\
          string/my_str_isupper.c\
          string/my_strlen.c\
          string/my_strlowcase.c\
          string/my_strncat.c\
          string/my_str_to_float.c\
          string/my_str_to_nbr.c\
          string/my_nbr_to_str.c\
          string/my_strncmp.c\
          string/my_strncpy.c\
          string/my_strstr.c\
          string/my_str_to_word_array.c\
          string/my_strupcase.c\
          string/my_strchr.c \
          string/my_isspace.c \
          string/my_strndup.c \
          io/mini_printf/mini_printf2.c\
          io/mini_printf/print_functions.c \
          core/my_trim.c

OBJ = $(SRC:.c=.o)
NAME = libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	mkdir -p ../../include/lib/
	cp include/* ../../include/lib

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
