/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:34:10 by batuhan           #+#    #+#             */
/*   Updated: 2025/03/02 17:55:25 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    error_handling_map(t_game *game)
{
    deallocate_game(game);
    ft_printf("Error, invalid map!\n");
    exit(1);
}
