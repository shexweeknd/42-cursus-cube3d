/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:17:37 by hramaros          #+#    #+#             */
/*   Updated: 2025/01/27 11:43:45 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPS_H
# define MAPS_H

# include "errors.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>

char	**parse_map(char *file);
void	print_map(char **map);
void	free_map(char **map);

#endif
