/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 11:04:27 by mtaylor           #+#    #+#             */
/*   Updated: 2019/05/16 11:04:29 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Mallocs space and returns a new array of string.
*/

char	**ft_matrixdup(char *src[])
{
	char	**copy;
	int		i;

	if ((copy = ft_memalloc(sizeof(char*) * (ft_matrixlen(src) + 1))))
	{
		i = 0;
		while (src[i])
		{
			copy[i] = ft_strdup(src[i]);
			i++;
		}
		return (copy);
	}
	return (0);
}
