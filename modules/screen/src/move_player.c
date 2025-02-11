/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:10:42 by hramaros          #+#    #+#             */
/*   Updated: 2025/02/11 12:04:45 by hramaros         ###   ########.fr       */
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

int	is_valid_coords(t_map *map, int x_dest, int y_dest)
{
	if (x_dest <= map->bloc_size || y_dest <= map->bloc_size)
		return (0);
	if (x_dest >= map->bloc_size * (map->x_len - 1) || y_dest >= map->bloc_size
		* (map->y_len - 1))
		return (0);
	return (1);
}

void	config_next_coord(t_map *map, double *dir_x, double *dir_y)
{
	int	*direction;

	direction = _player_direction(' ', 0);
	if (direction['w'])
	{
		*dir_x = map->p_x + PIXEL_SIZE * cos(map->p_angle * M_PI / 180);
		*dir_y = map->p_y + PIXEL_SIZE * sin(map->p_angle * M_PI / 180);
	}
	else if (direction['s'])
	{
		*dir_x = map->p_x - PIXEL_SIZE * cos(map->p_angle * M_PI / 180);
		*dir_y = map->p_y - PIXEL_SIZE * sin(map->p_angle * M_PI / 180);
	}
	else if (direction['a'])
	{
		*dir_x = map->p_x + PIXEL_SIZE * sin(map->p_angle * M_PI / 180);
		*dir_y = map->p_y - PIXEL_SIZE * cos(map->p_angle * M_PI / 180);
	}
	else if (direction['d'])
	{
		*dir_x = map->p_x - PIXEL_SIZE * sin(map->p_angle * M_PI / 180);
		*dir_y = map->p_y + PIXEL_SIZE * cos(map->p_angle * M_PI / 180);
	}
}

void	move_player(t_map *map)
{
	double	dir_x;
	double	dir_y;

	config_next_coord(map, &dir_x, &dir_y);
	if (is_valid_coords(map, dir_x, dir_y))
	{
		map->p_x = dir_x;
		map->p_y = dir_y;
	}
}
