/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 09:25:14 by mtaylor           #+#    #+#             */
/*   Updated: 2018/10/24 17:52:02 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Copies n bytes from memory area src to memory area dst. (Same as memcpy.)
**	If the char c occurs in src, the copy stops
**		and a pointer to the byte after the copy of c in dst is returned.
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
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
		if (destination[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
