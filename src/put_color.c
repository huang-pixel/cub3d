/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 19:06:42 by hhuang2           #+#    #+#             */
/*   Updated: 2026/10/22 00:23:27 by hhuang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
 *
 * Find the pixel's location using x, y, line, and bpp
 * Write the color there by splitting the integer into individual bytes
 * 
 */
void	put_one_pixel(t_game *g, int x, int y, int color)
{
	int	byte_pos;
	
	if (y < 0 || x < 0 || y >= WIN_HEIGHT || x >= WIN_WIDTH)
		return ;
	byte_pos = y * g->mlx_data->line_len +
			x * (g->mlx_data->bits_pixel / 8);
	g->mlx_data->img_add[byte_pos] = color & 0xFF;
	g->mlx_data->img_add[byte_pos + 1] = (color >> 8) & 0xFF;
	g->mlx_data->img_add[byte_pos + 2] = (color >> 16) & 0xFF;
	g->mlx_data->img_add[byte_pos + 3] = (color >> 24) & 0xFF;
}

/*
 *
 * Give the wall start and end boundary, draw ceilling and floor color for a single column
 * 
 */
void	fill_c_f(t_game *g, int col, int start_y, int end_y)
{
	int	y;
	
	y = 0;
	while (y < start_y)
	{
		put_one_pixel(g, col, y, g->map.map_config.ceiling_color);
		y++;
	}
	y = end_y;
	while (y < WIN_HEIGHT)
	{
		put_one_pixel(g, col, y, g->map.map_config.floor_color);
		y++;
	}
}