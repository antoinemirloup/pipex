/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:00:37 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/01 11:21:37 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	first_command(t_pipex *p, char **argv, char **env)
{
	int		fd_in;

	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		heredoc(p, argv, env);
	else
	{
		fd_in = open(argv[1], O_RDONLY, 0777);
		if (fd_in == -1)
			error_exit("Error while opening infile!\n");
		if (dup2(fd_in, STDIN_FILENO) == -1)
			exit ((close(p->fd[0]), close(p->fd[1]), \
			close(fd_in), EXIT_FAILURE));
		if (dup2(p->fd[1], STDOUT_FILENO) == -1)
			exit ((close(p->fd[0]), close(p->fd[1]), \
			close(fd_in), EXIT_FAILURE));
		close(p->fd[0]);
		close(p->fd[1]);
		close(fd_in);
		exec(argv, env, p->n);
	}
}

void	mid_command(t_pipex *p, char **argv, char **env)
{
	if (dup2(p->fd[1], STDOUT_FILENO) == -1)
		exit ((close(p->fd[0]), close(p->fd[1]), EXIT_FAILURE));
	close(p->fd[0]);
	close(p->fd[1]);
	exec(argv, env, p->n);
}

void	last_command(t_pipex *p, char **argv, char **env)
{
	int	fd_out;

	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		fd_out = open(argv[p->n + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd_out = open(argv[p->n + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out == -1)
		error_exit("Error while opening infile!\n");
	if (dup2(fd_out, STDOUT_FILENO) == -1)
		exit ((close(fd_out), EXIT_FAILURE));
	close(fd_out);
	exec(argv, env, p->n);
}

void	commands(t_pipex p, char **argv, int argc, char **env)
{
	if (p.n == 2)
		first_command(&p, argv, env);
	else if (p.n > 2 && p.n < argc - 2)
		mid_command(&p, argv, env);
	else if (p.n == argc - 2)
		last_command(&p, argv, env);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	p;
	int		status;

	status = 0;
	if (argc < 5)
		error_exit("Wrong format!\n");
	p.n = 2;
	while (p.n < argc - 1)
	{
		if (pipe(p.fd) == -1)
			exit (EXIT_FAILURE);
		p.pid = fork();
		if (p.pid == -1)
			exit ((close(p.fd[0]), close(p.fd[1]), EXIT_FAILURE));
		if (p.pid == 0)
			commands(p, argv, argc, env);
		else
		{
			dup2(p.fd[0], STDIN_FILENO);
			close(p.fd[0]);
			close(p.fd[1]);
			p.n++;
		}
	}
	exit_end(&p, status);
}
