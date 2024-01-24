/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:49:02 by amirloup          #+#    #+#             */
/*   Updated: 2024/01/24 16:22:53 by amirloup         ###   ########.fr       */
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
		i = 0;
		while (path[i])
		{
			path[i] = ft_strjoin(path[i], "/");
			path[i] = ft_strjoin(path[i], argv[0]);
			i++;
		}
	}
	return (path);
}

void	exec(char **argv, char **env, int n)
{
	int		i;
	char	**path;
	char	**cmd;

	cmd = split_argv(argv, n);
	i = 0;
	while (cmd[i])
	{
		cmd[i] = ft_strtrim(cmd[i], "\"");
		cmd[i] = ft_strtrim(cmd[i], " ");
		i++;
	}
	i = 0;
	path = find_path(cmd, env);
	while (path[i])
	{
		if (access(path[i], F_OK) == 0)
			if (access(path[i], X_OK) == 0)
				execve(path[i], cmd, env);
		i++;
	}
	if (execve(path[i], cmd, env) == -1)
		error_exit("Command not found!\n");
	free_tab(path);
	free_tab(cmd);
}

void	first_command(int *fd, char **argv, char **env)
{
	int	fd1;

	fd1 = open(argv[1], O_RDONLY, 0777);
	if (fd1 == -1)
		error_exit("Error while opening infile!\n");
	dup2(fd1, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	exec(argv, env, 2);
	close(fd1);
}

void	second_command(int *fd, char **argv, char **env)
{
	int	fd2;

	fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd2 == -1)
		error_exit("Error while opening outfile!\n");
	dup2(fd2, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	exec(argv, env, 3);
	close(fd2);
}

int	main(int argc, char **argv, char **env)
{
	int	*fd;
	int	pid;
	int	status;
	int	i;

	i = 0;
	if (argc < 5)
		error_exit("Wrong format!\n");
	while (i < argc)
	{
		if (pipe(fd[i]) == -1)
			exit (EXIT_FAILURE);
		pid1 = fork();
		if (pid == -1)
			exit (EXIT_FAILURE);
		if (pid1 == 0)
			first_command(fd, argv, env);
		waitpid(pid, NULL, 0);
		i++;
	}
	i = 0;
	while (i < argc)
	{
		close(fd[i]);
		i++;
	}

	waitpid(pid2, &status, 0);
	exit_end(status);
}
