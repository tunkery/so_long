/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:05:29 by bolcay            #+#    #+#             */
/*   Updated: 2025/02/26 18:49:57 by batuhan          ###   ########.fr       */
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
	void	*player;
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
void    map_background(mlx_t *mlx, int x, int y);
void    player_image(mlx_t *mlx, int x, int y);

void	key_hook(mlx_key_data_t keys, t_game *hey, mlx_t *mlx);
int		move_up(t_game *game, t_player *player, mlx_t *mlx);
int		move_down(t_game *game, t_player *player, mlx_t *mlx);
int		move_left(t_game *game, t_player *player, mlx_t *mlx);
int		move_right(t_game *game, t_player *player, mlx_t *mlx);

// int	check_corners(char **str);
// int	check_items(char **str);
// int	check_shape(char **str);

#endif