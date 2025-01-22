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
	cube_hook(&screen);
	mlx_loop(screen.mlx);
	printf("Here\n");
	return (0);
}
