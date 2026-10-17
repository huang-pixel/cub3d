/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 23:23:13 by hhuang2           #+#    #+#             */
/*   Updated: 2026/10/17 23:58:01 by hhuang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_up_down(t_player *p, t_game *g, float speed)
{
	float	tmp_x;
	float	tmp_y;

	if (p->move_forward)
	{
		tmp_x = p->pos.x + p->dir_x * speed;
		tmp_y = p->pos.y + p->dir_y * speed;
		if (!check_collision(tmp_x, tmp_y, g))
		{
			p->pos.x = tmp_x;
			p->pos.y = tmp_y;
		}
	}
	if (p->move_forward)
	{
		tmp_x = p->pos.x - p->dir_x *speed;
		tmp_y = p->pos.y - p->dir_y * speed;
		if (!check_collision(tmp_x, tmp_y, g))
		{
			p->pos.x = tmp_x;
			p->pos.y = tmp_y;
		}
	}
}

void	player_move(t_player *player, t_game *game)
{
	float	move_speed;

	move_speed = 0.1f;
	move_up_down(player, game, move_speed);
}