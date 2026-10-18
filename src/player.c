/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 23:23:13 by hhuang2           #+#    #+#             */
/*   Updated: 2026/10/18 18:04:28 by hhuang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
 *
 * Player movement includes:
 * move forward, backward
 * move left and right sideway
 * rotation
 * 
*/

/*
*
* Player position update:
* Calculate where the player would go
* Check whether that position is blocked
* Update the real position only if the position is safe
* 
*/
static void	move_leftside(t_player *p, t_game *g, float speed)
{
	float	prep_x;
	float	prep_y;
	float	tmp_x;
	float	tmp_y;

	prep_x = -p->dir_y;
	prep_y = p->dir_x;
	tmp_x = p->pos.x - prep_x * speed;
	tmp_y = p->pos.y - prep_y * speed;
	if (!check_collision(tmp_x, tmp_y, g))
	{
		p->pos.x = tmp_x;
		p->pos.y = tmp_y;
	}
}

static void	move_rightside(t_player *p, t_game *g, float speed)
{
	float	prep_x;
	float	prep_y;
	float	tmp_x;
	float	tmp_y;

	prep_x = -p->dir_y;
	prep_y = p->dir_x;
	tmp_x = p->pos.x + prep_x * speed;
	tmp_y = p->pos.y + prep_y * speed;
	if (!check_collision(tmp_x, tmp_y, g))
	{
		p->pos.x = tmp_x;
		p->pos.y = tmp_y;
	}
}

static void	move_up_down(t_player *p, t_game *g, float speed)
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

/*
 *
 * Player rotation update using rotation matrix formula
 * 
 */

static void	player_rotate(t_game *game, double rot)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(rot)
		- game->player.dir_y * sin(rot);
	game->player.dir_y = old_dir_x * sin(rot)
		+ game->player.dir_y * cos(rot);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(rot)
		- game->player.plane_y * sin(rot);
	game->player.plane_y = old_plane_x * sin(rot)
		+ game->player.plane_x * cos(rot);
}

void	player_move(t_player *player, t_game *game)
{
	float	move_speed;
	double	rot_speed;
	
	move_speed = 0.1f;
	rot_speed = 0.05;
	move_up_down(player, game, move_speed);
	if (player->move_left)
		move_leftside(player, game, move_speed);
	if (player->move_right)
		move_rightside(player, game, move_speed);
	if (player->rotate_left)
		player_rotate(game, -rot_speed);
	if (player->rotate_right)
		player_rotate(game, rot_speed);
}