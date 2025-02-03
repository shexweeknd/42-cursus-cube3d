/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:31:35 by hrazafis          #+#    #+#             */
/*   Updated: 2025/02/03 11:50:16 by hramaros         ###   ########.fr       */
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
	mlx_destroy_image(screen->mlx, screen->img);
	screen->img = mlx_new_image(screen->mlx, WIN_WIDTH, WIN_HEIGHT);
	put_black_screen(screen);
	draw_map_grid(screen);
	if ((key == 13 || key == 119) && is_valid_move(screen->map, 'w'))
		screen->map->p_y -= PIXEL_SIZE;
	if ((key == 0 || key == 97) && is_valid_move(screen->map, 'a'))
		screen->map->p_x -= PIXEL_SIZE;
	if ((key == 1 || key == 115) && is_valid_move(screen->map, 's'))
		screen->map->p_y += PIXEL_SIZE;
	if ((key == 2 || key == 100) && is_valid_move(screen->map, 'd'))
		screen->map->p_x += PIXEL_SIZE;
	draw_map_player(screen);
	mlx_put_image_to_window(screen->mlx, screen->mlx_win, screen->img, 0, 0);
	return (0);
}

int	data_init(t_screen *screen, char *map_file)
{
	screen->map = parse_map(map_file);
	if (!screen->map || !screen->map->grid || get_error())
		return (free(screen->map), 0);
	screen->map->map_height = WIN_HEIGHT / 4;
	screen->map->map_width = WIN_WIDTH / 6;
	screen->map->p_color = PLAYER_COLOR;
	screen->map->bloc_size = screen->map->map_height / screen->map->y_len;
	screen->map->player_size = screen->map->bloc_size / 4;
	screen->map->p_x = get_player_pos(screen->map->grid, 'x')
		* screen->map->bloc_size + screen->map->bloc_size / 2
		- screen->map->player_size / 2;
	screen->map->p_y = get_player_pos(screen->map->grid, 'y')
		* screen->map->bloc_size + screen->map->bloc_size / 2
		- screen->map->player_size / 2;
	printf("\33[1;32mMap loaded successfully!\33[0m\n");
	screen->mlx = mlx_init();
	screen->mlx_win = mlx_new_window(screen->mlx, WIN_WIDTH, WIN_HEIGHT,
			"CUBE3D");
	screen->img = mlx_new_image(screen->mlx, WIN_WIDTH, WIN_HEIGHT);
	screen->addr = mlx_get_data_addr(screen->img, &screen->bits_per_pixel,
			&screen->line_length, &screen->endian);
	mlx_put_image_to_window(screen->mlx, screen->mlx_win, screen->img, 0, 0);
	return (1);
}
