/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:09:15 by mtaylor           #+#    #+#             */
/*   Updated: 2019/02/06 19:07:29 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Writes the address of a void pointer in hexadecimal.
*/

#include "ft_printf.h"

static int	inner(int fd, void *pointer, t_fwplt fwplt)
{
	int			char_count;
	t_padding	padding;

	char_count = 0;
	padding = pf_get_padding(12, 2, fwplt);
	while (0 < padding.pre_spaces--)
		char_count += write(fd, " ", 1);
	char_count += write(fd, "0x", 2);
	while (0 < padding.zeros--)
		char_count += write(fd, "0", 1);
	char_count += pf_write_integer(fd, (uintmax_t)pointer, 16, 'a');
	while (0 < padding.post_spaces--)
		char_count += write(fd, " ", 1);
	return (char_count);
}

int			pf_print_address(int fd, va_list ap, t_fwplt fwplt)
{
	return (inner(fd, va_arg(ap, void*), fwplt));
}
