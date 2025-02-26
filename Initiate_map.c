/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Initiate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:59:17 by batuhan           #+#    #+#             */
/*   Updated: 2025/02/26 14:34:01 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    initiate_map()
{
}

void    map_floor(mlx_t *mlx)
{
    mlx_image_t *floor;
    mlx_texture_t   *floor_image;

    floor_image = mlx_load_png("images/dungeon_tile1.png");
    if (!floor_image)
        return (0);
    floor = mlx_texture_to_image(mlx, floor_image);
    mlx_delete_texture(floor_image);
}

void    map_wall(mlx_t *mlx)
{
    mlx_image_t *wall;
    mlx_texture_t   *wall_image;

    wall_image = mlx_load_png("images/dungeon_wall.png");
    if (!wall_image)
        return (0);
    wall = mlx_texture_to_image(mlx, wall_image);
    mlx_delete_texture(wall_image);
}

void    map_collectable(mlx_t *mlx)
{
    mlx_image_t *collectable;
    mlx_texture_t   *collectable_image;

    collectable_image = mlx_load_png("images/collectable.png");
    if (!collectable_image)
        return (0);
    collectable = mlx_texture_to_image(mlx, collectable_image);
    mlx_delete_texture(collectable_image);
}

void    map_exit(mlx_t *mlx)
{
    mlx_image_t *exit;
    mlx_texture_t   *exit_image;

    exit_image = mlx_load_png("images/exit_image.png");
    if (!exit_image)
        return (0);
    exit = mlx_texture_to_image(mlx, exit_image);
    mlx_delete_texture(exit_image);
}

void    map_player(mlx_t *mlx)
{
    mlx_image_t *player;
    mlx_texture_t   *player_image;

    player_image = mlx_load_png("images/player_image.png");
    if (!player_image)
        return (0);
    player = mlx_texture_to_image(mlx, player_image);
    mlx_delete_texture(player_image);
}
