/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 02:25:36 by daviles-          #+#    #+#             */
/*   Updated: 2023/10/12 22:45:15 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

void	child_input(int *m_fd, char **av, char **env)
{
	int		pid;
	int		fd_in;
	char	*cmd;
	char	**cmds;

	cmds = ft_split(av[2], ' ');
	if (check_route(cmds[0]) == 1)
		cmd = cmds[0];
	else
		cmd = get_pathwithcmd(cmds[0], env);
	pid = fork();
	if (pid < 0)
	{
		perror("Fork error");
		exit(1);
	}
	else if (pid == 0)
	{
		fd_in = open(av[1], O_RDONLY);
		if (fd_in < 0)
		{
			perror(av[1]);
			exit(1);
		}
		dup2(fd_in, STDIN_FILENO);
		dup2(m_fd[1], STDOUT_FILENO);
		close(m_fd[0]);
		close(m_fd[1]);
		execve(cmd, cmds, env);
		perror(cmd);
		exit(1);
	}
}

pid_t	child_output(int *m_fd, char **av, char **env)
{
	int		pid;
	int		fd_out;
	char	*cmd;
	char	**cmds;

	cmds = ft_split(av[3], ' ');
	if (check_route(cmds[0]) == 1)
		cmd = cmds[0];
	else
		cmd = get_pathwithcmd(cmds[0], env);
	pid = fork();
	if (pid < 0)
	{
		perror("Fork error");
		exit(1);
	}
	else if (pid == 0)
	{
		fd_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (fd_out < 0)
		{
			perror(av[4]);
			exit(1);
		}
		dup2(m_fd[0], STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		close(m_fd[0]);
		close(m_fd[1]);
		execve(cmd, cmds, env);
		perror(cmd);
		exit(1);
	}
	return (pid);
}
