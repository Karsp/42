/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strposchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <daviles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:35:47 by daviles-          #+#    #+#             */
/*   Updated: 2024/03/03 00:11:08 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//The strchr() function locates the first occurrence of c (converted to a 
//char) in the string pointed to by s.  The terminating null character is
// considered to be part of the string; therefore if c is `\0', the functions
// locate the terminating `\0'.

int	ft_strposchr(const char *s, int c)
{
	int	count;

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
