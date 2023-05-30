# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 18:40:25 by smelicha          #+#    #+#              #
#    Updated: 2023/05/30 23:31:42 by smelicha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= getnextline.a

SRCDIR = ./src/

SRC = $(shell find . -name "get_next_line.c")

CC = cc
FLAGS = -Wall -Wextra -Werror -g

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Linking $@"
	@ar rcs $(NAME) $(OBJ)
	@echo "Done!"

%.o: %.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJB)

fclean: clean
	@rm -f $(NAME)

re: fclean all

test: all
	@./$(NAME)

bonus: all

maintest: all
	@echo "~~~ Testing with main function ~~~"
	@$(CC) $(SRC) main.c $(FLAGS)
	@./a.out

maindebug: all
	@echo "~~~ Testing with main function ~~~"
	@$(CC) $(NAME) main.c -g $(FLAGS) -o prog
	@./prog

.PHONY: all clean fclean re test bonus maintest maindebug