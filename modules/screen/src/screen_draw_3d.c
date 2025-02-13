/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_draw_3d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42Antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:40:48 by hramaros          #+#    #+#             */
/*   Updated: 2025/02/13 19:42:36 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

double get_wall_height(double distance_to_wall, double bloc_size)
{
    double dist_proj_plane;
    
    dist_proj_plane = (WIN_WIDTH / 2) / tan(FOV / 2);
    return (bloc_size * dist_proj_plane / distance_to_wall);
}

double get_wall_width(void)
{
    return ((double)WIN_WIDTH / RAYS_NBR);
}

void draw_3d_ray(t_screen *screen, t_pos pos, double distance)
{
    t_dim dim;

    dim.h = get_wall_height(distance, screen->map->bloc_size);
    dim.w = get_wall_width();

    // printf("dim.h: %f\n", dim.h);
    // printf("dim.w: %f\n", dim.w);

    draw_3d_rect(screen, pos, dim);
}

void    draw_3d_rect(t_screen *screen, t_pos pos, t_dim dim)
{
    int i;
    int j;

    i = pos.x;
    while (i < (pos.x + dim.w))
    {
        j = pos.y;
        while (j < (pos.y + dim.h / 2))
        {
            if (j >= 0 && j < WIN_HEIGHT)
                my_mlx_pixel_put(screen, i, j, 0x00FF00);
            j++;
        }
        i++;
    }
    i = pos.x;
    while (i < (pos.x + dim.w))
    {
        j = pos.y;
        while (j > (pos.y - dim.h / 2))
        {
            if (j >= 0 && j < WIN_HEIGHT)
                my_mlx_pixel_put(screen, i, j, 0x00FF00);
            j--;
        }
        i++;
    }
}
