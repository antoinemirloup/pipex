/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:08:48 by amirloup          #+#    #+#             */
/*   Updated: 2024/01/19 16:04:26 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(char **argv, char **env)
{
	int		i;
	char	**tab;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	tab = ft_split(&env[i][5], ':');
	i = 0;
	while (tab[i])
	{
		tab[i] = ft_strjoin(tab[i], "/");
		tab[i] = ft_strjoin(tab[i], argv[0]);
		i++;
	}
	return (tab);
}

void	exec(char **argv, char **env, int n)
{
	int		i;
	char	**path;
	char	**tab;

	tab = ft_split(argv[n], ' ');
	i = 0;
	path = find_path(tab, env);
	while (path[i])
	{
		if (access(path[i], F_OK) == 0)
			if (access(path[i], X_OK) == 0)
				execve(path[i], tab, env);
		i++;
	}
	if (execve(path[i], tab, env) == -1)
		error_exit("Command not found!\n");
	free_tab(path);
	free_tab(tab);
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
		exit (EXIT_FAILURE);
	if (pid1 == 0)
		first_command(fd, argv, env);
	pid2 = fork();
	if (pid2 == -1)
		exit (EXIT_FAILURE);
	if (pid2 == 0)
		second_command(fd, argv, env);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	exit_end(status);
}
