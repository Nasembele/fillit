# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soyster <soyster@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/11 18:08:25 by soyster           #+#    #+#              #
#    Updated: 2019/06/14 16:42:37 by orhoda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC_DIR = sources

SRC = fillit_check.c fillit_coordinates.c fillit_main.c fillit_read.c \
	  fillit_solve.c fillit_validate.c

HEADER = includes

FLAG = -Wall -Wextra -Werror

OBJECTS = $(addprefix $(SRC_DIR)/,$(SRC:.c=.o))

all:	$(NAME)

$(NAME): $(OBJECTS)
	@make re -C ./libft
	@gcc -o $(NAME) $(FLAG) -L./libft -lft -I $(HEADER) $(OBJECTS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@gcc $(FLAG) -c $^ -I includes -o $@
	
.PHONY: clean fclean re

clean:
	@/bin/rm -f $(OBJECTS)
	@make clean -C ./libft
	
fclean:	clean
	@/bin/rm -f $(NAME)
	@make fclean -C ./libft
	
re: fclean all
