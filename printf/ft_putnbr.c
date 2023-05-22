/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:57:29 by daviles-          #+#    #+#             */
/*   Updated: 2023/05/16 19:15:21 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libftprintf.h"

int	ft_putnbr(int n, int *res)
{
	char	c;

	if (n == -2147483648)
		*res += write(1, "-2147483648", 11);
	else if (n < 0)
	{
		write(1, "-", 1);
		*res += 1;
		ft_putnbr((n * -1), res);
	}
	else if ((n / 10) == 0)
	{
		*res += 1;
		c = n + 48;
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr((n / 10), res);
		c = (n % 10) + 48;
		write(1, &c, 1);
		*res += 1;
	}
	return (*res);
}
