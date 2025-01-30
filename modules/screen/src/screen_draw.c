/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:08:20 by hramaros          #+#    #+#             */
/*   Updated: 2025/01/30 14:24:35 by hramaros         ###   ########.fr       */
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

void	draw_map_grid(t_screen *screen)
{
	int		i;
	int		j;
	char	**grid;

	grid = screen->map->grid;
	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			draw_map_bloc(screen, i, j, grid);
			j++;
		}
		i++;
	}
}

void	draw_map(t_screen *screen)
{
	mlx_destroy_image(screen->mlx, screen->img);
	screen->img = mlx_new_image(screen->mlx, WIN_WIDTH, WIN_HEIGHT);
	put_black_screen(screen);
	draw_map_grid(screen);
	draw_map_player(screen);
	mlx_put_image_to_window(screen->mlx, screen->mlx_win, screen->img, 0, 0);
}
