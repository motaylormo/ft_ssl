/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:45:03 by mtaylor           #+#    #+#             */
/*   Updated: 2018/12/08 14:13:34 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Applies the function f to each char of the string,
**		and saves the result in a new string.
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	char	*copy;
	size_t	i;

	if (s != NULL && f != NULL
			&& (new = (char*)malloc(ft_strlen(s) + 1)))
	{
		copy = (char*)s;
		i = 0;
		while (s[i])
		{
			new[i] = (*f)(copy[i]);
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (0);
}
