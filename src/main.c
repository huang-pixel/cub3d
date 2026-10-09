/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:47:53 by hhuang2           #+#    #+#             */
/*   Updated: 2026/09/01 22:22:22 by hhuang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
 *
 * Argument format validation:
 * Check whether there are 2 arguments, ./cub3D and .cub file
 * Check .cub extension
 * If true return 1, otherwise 0
 *
 */

static bool	check_args(int ac, char **av)
{
	int	len;

	if (ac != 2)
	{
		ft_putstr_fd(ERR_ARG, 2);
		return (false);
	}
	len = ft_strlen(av[1]);
	if (len < 4 || ft_strncmp(av[1] + len - 4, ".cub", 4))
	{
		ft_putstr_fd(ERR_EXT, 2);
		return (false);
	}
	return (true);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (!check_args(ac, av))
		return (EXIT_FAILURE);
	init_game(&game);
	if (!parse_file(av[1], &game))
		return (free_game(&game), EXIT_FAILURE);
	printf("all ok!");
	// if (start_game(&game))
	// 	return (free_game(&game), EXIT_FAILURE);
	// free_game(&game);
	return (EXIT_SUCCESS);
}
