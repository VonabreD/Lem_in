#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ederbano <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/25 02:46:37 by ederbano          #+#    #+#              #
#    Updated: 2017/10/14 14:02:29 by ederbano         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in

CC = gcc

SRC = main.c ft_helpers.c ft_brain.c ft_queue_proc.c ft_finisher.c ft_way_make.c ft_names.c ft_print_res.c ft_poc_in_data.c get_next_line.c ft_identify.c ft_take_name.c

SRCO = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCO)
		make -C ./libft
		$(CC) $(FLAGS) $(SRCO) -Llibft -lft -o $(NAME)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

clean:
	make clean -C ./libft
	rm -f $(SRCO)

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all
