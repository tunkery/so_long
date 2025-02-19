/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:05:29 by bolcay            #+#    #+#             */
/*   Updated: 2025/02/18 19:33:03 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdbool.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>

# define WIDTH 1800
# define HEIGHT	1000

typedef struct s_player
{
	int	x;
	int	y;
	int	moves;
}	t_player;


typedef struct s_game
{
	mlx_t	mlx;
	char	**map;
	char	*row;
	char	**player_pos;
	int		collectable_count;
	int		collectable;
	int		exit;
	int		exit_count;
	int		start;
	int		start_count;
}	t_game;

int	check_corners(char **str);
int	check_items(char **str);
int	check_shape(char **str);

#endif