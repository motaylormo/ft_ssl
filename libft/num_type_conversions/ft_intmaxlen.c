/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmaxlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:50:21 by mtaylor           #+#    #+#             */
/*   Updated: 2019/04/12 14:55:09 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	The width of an integer, printed out in that base.
*/

int		ft_intmaxlen(intmax_t num, unsigned int base)
{
	int	width;

	width = (num < 0) ? 2 : 1;
	while ((num = num / base))
		width++;
	return (width);
}
