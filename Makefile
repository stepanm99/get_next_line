# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 18:40:25 by smelicha          #+#    #+#              #
#    Updated: 2023/06/12 20:40:39 by smelicha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = get_next_line.c prog.c

CC = gcc
FLAGS = -Wall -Wextra -Werror -g -D BUFFER_SIZE=10


maintest:
	@echo "~~~ Testing with main function ~~~"
	@$(CC) $(SRC) prog.c $(FLAGS) -o prog
	@./prog

maindebug:
	@echo "~~~ Testing with main function ~~~"
	@gcc $(SRC) $(FLAGS) -o prog
	@./prog | cat -e
#	@valgrind ./prog

.PHONY: all clean fclean re test bonus maintest maindebug