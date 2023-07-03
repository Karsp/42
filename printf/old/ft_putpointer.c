/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:06:36 by daviles-          #+#    #+#             */
/*   Updated: 2023/05/19 17:47:25 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libftprintf.h"

int	ft_putpointer(void *ptr, int *res)
{
	unsigned long	n;
	char			*dicc;

	n = (unsigned long)ptr;
	dicc = "0123456789abcdef";
	if ((n / 16) == 0)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		if (write(1, &dicc[n % 16], 1) == -1)
			return (-1);
		*res += 3;
	}
	else
	{
		ft_putpointer((void *)(n / 16), res);
		if (write(1, &dicc[n % 16], 1) == -1)
			return (-1);
		*res += 1;
	}
	return (*res);
}
