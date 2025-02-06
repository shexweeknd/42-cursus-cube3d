/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:10:42 by hramaros          #+#    #+#             */
/*   Updated: 2025/02/06 15:22:04 by hramaros         ###   ########.fr       */
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

void	move_diagonaly(t_map *map, int *direction)
{
	if ((direction['w'] == 1) && (direction['d']) && is_valid_move(map, 'w')
		&& is_valid_move(map, 'd'))
	{
		map->p_y -= PIXEL_SIZE;
		map->p_x += PIXEL_SIZE;
	}
	else if ((direction['w'] == 1) && (direction['a']) && is_valid_move(map,
			'w') && is_valid_move(map, 'a'))
	{
		map->p_y -= PIXEL_SIZE;
		map->p_x -= PIXEL_SIZE;
	}
	else if ((direction['s'] == 1) && (direction['a']) && is_valid_move(map,
			's') && is_valid_move(map, 'a'))
	{
		map->p_y += PIXEL_SIZE;
		map->p_x -= PIXEL_SIZE;
	}
	else if ((direction['s'] == 1) && (direction['d']) && is_valid_move(map,
			's') && is_valid_move(map, 'd'))
	{
		map->p_y += PIXEL_SIZE;
		map->p_x += PIXEL_SIZE;
	}
}

void	move_orthogonaly(t_map *map, int *direction)
{
	if ((direction['w'] == 1) && is_valid_move(map, 'w'))
		map->p_y -= PIXEL_SIZE;
	else if ((direction['a'] == 1) && is_valid_move(map, 'a'))
		map->p_x -= PIXEL_SIZE;
	else if ((direction['s'] == 1) && is_valid_move(map, 's'))
		map->p_y += PIXEL_SIZE;
	else if ((direction['d'] == 1) && is_valid_move(map, 'd'))
		map->p_x += PIXEL_SIZE;
}

void	move_player(t_map *map)
{
	int	*direction;

	direction = _player_direction(' ', 0);
	move_diagonaly(map, direction);
	move_orthogonaly(map, direction);
}
