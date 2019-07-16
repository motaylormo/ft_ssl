/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 12:28:36 by mtaylor           #+#    #+#             */
/*   Updated: 2019/04/15 12:31:13 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Tests whether or not a char is whitespace.
**		'\f' is form feed
**		'\t' is a horizontal tab
**		' ' is a space
**		'\n' is a newline
**		'\v' is a vertical tab
**		'\r' is a carriage return
*/

int	ft_iswhitespace(int c)
{
	if (c == '\f' || c == '\t' || c == ' '
		|| c == '\n' || c == '\v' || c == '\r')
		return (1);
	else
		return (0);
}
