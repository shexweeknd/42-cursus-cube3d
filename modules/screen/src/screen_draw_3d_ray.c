/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_draw_3d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:40:48 by hramaros          #+#    #+#             */
/*   Updated: 2025/02/14 14:44:37 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

double	get_wall_height(double distance_to_wall, double bloc_size)
{
	double	dist_proj_plane;

	dist_proj_plane = (WIN_WIDTH / 2) / tan(FOV / 2);
	return (bloc_size * dist_proj_plane / distance_to_wall);
}

double	get_wall_width(void)
{
	return ((double)WIN_WIDTH / RAYS_NBR);
}

void	draw_3d_ray(t_screen *screen, t_pos pos, double distance)
{
	t_dim	dim;

	dim.h = get_wall_height(distance, screen->map->r_dim.b_size);
	dim.w = get_wall_width();
	draw_3d_rect(screen, pos, dim);
}
