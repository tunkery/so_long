/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:15:10 by batuhan           #+#    #+#             */
/*   Updated: 2025/03/03 15:18:22 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(t_game *game)
{
	char	**temp;
	int		i;
	int		fd;

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

void	dfs(t_game *game, bool **visited, int row, int col)
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

void	initiate_directions(int directions[4][2])
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
