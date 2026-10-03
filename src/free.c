/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 04:34:01 by vino              #+#    #+#             */
/*   Updated: 2026/09/11 01:16:52 by hhuang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	free_ptr(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	free_game(t_game *game)
{
	int	i;

	i = -1;
	if (game->map.map_config.no_txture)
		free(game->map.map_config.no_txture);
	if (game->map.map_config.so_txture)
		free(game->map.map_config.so_txture);
	if (game->map.map_config.ea_txture)
		free(game->map.map_config.ea_txture);
	if (game->map.map_config.we_txture)
		free(game->map.map_config.we_txture);
	if (game->map.map_data)
	{
		while (++i < game->map.map_height)
			free(game->map.map_data[i]);
		free(game->map.map_data);
		game->map.map_data = NULL;
	}
	i = -1;
	while (++i < 4)
		free_ptr(&game->tex[i].filepath);
}

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_map(char **map_data, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map_data[i]);
		i++;
	}
	free(map_data);
}
