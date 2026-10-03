/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 23:07:31 by hhuang2           #+#    #+#             */
/*   Updated: 2026/09/13 23:08:12 by hhuang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
 * parse_file() - parse the entire .cub file and populate the game struct.
 * open the file, read all lines, find where the map starts,
 * parse the header (textures + colors) and then parse the map.
 * returns 0 on success, 1 on any error.
 */

int	parse_file(char *file, t_game *game)
{
	char	**map_lines;
	int		fd;
	int		map_start;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd(ERR_READ_MAP, 2), 1);
	map_lines = read_all_map_lines(fd);
	close(fd);
	if (!map_lines)
		return (ft_putstr_fd(ERR_READ_MAP, 2), 1);
	map_start = find_map_start(map_lines);
	if (map_start < 0)
		return (free_tab(map_lines), ft_putstr_fd(ERR_MAP, 2), 1);
	if (parse_header(map_lines, map_start, game))
		return (free_tab(map_lines), 1);
	if (parsing_map(map_lines + map_start, game))
		return (free_tab(map_lines), 1);
	return (0);
}
