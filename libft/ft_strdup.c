/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:16:47 by amirloup          #+#    #+#             */
/*   Updated: 2023/10/22 14:42:40 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*d;

	i = 0;
	j = 0;
	while (s[i])
		i++;
	d = malloc((i + 1) * sizeof(char));
	if (d == NULL)
		return (NULL);
	while (s[j] && j < i)
	{
		d[j] = s[j];
		j++;
	}
	d[j] = '\0';
	return (d);
}
