/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 22:12:12 by hhuang2           #+#    #+#             */
/*   Updated: 2026/10/22 22:23:11 by hhuang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    free_map_data(t_game *game)
{
	int	i;

    if (!game || !game->map.map_data)
        return ;
    i = 0;
    while (i < game->map.map_height)
    {
        free(game->map.map_data[i]);
        i++;
    }
    free(game->map.map_data);
    game->map.map_data = NULL;
}

void	free_mapconfig_path(t_game *game)
{
	if (!game)
        return ;
	if (game->map.map_config.no_txture)
		free(game->map.map_config.no_txture);
	if (game->map.map_config.so_txture)
		free(game->map.map_config.so_txture);
	if (game->map.map_config.ea_txture)
		free(game->map.map_config.ea_txture);
	if (game->map.map_config.we_txture)
		free(game->map.map_config.we_txture);
    game->map.map_config.no_txture = NULL;
    game->map.map_config.so_txture = NULL;
    game->map.map_config.ea_txture = NULL;
    game->map.map_config.we_txture = NULL;
}

int quit_game(t_game *game)
{
	free_game(game);
	exit(EXIT_SUCCESS);
    return (0);
}