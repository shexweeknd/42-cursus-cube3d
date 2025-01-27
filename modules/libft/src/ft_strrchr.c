/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:12:38 by hramaros          #+#    #+#             */
/*   Updated: 2025/01/27 10:12:41 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*res;

	if ((char)c == '\0')
	{
		while (*str++)
			;
		return ((char *)(--str));
	}
	res = 0;
	while (*str)
		if (*str++ == (char)c)
			res = (char *)(str - 1);
	return (res);
}