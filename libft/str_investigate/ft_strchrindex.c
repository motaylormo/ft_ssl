/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrindex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:15:59 by mtaylor           #+#    #+#             */
/*   Updated: 2018/11/09 16:17:06 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Locates the first occurrence of the char in the string
**		and returns it's index.
**	(-1) if the char does not appear in the string.
*/

int	ft_strchrindex(const char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	if (str[i] == '\0' && c == '\0')
		return (i);
	return (-1);
}
