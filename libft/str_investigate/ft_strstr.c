/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:15:55 by mtaylor           #+#    #+#             */
/*   Updated: 2018/10/29 17:26:11 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Locates the first occurrence of the substr in the string
**		and returns a pointer to it.
**	NULL if the substr does not appear in the string.
*/

char	*ft_strstr(const char *haystack, const char *needle)
{
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (*haystack)
	{
		if (ft_strncmp(haystack, needle, ft_strlen(needle)) == 0)
			return ((char*)haystack);
		haystack++;
	}
	return (0);
}
