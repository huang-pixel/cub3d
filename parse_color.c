#include "test.h"

int is_valid_color_line(char **tab)
{
    if (count_size(tab) != 2)
    {
        ft_putstr_fd("Error\n Invalid color line\n", 2);
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
	// Value array size check
    if (!rgb || count_size(rgb) != 3)
    {
        free_tab(rgb);
        ft_putstr_fd("Error\n Color must have 1 indentifier and 3 values\n", 2);
        return (0);
    }
	// Value validation check
	i = 0;
	while (rgb[i])
	{
		if (!is_valid_value(rgb[i]))
		{
			free_tab(rgb);
			ft_putstr_fd("Error\n Invalid RGB value\n", 2);
			return (0);
		}
		i++;
	}
	// Save value data
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
		if (game->map.floor_color != -1)
			return(ft_putstr_fd("Error\n Duplication color\n", 2), 0);
		game->map.floor_color = (color->r << 16 | color->g << 8 | color->b);
	}
	else if (!ft_strncmp(color_line[0], "C", 2))
	{
		if (game->map.ceiling_color != -1)
			return(ft_putstr_fd("Error\n Duplication color\n", 2), 0);
		game->map.ceiling_color = (color->r << 16 | color->g << 8 | color->b);
	}
	else
		return (0);
	return (1);
}

int parse_color(char *line, t_color *color, t_game *game)
{
    char    **color_line;
    int     ret;

    replace_spaces(line);
    color_line = ft_split(line, ' ');
    if (!color_line)
        return (0);

    // Check the color line element
    if (!is_valid_color_line(color_line))
    {
        free_tab(color_line);
        return (0);
    }
	// Given rgb string
	// Check the validation of rgb value
	// Store R, G, B value
	if (!is_all_valid_rgb(color_line[1], color))
	{
		free_tab(color_line);
		return (0);
	}
	// Assign the validated value
	ret = set_rgb_value(color_line, color, game);
	free_tab(color_line);
    return (ret);
}