/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:29:09 by amirloup          #+#    #+#             */
/*   Updated: 2024/01/23 12:11:14 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	c_q(char *s, int i, int j)
{
	int	q;

	q = 0;
	while (j < i)
	{
		if (s[j] == '"' || s[j] == '\'')
			q++;
		j++;
	}
	return (q);
}

char	*ft_strncpy(char *s1, char *s2, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < n && s2[i])
	{
		if (s2[j] == '"' || s2[j] == '\'')
			j++;
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}

int	count_w(char *s, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			w++;
			while (s[i] && s[i] != c)
				i++;
		}
		else if (s[i] == c)
			i++;
	}
	return (w);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		j;
	int		k;
	int		wc;
	char	**out;

	i = 0;
	k = 0;
	wc = count_w(s, c);
	out = (char **)malloc(sizeof(char *) * (wc + 1));
	while (s[i])
	{
		while (s[i] && (s[i] == c))
			i++;
		j = i;
		while (s[i] && (s[i] != c))
			i++;
		if (i > j)
		{
			out[k] = malloc(sizeof(char) * ((i - j - c_q(s, i, j)) + 1));
			ft_strncpy(out[k++], &s[j], i - j - c_q(s, i, j));
		}
	}
	out[k] = NULL;
	return (out);
}

// int	main(int argc, char **argv)
// {
// 	char	c = ' ';
// 	int		i;
// 	char	**tab = ft_split(argv[1], c);
// 	i = 0;
// 	if (argc == 2)
// 	{
// 		while (tab[i])
// 		{
// 			printf("%s\n", tab[i]);
// 			free(tab[i]);
// 			i++;
// 		}
// 		free(tab);
// 	}
// }
