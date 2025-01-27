/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:17:37 by hramaros          #+#    #+#             */
/*   Updated: 2025/01/27 14:10:47 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPS_H
# define MAPS_H

# include "errors.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_map
{
	char	**grid;
	int		x;
	int		y;
}			t_map;

t_map		*parse_map(char *file);
void		print_grid(char **grid);
void		free_grid(char **grid);

char		*get_first_grid_line(int fd);
size_t		count_grid_line(char *file);

int			is_always_one(char *line);
int			is_newline(char **grid);
int			is_closed(char **grid, size_t line_len);
int			is_forbidden_char(char **grid);

#endif
