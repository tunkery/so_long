# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/16 19:05:06 by bolcay            #+#    #+#              #
#    Updated: 2025/02/28 16:58:24 by batuhan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c initiate_map.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		key_stuff.c helper_functions.c map_functions.c initiate_game.c

CC = cc
CFLAGS = -Wall -Werror -Wextra -g $(INCLUDE)
RM = rm -f
RM_DIR = rm -rf
NAME = so_long
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT_LIB = ${LIBFT_DIR}/libft.a

FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

MLX42_DIR = MLX42
MLX42_LIB = $(MLX42_DIR)/build/libmlx42.a

INCLUDE     = -I$(MLX42_DIR)/include -I header -I libft
LDINCLUDE   = -L$(MLX42_DIR)/build -lmlx42 -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -lglfw

all: ${NAME}

$(FT_PRINTF_LIB):
	make -C $(FT_PRINTF_DIR) && make clean -C $(FT_PRINTF_DIR)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR) && make clean -C $(LIBFT_DIR)

$(NAME): $(MLX42_LIB) $(LIBFT_LIB) $(FT_PRINTF_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDINCLUDE) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM_DIR) $(OBJS)

fclean: clean
		$(RM) $(NAME)
		make fclean -C $(FT_PRINTF_DIR)
		make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re