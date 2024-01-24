/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:06:35 by amirloup          #+#    #+#             */
/*   Updated: 2023/10/22 09:12:15 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void*s2, size_t n)
{
	size_t				i;
	const unsigned char	*us1;
	const unsigned char	*us2;

	i = 0;
	us1 = (const unsigned char *)s1;
	us2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (us1[i] != us2[i])
			return ((int)(us1[i] - us2[i]));
		i++;
		if (i == n)
			return (0);
	}
	return ((int)(us1[i] - us2[i]));
}
