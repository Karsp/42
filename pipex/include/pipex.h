/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:09:35 by daviles-          #+#    #+#             */
/*   Updated: 2023/10/13 01:31:35 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include <sys/wait.h>
# include <errno.h>
# include"../libft/libft.h"

// pipex
void	ft_pipex(char **av, char **env);
// childs
void	child_input(int *fdp, char **av, char **env);
pid_t	child_output(int *fdp, char **av, char **env);
// utils
void	ft_waitpid(pid_t out_pid);
void	ft_perror_exit(char *msj);
// parser
int		check_route(char *av);
int		check_path(char **env);
char	*get_path(char *cmd, char **env);
char	*getcmd_withpath(char *av, char ***cmds, char **env);

#endif
