/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vino <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 05:25:17 by vino              #+#    #+#             */
/*   Updated: 2026/10/03 05:25:19 by vino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**read_all_map_lines(int fd)
{
	char	**lines;
	char	*line;
	int		count;
	char	**new;
	int		i;

	lines = NULL;
	count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		new = malloc(sizeof(char *) * (count + 2));
		if (!new)
			return (ft_putstr_fd(ERR_MALLOC, 2), free_tab(lines), NULL);
		i = -1;
		while (++i < count)
			new[i] = lines[i];
		new[count] = line;
		new[count + 1] = NULL;
		free(lines);
		lines = new;
		count++;
		line = get_next_line(fd);
	}
	return (lines);
}

int	find_map_start(char **lines)
{
	int		i;
	char	*temp;

	i = 0;
	while (lines[i])
	{
		temp = lines[i];
		while (*temp == ' ' || *temp == '\t')
			temp++;
		if (*temp == '\0' || *temp == '\n')
		{
			i++;
			continue ;
		}
		if (!ft_strncmp(temp, "NO", 2) || !ft_strncmp(temp, "SO", 2)
			|| !ft_strncmp(temp, "EA", 2) || !ft_strncmp(temp, "WE", 2)
			|| temp[0] == 'F' || temp[0] == 'C')
		{
			i++;
			continue ;
		}
		return (i);
	}
	return (-1);
}

static int	get_header_identifier(char *line)
{
	if (!ft_strncmp(line, "NO", 2))
		return (ID_NO);
	if (!ft_strncmp(line, "SO", 2))
		return (ID_SO);
	if (!ft_strncmp(line, "WE", 2))
		return (ID_WE);
	if (!ft_strncmp(line, "EA", 2))
		return (ID_EA);
	if (line[0] == 'F')
		return (ID_F);
	if (line[0] == 'C')
		return (ID_C);
	return (-1);
}

int	handle_header_line(char *line, t_game *game, int *found)
{
	int	id;

	id = get_header_identifier(line);
	if (id < 0)
		return (ft_putstr_fd(ERR_INVALID_HEADER, 2), 1);
	if (found[id])
	{
		if (id == ID_NO)
			return (ft_putstr_fd(ERR_DUP_TEX_IDENT, 2), 1);
		if (id == ID_SO)
			return (ft_putstr_fd(ERR_DUP_TEX_IDENT, 2), 1);
		if (id == ID_WE)
			return (ft_putstr_fd(ERR_DUP_TEX_IDENT, 2), 1);
		if (id == ID_EA)
			return (ft_putstr_fd(ERR_DUP_TEX_IDENT, 2), 1);
		if (id == ID_F)
			return (ft_putstr_fd(ERR_DUP_FLOOR_COL, 2), 1);
		if (id == ID_C)
			return (ft_putstr_fd(ERR_DUP_CEIL_COL, 2), 1);
	}
	found[id] = 1;
	if (id == ID_NO || id == ID_SO || id == ID_WE || id == ID_EA)
		return (process_texture(line, game));
	return (process_color(line, game));
}

/*
** parse_header()
**
** Reads all lines before the map section and extracts the 6 required
** configuration identifiers: NO, SO, WE, EA, F, and C.
** Skips empty lines, detects duplicates, and rejects invalid header lines.
** If any identifier is missing, or if the map starts at line 0 (no header),
** the function returns an error.
**
** Returns:
**   0 on success
**   1 on error
*/

int	parse_header(char **lines, int map_start, t_game *game)
{
	int		i;
	int		found[ID_COUNT];
	char	*tmp;

	i = 0;
	ft_bzero(found, sizeof (found));
	while (i < map_start)
	{
		tmp = lines[i];
		while (*tmp == ' ' || *tmp == '\t')
			tmp++;
		if (*tmp != '\0' && *tmp != '\n')
		{
			if (handle_header_line(tmp, game, found))
				return (1);
		}
		i++;
	}
	if (!found[ID_NO] || !found[ID_SO] || !found[ID_WE]
		|| !found[ID_EA] || !found[ID_F] || !found[ID_C])
		return (ft_putstr_fd(ERR_MISS_IDENTIFIER, 2), 1);
	return (0);
}
