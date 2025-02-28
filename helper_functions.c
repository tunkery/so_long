/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:19:20 by batuhan           #+#    #+#             */
/*   Updated: 2025/02/28 16:44:37 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int size_of_map(t_game *game)
{
    char    *string;
    int     fd;
    int     map_size;

    map_size = 0;
    fd = open(game->map_file, O_RDONLY);
    if (fd < 0)
        return (0);
    string = get_next_line(fd);
    while (string)
    {
        free (string);
        string = get_next_line(fd);
        map_size++;
    }
    free (string);
    close (fd);
    return (map_size);
}
