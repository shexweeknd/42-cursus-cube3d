/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 07:06:13 by hramaros          #+#    #+#             */
/*   Updated: 2025/02/11 10:55:42 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H

# include "events.h"
# include "libft.h"
# include "maps.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

// WIN_WIDTH AND WIN_HEIGHT OF THE WINDOW
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define PIXEL_SIZE 2

// KEYS NUMBERS
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define KEY_EXIT 17

// SIZE
# define SQUARE_SIZE 1

// constant
# define M_PI 3.14159265358979323846
# define RAY_DIST 1000

// MOVEMENTS
# define ROTATION_SPEED 3

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
void		cube_hook(t_screen *screen);
int			data_init(t_screen *screen, char *map_file);

// KEYS
int			handle_exit(t_screen *screen);
int			handle_keypress(int key, t_screen *screen);
int			handle_keyrelease(int key);

// DRAW
void		my_mlx_pixel_put(t_screen *screen, int x, int y, int color);
void		draw_square(t_screen *screen, int pos_x, int pos_y, char cmd);
void		put_black_screen(t_screen *screen);
void		draw_map_grid(t_screen *screen);
void		draw_map_player(t_screen *screen);
void		draw_map(t_screen *screen);

// DRAW UTILS
void		config_size_color(int *size, int *color, char cmd, t_map *map);
void		draw_map_bloc(t_screen *screen, int i, int j, char **grid);
void		draw_line(t_screen *screen, double x1, double y1);
void		raycast(t_screen *screen);

// KEYS UTILS
int			is_valid_move(t_map *map, char cmd);
void		move_player(t_map *map);
void		rotate_player(t_map *map);
int			update_frame(t_screen *screen);
int			*_player_direction(int cmd, int value);
char		_is_rotating(int cmd);

#endif
