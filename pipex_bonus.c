/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:00:37 by amirloup          #+#    #+#             */
/*   Updated: 2024/01/25 16:52:48 by amirloup         ###   ########.fr       */
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

void	first_command(int *fd, char **argv, char **env, int n)
{
	int	fd_in;

	fd_in = open(argv[1], O_RDONLY, 0777);
	if (fd_in == -1)
		error_exit("Error while opening infile!\n");
	if (dup2(fd_in, STDIN_FILENO) == -1)
		exit ((close(fd[0]), close(fd[1]), close(fd_in), EXIT_FAILURE));
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		exit ((close(fd[0]), close(fd[1]), close(fd_in), EXIT_FAILURE));
	fflush(stdout);
	fprintf(stderr, "%s\n", argv[n]);
	close(fd[0]);
	close(fd[1]);
	close(fd_in);
	exec(argv, env, n);
}

void	command(int *fd, char **argv, char **env, int n)
{
	if (dup2(fd[0], STDIN_FILENO) == -1)
		exit ((close(fd[0]), close(fd[1]), EXIT_FAILURE));
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		exit ((close(fd[0]), close(fd[1]), EXIT_FAILURE));
	fflush(stdout);
	fprintf(stderr, "%s\n", argv[n]);
	close(fd[0]);
	close(fd[1]);
	exec(argv, env, n);
}

void	last_command(int *fd, char **argv, char **env, int n)
{
	int	fd_out;

	fd_out = open(argv[n], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out == -1)
		error_exit("Error while opening infile!\n");
	if (dup2(fd_out, STDOUT_FILENO) == -1)
		exit ((close(fd[0]), close(fd[1]), close(fd_out), EXIT_FAILURE));
	if (dup2(fd[0], STDIN_FILENO) == -1)
		exit ((close(fd[0]), close(fd[1]), close(fd_out), EXIT_FAILURE));
	fflush(stdout);
	fprintf(stderr, "%s\n", argv[n]);
	close(fd[0]);
	close(fd[1]);
	close(fd_out);
	exec(argv, env, n);
}

int	main(int argc, char **argv, char **env)
{
	int	fd[2];
	int	pid;
	int	status;
	int	n;

	if (argc < 5)
		error_exit("Wrong format!\n");
	n = 2;
	while (n < argc - 1)
	{
		if (pipe(fd) == -1)
			exit (EXIT_FAILURE);
		pid = fork();
		if (pid == -1)
			exit ((close(fd[0]), close(fd[1]), EXIT_FAILURE));
		if (pid == 0)
		{
			fflush(stdout);
			printf("%d\n", n);
			if (n == 2)
				first_command(fd, argv, env, 2);
			else if (n > 2 && n < argc - 1)
				command(fd, argv, env, n);
			else if (n == argc - 1)
				last_command(fd, argv, env, n);
		}
		n++;
		close(fd[0]);
		close(fd[1]);
	}
	while (n >= 2)
	{
		waitpid(pid, &status, 0);
		n--;
	}
	exit_end(status);
}
