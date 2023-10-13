/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 02:05:47 by daviles-          #+#    #+#             */
/*   Updated: 2023/10/13 02:28:07 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

void	ft_waitpid(pid_t out_pid)
{
	pid_t	pid;
	int		status;

	(void)out_pid;
	pid = 1;
	while (pid != -1)
	{
		pid = waitpid(-1, &status, 0);
//		if (pid == out_pid)
//			exit(0);
	}
}

void	ft_perror_exit(char *msj)
{
	perror(msj);
	exit(1);
}
