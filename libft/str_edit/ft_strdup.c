/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 09:27:04 by mtaylor           #+#    #+#             */
/*   Updated: 2018/12/08 14:47:38 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Mallocs space and returns a new string that holds a copy of the old string.
*/

char	*ft_strdup(const char *s1)
{
	char *copy;

	if ((copy = (char*)malloc(ft_strlen(s1) + 1)))
	{
		ft_strcpy(copy, s1);
		return (copy);
	}
	return (0);
}
