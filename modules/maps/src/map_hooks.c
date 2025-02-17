/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:56:36 by hramaros          #+#    #+#             */
/*   Updated: 2025/01/28 12:50:44 by hramaros         ###   ########.fr       */
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

static int	_is_closed_at(char *line, char c)
{
	int		j;
	size_t	size;

	if (!line)
		return (0);
	if (c == 'l')
	{
		j = 0;
		while (line && line[j] != '\0' && line[j] == ' ')
			j++;
		return ((line[j] == '1'));
	}
	else if (c == 'r')
	{
		size = ft_strlen(line);
		while (line && (line[size] == ' ' || line[size] == '\n'
				|| line[size] == '\0'))
			size--;
		if (line[size] != '1')
			return (0);
		return (1);
	}
	return (set_error(err_hook_instruction), 0);
}

int	is_closed(char **grid, size_t line_len)
{
	size_t	i;

	i = 1;
	while (i <= line_len - 2)
	{
		if (!_is_closed_at(grid[i], 'l') || !_is_closed_at(grid[i], 'r'))
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
