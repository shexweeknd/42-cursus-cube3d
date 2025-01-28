/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:18:02 by hramaros          #+#    #+#             */
/*   Updated: 2025/01/28 12:55:11 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"

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

t_map	*parse_map(char *file)
{
	size_t	line_len;
	t_map	*result;
	char	**grid_tmp;

	result = NULL;
	line_len = count_grid_line(file);
	if (line_len < 3)
		return (set_error(err_grid_format), NULL);
	grid_tmp = squarify(retrieve_grid(file, line_len), line_len);
	if (!grid_tmp)
		return (set_error(err_malloc), NULL);
	if (!validate_grid(grid_tmp, line_len))
		return (set_error(err_grid_format), free_grid(grid_tmp), NULL);
	result = malloc(sizeof(t_map));
	if (!result)
		return (set_error(err_malloc), free_grid(grid_tmp), NULL);
	result->grid = grid_tmp;
	result->p_x = get_player_pos(grid_tmp, 'x');
	result->p_y = get_player_pos(grid_tmp, 'y');
	fill_canva(result, line_len);
	if (get_error())
		return (free_grid(grid_tmp), free(result), NULL);
	return (result);
}
