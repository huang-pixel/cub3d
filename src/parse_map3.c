/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vino <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 05:40:54 by vino              #+#    #+#             */
/*   Updated: 2026/10/03 05:40:55 by vino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
 * is_walkable - Check whether a map character can be walked on
 *
 * Returns: 1 if the character is a floor cell or player position,
 *          0 otherwise.
 */

static bool	is_walkable(char c)
{
	return (c == '0' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W');
}

static bool	is_inside_map(t_game *g, int row, int col)
{
	return (row >= 0 && row < g->map.map_height
		&& col >= 0 && col < g->map.map_width);
}

/*
 * is_safe_cell - tells us whether a neighboring cell is acceptable
 * 
 * walls and walkable cells are safe
 * 
 * Returns: 1 if it is an allowed coordinate,
 *          0 otherwise.
 */

static int	is_safe_cell(t_game *g, int row, int col)
{
	char	c;

	c = g->map.map_data[row][col];
	if (c == ' ')
		return (0);
	if (c == '1' || is_walkable(c))
		return (1);
	return (0);
}

/*
 * check_neighbors - Validate that a walkable cell is fully enclosed.
 *
 * Given a walkable map cell at (row, col), this function checks its
 * four direct neighbors: up, down, left, and right.
 *
 * For each neighbor, two conditions must be satisfied:
 *   1) The neighbor coordinate must be inside the map boundaries.
 *   2) The neighbor cell must be "safe" — meaning it is either a wall
 *      ('1') or another walkable cell ('0', 'N', 'S', 'E', 'W').
 *
 * A walkable cell touching a space (' ') or going out of bounds means
 * the map is not properly closed, so the function returns 0.
 *
 * Returns:
 *   1 if all four neighbors exist and are safe,
 *   0 otherwise.
 */

static bool	check_neighbors(t_game *g, int row, int col)
{
	if (!is_inside_map(g, row - 1, col))
		return (false);
	if (!is_safe_cell(g, row - 1, col))
		return (false);
	if (!is_inside_map(g, row + 1, col))
		return (false);
	if (!is_safe_cell(g, row + 1, col))
		return (false);
	if (!is_inside_map(g, row, col - 1))
		return (false);
	if (!is_safe_cell(g, row, col - 1))
		return (false);
	if (!is_inside_map(g, row, col + 1))
		return (false);
	if (!is_safe_cell(g, row, col + 1))
		return (false);
	return (true);
}

/*
 * check_map_closure - Ensure all walkable tiles are properly enclosed.
 *
 * Iterates through the entire map and checks every walkable tile
 * ('0', 'N', 'S', 'E', 'W'). For each such tile, it verifies that its
 * four direct neighbors (up, down, left, right) exist inside the map
 * and are safe (not a space and not outside the map).
 *
 * If any walkable tile touches a space or goes out of bounds,
 * the map is considered open and the function returns 0 after
 * printing an error message.
 *
 * Returns 1 if the map is fully closed, otherwise 0.
 */

bool	check_map_closure(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->map.map_height)
	{
		j = 0;
		while (j < g->map.map_width)
		{
			if (is_walkable(g->map.map_data[i][j]))
			{
				if (!check_neighbors(g, i, j))
					return (ft_putstr_fd(ERR_MAP_CLOSE, 2), false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
