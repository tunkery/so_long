/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:59:17 by batuhan           #+#    #+#             */
/*   Updated: 2025/02/26 17:10:18 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    initiate_map(mlx_t *mlx, t_game *game)
{
    map_floor(mlx, game);
    map_wall(mlx, game);
    map_collectable(mlx, game);
    map_exit(mlx, game);
    map_player(mlx, game);
}

void    map_floor(mlx_t *mlx, t_game *game)
{
    mlx_image_t *floor;
    mlx_texture_t   *floor_image;
    int	col;
    int row;

    floor_image = mlx_load_png("images/dungeon_tile1.png");
    floor = mlx_texture_to_image(mlx, floor_image);
    if (!floor || !floor_image)
        return ;
    row = 0;
    while (game->map[row])
    {
        col = 0;
        while (game->map[row][col])
        {
            if (game->map[row][col] == '0')
                mlx_image_to_window(mlx, floor, (col * TILE_SIZE), (row * TILE_SIZE));
            col++;
        }
        row++;
    }
    mlx_delete_texture(floor_image);
}

void    map_wall(mlx_t *mlx, t_game *game)
{
    mlx_image_t *wall;
    mlx_texture_t   *wall_image;
    int col;
    int row;

    wall_image = mlx_load_png("images/dungeon_wall.png");
    wall = mlx_texture_to_image(mlx, wall_image);
    if (!wall_image || !wall)
        return ;
    row = 0;
    while (game->map[row])
    {
        col = 0;
        while (game->map[row][col])
        {
            if (game->map[row][col] == '1')
                mlx_image_to_window(mlx, wall, (col * TILE_SIZE), (row * TILE_SIZE));
            col++;
        }
        row++;
    }
    mlx_delete_texture(wall_image);
}

void    map_collectable(mlx_t *mlx, t_game *game)
{
    mlx_image_t *collectable;
    mlx_texture_t   *collectable_image;
    int col;
    int row;

    collectable_image = mlx_load_png("images/collectable.png");
    if (!collectable_image)
        return ;
    collectable = mlx_texture_to_image(mlx, collectable_image);
    row = 0;
    while (game->map[row])
    {
        col = 0;
        while (game->map[row][col])
        {
            if (game->map[row][col] == 'C')
                mlx_image_to_window(mlx, collectable, (col * TILE_SIZE), (row * TILE_SIZE));
            col++;
        }
        row++;
    }
    mlx_delete_texture(collectable_image);
}

void    map_exit(mlx_t *mlx, t_game *game)
{
    mlx_image_t *exit;
    mlx_texture_t   *exit_image;
    int col;
    int row;

    exit_image = mlx_load_png("images/exit_image.png");
    exit = mlx_texture_to_image(mlx, exit_image);
    if (!exit_image || !exit)
        return ;
    row = 0;
    while (game->map[row])
    {
        col = 0;
        while (game->map[row][col])
        {
            if (game->map[row][col] == 'E')
                mlx_image_to_window(mlx, exit, (col * TILE_SIZE), (row * TILE_SIZE));
            col++;
        }
        row++;
    }
    mlx_delete_texture(exit_image);
}

void    map_player(mlx_t *mlx, t_game *game)
{
    mlx_image_t *player;
    mlx_texture_t   *player_image;
    int col;
    int row;

    player_image = mlx_load_png("images/player_image.png");
    player = mlx_texture_to_image(mlx, player_image);
    if (!player_image || !player)
        return ;
    row = 0;
    while (game->map[row])
    {
        col = 0;
        while (game->map[row][col])
        {
            if (game->map[row][col] == 'P')
                mlx_image_to_window(mlx, player, (col * TILE_SIZE), (row * TILE_SIZE));
            col++;
        }
        row++;
    }
    mlx_delete_texture(player_image);
}
