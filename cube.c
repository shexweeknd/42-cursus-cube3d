/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazafis <hrazafis@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 06:25:01 by hramaros          #+#    #+#             */
/*   Updated: 2025/01/23 11:55:32 by hrazafis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_screen *screen, int x, int y, int color)
{
	char	*dst;

	dst = screen->addr + (y * screen->line_length + x * (screen->bits_per_pixel
				/ 8));
	*(unsigned int *)dst = color;
}
void	data_init(t_screen *screen)
{
	screen->mlx = mlx_init();
	screen->mlx_win = mlx_new_window(screen->mlx, WIDTH, HEIGHT, "CUBE3D");
	screen->img = mlx_new_image(screen->mlx, WIDTH, HEIGHT);
	screen->addr = mlx_get_data_addr(screen->img, &screen->bits_per_pixel,
			&screen->line_length, &screen->endian);
	my_mlx_pixel_put(screen, WIDTH / 2, HEIGHT / 2, 0x0000FF00);
	mlx_put_image_to_window(screen->mlx, screen->mlx_win, screen->img, 0, 0);
}

int	main(void)
{
	t_screen	screen;

	data_init(&screen);
	screen.p_x = WIDTH / 2;
	screen.p_y = HEIGHT / 2;
	screen.p_color = 0x00FF00;
	cube_hook(&screen);
	draw_player(&screen);
	mlx_key_hook(screen.mlx_win, handle_keypress, &screen);
	mlx_loop(screen.mlx);
	return (0);
}
