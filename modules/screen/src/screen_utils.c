/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:23:54 by hramaros          #+#    #+#             */
/*   Updated: 2025/02/11 15:54:12 by hramaros         ###   ########.fr       */
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

int	is_valid_move(t_map *map)
{
	double	dir_x;
	double	dir_y;

	dir_x = 0;
	dir_y = 0;
	config_next_coord(map, &dir_x, &dir_y);
	if (dir_x <= map->bloc_size || dir_y <= map->bloc_size
		|| dir_x >= map->bloc_size * (map->x_len - 1) || dir_y >= map->bloc_size
		* (map->y_len - 1))
		return (0);
	return (1);
}

int	update_frame(t_screen *screen)
{
	rotate_player(screen->map);
	move_player(screen->map);
	put_black_screen(screen);
	draw_map_grid(screen);
	draw_map_player(screen);
	trace_rays(screen);
	mlx_put_image_to_window(screen->mlx, screen->mlx_win, screen->img, 0, 0);
	return (0);
}
