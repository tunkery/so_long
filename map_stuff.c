/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:36:57 by bolcay            #+#    #+#             */
/*   Updated: 2025/02/26 15:40:46 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_path(char **str)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	while (str[i])
	{
		j = 0;
		count = 0;
		while (str[i][j])
		{
			if (str[i][j] == '0' || str[i][j] == 'C')
				count++;
			j++;
		}
		if (count < 1 && str[i])
			return (-1);
		i++;
	}
	return (1);
}

int	check_corners(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i][j])
	{
		if (str[i][j] != '1')
			return (-1);
		j++;
	}
	j--;
	while (str[i])
	{
		if (str[i][0] != '1')
			return (-1);
		if (str[i][j] != '1')
			return (-1);
		i++;
	}
	j = 0;
	i--;
	while (str[i][j])
	{
		if (str[i][j] != '1')
			return (-1);
		j++;
	}
	return (1);
}

int	check_items(char **str)
{
	int	i;
	int	j;
	int collectable_count;
	int exit_count;
	int	start_count;

	i = 1;
	collectable_count = 0;
	exit_count = 0;
	start_count = 0;
	while (str[i])
	{
		j = 1;
		while (str[i][j])
		{
			if (str[i][j] == 'C')
				collectable_count++;
			if (str[i][j] == 'E')
				exit_count++;
			if (str[i][j] == 'P')
				start_count++;
			j++;
		}
		i++;
	}
	if (collectable_count < 1 || exit_count != 1 || start_count != 1)
		return (-1);
	return (1);
}

int	check_shape(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i][j])
		j++;
	while (str[i])
		i++;
	if (i == j)
		return (-1);
	return (1);
}
