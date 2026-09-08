#include "test.h"

int	parse_file(int fd, t_game *game)
{
	char	*line;
	int		ret;

	line = get_next_line(fd);
	while (line != NULL)
	{
		if ((!ft_strncmp(line, "NO", 2)) || (!ft_strncmp(line, "SO", 2))
			|| (!ft_strncmp(line, "WE", 2)) || (!ft_strncmp(line, "EA", 2)))
		{
			ret = parse_texture(line, game);
			free(line);
		}
		// check if there's a color line: 
		// - the first char should be 'F' or 'C'
		// - the second char should be a space
		// - parsing the color
		// if (line[1] == 'F' || line[1] == 'C')
		//{

		//}
		line = get_next_line(fd);
	}
	return (ret);
}

int	main(int ac, char **av)
{
	int		fd;
	int		ret;
	t_game	game;

	if (ac != 2)
	{
		ft_putstr_fd("Error\n Wrong argument numbers\n", 2);
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\n Cannot open map file\n", 2);
		return (1);
	}
	ft_bzero(&game, sizeof(game));
	ret = parse_file(fd, &game);
	if (!ret)
		return (1);
	printf("%s\n", game.map.no_path);
	return (0);
}