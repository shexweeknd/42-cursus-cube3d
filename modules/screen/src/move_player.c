/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:10:42 by hramaros          #+#    #+#             */
/*   Updated: 2025/02/14 14:40:26 by hramaros         ###   ########.fr       */
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

void	set_coord(t_map *map, double *p_x, double *p_y, int dim)
{
	if (dim == 3)
	{
		*p_x = map->r_dim.p_x;
		*p_y = map->r_dim.p_y;
	}
	else if (dim == 2)
	{
		*p_x = map->s_dim.p_x;
		*p_y = map->s_dim.p_y;
	}
}

void	config_next_coord(t_map *map, double *dir_x, double *dir_y, int dim)
{
	int		*direction;
	double	p_x;
	double	p_y;

	direction = (set_coord(map, &p_x, &p_y, dim), _player_direction(' ', 0));
	if (direction['w'])
	{
		*dir_x = p_x + PIXEL_SIZE * cos(map->p_angle);
		*dir_y = p_y + PIXEL_SIZE * sin(map->p_angle);
	}
	else if (direction['s'])
	{
		*dir_x = p_x - PIXEL_SIZE * cos(map->p_angle);
		*dir_y = p_y - PIXEL_SIZE * sin(map->p_angle);
	}
	else if (direction['a'])
	{
		*dir_x = p_x + PIXEL_SIZE * sin(map->p_angle);
		*dir_y = p_y - PIXEL_SIZE * cos(map->p_angle);
	}
	else if (direction['d'])
	{
		*dir_x = p_x - PIXEL_SIZE * sin(map->p_angle);
		*dir_y = p_y + PIXEL_SIZE * cos(map->p_angle);
	}
}

int	is_valid_move(t_map *map, t_pos pos, double p_size, int dim)
{
	double	dir_x;
	double	dir_y;

	dir_x = pos.x;
	dir_y = pos.y;
	return ((!is_wall(map, dir_x - p_size, dir_y - p_size, dim))
		&& (!is_adjacent_wall(map, dir_x + p_size, dir_y + p_size, dim)
			&& !is_adjacent_wall(map, dir_x - p_size, dir_y - p_size, dim))
		&& (!is_adjacent_wall(map, dir_x + p_size, dir_y - p_size, dim)
			&& !is_adjacent_wall(map, dir_x - p_size, dir_y + p_size, dim))
		&& dir_x > 0 && dir_y > 0);
}

void	move_player(t_map *map, int dim)
{
	double	dir_x;
	double	dir_y;
	int		p_size;

	if (dim == 3)
		p_size = map->r_dim.p_size / 2 - 1;
	else if (dim == 2)
		p_size = map->s_dim.p_size / 2 - 1;
	dir_x = 0;
	dir_y = 0;
	config_next_coord(map, &dir_x, &dir_y, dim);
	if (is_valid_move(map, (t_pos){dir_x, dir_y}, p_size, dim))
	{
		if (dim == 3)
		{
			map->r_dim.p_x = dir_x;
			map->r_dim.p_y = dir_y;
		}
		else if (dim == 2)
		{
			map->s_dim.p_x = dir_x;
			map->s_dim.p_y = dir_y;
		}
	}
}
