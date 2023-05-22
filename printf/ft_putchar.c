/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:05:51 by daviles-          #+#    #+#             */
/*   Updated: 2023/05/19 16:58:21 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libftprintf.h"

int	ft_putchar(char c, int *res)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	*res = *res + 1;
	return (*res);
}
