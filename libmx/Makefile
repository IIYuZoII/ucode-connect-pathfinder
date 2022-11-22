NAME = libmx.a
INC = $(wildcard inc/*.h)
SRC = $(wildcard src/*.c)
OBJ = $(addprefix obj/, $(notdir $(SRC:%.c=%.o)))
CC = clang
FLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic


all: clean $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^

$(OBJ): | obj

obj/%.o: src/%.c $(INC)
	@clang $(FLAGS) -c $< -o $@ -I inc

obj:
	@mkdir -p $@

clean:
	@rm -rf obj

uninstall:
	@rm -rf obj
	@rm -rf $(NAME)

reinstall: uninstall all
