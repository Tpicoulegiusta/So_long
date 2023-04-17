# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 10:46:54 by tpicoule          #+#    #+#              #
#    Updated: 2023/04/17 13:41:29 by tpicoule         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

SOURCES		= so_long.c \
			  so_long_utils.c \
			  so_long_utils_2.c \
			  so_long_utils_3.c \
			  get_next_line.c \
			  ft_split.c \
			  get_next_line_utils.c
OBJECTS		= ${SOURCES:.c=.o}
RM			= rm -f
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: 	${OBJECTS}

all:		${NAME}

clean:
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
