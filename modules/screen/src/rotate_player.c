/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:26:35 by hramaros          #+#    #+#             */
/*   Updated: 2025/02/13 15:04:49 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

char	_is_rotating(int cmd)
{
	static char	flag = '\0';

	if (cmd == 'r')
		flag = 'r';
	else if (cmd == 'l')
		flag = 'l';
	else if (cmd == '\0')
		flag = '\0';
	return (flag);
}

void	rotate_player(t_map *map)
{
	if (_is_rotating('g') == 'r')
		map->p_angle = (map->p_angle + ROTATION_SPEED);
	else if (_is_rotating('g') == 'l')
		map->p_angle = (map->p_angle - ROTATION_SPEED);
	if (map->p_angle > 2 * M_PI)
		map->p_angle = 0;
	else if (map->p_angle < 0)
		map->p_angle = 2 * M_PI;
}
