/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fwplt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 21:15:48 by mtaylor           #+#    #+#             */
/*   Updated: 2019/02/06 16:11:36 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const int	g_get_length[] = {
	['h'] = h,
	['l'] = l,
	['j'] = j,
	['z'] = z,
	['L'] = L
};

static int	get_length(const char **str)
{
	int	val;

	val = -1;
	if (ft_strchr("hljzL", **str))
	{
		val = g_get_length[(int)**str];
		if (ft_strnequ(*str, "hh", 2))
			val = hh;
		if (ft_strnequ(*str, "ll", 2))
			val = ll;
		(*str) += (val == hh || val == ll) ? 2 : 1;
	}
	return (val);
}

static const int	g_get_flag[] = {
	['#'] = hash,
	['0'] = zero,
	['-'] = minus,
	[' '] = space,
	['+'] = plus,
	['*'] = star
};

static int	get_flags(const char **str)
{
	int	val;

	val = 0;
	while (ft_strchr("#0-+ *", **str))
	{
		val |= g_get_flag[(int)**str];
		(*str)++;
	}
	return (val);
}

static char	get_type(const char **str)
{
	int	val;

	val = -1;
	if (ft_strchr("cCsp diouxXb f %", **str) && **str != ' ')
	{
		val = **str;
		(*str)++;
	}
	return ((FOR_INT(val)) ? 'i' : val);
}

static int	get_num(const char **str, va_list ap, t_fwplt *fwplt, int code)
{
	int	num;

	num = 0;
	if (**str == '*' || (fwplt->flags & star && code == 'w'))
	{
		num = va_arg(ap, int);
		(*str) += (**str == '*') ? 1 : 0;
		if (code == 'w' && num < 0)
		{
			num *= -1;
			fwplt->flags |= minus;
		}
	}
	if (ft_isdigit(**str))
	{
		num = 0;
		while (ft_isdigit(**str))
		{
			num = (num * 10) + (**str - '0');
			(*str)++;
		}
	}
	return (num);
}

t_fwplt		pf_get_fwplt(const char **str, t_fwplt fwplt, va_list ap)
{
	fwplt.flags = get_flags(str);
	fwplt.width = -1;
	if (ft_isdigit(**str) || fwplt.flags & star)
		fwplt.width = get_num(str, ap, &fwplt, 'w');
	fwplt.precision = -1;
	if (**str == '.')
	{
		(*str)++;
		fwplt.precision = get_num(str, ap, &fwplt, 'p');
	}
	fwplt.length = get_length(str);
	fwplt.type = get_type(str);
	return (fwplt);
}
