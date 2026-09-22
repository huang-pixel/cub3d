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
		len = ft_strlen(tmp->content);
		if (len > max)
			max = len;
		tmp = tmp->next;
	}
	return (max);
}

int	save_map_tab(t_game *game, t_list *map_list)
{
	// Compute the map width(column) and height(row)
	game->map.height = ft_lstsize(map_list);
	game->map.weight = get_max_length(map_list);

	// Given the map height, initialize an array of char *
	// Each char * is a map line
	// Generate a row + NULL-sized array of string : [NULL], [NULL], ... 
	// 
	game->map.map_tab = ft_calloc(game->map.height + 1, sizeof(char *));
	if (!game->map.map_tab)
		return (0);
	// Generate a row-sized array of integer : line[0] = int, line[1] = int, ...
	//game->map.line = malloc(game->map.height * sizeof(int));
	//if (!game->map.line)
	//{
	//	free(game->map.map_tab); // map_tab is an array of NULL pointer, just free this array pointer
	//	game->map.map_tab = NULL;
	//	return (0);
	//}
	return (1);
}

int convert_to_tab(t_list *map_list, t_game *game)
{
	return (1);
}

/*
 *
 * A read loop for reading and saving the map lines into a list
 * 
 */
int read_map_lines(t_list **map_lst, int fd)
{
    char    *content;
    t_list  *newnode;
    
    while (1)
    {
        content = get_next_line(fd);
        if (!content)
            break ;
        delete_newline(content);
        newnode = ft_lstnew(ft_strdup(content));
        if (!newnode)
            return (free(content), ft_lstclear(map_lst, free), 0);
        ft_lstadd_back(map_lst, newnode);
    }
    return (1);
}

int parse_map(char *line)
{
    return (1);
}