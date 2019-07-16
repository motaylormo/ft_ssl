/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:42:18 by mtaylor           #+#    #+#             */
/*   Updated: 2018/10/24 19:04:48 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	If char has a lowercase version, returns that.
**	Otherwise, returns char unchanged.
*/

int		ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return ((c - 'A') + 'a');
	else
		return (c);
}
