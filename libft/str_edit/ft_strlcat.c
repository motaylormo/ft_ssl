/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 09:28:11 by mtaylor           #+#    #+#             */
/*   Updated: 2019/03/07 17:04:35 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Appends src to the end of dst.
**	It will not overflow dst's space,
**		so src will get cut short if it runs out of space.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	len;
	size_t	x;

	dst_len = ft_strlen(dst);
	len = ft_strlen(src);
	x = 0;
	len += (dstsize <= dst_len) ? dstsize : dst_len;
	while (dstsize > 0 && dst_len + x < dstsize - 1 && src[x])
	{
		dst[dst_len + x] = src[x];
		x++;
	}
	if (dstsize != 0)
		dst[dst_len + x] = '\0';
	return (len);
}
