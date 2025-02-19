/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:00:43 by bolcay            #+#    #+#             */
/*   Updated: 2025/02/18 20:16:47 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook(mlx_key_data_t keys, void *game)
{
	t_game *hey;
	int		key_code;

	key_code = keys.key;
	if (keys.action == MLX_PRESS || keys.action == MLX_REPEAT)
	{
		if (key_code == MLX_KEY_W)

		else if (key_code == MLX_KEY_A)

		else if (key_code == MLX_KEY_S)

		else if (key_code == MLX_KEY_D)

		else if (key_code == MLX_KEY_ESCAPE)
		{
			exit(1);
		}
	}
}

int	valid_moves(t_game *game)
{
	
}

void	move_up(t_game game)
{
	int	i;
	int	j;
}
