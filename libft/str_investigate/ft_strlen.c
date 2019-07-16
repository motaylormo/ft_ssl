/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:09:04 by mtaylor           #+#    #+#             */
/*   Updated: 2018/10/23 15:59:01 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Returns the number of chars in string before '\0'
*/

size_t	ft_strlen(const char *s)
{
	size_t x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}
