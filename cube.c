/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:33:07 by hramaros          #+#    #+#             */
/*   Updated: 2025/01/30 13:20:55 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <fcntl.h>
#include <stdio.h>
#include <time.h>

int	main(int ac, char **av)
{
	t_screen	screen;

	verify_args(ac, av);
	if (get_error())
		return (print_error(), 1);
	if (!data_init(&screen, av[1]))
		return (print_error(), 1);
	print_grid(screen.map->grid);
	draw_map(&screen);
	sleep(30);
	return (free_screen(&screen), 0);
	// screen.p_x = WIN_WIDTH / 4;
	// screen.p_y = WIN_HEIGHT / 4;
	// screen.p_color = PLAYER_COLOR;
	// cube_hook(&screen);
	// draw_map(&screen, screen.map);
	// draw_square(&screen, PLAYER_SIZE, screen.p_x, screen.p_y,
	// screen.p_color);
	// mlx_put_image_to_window(screen.mlx, screen.mlx_win, screen.img, 0, 0);
	// mlx_key_hook(screen.mlx_win, handle_keypress, &screen);
	// mlx_loop(screen.mlx);
	return (0);
}
