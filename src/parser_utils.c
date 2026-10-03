/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vino <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 04:33:25 by vino              #+#    #+#             */
/*   Updated: 2026/10/03 04:33:46 by vino             ###   ########.fr       */
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

void	trim_line(char *s)
{
	int	len;

	len = (int)ft_strlen(s);
	while (len > 0 && (s[len - 1] == '\n'
			|| s[len - 1] == '\r'
			|| s[len - 1] == ' '
			|| s[len - 1] == '\t'))
	{
		s[len - 1] = '\0';
		len--;
	}
}
