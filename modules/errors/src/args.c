/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:36:19 by hramaros          #+#    #+#             */
/*   Updated: 2025/01/27 10:36:28 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

static int	verify_extension(char *file, char *ext)
{
	int	i;
	int	file_size;

	file_size = ft_strlen(file);
	if (!file_size)
		return (0);
	if (file_size < 5)
		return (0);
	i = file_size - 1;
	while (file[i] == ext[i - file_size + 4] && i > file_size - 5)
		i--;
	if (i == file_size - 5 && file[file_size - 5] != '/')
		return (1);
	return (0);
}

void	verify_args(int ac, char **av)
{
	if (ac != 2)
		set_error(args_number);
	else if (!verify_extension(av[1], ".cub"))
		set_error(cube_extension);
}
