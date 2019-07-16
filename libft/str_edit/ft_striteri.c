/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:00:51 by mtaylor           #+#    #+#             */
/*   Updated: 2018/12/08 14:09:05 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Applies the function f to each char of the string,
**		and passing its index as first argument.
**	Each char is passed by address to f to be modified.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int i;

	i = 0;
	if (s != NULL && f != NULL)
	{
		while (*s)
		{
			(*f)(i, s);
			i++;
			s++;
		}
	}
}
