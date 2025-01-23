/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananarivo.mg>  #+#  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-23 10:28:15 by hramaros          #+#    #+#             */
/*   Updated: 2025-01-23 10:28:15 by hramaros         ###   ########.fr       */
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

void	data_init(t_screen *screen)
{
	int i;
	int j;

	int map[4][4] = {{1, 1, 1, 1}, {1, 0, 0, 1}, {1, 0, 0, 1}, {1, 1, 1, 1}};

	screen->mlx = mlx_init();
	screen->mlx_win = mlx_new_window(screen->mlx, WIDTH, HEIGHT, "CUBE3D");
	screen->img = mlx_new_image(screen->mlx, WIDTH, HEIGHT);
	screen->addr = mlx_get_data_addr(screen->img, &screen->bits_per_pixel,
			&screen->line_length, &screen->endian);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			screen->map[i][j] = map[i][j];
			j++;
		}
		i++;
	}
}