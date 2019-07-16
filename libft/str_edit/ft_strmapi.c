/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:15:06 by mtaylor           #+#    #+#             */
/*   Updated: 2018/12/08 14:14:24 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Applies the function f to each char of the string,
**		and passing its index as first argument.
**	Saves the result in a new string.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	char	*copy;
	size_t	i;

	if (s != NULL && f != NULL
			&& (new = (char*)malloc(ft_strlen(s) + 1)))
	{
		copy = (char*)s;
		i = 0;
		while (*s)
		{
			new[i] = (*f)(i, *s);
			i++;
			s++;
		}
		new[i] = '\0';
		return (new);
	}
	return (0);
}
