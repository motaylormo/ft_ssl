/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:17:36 by mtaylor           #+#    #+#             */
/*   Updated: 2018/10/24 13:35:51 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Compares s1 against s2.
**	Returns (0) for matching,
**		and the difference between the first two differing chars otherwise.
*/

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if ((s1[i] == '\0' && s2[i] != '\0') || (s2[i] == '\0' && s1[i] != '\0'))
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
