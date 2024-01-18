/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:08:48 by amirloup          #+#    #+#             */
/*   Updated: 2024/01/18 16:58:17 by amirloup         ###   ########.fr       */
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
	free_tab(path);
	free_tab(tab);
}

void	first_command(int *fd, char **argv, char **env)
{
	int	fd1;

	fd1 = open(argv[1], O_RDONLY);
	dup2(fd1, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	exec(argv, env, 2);
}

void	second_command(int *fd, char **argv, char **env)
{
	int	fd2;

	fd2 = open(argv[4], O_WRONLY | O_CREAT | S_IRWXU);
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

	if (argc >= 2)
	{
		if (pipe(fd) == -1)
			return (1);
		pid1 = fork();
		if (pid1 == 0)
			first_command(fd, argv, env);
		pid2 = fork();
		if (pid2 == 0)
			second_command(fd, argv, env);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
}
