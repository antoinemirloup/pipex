/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:07:22 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/01 11:42:54 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	heredoc(t_pipex *p, char **argv)
{
	char	*s;

	s = get_next_line(0);
	while (1)
	{
		if ((ft_strncmp(argv[2], s, ft_strlen(argv[2])) == 0)
			&& s[ft_strlen(argv[2])] == '\n')
			exit ((close(p->fd[0]), close(p->fd[1]), free(s), 0));
		ft_putstr_fd(s, p->fd[1]);
		if (dup2(p->fd[1], STDOUT_FILENO) == -1)
			exit ((close(p->fd[0]), close(p->fd[1]), EXIT_FAILURE));
		free(s);
		s = get_next_line(0);
	}
}
