/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:00:37 by amirloup          #+#    #+#             */
/*   Updated: 2024/01/30 10:45:22 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**find_path(char **argv, char **env)
{
	int		i;
	char	**path;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	if (ft_strncmp(argv[0], "./", 2) == 0)
		path = path_script(argv);
	else
	{
		path = ft_split(&env[i][5], ':');
		if (!path)
			exit ((free_tab(path), EXIT_FAILURE));
		path = join_path(path, argv);
	}
	return (path);
}

void	exec(char **argv, char **env, int n)
{
	int		i;
	char	**path;
	char	**cmd;

	path = NULL;
	cmd = split_argv(argv, n);
	cmd = trim_cmd(cmd, path);
	i = 0;
	path = find_path(cmd, env);
	while (path[i])
	{
		if (access(path[i], F_OK) == 0)
			if (access(path[i], X_OK) == 0)
				execve(path[i], cmd, env);
		i++;
	}
	error_exit((free_tab(path), free_tab(cmd), "Command not found!\n"));
}

void	first_command(t_pipex *p, char **argv, char **env)
{
	int	fd_in;

	fd_in = open(argv[1], O_RDONLY, 0777);
	if (fd_in == -1)
		error_exit("Error while opening infile!\n");
	if (dup2(fd_in, STDIN_FILENO) == -1)
		exit ((close(p->fd[0]), close(p->fd[1]), close(fd_in), EXIT_FAILURE));
	if (dup2(p->fd[1], STDOUT_FILENO) == -1)
		exit ((close(p->fd[0]), close(p->fd[1]), close(fd_in), EXIT_FAILURE));
	close(p->fd[0]);
	close(p->fd[1]);
	close(fd_in);
	exec(argv, env, p->n);
}

void	command(t_pipex *p, char **argv, char **env)
{
	if (dup2(p->temp, STDIN_FILENO) == -1)
		exit ((close(p->fd[0]), close(p->fd[1]), EXIT_FAILURE));
	if (dup2(p->fd[1], STDOUT_FILENO) == -1)
		exit ((close(p->fd[0]), close(p->fd[1]), EXIT_FAILURE));
	close(p->fd[0]);
	close(p->fd[1]);
	exec(argv, env, p->n);
}

void	last_command(t_pipex *p, char **argv, char **env)
{
	int	fd_out;

	fd_out = open(argv[p->n + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out == -1)
		error_exit("Error while opening infile!\n");
	if (dup2(p->temp, STDIN_FILENO) == -1)
		exit ((close(fd_out), EXIT_FAILURE));
	if (dup2(fd_out, STDOUT_FILENO) == -1)
		exit ((close(fd_out), EXIT_FAILURE));
	close(fd_out);
	exec(argv, env, p->n);
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
		p.temp = p.fd[0];
		if (pipe(p.fd) == -1)
			exit (EXIT_FAILURE);
		p.pid = fork();
		if (p.pid == -1)
			exit ((close(p.fd[0]), close(p.fd[1]), EXIT_FAILURE));
		if (p.pid == 0)
		{
			if (p.n == 2)
				first_command(&p, argv, env);
			else if (p.n > 2 && p.n < argc - 2)
				command(&p, argv, env);
			else if (p.n == argc - 2)
				last_command(&p, argv, env);
		}
		p.n++;
		close(p.fd[1]);
	}
	exit_end(&p, status);
}
