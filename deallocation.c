/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deallocation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:40:54 by batuhan           #+#    #+#             */
/*   Updated: 2025/03/02 20:46:23 by bolcay           ###   ########.fr       */
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
}

void	deallocate_bool(bool **visited)
{
	int	i;

	i = 0;
	if (!visited)
		return ;
	while (visited[i])
	{
		free(visited[i]);
		i++;
	}
}

void	deallocate_game(t_game *game)
{
	deallocate_struct(game);
	free(game->player);
	free(game);
}

void	clean_exit(t_game *game)
{
	if (game->player->player_image)
		mlx_delete_image(game->mlx, game->player->player_image);
	if (game->player->floor_image)
		mlx_delete_image(game->mlx, game->player->floor_image);
	mlx_terminate(game->mlx);
	deallocate_game(game);
	exit (EXIT_SUCCESS);
}
