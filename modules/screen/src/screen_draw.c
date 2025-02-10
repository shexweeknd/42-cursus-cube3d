/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:08:20 by hramaros          #+#    #+#             */
/*   Updated: 2025/02/10 15:00:06 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

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
	return ;
}

void	draw_map_grid(t_screen *screen)
{
	int		i;
	int		j;
	char	**grid;

	grid = screen->map->grid;
	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			draw_map_bloc(screen, i, j, grid);
			j++;
		}
		i++;
	}
}

void	draw_map(t_screen *screen)
{
	mlx_destroy_image(screen->mlx, screen->img);
	screen->img = mlx_new_image(screen->mlx, WIN_WIDTH, WIN_HEIGHT);
	put_black_screen(screen);
	draw_map_grid(screen);
	draw_map_player(screen);
	raycast(screen);
	mlx_put_image_to_window(screen->mlx, screen->mlx_win, screen->img, 0, 0);
}
