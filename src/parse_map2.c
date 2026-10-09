/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 05:37:30 by vino              #+#    #+#             */
/*   Updated: 2026/10/05 16:30:05 by hhuang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_player_position(t_game *game, int *count, int row, int col)
{
	(*count)++;
	game->player.pos.x = (float)col + 0.5f;
	game->player.pos.y = (float)row + 0.5f;
	game->map.map_data[row][col] = '0';
}

static void	set_player_ns_dir(t_game *g, char c)
{
	if (c == 'N')
	{
		g->player.angle = -PI / 2;
		g->player.dir_x = 0.0f;
		g->player.dir_y = -1.0f;
		g->player.plane_x = 0.66f;
		g->player.plane_y = 0.0f;
	}
	else if (c == 'S')
	{
		g->player.angle = PI / 2;
		g->player.dir_x = 0.0f;
		g->player.dir_y = 1.0f;
		g->player.plane_x = -0.66f;
		g->player.plane_y = 0.0f;
	}
}

static void	set_player_we_dir(t_game *g, char c)
{
	if (c == 'W')
	{
		g->player.angle = PI;
		g->player.dir_x = -1.0f;
		g->player.dir_y = 0.0f;
		g->player.plane_x = 0.0f;
		g->player.plane_y = -0.66f;
	}
	else if (c == 'E')
	{
		g->player.angle = 0.0f;
		g->player.dir_x = 1.0f;
		g->player.dir_y = 0.0f;
		g->player.plane_x = 0.0f;
		g->player.plane_y = 0.66f;
	}
}

/*
 * find_player - Locate the player's start tile and initialize player data.
 *
 * Scans the map to find the tile containing the player start character
 * ('N', 'S', 'E', or 'W'). When found, it:
 *   - increases the player counter,
 *   - sets the player's position to the center of that tile,
 *   - replaces that tile (the one containing N/S/E/W) with '0',
 *   - sets the player's direction and camera plane.
 *
 * Ensures exactly one player start exists.
 * Returns 1 on success, or 0 and prints an error if none or multiple are found.
 */

bool	find_player(t_game *game)
{
	int		i;
	int		j;
	int		player_count;
	char	c;

	i = -1;
	player_count = 0;
	while (++i < game->map.map_height)
	{
		j = -1;
		while (++j < game->map.map_width)
		{
			c = game->map.map_data[i][j];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				set_player_position(game, &player_count, i, j);
				set_player_ns_dir(game, c);
				set_player_we_dir(game, c);
			}
		}
	}
	if (player_count != 1)
		return (ft_putstr_fd(ERR_PLAYER, 2), false);
	return (true);
}
