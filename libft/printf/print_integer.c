/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:06:28 by mtaylor           #+#    #+#             */
/*   Updated: 2019/02/04 15:12:06 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Writes a signed integer in decimal notation.
*/

#include "ft_printf.h"

int			pf_write_integer(int fd, uintmax_t num, int base, int hexcase)
{
	uintmax_t		num_copy;
	uintmax_t		div;
	unsigned int	digit;
	int				char_count;

	char_count = 0;
	div = 1;
	num_copy = num;
	while ((num_copy = num_copy / base))
		div *= base;
	while (div >= 1)
	{
		digit = num / div;
		digit += (digit < 10) ? '0' : -10 + hexcase;
		num %= div;
		div /= base;
		char_count += write(fd, &digit, 1);
	}
	return (char_count);
}

static int	s_inner(int fd, intmax_t num, t_fwplt fwplt)
{
	int			char_count;
	t_padding	padding;

	char_count = 0;
	padding = pf_get_padding(
			pf_integer_digit_len((num < 0) ? -num : num, 10, fwplt),
			(num < 0 || fwplt.flags & plus || fwplt.flags & space) ? 1 : 0,
			fwplt);
	while (0 < padding.pre_spaces--)
		char_count += write(fd, " ", 1);
	char_count += pf_print_any_leading_char(fd, (num < 0), fwplt);
	while (0 < padding.zeros--)
		char_count += write(fd, "0", 1);
	if (!(num == 0 && fwplt.precision == 0))
		char_count += pf_write_integer(fd, (num < 0) ? -num : num, 10, 'a');
	while (0 < padding.post_spaces--)
		char_count += write(fd, " ", 1);
	return (char_count);
}

int			pf_print_signed_integer(int fd, va_list ap, t_fwplt fwplt)
{
	if (fwplt.length == -1)
		return (s_inner(fd, va_arg(ap, int), fwplt));
	else if (fwplt.length == hh)
		return (s_inner(fd, (signed char)va_arg(ap, int), fwplt));
	else if (fwplt.length == h)
		return (s_inner(fd, (short)va_arg(ap, int), fwplt));
	else if (fwplt.length == l)
		return (s_inner(fd, va_arg(ap, long), fwplt));
	else if (fwplt.length == ll)
		return (s_inner(fd, va_arg(ap, long long), fwplt));
	else if (fwplt.length == j)
		return (s_inner(fd, va_arg(ap, intmax_t), fwplt));
	else if (fwplt.length == z)
		return (s_inner(fd, va_arg(ap, ssize_t), fwplt));
	else
		return (-1);
}

static const int	g_get_base[] = {
	['o'] = 8,
	['x'] = 16,
	['X'] = 16,
	['u'] = 10,
	['i'] = 10,
	['b'] = 2
};

static int	u_inner(int fd, uintmax_t num, t_fwplt fwplt)
{
	int			char_count;
	int			hexcase;
	int			base;
	t_padding	padding;

	base = g_get_base[fwplt.type];
	hexcase = (fwplt.type == 'X') ? 'A' : 'a';
	char_count = 0;
	padding = pf_get_padding(pf_integer_digit_len(num, base, fwplt),
			(FOR_HEX(fwplt.type) && (fwplt.flags & hash) && num > 0) ? 2 : 0,
			fwplt);
	while (0 < padding.pre_spaces--)
		char_count += write(fd, " ", 1);
	if (FOR_HEX(fwplt.type) && (fwplt.flags & hash) && num > 0)
		char_count += write(fd, (hexcase == 'A') ? "0X" : "0x", 2);
	while (0 < padding.zeros--)
		char_count += write(fd, "0", 1);
	if (!(num == 0 && (fwplt.precision == 0
					|| (FOR_OCT(fwplt.type) && (fwplt.flags & hash)))))
		char_count += pf_write_integer(fd, num, base, hexcase);
	while (0 < padding.post_spaces--)
		char_count += write(fd, " ", 1);
	return (char_count);
}

int			pf_print_unsigned_integer_base(int fd, va_list ap, t_fwplt fwplt)
{
	if (fwplt.length == -1)
		return (u_inner(fd, va_arg(ap, unsigned int), fwplt));
	else if (fwplt.length == hh)
		return (u_inner(fd, (unsigned char)va_arg(ap, int), fwplt));
	else if (fwplt.length == h)
		return (u_inner(fd, (unsigned short)va_arg(ap, int), fwplt));
	else if (fwplt.length == l)
		return (u_inner(fd, va_arg(ap, unsigned long), fwplt));
	else if (fwplt.length == ll)
		return (u_inner(fd, va_arg(ap, unsigned long long), fwplt));
	else if (fwplt.length == j)
		return (u_inner(fd, va_arg(ap, uintmax_t), fwplt));
	else if (fwplt.length == z)
		return (u_inner(fd, va_arg(ap, size_t), fwplt));
	else
		return (-1);
}
