/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:59:17 by batuhan           #+#    #+#             */
/*   Updated: 2025/02/28 18:28:50 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    initiate_map(t_game *game)
{
    map_floor(game);
    map_wall(game);
    map_collectable(game);
    map_exit(game);
    map_player(game);
}

void    map_floor(t_game *game)
{
    mlx_image_t *floor;
    mlx_texture_t   *floor_image;
    int	col;
    int row;

    floor_image = mlx_load_png("images/dungeon_tile1.png");
    floor = mlx_texture_to_image(game->mlx, floor_image);
    if (!floor || !floor_image)
        return ;
    row = 0;
    while (game->map[row])
    {
        col = 0;
        while (game->map[row][col])
        {
            if (game->map[row][col] == '0')
                mlx_image_to_window(game->mlx, floor, (row * TILE_SIZE), (col * TILE_SIZE));
            col++;
        }
        row++;
    }
    mlx_delete_texture(floor_image);
}

void    map_wall(t_game *game)
{
    mlx_image_t *wall;
    mlx_texture_t   *wall_image;
    int col;
    int row;

    wall_image = mlx_load_png("images/dungeon_wall.png");
    wall = mlx_texture_to_image(game->mlx, wall_image);
    if (!wall_image || !wall)
        return ;
    row = 0;
    while (game->map[row])
    {
        col = 0;
        while (game->map[row][col])
        {
            if (game->map[row][col] == '1')
                mlx_image_to_window(game->mlx, wall, (row * TILE_SIZE), (col * TILE_SIZE));
            col++;
        }
        row++;
    }
    mlx_delete_texture(wall_image);
}

void    map_collectable(t_game *game)
{
    mlx_image_t *collectable;
    mlx_texture_t   *collectable_image;
    int col;
    int row;

    collectable_image = mlx_load_png("images/collectable.png");
    collectable = mlx_texture_to_image(game->mlx, collectable_image);
    if (!collectable || !collectable_image)
        return ;
    game->collectable = 0;
    row = 0;
    while (game->map[row])
    {
        col = 0;
        while (game->map[row][col])
        {
            if (game->map[row][col] == 'C')
            {
                mlx_image_to_window(game->mlx, collectable, (row * TILE_SIZE), (col * TILE_SIZE));
                game->collectable++;
            }
            col++;
        }
        row++;
    }
    mlx_delete_texture(collectable_image);
}

void    map_exit(t_game *game)
{
    mlx_image_t *exit;
    mlx_texture_t   *exit_image;
    int col;
    int row;

    exit_image = mlx_load_png("images/exit_image.png");
    exit = mlx_texture_to_image(game->mlx, exit_image);
    if (!exit_image || !exit)
        return ;
    row = 0;
    while (game->map[row])
    {
        col = 0;
        while (game->map[row][col])
        {
            if (game->map[row][col] == 'E')
                mlx_image_to_window(game->mlx, exit, (row * TILE_SIZE), (col * TILE_SIZE));
            col++;
        }
        row++;
    }
    mlx_delete_texture(exit_image);
}

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
                mlx_image_to_window(game->mlx, player, (row * TILE_SIZE), (col * TILE_SIZE));
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

    floor_image = mlx_load_png("images/dungeon_tile1.png");
    game->player->floor_image = mlx_texture_to_image(game->mlx, floor_image);
    if (!game->player->floor_image || !floor_image)
        return ;
    col = x * TILE_SIZE;
    row = y * TILE_SIZE;
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
    col = x * TILE_SIZE;
    row = y * TILE_SIZE;
    mlx_image_to_window(game->mlx, game->player->player_image, col, row);
    mlx_delete_texture(player_image);
}
