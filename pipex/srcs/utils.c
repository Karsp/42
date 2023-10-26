/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 02:05:47 by daviles-          #+#    #+#             */
/*   Updated: 2023/10/26 03:26:09 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

void	ft_close(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}

void	ft_cpypipes(int *old_pipe, int *new_pipe)
{
	old_pipe[0] = new_pipe[0];
	old_pipe[1] = new_pipe[1];
}

void	ft_perror_exit(char *msj)
{
	perror(msj);
	exit(1);
}
