/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Created: 2026/09/10 00:39:44 by vino              #+#    #+#             */
/*   Updated: 2026/09/10 00:39:49 by vino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	skip_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' '
		|| line[i] == '\t'))
		i++;
	return (i);
}

/*
 *
 * Count array size, except null and empty element
 * 
 */

int	count_size(char	**tex)
{
	int	i;

	i = 0;
	while (tex[i])
		i++;
	return (i);
}

/*
 *
 * Delete the last newline character from each line
 * 
 */
void	delete_newline(char *line)
{
	int	len;

	if (!line)
		return ;
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

/*
 *
 * Find tab in each line and replace them by ' '
 * 
 */
void	replace_spaces(char	*line)
{
	int	i;

	if (!line)
		return ;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			line[i] = ' ';
		i++;
	}
}
