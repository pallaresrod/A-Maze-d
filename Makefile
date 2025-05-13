##
## EPITECH PROJECT, 2024
## B-CPE-110: Secured
## File description:
## Makefile
##

SRC = src/main.c \
	  src/linked_ants/linked_list_ants.c \
	  src/amazed.c \
	  src/algorithm/algorithm.c \
	  src/algorithm/path_manager.c \
	  src/algorithm/sorting.c \
	  src/algorithm/edit_paths.c \
	  src/robots_movement/robots.c \
	  src/robots_movement/printf.c \
	  src/robots_movement/end_start.c \
	  src/robots_movement/movement.c \
	  src/robots_movement/handle_robots.c \

OBJ = $(SRC:.c=.o)
NAME = amazed
LIBS = -lmy -L ./lib
WFLAGS = -Wall -Werror -Wextra
CFLAGS = -g

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/my
	make clean -C lib/my
	gcc $(OBJ) $(LIBS) -o $(NAME) $(WFLAGS) -g3
	find . -type f -name "*.o" -delete
	echo -e "\033[3;34m\nMakefile of $(NAME) compiled successfully.\033[0m"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
