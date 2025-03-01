/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:00:43 by bolcay            #+#    #+#             */
/*   Updated: 2025/03/01 18:48:27 by batuhan          ###   ########.fr       */
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

int	move_up(t_game *game, t_player *player)
{
	game->player->x--;
	if (game->map[player->x][player->y] == 'C')
	{
		ft_printf("a motivational message for collecting something!!!\n");
		game->collectable_count++;
		map_background(game, (player->x), player->y);
		player_image(game, player->x, player->y);
		map_background(game, (player->x + 1), player->y);
		game->map[player->x][player->y] = '0';
	}
	else if (game->map[player->x][player->y] == '1')
	{
		ft_printf("bruh... you can't go there...\n");
		game->player->x++;
	}
	else if (game->map[player->x][player->y] == 'E' && game->collectable == game->collectable_count)
	{
		ft_printf("congrats!!\n");
		exit(1);
	}
	else if (game->map[player->x][player->y] == 'E' && game->collectable > game->collectable_count)
	{
		ft_printf("you need to collect %d more items\n", (game->collectable - game->collectable_count));
		game->player->x++;
	}
	else if (game->map[player->x][player->y] == '0' || game->map[player->x][player->y] == 'P')
	{
		map_background(game, (player->x + 1), player->y);
		player_image(game, player->x, player->y);
	}
	player->moves++;
	ft_printf("move: up,  number of moves: %d\n", player->moves);
	return (1);
}

int	move_down(t_game *game, t_player *player)
{
	game->player->x++;
	if (game->map[player->x][player->y] == 'C')
	{
		ft_printf("a motivational message for collecting something!!!\n");
		game->collectable_count++;
		map_background(game, (player->x), player->y);
		player_image(game, player->x, player->y);
		map_background(game, (player->x - 1), player->y);
		game->map[player->x][player->y] = '0';
	}
	else if (game->map[player->x][player->y] == '1')
	{
		ft_printf("bruh... you can't go there...\n");
		game->player->x--;
	}
	else if (game->map[player->x][player->y] == 'E' && game->collectable == game->collectable_count)
	{
		ft_printf("congrats!!\n");
		exit(1);
	}
	else if (game->map[player->x][player->y] == 'E' && game->collectable > game->collectable_count)
	{
		ft_printf("you need to collect %d more items\n", (game->collectable - game->collectable_count));
		game->player->x--;
	}
	else if (game->map[player->x][player->y] == '0' || game->map[player->x][player->y] == 'P')
	{
		map_background(game, (player->x - 1), player->y);
		player_image(game, player->x, player->y);
	}
	player->moves++;
	ft_printf("move: down,  number of moves: %d\n", player->moves);
	return (1);
}

int	move_right(t_game *game, t_player *player)
{
	game->player->y++;
	if (game->map[player->x][player->y] == 'C')
	{
		ft_printf("a motivational message for collecting something!!!\n");
		game->collectable_count++;
		map_background(game, (player->x), player->y);
		player_image(game, player->x, player->y);
		map_background(game, player->x, (player->y - 1));
		game->map[player->x][player->y] = '0';
	}
	else if (game->map[player->x][player->y] == '1')
	{
		ft_printf("bruh... you can't go there...\n");
		game->player->y--;
	}
	else if (game->map[player->x][player->y] == 'E' && game->collectable == game->collectable_count)
	{
		ft_printf("congrats!!\n");
		exit(1);
	}
	else if (game->map[player->x][player->y] == 'E' && game->collectable > game->collectable_count)
	{
		ft_printf("you need to collect %d more items\n", (game->collectable - game->collectable_count));
		game->player->y--;
	}
	else if (game->map[player->x][player->y] == '0' || game->map[player->x][player->y] == 'P')
	{
		map_background(game, player->x, (player->y - 1));
		player_image(game, player->x, player->y);
	}
	player->moves++;
	ft_printf("move: right,  number of moves: %d\n", player->moves);
	return (1);
}

int	move_left(t_game *game, t_player *player)
{
	game->player->y--;
	if (game->map[player->x][player->y] == 'C')
	{
		ft_printf("a motivational message for collecting something!!!\n");
		game->collectable_count++;
		map_background(game, (player->x), player->y);
		player_image(game, player->x, player->y);
		map_background(game, player->x, (player->y + 1));
		game->map[player->x][player->y] = '0';
	}
	else if (game->map[player->x][player->y] == '1')
	{
		ft_printf("bruh... you can't go there...\n");
		game->player->y++;
	}
	else if (game->map[player->x][player->y] == 'E' && game->collectable == game->collectable_count)
	{
		ft_printf("congrats!!\n");
		exit(1);
	}
	else if (game->map[player->x][player->y] == 'E' && game->collectable > game->collectable_count)
	{
		ft_printf("you need to collect %d more items\n", (game->collectable - game->collectable_count));
		game->player->y++;
	}
	else if (game->map[player->x][player->y] == '0' || game->map[player->x][player->y] == 'P')
	{
		map_background(game, player->x, (player->y + 1));
		player_image(game, player->x, player->y);
	}
	player->moves++;
	ft_printf("move: left,  number of moves: %d\n", player->moves);
	return (1);
}
