/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 10:12:35 by amirloup          #+#    #+#             */
/*   Updated: 2024/01/30 15:08:24 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		i;
	size_t		j;
	char		*s;
	size_t		sizes1;
	size_t		sizes2;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	sizes1 = ft_strlen(s1);
	sizes2 = ft_strlen(s2);
	s = (char *)malloc((sizes1 + sizes2 + 1) * sizeof(char));
	if (!s)
		return (free(s), NULL);
	while (s1[i])
		s[j++] = s1[i++];
	i = 0;
	while (s2[i])
		s[j++] = s2[i++];
	s[j] = '\0';
	free(s1);
	return (s);
}
