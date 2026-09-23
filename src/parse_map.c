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

// static	int	is_player(char c)
// {
// 	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
// 		return (1);
// 	return (0);
// }

/*
 * is_walkable - Check whether a map character can be walked on
 *
 * Returns: 1 if the character is a floor cell or player position,
 *          0 otherwise.
 */

static int	is_walkable(char c)
{
	if (c == '0' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

/*
 * is_inside_map - Check whether a map position exists/coordinate exists.
 *
 * position outside -> 0
 * position exists -> 1
 *  
 * Returns: 1 if the row and column are inside the stored map,
 *          0 otherwise.
 */

static int	is_inside_map(t_game *g, int row, int col)
{
	if (row < 0)
		return (0);
	if (row >= g->map.map_height)
		return (0);
	if (col < 0)
		return (0);
	if (col >= (int)ft_strlen(g->map.map_data[row]))
		return (0);
	return (1);
}

/*
 * is_safe_cell - checks if the tells us whether a neighboring cell is acceptable
 *  
 * Returns: 1 if it is an allowed coordinate,
 *          0 otherwise.
 */

static int	is_safe_cell(t_game *g, int row, int col)
{
	char	c;

	c = g->map.map_data[row][col];
	if (c == '1')
		return (1);
	if (is_walkable(c))
		return (1);
	return (0);
}

/*
 *
 * Given a walkable cell, check whether all 4 neighboring positions exists and safe
 * 
*/

static int	check_neighbors(t_game *g, int row, int col)
{
	if(!is_inside_map(g, row - 1, col))
		return (0);
	if (!is_safe_cell(g, row - 1, col))
		return (0);
	if (!is_inside_map(g, row + 1, col))
		return (0);
	if (!is_safe_cell(g, row + 1, col))
		return (0);
	if (!is_inside_map(g, row, col - 1))
		return (0);
	if (!is_safe_cell(g, row, col - 1))
		return (0);
	if (!is_inside_map(g, row, col + 1))
		return (0);
	if (!is_safe_cell(g, row, col + 1))
		return (0);
	return (1);
}

/*
 * 
 * check if only one player exists, else error 
 *  
*/

static int	check_player(t_game *g)
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	player_count = 0;
	while (i < g->map.map_height)
	{
		j = 0;
		while (g->map.map_data[i][j])
		{
			if (g->map.map_data[i][j] == 'N'
				|| g->map.map_data[i][j] == 'S'
				|| g->map.map_data[i][j] == 'E'
				|| g->map.map_data[i][j] == 'W')
				player_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1)
		return (ft_putstr_fd(ERR_PLAYER, 2), 1);
	return (0);
}

/*
 *
 * check_map_closure - checks if all the cells except the wall are valid
 *
*/

static int	check_map_closure(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->map.map_height)
	{
		j = 0;
		while (g->map.map_data[i][j])
		{
			if (is_walkable(g->map.map_data[i][j]))
			{
				if (!check_neighbors(g, i, j))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int is_valid_map(t_game *g) 
{
	int	i;

	i = 0;
	if (!check_player(g))
		return (ft_putstr_fd(ERR_PLAYER, 2), 1);
	if (!check_map_closure(g))
		return (ft_putstr_fd(ERR_MAP_CLOSE, 2), 1);
	return (0);
}

/*
 *
 * Check if the map line is valid. A valid map line can only contain the following characters:
 * - '1' for walls
 * - '0' for empty space
 * - 'N', 'S', 'E', 'W' for player starting positions
 * - ' ' (space) and '\t' (tab) for formatting
 * 
 * If any other character is found, the function returns 1 (invalid), else returns 0 (valid).
 * 
 */

static int is_valid_map_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0'
			&& line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W'
			&& line[i] != ' ' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	process_map(char *line, t_game *g)
{
	char	*map_line;
	char	**new_map_data;
	int		i;

	i = 0;
	map_line = ft_strdup(line);
	if (!map_line)
		return (ft_putstr_fd(ERR_MALLOC, 2), 1);
	new_map_data = malloc(sizeof(char *) * (g->map.map_height + 1 + 1)); // existing rows(map height) + new row + NULL
	if (!new_map_data)
		return (free(map_line), ft_putstr_fd(ERR_MALLOC, 2), 1);
	if (!is_valid_map_line(map_line))
	{
		free(map_line);
		free(new_map_data);
		return (ft_putstr_fd(ERR_MAP_LINE, 2), 1);
	}
	while ( i < g->map.map_height)
	{
		new_map_data[i] = g->map.map_data[i];
		i++;
	}
	new_map_data[i] = map_line;
	new_map_data[++i] = NULL;
	free(g->map.map_data);
	g->map.map_data = new_map_data;
	g->map.map_height = i;
	return (0);
}
