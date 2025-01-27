/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:57:19 by hramaros          #+#    #+#             */
/*   Updated: 2025/01/27 10:37:32 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "libft.h"
# include <stdio.h>

enum	e_error
{
	args_number = -1,
	cube_extension = -2,
};

int		get_error(void);
void	set_error(int new_error);
void	print_error(void);

// ARGUMENTS ERRORS HANDLING
void	verify_args(int ac, char **av);

#endif