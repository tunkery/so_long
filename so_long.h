/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:05:29 by bolcay            #+#    #+#             */
/*   Updated: 2025/02/26 17:10:11 by batuhan          ###   ########.fr       */
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

# define TILE_SIZE 32
# define WIDTH 2200
# define HEIGHT	1200

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

void    map_floor(mlx_t *mlx, t_game *game);
void    map_wall(mlx_t *mlx, t_game *game);
void    map_collectable(mlx_t *mlx, t_game *game);
void    map_exit(mlx_t *mlx, t_game *game);
void    map_player(mlx_t *mlx, t_game *game);
void    initiate_map(mlx_t *mlx, t_game *game);

// int	check_corners(char **str);
// int	check_items(char **str);
// int	check_shape(char **str);

#endif