/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolcay <bolcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:08:33 by bolcay            #+#    #+#             */
/*   Updated: 2025/03/03 01:57:36 by bolcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkleak()
{
	system("leaks so_long");
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	atexit(&checkleak);
	initiate_game(av);
	return (0);
}
