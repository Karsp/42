/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:08:33 by daviles-          #+#    #+#             */
/*   Updated: 2023/10/19 11:56:25 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

int	main(int ac, char **av, char **env)
{
	if (ac == 5)
	{
		ft_pipex(av, env);
	}
	else
		ft_printf("Invalid args. Follow this example:\n \
	./pipex archivo1 comando1 comando2 archivo2\n");
	return (0);
}
