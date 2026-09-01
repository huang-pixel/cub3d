/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 15:35:04 by hhuang2           #+#    #+#             */
/*   Updated: 2026/09/01 16:50:53 by hhuang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*
 *
 * Map struct:
 * 
 */
typedef struct s_map
{
    
}   t_map;

/*
 *
 * Texture struct:
 * - A path to a .xpm texture file
 * - Image pointer
 */
typedef struct s_texture
{
    void    *img;
    char    *filepath;
}   t_texture;

/*
 *
 * Vector struct:
 * Used for save position and movement calculation
 * 
 */
typedef struct s_vector
{
    float   x;
    float   y;
}   t_vector;

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
    t_vector    pos;
    float       dir_x;
    float       dir_y;
    float       plane_x;
    float       plane_y; 
    int         key_up;
    int         key_down;
    int         key_left;
    int         key_right;
}   t_player;

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
    t_player    player;
    t_texture   tex[4];
    t_map       map;    
}   t_game;

#endif