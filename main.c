#include "test.h"

void    init_game(t_game *game)
{
    ft_bzero(game, sizeof(game));
    game->map.floor_color = -1;
    game->map.ceiling_color = -1;
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
    init_game(&game);
	ret = parse_file(fd, &game);
	if (!ret)
		return (1);
	printf("%s\n", game.map.no_path);
    printf("color = 0x%X\n", game.map.floor_color);
	return (0);
}