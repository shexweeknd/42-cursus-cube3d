/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazafis <hrazafis@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:33:07 by hramaros          #+#    #+#             */
/*   Updated: 2025/01/23 14:59:10 by hrazafis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <stdio.h>

int	main(void)
{
	t_screen	screen;

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
