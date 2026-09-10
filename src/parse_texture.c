/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 00:14:53 by hhuang2           #+#    #+#             */
/*   Updated: 2026/09/11 01:15:32 by hhuang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
 *
 * Check whether texture is valid : 
 * 1. element number, 2. open file, 3. .xpm extension
 * 
 */
int	is_valid_tex(char **tex)
{
	int	fd;
	int	len;

	if (count_size(tex) != 2)
	{
		ft_putstr_fd(ERR_TEXTURE_LINE, 2);
		return (0);
	}
	fd = open(tex[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd(ERR_TEXTURE_READ, 2);
		return (0);
	}
	len = ft_strlen(tex[1]);
	if (len < 4 || ft_strncmp(tex[1] + len - 4, ".xpm", 4))
	{
		ft_putstr_fd(ERR_TEXTURE_EXT, 2);
		return (0);
	}
	close(fd);
	return (1);
}

/*
 *
 * Save each texture valid path and check the duplication
 * If a path is already exists, print duplication error msg
 * Otherwise, store it
 * If ft_strncmp fails, return 0
 * 
 */
int	save_tex_path(char **tex, t_game *game)
{
	if (!ft_strncmp(tex[0], "NO", 3))
	{
        if (game->map.no_path != NULL)
            return (ft_putstr_fd(ERR_DUP_TEXTURE, 2), 0);
        game->map.no_path = ft_strdup(tex[1]);
    }
	else if (!ft_strncmp(tex[0], "SO", 3))
	{
        if (game->map.so_path != NULL)
            return (ft_putstr_fd(ERR_DUP_TEXTURE, 2), 0);
        game->map.so_path = ft_strdup(tex[1]);
    }
	else if (!ft_strncmp(tex[0], "WE", 3))
	{
        if (game->map.we_path != NULL)
            return (ft_putstr_fd(ERR_DUP_TEXTURE, 2), 0);
        game->map.we_path = ft_strdup(tex[1]);
    }
	else if (!ft_strncmp(tex[0], "EA", 3))
	{
        if (game->map.ea_path != NULL)
            return (ft_putstr_fd(ERR_DUP_TEXTURE, 2), 0);
        game->map.ea_path = ft_strdup(tex[1]);
    }
    else
        return (0);
    return (1);
}

/*
 * 
 * Texture parsing process:
 * - Remove the last newline charater in the end (can do it early for each line)
 * - Replace any spaces by ' ', since ' ' is delimiter to split
 * - Split a texture line and get the tex array
 *   - if split fails, return 0
 * - Check whether the texture is valid given its array
 * - Store the line
 * 
 */
int	process_texture(char *line, t_game *game)
{
	char	**tex;
	int		ret;

	delete_newline(line);
	replace_spaces(line);
	tex = ft_split(line, ' ');
    if (!tex)
        return (0);
    /*if (!tex[0])
    {
        free_tab(tex);
        return (1);
    }*/
	if (!(is_valid_tex(tex)))
	{
		free_tab(tex);
		return (0);
	}
	ret = save_tex_path(tex, game);
	free_tab(tex);
	return (ret);
}