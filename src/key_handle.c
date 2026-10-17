/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 20:49:58 by hhuang2           #+#    #+#             */
/*   Updated: 2026/10/17 22:31:29 by hhuang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_press(int key, t_game *game)
{
	if (key == KEY_ESC)
		quit_game(game);
	if (key == KEY_W)
		game->player.move_forward = 1;
	if (key == KEY_S)
		game->player.move_backward = 1;
	if (key == KEY_A)
		game->player.move_left = 1;
	if (key == KEY_D)
		game->player.move_right = 1;
	if (key == KEY_LEFT)
		game->player.rotate_left = 1;
	if (key == KEY_RIGHT)
		game->player.rotate_right = 1;
	return (1);
}

int	key_release(int key, t_game *game)
{
	if (key == KEY_W)
		game->player.move_forward = 0;
	if (key == KEY_S)
		game->player.move_backward = 0;
	if (key == KEY_A)
		game->player.move_left = 0;
	if (key == KEY_D)
		game->player.move_right = 0;
	if (key == KEY_LEFT)
		game->player.rotate_left = 0;
	if (key == KEY_RIGHT)
		game->player.rotate_right = 0;
	return (1);
}