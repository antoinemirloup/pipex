/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:06:30 by amirloup          #+#    #+#             */
/*   Updated: 2023/10/19 15:46:16 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*us;
	unsigned char	uc;

	us = (unsigned char *)s;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		us[i] = uc;
		i++;
	}
	return (s);
}
