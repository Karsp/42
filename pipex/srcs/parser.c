/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 02:39:08 by daviles-          #+#    #+#             */
/*   Updated: 2023/10/12 23:13:48 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

int	check_route(char *av)
{
	if (ft_strncmp(av, "/", 1) == 0 || ft_strncmp(av, "./", 2) == 0)
		return (1);
	else if (ft_strncmp(av, "../", 3) == 0)
		return (1);
	else
		return (0);
}

int	check_path(char **env)
{
	int	i;
	
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (i);
		i++;
	}
	return (i);
}

char	*get_pathwithcmd(char *cmd, char **env)
{
	int		i;
	char	**paths;
	char	*path;
	char	*cmd_path;

	i = check_path(env);
	if (!env[i] || !env)
		return ("./");
	else
		paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(path, cmd);
		if (access(cmd_path, X_OK) == 0)
			return (free(paths), cmd_path);
		free(cmd_path);
		free(path);
		i++;
	}
	return (ft_freematrix(&paths), NULL);
}
/*
char	*get_path(char *cmd, char **env)
{
	char	*cmd;
	char	**cmds;

	cmds = ft_split(av[2], ' ');
	if (check_route(cmds[0]) == 1)
		cmd = cmds[0];
	else
		cmd = get_path(cmds[0], env);
	return (cmd);
}*/
