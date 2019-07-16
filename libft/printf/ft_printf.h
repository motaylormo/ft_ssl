/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 12:19:43 by mtaylor           #+#    #+#             */
/*   Updated: 2019/03/07 17:05:04 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** headers
** <unistd.h> is for write
** <stdlib.h> is for malloc & free & exit
** <stdarg.h> is for the va_list stuff
** <math.h> is for the INFINITY macro - but there are no functions used
*/

# include "../libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <math.h>

/*
** flags for types
*/

# define FOR_STR(c) (c == 's')
# define FOR_CHAR(c) (c == 'c' || c == 'C')
# define FOR_INT(c) (c == 'd' || c == 'i')
# define FOR_OCT(c) (c == 'o')
# define FOR_HEX(c) (c == 'x' || c == 'X')
# define FOR_DEC(c) (c == 'u')
# define FOR_BIN(c) (c == 'b')
# define FOR_FP(c) (c == 'f')
# define FOR_PTR(c) (c == 'p')

# define SUBMACRO(c) (FOR_OCT(c) || FOR_HEX(c) || FOR_DEC(c) || FOR_BIN(c))
# define PRC_PADDING(c) (SUBMACRO(c) || FOR_INT(c))

/*
** other flag sets
*/

enum	e_flags{
	plus = 1,
	minus = 1 << 1,
	zero = 1 << 2,
	hash = 1 << 3,
	space = 1 << 4,
	star = 1 << 5
};

enum	e_length{
	hh,
	h,
	l,
	ll,
	j,
	z,
	L
};

/*
** structs
*/

typedef struct	s_fwplt
{
	int	flags;
	int	width;
	int	precision;
	int	length;
	int	type;
}				t_fwplt;

typedef struct	s_padding
{
	int	zeros;
	int	pre_spaces;
	int	post_spaces;
}				t_padding;

/*
** functs
*/

t_fwplt			pf_get_fwplt(const char **str, t_fwplt fwplt, va_list ap);
t_padding		pf_get_padding(int core_len, int extras_len, t_fwplt fwplt);
int				pf_print_any_leading_char(int fd, int neg, t_fwplt fwplt);
int				pf_integer_digit_len(uintmax_t num, int base, t_fwplt fwplt);
int				pf_write_integer(int fd, uintmax_t num, int base, int hexcase);
int				pf_print_string(int fd, va_list ap, t_fwplt fwplt);
int				pf_print_char(int fd, va_list ap, t_fwplt fwplt);
int				pf_print_unsigned_integer_base(int fd, va_list ap,
												t_fwplt fwplt);
int				pf_print_signed_integer(int fd, va_list ap, t_fwplt fwplt);
int				pf_print_floating_point(int fd, va_list ap, t_fwplt fwplt);
int				pf_print_address(int fd, va_list ap, t_fwplt fwplt);
int				pf_print_percent_sign(int fd, va_list ap, t_fwplt fwplt);

#endif
