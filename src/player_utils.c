/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 23:47:22 by hhuang2           #+#    #+#             */
/*   Updated: 2026/10/17 23:53:13 by hhuang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_collision(float x, float y, t_game *g)
{
	int	px;
	int	py;

	px = (int)x;
	py = (int)y;
	if (py < 0 || px < 0 || py >= g->map.map_height || px >= g->map.map_width)
		return (1);
	if (g->map.map_data[py][px] == '1')
		return (1);
	return (0);
}