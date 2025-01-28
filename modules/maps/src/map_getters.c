/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_getters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:33:06 by hramaros          #+#    #+#             */
/*   Updated: 2025/01/28 12:36:33 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"

int	get_player_pos(char **grid, char axis)
{
	int	i;
	int	j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == 'N' || grid[i][j] == 'S' || grid[i][j] == 'E'
				|| grid[i][j] == 'W')
			{
				if (axis == 'x')
					return (j);
				else if (axis == 'y')
					return (i);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

size_t	get_max_line_size(char **grid)
{
	size_t	i;
	size_t	max_len;
	size_t	curr_len;

	i = 0;
	max_len = 0;
	while (grid[i])
	{
		curr_len = ft_strlen(grid[i]);
		if (curr_len > max_len)
			max_len = curr_len;
		i++;
	}
	return (max_len);
}

char	*get_first_grid_line(int fd)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (line[i] == ' ')
			i++;
		if (line[i] == '1')
			break ;
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}
