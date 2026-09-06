/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vino <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 04:34:01 by vino              #+#    #+#             */
/*   Updated: 2026/09/06 04:34:07 by vino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_game(t_game *game)
{
	int	i;

	i = 0;
	if (game->map.map_config.no_txture)
		free(game->map.map_config.no_txture);
	if (game->map.map_config.so_txture)
		free(game->map.map_config.so_txture);
	if (game->map.map_config.ea_txture)
		free(game->map.map_config.ea_txture);
	if (game->map.map_config.we_txture)
		free(game->map.map_config.we_txture);
	if (game->map.map)
	{
		while (game->map.map[i])
		{
			free(game->map.map[i]);
			i++;
		}
		free(game->map.map);
	}
	i = 0;
	while (i < 4)
	{
		if (game->tex[i].filepath)
			free(game->tex[i].filepath);
		i++;
	}
}
