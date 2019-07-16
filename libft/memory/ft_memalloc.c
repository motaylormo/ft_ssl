/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:47:29 by mtaylor           #+#    #+#             */
/*   Updated: 2018/12/08 13:58:49 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Mallocs space and return a fresh memory area.
**	The memory allocated is initialized to 0.
*/

void	*ft_memalloc(size_t size)
{
	void *space;

	if ((space = malloc(size)))
	{
		ft_bzero(space, size);
		return (space);
	}
	return (0);
}
