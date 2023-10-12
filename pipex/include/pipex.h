/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:09:35 by daviles-          #+#    #+#             */
/*   Updated: 2023/10/12 20:09:16 by daviles-         ###   ########.fr       */
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
// parser
int		check_route(char *av);
int		check_path(char **env);
char	*get_pathwithcmd(char *cmd, char **env);

#endif
