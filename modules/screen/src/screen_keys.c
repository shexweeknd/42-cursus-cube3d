/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:31:28 by hrazafis          #+#    #+#             */
/*   Updated: 2025/01/30 11:32:24 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

void	cube_hook(t_screen *screen)
{
	mlx_hook(screen->mlx_win, KEY_PRESS, 1L << 0, handle_key, screen);
	mlx_hook(screen->mlx_win, KEY_EXIT, 1L << 17, handle_exit, screen);
}

int	handle_keypress(int keycode, t_screen *screen)
{
	mlx_destroy_image(screen->mlx, screen->img);
	screen->img = mlx_new_image(screen->mlx, WIDTH, HEIGHT);
	put_black_screen(screen);
	draw_map_grid(screen);
	if (keycode == 13 || keycode == 119)
		screen->map->p_y -= PLAYER_SIZE;
	else if (keycode == 0 || keycode == 97)
		screen->map->p_x -= PLAYER_SIZE;
	else if (keycode == 1 || keycode == 115)
		screen->map->p_y += PLAYER_SIZE;
	else if (keycode == 2 || keycode == 100)
		screen->map->p_x += PLAYER_SIZE;
	draw_map_player(screen);
	mlx_put_image_to_window(screen->mlx, screen->mlx_win, screen->img, 0, 0);
	return (0);
}
