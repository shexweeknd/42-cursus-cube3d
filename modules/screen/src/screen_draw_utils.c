/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_draw_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:48:49 by hramaros          #+#    #+#             */
/*   Updated: 2025/02/03 11:37:03 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

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

void	draw_map_bloc(t_screen *screen, int i, int j, char **grid)
{
	if (grid[i][j] == '1')
		draw_square(screen, screen->map->bloc_size * j, screen->map->bloc_size
			* i, 'b');
	else if (grid[i][j] == '0')
		draw_square(screen, screen->map->bloc_size * j, screen->map->bloc_size
			* i, 's');
	else if (grid[i][j] == 'N' || grid[i][j] == 'S' || grid[i][j] == 'W')
	{
		draw_square(screen, screen->map->bloc_size * j, screen->map->bloc_size
			* i, 's');
	}
	return ;
}

void	draw_map_player(t_screen *screen)
{
	draw_square(screen, screen->map->p_x, screen->map->p_y, 'p');
	printf("Player pos: %d, %d\n", screen->map->p_x, screen->map->p_y);
	return ;
}
