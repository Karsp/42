/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:08:33 by daviles-          #+#    #+#             */
/*   Updated: 2023/10/19 19:43:21 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex_bonus.h"

int	main(int ac, char **av, char **env)
{
	ft_pipex_bonus(ac, av, env);
/*	if (ac == 5)
	{
		ft_pipex(av, env);
	}
	else
		ft_printf("Invalid args. Follow this example:\n \
	./pipex archivo1 comando1 comando2 archivo2\n");
	*/
	close(0);
	return (0);
}
