/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 01:47:01 by daviles-          #+#    #+#             */
/*   Updated: 2023/10/25 23:51:52 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

void	ft_pipex(char **av, char **env)
{
	int		main_fd[2];
	int		status;

	pipe(main_fd);
	child_input(main_fd, av, env);
	child_output(main_fd, av, env);
	close(main_fd[0]);
	close(main_fd[1]);
	waitpid(-1, &status, 0);
}
