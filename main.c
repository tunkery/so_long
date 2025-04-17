/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:08:33 by bolcay            #+#    #+#             */
/*   Updated: 2025/03/06 20:07:50 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkleak(void)
{
	system("leaks so_long");
}

int	main(int ac, char **av)
{
	char	*check;

	if (ac != 2)
	{
		ft_printf("Invalid argument\n");
		return (0);
	}
	check = ft_strrchr(av[1], '.');
	if (!check || ft_strncmp(check, ".ber", ft_strlen(check)) != 0)
	{
		ft_printf("Please enter a .ber file\n");
		return (0);
	}
	atexit(&checkleak);
	initiate_game(av);
	return (0);
}
