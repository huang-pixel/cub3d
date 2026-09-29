#include "test.h"


int valid_player(t_game *game)
{
    int	x;
	int	y;
	int	player;

	y = 0;
	player = 0;
	while (y < game->map.height && game->map.map_tab[y])
	{
		x = 0;
		while (game->map.map_tab[y][x])
		{
			// set_player;
			 // player++;
			// x++;
		}
		y++;
	}
	if (player != 1)
		return (ft_putstr_fd("Error\n Player must be one", 2), 0);
	return (1);
}