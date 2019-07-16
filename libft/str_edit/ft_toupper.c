/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:38:45 by mtaylor           #+#    #+#             */
/*   Updated: 2018/10/24 19:04:35 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	If char has an uppercase version, returns that.
**	Otherwise, returns char unchanged.
*/

int		ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return ((c - 'a') + 'A');
	else
		return (c);
}
