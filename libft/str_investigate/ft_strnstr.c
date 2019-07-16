/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 09:32:51 by mtaylor           #+#    #+#             */
/*   Updated: 2018/12/08 15:50:01 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Returns pointer to the first occurrence of needle in haystack,
**		where not more than len characters are searched.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	if (*needle == '\0')
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	while (*haystack && len >= needle_len)
	{
		if (ft_strncmp(haystack, needle, needle_len) == 0)
			return ((char*)haystack);
		haystack++;
		len--;
	}
	return (0);
}
