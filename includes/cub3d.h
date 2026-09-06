/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 15:35:04 by hhuang2           #+#    #+#             */
/*   Updated: 2026/09/06 17:44:34 by hhuang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "../libft/libft.h"
#include "mlx.h"
#include <math.h>


# define KEY_W   119
# define KEY_S	115
# define KEY_A	97
# define KEY_D	100


# define KEY_LEFT 65361
# define KEY_RIGHT 65363

//Error messages
# define ERR_ARG "Error\n Usage: ./cub3D <map.cub>\n"
# define ERR_EXT "Error\n Invalid map file extension\n"
# define ERR_READ_MAP "Error\n Can't read map file\n"
# define ERR_MAP "Error\n Invalid map file\n"
# define ERR_DUP_IDENTIFIER "Error\n Duplicate identifier in the map\n"
# define ERR_MISS_IDENTIFIER "Error\n Missing identifier in the map\n"
# define ERR_FLOOR "Error\n Invalid floor color\n"
# define ERR_CEILING "Error\n Invalid ceiling color\n"
# define ERR_TEXTURE "Error\n Invalid texture file\n"

//Memory related error messages
# define ERR_MALLOC "Error\n Memory allocation failed\n"

/*
 *
 * mlx struct:
 *
 */
typedef struct s_mlx
{
	void	*mlx;
	void 	*win;
	void	*img;
	char	*img_addr;
} t_mlx;

typedef struct s_mapconfig
{
	char	*no_txture;
	char	*so_txture;
	char	*ea_txture;
	char	*we_txture;
	int		floor_color;
	int		ceiling_color;
}	t_mapconfig;

/*
 *
 * Map struct:
 * - width: numbers of columns in the map
 * - height: numbers of rows in the map
 * - no_path: path to north texture 
 * - so_path: path to south texture
 * - we_path: path to west texture
 * - ea_path: path to east texture
 */
typedef struct s_map
{
    int		width;
	int		height;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	t_mapconfig	map_config;
	char		**map;
	int			map_width;
	int			map_height;
}   t_map;

/*
 *
 * Texture struct:
 * - A path to a .xpm texture file
 * - Image pointer
 */
typedef struct s_texture
{
	void	*img;
	char	*filepath;
}	t_texture;

/*
 *
 * Vector struct:
 * Used for saving position and movement calculation
 * 
 */
typedef struct s_vector
{
	float	x;
	float	y;
}	t_vector;

/*
 *
 * Player struct includes:
 * - pos: current coordinates on the map (x, y)
 * - dir_x/y: directions where the player is looking
 * - plane_x/y: camera plane used for FOV (field of view) in raycasting
 * - key_up/down: move forward and backward
 * - key_left/right: move left and right
 * 
 */
typedef struct s_player
{
	t_vector	pos;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y; 
	int		move_forward;
	int		move_backward;
	int		move_left;
	int		move_right;
	int		rotate_left;
	int		rotate_right;
}	t_player;

/*
 *
 * Game struct includes:
 *  Player: player position
 *  Texture: 4 sides wall textures: North, South, East, West
 *  Map: 
 * 
 */
typedef struct s_game
{
	t_mlx		mlx;
	t_player	player;
	t_texture	tex[4];
	t_map		map;
}	t_game;


void    init_game(t_game *game);
void	free_game(t_game *game);
int	parse_file(char *file, t_game *game);

#endif
