/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:25:14 by amirloup          #+#    #+#             */
/*   Updated: 2023/10/20 10:07:09 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*us;
	unsigned char		uc;

	us = (const unsigned char *)s;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (us[i] == uc)
			return ((void *)&us[i]);
		i++;
	}
	return (NULL);
}
