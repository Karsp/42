/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 02:39:08 by daviles-          #+#    #+#             */
/*   Updated: 2023/10/12 22:55:04 by daviles-         ###   ########.fr       */
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
	if (!env[i])
		return (NULL);
	paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(path, cmd);
		free(path);
		if (access(cmd_path, X_OK) == 0)
		{
			free(paths);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	ft_freematrix(&paths);
	return (NULL);
}
