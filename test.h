#ifndef TEST_H
# define TEST_H

#include "libft/libft.h"
#include <stdio.h>

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
}			t_map;

typedef struct s_game
{
	t_map		map;
	t_texture	tex[4];
}				t_game;

void	delete_newline(char *line);
void	replace_spaces(char	*line);
void	free_tab(char **tab);
int		count_size(char	**tex);
int		is_valid_tex(char **tex);
int		save_tex_path(char **tex, t_game *game);
int		parse_texture(char *line, t_game *game);
int		parse_file(int fd, t_game *game);

#endif
