/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:21:35 by mtaylor           #+#    #+#             */
/*   Updated: 2019/03/07 17:14:35 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Converts an int to being written out in a string in the specified base.
*/

static char	*make_str(int n, int *div, unsigned int base)
{
	char	*str;
	int		num_width;

	num_width = (n < 0) ? 1 : 0;
	*div = 1;
	while ((n = n / base))
	{
		*div *= base;
		num_width++;
	}
	str = ft_strnew(num_width + 1);
	return (str);
}

char		*ft_itoabase(int n, unsigned int base)
{
	char	*str;
	int		div;
	int		digit;
	int		i;

	str = make_str(n, &div, base);
	i = 0;
	if (n < 0)
		str[i++] = '-';
	while (div >= 1)
	{
		digit = ((n < 0) ? -n : n) / div;
		str[i++] = (digit > 9) ? (digit - 10) + 'a' : digit + '0';
		n %= div;
		div /= base;
	}
	return (str);
}
