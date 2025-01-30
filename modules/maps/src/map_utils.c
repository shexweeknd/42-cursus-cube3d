/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:11:27 by hramaros          #+#    #+#             */
/*   Updated: 2025/01/30 12:46:53 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"

void	print_grid(char **grid)
{
	int	i;

	i = 0;
	while (grid[i])
		printf("%s\n", grid[i++]);
}

void	free_grid(char **grid)
{
	int	i;

	i = 0;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

size_t	count_grid_line(char *file)
{
	int		fd;
	char	*line;
	size_t	count;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (set_error(err_file_open), 0);
	line = get_first_grid_line(fd);
	count = 0;
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}
