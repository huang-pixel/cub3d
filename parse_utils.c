/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 17:28:39 by hhuang2           #+#    #+#             */
/*   Updated: 2026/09/08 17:33:02 by hhuang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

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
 * Find tab or newline character in each line and replace them by ' '
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

/*
 *
 * Count texture size, except null and empty element
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