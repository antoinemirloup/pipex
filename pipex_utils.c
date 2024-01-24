/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:14:51 by amirloup          #+#    #+#             */
/*   Updated: 2024/01/24 12:08:56 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tab(char **tab)
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

void	exit_end(int status)
{
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	else
		exit(EXIT_FAILURE);
}

void	error_exit(char *s)
{
	ft_putstr_fd(s, 2);
	exit (EXIT_FAILURE);
}

char	**full_cmd(char *argv)
{
	char	**tab;
	char	**cmd;
	int		i;

	tab = ft_split(argv, '/');
	i = 0;
	while (tab[i])
		i++;
	cmd = &tab[i - 1];
	return (cmd);
}

char	**path_script(char **argv)
{
	char	**path;

	path = ft_split(".", ' ');
	path[0] = ft_strjoin(path[0], "/");
	path[0] = ft_strjoin(path[0], argv[0]);
	return (path);
}
