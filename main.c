/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:08:33 by bolcay            #+#    #+#             */
/*   Updated: 2025/03/02 16:38:48 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void	init_map(char **hey);

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	initiate_game(av);
	// mlx_terminate(mlx);
	return (0);
}

// int	main()
// {
	// void	*mlx_ptr;
	// char	*title;
	// char *hey[] = {
	// "1111111111111111111111111111111111",
	// "1E0000000000000C00000C000000000001",
	// "1010010100100000101001000000010101",
	// "1010010010101010001001000000010101",
	// "1P0000000C00C0000000000000000000C1",
	// "1111111111111111111111111111111111",
	// NULL
	// };

	// if (check_corners(hey) == -1)
	// 	ft_printf("map is not valid\n");
	// else
	// 	ft_printf("map is valid\n");
	// if (check_items(hey) == -1)
	// 	ft_printf("map is not valid\n");
	// else
	// 	ft_printf("map is valid\n");
	// if (check_shape(hey) == -1)
	// 	ft_printf("map is not valid\n");
	// else
	// 	ft_printf("map is valid\n");
	// if (hey[1][0] > 99)
	// 	return ;
	// title = "Bhen";
	// if (ac < 0)
	// 	return (0);
	// mlx_ptr = mlx_init(WIDTH, HEIGHT, title, true);
	// if (!mlx_ptr)
	// 	return (0);
	// init_map(hey);
	// mlx_loop(mlx_ptr);
	// free(mlx_ptr);
// 	return (0);
// }

// static void	init_map(char **hey)
// {
// 	t_game *yo;
// 	int		i;
// 	int		j;

// 	yo = malloc(sizeof(t_game));
// 	if (!yo)
// 		return ;
// 	j = 0;
// 	while (hey[j])
// 		j++;
// 	i = 0;
// 	yo->map = malloc(sizeof(char *) * (j + 1));
// 	if (!yo->map)
// 		return ;
// 	while (i < j)
// 	{
// 		yo->map[i] = malloc(sizeof(char) * (ft_strlen(hey[i]) + 1));
// 		if (!yo->map[i])
// 			return ;
// 		i++;
// 	}
// 	i = 0;
// 	while (hey[i])
// 	{
// 		j = 0;
// 		while (hey[i][j])
// 		{
// 			yo->map[i][j] = hey[i][j];
// 			j++;
// 		}
// 		i++;
// 	}
// 	yo->map[i] = NULL;
// 	// i = 0;
// 	// while (hey[i])
// 	// {
// 	// 	j = 0;
// 	// 	while (hey[i][j])
// 	// 	{
// 	// 		ft_printf("%c", yo->map[i][j]);
// 	// 		j++;
// 	// 	}
// 	// 	ft_printf("\n");
// 	// 	i++;
// 	// }
// }
