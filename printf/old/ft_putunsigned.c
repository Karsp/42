/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:04:10 by daviles-          #+#    #+#             */
/*   Updated: 2023/05/16 18:04:34 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libftprintf.h"

int	ft_putunsigned(unsigned int n, int *res)
{
	char	c;

	if (n == 2147483648)
		*res += write(1, "2147483648", 10);
	else if (n == 0)
	{
		*res += 1;
		write(1, "0", 1);
	}
	else if ((n / 10) == 0)
	{
		*res += 1;
		c = n + 48;
		write(1, &c, 1);
	}
	else
	{
		ft_putunsigned((n / 10), res);
		c = (n % 10) + 48;
		write(1, &c, 1);
		*res += 1;
	}
	return (*res);
}
