/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 21:21:05 by hhuang2           #+#    #+#             */
/*   Updated: 2026/10/18 23:44:37 by hhuang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_tex_msg(t_game *game, char *msg)
{
	ft_putstr_fd(msg, 2);
	free_game(game);
	exit(EXIT_FAILURE);
}

int	load_xpm(t_game *game, t_texture *tex, char *path)
{
	if (!path)
		return (0);
	tex->img_ptr = mlx_xpm_file_to_image(game->mlx_data->mlx_ptr, path,
			&tex->width, &tex->height);
	if (!tex->img_ptr)
		return (0);
	tex->img_add = mlx_get_data_addr(tex->img_ptr, &tex->bpp,
			&tex->len, &tex->endian);
	if (!tex->img_add)
		return (0);
	return (1);
}

void	init_textures(t_game *game)
{
	if (!load_xpm(game, &game->tex[0], game->map.map_config.no_txture))
		init_tex_msg(game, ERR_TEX_LOAD);
	if (!load_xpm(game, &game->tex[1], game->map.map_config.so_txture))
		init_tex_msg(game, ERR_TEX_LOAD);
	if (!load_xpm(game, &game->tex[2], game->map.map_config.we_txture))
		init_tex_msg(game, ERR_TEX_LOAD);
	if (!load_xpm(game, &game->tex[3], game->map.map_config.ea_txture))
		init_tex_msg(game, ERR_TEX_LOAD);
}
