#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 14:56:28 by jocaball          #+#    #+#              #
#    Updated: 2023/08/31 11:05:40 by jocaball         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = philo

CC = gcc
CFLAGS = -Wall -Werror -Wextra

HDR = $(filter-out $(shell find -type f -name '*_bonus.h'), $(shell find -type f -name '*.h'))
SRC = $(filter-out $(shell find -type f -name '*_bonus.c'), $(shell find -type f -name '*.c'))
OBJ = $(SRC:%.c=%.o)

HDR_BONUS = $(shell find -type f -name '*.h')
SRC_BONUS = $(shell find -type f -name '*_bonus.c')
OBJ_BONUS = $(SRC_BONUS:.c=.o)

$(NAME) : $(OBJ) $(HDR)

all: $(NAME)

clean :
	@rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

test : all
	./philo 3 500 100 50 2

test_mem : all
	valgrind -s --leak-check=full --track-origins=yes --show-leak-kinds=all  ./philo 300 5000 100 50 3

phony : all clean fclean re $(NAME)
