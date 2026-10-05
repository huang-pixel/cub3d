#ifndef TEST_H
# define TEST_H

#include "libft/libft.h"
#include <stdio.h>

# define PI 3.14159265358979323846

typedef struct s_texture
{
	char	*path;
}			t_texture;

typedef struct s_map
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
    int     floor_color;
    int     ceiling_color;
    int     height;
    int     width;
    char    **map_tab;
    int     *line;
}			t_map;

typedef struct s_vector
{
	float	x;
	float	y;
}			t_vector;

typedef struct s_player
{
	t_vector	pos;
	float	dir_x;
	float	dir_y;
	float	angle;
	float	plane_x;
	float	plane_y;
}			t_player;

typedef struct s_color
{
    int r;
    int g;
    int b;
}       t_color;

typedef struct s_game
{
	t_map		map;
	t_texture	tex[4];
	t_player	player;
	t_color		color;
}				t_game;

void    init_game(t_game *game);

/* Parsing utils */
void	delete_newline(char *line);
int     ft_isspace(int c);
void	replace_spaces(char	*line);
void	free_tab(char **tab);
int		count_size(char	**tab);

/* Texture parsing */
int		is_valid_tex(char **tex);
int		save_tex_path(char **tex, t_game *game);
int		parse_texture(char *line, t_game *game);

/* Color parsing */
int     is_valid_color_line(char **tab);
int	    is_valid_value(char *value);
int     is_all_valid_rgb(char *color_str, t_color *color);
int	    set_rgb_value(char **color_line, t_color *color, t_game *game);
int     parse_color(char *line, t_color *color, t_game *game);

/* Map parsing */
int     is_map_line(char *line);
int 	check_map_config(t_game *game);
int	    get_max_length(t_list *map_list);
void	fill_spaces(char *newline, int len, int max);
char	*normalise(int max_len, char *content);
int 	read_map_lines(t_list **map_lst, int fd);
int	    alloc_map_tab(t_game *game, t_list *map_list);
int	    save_map_tab(t_game *game, t_list *map_list);
int     parse_map(char *line, int fd, t_game *game);

int     parse_line(char *line, t_game *game);
int		parse_file(int fd, t_game *game);

/* Player validation */
void    set_angle(t_player *player, char c);
int     save_player_pos(t_game *game, int x, int y);
int 	is_valid_player(t_game *game);

/* Map validation */
int is_valid_char(char c);
int	check_valid_char(t_game *game);

#endif
