/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:54:43 by mtaylor           #+#    #+#             */
/*   Updated: 2018/12/08 14:07:20 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Applies the function f to each char of the string.
**	Each char is passed by address to f to be modified.
*/

void	ft_striter(char *s, void (*f)(char *))
{
	if (s != NULL && f != NULL)
	{
		while (*s)
		{
			(*f)(s);
			s++;
		}
	}
}
