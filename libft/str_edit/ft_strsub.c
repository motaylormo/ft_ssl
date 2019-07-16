/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:26:39 by mtaylor           #+#    #+#             */
/*   Updated: 2018/12/08 14:25:13 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Mallocs space and returns a fresh string
**		that's the segment of the old string, len starting at start.
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *new;

	if (s != NULL && (new = (char*)malloc(len + 1)))
	{
		while (start--)
			s++;
		ft_strncpy(new, s, len);
		new[len] = '\0';
		return (new);
	}
	return (0);
}
