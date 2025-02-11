/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_raycast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:46:15 by hramaros          #+#    #+#             */
/*   Updated: 2025/02/11 12:07:36 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

void	draw_line(t_screen *screen, double x1, double y1, int color)
{
	double	x;
	double	y;
	double	dx;
	double	dy;
	double	step;

	x = screen->map->p_x + screen->map->player_size / 2;
	y = screen->map->p_y + screen->map->player_size / 2;
	dx = x1 - x;
	dy = y1 - y;
	if (fabs(dx) > fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	dx /= step;
	dy /= step;
	while ((int)(x - x1) || (int)(y - y1))
	{
		if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
			my_mlx_pixel_put(screen, x, y, color);
		x += dx;
		y += dy;
	}
	return ;
}

void	raycast(t_screen *screen)
{
	double	angle_start;
	double	angle_end;
	double	dir_x;
	double	dir_y;

	angle_start = screen->map->p_angle - FOV / 2;
	angle_end = screen->map->p_angle + FOV / 2;
	while (angle_start < angle_end)
	{
		dir_x = screen->map->p_x + RAY_DIST * cos(angle_start * M_PI / 180);
		dir_y = screen->map->p_y + RAY_DIST * sin(angle_start * M_PI / 180);
		draw_line(screen, dir_x, dir_y, 0xFF0000);
		angle_start += RAY_DENSITY;
	}
	dir_x = screen->map->p_x + RAY_DIST * cos(screen->map->p_angle * M_PI
			/ 180);
	dir_y = screen->map->p_y + RAY_DIST * sin(screen->map->p_angle * M_PI
			/ 180);
	draw_line(screen, dir_x, dir_y, 0x00FF00);
}
