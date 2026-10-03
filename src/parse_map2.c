/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vino <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 05:37:30 by vino              #+#    #+#             */
/*   Updated: 2026/10/03 05:37:32 by vino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_player_position(t_game *game, int *count, int row, int col)
{
	(*count)++;
	game->player.pos.x = col + 0.5;
	game->player.pos.y = row + 0.5;
	game->map.map_data[row][col] = '0';
}

static void	set_player_ns_dir(t_game *g, char c)
{
	if (c == 'N')
	{
		g->player.dir_x = 0;
		g->player.dir_y = -1;
		g->player.plane_x = 0.66;
		g->player.plane_y = 0;
	}
	else if (c == 'S')
	{
		g->player.dir_x = 0;
		g->player.dir_y = 1;
		g->player.plane_x = -0.66;
		g->player.plane_y = 0;
	}
}

static void	set_player_we_dir(t_game *g, char c)
{
	if (c == 'W')
	{
		g->player.dir_x = -1;
		g->player.dir_y = 0;
		g->player.plane_x = 0;
		g->player.plane_y = -0.66;
	}
	else if (c == 'E')
	{
		g->player.dir_x = 1;
		g->player.dir_y = 0;
		g->player.plane_x = 0;
		g->player.plane_y = 0.66;
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

int	find_player(t_game *game)
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
		return (ft_putstr_fd(ERR_PLAYER, 2), 0);
	return (1);
}
