/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:31:04 by mtaylor           #+#    #+#             */
/*   Updated: 2018/12/08 14:03:14 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Mallocs space and returns a fresh string full of '\0'.
*/

char	*ft_strnew(size_t size)
{
	void *space;

	if ((space = malloc(size + 1)))
	{
		ft_memset(space, '\0', size + 1);
		return (space);
	}
	return (0);
}
