/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:56:50 by hramaros          #+#    #+#             */
/*   Updated: 2025/01/27 10:10:09 by hramaros         ###   ########.fr       */
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
	if (error == args_number)
		printf("Error: Wrong number of Arguments\n");
	else if (error == cube_extension)
		printf("Error: Wrong file extension\n");
}
