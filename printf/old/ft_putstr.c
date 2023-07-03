/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:53:55 by daviles-          #+#    #+#             */
/*   Updated: 2023/05/19 17:06:14 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libftprintf.h"

int	ft_putstr(char *str, int *res)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if ((write(1, &str[i], 1)) == -1)
				return (-1);
			i++;
			*res += 1;
		}
	}
	else
	{
		write(1, "(null)", 6);
		*res += 6;
		return (6);
	}
	return (i);
}
