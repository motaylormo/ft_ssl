/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 09:28:25 by mtaylor           #+#    #+#             */
/*   Updated: 2019/03/07 14:11:41 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Locates the first occurrence of the char in the string
**		and returns a pointer to it.
**	NULL if the char does not appear in the string.
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (c == '\0' && *s == '\0')
		return ((char*)s);
	return (0);
}
