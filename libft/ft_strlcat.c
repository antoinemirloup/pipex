/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:28:59 by amirloup          #+#    #+#             */
/*   Updated: 2023/10/26 13:57:38 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	srcsize;
	size_t	dstsize;

	i = 0;
	j = 0;
	if (!dst && !size)
		return (0);
	srcsize = ft_strlen(src);
	dstsize = ft_strlen(dst);
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0' && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dstsize + srcsize);
}
