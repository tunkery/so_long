/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:19:20 by batuhan           #+#    #+#             */
/*   Updated: 2025/03/02 22:27:11 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	size_of_map(t_game *game)
{
	char	*string;
	int		fd;
	int		map_size;

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

void	initiate_variables(t_game *game)
{
	game->exit_found = 0;
	game->cc = 0;
	game->collectable = 0;
	game->exit_count = 0;
	game->start_count = 0;
	game->collectable_count = 0;
	game->player->moves = 0;
}
