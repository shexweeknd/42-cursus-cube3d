/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:18:02 by hramaros          #+#    #+#             */
/*   Updated: 2025/01/28 12:17:15 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size, char c)
{
	char	*result;
	size_t	i;

	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < size)
	{
		result[i] = c;
		i++;
	}
	result[size] = '\0';
	return (result);
}
