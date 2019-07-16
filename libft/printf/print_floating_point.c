/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_floatingpoint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:04:52 by mtaylor           #+#    #+#             */
/*   Updated: 2019/02/09 13:18:35 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Writes a double or float (after conversion to double) in decimal notation.
*/

#include "ft_printf.h"

static char	*make_num_str(long double num, int precision)
{
	char		*num_str;
	long double	div;
	int			num_width;

	div = 1;
	num_width = 2;
	while ((div * 10 <= num))
	{
		div *= 10;
		num_width++;
	}
	if (precision > 0)
		num_width += precision + 1;
	num_str = (char*)ft_memalloc(sizeof(char) * (num_width + 1));
	num_str[0] = '0';
	return (num_str);
}

static void	round_end(char *num_str, int i)
{
	while (--i >= 0)
	{
		if (num_str[i] >= '0' && num_str[i] <= '8')
		{
			num_str[i]++;
			return ;
		}
		else if (num_str[i] == '9')
			num_str[i] = '0';
		else if (!(num_str[i] == '.'))
			return ;
	}
}

static void	fill_num_str(long double num, char *num_str, int precision)
{
	long double		div;
	unsigned int	digit;
	int				i;

	i = 1;
	div = 1;
	while (div * 10 <= num)
		div *= 10;
	while (div >= 1)
	{
		digit = num / div;
		num -= div * digit;
		div /= 10;
		num_str[i++] = digit + '0';
	}
	if (precision > 0)
		num_str[i++] = '.';
	while (precision--)
	{
		digit = num * 10;
		num = (num * 10) - digit;
		num_str[i++] = digit + '0';
	}
	if (num >= (long double)0.5)
		round_end(num_str, i);
}

static int	inner(int fd, long double num, t_fwplt fwplt)
{
	int			char_count;
	char		*num_str;
	char		*head;
	t_padding	padding;

	fwplt.precision = (fwplt.precision == -1) ? 6 : fwplt.precision;
	num_str = make_num_str(num, fwplt.precision);
	fill_num_str((num < 0) ? -num : num, num_str, fwplt.precision);
	head = num_str;
	num_str += (num_str[0] == '0' && ft_isdigit(num_str[1])) ? 1 : 0;
	padding = pf_get_padding(ft_strlen(num_str),
			(num < 0 || fwplt.flags & plus || fwplt.flags & space) ? 1 : 0,
			fwplt);
	char_count = 0;
	while (0 < padding.pre_spaces--)
		char_count += write(fd, " ", 1);
	char_count += pf_print_any_leading_char(fd, (num < 0), fwplt);
	while (0 < padding.zeros--)
		char_count += write(fd, "0", 1);
	char_count += write(fd, num_str, ft_strlen(num_str));
	while (0 < padding.post_spaces--)
		char_count += write(fd, " ", 1);
	free(head);
	return (char_count);
}

int			pf_print_floating_point(int fd, va_list ap, t_fwplt fwplt)
{
	long double	arg;

	if (fwplt.length == -1 || fwplt.length == l)
		arg = va_arg(ap, double);
	else if (fwplt.length == L)
		arg = va_arg(ap, long double);
	else
		return (-1);
	if (arg != arg)
		return (write(fd, "nan", 3));
	if (arg == -INFINITY)
		return (write(fd, "-inf", 4));
	if (arg == INFINITY)
		return (write(fd, "inf", 3));
	return (inner(fd, arg, fwplt));
}
