/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_draw_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:48:49 by hramaros          #+#    #+#             */
/*   Updated: 2025/02/10 15:32:15 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

void	my_mlx_pixel_put(t_screen *screen, int x, int y, int color)
{
	char	*dst;

	dst = screen->addr + (y * screen->line_length + x * (screen->bits_per_pixel
				/ 8));
	*(unsigned int *)dst = color;
}

void	put_black_screen(t_screen *screen)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_WIDTH)
	{
		j = 0;
		while (j < WIN_HEIGHT)
			my_mlx_pixel_put(screen, i, j++, 0x000000);
		i++;
	}
}

void	draw_square(t_screen *screen, int pos_x, int pos_y, char cmd)
{
	int	i;
	int	j;
	int	size;
	int	color;

	config_size_color(&size, &color, cmd, screen->map);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
			my_mlx_pixel_put(screen, pos_x + i, pos_y + j++, color);
		i++;
	}
}

void	config_size_color(int *size, int *color, char cmd, t_map *map)
{
	if (cmd == 'p')
	{
		*size = map->player_size;
		*color = map->p_color;
	}
	else if (cmd == 'b')
	{
		*size = map->bloc_size - 1;
		*color = 0xFFFF;
	}
	else if (cmd == 's')
	{
		*size = map->bloc_size - 1;
		*color = 0xE2D8D7;
	}
	return ;
}

void	draw_line(t_screen *screen, double x1, double y1)
{
	double	x;
	double	y;
	double	x2;
	double	y2;
	double	dx;
	double	dy;
	double	step;

	x = screen->map->p_x;
	y = screen->map->p_y;
	x2 = x1;
	y2 = y1;
	dx = x2 - x;
	dy = y2 - y;
	step = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
	dx /= step;
	dy /= step;
	while ((int)(x - x2) || (int)(y - y2))
	{
		if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
			my_mlx_pixel_put(screen, x, y, 0xFF0000);
		x += dx;
		y += dy;
	}
	return ;
}

void	raycast(t_screen *screen)
{
	double	dir_x;
	double	dir_y;

	dir_x = screen->map->p_x + 100 * cos(screen->map->p_angle * M_PI / 180);
	dir_y = screen->map->p_y + 100 * sin(screen->map->p_angle * M_PI / 180);
	printf("dir_x: %f, dir_y: %f\n", dir_x, dir_y);
	printf("p_x: %d, p_y: %d\n", screen->map->p_x, screen->map->p_y);
	draw_line(screen, dir_x, dir_y);
}

int	update_frame(t_screen *screen)
{
	move_player(screen->map);
	put_black_screen(screen);
	draw_map_grid(screen);
	draw_map_player(screen);
	raycast(screen);
	mlx_put_image_to_window(screen->mlx, screen->mlx_win, screen->img, 0, 0);
	return (0);
}
