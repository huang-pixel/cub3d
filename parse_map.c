#include "test.h"

/*
 *
 * A read loop for reading and saving all map lines into a list
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

int	save_map_tab(t_game *game, t_list *map_list)
{
	int		i;
    t_list	*tmp;
	// Compute the map width(column) and height(row)
	game->map.height = ft_lstsize(map_list);
	game->map.width = get_max_length(map_list);

	// Given the map height, initialize an array of char *
	// Each char * is a map line
	// Generate a row + NULL-sized array of string : [NULL], [NULL], ... 
	game->map.map_tab = ft_calloc(game->map.height + 1, sizeof(char *));
	if (!game->map.map_tab)
		return (0);
	// Save each map line into each game->map.map->tab
	// Before saving, normalise a map line by padding with spaces
	i = 0;
	tmp = map_list;
	while (tmp)
	{
		game->map.map_tab[i] = normalise(game->map.width, (char *)tmp->content);
		i++;
		tmp = tmp->next;
	}
	return (1);
}

int parse_map(char *line, int fd, t_game *game)
{
    t_list  *map_head;

    delete_newline(line);
    map_head = ft_lstnew(ft_strdup(line));
    if (!map_head)
        return (0);
    if (!read_map_lines(&map_head, fd))
        return (0);
    if (!save_map_tab(game, map_head))
        return (ft_lstclear(&map_head, free), 0);
    ft_lstclear(&map_head, free);
    return (1);
}