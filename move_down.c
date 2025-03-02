/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:13:38 by batuhan           #+#    #+#             */
/*   Updated: 2025/03/02 18:01:48 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void down_c(t_game *game, t_player *player);
static void down_e(t_game *game);

int	move_down(t_game *game, t_player *player)
{
	game->player->x++;
	if (game->map[player->x][player->y] == 'C')
        down_c(game, player);
	else if (game->map[player->x][player->y] == '1')
	{
		ft_printf("bruh... you can't go there...\n");
		game->player->x--;
	}
	else if (game->map[player->x][player->y] == 'E')
        down_e(game);
	else if (game->map[player->x][player->y] == '0' || game->map[player->x][player->y] == 'P')
	{
		map_background(game, (player->x - 1), player->y);
		player_image(game, player->x, player->y);
	}
	player->moves++;
	ft_printf("move: down,  number of moves: %d\n", player->moves);
	return (1);
}

static void down_c(t_game *game, t_player *player)
{
    ft_printf("You feel your power increasing\n");
    game->collectable_count++;
    map_background(game, (player->x), player->y);
    player_image(game, player->x, player->y);
    map_background(game, (player->x - 1), player->y);
    game->map[player->x][player->y] = '0';
}

static void down_e(t_game *game)
{
    int i;

    i = (game->collectable - game->collectable_count);
    if (game->collectable == game->collectable_count)
    {
        mlx_terminate(game->mlx);
		deallocate_game(game);
    }
	else if (game->collectable > game->collectable_count)
	{
		ft_printf("you need to collect %d more magic crystals\n", i);
		game->player->x--;
	}
}
