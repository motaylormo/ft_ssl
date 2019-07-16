/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:26:59 by mtaylor           #+#    #+#             */
/*   Updated: 2018/12/08 14:17:02 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Return 1 if two strings are identical,
**		0 otherwise
*/

int	ft_strequ(char const *s1, char const *s2)
{
	if (s1 == NULL && s2 == NULL)
		return (1);
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (ft_strcmp(s1, s2) == 0)
		return (1);
	else
		return (0);
}
