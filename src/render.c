/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 21:59:32 by hhuang2           #+#    #+#             */
/*   Updated: 2026/10/22 22:31:55 by hhuang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	render_loop(t_game *g, t_player *p, int col)
{
	t_dda	d;
	float	camera_x;

	camera_x = 2.0f * col / (float)WIN_WIDTH - 1.0f;
	init_dda(&d, p, camera_x);
	if (dda_ray_move_check(&d, g))
		render_single_wall(&d, g, col);
}

int	render_game(t_game *game)
{
    t_player	*player;
    int			i;

	player = &game->player;
	player_move(player, game);
	i = 0;
	while (i < WIN_WIDTH)
	{
		render_loop(game, player, i);
		i++;
	}
	mlx_put_image_to_window(game->mlx_data->mlx_ptr, game->mlx_data->window,
		game->mlx_data->image, 0, 0);
	return (0);
}