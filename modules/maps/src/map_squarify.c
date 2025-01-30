/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_squarify.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:52:03 by hramaros          #+#    #+#             */
/*   Updated: 2025/01/30 12:55:13 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"

void	process_line(char **result, char **grid, size_t max_len)
{
	size_t	i;
	char	*padding;

	i = 0;
	while (grid[i])
	{
		if (grid[i][ft_strlen(grid[i]) - 1] == '\n')
			grid[i][ft_strlen(grid[i]) - 1] = '\0';
		padding = NULL;
		if (ft_strlen(grid[i]) < max_len - 1)
		{
			padding = ft_strnew(max_len - ft_strlen(grid[i]) + 1, ' ');
			result[i] = ft_strjoin(grid[i], padding);
			result[i][max_len - 1] = '\0';
			free(padding);
		}
		else
			result[i] = ft_strdup(grid[i]);
		i++;
	}
	return ;
}

char	**squarify(char **grid, size_t line_len)
{
	char	**result;
	size_t	max_len;

	if (!grid)
		return (NULL);
	max_len = get_max_line_size(grid);
	if (max_len == 0)
		return (set_error(err_grid_format), free_grid(grid), NULL);
	result = malloc(sizeof(char *) * (line_len + 1));
	if (!result)
		return (free_grid(grid), NULL);
	process_line(result, grid, max_len - 1);
	result[line_len - 1][max_len - 1] = '\0';
	result[line_len] = NULL;
	return (free_grid(grid), result);
}
