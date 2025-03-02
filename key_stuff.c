/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:00:43 by bolcay            #+#    #+#             */
/*   Updated: 2025/03/02 16:22:39 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook(mlx_key_data_t keys, void *hey)
{
	int		key_code;
	t_game	*game;

	game = (t_game *)hey;
	key_code = keys.key;
	if (keys.action == MLX_PRESS || keys.action == MLX_REPEAT)
	{
		if (key_code == MLX_KEY_W)
			move_up(game, game->player);
		else if (key_code == MLX_KEY_A)
			move_left(game, game->player);
		else if (key_code == MLX_KEY_S)
			move_down(game, game->player);
		else if (key_code == MLX_KEY_D)
			move_right(game, game->player);
		else if (key_code == MLX_KEY_ESCAPE)
		{
			exit(1);
		}
	}
}
