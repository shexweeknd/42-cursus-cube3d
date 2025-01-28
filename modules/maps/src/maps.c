/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grids.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:18:02 by hramaros          #+#    #+#             */
/*   Updated: 2025/01/27 14:03:00 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"

int	is_valid_grid(char **grid, size_t line_len)
{
	if (is_newline(grid))
		return (0);
	if (!is_always_one(grid[0]) || !is_always_one(grid[line_len - 1]))
		return (0);
	if (!is_closed(grid, line_len))
		return (0);
	if (is_forbidden_char(grid))
		return (0);
	return (1);
}

// TODO
size_t	get_max_line_size(char **grid)
{
	size_t	i;
	size_t	max_len;
	size_t	curr_len;

	i = 0;
	max_len = 0;
	while (grid[i])
	{
		curr_len = ft_strlen(grid[i]);
		if (curr_len > max_len)
			max_len = curr_len;
		i++;
	}
	return (max_len);
}

char	**retrieve_grid(char *file, size_t line_len)
{
	int		fd;
	int		i;
	char	**result;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (set_error(err_file_open), NULL);
	line = get_first_grid_line(fd);
	result = malloc(sizeof(char *) * (line_len + 1));
	if (!result)
		return (set_error(err_malloc), NULL);
	i = 0;
	while (line)
	{
		result[i++] = line;
		line = get_next_line(fd);
	}
	result[i] = NULL;
	return (close(fd), result);
}

int	get_player_pos(char **grid, char axis)
{
	int	i;
	int	j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == 'N' || grid[i][j] == 'S' || grid[i][j] == 'E'
				|| grid[i][j] == 'W')
			{
				if (axis == 'x')
					return (j);
				else if (axis == 'y')
					return (i);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

typedef struct s_pos
{
	size_t	x;
	size_t	y;
}			t_pos;

void	flood_canva(char **grid, size_t line_len, t_pos curr)
{
	if (curr.x <= 0 || curr.y <= 0 || curr.y >= line_len - 1
		|| grid[curr.y][curr.x] == '\n' || grid[curr.y][curr.x] == '\0'
		|| grid[curr.y][curr.x] == '1' || grid[curr.y][curr.x] == 'F')
		return ;
	if (grid[curr.y][curr.x] == ' ')
	{
		set_error(err_grid_format);
		return ;
	}
	grid[curr.y][curr.x] = 'F';
	if (get_error())
		return ;
	flood_canva(grid, line_len, (t_pos){curr.x - 1, curr.y});
	flood_canva(grid, line_len, (t_pos){curr.x + 1, curr.y});
	flood_canva(grid, line_len, (t_pos){curr.x, curr.y - 1});
	flood_canva(grid, line_len, (t_pos){curr.x, curr.y + 1});
}

void	fill_canva(t_map *map, size_t line_len)
{
	char	**copy;
	size_t	i;

	copy = malloc(sizeof(char *) * (line_len + 1));
	if (!copy)
		return (set_error(err_malloc));
	i = 0;
	while (i < line_len)
	{
		copy[i] = ft_strdup(map->grid[i]);
		i++;
	}
	copy[i] = NULL;
	flood_canva(copy, line_len, (t_pos){map->p_x, map->p_y});
	printf("The copied map is: \n");
	print_grid(copy);
	free_grid(copy);
	return ;
}

char	**squarify(char **grid, size_t line_len)
{
	char	**result;
	size_t	i;
	size_t	max_len;

	if (!grid)
		return (NULL);
	max_len = get_max_line_size(grid);
	if (max_len == 0)
		return (set_error(err_grid_format), free_grid(grid), NULL);
	result = malloc(sizeof(char *) * (line_len + 1));
	if (!result)
		return (free_grid(grid), NULL);
	i = 0;
	while (grid[i])
	{
		if (ft_strlen(grid[i]) < max_len)
		{
			grid[i][ft_strlen(grid[i]) - 1] = '\0';
			result[i] = ft_strjoin(grid[i], ft_strnew(max_len
						- ft_strlen(grid[i]), ' '));
			result[i][max_len - 1] = '\n';
		}
		else
			result[i] = ft_strdup(grid[i]);
		i++;
	}
	result[i - 1][max_len - 1] = '\0';
	result[i] = NULL;
	return (free_grid(grid), result);
}

// TODO
t_map	*parse_map(char *file)
{
	size_t	line_len;
	t_map	*result;
	char	**grid_tmp;

	result = NULL;
	line_len = count_grid_line(file);
	if (line_len < 3)
		return (set_error(err_grid_format), NULL);
	grid_tmp = squarify(retrieve_grid(file, line_len), line_len);
	if (!grid_tmp)
		return (set_error(err_malloc), NULL);
	if (!is_valid_grid(grid_tmp, line_len))
		return (set_error(err_grid_format), free_grid(grid_tmp), NULL);
	result = malloc(sizeof(t_map));
	if (!result)
		return (set_error(err_malloc), free_grid(grid_tmp), NULL);
	result->grid = grid_tmp;
	result->p_x = get_player_pos(grid_tmp, 'x');
	result->p_y = get_player_pos(grid_tmp, 'y');
	fill_canva(result, line_len);
	if (get_error())
		return (free_grid(grid_tmp), free(result), NULL);
	return (result);
}
