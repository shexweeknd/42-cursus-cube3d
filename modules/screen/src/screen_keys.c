/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:31:28 by hrazafis          #+#    #+#             */
/*   Updated: 2025/01/30 14:31:12 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

void	cube_hook(t_screen *screen)
{
	mlx_hook(screen->mlx_win, KEY_PRESS, 1L << 0, handle_key, screen);
	mlx_hook(screen->mlx_win, KEY_EXIT, 1L << 17, handle_exit, screen);
}

int	is_valid_move(t_screen *screen, char cmd)
{
	int	x;
	int	y;

	x = screen->map->p_x;
	y = screen->map->p_y;
	if (cmd == 'w')
		y -= PIXEL_SIZE;
	else if (cmd == 'a')
		x -= PIXEL_SIZE;
	else if (cmd == 's')
		y += PIXEL_SIZE;
	else if (cmd == 'd')
		x += PIXEL_SIZE;
	if (x < 0 || y < 0 || x >= screen->map->map_width
		|| y >= screen->map->map_height)
		return (0);
	return (1);
}

int	handle_keypress(int keycode, t_screen *screen)
{
	mlx_destroy_image(screen->mlx, screen->img);
	screen->img = mlx_new_image(screen->mlx, WIN_WIDTH, WIN_HEIGHT);
	put_black_screen(screen);
	draw_map_grid(screen);
	if ((keycode == 13 || keycode == 119) && is_valid_move(screen, 'w'))
		screen->map->p_y -= PIXEL_SIZE;
	else if ((keycode == 0 || keycode == 97) && is_valid_move(screen, 'a'))
		screen->map->p_x -= PIXEL_SIZE;
	else if ((keycode == 1 || keycode == 115) && is_valid_move(screen, 's'))
		screen->map->p_y += PIXEL_SIZE;
	else if ((keycode == 2 || keycode == 100) && is_valid_move(screen, 'd'))
		screen->map->p_x += PIXEL_SIZE;
	draw_map_player(screen);
	mlx_put_image_to_window(screen->mlx, screen->mlx_win, screen->img, 0, 0);
	return (0);
}
