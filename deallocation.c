/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deallocation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:40:54 by batuhan           #+#    #+#             */
/*   Updated: 2025/03/04 15:15:41 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	deallocate_struct(t_game *game)
{
	int	i;

	i = 0;
	if (!game->map)
		return ;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	deallocate_bool(bool **visited)
{
	int	i;

	i = 0;
	if (!visited)
		return ;
	while (visited[i])
		i++;
	while (i >= 0)
	{
		i--;
		free(visited[i]);
	}
	free(visited);
}

void	deallocate_game(t_game *game)
{
	deallocate_struct(game);
	game->map = NULL;
	free(game->player);
	game->player = NULL;
	free(game);
	game = NULL;
}

void	clean_exit(t_game *game)
{
	if (game->player->player_image)
		mlx_delete_image(game->mlx, game->player->player_image);
	if (game->player->floor_image)
		mlx_delete_image(game->mlx, game->player->floor_image);
	if (game->player->player_image_c)
		mlx_delete_image(game->mlx, game->player->player_image_c);
	if (game->player->floor_image_c)
		mlx_delete_image(game->mlx, game->player->floor_image_c);
	if (game->player->wall_image)
		mlx_delete_image(game->mlx, game->player->wall_image);
	if (game->player->coll_image)
		mlx_delete_image(game->mlx, game->player->coll_image);
	if (game->player->exit_image)
		mlx_delete_image(game->mlx, game->player->exit_image);
	mlx_terminate(game->mlx);
	deallocate_game(game);
	exit (EXIT_SUCCESS);
}
