/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:08:33 by daviles-          #+#    #+#             */
/*   Updated: 2023/10/26 03:57:25 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

int	main(int ac, char **av, char **env)
{
	if (ac <= 4)
		ft_printf("Invalid arguments. Try this examples:\n \
		./pipex file1 command1 command2 file2\n \
		./pipex file1 command1 command2 command3... file2\n \
		./pipex here_doc LIMITER comand1 comand2 file_out\n");
	else
		ft_pipex_bonus(ac, av, env);
	close(0);
	return (0);
}
