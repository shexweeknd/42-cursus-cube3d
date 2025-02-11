/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_draw_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:48:49 by hramaros          #+#    #+#             */
/*   Updated: 2025/02/11 10:38:13 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

void	my_mlx_pixel_put(t_screen *screen, int x, int y, int color)
{
	char	*dst;

	dst = screen->addr + (y * screen->line_length + x * (screen->bits_per_pixel
				/ 8));
	*(unsigned int *)dst = color;
}

void	put_black_screen(t_screen *screen)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_WIDTH)
	{
		j = 0;
		while (j < WIN_HEIGHT)
			my_mlx_pixel_put(screen, i, j++, 0x000000);
		i++;
	}
}

void	draw_square(t_screen *screen, int pos_x, int pos_y, char cmd)
{
	int	i;
	int	j;
	int	size;
	int	color;

	config_size_color(&size, &color, cmd, screen->map);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
			my_mlx_pixel_put(screen, pos_x + i, pos_y + j++, color);
		i++;
	}
}

void	config_size_color(int *size, int *color, char cmd, t_map *map)
{
	if (cmd == 'p')
	{
		*size = map->player_size;
		*color = map->p_color;
	}
	else if (cmd == 'b')
	{
		*size = map->bloc_size - 1;
		*color = 0xFFFF;
	}
	else if (cmd == 's')
	{
		*size = map->bloc_size - 1;
		*color = 0xE2D8D7;
	}
	return ;
}
