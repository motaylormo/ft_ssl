/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 19:47:02 by mtaylor           #+#    #+#             */
/*   Updated: 2019/02/06 19:07:56 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Display a single char (after conversion to unsigned int).
*/

#include "ft_printf.h"

static int	to_unicode(int fd, wchar_t c)
{
	unsigned int	octet;

	if (c <= 0x7F)
	{
		return (write(fd, &c, 1));
	}
	else if (c <= 0x7FF)
	{
		octet = (((c & 0x3f) << 8) | (c >> 6)) | 0x80c0;
		return (write(fd, &octet, 2));
	}
	else if (c <= 0xFFFF)
	{
		octet = (((c & 0x3f) << 16) |
				(((c >> 6) & 0x3f) << 8) | (c >> 12)) | 0x8080e0;
		return (write(fd, &octet, 3));
	}
	else if (c <= 0x10FFFF)
	{
		octet = (((((c & 0x3f) << 24) | (((c >> 6) & 0x3f) << 16))
				| (((c >> 12) & 0x3f) << 8)) | (c >> 18)) | 0x808080f0;
		return (write(fd, &octet, 4));
	}
	return (-1);
}

static int	inner(int fd, wchar_t c, t_fwplt fwplt)
{
	int			char_count;
	t_padding	padding;

	char_count = 0;
	padding = pf_get_padding(1, 0, fwplt);
	while (0 < padding.pre_spaces--)
		char_count += write(fd, " ", 1);
	while (0 < padding.zeros--)
		char_count += write(fd, "0", 1);
	char_count += (fwplt.type == 'C' || fwplt.length == l) ?
		to_unicode(fd, c) : write(fd, &c, 1);
	while (0 < padding.post_spaces--)
		char_count += write(fd, " ", 1);
	return (char_count);
}

int			pf_print_char(int fd, va_list ap, t_fwplt fwplt)
{
	if (fwplt.type == 'C' || fwplt.length == l)
		return (inner(fd, va_arg(ap, wchar_t), fwplt));
	else if (fwplt.type == 'c')
		return (inner(fd, va_arg(ap, unsigned int), fwplt));
	return (-1);
}
