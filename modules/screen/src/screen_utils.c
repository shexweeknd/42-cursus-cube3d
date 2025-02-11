/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:23:54 by hramaros          #+#    #+#             */
/*   Updated: 2025/02/11 11:52:55 by hramaros         ###   ########.fr       */
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
	free_grid(screen->map->grid);
	free(screen->map);
	return ;
}

int	is_valid_move(t_map *map, char cmd)
{
	int	dir_x;
	int	dir_y;

	if (cmd == 'w')
	{
		dir_x = map->p_x + PIXEL_SIZE * cos(map->p_angle * M_PI / 180);
		dir_y = map->p_y + PIXEL_SIZE * sin(map->p_angle * M_PI / 180);
	}
	else if (cmd == 'a')
	{
		dir_x = map->p_x + PIXEL_SIZE * sin(map->p_angle * M_PI / 180);
		dir_y = map->p_y - PIXEL_SIZE * cos(map->p_angle * M_PI / 180);
	}
	else if (cmd == 's')
	{
		dir_x = map->p_x - PIXEL_SIZE * cos(map->p_angle * M_PI / 180);
		dir_y = map->p_y - PIXEL_SIZE * sin(map->p_angle * M_PI / 180);
	}
	else if (cmd == 'd')
	{
		dir_x = map->p_x - PIXEL_SIZE * sin(map->p_angle * M_PI / 180);
		dir_y = map->p_y + PIXEL_SIZE * cos(map->p_angle * M_PI / 180);
	}
	if (dir_x <= map->bloc_size || dir_y <= map->bloc_size
		|| dir_x >= map->bloc_size * (map->x_len - 1) || dir_y >= map->bloc_size
		* (map->y_len - 1))
		return (0);
	return (1);
}

int	update_frame(t_screen *screen)
{
	move_player(screen->map);
	rotate_player(screen->map);
	put_black_screen(screen);
	draw_map_grid(screen);
	draw_map_player(screen);
	raycast(screen);
	mlx_put_image_to_window(screen->mlx, screen->mlx_win, screen->img, 0, 0);
	return (0);
}
