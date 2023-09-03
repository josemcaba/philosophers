# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 14:56:28 by jocaball          #+#    #+#              #
#    Updated: 2023/09/03 02:14:40 by jocaball         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g # -fsanitize=thread

HDR = philo.h
SRC = philo.c data_init.c philos_init.c states.c controller.c time.c
OBJ = $(SRC:%.c=%.o)

$(NAME) : $(SRC) $(HDR)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

test : all
	./philo 4 224 92 57 3

test_mem : all
#	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./philo 3 224 92 57 3
	valgrind --tool=helgrind ./philo 3 224 92 57 3

phony : all clean fclean re $(NAME)
