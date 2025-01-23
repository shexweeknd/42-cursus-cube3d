/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazafis <hrazafis@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:44:59 by hrazafis          #+#    #+#             */
/*   Updated: 2025/01/23 15:45:02 by hrazafis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	int		ret;

	i = 0;
	sign = 1;
	ret = 0;
	while (((nptr[i] <= 13 && nptr[i] >= 9) || nptr[i] == ' ') && nptr[i])
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] && (nptr[i] <= '9' && nptr[i] >= '0'))
	{
		ret *= 10;
		ret += (nptr[i] - '0');
		i++;
	}
	return (ret * sign);
}
