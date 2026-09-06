/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 23:07:31 by hhuang2           #+#    #+#             */
/*   Updated: 2026/09/06 00:33:22 by hhuang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

/*
 *
 * Parse workflow:
 * - Open file
 * - Read one line, check whether it's a map line or texture/color line
 *   - if it's a map line, we store map lines
 *   - if we encounter texture/color line, should process texture/color information
 * 
 */

/*int	parse_file(char *file, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Error\n Cannot open map file\n", 2), 0);
	while ((line = get_next_line(fd)) != NULL)
    {
        if 
    }
}*/
