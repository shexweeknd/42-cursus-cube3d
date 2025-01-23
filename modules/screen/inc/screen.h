/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libscreen.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananarivo.mg>  #+#  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-22 07:06:13 by hramaros          #+#    #+#             */
/*   Updated: 2025-01-22 07:06:13 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSCREEN_H
# define LIBSCREEN_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>

// WIDTH AND HEIGHT OF THE WINDOW
# define WIDTH 720
# define HEIGHT 480
# define PIXEL_SIZE 10

// KEYS NUMBERS
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define KEY_EXIT 17

typedef struct s_screen
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		p_x;
	int		p_y;
	int		p_color;
}			t_screen;

void		free_screen(t_screen *screen);
int			handle_exit(t_screen *screen);
int			handle_key(int key, t_screen *screen);
void		cube_hook(t_screen *screen);
void		draw_player(t_screen *screen);
int			handle_keypress(int keycode, t_screen *screen);
void		my_mlx_pixel_put(t_screen *screen, int x, int y, int color);

#endif
