/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 01:47:01 by daviles-          #+#    #+#             */
/*   Updated: 2023/10/19 21:00:24 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex_bonus.h"

void	ft_pipex_bonus(int ac, char **av, char **env)
{
	int		main_fd[2];
	pid_t	pid;
	int		i;

	i = 3;
	pipe(main_fd); // proteger pipes
	if (!ft_strncmp(av[1], "here_doc", 9))
	{
	}
	else
		child_input_bonus(main_fd, av[2], av[1], env);
	//dpritntf(2, "antes\n");
	while (i < ac - 2 && ac > 5)
	{
		dprintf(2, "HOLA\n");
		child_middle(main_fd, av[i], env);
		i++;
	}
	dprintf(2, "fuera\n");
	pid = child_output_bonus(main_fd, av[i], av[ac - 1], env);
	printf("no llega\n");
	ft_waitpid(pid);
}
