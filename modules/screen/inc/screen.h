/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 07:06:13 by hramaros          #+#    #+#             */
/*   Updated: 2025/01/30 12:57:17 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H

# include "libft.h"
# include "maps.h"
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>

// WIDTH AND HEIGHT OF THE WINDOW
# define WIDTH 1920
# define HEIGHT 1080
# define PIXEL_SIZE 10

// KEYS NUMBERS
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define KEY_EXIT 17

// SIZE
# define PLAYER_SIZE 20
# define SQUARE_SIZE 100

typedef struct s_screen
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_map	*map;
}			t_screen;

// UTILS
void		free_screen(t_screen *screen);
int			handle_keypress(int keycode, t_screen *screen);
void		cube_hook(t_screen *screen);
int			data_init(t_screen *screen, char *map_file);

// KEYS
int			handle_exit(t_screen *screen);
int			handle_key(int key, t_screen *screen);

// DRAW
void		my_mlx_pixel_put(t_screen *screen, int x, int y, int color);
void		draw_square(t_screen *screen, int size, int p_x, int p_y,
				int color);
void		put_black_screen(t_screen *screen);
void		draw_map_grid(t_screen *screen);
void		draw_map_player(t_screen *screen);
void		draw_map(t_screen *screen);

#endif
