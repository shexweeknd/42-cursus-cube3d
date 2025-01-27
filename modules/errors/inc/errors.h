/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:57:19 by hramaros          #+#    #+#             */
/*   Updated: 2025/01/27 14:04:26 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "libft.h"
# include <stdio.h>

enum	e_error
{
	err_args_nbr = 1,
	err_file_extension,
	err_file_open,
	err_file_empty,
	err_malloc,
	err_grid_format,
};

int		get_error(void);
void	set_error(int new_error);
void	print_error(void);

// ARGUMENTS ERRORS HANDLING
void	verify_args(int ac, char **av);

#endif