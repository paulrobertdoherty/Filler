# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/30 16:29:23 by pdoherty          #+#    #+#              #
#    Updated: 2018/12/12 11:05:42 by pdoherty         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pdoherty.filler

FLAGS = -Wall -Werror -Wextra

SRC = *.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):
	@make -C libft
	@gcc $(FLAGS) -c $(SRC)
	@gcc -o $(NAME) $(OBJ) libft/libft.a

clean:
	@rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all
