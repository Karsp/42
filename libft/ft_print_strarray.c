/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strarray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:17:15 by daviles-          #+#    #+#             */
/*   Updated: 2024/03/03 00:09:12 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_print_strarray(char **array)
{
	int	i;

	i = 0;
	if (!*array || !array)
		return ;
	while (array[i])
	{
		ft_printf("%s\n", array[i]);
		i++;
	}
}
