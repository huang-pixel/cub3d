/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 23:07:31 by hhuang2           #+#    #+#             */
/*   Updated: 2026/09/05 00:25:07 by hhuang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

/*
 *
 * Check whether the read line is a map line
 * 
 */

static int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	if (!line[i])
		return (0);
	if (line[i] == '1' || line[i] == '0')
		return (1);
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
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Error\n Cannot open map file\n", 2), 0);
	while ((line = get_next_line(fd)) != NULL)
	{
		if (is_map_line(line))
		{
			if (process_map(line))
			{
				free(line);
				break;
			}
		}
		
	}
}
