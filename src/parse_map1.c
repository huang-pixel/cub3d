/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vino <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 02:01:30 by vino              #+#    #+#             */
/*   Updated: 2026/09/14 02:01:33 by vino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * validate_map_lines()
 *
 * Checks whether every raw map line is structurally valid before
 * building the rectangular grid.
 *
 * A map line is considered valid if:
 *   - It is not empty.
 *   - It is not made only of spaces/tabs/newlines.
 *   - Every character belongs to the allowed set:
 *         '0'  floor
 *         '1'  wall
 *         'N','S','E','W'  player start
 *         ' '  void
 *         '\t' tab
 *         '\n' newline
 *
 * Empty lines or lines containing any other character make the map invalid.
 *
 * Returns:
 *   1  if all lines are valid
 *   0  if any line is invalid (and prints the corresponding error)
 */

static bool	validate_map_lines(char **lines)
{
	int		i;
	int		j;
	int		only_spaces;
	char	c;

	i = 0;
	while (lines[i])
	{
		j = -1;
		only_spaces = 1;
		while (lines[i][++j])
		{
			c = lines[i][j];
			if (c != ' ' && c != '\t' && c != '\n')
				only_spaces = 0;
			if (c != '0' && c != '1' && c != 'N'
				&& c != 'S' && c != 'E' && c != 'W'
				&& c != ' ' && c != '\t' && c != '\n')
				return (ft_putstr_fd(ERR_MAP_LINE, 2), false);
		}
		if (only_spaces)
			return (ft_putstr_fd(ERR_MAP_EMPTY_LINE, 2), false);
		i++;
	}
	return (true);
}

static void	find_map_height_max_width(char **lines, t_game *game)
{
	int	i;
	int	max_width;

	max_width = 0;
	i = 0;
	while (lines[i])
	{
		if (((int)ft_strlen(lines[i])) > max_width)
			max_width = ft_strlen(lines[i]);
		i++;
	}
	game->map.map_height = i;
	game->map.map_width = max_width;
}

/*
 * build_rectangular_grid()
 *
 * Converts the raw map lines into a rectangular 2D grid stored in
 * game->map.map_data. Cub3D requires the map to be rectangular so that
 * neighbor checks (x+1, x-1, y+1, y-1) never go out of bounds.
 *
 * Steps performed:
 *   1. Determine map_height and map_width:
 *        - map_height = number of lines
 *        - map_width  = length of the longest line
 *
 *   2. Allocate a 2D array (map_data) with map_height rows.
 *
 *   3. For each row:
 *        - Allocate map_width + 1 characters
 *        - Copy the original line
 *        - Pad the remaining characters with ' ' (void)
 *        - Null‑terminate the row
 *
 * Why padding with spaces?
 *   - ' ' represents void/outside the map
 *   - prevents out‑of‑bounds access during closure checks
 *   - keeps the original map shape intact (padding with '0' or '1'
 *     would change the map)
 *
 * Returns:
 *   1 on success
 *   0 on allocation failure (and prints an error)
 */

static bool	build_rectangular_grid(char **lines, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	find_map_height_max_width(lines, game);
	game->map.map_data = malloc(sizeof(char *) * game->map.map_height);
	if (!game->map.map_data)
		return (ft_putstr_fd(ERR_MALLOC, 2), false);
	while (++i < game->map.map_height)
	{
		j = -1;
		game->map.map_data[i] = malloc(game->map.map_width + 1);
		if (!game->map.map_data[i])
			return (free_map(game->map.map_data, i),
				ft_putstr_fd(ERR_MALLOC, 2), false);
		while (++j < game->map.map_width)
		{
			if (lines[i][j] == '\0')
				game->map.map_data[i][j] = ' ';
			else
				game->map.map_data[i][j] = lines[i][j];
		}
		game->map.map_data[i][j] = '\0';
	}
	return (true);
}

bool	parsing_map(char **lines, t_game *game)
{
	if (!validate_map_lines(lines))
		return (false);
	if (!build_rectangular_grid(lines, game))
		return (false);
	if (!find_player(game))
		return (false);
	if (!check_map_closure(game))
		return (false);
	return (true);
}
