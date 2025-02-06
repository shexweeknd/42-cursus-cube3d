/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:23:54 by hramaros          #+#    #+#             */
/*   Updated: 2025/02/06 15:27:32 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

void	free_screen(t_screen *screen)
{
	if (!screen)
		return ;
	if (screen->mlx_win)
	{
		mlx_destroy_image(screen->mlx, screen->img);
		mlx_destroy_window(screen->mlx, screen->mlx_win);
		mlx_destroy_display(screen->mlx);
	}
	free(screen->mlx);
	free_grid(screen->map->grid);
	free(screen->map);
	return ;
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
