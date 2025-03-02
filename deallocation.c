/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deallocation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:40:54 by batuhan           #+#    #+#             */
/*   Updated: 2025/03/02 17:33:58 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    deallocate_struct(t_game *game)
{
    int i;

    i = 0;
    if (!game->map)
        return ;
    while (game->map[i])
    {
        free(game->map[i]);
        i++;
    }
}

void    deallocate_bool(bool **visited)
{
    int i;

    i = 0;
    if (!visited)
        return ;
    while (visited[i])
    {
        free(visited[i]);
        i++;
    }
}

void    deallocate_game(t_game *game)
{
    deallocate_struct(game);
    game->map = NULL;
    free(game->player);
    game->player = NULL;
    free(game);
    game = NULL;
}
