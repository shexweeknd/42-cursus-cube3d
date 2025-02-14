/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:08:20 by hramaros          #+#    #+#             */
/*   Updated: 2025/02/14 14:13:47 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

void	draw_map_bloc(t_screen *screen, int i, int j, char **grid)
{
	int	pos_x;
	int	pos_y;

	pos_x = screen->map->s_dim.b_size * j + screen->map->s_dim.b_size / 2;
	pos_y = screen->map->s_dim.b_size * i + screen->map->s_dim.b_size / 2;
	if (grid[i][j] == '1')
		draw_bloc_square(screen, pos_x, pos_y, 'b');
	else if (grid[i][j] == '0')
		draw_bloc_square(screen, pos_x, pos_y, 's');
	else if (grid[i][j] == 'N' || grid[i][j] == 'S' || grid[i][j] == 'W')
		draw_bloc_square(screen, pos_x, pos_y, 's');
	return ;
}

void	draw_map_player(t_screen *screen)
{
	int	pos_x;
	int	pos_y;

	pos_x = screen->map->s_dim.p_x;
	pos_y = screen->map->s_dim.p_y;
	draw_bloc_square(screen, pos_x, pos_y, 'p');
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
	trace_rays(screen, 2);
	mlx_put_image_to_window(screen->mlx, screen->mlx_win, screen->img, 0, 0);
}
