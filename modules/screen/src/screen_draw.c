/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:08:20 by hramaros          #+#    #+#             */
/*   Updated: 2025/01/30 11:59:58 by hramaros         ###   ########.fr       */
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
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
			my_mlx_pixel_put(screen, i, j++, 0x000000);
		i++;
	}
}

void	draw_square(t_screen *screen, int size, int p_x, int p_y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
			my_mlx_pixel_put(screen, p_x + i, p_y + j++, color);
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
			if (grid[i][j] == '1')
				draw_square(screen, SQUARE_SIZE - 1, SQUARE_SIZE * j,
					SQUARE_SIZE * i, 0xFFFF);
			else if (grid[i][j] == '0')
				draw_square(screen, SQUARE_SIZE - 1, SQUARE_SIZE * j,
					SQUARE_SIZE * i, 0xE2D8D7);
			else if (grid[i][j] == 'N' || grid[i][j] == 'S'
				|| grid[i][j] == 'W')
			{
				draw_square(screen, SQUARE_SIZE - 1, SQUARE_SIZE * j,
					SQUARE_SIZE * i, 0xE2D8D7);
				draw_square(screen, PLAYER_SIZE, screen->map->p_x * SQUARE_SIZE
					+ SQUARE_SIZE / 2 - PLAYER_SIZE / 2, screen->map->p_y
					* SQUARE_SIZE + SQUARE_SIZE / 2 - PLAYER_SIZE / 2,
					screen->map->p_color);
			}
			j++;
			mlx_put_image_to_window(screen->mlx, screen->mlx_win, screen->img,
				0, 0);
		}
		i++;
	}
}

void	draw_map(t_screen *screen)
{
	mlx_destroy_image(screen->mlx, screen->img);
	screen->img = mlx_new_image(screen->mlx, WIDTH, HEIGHT);
	put_black_screen(screen);
	draw_map_grid(screen);
	mlx_put_image_to_window(screen->mlx, screen->mlx_win, screen->img, 0, 0);
}