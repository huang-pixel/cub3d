#include "test.h"

int is_valid_char(char c)
{
    return (ft_strchr("10 NSEW", c) != NULL);
}

int	check_valid_char(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map_tab[y])
	{
		x = 0;
		while (game->map.map_tab[y][x])
		{
			if (!is_valid_char(game->map.map_tab[y][x]))
			{
				ft_putstr_fd("Error\n Invalid character in the map\n", 2);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}