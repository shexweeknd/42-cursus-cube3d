/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:23:54 by hramaros          #+#    #+#             */
/*   Updated: 2025/02/14 14:22:41 by hramaros         ###   ########.fr       */
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

void	render_2d_map(t_screen *screen)
{
	draw_map_grid(screen);
	draw_map_player(screen);
	trace_rays(screen, 2);
}

int	update_frame(t_screen *screen)
{
	rotate_player(screen->map);
	move_player(screen->map, 3);
	move_player(screen->map, 2);
	draw_skyline(screen);
	trace_rays(screen, 3);
	render_2d_map(screen);
	mlx_put_image_to_window(screen->mlx, screen->mlx_win, screen->img, 0, 0);
	return (0);
}
