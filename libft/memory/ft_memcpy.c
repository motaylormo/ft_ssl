/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 14:55:00 by mtaylor           #+#    #+#             */
/*   Updated: 2018/10/23 19:01:23 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Copies n bytes from memory area src to memory area dst.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;
	size_t			i;

	destination = (unsigned char*)dst;
	source = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dst);
}
