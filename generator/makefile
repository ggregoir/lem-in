# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/14 00:31:10 by cmehay            #+#    #+#              #
#    Updated: 2017/08/12 21:06:43 by iburel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	gen
CC		=	gcc
CFLAGS	=	-Ofast

all: $(NAME)

$(NAME): gen.c
	$(CC) -o $@ $^ $(CFLAGS)

clean:

fclean:
	rm -rf $(NAME)

re: fclean all