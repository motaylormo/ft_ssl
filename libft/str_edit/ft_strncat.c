/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:21:07 by mtaylor           #+#    #+#             */
/*   Updated: 2018/10/23 20:19:25 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Append no more than n chars from s2 to the end of s1.
**	Expects s1 to have sufficient space to hold the result.
*/

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t x;
	size_t y;

	x = 0;
	y = 0;
	while (s1[x])
		x++;
	while (s2[y] && y < n)
	{
		s1[x] = s2[y];
		x++;
		y++;
	}
	s1[x] = '\0';
	return (s1);
}
