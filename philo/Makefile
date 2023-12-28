# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 14:56:28 by jocaball          #+#    #+#              #
#    Updated: 2023/12/28 19:39:55 by jocaball         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pthread

HDR = philo.h
SRC = philo.c data_init.c philos_init.c philos_create.c states.c controller.c \
	  utils.c
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

.PHONY : all clean fclean re $(NAME)
