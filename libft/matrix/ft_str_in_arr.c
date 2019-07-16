/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_in_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 10:42:28 by mtaylor           #+#    #+#             */
/*   Updated: 2019/05/16 10:42:30 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Checks whether a string appears in an array of strings.
**	Returns the index of the string,
**		or -1 if it doesn't appear.
*/

int		ft_str_in_arr(char *str, const char *array[])
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (ft_strequ(str, array[i]))
			return (i);
		i++;
	}
	return (-1);
}
