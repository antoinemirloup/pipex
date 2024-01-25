/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:29:30 by amirloup          #+#    #+#             */
/*   Updated: 2024/01/25 13:29:43 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
	if (!tab)
		exit ((free_tab(tab), EXIT_FAILURE));
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
	if (!path)
		exit ((free_tab(path), EXIT_FAILURE));
	path[0] = ft_strjoin(path[0], "/");
	if (!path[0])
		exit ((free(path[0]), EXIT_FAILURE));
	path[0] = ft_strjoin(path[0], argv[0]);
	if (!path[0])
		exit ((free(path[0]), EXIT_FAILURE));
	return (path);
}
