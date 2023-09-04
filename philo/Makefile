# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 14:56:28 by jocaball          #+#    #+#              #
#    Updated: 2023/09/03 21:57:52 by jocaball         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAGS = -Wall -Werror -Wextra

HDR = philo.h
SRC = philo.c data_init.c philos_init.c philos_create.c states.c controller.c \
	  time.c error.c destroyers.c
OBJ = $(SRC:%.c=%.o)

$(NAME) : $(SRC) $(HDR)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

run : fclean
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	./philo 5 300 70 60 4

test1 : fclean
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -g -fsanitize=address
	./philo 5 300 70 60 4

test2 : fclean
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -g -fsanitize=thread
	./philo 5 300 70 60 4

test_val1 : fclean
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -g
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./philo 5 300 70 60 4

test_val2 : fclean
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -g
	valgrind --tool=helgrind ./philo 5 300 70 60 4

phony : all clean fclean re $(NAME)
