/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 09:25:27 by mtaylor           #+#    #+#             */
/*   Updated: 2018/10/24 15:41:26 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Copies len bytes from string src to string dst.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *destination;
	unsigned char *source;

	destination = (unsigned char*)dst;
	source = (unsigned char*)src;
	if (source == destination)
		return (dst);
	if (source < destination)
	{
		source += len - 1;
		destination += len - 1;
		while (len--)
			*destination-- = *source--;
	}
	else
	{
		while (len--)
			*destination++ = *source++;
	}
	return (dst);
}
