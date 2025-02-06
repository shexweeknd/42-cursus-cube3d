/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:24:51 by hramaros          #+#    #+#             */
/*   Updated: 2025/02/06 15:25:09 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"

int	handle_exit(t_screen *screen)
{
	if (screen)
		free_screen(screen);
	exit(0);
	return (0);
}

int	handle_keypress(int key, t_screen *screen)
{
	if (key == 53 || key == 65307)
		handle_exit(screen);
	if (key == 119)
		_player_direction('w', 1);
	else if (key == 97)
		_player_direction('a', 1);
	else if (key == 115)
		_player_direction('s', 1);
	else if (key == 100)
		_player_direction('d', 1);
	return (0);
}

int	handle_keyrelease(int key)
{
	if (key == 119)
		_player_direction('w', 0);
	else if (key == 97)
		_player_direction('a', 0);
	else if (key == 115)
		_player_direction('s', 0);
	else if (key == 100)
		_player_direction('d', 0);
	return (0);
}
