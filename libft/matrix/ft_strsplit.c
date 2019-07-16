/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 19:30:37 by mtaylor           #+#    #+#             */
/*   Updated: 2018/12/08 14:37:25 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Mallocs space and returns a fresh double array of strings,
**		each word as a separate string,
**		spliting the string into words at the delimiter char.
*/

static size_t	ft_word_count(char const *s, char c)
{
	size_t words;
	size_t yes;

	words = 0;
	while (*s)
	{
		yes = 0;
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			s++;
			yes++;
		}
		if (yes > 0)
			words++;
	}
	return (words + 1);
}

static char		**ft_get_words(char const *s, char c, char **array)
{
	size_t	len;
	size_t	word;
	size_t	start;

	word = 0;
	len = 0;
	start = 0;
	while (s[start])
	{
		while (s[start] && (s[start] == c))
			start++;
		while (s[start + len] && (s[start + len] != c))
			len++;
		if (len > 0)
			array[word++] = ft_strsub(s, start, len);
		start = start + len;
		len = 0;
	}
	array[word] = 0;
	return (array);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;

	if (s == NULL)
		return (0);
	if ((array = (char**)malloc(ft_word_count(s, c) * sizeof(char*))) == NULL)
		return (NULL);
	array = ft_get_words(s, c, array);
	return (array);
}
