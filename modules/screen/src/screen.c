/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananarivo.mg>  #+#  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-22 07:09:18 by hramaros          #+#    #+#             */
/*   Updated: 2025-01-22 07:09:18 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

void	free_screen(t_screen *screen)
{
	if (!screen)
		return ;
	if (screen->mlx_win)
	{
		mlx_destroy_window(screen->mlx, screen->mlx_win);
		mlx_destroy_display(screen->mlx);
	}
	free(screen->mlx);
	return ;
}

int	handle_exit(t_screen *screen)
{
	if (screen)
		free_screen(screen);
	exit(1);
	return (0);
}

int	handle_key(int key, t_screen *screen)
{
	printf("Key: %d\n", key);
	if (key == 53 || key == 65307)
		handle_exit(screen);
	return (0);
}

void	cube_hook(t_screen *screen)
{
	mlx_hook(screen->mlx_win, KEY_PRESS, 1L << 0, handle_key, screen);
	mlx_hook(screen->mlx_win, KEY_EXIT, 1L << 17, handle_exit, screen);
}

void	draw_player(t_screen *screen)
{
	for (int i = 0; i < PIXEL_SIZE; i++)
	{
		for (int j = 0; j < PIXEL_SIZE; j++)
		{
			mlx_pixel_put(screen->mlx, screen->mlx_win, screen->p_x + i,
				screen->p_y + j, screen->p_color);
		}
	}
}

int	handle_keypress(int keycode, t_screen *screen)
{
	screen->p_color = 0x000000;
	draw_player(screen);

	if (keycode == 13 || keycode == 119)
		screen->p_y -= PIXEL_SIZE / 2;
	else if (keycode == 0 || keycode == 97)
		screen->p_x -= PIXEL_SIZE / 2;
	else if (keycode == 1 || keycode == 115)
		screen->p_y += PIXEL_SIZE / 2;
	else if (keycode == 2 || keycode == 100)
		screen->p_x += PIXEL_SIZE / 2;

	screen->p_color = 0x00FF00;
	draw_player(screen);

	return (0);
}