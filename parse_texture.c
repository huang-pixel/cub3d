/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 16:00:41 by hhuang2           #+#    #+#             */
/*   Updated: 2026/09/06 00:34:29 by hhuang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

/*
 *
 * Check validation of texture file:
 * - Check the file extension .xpm
 * - Check whether we can open the file
 * 
 */

int	check_tex_file(char *line)
{
	int	len;
    int fd;
	
	len = ft_strlen(line);
	if (len < 4 || ft_strncmp(line + len - 4, ".xpm", 4))
	{
		ft_putstr_fd("Error\n Invalid texture file extension\n", 2);
		return (0);
	}
    fd = open(line, O_RDONLY);
    if (fd < 0)
    {
        ft_putstr_fd("Error\n Cannot open texture file\n", 2);
		return (0);
    }
    close (fd);
    return (1);
}

/*
 *
 * Store the validated path 
 * 
 */

/*int	save_tex_path(char **tex, t_game *game)
{
	if (!ft_strncmp(tex[0], "NO", 3))
		game->map.no_path = 
}*/

/*
 *
 * Parse a texture line process:
 * - Split up each texture line to get the path
 * - Check whether the path is a validation texture file
 * - Copy the path to the corresponding address pointer in texture struct
 * 
 */

/*int parse_texture(char *line, t_game *game)
{
    char	**tex;
	
	tex = ft_split(line, ' ');
	if (!check_tex_file(tex[1]))
	{
		free_tab(tex);
		return (0);
	}
	
}*/