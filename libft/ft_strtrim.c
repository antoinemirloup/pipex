/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 10:41:47 by amirloup          #+#    #+#             */
/*   Updated: 2023/10/22 13:47:58 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*s;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	if (start >= end)
		return (ft_strdup(""));
	s = (char *)malloc((end - start + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	while (start < end)
		s[i++] = s1[start++];
	s[i] = '\0';
	return (s);
}
