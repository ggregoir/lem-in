# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/29 19:13:14 by ggregoir          #+#    #+#              #
#    Updated: 2017/09/14 14:39:31 by ggregoir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= lem-in

SRC		= srcs/main.c srcs/parsing.c srcs/get_next_line.c srcs/error.c \
		  srcs/buffer.c srcs/utils.c srcs/algo.c srcs/algo2.c srcs/delete.c \
		  srcs/color.c srcs/color2.c srcs/print_result.c
		
OBJ		= $(patsubst srcs/%.c,obj/%.o,$(SRC))
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc -Wall -Wextra -Werror -L libft/ -lft -g $(SRC) -o $(NAME)
	@echo '\033[32m[ ✔ ] \n\033[0m' "Create lem_in"

obj/%.o: srcs/%.c
	mkdir -p obj
	gcc -Wall -Wextra -Werror -c $< -o $@
	@echo '\033[0m[ ✔ ] \n\033[0m' "$<"

clean:
	/bin/rm -rf obj/
	make -C libft/ clean
	@echo '\033[31m[ ✔ ] \n\033[0m' "Clean Lib"

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean
	@echo '\033[31m[ ✔ ] \n\033[0m' "Fclean Lib"

re: fclean all

test: all
	@echo '\033[32m\n\033[0m' "-------------------------------------"
	./lem-in test

all: $(NAME)
.PHONY: clean fclean re all test
