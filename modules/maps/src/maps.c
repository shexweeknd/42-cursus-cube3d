/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:18:02 by hramaros          #+#    #+#             */
/*   Updated: 2025/01/27 11:59:35 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"

int	is_always_one(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	while (line[i] == '1')
		i++;
	if (line[i] == '\0')
		return (1);
	return (0);
}

char	*get_first_map_line(int fd)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (line[i] == ' ')
			i++;
		if (line[i] == '1')
			break ;
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

size_t	count_map_line(char *file)
{
	int		fd;
	char	*line;
	size_t	count;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (set_error(err_map_open), 0);
	line = get_first_map_line(fd);
	count = 0;
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

// TODO
int	is_valid_map(char **map)
{
	(void)map;
	return (0);
}

char	**retrieve_map(char *file, size_t line_len)
{
	int		fd;
	int		i;
	char	**result;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (set_error(err_map_open), NULL);
	line = get_first_map_line(fd);
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

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		printf("%s", map[i++]);
	printf("\n");
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

// TODO
char	**parse_map(char *file)
{
	char	**result;
	char	**map_tmp;
	size_t	line_len;

	result = NULL;
	line_len = count_map_line(file);
	if (line_len == 0)
		return (set_error(err_map_format), NULL);
	map_tmp = retrieve_map(file, line_len);
	if (!map_tmp)
		return (set_error(err_malloc), NULL);
	result = map_tmp;
	return (result);
}
