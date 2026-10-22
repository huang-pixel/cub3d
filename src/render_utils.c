/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 22:06:09 by hhuang2           #+#    #+#             */
/*   Updated: 2026/10/22 21:59:55 by hhuang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
 *
 * This function calculates how far away is the wall for correct perspective
 * in dda_ray_move_check, when hit the wall, side dist has been already added once
 * subtract the last increment to recover the real distance to the wall
 * 
 */
float	get_perp_dist(t_dda *d)
{
	if (d->side == 0)
		return (d->side_dist_x - d->delta_dist_x);
	else
		return (d->side_dist_y - d->delta_dist_y);
}


/*
 *
 * Based on perpendicular distance
 * This function turns that distance into wall screen position
 * start: where the wall begins vertically
 * end: where the wall ends vertically
 * 
 */
void	compute_wall_pos(int *start, int *end, float prep_dist,
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