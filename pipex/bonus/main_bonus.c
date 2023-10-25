/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:08:33 by daviles-          #+#    #+#             */
/*   Updated: 2023/10/25 23:13:57 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex_bonus.h"

int	main(int ac, char **av, char **env)
{
	if (ac >= 6)
		ft_pipex_bonus(ac, av, env);
	else
		ft_printf("Invalid args. Follow this example:\n \
	./pipex here_doc LIMITER comand1 comand2 file_out\n");
	close(0);
	return (0);
}
