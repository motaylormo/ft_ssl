/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 12:16:50 by mtaylor           #+#    #+#             */
/*   Updated: 2019/02/03 18:22:28 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_padding	pf_get_padding(int core_len, int extras_len, t_fwplt fwplt)
{
	t_padding	padding;
	int			spaces;

	padding.zeros = 0;
	padding.pre_spaces = 0;
	padding.post_spaces = 0;
	if (FOR_OCT(fwplt.type) && (fwplt.flags & hash))
		padding.zeros += 1;
	if (PRC_PADDING(fwplt.type) && fwplt.precision > core_len + padding.zeros)
		padding.zeros += fwplt.precision - (core_len + padding.zeros);
	spaces = fwplt.width - (core_len + padding.zeros + extras_len);
	if (fwplt.flags & minus)
		padding.post_spaces += spaces;
	else if (fwplt.flags & zero && fwplt.precision == -1)
		padding.zeros += spaces;
	else
		padding.pre_spaces += spaces;
	return (padding);
}

int			pf_print_any_leading_char(int fd, int neg, t_fwplt fwplt)
{
	if (neg == 1)
		return (write(fd, "-", 1));
	else if (fwplt.flags & plus)
		return (write(fd, "+", 1));
	else if (fwplt.flags & space)
		return (write(fd, " ", 1));
	return (0);
}

int			pf_integer_digit_len(uintmax_t num, int base, t_fwplt fwplt)
{
	int	num_width;

	num_width = (fwplt.precision == 0 && num == 0) ? 0 : 1;
	while ((num = num / base))
		num_width++;
	return (num_width);
}
