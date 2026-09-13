/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 21:52:43 by hhuang2           #+#    #+#             */
/*   Updated: 2026/09/13 23:06:22 by hhuang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int is_valid_color_line(char **tab)
{
    if (count_size(tab) != 2)
    {
        ft_putstr_fd(ERR_COL_LINE, 2);
        return (0);
    }
    return (1);
}

/*
 *
 * Check the validation of rgb value: 
 * 1. each char must be a digit 
 * 2. convert the value by atoi, it should between 0 from 255
 * 
 */

int	is_valid_value(char *value)
{
	int	i;
	int	num;

	i = 0;
	while (value[i])
	{
		if (!ft_isdigit(value[i]))
			return (0);
		i++;
	}
	num = ft_atoi(value);
	if (num < 0 || num > 255)
		return (0);
	return (1);
}

int is_all_valid_rgb(char *color_str, t_color *color)
{
    char    **rgb;
	int		i;

    rgb = ft_split(color_str, ',');
    if (!rgb || count_size(rgb) != 3)
        return (free_tab(rgb), ft_putstr_fd(ERR_COL_FORMAT, 2), 0);
    i = -1;
    while (rgb[++i])
    {
        if (!is_valid_value(rgb[i]))
            return (free_tab(rgb), ft_putstr_fd(ERR_COL_VAL, 2), 0); 
    }
	color->r = ft_atoi(rgb[0]);
	color->g = ft_atoi(rgb[1]);
	color->b = ft_atoi(rgb[2]);
	free_tab(rgb);
	return (1);
}

int	set_rgb_value(char **color_line, t_color *color, t_game *game)
{
	if (!ft_strncmp(color_line[0], "F", 2))
    {
        if (game->map.map_config.floor_color != -1)
			return(ft_putstr_fd(ERR_COL_DUP, 2), 0);
		game->map.map_config.ceiling_color = (color->r << 16 | color->g << 8 | color->b);
    }
    else if (!ft_strncmp(color_line[0], "C", 2))
    {
        if (game->map.map_config.ceiling_color != -1)
			return(ft_putstr_fd(ERR_COL_DUP, 2), 0);
		game->map.map_config.ceiling_color = (color->r << 16 | color->g << 8 | color->b);
    }
	else
		return (0);
	return (1);
}

int process_color(char *line, t_color *color, t_game *game)
{
    char    **color_line;
    int     ret;

    replace_spaces(line);
    color_line = ft_split(line, ' ');
    if (!color_line)
        return (0);
    if (!is_valid_color_line(color_line))
        return (free_tab(color_line), 0);
	if (!is_all_valid_rgb(color_line[1], color))
        return (free_tab(color_line), 0);
	ret = set_rgb_value(color_line, color, game);
	free_tab(color_line);
    return (ret);
}