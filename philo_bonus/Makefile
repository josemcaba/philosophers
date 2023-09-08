# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 14:56:28 by jocaball          #+#    #+#              #
#    Updated: 2023/09/05 22:44:59 by jocaball         ###   ########.fr        #
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
	./philo 6 220 100 100 3

test1 : fclean
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -g -fsanitize=address
	./philo 6 220 100 100 3

test2 : fclean
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -g -fsanitize=thread
	./philo 6 220 100 100 3

test_val1 : fclean
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -g
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./philo ./philo 6 220 100 100 3

test_val2 : fclean
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -g
	valgrind --tool=helgrind ./philo 6 220 100 100 3

phony : all clean fclean re $(NAME)
