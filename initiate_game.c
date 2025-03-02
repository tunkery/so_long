/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:11:04 by batuhan           #+#    #+#             */
/*   Updated: 2025/03/02 17:33:57 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    initiate_game(char  **av)
{
    t_game  *game;

    game = malloc(sizeof(t_game));
    game->player = malloc(sizeof(t_player));
    if (!game || !game->player)
        return ;
    game->map_file = av[1];
    game->map = read_map(game);
    if (!game->map)
        return ;
    check_map(game);
    start_point(game);
    game->mlx = mlx_init(WIDTH, HEIGHT, "game", true);
    if (!game->mlx)
        return ;
    initiate_map(game);
    mlx_key_hook(game->mlx, key_hook, game);
    mlx_loop(game->mlx);
    mlx_terminate(game->mlx);
    deallocate_game(game);
}
