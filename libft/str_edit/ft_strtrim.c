/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:36:34 by mtaylor           #+#    #+#             */
/*   Updated: 2018/12/12 16:32:00 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Mallocs space and returns a fresh string
**		that's copy of the string without whitespace (' ' or '\n' or '\t')
**		at the beginning and end.
*/

char	*ft_strtrim(char const *s)
{
	char	*new;
	size_t	first;
	size_t	last;

	if (s != NULL)
	{
		first = 0;
		last = ft_strlen(s) - 1;
		while (s[first] &&
				((s[first] == ' ') || (s[first] == '\n') || (s[first] == '\t')))
			first++;
		while (last > first &&
				((s[last] == ' ') || (s[last] == '\n') || (s[last] == '\t')))
			last--;
		if ((new = ft_strsub(s, first, (last - first) + 1)))
			return (new);
	}
	return (0);
}
