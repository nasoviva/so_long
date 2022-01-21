# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hverda <hverda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 18:23:47 by hverda            #+#    #+#              #
#    Updated: 2021/10/05 15:14:53 by hverda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		so_long

LIST =		srcs/pars.c \
			srcs/keys.c \
			srcs/steps.c \
			srcs/values.c \
			srcs/action.c \
			srcs/free.c \
			srcs/utilites_keys.c \
			srcs/utilite_pars.c \
			srcs/utilites_1.c \
			srcs/so_long.c \
			srcs/utilites_2.c \

LIST_H = include/so_long.h

MINILIBX = libmlx.a

OBJ = $(patsubst %.c,%.o,$(LIST))

FLAGS = -Wall -Wextra -Werror -I minilibx -L minilibx -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJ) $(LIST_H)
	@make -C minilibx
	@cp minilibx/$(MINILIBX) .
	gcc $(FLAGS) $(LIST) -o $(NAME)

clean :
	@rm -f $(OBJ) $(OBJ_B)
	@make clean -C minilibx

fclean : clean
	@rm -f $(NAME)
	@rm -f $(MINILIBX)

re : fclean all

.PHONY : all clean fclean re