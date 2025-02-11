/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_bloc_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:56:17 by hramaros          #+#    #+#             */
/*   Updated: 2025/02/11 15:56:58 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

static void	draw_b_r(t_screen *screen, int pos_x, int pos_y, int color)
{
	int	i;
	int	j;
	int	bloc_size;

	if (color == screen->map->p_color)
		bloc_size = screen->map->player_size;
	else
		bloc_size = screen->map->bloc_size;
	i = 0;
	while (i < (bloc_size / 2))
	{
		j = 0;
		while (j < (bloc_size / 2))
			my_mlx_pixel_put(screen, pos_x + i, pos_y + j++, color);
		i++;
	}
}

static void	draw_t_l(t_screen *screen, int pos_x, int pos_y, int color)
{
	int	i;
	int	j;
	int	bloc_size;

	if (color == screen->map->p_color)
		bloc_size = screen->map->player_size;
	else
		bloc_size = screen->map->bloc_size;
	i = 0;
	while (i > -(bloc_size / 2))
	{
		j = 0;
		while (j > -(bloc_size / 2))
			my_mlx_pixel_put(screen, pos_x + i, pos_y + j--, color);
		i--;
	}
}

static void	draw_b_l(t_screen *screen, int pos_x, int pos_y, int color)
{
	int	i;
	int	j;
	int	bloc_size;

	if (color == screen->map->p_color)
		bloc_size = screen->map->player_size;
	else
		bloc_size = screen->map->bloc_size;
	i = 0;
	while (i > -(bloc_size / 2))
	{
		j = 0;
		while (j < (bloc_size / 2))
			my_mlx_pixel_put(screen, pos_x + i, pos_y + j++, color);
		i--;
	}
}

static void	draw_t_r(t_screen *screen, int pos_x, int pos_y, int color)
{
	int	i;
	int	j;
	int	bloc_size;

	if (color == screen->map->p_color)
		bloc_size = screen->map->player_size;
	else
		bloc_size = screen->map->bloc_size;
	i = 0;
	while (i < (bloc_size / 2))
	{
		j = 0;
		while (j > -(bloc_size / 2))
			my_mlx_pixel_put(screen, pos_x + i, pos_y + j--, color);
		i++;
	}
}

void	draw_bloc_square(t_screen *screen, int pos_x, int pos_y, char cmd)
{
	int	color;

	if (cmd == 'b')
		color = 0xFFFF;
	else if (cmd == 's')
		color = 0xE2D8D7;
	else if (cmd == 'p')
		color = screen->map->p_color;
	draw_b_r(screen, pos_x, pos_y, color);
	draw_t_r(screen, pos_x, pos_y, color);
	draw_t_l(screen, pos_x, pos_y, color);
	draw_b_l(screen, pos_x, pos_y, color);
}
