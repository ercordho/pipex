# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/23 12:03:01 by ercordho          #+#    #+#              #
#    Updated: 2021/09/23 16:22:12 by ercordho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
INC		=	inc
SRCS	=	srcs/ascii/ft_isalnum.c \
			srcs/ascii/ft_isalpha.c \
			srcs/ascii/ft_ischarset.c \
			srcs/ascii/ft_isdigit.c \
			\
			srcs/memory/ft_memcpy.c \
			srcs/memory/ft_memdel.c \
			srcs/memory/ft_memdels.c \
			srcs/memory/ft_memset.c \
			srcs/memory/ft_memsetmalloc.c \
			srcs/memory/ft_realloc.c \
			srcs/memory/ft_swap.c \
			\
			srcs/read/get_next_line.c \
			\
			srcs/string/ft_countwords.c \
			srcs/string/ft_split.c \
			srcs/string/ft_strcat.c \
			srcs/string/ft_strcmp.c \
			srcs/string/ft_strdup.c \
			srcs/string/ft_strjoin.c \
			srcs/string/ft_strlen.c \
			srcs/string/ft_strncmp.c \
			srcs/string/ft_strrev.c \
			srcs/string/ft_strslen.c \
			srcs/string/ft_strsub.c \
			\
			srcs/write/ft_putchar.c \
			srcs/write/ft_putendl.c \
			srcs/write/ft_putendls.c \
			srcs/write/ft_putnbr.c \
			srcs/write/ft_putstr.c \
			srcs/write/ft_putstrs.c
OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar src $@ $^

.c.o:		$(SRCS)
			@$(CC) $(CFLAGS) -I $(INC) -c $< -o $(<:.c=.o)

clean:
			@rm -f $(OBJS)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
