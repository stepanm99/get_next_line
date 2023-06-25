# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 18:40:25 by smelicha          #+#    #+#              #
#    Updated: 2023/06/25 21:47:15 by smelicha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = get_next_line.c get_next_line_utils.c

CC = gcc
FLAGS = -Wall -Wextra -Werror -g -D BUFFER_SIZE=10


maintest:
	@echo "~~~ Testing with main function ~~~"
	@$(CC) $(SRC) main.c $(FLAGS) -o prog
	@./prog

sanitize:
	@echo "~~~ Testing with main function ~~~"
	@$(CC) $(SRC) main.c $(FLAGS) -fsanitize=address -o prog
	@./prog

maindebug:
	@echo "~~~ Testing with main function ~~~"
	@gcc $(SRC) main.c $(FLAGS) -o prog
	@./prog | cat -e
	@valgrind --leak-check=full ./prog

.PHONY: all clean fclean re test bonus maintest maindebug