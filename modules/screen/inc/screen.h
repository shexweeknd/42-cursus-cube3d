/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 07:06:13 by hramaros          #+#    #+#             */
/*   Updated: 2025/02/14 15:08:56 by hramaros         ###   ########.fr       */
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
# define WIN_WIDTH 1080
# define WIN_HEIGHT 600
# define STEP_SIZE 10

// KEYS NUMBERS
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define KEY_EXIT 17

// SIZE
# define BLOC_SIZE 128

// constant
# define M_PI 3.14159265358979323846
# define RAY_DIST 4000
# define RAY_DENSITY 1
# define RAYS_NBR 1000

// MOVEMENTS
# define ROTATION_SPEED 0.05

// COLORS
# define FLOOR_COLOR 0x202020
# define WALL_COLOR 0x808080
# define SKY_COLOR 0x87CEEB

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

typedef struct s_dim
{
	double	w;
	double	h;
}			t_dim;

// UTILS
void		free_screen(t_screen *screen);
void		cube_hook(t_screen *screen);
int			data_init(t_screen *screen, char *map_file);
double		get_scaling_factor(t_map *map);

// KEYS
int			handle_exit(t_screen *screen);
int			handle_keypress(int key, t_screen *screen);
int			handle_keyrelease(int key);

// DRAW
void		my_mlx_pixel_put(t_screen *screen, int x, int y, int color);
void		put_black_screen(t_screen *screen);
void		draw_map_grid(t_screen *screen);
void		draw_map_player(t_screen *screen);
void		draw_map(t_screen *screen);

// DRAW UTILS
void		draw_line(t_screen *screen, double ray_angle, int color);
void		trace_rays(t_screen *screen, int dim);

// KEYS UTILS
void		config_next_coord(t_map *map, double *dir_x, double *dir_y,
				int dim);
void		move_player(t_map *map, int dim);
void		rotate_player(t_map *map);
int			update_frame(t_screen *screen);
int			*_player_direction(int cmd, int value);
char		_is_rotating(int cmd);
int			is_wall(t_map *map, double x_dest, double y_dest, int dim);
int			is_adjacent_wall(t_map *map, double x, double y, int dim);
void		draw_bloc_square(t_screen *screen, int pos_x, int pos_y, char cmd);
void		draw_map_bloc(t_screen *screen, int i, int j, char **grid);

// 3D UTILS
void		draw_3d_ray(t_screen *screen, t_pos pos, double distance);
void		draw_3d_rect(t_screen *screen, t_pos pos, t_dim dim);
double		get_wall_width(void);
void		draw_skyline(t_screen *screen);

#endif
