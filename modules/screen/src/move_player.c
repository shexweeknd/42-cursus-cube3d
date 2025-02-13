/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:10:42 by hramaros          #+#    #+#             */
/*   Updated: 2025/02/13 14:44:18 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

int	*_player_direction(int cmd, int value)
{
	static int	direction[128];

	if (cmd == 'w' || cmd == 'a' || cmd == 's' || cmd == 'd')
		direction[cmd] = value;
	return (direction);
}

void	config_next_coord(t_map *map, double *dir_x, double *dir_y)
{
	int	*direction;

	direction = _player_direction(' ', 0);
	if (direction['w'])
	{
		*dir_x = map->p_x + PIXEL_SIZE * cos(map->p_angle);
		*dir_y = map->p_y + PIXEL_SIZE * sin(map->p_angle);
	}
	else if (direction['s'])
	{
		*dir_x = map->p_x - PIXEL_SIZE * cos(map->p_angle);
		*dir_y = map->p_y - PIXEL_SIZE * sin(map->p_angle);
	}
	else if (direction['a'])
	{
		*dir_x = map->p_x + PIXEL_SIZE * sin(map->p_angle);
		*dir_y = map->p_y - PIXEL_SIZE * cos(map->p_angle);
	}
	else if (direction['d'])
	{
		*dir_x = map->p_x - PIXEL_SIZE * sin(map->p_angle);
		*dir_y = map->p_y + PIXEL_SIZE * cos(map->p_angle);
	}
}

void	move_player(t_map *map)
{
	double	dir_x;
	double	dir_y;
	int		p_size;

	p_size = map->player_size / 2 - 1;
	dir_x = 0;
	dir_x = 0;
	config_next_coord(map, &dir_x, &dir_y);
	if ((!is_wall(map, dir_x + p_size, dir_y + p_size) && !is_wall(map, dir_x
				- p_size, dir_y - p_size)) && (!is_adjacent_wall(map, dir_x
				+ p_size, dir_y + p_size) && !is_adjacent_wall(map, dir_x
				- p_size, dir_y - p_size)) && (!is_adjacent_wall(map, dir_x
				+ p_size, dir_y - p_size) && !is_adjacent_wall(map, dir_x
				- p_size, dir_y + p_size)) && dir_x > 0
		&& dir_x < map->map_width && dir_y > 0 && dir_y < map->map_height)
	{
		map->p_x = dir_x;
		map->p_y = dir_y;
	}
}
