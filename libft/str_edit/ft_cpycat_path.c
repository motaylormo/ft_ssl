/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpycat_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 16:27:40 by mtaylor           #+#    #+#             */
/*   Updated: 2019/05/30 16:27:41 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Fills dst with a copy of new + old, concatenated, with '/' between.
**	Expects dst to have sufficient space to hold the result.
*/

void	ft_cpycat_path(char *dst, const char *old, const char *new)
{
	ft_strcpy(dst, old);
	if (dst[ft_strlen(dst) - 1] != '/')
		ft_strcat(dst, "/");
	ft_strcat(dst, new);
}
