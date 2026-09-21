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

int check_map_config(t_game *game)
{
    if (!game->map.no_path || !game->map.so_path || !game->map.we_path || !game->map.ea_path)
        return (0);
    if (game->map.floor_color == -1 || game->map.ceiling_color == -1)
        return (0);
    return (1);
}

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
    return (0);
}