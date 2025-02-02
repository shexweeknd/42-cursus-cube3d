/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:16:23 by hramaros          #+#    #+#             */
/*   Updated: 2025/01/28 12:21:34 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	total;
	size_t	i;
	size_t	j;

	total = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(sizeof(char) * (total + 1));
	if (!result)
		return (NULL);
	i = 0;
	if (s1 && s1[0])
	{
		j = 0;
		while (s1[j])
			result[i++] = s1[j++];
	}
	if (s2 && s2[0])
	{
		j = 0;
		while (s2[j])
			result[i++] = s2[j++];
	}
	result[total] = '\0';
	return (result);
}
