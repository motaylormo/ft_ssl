/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_argv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 12:45:18 by mtaylor           #+#    #+#             */
/*   Updated: 2019/05/20 12:45:19 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Like ft_strsplit()
**		but any whitespace, not just spaces
**		and handling "quoted args"
*/

static unsigned int	count_args(char *str)
{
	unsigned int	count;
	unsigned int	next_quote;

	count = 0;
	while (*str)
	{
		while (*str && ft_iswhitespace(*str))
			str++;
		if (*str && ((*str == '"') || (*str == '\'')) &&
			ft_strchr(str + 1, *str))
		{
			next_quote = ft_strchrindex(str + 1, *str);
			if (next_quote > 0)
				count++;
			str += next_quote + 2;
		}
		else if (*str && !ft_iswhitespace(*str))
		{
			while (*str && !ft_iswhitespace(*str))
				str++;
			count++;
		}
	}
	return (count);
}

static char			**get_args(char *str, char **argv, unsigned int argc)
{
	unsigned int	len;
	unsigned int	i;

	i = 0;
	while ((i < argc) && *str)
	{
		while (*str && ft_iswhitespace(*str))
			str++;
		len = 0;
		if (*str && ((*str == '"') || (*str == '\''))
			&& ft_strchr(str + 1, *str))
		{
			if ((len = ft_strchrindex(str + 1, *str)) > 0)
				argv[i++] = ft_strsub(str, 1, len);
			str += len + 2;
		}
		else if (*str && !ft_iswhitespace(*str))
		{
			while (str[len] && !ft_iswhitespace(str[len]))
				len++;
			argv[i++] = ft_strsub(str, 0, len);
			str += len;
		}
	}
	return (argv);
}

char				**str_to_argv(char *str)
{
	unsigned int	argc;
	char			**argv;

	if (str == NULL)
		return (NULL);
	argc = count_args(str);
	if (argc < 1)
		return (NULL);
	if (!(argv = ft_memalloc(sizeof(char*) * (argc + 1))))
		return (NULL);
	argv = get_args(str, argv, argc);
	return (argv);
}
