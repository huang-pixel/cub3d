#include "test.h"

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

/*
 *
 * Delete the last newline character from each line
 * 
 */
void	delete_newline(char *line)
{
	int	len;

	if (!line)
		return ;
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

/*
 *
 * Find tab or newline character in each line and replace them by ' '
 * 
 */
void	replace_spaces(char	*line)
{
	int	i;

	if (!line)
		return ;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			line[i] = ' ';
		i++;
	}
}

/*
 *
 * Count texture size, except null and empty element
 * 
 */

int	count_size(char	**tex)
{
	int	i;

	i = 0;
	while (tex[i])
		i++;
	return (i);
}

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