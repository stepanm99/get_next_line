# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 18:40:25 by smelicha          #+#    #+#              #
#    Updated: 2023/06/27 21:38:31 by smelicha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = get_next_line.a
NAMEB = get_next_line_bonus.a

SRC = get_next_line.c get_next_line_utils.c

BONUS_SRC = get_next_line_bonus.c get_next_line_utils_bonus.c

CC = cc
FLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=1

OBJ = $(SRC:.c=.o)
OBJB = $(BONUS_SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@echo "Compiling $<"
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "Done"

$(NAME): $(OBJ)
	@echo "Linking $@"
	@ar rcs $(NAME) $(OBJ)
	@echo "Done"

bonus: $(OBJB)
	@echo "Linking bonus $@"
	@ar rcs $(NAMEB) $(OBJB)
	@echo "Done"

clean:
	@rm -f $(OBJ) $(OBJB)

fclean: clean
	@rm -f $(NAME) $(NAMEB)

re: fclean all

rebonus: fclean bonus

maintest: re
	@echo "~~~ Testing with main function ~~~"
	@$(CC) $(NAME) main.c $(FLAGS) -o prog
	@./prog

maintestbonus: rebonus
	@echo "~~~ Testing with main function ~~~"
	@$(CC) $(NAMEB) main.c $(FLAGS) -o prog
	@./prog

sanitize: re
	@echo "~~~ Testing with main function ~~~"
	@$(CC) $(NAME) main.c $(FLAGS) -fsanitize=address -o prog
	@./prog

sanitizebonus: rebonus
	@echo "~~~ Testing with main function ~~~"
	@$(CC) $(NAMEB) main.c $(FLAGS) -fsanitize=address -o prog
	@./prog

maindebug: re
	@echo "~~~ Testing with main function ~~~"
	@gcc $(NAME) main.c $(FLAGS) -g -o prog
	@./prog | cat -e
	@valgrind --leak-check=full ./prog

maindebugbonus: rebonus
	@echo "~~~ Testing with main function ~~~"
	@gcc $(NAMEB) main.c $(FLAGS) -g -o prog
	@./prog | cat -e
	@valgrind --leak-check=full ./prog

.PHONY: all clean fclean re rebonus bonus maintest maintestbonus maindebug \
	maindebugbonus