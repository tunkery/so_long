/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:36:57 by bolcay            #+#    #+#             */
/*   Updated: 2025/02/28 17:22:25 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_path(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	while (game->map[i])
	{
		j = 0;
		count = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '0' || game->map[i][j] == 'C')
				count++;
			j++;
		}
		if (count < 1 && game->map[i])
		{
			ft_printf("no valid path\n");
			exit(1);
		}
		i++;
	}
	return (1);
}

int	check_corners(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i][j])
	{
		if (game->map[i][j] != '1')
			return (-1);
		j++;
	}
	j--;
	while (game->map[i])
	{
		if (game->map[i][0] != '1')
			return (-1);
		if (game->map[i][j] != '1')
			return (-1);
		i++;
	}
	j = 0;
	i--;
	while (game->map[i][j])
	{
		if (game->map[i][j] != '1')
			return (-1);
		j++;
	}
	return (1);
}

int	check_items(t_game *game, char **str)
{
	int	i;
	int	j;

	i = 1;
	game->collectable = 0;
	game->exit_count = 0;
	game->start_count = 0;
	while (str[i])
	{
		j = 1;
		while (str[i][j])
		{
			if (str[i][j] == 'C')
				game->collectable++;
			if (str[i][j] == 'E')
				game->exit_count++;
			if (str[i][j] == 'P')
				game->start_count++;
			j++;
		}
		i++;
	}
	if (game->collectable < 1 || game->exit_count != 1 || game->start_count != 1)
		return (-1);
	return (1);
}

int	check_shape(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i][j])
		j++;
	while (game->map[i])
		i++;
	if (i == j)
		return (-1);
	return (1);
}
