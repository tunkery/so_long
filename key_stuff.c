/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:00:43 by bolcay            #+#    #+#             */
/*   Updated: 2025/02/20 23:47:42 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook(mlx_key_data_t keys, void *game)
{
	t_game *hey;
	t_player *plyr;
	int		key_code;

	key_code = keys.key;
	if (keys.action == MLX_PRESS || keys.action == MLX_REPEAT)
	{
		if (key_code == MLX_KEY_W)
			move_up(hey, plyr);
		else if (key_code == MLX_KEY_A)

		else if (key_code == MLX_KEY_S)

		else if (key_code == MLX_KEY_D)

		else if (key_code == MLX_KEY_ESCAPE)
		{
			exit(1);
		}
	}
}

int	move_up(t_game *game, t_player *player)
{
	player->y++;
	if (game->map[player->x][player->y] == 'C')
	{
		ft_printf("a motivational message for collecting something!!!\n");
	}
	if (game->map[player->x][player->y] == '1')
	{
		ft_printf("bruh... you can't go there...\n");
	}
	return (1);
}

void	move_up(t_game game)
{
	int	i;
	int	j;
}
