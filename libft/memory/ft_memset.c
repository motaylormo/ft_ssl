/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 13:07:53 by mtaylor           #+#    #+#             */
/*   Updated: 2018/10/24 15:46:00 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Fills memory area with len of c (converted to an unsigned char).
*/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *str;

	str = b;
	while (len--)
	{
		*str = (unsigned char)c;
		str++;
	}
	return (b);
}
