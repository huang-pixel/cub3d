/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 04:34:01 by vino              #+#    #+#             */
/*   Updated: 2026/10/16 23:39:48 by hhuang2          ###   ########.fr       */
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

void	free_textures(t_game *game)
{
	int	i;

    free_mapconfig_path(game);
    if (!game->mlx_data || !game->mlx_data->mlx_ptr)
		return ;
	i = -1;
	while (++i < 4)
	{
		if (game->tex[i].img_ptr)
		{
			mlx_destroy_image(game->mlx_data->mlx_ptr, game->tex[i].img_ptr);
			game->tex[i].img_ptr = NULL;
            game->tex[i].img_add = NULL;
		}
	}
}

void	free_mlx_data(t_game *game)
{
    t_mlx_data  *mlx;
    
    if (!game || !game->mlx_data)
        return ;
    mlx = game->mlx_data;
	if (mlx->mlx_ptr)
	{
		if (mlx->image)
			mlx_destroy_image(mlx->mlx_ptr, mlx->image);
		if (mlx->window)
			mlx_destroy_window(mlx->mlx_ptr, mlx->window);
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
    free(mlx);
    game->mlx_data = NULL;
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
    free_map_data(game);
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

void   free_map(char **map_data, int height)
{
	int	i;
	
	i = 0;
	while (i < height)
	{
		free(map_data[i]);
		i++;
	}
	free(map_data);
}