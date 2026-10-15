/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 04:34:01 by vino              #+#    #+#             */
/*   Updated: 2026/10/16 00:23:05 by hhuang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*static void	free_ptr(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}*/

void    free_map(t_game *game)
{
	int	i;

    if (!game->map.map_data)
        return ;
    i = 0;
    while (game->map.map_data[i])
    {
        free(game->map.map_data[i]);
        i++;
    }
    free(game->map.map_data);
    game->map.map_data = NULL;
}

void	free_textures(t_game *game)
{
	int	i;

	if (game->map.map_config.no_txture)
		free(game->map.map_config.no_txture);
	if (game->map.map_config.so_txture)
		free(game->map.map_config.so_txture);
	if (game->map.map_config.ea_txture)
		free(game->map.map_config.ea_txture);
	if (game->map.map_config.we_txture)
		free(game->map.map_config.we_txture);
	if (!game->mlx_data)
		return ;
	i = 0;
	while (i < 4)
	{
		if (game->tex[i].img_ptr)
		{
			mlx_destroy_image(game->mlx_data->mlx_ptr, game->tex[i].img_ptr);
			game->tex[i].img_ptr = NULL;
		}
		i++;
	}
}

void	free_mlx_data(t_game *game)
{
	if (game->mlx_data)
	{
		if (game->mlx_data->image)
			mlx_destroy_image(game->mlx_data->mlx_ptr, game->mlx_data->image);
		if (game->mlx_data->window)
			mlx_destroy_window(game->mlx_data->mlx_ptr, game->mlx_data->window);
		if (game->mlx_data->mlx_ptr)
		{
			mlx_destroy_display(game->mlx_data->mlx_ptr);
			free(game->mlx_data->mlx_ptr);
		}
		free(game->mlx_data);
		game->mlx_data = NULL;
	}
}

void	free_game(t_game *game)
{
	int	i;

	if (!game)
		return ;
    free_map(game);
	free_textures(game);
	free_mlx_data(game);
}

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

