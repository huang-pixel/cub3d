/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 16:00:45 by hhuang2           #+#    #+#             */
/*   Updated: 2026/10/23 20:58:31 by hhuang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_mlx_msg(t_game *game, char *msg)
{
	ft_putstr_fd(msg, 2);
	free_game(game);
	exit(EXIT_FAILURE);
}


static void	init_window(t_game *game)
{
	game->mlx_data->window = mlx_new_window(game->mlx_data->mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!game->mlx_data->window)
		init_mlx_msg(game, ERR_MLX_WIN_INIT);
}

static void	init_image(t_game *game)
{
	game->mlx_data->image = mlx_new_image(game->mlx_data->mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT);
	if (!game->mlx_data->image)
		init_mlx_msg(game, ERR_MLX_IMG_INIT);
	game->mlx_data->img_add = mlx_get_data_addr(game->mlx_data->image,
			&game->mlx_data->bits_pixel, &game->mlx_data->line_len,
			&game->mlx_data->endian);
	if (!game->mlx_data->img_add)
		init_mlx_msg(game, ERR_MLX_IMG_ADD_INIT);
}

void	init_mlx_engine(t_game *game)
{
	game->mlx_data = malloc(sizeof(*game->mlx_data));
	if (!game->mlx_data)
		init_mlx_msg(game, ERR_MLX_ALLO);
	ft_bzero(game->mlx_data, sizeof(*game->mlx_data));
	game->mlx_data->mlx_ptr = mlx_init();
	if (!game->mlx_data->mlx_ptr)
		init_mlx_msg(game, ERR_MLX_INIT);
	init_window(game);
	init_image(game);
}