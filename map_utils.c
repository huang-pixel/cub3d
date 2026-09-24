#include "test.h"

int is_map_line(char *line)
{
    int i;

    i = 0;
    // spaces are valid part of the map
    while (ft_isspace(line[i]))
        i++;
    // suppose line = "    \0", is invalide map line
    if (!line[i])
        return (0);
    if (line[i] == '1' || line[i] == '0')
        return (1);
    if (ft_strchr("NSEW", line[i]))
    {
        if (line[i + 1] == ' ' || line[i + 1] == '1' || line[i + 1] == '0'
            || line[i + 1] == '\0')
            return (1);    
    }
    return (0);
}

/*
 *
 * Check whether the texture path and color are setting
 * 
 */

int check_map_config(t_game *game)
{
    if (!game->map.no_path || !game->map.so_path || !game->map.we_path || !game->map.ea_path)
        return (0);
    if (game->map.floor_color == -1 || game->map.ceiling_color == -1)
        return (0);
    return (1);
}

/*
 *
 * Compute and get the max width of map list
 * 
 */

int	get_max_length(t_list *map_list)
{
	int		max;
	int		len;
	t_list	*tmp;

	tmp = map_list;
	max = 0;
	while (tmp)
	{
		len = ft_strlen((char *)tmp->content);
		if (len > max)
			max = len;
		tmp = tmp->next;
	}
	return (max);
}

void	fill_spaces(char *newline, int len, int max)
{
	while (len < max)
	{
		newline[len] = ' ';
		len++;
	}
	newline[len] = '\0';
}

char	*normalise(int max_len, char *content)
{
	int		len;
	char	*newline;

	len = ft_strlen(content);
	newline = malloc(sizeof(char) * (max_len + 1));
	if (!newline)
		return (NULL);
	ft_memcpy(newline, content, len);
	fill_spaces(newline, len, max_len);
	return (newline);
}