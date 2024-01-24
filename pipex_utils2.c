/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:06:37 by amirloup          #+#    #+#             */
/*   Updated: 2024/01/24 14:36:24 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**split_argv(char **argv, int n)
{
	char	**cmd;

	if (argv[n][0] == '/')
		cmd = full_cmd(argv[n]);
	else if (ft_strncmp(argv[n], "awk '", 5) == 0)
		cmd = ft_split(argv[n], '\'');
	else if (ft_strncmp(argv[n], "awk \"", 5) == 0)
		cmd = ft_split(argv[n], '"');
	else
		cmd = ft_split(argv[n], ' ');
	return (cmd);
}
