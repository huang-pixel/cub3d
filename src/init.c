/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 04:03:42 by vino              #+#    #+#             */
/*   Updated: 2026/10/17 22:37:23 by hhuang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_game(t_game *game)
{
	ft_bzero(game, sizeof(game));
	game->map.map_config.floor_color = -1;
	game->map.map_config.ceiling_color = -1;
}

void	init_event_hook(t_game *game)
{
	mlx_hook(game->mlx_data->window, 17, 0, quit_game, game);
	mlx_hook(game->mlx_data->window, 2, 1L << 0, key_press, game);
	mlx_hook(game->mlx_data->window, 3, 1L << 1, key_release, game);
	// mlx_hook(game->mlx_data->mlx_ptr, render_game, game);
}
