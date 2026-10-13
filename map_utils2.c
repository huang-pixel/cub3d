#include "test.h"

/*
 *
 * Make a new map tab copy before flood fill
 * 
 */

char	**dup_map(t_game *game)
{
	char	**dup;
	int		y;

	if (!game || !(game->map.height))
		return (NULL);
	dup = ft_calloc(game->map.height + 1, sizeof(char *));
	if (!dup)
		return (NULL);
	y = 0;
	while (game->map.map_tab[y])
	{
		dup[y] = ft_strdup(game->map.map_tab[y]);
		if (!dup[y])
		{
			free_tab(dup);
			return (NULL);
		}
		y++;
	}
	return (dup);
}

