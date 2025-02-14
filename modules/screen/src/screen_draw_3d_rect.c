/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_draw_3d_rect.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:44:19 by hramaros          #+#    #+#             */
/*   Updated: 2025/02/14 14:44:40 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

void	draw_3d_rect_bottom(t_screen *screen, t_pos pos, t_dim dim)
{
	int	i;
	int	j;

	i = pos.x;
	while (i < (pos.x + dim.w))
	{
		j = pos.y;
		while (j < (pos.y + dim.h / 2))
		{
			if (j >= 0 && j < WIN_HEIGHT)
				my_mlx_pixel_put(screen, i, j, WALL_COLOR);
			j++;
		}
		i++;
	}
}

void	draw_3d_rect_top(t_screen *screen, t_pos pos, t_dim dim)
{
	int	i;
	int	j;

	i = pos.x;
	while (i < (pos.x + dim.w))
	{
		j = pos.y;
		while (j > (pos.y - dim.h / 2))
		{
			if (j >= 0 && j < WIN_HEIGHT)
				my_mlx_pixel_put(screen, i, j, WALL_COLOR);
			j--;
		}
		i++;
	}
}

void	draw_3d_rect(t_screen *screen, t_pos pos, t_dim dim)
{
	draw_3d_rect_bottom(screen, pos, dim);
	draw_3d_rect_top(screen, pos, dim);
}
