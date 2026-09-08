/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 17:36:10 by hhuang2           #+#    #+#             */
/*   Updated: 2026/09/08 17:36:40 by hhuang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

/*
 *
 * Check whether : 1. element number, 2. open file, 3. .xpm extension
 * 
 */
int	is_valid_tex(char **tex)
{
	int	fd;
	int	len;

	if (count_size(tex) != 2)
	{
		ft_putstr_fd("Error\n Invalid texture line\n", 2);
		return (0);
	}
	fd = open(tex[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\n Cannot open texture file\n", 2);
		return (0);
	}
	len = ft_strlen(tex[1]);
	if (len < 4 || ft_strncmp(tex[1] + len - 4, ".xpm", 4))
	{
		ft_putstr_fd("Error\n Invalid texture extension\n", 2);
		return (0);
	}
	close(fd);
	return (1);
}

int	save_tex_path(char **tex, t_game *game)
{
	if (!ft_strncmp(tex[0], "NO", 3))
		game->map.no_path = ft_strdup(tex[1]);
	else if (!ft_strncmp(tex[0], "SO", 3))
		game->map.so_path = ft_strdup(tex[1]);
	else if (!ft_strncmp(tex[0], "WE", 3))
		game->map.we_path = ft_strdup(tex[1]);
	else if (!ft_strncmp(tex[0], "EA", 3))
		game->map.ea_path = ft_strdup(tex[1]);
	return (1);
}

int	parse_texture(char *line, t_game *game)
{
	char	**tex;
	int		ret;

	delete_newline(line);
	replace_spaces(line);
	tex = ft_split(line, ' ');
	if (!(is_valid_tex(tex)))
	{
		free_tab(tex);
		return (0);
	}
	ret = save_tex_path(tex, game);
	free_tab(tex);
	return (ret);
}