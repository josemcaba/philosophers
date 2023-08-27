#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 14:56:28 by jocaball          #+#    #+#              #
#    Updated: 2023/08/27 15:31:07 by jocaball         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = philo

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC = philo.c parser.c loader.c time.c philosopher.c states.c
HDR = philo.h
OBJ = $(SRC:%.c=%.o)

$(NAME) : $(OBJ) $(HDR)

all: $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

test : all
	./philo 3 500 100 50 2

phony : all clean fclean re $(NAME)
