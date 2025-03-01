/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:36:57 by bolcay            #+#    #+#             */
/*   Updated: 2025/03/01 19:31:41 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_shape(t_game *game);
static int	check_items(t_game *game);
static int	check_corners(t_game *game);
static int	a_function(t_game *game);
static void	dfs(t_game *game, bool **visited, int row, int col);

int	check_map(t_game *game)
{
	if (check_shape(game) == -1)
		exit(1);
	ft_printf("check\n");
	if (check_corners(game) == -1)
		exit(1);
	ft_printf("check1\n");
	if (check_items(game) == -1)
		exit(1);
	ft_printf("check2\n");
	if (a_function(game) == -1)
		exit(1);
	ft_printf("check3\n");
	return (1);
}



static void	initiate_directions(int directions[4][2])
{
	directions[0][0] = -1;
	directions[0][1] = 0;
	directions[1][0] = 1;
	directions[1][1] = 0;
	directions[2][0] = 0;
	directions[2][1] = -1;
	directions[3][0] = 0;
	directions[3][1] = 1;
}

static void	dfs(t_game *game, bool **visited, int row, int col)
{
	int	directions[4][2];
	int	n_row;
	int	n_col;
	int	i;

	i = 0;
	initiate_directions(directions);
	if (game->map[row][col] == 'C')
		game->cc++;
	else if (game->map[row][col] == 'E')
		game->exit_found = 1;
	visited[row][col] = true;
	while (i < 4)
	{
		n_row = row + directions[i][0];
		n_col = col + directions[i][1];
		if (n_row >= 0 && n_row < game->row_lenght && n_col >= 0 
			&& n_col < game->col_lenght && !visited[n_row][n_col]
			&& game->map[n_row][n_col] != '1')
			dfs(game, visited, n_row, n_col);
		i++;
	}
}

static int	a_function(t_game *game)
{
	bool	**visited;
	int		i;
	int		j;

	i = 0;
	j = 0;
	game->exit_found = 0;
	game->cc = 0;
	visited = (bool **)malloc(sizeof(bool *) * size_of_map(game));
	if (!visited)
		return (0);
	while (game->map[i][j])
		j++;
	i = 0;
	j--;
	while (i < size_of_map(game))
	{
		visited[i] = (bool *)malloc(sizeof(bool) * j);
		if (!visited[i])
			return (0);
		i++;
	}
	start_point(game);
	dfs(game, visited, game->player->x, game->player->y);
	if (game->exit_found > 0 && game->cc == game->collectable)
	{
		ft_printf("its valid biatch\n");
		return (1);
	}
	else
		ft_printf("nope, try another map\n");
	return (-1);
}

// int	valid_path(t_game *game)
// {
// 	int	i;
// 	int	j;
// 	int	count;
// 	int	collect;

// 	collect = 0;
// 	i = 1;
// 	while (game->map[i])
// 	{
// 		j = 0;
// 		while (game->map[i][j])
// 		{
// 			while (game->map[i][j] != '0' || game->map[i][j] != 'C')
// 				j++;
// 			if (game->map[i][j] == '0' || game->map[i][j] == 'C')
// 			{
// 			}
// 		}
// 		i++;
// 	}
// 	if (collect != game->collectable)
// 		return (-1);
// 	return (1);
// }

static int	check_corners(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_printf("checkfirst\n");
	while (game->map[i][j])
	{
		if (game->map[i][j] != '1')
			return (-1);
		j++;
	}
	ft_printf("check4\n");
	j--;
	while (game->map[i])
	{
		if (game->map[i][0] != '1')
			return (-1);
		if (game->map[i][j] != '1')
			return (-1);
		i++;
	}
	ft_printf("check5\n");
	j = 0;
	i--;
	while (game->map[i][j])
	{
		if (game->map[i][j] != '1')
			return (-1);
		j++;
	}
	ft_printf("check6\n");
	return (1);
}

static int	check_items(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	game->collectable = 0;
	game->exit_count = 0;
	game->start_count = 0;
	while (game->map[i])
	{
		j = 1;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->collectable++;
			if (game->map[i][j] == 'E')
				game->exit_count++;
			if (game->map[i][j] == 'P')
				game->start_count++;
			j++;
		}
		i++;
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
