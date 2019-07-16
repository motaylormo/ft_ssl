/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:19:58 by mtaylor           #+#    #+#             */
/*   Updated: 2018/10/23 16:09:47 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Append a copy of s2 to the end of s1, then terminating '\0'.
**	Expects s1 to have sufficient space to hold the result.
*/

char	*ft_strcat(char *s1, const char *s2)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (s1[x])
		x++;
	while (s2[y])
	{
		s1[x] = s2[y];
		x++;
		y++;
	}
	s1[x] = '\0';
	return (s1);
}
