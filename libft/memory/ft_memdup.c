/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:38:53 by mtaylor           #+#    #+#             */
/*   Updated: 2019/04/02 17:44:02 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Mallocs space and returns a new memory area
**		that holds a copy of n bytes from the old memory area.
*/

void	*ft_memdup(void *src, size_t bytes)
{
	unsigned char	*source;
	unsigned char	*copy;

	source = (unsigned char*)src;
	if ((copy = ft_memalloc(bytes)))
	{
		ft_memcpy(copy, source, bytes);
		return (copy);
	}
	return (0);
}
