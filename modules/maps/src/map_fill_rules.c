/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill_rules.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:58:41 by hramaros          #+#    #+#             */
/*   Updated: 2025/01/27 14:52:49 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"

// void	flood_canva(char **grid, t_pos size, t_pos curr)
// {
// 	if (curr.x >= size.x || curr.y >= size.y || curr.x <= 0 || curr.y <= 0
// 		|| grid[curr.y][curr.x] == '1' || grid[curr.y][curr.x] == 'F')
// 		return ;
// 	grid[curr.y][curr.x] = 'F';
// 	flood_canva(grid, size, (t_pos){curr.x - 1, curr.y});
// 	flood_canva(grid, size, (t_pos){curr.x + 1, curr.y});
// 	flood_canva(grid, size, (t_pos){curr.x, curr.y - 1});
// 	flood_canva(grid, size, (t_pos){curr.x, curr.y + 1});
// }
