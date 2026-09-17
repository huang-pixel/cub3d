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
			&& line[i] != ' ' && line[i] != '\t')
			return (1);
		i++;
	}
	return (0);
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
	if (is_valid_map_line(map_line))
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
