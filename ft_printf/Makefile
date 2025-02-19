# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 20:30:18 by bolcay            #+#    #+#              #
#    Updated: 2025/02/15 14:44:20 by bolcay           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf_utils.c ft_printf_utils2.c ft_printf.c ft_printf_utils3.c

OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -fr

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re