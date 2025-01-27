/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grids.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:18:02 by hramaros          #+#    #+#             */
/*   Updated: 2025/01/27 14:03:00 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"

// TODO
int	is_valid_grid(char **grid, size_t line_len)
{
	if (is_newline(grid))
		return (0);
	if (!is_always_one(grid[0]) || !is_always_one(grid[line_len - 1]))
		return (0);
	if (!is_closed(grid, line_len))
		return (0);
	if (is_forbidden_char(grid))
		return (0);
	return (1);
}

char	**retrieve_grid(char *file, size_t line_len)
{
	int		fd;
	int		i;
	char	**result;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (set_error(err_file_open), NULL);
	line = get_first_grid_line(fd);
	result = malloc(sizeof(char *) * (line_len + 1));
	if (!result)
		return (set_error(err_malloc), NULL);
	i = 0;
	while (line)
	{
		result[i++] = line;
		line = get_next_line(fd);
	}
	result[i] = NULL;
	return (close(fd), result);
}

// TODO
t_map	*parse_map(char *file)
{
	t_map	*result;
	char	**grid_tmp;
	size_t	line_len;

	result = NULL;
	line_len = count_grid_line(file);
	if (line_len < 3)
		return (set_error(err_grid_format), NULL);
	grid_tmp = retrieve_grid(file, line_len);
	if (!grid_tmp)
		return (set_error(err_malloc), NULL);
	if (!is_valid_grid(grid_tmp, line_len))
		return (set_error(err_grid_format), free_grid(grid_tmp), NULL);
	result = malloc(sizeof(t_map));
	if (!result)
		return (set_error(err_malloc), free_grid(grid_tmp), NULL);
	result->grid = grid_tmp;
	return (result);
}
