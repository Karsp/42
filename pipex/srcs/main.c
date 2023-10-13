/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:08:33 by daviles-          #+#    #+#             */
/*   Updated: 2023/10/13 02:58:29 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

void	leaker(void)
{
	system("leaks -q pipex");
}

int	main(int ac, char **av, char **env)
{
	atexit(leaker);
	if (ac == 5)
	{
		ft_pipex(av, env);
	}
	else
		ft_printf("./pipex archivo1 comando1 comando2 archivo2\n");
	return (0);
}
