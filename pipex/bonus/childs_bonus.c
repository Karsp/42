/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:12:00 by daviles-          #+#    #+#             */
/*   Updated: 2023/10/19 21:00:22 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex_bonus.h"

void	child_input_bonus(int *m_fd, char *av, char *av_in, char **env)
{
	int		pid;
	char	*cmd;
	char	**cmds;
	int		fd_in;

	pid = fork();
	if (pid < 0)
		ft_perror_exit("Fork error");
	else if (pid == 0)
	{
		cmd = getcmd_withpath(av, &cmds, env);
		fd_in = open(av_in, O_RDONLY);
		if (fd_in < 0)
			ft_perror_exit(av_in);
		close(m_fd[0]);
		dup2(fd_in, STDIN_FILENO);
		dup2(m_fd[1], STDOUT_FILENO);
		close(m_fd[1]);
		close(fd_in);
		execve(cmd, cmds, env);
		ft_perror_exit(cmds[0]);
	}
	//close(m_fd[0]);
	//close(m_fd[1]);
}

void	child_middle(int *fd, char *av, char **env)
{
	int		pid;
	char	*cmd;
	char	**cmds;

	//pipe(fd);
	pid = fork();
	if (pid < 0)
		ft_perror_exit("Fork error");
	else if (pid == 0)
	{
		cmd = getcmd_withpath(av, &cmds, env);
		dup2(fd[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve(cmd, cmds, env);
		ft_perror_exit(cmds[0]);
	}
	//close(fd[0]);
	//close(fd[1]);
}

pid_t	child_output_bonus(int *m_fd, char *av, char *av_out, char **env)
{
	int		pid;
	int		fd_out;
	char	*cmd;
	char	**cmds;

	//pipe(m_fd);
	pid = fork();
	if (pid < 0)
		ft_perror_exit("Fork error");
	else if (pid == 0)
	{
		cmd = getcmd_withpath(av, &cmds, env);
		fd_out = open(av_out, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (fd_out < 0)
			ft_perror_exit(av_out);
		close(m_fd[1]);
		dup2(m_fd[0], STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		close(m_fd[0]);
		close(fd_out);
		execve(cmd, cmds, env);
		ft_perror_exit(cmds[0]);
	}
	close(m_fd[0]);
	close(m_fd[1]);
	close(0);
	return (pid);
}
