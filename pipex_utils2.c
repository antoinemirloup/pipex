/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:31:35 by amirloup          #+#    #+#             */
/*   Updated: 2024/01/23 14:36:17 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**awk_cmd(char **argv, int n, char c)
{
	int		i;
	char	**cmd;
	char	**tab;

	i = 0;
	cmd = (char **)malloc(sizeof(char *) * 3);
	tab = ft_split(argv[n], c);
	while (tab[i])
		i++;
	cmd[0] = "awk";
	cmd[1] = tab[i - 1];
	cmd[2] = NULL;
	return (cmd);
}
