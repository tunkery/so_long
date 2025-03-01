/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:15:10 by batuhan           #+#    #+#             */
/*   Updated: 2025/03/01 19:29:52 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **read_map(t_game *game)
{
    char    **temp;
    int     i;
    int     fd;

    temp = (char **)malloc(sizeof(char **) * (size_of_map(game) + 1));
    if (!temp)
        return (0);
    fd = open(game->map_file, O_RDONLY);
    if (fd < 0)
        return (0);
    i = 0;
    temp[i] = get_next_line(fd);
    if (!temp[i])
        return (NULL);
    while (temp[i])
    {
        if (temp[i][ft_strlen(temp[i]) - 1] == '\n')
            temp[i][ft_strlen(temp[i]) - 1] = '\0';
        i++;
        temp[i] = get_next_line(fd);
    }
    close (fd);
    return (temp);
}

void	start_point(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player->x = i;
				game->player->y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}
