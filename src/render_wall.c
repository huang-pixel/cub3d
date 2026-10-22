/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 20:27:08 by hhuang2           #+#    #+#             */
/*   Updated: 2026/10/22 20:34:26 by hhuang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
 * This file prepares and calculates some fields for rendering textures
 */

/*
 *
 * Choose the wall texture, ray direction indicates which side the ray hits
 * 
 */

int	ray_tex_side(t_dda *d)
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
 * Compute the exact point where the ray hits the wall
 * Find where that point lies along the wall
 * Choose the correct column from the texture
 * 
 */

int	get_hit_tex(t_dda *d, t_texture *tex, t_game *g,
			float prep_dist)
{
	float	hit_pos;
	int		tex_col;

	if (d->side == 0)
		hit_pos = g->player.pos.y + prep_dist * d->ray_dir_y;
	else
		hit_pos = g->player.pos.x + prep_dist *d ->ray_dir_x;
	hit_pos -= floor(hit_pos);
	tex_col = (int)(hit_pos * tex->width);
	if ((d->side == 0 && d->ray_dir_x > 0)
		|| (d->side == 1 && d->ray_dir_y < 0))
		tex_col = tex->width - tex_col - 1;
	return (tex_col);
}

void	draw_wall_col(t_game *g, t_texture *tex, t_wall *w, int col)
{
	int		color;
	int		tex_row;
	int		y;
	float	tex_pos;
	float	move_step;
	
	move_step = (float)tex->height / w->height;
	tex_pos = (w->start - WIN_HEIGHT / 2 + w->height / 2) * move_step;
	if (tex_pos < 0)
		tex_pos = 0;
	y = w->start;
	while (y < w->end)
	{
		tex_row = (int)tex_pos;
		if (tex_row >= tex->height)
			tex_row = tex->height - 1;
		color = *(int *)(tex->img_add + (tex_row * tex->len)
				+ (w->tex_col * (tex->bpp / 8)));
		put_one_pixel(g, col, y, color);
		tex_pos += move_step;
		y++;
	}
}

void	render_single_wall(t_dda *d, t_game *g, int col)
{
	float		prep_dist;
	t_wall		w;
	t_texture	*tex;

	prep_dist = get_perp_dist(d);
	if (prep_dist <= 0)
		prep_dist = 0.1f;
	tex = &g->tex[ray_tex_side(d)];
	compute_wall_pos(&w.start, &w.end, prep_dist, &w.height);
	fill_c_f(g, col, w.start, w.end);
	w.tex_col = get_hit_tex(d, tex, g, prep_dist);
	draw_wall_col(g, tex, &w, col);
}