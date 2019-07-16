/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent_sign.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:34:05 by mtaylor           #+#    #+#             */
/*   Updated: 2019/02/06 19:08:41 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Display a field with only a '%', but which can have padding and all that.
** This is absolute bullshit. %% is for neutralizing %, just like // is for /.
** But the tests want this, so
*/

#include "ft_printf.h"

static int	inner(int fd, t_fwplt fwplt)
{
	int			char_count;
	t_padding	padding;

	char_count = 0;
	padding = pf_get_padding(1, 0, fwplt);
	while (0 < padding.pre_spaces--)
		char_count += write(fd, " ", 1);
	while (0 < padding.zeros--)
		char_count += write(fd, "0", 1);
	char_count += write(fd, "%", 1);
	while (0 < padding.post_spaces--)
		char_count += write(fd, " ", 1);
	return (char_count);
}

int			pf_print_percent_sign(int fd, va_list ap, t_fwplt fwplt)
{
	(void)ap;
	return (inner(fd, fwplt));
}
