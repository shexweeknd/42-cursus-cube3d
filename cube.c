/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:33:07 by hramaros          #+#    #+#             */
/*   Updated: 2025/02/14 13:36:43 by hramaros         ###   ########.fr       */
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
	cube_hook(&screen);
	mlx_loop(screen.mlx);
	return (free_screen(&screen), 0);
}
