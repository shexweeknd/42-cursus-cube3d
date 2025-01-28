/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:31:28 by hrazafis          #+#    #+#             */
/*   Updated: 2025/01/28 13:08:05 by hramaros         ###   ########.fr       */
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
	return ;
}

int	handle_exit(t_screen *screen)
{
	if (screen)
		free_screen(screen);
	exit(0);
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

void	draw_map(t_screen *screen, int map[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (map[i][j] == 1)
				draw_square(screen, MAP_SIZE - 1, MAP_SIZE * j, MAP_SIZE * i,
					0xFFFF);
			else if (map[i][j] == 0)
				draw_square(screen, MAP_SIZE - 1, MAP_SIZE * j, MAP_SIZE * i,
					0xE2D8D7);
			j++;
		}
		i++;
	}
}

int	handle_keypress(int keycode, t_screen *screen)
{
	mlx_destroy_image(screen->mlx, screen->img);
	screen->img = mlx_new_image(screen->mlx, WIDTH, HEIGHT);
	draw_map(screen, screen->map);
	if (keycode == 13 || keycode == 119)
		screen->p_y -= PLAYER_SIZE;
	else if (keycode == 0 || keycode == 97)
		screen->p_x -= PLAYER_SIZE;
	else if (keycode == 1 || keycode == 115)
		screen->p_y += PLAYER_SIZE;
	else if (keycode == 2 || keycode == 100)
		screen->p_x += PLAYER_SIZE;
	draw_square(screen, PLAYER_SIZE, screen->p_x, screen->p_y, screen->p_color);
	mlx_put_image_to_window(screen->mlx, screen->mlx_win, screen->img, 0, 0);
	return (0);
}
