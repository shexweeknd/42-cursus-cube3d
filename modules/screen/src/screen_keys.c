/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:31:28 by hrazafis          #+#    #+#             */
/*   Updated: 2025/02/03 11:52:15 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

void	cube_hook(t_screen *screen)
{
	mlx_hook(screen->mlx_win, KEY_PRESS, 1L << 0, handle_key, screen);
	mlx_hook(screen->mlx_win, KEY_EXIT, 1L << 17, handle_exit, screen);
}

int	is_outside_map(t_map *map, int x, int y)
{
	int	last_px;
	int	last_py;

	if (x < 0 || y < 0)
		return (1);
	last_px = map->x_len * map->bloc_size - map->player_size;
	last_py = map->y_len * map->bloc_size - map->player_size;
	if (x > last_px || y > last_py)
		return (1);
	return (0);
}

int	is_valid_move(t_map *map, char cmd)
{
	int	x;
	int	y;

	x = map->p_x;
	y = map->p_y;
	if (cmd == 'w')
		y -= PIXEL_SIZE;
	else if (cmd == 'a')
		x -= PIXEL_SIZE;
	else if (cmd == 's')
		y += PIXEL_SIZE;
	else if (cmd == 'd')
		x += PIXEL_SIZE;
	if (x <= 0 || y <= 0 || (x > map->x_len * map->bloc_size - map->player_size)
		|| (y > map->y_len * map->bloc_size - map->player_size))
		return (0);
	return (1);
}
