/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:19:48 by mtaylor           #+#    #+#             */
/*   Updated: 2018/12/08 14:23:54 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Mallocs spaces and return a new string
**		that's the two old strings catted together.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	if (s1 != NULL && s2 != NULL
			&& (new = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
	{
		ft_strcpy(new, s1);
		ft_strcat(new, s2);
		return (new);
	}
	return (0);
}
