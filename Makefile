# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 16:06:21 by ercordho          #+#    #+#              #
#    Updated: 2021/09/23 12:59:27 by ercordho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex
CC		=	gcc
COMPILE	=	-L libft -lft
CFLAGS	=	-Wall -Wextra -Werror
SRC		=	main.c
OBJ		=	$(SRC:.c=.o)

OS := $(shell uname -s)
ifeq ($(OS),Darwin)
#	CFLAGS		+=	-D MACOS -fsanitize=address
endif
ifeq ($(OS),Linux)
endif

all:		libft $(NAME)
$(NAME):	$(OBJ)
			@$(CC) $^ $(COMPILE) -o $@
libft:
			@make -C libft
.c.o:		$(SRC)
			@$(CC) $(CFLAGS) -c $<
clean:
			@rm -f $(OBJ)
fclean:		clean
			@rm -f $(NAME)
			@make fclean -C libft
re:			fclean all
.PHONY:		all libft clean fclean re