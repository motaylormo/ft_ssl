/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 10:03:46 by mtaylor           #+#    #+#             */
/*   Updated: 2019/03/07 17:12:38 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Converts an int to being written out in a str.
*/

static char	*make_str(int n, int *div)
{
	char	*str;
	int		num_width;

	num_width = (n < 0) ? 1 : 0;
	*div = 1;
	while ((n = n / 10))
	{
		*div *= 10;
		num_width++;
	}
	str = ft_strnew(num_width + 1);
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		div;
	int		digit;
	int		i;

	if (!(str = make_str(n, &div)))
		return (0);
	i = 0;
	if (n < 0)
		str[i++] = '-';
	while (div >= 1)
	{
		digit = n / div;
		str[i++] = '0' + ((digit < 0) ? digit * -1 : digit);
		n %= div;
		div /= 10;
	}
	return (str);
}
