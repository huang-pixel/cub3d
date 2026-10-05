#include "test.h"

int save_player_pos(t_game *game, int x, int y)
{
	char	c;

	c = game->map.map_tab[y][x];
	if (ft_strchr("NSEW", c))
	{
		// Put the player in the middle of the cell, instead of the corner like (1, 1)
		game->player.pos.x = (float)x + 0.5f;
		game->player.pos.y = (float)y + 0.5f;
		set_angle(&game->player, c);
		// we don't need the spawn letter anymore, since we've already save the infos in set_angle
		game->map.map_tab[y][x] = '0';
		return (1);
	}
    return (0);
}

int is_valid_player(t_game *game)
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
			if (save_player_pos(game, x, y))
				player++;
			x++;
		}
		y++;
	}
	if (player != 1)
		return (ft_putstr_fd("Error\n Player must be one", 2), 0);
	return (1);
}