/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_map_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:56:29 by batuhan           #+#    #+#             */
/*   Updated: 2025/03/02 14:58:53 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    map_player(t_game *game)
{
    mlx_image_t *player;
    mlx_texture_t   *player_image;
    int col;
    int row;

    player_image = mlx_load_png("images/player_image.png");
    player = mlx_texture_to_image(game->mlx, player_image);
    if (!player_image || !player)
        return ;
    row = 0;
    while (game->map[row])
    {
        col = 0;
        while (game->map[row][col])
        {
            if (game->map[row][col] == 'P')
                mlx_image_to_window(game->mlx, player, (col * TILE_SIZE), (row * TILE_SIZE));
            col++;
        }
        row++;
    }
    mlx_delete_texture(player_image);
}

void    map_background(t_game *game, int x, int y)
{
    mlx_texture_t   *floor_image;
    int	col;
    int row;

    floor_image = mlx_load_png("images/floor.png");
    game->player->floor_image = mlx_texture_to_image(game->mlx, floor_image);
    if (!game->player->floor_image || !floor_image)
        return ;
    col = y * TILE_SIZE;
    row = x * TILE_SIZE;
    mlx_image_to_window(game->mlx, game->player->floor_image, col, row);
    mlx_delete_texture(floor_image);
}

void    player_image(t_game *game, int x, int y)
{
    mlx_texture_t   *player_image;
    int col;
    int row;

    player_image = mlx_load_png("images/player_image.png");
    game->player->player_image = mlx_texture_to_image(game->mlx, player_image);
    if (!game->player->player_image || !player_image)
        return ;
    col = y * TILE_SIZE;
    row = x * TILE_SIZE;
    mlx_image_to_window(game->mlx, game->player->player_image, col, row);
    mlx_delete_texture(player_image);
}
