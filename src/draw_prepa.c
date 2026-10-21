/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_prepa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 23:19:02 by hhuang2           #+#    #+#             */
/*   Updated: 2026/10/20 23:21:24 by hhuang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
 *
 * This function is calculating how far away is the wall for correct perspective
 * in dda_ray_move_check, when hit the wall, side dist has been already added once
 * subtract the last increment to recover the real distance to the wall
 * 
 */
static float	get_perp_dist(t_dda *d)
{
	if (d->side == 0)
		return (d->side_dist_x - d->delta_dist_x);
	else
		return (d->side_dist_y - d->delta_dist_y);
}

/*
 *
 * Choose the wall texture, ray direction indicates which side the ray hits
 * 
 */
static int	ray_tex_side(t_dda *d)
{
	if (d->side == 0)
	{
		if (d->ray_dir_x > 0)
			return (3);
		return (2);
	}
	else
	{
		if (d->ray_dir_y > 0)
			return (1);
		return (0);
	}
}

/*
 *
 * Based on perpendicular distance
 * this function turns that distance into wall screen position
 * 
 */
static void	compute_wall_pos(int *start, int *end, float prep_dist,
			float *height)
{
	*height = (int)(WIN_HEIGHT / prep_dist);
	*start = -(*height) / 2 + WIN_HEIGHT / 2;
	if (*start < 0)
		*start = 0;
	*end = (*height) / 2 + WIN_HEIGHT / 2;
	if (*end >= WIN_HEIGHT)
		*end = WIN_HEIGHT - 1;
}

static void	put_one_pixel(t_game *g, int x, int y, int color)
{
	
}