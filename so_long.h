/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:05:29 by bolcay            #+#    #+#             */
/*   Updated: 2025/02/28 18:02:48 by batuhan          ###   ########.fr       */
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
# include <stddef.h>
# include <fcntl.h>

# define TILE_SIZE 32
# define WIDTH 2200
# define HEIGHT	1200

typedef struct s_player
{
	int	x;
	int	y;
	int	moves;
	mlx_image_t	*player_image;
	mlx_image_t	*floor_image;
}	t_player;


typedef struct s_game
{
	mlx_t	*mlx;
	char	**map;
	char	*map_file;
	t_player	*player;
	int		collectable_count;
	int		collectable;
	int		exit;
	int		exit_count;
	int		start;
	int		start_count;
}	t_game;

void    map_floor(t_game *game);
void    map_wall(t_game *game);
void    map_collectable(t_game *game);
void    map_exit(t_game *game);
void    map_player(t_game *game);
void    initiate_map(t_game *game);
void    map_background(t_game *game, int x, int y);
void    player_image(t_game *game, int x, int y);
void	start_point(t_game *game);

void	key_hook(mlx_key_data_t keys, void *hey);
int		move_up(t_game *game, t_player *player);
int		move_down(t_game *game, t_player *player);
int		move_left(t_game *game, t_player *player);
int		move_right(t_game *game, t_player *player);

int 	size_of_map(t_game *game);
char 	**read_map(t_game *game);

void    initiate_game(char  **av);

// int	check_corners(char **str);
// int	check_items(char **str);
// int	check_shape(char **str);

#endif