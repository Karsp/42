/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 01:47:01 by daviles-          #+#    #+#             */
/*   Updated: 2023/10/25 22:20:36 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex_bonus.h"

void	ft_pipex_bonus(int ac, char **av, char **env)
{
	int		main_pipe[2];
	int		status;

	if (pipe(main_pipe) == -1)
		ft_perror_exit("Pipe error");
	if (!ft_strncmp(av[1], "here_doc", 9))
		ft_heredoc(main_pipe, av, ac, env);
	else
		child_input_bonus(main_pipe, av[2], av[1], env);
		process_middle(main_pipe, ac, av, env);
	close(main_pipe[0]);
	close(main_pipe[1]);
	waitpid(-1, &status, 0);
}
