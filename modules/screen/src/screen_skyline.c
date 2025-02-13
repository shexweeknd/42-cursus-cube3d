/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_skyline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42Antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:34:45 by hramaros          #+#    #+#             */
/*   Updated: 2025/02/13 20:53:13 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

void draw_sky(t_screen *screen)
{
    int i;
    int j;

    i = 0;
    while (i < WIN_WIDTH)
    {
        j = 0;
        while (j < WIN_HEIGHT / 2)
        {
            if (j >= 0 && j < WIN_HEIGHT)
                my_mlx_pixel_put(screen, i, j, SKY_COLOR);
            j++;
        }
        i++;
    }
}

void draw_floor(t_screen *screen)
{
    int i;
    int j;

    i = 0;
    while (i < WIN_WIDTH)
    {
        j = WIN_HEIGHT / 2;
        while (j < WIN_HEIGHT)
        {
            if (j >= 0 && j < WIN_HEIGHT)
                my_mlx_pixel_put(screen, i, j, FLOOR_COLOR);
            j++;
        }
        i++;
    }
}

void draw_skyline(t_screen *screen)
{
    draw_floor(screen);
    draw_sky(screen);
}
