/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:08:48 by amirloup          #+#    #+#             */
/*   Updated: 2024/01/17 15:14:44 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	find_path(char **env)
// {
// 	if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T')
		
// }

int	main(int argc, char **argv, char **env)
{
	int	i;

	i = 0;
	(void)argc;
	(void)argv;
	// if (argc != 5)
	// 	write(2, "Wrong format!\n", 14);
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}
