/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:08:48 by amirloup          #+#    #+#             */
/*   Updated: 2024/01/17 17:09:51 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(char **env)
{
	int		i;
	char	**tab;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	tab = ft_split(&env[i][5], ':');
	i = 0;
	while (tab[i])
	{
		tab[i] = ft_strjoin(tab[i], "/");
		i++;
	}
	return (tab);
}

int	main(int argc, char **argv, char **env)
{
	int		i;
	char	**path;

	i = 0;
	(void)argc;
	(void)argv;
	path = find_path(env);
	while (path[i])
	{
		printf("%s\n", path[i]);
		free(path[i]);
		i++;
	}
	free(path);
}
