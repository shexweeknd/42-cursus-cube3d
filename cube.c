/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazafis <hrazafis@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:33:07 by hramaros          #+#    #+#             */
/*   Updated: 2025/01/23 16:04:34 by hrazafis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <fcntl.h>
#include <stdio.h>

char	**parse_map(char *file)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	fd = open(file, O_RDONLY);
	map = NULL;
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		i++;
		line = get_next_line(fd);
		free(line);
	}
	return (map);
}

int	main(int ac, char **av)
{
	t_screen	screen;

	if (ac != 2)
	{
		printf("Error\n");
		return (1);
	}
	parse_map(av[1]);
	return (0);
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
