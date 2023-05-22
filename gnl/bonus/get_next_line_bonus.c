/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 22:06:04 by daviles-          #+#    #+#             */
/*   Updated: 2023/04/27 20:56:49 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line_bonus.h"

void	ft_free(char ***str)
{
	if (**str)
	{
		free(**str);
		**str = NULL;
	}
}

int	ft_strposchr(const char *s, int c)
{
	int		count;

	count = 0;
	if (s)
	{
		while (((char *) s)[count] != '\0')
		{
			if (((char *) s)[count] == (char) c)
				return (count);
			count++;
		}
	}
	return (-1);
}

char	*ft_saveline(char ***waste)
{
	char		*rln;
	char		*tmp;
	int			to;
	size_t		size;

	size = ft_strposchr(*waste, '\n');
	if (ft_strposchr(&waste, '\n') != -1 && size != ft_strlen(waste))
	{
		to = ft_strposchr(*waste, '\n') + 1;
		rln = ft_substr(*waste, 0, to);
		tmp = *waste;
		*waste = ft_substr(*waste, to, ft_strlen(*waste));
		ft_free(&tmp);
	}
	else
	{
		to = ft_strlen(*waste);
		rln = ft_substr(*waste, 0, to);
		if (*waste)
			ft_free(waste);
	}
	return (rln);
}

int	ft_read(char ***waste, int fd)
{
	int		r;
	char	*tmp;
	char	*buf;

	buf = (char *) ft_calloc (BUFFER_SIZE + 1, 1);
	r = 1;
	while (r > 0 && ft_strposchr(buf, '\n') == -1)
	{
		ft_bzero(buf, BUFFER_SIZE);
		r = read(fd, buf, BUFFER_SIZE);
		tmp = *waste[fd];
		*waste[fd] = ft_strjoin(*waste[fd], buf);
		ft_free(&tmp);
	}
	ft_free(&buf);
	if (r <= 0)
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	**waste;
	int			i;

	i = 0;
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
	{
		ft_free(waste);
		return (0);
	}
	if (waste == NULL)
		waste = (char **) ft_calloc (1, sizeof(char *));
	if (ft_strposchr(waste, '\n') == -1)
		if (ft_read(&waste, fd) == 0)
		{
			if (ft_strlen(waste) > 0)
			{
				line = waste;
				waste = NULL;
				return (line);
			}
			ft_free(&waste);
			return (0);
		}
	return (ft_saveline(&waste));
}

int	main(void)
{
	int		fd;
	char	*line = "";
	int		fd2;
	int		i;
	char	*line2 = "";

	i = 1;
	fd = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	line = get_next_line(fd);
	line2 = get_next_line(fd2);
	printf("Result A: %s", line);
	printf("Result B: %s", line);
/*	while (line)
	{
		printf("Result %d: %s", i, line);
		free(line);
		line = NULL;
		line = get_next_line(fd);
		i++;
	}
	*/
    close(fd);
//	system("leaks a.out");
	return (0);
}

