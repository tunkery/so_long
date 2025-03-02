/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:36:57 by bolcay            #+#    #+#             */
/*   Updated: 2025/03/02 17:56:47 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_shape(t_game *game);
static int	check_items(t_game *game);
static int	check_corners(t_game *game, int i, int j);
static int	check_valid_path(t_game *game);

int	check_map(t_game *game)
{
	if (check_shape(game) == -1)
		error_handling_map(game);
	if (check_corners(game, 0, 0) == -1)
		error_handling_map(game);
	if (check_items(game) == -1)
		error_handling_map(game);
	if (check_valid_path(game) == -1)
		error_handling_map(game);
	return (1);
}

static int	check_valid_path(t_game *game)
{
	bool	**visited;
	int		i;

	i = 0;
	game->exit_found = 0;
	game->cc = 0;
	visited = (bool **)malloc(sizeof(bool *) * size_of_map(game));
	if (!visited)
		return (0);
	while (i < size_of_map(game))
	{
		visited[i] = (bool *)malloc(sizeof(bool) * (ft_strlen(game->map[i]) - 1));
		if (!visited[i])
			return (0);
		i++;
	}
	start_point(game);
	dfs(game, visited, game->player->x, game->player->y);
	deallocate_bool(visited);
	if (game->exit_found > 0 && game->cc == game->collectable)
		return (1);
	return (-1);
}

static int	check_corners(t_game *game, int i, int j)
{
	while (game->map[i][j])
	{
		if (game->map[i][j] != '1')
			return (-1);
		j++;
	}
	j--;
	while (game->map[i])
	{
		if (game->map[i][0] != '1' || game->map[i][j] != '1')
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

static int	check_items(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->collectable = 0;
	game->exit_count = 0;
	game->start_count = 0;
	while (game->map[++i])
	{
		j = 0;
		while (game->map[i][++j])
		{
			if (game->map[i][j] != 'C' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'P' && game->map[i][j] != '0'
				&& game->map[i][j] != '1')
				return (-1);
			if (game->map[i][j] == 'C')
				game->collectable++;
			if (game->map[i][j] == 'E')
				game->exit_count++;
			if (game->map[i][j] == 'P')
				game->start_count++;
		}
	}
	if (game->collectable < 1 || game->exit_count != 1 || game->start_count != 1)
		return (-1);
	return (1);
}

static int	check_shape(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i][j])
		j++;
	while (game->map[i])
		i++;
	i--;
	j--;
	game->row_lenght = i;
	game->col_lenght = j;
	if (i == j)
		return (-1);
	return (1);
}
