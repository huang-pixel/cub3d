/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 04:03:42 by vino              #+#    #+#             */
/*   Updated: 2026/10/13 23:31:37 by hhuang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_game *game)
{
	ft_bzero(game, sizeof(game));
	game->map.map_config.floor_color = -1;
	game->map.map_config.ceiling_color = -1;
}

t_mlx_data	*init_mlx_data(void)
{
	t_mlx_data	*mlx_data;

	mlx_data = malloc(sizeof(t_mlx_data));
	if (!mlx_data)
		return (NULL);
	mlx_data->mlx_ptr = mlx_init();
	if (!mlx_data->mlx_ptr)
		return (free(mlx_data), NULL);
	mlx_data->window = NULL;
	mlx_data->image = NULL;
	mlx_data->img_add = NULL;
	mlx_data->bits_pixel = 0;
	mlx_data->line_len = 0;
	mlx_data->endian = 0;
	return (mlx_data);
}
