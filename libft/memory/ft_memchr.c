/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 09:25:54 by mtaylor           #+#    #+#             */
/*   Updated: 2018/10/24 15:58:12 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Locates the first occurrence of c in string s.
**	Returns a pointer to c in the str,
**		or NULL if c doesn't exist within n bytes.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char*)s;
	while (n-- > 0)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	return (0);
}
