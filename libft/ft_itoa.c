/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:37:00 by amirloup          #+#    #+#             */
/*   Updated: 2023/10/26 15:17:38 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	is_n(int n)
{
	int	signe;

	signe = 0;
	if (n < 0)
		signe = 1;
	return (signe);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		signe;

	signe = is_n(n);
	if (signe == 1)
		n = -n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	s = malloc((size(n) + signe + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	s[size(n) + signe] = '\0';
	while (n)
	{
		s[size(n) + signe - 1] = '0' + (n % 10);
		n = n / 10;
	}
	if (signe == 1)
		s[0] = '-';
	return (s);
}
