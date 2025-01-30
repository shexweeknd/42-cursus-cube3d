/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:31:35 by hrazafis          #+#    #+#             */
/*   Updated: 2025/01/30 11:39:01 by hramaros         ###   ########.fr       */
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

int	handle_exit(t_screen *screen)
{
	if (screen)
		free_screen(screen);
	exit(0);
	return (0);
}

int	handle_key(int key, t_screen *screen)
{
	printf("Key: %d\n", key);
	if (key == 53 || key == 65307)
		handle_exit(screen);
	return (0);
}

int	get_scr_ppos(int p_pos)
{
	return (p_pos * PIXEL_SIZE);
}

int	data_init(t_screen *screen, char *map_file)
{
	t_map	*map;

	// INIT THE MAP
	map = parse_map(map_file);
	if (!map || !map->grid || get_error())
		return (free(map), 0);
	screen->map = map;
	screen->map->p_x = get_player_pos(map->grid, 'x');
	screen->map->p_y = get_player_pos(map->grid, 'y');
	screen->map->p_color = PLAYER_COLOR;
	printf("\33[1;32mMap loaded successfully!\33[0m\n");
	
	// INIT THE SCREEN
	screen->mlx = mlx_init();
	screen->mlx_win = mlx_new_window(screen->mlx, WIDTH, HEIGHT, "CUBE3D");
	screen->img = mlx_new_image(screen->mlx, WIDTH, HEIGHT);
	screen->addr = mlx_get_data_addr(screen->img, &screen->bits_per_pixel,
			&screen->line_length, &screen->endian);
	mlx_put_image_to_window(screen->mlx, screen->mlx_win, screen->img, 0, 0);
	return (1);
}
