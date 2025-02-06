/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:31:35 by hrazafis          #+#    #+#             */
/*   Updated: 2025/02/06 15:26:46 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

void	cube_hook(t_screen *screen)
{
	mlx_hook(screen->mlx_win, ON_KEYPRESS, (1L << 0), handle_keypress, screen);
	mlx_hook(screen->mlx_win, ON_KEYRELEASE, (1L << 1), handle_keyrelease,
		screen);
	mlx_hook(screen->mlx_win, ON_DESTROY, (1L << 17), handle_exit, screen);
	mlx_loop_hook(screen->mlx, update_frame, screen);
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
