#include "test.h"

int	parse_line(char *line, t_game *game)
{
	int		i;
	t_color	color;

	// remove the last \n character for each line
	delete_newline(line);
	i = 0;
	// skip the blank space
	while (ft_isspace(line[i]))
		i++;
    // suppose line is :"", "    ", "\t\t", "   \t  ", these are all valid empty lines, return OK
    if (line[i] == '\0')
        return (1);
	// check whether there's a texture line
	if (!ft_strncmp(&line[i], "NO", 2) || !ft_strncmp(&line[i], "SO", 2)
		|| !ft_strncmp(&line[i], "WE", 2) || !ft_strncmp(&line[i], "EA", 2))
		return (parse_texture(line, game));
	// whether there's a color line
	if ((line[i] == 'F' || line[i] == 'C') && ft_isspace(line[i + 1]))
		return (parse_color(line, &color, game));
	return (0);
}

int	parse_file(int fd, t_game *game)
{
	char 	*line;
	int 	ret;

	line = get_next_line(fd);
	while (line != NULL)
	{
        if (is_map_line(line))
        {
            if (check_map_config(game))
            {
				ret = parse_map(line, fd, game);
				free(line);
			}
        }
		ret = parse_line(line, game);
		free(line);
		line = get_next_line(fd);
	}
	return (ret);
}