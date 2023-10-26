/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:09:35 by daviles-          #+#    #+#             */
/*   Updated: 2023/10/26 03:26:06 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include"pipex.h"

// pipex
void	ft_pipex_bonus(int ac, char **av, char **env);
// childs
void	child_input_bonus(int *m_fd, char *av, char *av_in, char **env);
void	child_output_bonus(int *m_fd, char **av, int ac, char **env);
void	child_middle(int *new_fd, int *old_fd, char *av, char **env);
void	process_middle(int	*main_pipe, int ac, char **av, char **env);
void	ft_heredoc(int *main_pipe, char **av, int ac, char **env);
// utils
void	ft_close(int fd1, int fd2);
void	ft_cpypipes(int *old_pipe, int *new_pipe);
// parser

#endif
