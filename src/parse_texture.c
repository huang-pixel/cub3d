/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 00:14:53 by hhuang2           #+#    #+#             */
/*   Updated: 2026/09/29 23:44:38 by hhuang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
 *
 * Check whether texture is valid : 
 * 1. element number, 2. open file, 3. .xpm extension
 * 
 */
bool	is_valid_tex(char **tex)
{
	int	fd;
	int	len;

	if (count_size(tex) != 2)
	{
		ft_putstr_fd(ERR_TEXTURE_LINE, 2);
		return (false);
	}
	fd = open(tex[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd(ERR_TEXTURE_READ, 2);
		return (false);
	}
	len = ft_strlen(tex[1]);
	if (len < 4 || ft_strncmp(tex[1] + len - 4, ".xpm", 4))
	{
		close(fd);
		ft_putstr_fd(ERR_TEXTURE_EXT, 2);
		return (false);
	}
	close(fd);
	return (true);
}

static bool	set_tex(char **txt_dst, char *txt_src)
{
	if (*txt_dst != NULL)
		return (ft_putstr_fd(ERR_DUP_TEXTURE, 2), false);
	*txt_dst = ft_strdup(txt_src);
	if (!*txt_dst)
		return (ft_putstr_fd(ERR_MALLOC, 2), false);
	return (true);
}

/*
 *
 * Save each texture valid path and check the duplication
 * If a path is already exists, print duplication error msg
 * Otherwise, store it
 * If ft_strncmp fails, return 0
 * 
 */
bool	save_tex_path(char **tex, t_game *game)
{
	if (!ft_strncmp(tex[0], "NO", 2))
		return (set_tex(&game->map.map_config.no_txture, tex[1]));
	else if (!ft_strncmp(tex[0], "SO", 2))
		return (set_tex(&game->map.map_config.so_txture, tex[1]));
	else if (!ft_strncmp(tex[0], "WE", 2))
		return (set_tex(&game->map.map_config.we_txture, tex[1]));
	else if (!ft_strncmp(tex[0], "EA", 2))
		return (set_tex(&game->map.map_config.ea_txture, tex[1]));
	ft_putstr_fd(ERR_TEXTURE_LINE, 2);
	return (true);
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
bool	process_texture(char *line, t_game *game)
{
	char	**tex;
	int		ret;

	delete_newline(line);
	replace_spaces(line);
	tex = ft_split(line, ' ');
	if (!tex)
		return (false);
	if (!(is_valid_tex(tex)))
	{
		free_tab(tex);
		return (false);
	}
	ret = save_tex_path(tex, game);
	free_tab(tex);
	return (ret);
}
