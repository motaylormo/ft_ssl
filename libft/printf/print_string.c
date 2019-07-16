/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 19:11:49 by mtaylor           #+#    #+#             */
/*   Updated: 2019/02/06 19:09:20 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Display a string. The argument is a pointer to char.
** Characters are displayed until a '\0' is encountered, or until the number
** 				of characters indicated by the precision have been displayed.
** (The terminating '\0' is not output.)
*/

#include "ft_printf.h"

static int	inner(int fd, char *str, t_fwplt fwplt)
{
	int			char_count;
	int			len;
	t_padding	padding;

	char_count = 0;
	len = ft_strlen(str);
	if (fwplt.precision != -1 && fwplt.precision < len)
		len = fwplt.precision;
	padding = pf_get_padding(len, 0, fwplt);
	while (0 < padding.pre_spaces--)
		char_count += write(fd, " ", 1);
	while (0 < padding.zeros--)
		char_count += write(fd, "0", 1);
	char_count += write(fd, str, len);
	while (0 < padding.post_spaces--)
		char_count += write(fd, " ", 1);
	return (char_count);
}

int			pf_print_string(int fd, va_list ap, t_fwplt fwplt)
{
	char		*arg;

	arg = va_arg(ap, char*);
	if (arg == NULL)
		return (inner(fd, "(null)", fwplt));
	else
		return (inner(fd, arg, fwplt));
}
