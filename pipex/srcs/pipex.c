/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 01:47:01 by daviles-          #+#    #+#             */
/*   Updated: 2023/10/12 01:48:22 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

void	ft_pipex(int ac, char **av, char **env)
{
	int		main_fd[2];
	pid_t	pid;

	(void)env;
	(void)ac;
	pipe(main_fd);
	child_input(main_fd, av, env);
	pid = child_output(main_fd, av, env);
	close(main_fd[0]);
	close(main_fd[1]);
	ft_waitpid(pid);
	close(0);
}

