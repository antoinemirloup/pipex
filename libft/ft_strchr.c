/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:19:38 by amirloup          #+#    #+#             */
/*   Updated: 2023/10/20 14:25:48 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != (unsigned char)c)
	{
		if (s[i] == '\0')
			return ((char *)0);
		i++;
	}
	return ((char *)&s[i]);
}
