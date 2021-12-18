# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 18:47:17 by ercordho          #+#    #+#              #
#    Updated: 2021/12/18 01:28:41 by ercordho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f
SRCS			=	srcs/ascii/ft_ischarset.c \
				\
					srcs/error/error_access.c \
					srcs/error/error_child_dup2.c \
					srcs/error/error_child_fork.c \
					srcs/error/error_close_file.c \
					srcs/error/error_cmd.c \
					srcs/error/error_init_cmd.c \
					srcs/error/error_init_paths.c \
					srcs/error/error_malloc_paths.c \
					srcs/error/error_open_file.c \
					srcs/error/error_pipe.c \
					srcs/error/error_waitpid.c \
				\
					srcs/init/init_pipex.c \
				\
					srcs/memory/ft_memdel.c \
					srcs/memory/ft_memdels.c \
					srcs/memory/ft_memset.c \
				\
					srcs/string/countwords.c \
					srcs/string/ft_split.c \
					srcs/string/ft_strdup.c \
					srcs/string/ft_strjoinsep.c \
					srcs/string/ft_strlen.c \
					srcs/string/ft_strncmp.c \
					srcs/string/ft_strrchr.c \
				\
					srcs/write/ft_putchar.c \
					srcs/write/ft_putendl.c \
					srcs/write/ft_putstr.c \
				\
					srcs/pipex.c \
				\
					main.c
OBJS			=	$(SRCS:.c=.o)

$(NAME) 		: 	$(OBJS)
					@$(CC) $(CFLAGS) -o $@ $^
all				:	$(NAME)
%.o				:	%.c %.h
					@$(CC) $(CFLAGS) -c $<
clean			:
					@$(RM) $(OBJS)
fclean			:	clean
					@$(RM) $(NAME)
re				:	fclean all
.PHONY			:	all clean fclean re
