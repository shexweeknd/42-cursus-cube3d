/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:51:09 by hramaros          #+#    #+#             */
/*   Updated: 2025/01/28 12:51:20 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"

int	validate_grid(char **grid, size_t line_len)
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
