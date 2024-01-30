/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:29:09 by amirloup          #+#    #+#             */
/*   Updated: 2024/01/30 15:49:56 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_mem(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*ft_strncpy(char *s1, char *s2, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < n && s2[i])
	{
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

// void	fill_tab(int i, int j, char **tab, char *s)
// {
// 	int	k;

// 	k = 0;
// 	tab[k] = (char *)malloc(sizeof(char) * ((i - j + 1)));
// 	if (!tab[k])
// 		return (free(tab[k]));
// 	ft_strncpy(tab[k++], &s[j], i - j);
// }

char	**ft_split(char *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	k = 0;
	tab = (char **)malloc(sizeof(char *) * (count_w(s, c) + 1));
	if (!tab)
		return (free_mem(tab), NULL);
	while (s[i])
	{
		while (s[i] && (s[i] == c))
			i++;
		j = i;
		while (s[i] && (s[i] != c))
			i++;
		if (i > j)
			// fill_tab(i, j, tab, s);
		{
			tab[k] = (char *)malloc(sizeof(char) * ((i - j + 1)));
			if (!tab[k])
				return (free(tab[k]), NULL);
			ft_strncpy(tab[k++], &s[j], i - j);
		}
	}
	tab[k] = NULL;
	return (tab);
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
