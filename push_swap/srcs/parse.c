/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:38:03 by daviles-          #+#    #+#             */
/*   Updated: 2023/08/30 21:40:51 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_chkduplicate(char *str)
{
	(void)str;
	return 1;
}

int	ft_chkint(char *str)
{
	(void)str;
	return 1;
}
int	ft_chknbr(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		i++;
		if (str[i] == '\0' || (str[i] < '0' || str[i] > '9'))
			return(ft_printerror("Not a number after sign.\n"));
	}
	while (str[i] != '\0' )
	{
		if (str[i] < '0' || str[i] > '9')
			return (ft_printerror("Invalid character.\n"));
		i++;
	}
	return 1;
}

int	ft_chkstr(char **nbrs)
{
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	if (!*nbrs)
		ft_printerror("Ivalid or empty input.\n");
	while (nbrs[i] != '\0')
	{
		if (ft_chknbr(nbrs[i]))
			printf("Valid %s\n", nbrs[i]);
		i++;
	}
	return 1;
}

