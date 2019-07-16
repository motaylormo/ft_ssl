/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:11:50 by mtaylor           #+#    #+#             */
/*   Updated: 2019/02/06 16:51:12 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_str_seg(int fd, const char **str)
{
	int	char_count;
	int	i;

	char_count = 0;
	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '%')
			break ;
		i++;
	}
	char_count += write(fd, *str, i);
	*str += i;
	if (**str == '%')
		(*str)++;
	return (char_count);
}

static int (*g_print_table[])(int, va_list, t_fwplt) =
{
	['s'] = pf_print_string,
	['c'] = pf_print_char,
	['C'] = pf_print_char,
	['i'] = pf_print_signed_integer,
	['o'] = pf_print_unsigned_integer_base,
	['u'] = pf_print_unsigned_integer_base,
	['x'] = pf_print_unsigned_integer_base,
	['X'] = pf_print_unsigned_integer_base,
	['b'] = pf_print_unsigned_integer_base,
	['f'] = pf_print_floating_point,
	['p'] = pf_print_address,
	['%'] = pf_print_percent_sign
};

static int	parse(int fd, const char *str, va_list ap)
{
	int		char_count;
	t_fwplt	fwplt;

	char_count = 0;
	while (1)
	{
		char_count += get_str_seg(fd, &str);
		if (*str == '\0')
			break ;
		fwplt = pf_get_fwplt(&str, fwplt, ap);
		if (fwplt.type != -1)
			char_count += g_print_table[fwplt.type](fd, ap, fwplt);
	}
	return (char_count);
}

/*
**	ap stands for argument pointer
*/

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = parse(STDOUT_FILENO, format, ap);
	va_end(ap);
	return (ret);
}

int			ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = parse(fd, format, ap);
	va_end(ap);
	return (ret);
}
