/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:56:50 by hramaros          #+#    #+#             */
/*   Updated: 2025/01/28 12:42:35 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

static int	_error(int new_error, int change)
{
	static int	error = 0;

	if (change)
		error = new_error;
	return (error);
}

int	get_error(void)
{
	return (_error(0, 0));
}

void	set_error(int new_error)
{
	_error(new_error, 1);
}

void	print_error(void)
{
	int	error;

	error = get_error();
	if (error == err_args_nbr)
		printf("\033[0;31mError: Wrong number of arguments\033[0m\n");
	else if (error == err_file_extension)
		printf("\033[0;31mError: Wrong file extension\033[0m\n");
	else if (error == err_file_open)
		printf("\033[0;31mError: Could not open map file\033[0m\n");
	else if (error == err_file_empty)
		printf("\033[0;31mError: Empty map file\033[0m\n");
	else if (error == err_malloc)
		printf("\033[0;31mError: Memory allocation failed\033[0m\n");
	else if (error == err_grid_format)
		printf("\033[0;31mError: Invalid map format\033[0m\n");
	else if (error == err_hook_instruction)
		printf("\033[0;31mError: Invalid hook instruction\033[0m\n");
}
