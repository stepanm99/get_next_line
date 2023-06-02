# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 18:40:25 by smelicha          #+#    #+#              #
#    Updated: 2023/06/03 00:04:34 by smelicha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= getnextline.a

SRC = $(shell find . -name "get_next_line.c" -o -name "test1.c" -o -name "leakcheck.c")

CC = cc
FLAGS = -Wall -Wextra -Werror

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Linking $@"
	@ar rcs $(NAME) $(OBJ)
	@echo "Done!"

%.o: %.c
	@echo "Compiling $<"
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

test: all
	@./$(NAME)

bonus: all

maintest: FLAGS += -D BUFFER_SIZE=500
maintest: all
	@echo "~~~ Testing with main function ~~~"
	@$(CC) $(SRC) prog.c $(FLAGS) -o prog
	@./a.out

maindebug: FLAGS += -g -D BUFFER_SIZE=500
maindebug: all
	@echo "~~~ Testing with main function ~~~"
	@$(CC) $(NAME) prog.c $(FLAGS) -o prog
	@./prog

.PHONY: all clean fclean re test bonus maintest maindebug