/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:48:24 by amirloup          #+#    #+#             */
/*   Updated: 2024/01/24 16:01:03 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>

# include "libft/libft.h"

void	free_tab(char **tab);
void	exit_end(int status);
void	error_exit(char *s);
char	**full_cmd(char *argv);
char	**path_script(char **argv);
char	**split_argv(char **argv, int n);

#endif