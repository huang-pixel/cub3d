/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 20:31:05 by hhuang2           #+#    #+#             */
/*   Updated: 2026/10/19 17:19:25 by hhuang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
 *
 * Calculate the ray direction and get the map start cell position
 * 
 */
static void	init_ray_point(t_dda *d, t_player *p, float camera_x)
{
	d->ray_dir_x = p->dir_x + p->plane_x * camera_x;
	d->ray_dir_y = p->dir_y + p->plane_y * camera_x;
	d->map_x = (int)p->pos.x;
	d->map_y = (int)p->pos.y;
}

/*
 *
 * Calculate how far a ray needs to go horizontally or vertically 
 * to cross into the next grid cell
 * 
 */
static void	init_delta(t_dda *d)
{
	if (d->ray_dir_x == 0.0f)
		d->delta_dist_x = 1e30;
	else
		d->delta_dist_x = fabs(1.0f / d->ray_dir_x);
	if (d->ray_dir_y == 0.0f)
		d->delta_dist_y = 1e30;
	else
		d->delta_dist_y = fabs(1.0f / d->ray_dir_y);
}

/*
 *
 * step_x and step_y: Which direction should we move through the map
 * side_dist_x and side_dist_y: How far away is the next grid line in each direction
 * 
 */
static void	init_step_side(t_dda *d, t_player *p)
{
	if (d->ray_dir_x < 0.0f)
	{
		d->step_x = -1;
		d->side_dist_x = (p->pos.x - d->map_x) * d->delta_dist_x;
	}
	else
	{
		d->step_x = 1;
		d->side_dist_x = (d->map_x + 1.0f - p->pos.x) * d->delta_dist_x;
	}
	if (d->ray_dir_y < 0.0f)
	{
		d->step_y = -1;
		d->side_dist_y =(p->pos.y - d->map_y) * d->delta_dist_y;
	}
	else
	{
		d->step_y = 1;
		d->side_dist_y = (d->map_y + 1.0f - p->pos.y) * d->delta_dist_y;
	}
}

/*
 *
 * This function repeatedly moves through the map, one grid boundary at a time, 
 * until it finds a wall or goes outside the map
 * 1. Decide which grid boundary comes first
 * 2. Update its map coordinates
 * 3. Check whether the ray has left the map
 * 
 */
int	dda_ray_move_check(t_dda *d, t_game *g)
{
	int	is_hit;
	
	is_hit = 0;
	while (!is_hit)
	{
		if (d->side_dist_x < d->side_dist_y)
		{
			d->side_dist_x += d->delta_dist_x;
			d->map_x += d->step_x;
			d->side = 0;
		}
		else
		{
			d->side_dist_y += d->delta_dist_y;
			d->map_y += d->step_y;
			d->side = 1;
		}
		if (d->map_y < 0 || d->map_y >= g->map.map_height
			|| d->map_x < 0 || d->map_x >= g->map.map_width)
			return (0);
		if (g->map.map_data[d->map_y][d->map_x] == '1')
			is_hit = 1;
	}
	return (1);
}

void	init_dda(t_dda *d, t_player *p, float camera_x)
{
    init_ray_point(d, p, camera_x);
	init_delta(d);
	init_step_side(d, p);
}