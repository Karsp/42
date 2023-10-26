/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:12:00 by daviles-          #+#    #+#             */
/*   Updated: 2023/10/26 03:57:12 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

void	child_input_bonus(int *main_pipe, char *av, char *av_in, char **env)
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
		close(main_pipe[0]);
		if (dup2(fd_in, STDIN_FILENO) == -1
			|| dup2(main_pipe[1], STDOUT_FILENO) == -1)
			ft_perror_exit("Dup2 error");
		close(main_pipe[1]);
		close(fd_in);
		execve(cmd, cmds, env);
		ft_perror_exit(cmds[0]);
	}
	close(main_pipe[1]);
	waitpid(pid, NULL, 0);
}

void	process_middle(int	*main_pipe, int ac, char **av, char **env)
{
	int	pid;
	int	new_pipe[2];
	int	old_pipe[2];
	int	i;

	i = 3;
	if (!ft_strncmp(av[1], "here_doc", 9))
		i = 4;
	ft_cpypipes(old_pipe, main_pipe);
	while (i < ac - 2)
	{
		if (pipe(new_pipe) == -1)
			ft_perror_exit("Pipe error");
		pid = fork();
		if (pid < 0)
			ft_perror_exit("Fork error");
		else if (pid == 0)
			child_middle(new_pipe, old_pipe, av[i], env);
		ft_close(old_pipe[0], new_pipe[1]);
		waitpid(pid, NULL, 0);
		ft_cpypipes(old_pipe, new_pipe);
		i++;
	}
	child_output_bonus(old_pipe, av, ac, env);
}

void	child_middle(int *new_pipe, int *old_pipe, char *av, char **env)
{
	char	*cmd;
	char	**cmds;

	cmd = getcmd_withpath(av, &cmds, env);
	dup2(old_pipe[0], STDIN_FILENO);
	dup2(new_pipe[1], STDOUT_FILENO);
	ft_close(new_pipe[0], new_pipe[1]);
	ft_close(old_pipe[0], old_pipe[1]);
	execve(cmd, cmds, env);
	ft_perror_exit(cmds[0]);
}

void	child_output_bonus(int *main_pipe, char **av, int ac, char **env)
{
	int		pid;
	int		fd_out;
	char	*cmd;
	char	**cmds;

	pid = fork();
	if (pid < 0)
		ft_perror_exit("Fork error");
	else if (pid == 0)
	{
		cmd = getcmd_withpath(av[ac - 2], &cmds, env);
		if (!ft_strncmp(av[1], "here_doc", 9))
			fd_out = open(av[ac - 1], O_RDWR | O_CREAT | O_APPEND, 0666);
		else
			fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (fd_out < 0)
			ft_perror_exit(av[ac - 1]);
		dup2(main_pipe[0], STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		ft_close(main_pipe[0], main_pipe[1]);
		close(fd_out);
		execve(cmd, cmds, env);
		ft_perror_exit(cmds[0]);
	}
	waitpid(pid, NULL, 0);
}

void	ft_heredoc(int *main_pipe, char **av, int ac, char **env)
{
	char	*line;
	int		fd_in;

	(void)ac;
	fd_in = open(".heredoc", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd_in == -1)
		ft_perror_exit("Pipe error");
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (line == 0)
			break ;
		if (!ft_strncmp(line, av[2], ft_strlen(av[2]))
			&& (ft_strlen(av[2]) + 1) == ft_strlen(line))
			break ;
		write(fd_in, line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(fd_in);
	child_input_bonus(main_pipe, av[3], ".heredoc", env);
}
