/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:31:35 by hrazafis          #+#    #+#             */
/*   Updated: 2025/02/06 14:43:47 by hramaros         ###   ########.fr       */
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

int	handle_keypress(int key, t_screen *screen)
{
	printf("Key: %d\n", key);
	if (key == 53 || key == 65307)
		handle_exit(screen);
	if (key == 119)
		_player_direction('w', 1);
	else if (key == 97)
		_player_direction('a', 1);
	else if (key == 115)
		_player_direction('s', 1);
	else if (key == 100)
		_player_direction('d', 1);
	move_player(screen->map);
	mlx_destroy_image(screen->mlx, screen->img);
	screen->img = mlx_new_image(screen->mlx, WIN_WIDTH, WIN_HEIGHT);
	put_black_screen(screen);
	draw_map_grid(screen);
	draw_map_player(screen);
	mlx_put_image_to_window(screen->mlx, screen->mlx_win, screen->img, 0, 0);
	return (0);
}

int handle_keyrelease(int key)
{
	if (key == 119)
		_player_direction('w', 0);
	else if (key == 97)
		_player_direction('a', 0);
	else if (key == 115)
		_player_direction('s', 0);
	else if (key == 100)
		_player_direction('d', 0);
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
