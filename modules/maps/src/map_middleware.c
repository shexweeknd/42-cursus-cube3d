/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_middleware.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:56:36 by hramaros          #+#    #+#             */
/*   Updated: 2025/01/27 13:56:55 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"

int	is_always_one(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '1')
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return (1);
	return (0);
}

int	is_newline(char **grid)
{
	int	i;

	i = 0;
	while (grid[i])
	{
		if (grid[i][0] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	is_closed_at_left(char *line)
{
	int	j;

	j = 0;
	while (line[j] == ' ')
		j++;
	return ((line[j] == '1'));
}

int	is_closed_at_right(char *line)
{
	size_t	size;

	size = ft_strlen(line);
	while (line[size] == ' ' || line[size] == '\n' || line[size] == '\0')
		size--;
	if (line[size] != '1')
		return (0);
	return (1);
}

int	is_closed(char **grid, size_t line_len)
{
	size_t	i;

	i = 1;
	while (i <= line_len - 2)
	{
		if (!is_closed_at_left(grid[i]) || !is_closed_at_right(grid[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_forbidden_char(char **grid)
{
	size_t	i;
	size_t	j;
	int		count;

	count = 0;
	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] != '\n' && grid[i][j] != '1' && grid[i][j] != '0'
				&& grid[i][j] != ' ' && grid[i][j] != 'N' && grid[i][j] != 'S'
				&& grid[i][j] != 'E' && grid[i][j] != 'W')
				return (1);
			if (grid[i][j] == 'N' || grid[i][j] == 'S' || grid[i][j] == 'E'
				|| grid[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (1);
	return (0);
}
