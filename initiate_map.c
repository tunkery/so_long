/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:59:17 by batuhan           #+#    #+#             */
/*   Updated: 2025/03/03 01:42:23 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initiate_map(t_game *game)
{
	map_floor(game);
	map_wall(game);
	map_collectable(game);
	map_exit(game);
	map_player(game);
}

void	map_floor(t_game *game)
{
	mlx_texture_t	*floor_img;
	int				col;
	int				row;

	floor_img = mlx_load_png("images/floor.png");
	game->player->floor_image_c = mlx_texture_to_image(game->mlx, floor_img);
	if (!game->player->floor_image_c || !floor_img)
		return ;
	row = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col])
		{
			if (game->map[row][col] == '0' || game->map[row][col] == 'P'
				|| game->map[row][col] == 'C' || game->map[row][col] == 'E')
				mlx_image_to_window(game->mlx, game->player->floor_image_c, (col * TS), (row * TS));
			col++;
		}
		row++;
	}
	mlx_delete_texture(floor_img);
}

void	map_wall(t_game *game)
{
	mlx_texture_t	*wall_img;
	int				col;
	int				row;

	wall_img = mlx_load_png("images/wall.png");
	game->player->wall_image = mlx_texture_to_image(game->mlx, wall_img);
	if (!wall_img || !game->player->wall_image)
		return ;
	row = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col])
		{
			if (game->map[row][col] == '1')
				mlx_image_to_window(game->mlx, game->player->wall_image, (col * TS), (row * TS));
			col++;
		}
		row++;
	}
	mlx_delete_texture(wall_img);
}

void	map_collectable(t_game *game)
{
	mlx_texture_t	*collectable_img;
	int				col;
	int				row;

	collectable_img = mlx_load_png("images/magic.png");
	game->player->coll_image = mlx_texture_to_image(game->mlx, collectable_img);
	if (!game->player->coll_image || !collectable_img)
		return ;
	row = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col])
		{
			if (game->map[row][col] == 'C')
				mlx_image_to_window(game->mlx, game->player->coll_image, (col * TS), (row * TS));
			col++;
		}
		row++;
	}
	mlx_delete_texture(collectable_img);
}

void	map_exit(t_game *game)
{
	mlx_texture_t	*exit_img;
	int				col;
	int				row;

	exit_img = mlx_load_png("images/door.png");
	game->player->exit_image = mlx_texture_to_image(game->mlx, exit_img);
	if (!exit_img || !game->player->exit_image)
		return ;
	row = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col])
		{
			if (game->map[row][col] == 'E')
				mlx_image_to_window(game->mlx, game->player->exit_image, (col * TS), (row * TS));
			col++;
		}
		row++;
	}
	mlx_delete_texture(exit_img);
}
