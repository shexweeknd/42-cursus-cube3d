/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_tracerays.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42Antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:46:15 by hramaros          #+#    #+#             */
/*   Updated: 2025/02/13 21:26:27 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

int	is_wall(t_map *map, double x_dest, double y_dest)
{
	int	x;
	int	y;

	if (!x_dest || !y_dest)
		return (1);
	if (x_dest < 0 || x_dest >= map->x_len * map->bloc_size || y_dest < 0
		|| y_dest >= map->y_len * map->bloc_size)
		return (1);
	x = (int)(x_dest / map->bloc_size);
	y = (int)(y_dest / map->bloc_size);
	if (map->grid[y][x] == '1')
		return (1);
	return (0);
}

int	is_adjacent_wall(t_map *map, double x, double y)
{
	if (is_wall(map, x, y) || is_wall(map, x + 1, y) || is_wall(map, x - 1, y)
		|| is_wall(map, x, y + 1) || is_wall(map, x, y - 1))
		return (1);
	return (0);
}

void	draw_line(t_screen *screen, double ray_angle, int color)
{
	double	ray_x;
	double	ray_y;

	ray_x = screen->map->p_x;
	ray_y = screen->map->p_y;
	while (!is_wall(screen->map, ray_x, ray_y) && !is_adjacent_wall(screen->map,
			ray_x, ray_y))
	{
		if (ray_x > 0 && ray_y > 0)
			my_mlx_pixel_put(screen, ray_x, ray_y, color);
		ray_x += cos(ray_angle);
		ray_y += sin(ray_angle);
	}
	return ;
}

void	draw_line_3d(t_screen *screen, double ray_angle, int i)
{
	double	ray_x;
	double	ray_y;
	double 	distance;

	ray_x = screen->map->p_x;
	ray_y = screen->map->p_y;
	while (!is_wall(screen->map, ray_x, ray_y) && !is_adjacent_wall(screen->map,
			ray_x, ray_y))
	{
		ray_x += cos(ray_angle);
		ray_y += sin(ray_angle);
	}
	distance = sqrt((ray_x - screen->map->p_x) * (ray_x - screen->map->p_x) + (ray_y
				- screen->map->p_y) * (ray_y - screen->map->p_y));
	distance *= cos(ray_angle - screen->map->p_angle);
	draw_3d_ray(screen, (t_pos){i * get_wall_width(), WIN_HEIGHT / 2}, distance);
	return ;
}

void	trace_rays(t_screen *screen, int dim)
{
	int		i;
	double	ray_angle;

	i = 0;
	while (i < RAYS_NBR)
	{
		ray_angle = screen->map->p_angle - (FOV / 2) + (i * FOV / RAYS_NBR);
		if (dim == 2)
			draw_line(screen, ray_angle, 0xFF0000);
		else if (dim == 3)
			draw_line_3d(screen, ray_angle, i);
		i++;
	}
	// RAY PRINCIPAL
	draw_line(screen, screen->map->p_angle, 0x00FF00);
}
