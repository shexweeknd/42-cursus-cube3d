/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flooder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:58:41 by hramaros          #+#    #+#             */
/*   Updated: 2025/02/13 14:15:45 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"

void	flood_canva(char **grid, size_t line_len, t_pos curr)
{
	if ((size_t)curr.x <= 0 || (size_t)curr.y <= 0 || (size_t)curr.y >= line_len
		- 1 || grid[(size_t)curr.y][(size_t)curr.x] == '\n'
		|| grid[(size_t)curr.y][(size_t)curr.x] == '\0'
		|| grid[(size_t)curr.y][(size_t)curr.x] == '1'
		|| grid[(size_t)curr.y][(size_t)curr.x] == 'F')
		return ;
	if (grid[(size_t)curr.y][(size_t)curr.x] == ' ')
	{
		set_error(err_grid_format);
		return ;
	}
	grid[(size_t)curr.y][(size_t)curr.x] = 'F';
	if (get_error())
		return ;
	flood_canva(grid, line_len, (t_pos){curr.x - 1, curr.y});
	flood_canva(grid, line_len, (t_pos){curr.x + 1, curr.y});
	flood_canva(grid, line_len, (t_pos){curr.x, curr.y - 1});
	flood_canva(grid, line_len, (t_pos){curr.x, curr.y + 1});
}

void	fill_canva(t_map *map, size_t line_len)
{
	char	**copy;
	size_t	i;

	copy = malloc(sizeof(char *) * (line_len + 1));
	if (!copy)
		return (set_error(err_malloc));
	i = 0;
	while (i < line_len)
	{
		copy[i] = ft_strdup(map->grid[i]);
		i++;
	}
	copy[i] = NULL;
	flood_canva(copy, line_len, (t_pos){get_player_pos(map->grid, 'x'),
		get_player_pos(map->grid, 'y')});
	free_grid(copy);
	return ;
}
