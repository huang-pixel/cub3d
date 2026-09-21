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

int parse_map(char *line)
{
    return (0);
}