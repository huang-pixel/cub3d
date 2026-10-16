/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 22:12:12 by hhuang2           #+#    #+#             */
/*   Updated: 2026/10/16 22:14:18 by hhuang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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