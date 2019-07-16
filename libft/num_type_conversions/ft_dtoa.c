/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 15:04:32 by mtaylor           #+#    #+#             */
/*   Updated: 2019/03/07 17:03:52 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Converts a double to being written out in a str,
**		with the specified points of precision.
**	No rounding.
*/

static char	*make_str(double n, int precision, double *div)
{
	char	*str;
	int		num_width;

	num_width = (n < 0) ? 2 : 1;
	*div = 1;
	while ((*div * 10 <= n))
	{
		*div *= 10;
		num_width++;
	}
	if (precision > 0)
		num_width += precision + 1;
	str = ft_strnew(num_width + 1);
	return (str);
}

char		*ft_dtoa(double n, int precision)
{
	char			*str;
	double			div;
	unsigned int	digit;
	int				i;

	str = make_str(n, precision, &div);
	i = 0;
	if (n < 0)
		str[i++] = '-';
	while (div >= 1)
	{
		digit = ((n < 0) ? -n : n) / div;
		n -= div * digit;
		div /= 10;
		str[i++] = digit + '0';
	}
	if (precision > 0)
		str[i++] = '.';
	while (precision--)
	{
		digit = ((n < 0) ? -n : n) * 10;
		n = (n * 10) - digit;
		str[i++] = digit + '0';
	}
	return (str);
}
