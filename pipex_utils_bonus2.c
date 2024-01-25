/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:30:10 by amirloup          #+#    #+#             */
/*   Updated: 2024/01/25 13:30:26 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**split_argv(char **argv, int n)
{
	char	**cmd;

	if (argv[n][0] == '/')
		cmd = full_cmd(argv[n]);
	else if (ft_strncmp(argv[n], "awk '", 5) == 0)
	{
		cmd = ft_split(argv[n], '\'');
		if (!cmd)
			exit ((free_tab(cmd), EXIT_FAILURE));
	}
	else if (ft_strncmp(argv[n], "awk \"", 5) == 0)
	{
		cmd = ft_split(argv[n], '"');
		if (!cmd)
			exit ((free_tab(cmd), EXIT_FAILURE));
	}
	else
	{
		cmd = ft_split(argv[n], ' ');
		if (!cmd)
			exit ((free_tab(cmd), EXIT_FAILURE));
	}
	return (cmd);
}

char	**trim_cmd(char **cmd, char **path)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		cmd[i] = ft_strtrim(cmd[i], "\"");
		if (!cmd[i])
			exit ((free_tab(path), free_tab(cmd), EXIT_FAILURE));
		cmd[i] = ft_strtrim(cmd[i], " ");
		if (!cmd[i])
			exit ((free_tab(path), free_tab(cmd), EXIT_FAILURE));
		i++;
	}
	return (cmd);
}

char	**join_path(char **path, char **argv)
{
	int	i;

	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		if (!path[i])
			exit ((free(path[i]), EXIT_FAILURE));
		path[i] = ft_strjoin(path[i], argv[0]);
		if (!path[i])
			exit ((free(path[i]), EXIT_FAILURE));
		i++;
	}
	return (path);
}
