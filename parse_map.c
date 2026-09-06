/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 16:06:20 by hhuang2           #+#    #+#             */
/*   Updated: 2026/09/05 16:06:57 by hhuang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

/*
 *
 * Check whether the read line is a map line
 * 
 */

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	if (!line[i])
		return (0);
	if (line[i] == '1' || line[i] == '0')
		return (1);
	return (0);
}