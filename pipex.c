/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:08:48 by amirloup          #+#    #+#             */
/*   Updated: 2024/01/25 12:37:34 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	first_command(int *fd, char **argv, char **env)
{
	int	fd1;

	fd1 = open(argv[1], O_RDONLY, 0777);
	if (fd1 == -1)
		error_exit("Error while opening infile!\n");
	if (dup2(fd1, STDIN_FILENO) == -1)
		exit ((close(fd[0]), close(fd[1]), close(fd1), EXIT_FAILURE));
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		exit ((close(fd[0]), close(fd[1]), close(fd1), EXIT_FAILURE));
	close(fd[0]);
	close(fd[1]);
	close(fd1);
	exec(argv, env, 2);
}

void	second_command(int *fd, char **argv, char **env)
{
	int	fd2;

	fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd2 == -1)
		error_exit("Error while opening outfile!\n");
	if (dup2(fd2, STDOUT_FILENO) == -1)
		exit ((close(fd[0]), close(fd[1]), close(fd2), EXIT_FAILURE));
	if (dup2(fd[0], STDIN_FILENO) == -1)
		exit ((close(fd[0]), close(fd[1]), close(fd2), EXIT_FAILURE));
	close(fd[0]);
	close(fd[1]);
	close(fd2);
	exec(argv, env, 3);
}

int	main(int argc, char **argv, char **env)
{
	int	fd[2];
	int	pid1;
	int	pid2;
	int	status;

	if (argc != 5)
		error_exit("Wrong format!\n");
	if (pipe(fd) == -1)
		exit (EXIT_FAILURE);
	pid1 = fork();
	if (pid1 == -1)
		exit ((close(fd[0]), close(fd[1]), EXIT_FAILURE));
	if (pid1 == 0)
		first_command(fd, argv, env);
	pid2 = fork();
	if (pid2 == -1)
		exit ((close(fd[0]), close(fd[1]), EXIT_FAILURE));
	if (pid2 == 0)
		second_command(fd, argv, env);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	exit_end(status);
}
