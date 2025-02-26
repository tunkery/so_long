/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:00:43 by bolcay            #+#    #+#             */
/*   Updated: 2025/02/26 18:30:09 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook(mlx_key_data_t keys, t_game *hey, mlx_t *mlx)
{
	int		key_code;

	key_code = keys.key;
	if (keys.action == MLX_PRESS || keys.action == MLX_REPEAT)
	{
		if (key_code == MLX_KEY_W)
			move_up(hey, hey->player, mlx);
		else if (key_code == MLX_KEY_A)

		else if (key_code == MLX_KEY_S)

		else if (key_code == MLX_KEY_D)

		else if (key_code == MLX_KEY_ESCAPE)
		{
			exit(1);
		}
	}
}

int	move_up(t_game *game, t_player *player, mlx_t *mlx)
{
	if (game->map[player->x][player->y] == 'C')
	{
		ft_printf("a motivational message for collecting something!!!\n");
		game->collectable_count++;
		map_background(mlx, game, player->x, player->y);
		player->x++;
		player_image(mlx, game, player->x, player->y);
	}
	// else if (game->map[player->x][player->y] == '1')
	// {
	// 	ft_printf("bruh... you can't go there...\n");
	// }
	else if (game->map[player->x][player->y] == 'E' && game->collectable == game->collectable_count)
	{
		ft_printf("congrats!!\n");
	}
	else if (game->map[player->x][player->y] == 'E' && game->collectable > game->collectable_count)
	{
		ft_printf("you need to collect %d more items\n", (game->collectable - game->collectable_count));
		player->x++;
		player_image(mlx, game, player->x, player->y);
	}
	else if (game->map[player->x][player->y] == '0')
	{
		player->x++;
		player_image(mlx, game, player->x, player->y);
	}
	player->moves++;
	ft_printf("move: up,  number of moves: %d\n", player->moves);
	return (1);
}

int	move_down(t_game *game, t_player *player, mlx_t *mlx)
{
	if (game->map[player->x][player->y] == 'C')
	{
		ft_printf("a motivational message for collecting something!!!\n");
		game->collectable_count++;
		map_background(mlx, game, player->x, player->y);
		player->x--;
		player_image(mlx, game, player->x, player->y);
	}
	// else if (game->map[player->x][player->y] == '1')
	// {
	// 	ft_printf("bruh... you can't go there...\n");
	// }
	else if (game->map[player->x][player->y] == 'E' && game->collectable == game->collectable_count)
	{
		ft_printf("congrats!!\n");
	}
	else if (game->map[player->x][player->y] == 'E' && game->collectable > game->collectable_count)
	{
		ft_printf("you need to collect %d more items\n", (game->collectable - game->collectable_count));
		player->x--;
		player_image(mlx, game, player->x, player->y);
	}
	else if (game->map[player->x][player->y] == '0')
	{
		player->x--;
		player_image(mlx, game, player->x, player->y);
	}
	player->moves++;
	ft_printf("move: down,  number of moves: %d\n", player->moves);
	return (1);
}

int	move_right(t_game *game, t_player *player, mlx_t *mlx)
{
	if (game->map[player->x][player->y] == 'C')
	{
		ft_printf("a motivational message for collecting something!!!\n");
		game->collectable_count++;
		map_background(mlx, game, player->x, player->y);
		player->y++;
		player_image(mlx, game, player->x, player->y);
	}
	// else if (game->map[player->x][player->y] == '1')
	// {
	// 	ft_printf("bruh... you can't go there...\n");
	// }
	else if (game->map[player->x][player->y] == 'E' && game->collectable == game->collectable_count)
	{
		ft_printf("congrats!!\n");
	}
	else if (game->map[player->x][player->y] == 'E' && game->collectable > game->collectable_count)
	{
		ft_printf("you need to collect %d more items\n", (game->collectable - game->collectable_count));
		player->y++;
		player_image(mlx, game, player->x, player->y);
	}
	else if (game->map[player->x][player->y] == '0')
	{
		player->y++;
		player_image(mlx, game, player->x, player->y);
	}
	player->moves++;
	ft_printf("move: right,  number of moves: %d\n", player->moves);
	return (1);
}

int	move_left(t_game *game, t_player *player, mlx_t *mlx)
{
	if (game->map[player->x][player->y] == 'C')
	{
		ft_printf("a motivational message for collecting something!!!\n");
		game->collectable_count++;
		map_background(mlx, game, player->x, player->y);
		player->y--;
		player_image(mlx, game, player->x, player->y);
	}
	// else if (game->map[player->x][player->y] == '1')
	// {
	// 	ft_printf("bruh... you can't go there...\n");
	// }
	else if (game->map[player->x][player->y] == 'E' && game->collectable == game->collectable_count)
	{
		ft_printf("congrats!!\n");
	}
	else if (game->map[player->x][player->y] == 'E' && game->collectable > game->collectable_count)
	{
		ft_printf("you need to collect %d more items\n", (game->collectable - game->collectable_count));
		player->y--;
		player_image(mlx, game, player->x, player->y);
	}
	else if (game->map[player->x][player->y] == '0')
	{
		player->y--;
		player_image(mlx, game, player->x, player->y);
	}
	player->moves++;
	ft_printf("move: left,  number of moves: %d\n", player->moves);
	return (1);
}
