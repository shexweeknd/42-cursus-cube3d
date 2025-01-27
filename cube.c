/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:33:07 by hramaros          #+#    #+#             */
/*   Updated: 2025/01/27 11:44:27 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	t_screen	screen;
	char		**map;

	verify_args(ac, av);
	if (get_error())
		return (print_error(), 1);
	map = parse_map(av[1]);
	if (!map || get_error())
		return (print_error(), 1);
	printf("\033[0;32mMap parsed successully\033[0m\n");
	return (print_map(map), free_map(map), 0);
	data_init(&screen);
	screen.p_x = WIDTH / 4;
	screen.p_y = HEIGHT / 4;
	screen.p_color = 0x00FF00;
	cube_hook(&screen);
	draw_map(&screen, screen.map);
	draw_square(&screen, PLAYER_SIZE, screen.p_x, screen.p_y, screen.p_color);
	mlx_put_image_to_window(screen.mlx, screen.mlx_win, screen.img, 0, 0);
	mlx_key_hook(screen.mlx_win, handle_keypress, &screen);
	mlx_loop(screen.mlx);
	return (0);
}
