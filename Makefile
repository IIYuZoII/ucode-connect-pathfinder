NAME = pathfinder
CC = clang
FLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

SRC = $(wildcard src/*.c)
OBJ = $(addprefix obj/,$(notdir $(SRC:.c=.o)))

all: $(SRC) $(NAME)

$(NAME): create_objdir $(OBJ)
	@make -sC libmx
	@$(CC) $(FLAGS) $(OBJ) -Llibmx -lmx -o $(NAME)

obj/%.o: src/%.c
	@$(CC) $(FLAGS) -c $< -o $@
	
clean:
	@rm -rf obj

create_objdir:
	@mkdir -p obj

uninstall: clean
	@rm -rf $(NAME)
	@make -sC libmx uninstall

reinstall: uninstall all

