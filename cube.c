/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananarivo.mg>  #+#  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-22 06:25:01 by hramaros          #+#    #+#             */
/*   Updated: 2025-01-22 06:25:01 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <stdio.h>

int	main(void)
{
	t_screen	screen;

	screen.mlx = mlx_init();
	if (!screen.mlx)
		return (write(1, "Error\n", 6), 0);
	screen.mlx_win = mlx_new_window(screen.mlx, WIDTH, HEIGHT, "CUBE3D");
	if (!screen.mlx_win)
		return (write(1, "Error\n", 6), 0);
	screen.p_x = WIDTH / 2;
	screen.p_y = HEIGHT / 2;
	screen.p_color = 0x00FF00;
	cube_hook(&screen);
	draw_player(&screen);
	mlx_key_hook(screen.mlx_win, handle_keypress, &screen);
	mlx_loop(screen.mlx);
	return (0);
}
