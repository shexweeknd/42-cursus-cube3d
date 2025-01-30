/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:17:37 by hramaros          #+#    #+#             */
/*   Updated: 2025/01/30 13:25:47 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPS_H
# define MAPS_H

# include "errors.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>

# define PLAYER_COLOR 0xFF0000

typedef struct s_map
{
	char	**grid;
	int		map_width;
	int		map_height;
	int		bloc_size;
	int		player_size;
	int		p_x;
	int		p_y;
	int		p_color;
	int		y_len;
	int		x_len;
}			t_map;

typedef struct s_pos
{
	size_t	x;
	size_t	y;
}			t_pos;

// ENTRY POINT
t_map		*parse_map(char *file);

// UTILS
void		print_grid(char **grid);
void		free_grid(char **grid);
size_t		count_grid_line(char *file);
char		**squarify(char **grid, size_t line_len);

// HOOKS
int			is_always_one(char *line);
int			is_newline(char **grid);
int			is_closed(char **grid, size_t line_len);
int			is_forbidden_char(char **grid);

// VALIDATOR
int			validate_grid(char **grid, size_t line_len);

// GETTERS
char		*get_first_grid_line(int fd);
int			get_player_pos(char **grid, char axis);
size_t		get_max_line_size(char **grid);

// FLOODER
void		flood_canva(char **grid, size_t line_len, t_pos curr);
void		fill_canva(t_map *map, size_t line_len);

#endif
