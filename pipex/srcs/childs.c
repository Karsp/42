/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 02:25:36 by daviles-          #+#    #+#             */
/*   Updated: 2023/10/13 03:09:05 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

void	child_input(int *m_fd, char **av, char **env)
{
	int		pid;
	int		fd_in;
	char	*cmd;
	char	**cmds;

	cmd = getcmd_withpath(av[2], &cmds, env);
	pid = fork();
	if (pid < 0)
		ft_perror_exit("Fork error");
	else if (pid == 0)
	{
		fd_in = open(av[1], O_RDONLY);
		if (fd_in < 0)
			ft_perror_exit(av[1]);
		dup2(fd_in, STDIN_FILENO);
		dup2(m_fd[1], STDOUT_FILENO);
		close(m_fd[0]);
		close(m_fd[1]);
		close(fd_in);
		execve(cmd, cmds, env);
		ft_perror_exit(cmds[0]);
	}
}

pid_t	child_output(int *m_fd, char **av, char **env)
{
	int		pid;
	int		fd_out;
	char	*cmd;
	char	**cmds;

	cmd = getcmd_withpath(av[3], &cmds, env);
	pid = fork();
	if (pid < 0)
		ft_perror_exit("Fork error");
	else if (pid == 0)
	{
		fd_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (fd_out < 0)
			ft_perror_exit(av[4]);
		dup2(m_fd[0], STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		close(m_fd[0]);
		close(m_fd[1]);
		close(fd_out);
		execve(cmd, cmds, env);
		ft_perror_exit(cmds[0]);
	}
	return (pid);
}
