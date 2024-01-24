/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:18:53 by amirloup          #+#    #+#             */
/*   Updated: 2023/10/23 09:27:49 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*d;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	d = (char *)malloc((len + 1) * sizeof(char));
	if (d == NULL)
		return (NULL);
	while (i < len)
	{
		d[i] = s[i + start];
		i++;
	}	
	d[i] = '\0';
	return (d);
}
