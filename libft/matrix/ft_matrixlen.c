/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 11:08:09 by mtaylor           #+#    #+#             */
/*   Updated: 2019/05/16 11:08:10 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Returns the number of strings in array before '\0'
*/

size_t	ft_matrixlen(char *s[])
{
	size_t x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}
