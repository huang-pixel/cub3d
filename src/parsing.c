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

#include "cub3d.h"

/*
 *
 * Determines the type of line in the map file.
 * 
 */

static int	line_type(char *line)
{
	int	i;

	i = skip_spaces(line);
    delete_newline(line);
	if (line[i] == '\0' || line[i] == '\n')
		return (EMPTY_LINE);
	if (line[i] == 'N' && line[i + 1] == 'O')
		return (TEXTURE_LINE);
	if (line[i] == 'S' && line[i + 1] == 'O')
		return (TEXTURE_LINE);
	if (line[i] == 'W' && line[i + 1] == 'E')
		return (TEXTURE_LINE);
	if (line[i] == 'E' && line[i + 1] == 'A')
		return (TEXTURE_LINE);
	if (line[i] == 'F' || line[i] == 'C')
		return (COLOR_LINE);
	if (line[i] == '1' || line[i] == '0' || line[i] == 'N'
		|| line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
		return (MAP_LINE);
	return (INVALID_LINE);
}

/* 
 * 
 * Check if all required configuration elements are present. 
 * 
 */ 

 static int	check_config(t_game *game)
 {
	 	if (!game->map.map_config.no_txture ||
 		!game->map.map_config.so_txture ||
 		!game->map.map_config.we_txture ||
 		!game->map.map_config.ea_txture)
 	{
 		ft_putstr_fd(ERR_MISSING_TEXTURE, 2);
 		return (1);
 	}
 	if (game->map.map_config.floor_color == -1 || game->map.map_config.ceiling_color == -1)
 	{
 		ft_putstr_fd(ERR_MISSING_COLOR, 2);
 		return (1);
 	}
 	return (0);
 }

 /* 
 * 
 * Check if the map is valid. If the map is empty or has 0 height, 
 * print an error message and return 1, else return 0.
 * 
 */ 

 static int check_map(t_game *game)
 {
 	if (!game->map.map || game->map.map_height == 0)
 	{
 		ft_putstr_fd(ERR_INVALID_MAP_LINE, 2);
 		return (1);
 	}
 	return (0);
 }

static int proceed_line(int type, char *line, t_game *game, int *map_started)
{
	if (*map_started)
	{
		if (type != MAP_LINE)
			return (ft_putstr_fd(ERR_INVALID_MAP_LINE, 2), 1);
		if (process_map(line, game))
			return (1);
	}
	else
	{
		if (type == MAP_LINE)
		{
			*map_started = 1;
			if (process_map(line, game))
				return (1);
		}
		if (type == TEXTURE_LINE && process_texture(line, game))
			return (1);
		if (type == COLOR_LINE && process_color(line, &game->color, game))
			return (1);
	}
	return (0);
}

/*
 *
 * Parse workflow:
 * - Open file
 * - Read one line, check whether it's a map line or texture/color line
 *   - if it's a map line, we store map lines
 *   - if we encounter texture/color line, should process texture/color information
 * 
 */

int	parse_file(char *file, t_game *game)
{
	int		fd;
	int 	type;
	char	*line;
	int		map_started;

	map_started = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd(ERR_READ_MAP, 2), 1);
	while ((line = get_next_line(fd)) != NULL)
	{
		type = line_type(line);
		if (type == INVALID_LINE)
		{
			ft_putstr_fd(ERR_INVALID_MAP_LINE, 2);
			return (free(line), close(fd), 1);
		}
		if (proceed_line(type, line, game, &map_started))
			return (free(line), close(fd), 1);
		free(line);
	}
	if (check_config(game) || check_map(game))
		return (close(fd), 1);
	return (close(fd), 0);
}
