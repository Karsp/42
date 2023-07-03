/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:59:05 by daviles-          #+#    #+#             */
/*   Updated: 2023/05/16 19:09:17 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libftprintf.h"

int	ft_putnbr_base(unsigned int n, char base, int *res)
{
	char	*dicc;

	if (base == 'x')
		dicc = "0123456789abcdef";
	else if (base == 'X')
		dicc = "0123456789ABCDEF";
	if ((n / 16) == 0)
	{
		*res += 1;
		write(1, &dicc[n % 16], 1);
	}
	else
	{
		ft_putnbr_base((n / 16), base, res);
		write(1, &dicc[n % 16], 1);
		*res += 1;
	}
	return (*res);
}
