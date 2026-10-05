#include "test.h"

/*
 * 
 * dir  = where I look
 * plane = how wide I see
 * angle = direction expressed as an angle
 */

/*
 * To calculate each ray’s direction:
 *  rayDir = direction + cameraPlane * cameraX
 *  direction = player direction vector
 *  cameraX = a value from -1 (left edge) to +1 (right edge)
 *  cameraPlane = left/right direction vector (FOV)
 *  PI / 2: 90 degrees, expressed in radians.
 *  0.66f: Camera plane length → controls FOV.
 * 
 */

static void set_no_angle(t_player *player)
{
    player->angle = -PI / 2;
    player->dir_x = 0.0f;
    player->dir_y = -1.0f;
    player->plane_x = 0.66f;
    player->plane_y = 0.0f;
}

static void set_so_angle(t_player *player)
{
    player->angle = PI / 2;
    player->dir_x = 0.0f;
    player->dir_y = 1.0f;
    player->plane_x = -0.66f;
    player->plane_y = 0.0f;
}

static void set_ew_angle(t_player *player)
{
    player->angle = 0.0f;
    player->dir_x = 1.0f;
    player->dir_y = 0.0f;
    player->plane_x = 0.0f;
    player->plane_y = 0.66f;
}

static void set_we_angle(t_player *player)
{
    player->angle = PI;
    player->dir_x = -1.0f;
    player->dir_y = 0.0f;
    player->plane_x = 0.0f;
    player->plane_y = -0.66f;
}

void    set_angle(t_player *player, char c)
{
    if (c == 'N')
        set_no_angle(player);
    else if (c == 'S')
        set_so_angle(player);
    else if (c == 'E')
        set_ew_angle(player);
    else if (c == 'W')
        set_we_angle(player);
}