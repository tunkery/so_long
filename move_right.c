/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:14:38 by batuhan           #+#    #+#             */
/*   Updated: 2025/03/02 18:01:45 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void right_c(t_game *game, t_player *player);
static void right_e(t_game *game);

int	move_right(t_game *game, t_player *player)
{
	game->player->y++;
	if (game->map[player->x][player->y] == 'C')
        right_c(game, player);
	else if (game->map[player->x][player->y] == '1')
	{
		ft_printf("bruh... you can't go there...\n");
		game->player->y--;
	}
	else if (game->map[player->x][player->y] == 'E')
        right_e(game);
	else if (game->map[player->x][player->y] == '0' || game->map[player->x][player->y] == 'P')
	{
		map_background(game, player->x, (player->y - 1));
		player_image(game, player->x, player->y);
	}
	player->moves++;
	ft_printf("move: right,  number of moves: %d\n", player->moves);
	return (1);
}

static void right_c(t_game *game, t_player *player)
{
    ft_printf("You feel your power increasing\n");
    game->collectable_count++;
    map_background(game, (player->x), player->y);
    player_image(game, player->x, player->y);
    map_background(game, player->x, (player->y - 1));
    game->map[player->x][player->y] = '0';
}

static void right_e(t_game *game)
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
		game->player->y--;
	}
}
