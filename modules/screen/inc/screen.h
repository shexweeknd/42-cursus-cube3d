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

// KEYS NUMBERS
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define KEY_EXIT 17

typedef struct s_screen
{
	void	*mlx;
	void	*mlx_win;
}			t_screen;

void		free_screen(t_screen *screen);
int			handle_exit(t_screen *screen);
int			handle_key(int key, t_screen *screen);
void		cube_hook(t_screen *screen);

#endif
