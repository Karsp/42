/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 02:25:36 by daviles-          #+#    #+#             */
/*   Updated: 2023/10/11 04:35:05 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

void	child_input(int *m_fd, char **av, char **env)
{
	int	pid;
	int	fd_in;
	char *route = ft_strjoin("/bin/", av[1]);

	(void)env;
	pid = fork();
	if (pid < 0)
	{
		ft_putstr_fd("Fork error", 2);
		exit(1);
	}
	else if (pid == 0)
	{
//		fd_in = open(av[1], O_RDONLY);
		fd_in = open("file", O_RDONLY);
		dup2(fd_in, STDIN_FILENO);
		dup2(m_fd[1], STDOUT_FILENO);
		close(m_fd[0]);
		close(m_fd[1]);
		execve(route, NULL, NULL);
		ft_putstr_fd("Execv error in", 2);
		exit(1);
	}
}

pid_t	child_output(int *m_fd, char **av, char **env)
{
	int	pid;
	int	fd_out;
	char *route = ft_strjoin("/usr/bin/", av[2]);

	(void)env;
	pid = fork();
	if (pid < 0)
	{
		ft_putstr_fd("Fork error", 2);
		exit(1);
	}
	else if (pid == 0)
	{
		fd_out = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		dup2(m_fd[0], STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		close(m_fd[0]);
		close(m_fd[1]);
		execve(route, &av[2], NULL);
		ft_putstr_fd("Execv error out", 2);
		exit(1);
	}
	return (pid);
}
