/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:52:20 by mtaylor           #+#    #+#             */
/*   Updated: 2019/04/08 14:52:22 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	For ostr, list all the flags.
**	: after a letter indicates that flag needs an arg following it.
**	? is given for any flag that is not in ostr.
*/

/*
**	char *optarg	Index in ARGV of the next element to be scanned.
**	int optind		Callers store zero here to inhibit the error message
**					for unrecognized options.
**	int opterr		Set to an option character which was unrecognized.
**	int optopt		Keep a global copy of all internal members of getopt_data.
*/

static int	getopt_sub(int argc, char **argv, char *ostr, char **place)
{
	if (optreset || **place == 0)
	{
		optreset = 0;
		*place = argv[optind];
		if (optind >= argc || *(*place)++ != '-')
			return ((*(*place = "") == 0) * -1);
		optopt = *(*place)++;
		if (optopt == '-' && **place == 0)
		{
			++optind;
			*place = "";
			return (-1);
		}
		if (optopt == 0)
		{
			*place = "";
			if (ft_strchr(ostr, '-') == NULL)
				return (-1);
			optopt = '-';
		}
	}
	else
		optopt = *(*place)++;
	return (0);
}

static int	getopt_else(int argc, char **argv, char **ostr, char **place)
{
	if (**place)
		optarg = *place;
	else if (argc > ++optind)
		optarg = argv[optind];
	else
	{
		++optind;
		optarg = NULL;
		*place = "";
		if (**ostr == ':')
			return (':');
		if (opterr)
			ft_printf("%s: option requites an argument -- %c\n", *argv, optopt);
		return ('?');
	}
	*place = "";
	++optind;
	return (0);
}

int			ft_getopt(int argc, char **argv, char *ostr)
{
	static char	*place = "";
	char		*oli;
	int			tmp;

	if ((tmp = getopt_sub(argc, argv, ostr, &place)))
		return (tmp);
	if (optopt == ':' || (oli = ft_strchr(ostr, optopt)) == NULL)
	{
		if (*place == 0)
			++optind;
		if (opterr && *ostr != ':')
			ft_printf("%s: illegal option -- %c\n", *argv, optopt);
		return ('?');
	}
	if (oli[1] != ':')
	{
		optarg = NULL;
		if (*place == 0)
			++optind;
	}
	else if ((tmp = getopt_else(argc, argv, &ostr, &place)))
		return (tmp);
	return (optopt);
}
